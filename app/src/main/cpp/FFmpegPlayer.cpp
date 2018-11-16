//
// Created by niantuo on 2018/11/15.
//

#include "FFmpegPlayer.h"

JavaVM *g_vm = NULL;

long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


/**
 * 显示到Android SurfaceView上，必须把数据解码好。
 * @param window
 * @param buffer
 * @param data
 */
void
renderAndroid(ANativeWindow *window, uint8_t *data, int src_stride) {
    if (window == NULL) {
        return;
    }
    ANativeWindow_Buffer buffer;
    if (ANativeWindow_lock(window, &buffer, NULL) > -1) {
        uint8_t *dst = (uint8_t *) buffer.bits;
        int dest_stride = buffer.stride * 4;

        for (int h = 0; h < buffer.height; h++) {
            memcpy(dst + h * dest_stride,
                   data + h * src_stride,
                   (size_t) src_stride);
        }
        ANativeWindow_unlockAndPost(window);
    } else {
        LOGI("renderAndroid could not lock NativeWindow.");
    }
}

/**
 * 解码，并且缩放到合适的
 * @param codecContext 解码器上下文环境
 * @param swsCtx
 * @param frame
 * @param rgbFrame
 * @param packet
 */
void decoder(AVCodecContext *codecContext, SwsContext *swsCtx,
             AVFrame *frame, AVFrame *rgbFrame, AVPacket *packet) {
    int ret = avcodec_send_packet(codecContext, packet);
    if (ret < 0 && ret != AVERROR(EAGAIN) && ret != AVERROR_EOF) {
        return;
    }
    ret = avcodec_receive_frame(codecContext, frame);
    if (ret < 0 && ret != AVERROR_EOF)
        return;

    if (swsCtx == NULL || frame == NULL || rgbFrame == NULL) {
        LOGE("swsCtx or frame or rgbFrame  is NULL");
        return;
    }

    sws_scale(swsCtx, (const uint8_t *const *) frame->data, frame->linesize, 0,
              codecContext->height, rgbFrame->data, rgbFrame->linesize);

}


FFmpegPlayer::FFmpegPlayer(JNIEnv *env, jobject instance, int dstW, int dstH,
                           int id) {

    pthread_mutex_init(&mutex, NULL);
    this->instance = env->NewGlobalRef(instance);
    this->dstW = dstW;
    this->dstH = dstH;
    this->id = id;
}


void FFmpegPlayer::initial(JNIEnv *env, jobject surface) {
    pthread_mutex_lock(&mutex);
    window = ANativeWindow_fromSurface(env, surface);
    if (window == NULL) {
        LOGE("window initial failed !");
        onError(-1, "本地播放器初始化失败。");
        g_vm->DetachCurrentThread();
        return;
    }
    status = READY;
    onReady(env, id);
    pthread_mutex_unlock(&mutex);
}

/**
 * 开始拉流。如果当前状态为播放准备，则无需重新拉取流信息。
 * @param url
 * @return
 */
int FFmpegPlayer::readyPull(const char *url) {
    if (status == UN_READY) {
        onError(-11, "播放器未初始化。");
        return -11;
    }

    if (status == PLAYING) {
        isLoop = false;
        return 0;
    }
    isLoop = true;
    AVDictionary *options = NULL;
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    av_dict_set_int(&options, "max_analyze_duration", 1000, 0);
    av_dict_set_int(&options, "probesize", 2048, 0);
    LOGI("readyPull->time 1: %ld", getCurrentTime());
    AVFormatContext *pFormatCtx = avformat_alloc_context();
    //打开文件或者流
    if (avformat_open_input(&pFormatCtx, url, NULL, &options) < 0) {
        LOGI("could not open input stream! ");
        onError(-12, "无法打开视频输入。");
        return -1;
    }
    LOGI("readyPull->time2 : %ld", getCurrentTime());
//    查找文件的流信息
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        LOGI("could not find stream information.\n");
        onError(-13, "无法找到流信息。");
        return -2;
    }

    LOGI("readyPull->time 3: %ld", getCurrentTime());
    //    在流的信息中找出视频流
    int videoIndex = -1;
    int audioIndex = -1;
    for (int i = 0; i < pFormatCtx->nb_streams; ++i) {
        AVMediaType mediaType = pFormatCtx->streams[i]->codecpar->codec_type;
        if (mediaType == AVMEDIA_TYPE_VIDEO) {
            videoIndex = i;
        } else if (mediaType == AVMEDIA_TYPE_AUDIO) {
            audioIndex = i;
        }
    }
    if (videoIndex == -1) {
        LOGI("could find video stream.\n");
        onError(-14, "没有找到视频流信息。");
        return -3;
    }

    AVCodecParameters *parameters = pFormatCtx->streams[videoIndex]->codecpar;
    pull(pFormatCtx, parameters, videoIndex, audioIndex);
    avformat_close_input(&pFormatCtx);
    av_free(parameters);
    av_free(options);
    return 0;
}


/**
 * 准备拉流并且显示到Android 的SurfaceView上面去。
 * 如果当前为播放，则停止从上下文中取数据。
 * @return
 */
int
FFmpegPlayer::pull(AVFormatContext *ctx, AVCodecParameters *parameters, int v_index, int a_index) {


    AVCodec *avCodec = avcodec_find_decoder(parameters->codec_id);
    if (avCodec == NULL) {
        LOGE("codec is NULL.\n");
        onError(-20, "没有找到合适的解码器。");
        return -4;
    }
    AVCodecContext *vCodecCtx = avcodec_alloc_context3(avCodec);
    avcodec_parameters_to_context(vCodecCtx, parameters);
    if (avcodec_open2(vCodecCtx, avCodec, NULL) < 0) {
        LOGE("could not open codec.\n");
        onError(-21, "打开解码器错误。");
        return -5;
    }


    AVFrame *o_frame = av_frame_alloc();
    AVFrame *rgb_frame = av_frame_alloc();

    int numBytes = av_image_get_buffer_size(AV_PIX_FMT_RGBA, dstW, dstH, 1);
    uint8_t *v_out_buffer = (uint8_t *) av_malloc(numBytes * sizeof(uint8_t));

    av_image_fill_arrays(rgb_frame->data, rgb_frame->linesize, v_out_buffer, AV_PIX_FMT_RGBA, dstW,
                         dstH, 1);
    SwsContext *swsCtx = sws_getContext(parameters->width, parameters->height, vCodecCtx->pix_fmt,
                                        dstW, dstH,
                                        AV_PIX_FMT_RGBA,
                                        SWS_BICUBIC, NULL, NULL, NULL);

    ANativeWindow_setBuffersGeometry(window, dstW, dstH, WINDOW_FORMAT_RGBA_8888);

    onPlay();
    AVPacket *packet = av_packet_alloc();
    //读取帧
    while (isLoop) {
        int ret = av_read_frame(ctx, packet);
        if (ret > -1 && packet->stream_index == v_index) {
            decoder(vCodecCtx, swsCtx, o_frame, rgb_frame, packet);
            renderAndroid(window, rgb_frame->data[0], rgb_frame->linesize[0]);
        } else {
//            LOGI("pull 读取视频帧失败。");
        }
        av_packet_unref(packet);
    }
    av_packet_free(&packet);
    sws_freeContext(swsCtx);
    avcodec_close(vCodecCtx);
    av_free(v_out_buffer);
    av_frame_free(&o_frame);
    av_frame_free(&rgb_frame);
    onPause();
    return 0;
}


void FFmpegPlayer::onReady(JNIEnv *env, int id) {
    jclass jClz = env->GetObjectClass(instance);
    jmethodID onReady = env->GetMethodID(jClz, "onReady", "(I)V");
    env->CallVoidMethod(instance, onReady, id);
}

void FFmpegPlayer::onPlay() {
    status = PLAYING;
    JNIEnv *env;
    g_vm->AttachCurrentThread(&env, NULL);
    jclass jClz = env->GetObjectClass(instance);
    jmethodID onReady = env->GetMethodID(jClz, "onPlay", "()V");
    env->CallVoidMethod(instance, onReady);
}

/**
 * 停止播放的回调。
 * @param code 错误码
 * @param message  消息
 */
void FFmpegPlayer::onStop(int code, const char *message) {
    JNIEnv *env;
    g_vm->AttachCurrentThread(&env, NULL);
    jclass clz = env->GetObjectClass(instance);
    jmethodID methodName = env->GetMethodID(clz, "onStop", "(ILjava/lang/String;)V");
    jint _code = code;
    jstring _msg = env->NewStringUTF(message);
    env->CallVoidMethod(instance, methodName, _code, _msg);
}

/**
 * 暂停的回调
 */
void FFmpegPlayer::onPause() {
    if (status != UN_READY) {
        status = READY;
        JNIEnv *env;
        g_vm->AttachCurrentThread(&env, NULL);
        jclass jClz = env->GetObjectClass(instance);
        jmethodID onReady = env->GetMethodID(jClz, "onPause", "()V");
        env->CallVoidMethod(instance, onReady);
    }
}

/**
 * 播放错误的回调
 * @param code  错误码
 * @param errMsg  错误消息
 */
void FFmpegPlayer::onError(int code, const char *errMsg) {
    JNIEnv *env;
    g_vm->AttachCurrentThread(&env, NULL);
    jclass clz = env->GetObjectClass(instance);
    jmethodID methodName = env->GetMethodID(clz, "onError", "(ILjava/lang/String;)V");
    jint _code = code;
    jstring _msg = env->NewStringUTF(errMsg);
    env->CallVoidMethod(instance, methodName, _code, _msg);
}

FFmpegPlayer::~FFmpegPlayer() {
    LOGI("FFmpegPlayer 析构函数。");
    if (status == UN_READY) {
        return;
    }
    isLoop = false;
    pthread_mutex_lock(&mutex);
    status = UN_READY;
    if (window != NULL) {
        ANativeWindow_release(window);
        window = NULL;
    }
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

int FFmpegPlayer::release(JNIEnv *env) {
    isLoop = false;
    env->DeleteGlobalRef(instance);
    return 0;
}


//维护一个静态的解码器列表。
static FFmpegPlayer *decoderMap[10];
static int count = 0;

int getId() {
    for (int i = 0; i < 10; ++i) {
        if (decoderMap[i] == NULL) {
            return i;
        }
    }
    return 1;
}

extern "C" JNIEXPORT jint JNICALL
Java_cn_tonyandmoney_tina_camera_support_view_H264SurfaceView_init(JNIEnv *env,
                                                                   jobject instance,
                                                                   jobject surface,
                                                                   jint w, jint h) {

    if (g_vm == NULL) {
        env->GetJavaVM(&g_vm);
        av_register_all();
    }
    int id = getId();
    FFmpegPlayer *decoder = new FFmpegPlayer(env, instance, w, h, id);
    decoderMap[id] = decoder;
    decoder->initial(env, surface);
    return id;
}

extern "C" JNIEXPORT jint JNICALL
Java_cn_tonyandmoney_tina_camera_support_view_H264SurfaceView_release(JNIEnv *env,
                                                                      jobject instance,
                                                                      jint id) {
    FFmpegPlayer *decoder = decoderMap[id];
    if (decoder == NULL) {
        LOGE("decoder 未初始化。");
        return -1;
    }
    decoder->release(env);
    delete decoder;
    decoderMap[count] = NULL;
    return -1;
}

extern "C" JNIEXPORT jint JNICALL
Java_cn_tonyandmoney_tina_camera_support_view_H264SurfaceView_play(JNIEnv *env,
                                                                   jobject instance,
                                                                   jstring _url,
                                                                   jint id) {

    FFmpegPlayer *decoder = decoderMap[id];
    if (decoder == NULL) {
        LOGE("decoder 未初始化。");
        return -1;
    }

    const char *url = env->GetStringUTFChars(_url, 0);
    int ret = decoder->readyPull(url);
    env->ReleaseStringUTFChars(_url, url);
    return ret;
}