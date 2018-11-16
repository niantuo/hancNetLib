//
// Created by niantuo on 2018/11/15.
//
#include <jni.h>
#include <android/bitmap.h>
#include "ffmpeg.h"

ffmpeg::ffmpeg() {
    pCodecCtx = NULL;
    videoStream = -1;
}

ffmpeg::~ffmpeg() {
    sws_freeContext(pSwsCtx);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);
}

int ffmpeg::initial(char *url, JNIEnv *e) {
    int err;
    env = e;
    rtspURL = url;
    AVCodec *pCodec;
    av_register_all();
    avformat_network_init();
    pFormatCtx = avformat_alloc_context();
    pFrame = av_frame_alloc();
    err = avformat_open_input(&pFormatCtx, rtspURL, NULL, NULL);
    if (err < 0) {
        printf("can not open this stream!");
        return err;
    }
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf("can not find stream info !");
        return -1;
    }
    int i = 0;
    videoStream = -1;
    for (i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
            break;
        }
    }
    if (videoStream == -1) {
        printf("can not find video stream! ");
        return -1;
    }

    AVCodecParameters *parameters = pFormatCtx->streams[videoStream]->codecpar;
    width = parameters->width;
    height = parameters->height;

    pCodec = avcodec_find_decoder(parameters->codec_id);


    pSwsCtx = sws_getContext(width, height, AV_PIX_FMT_YUV420P, width, height, AV_PIX_FMT_RGB24,
                             SWS_BICUBIC, 0, 0, 0);
    if (pCodec == NULL) {
        printf("Unsupported codec! ");
        return -1;
    }

    pCodecCtx = avcodec_alloc_context3(pCodec);

    printf("video size : width=%d height=%d \n", width, height);

    AVDictionary *options = NULL;
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    if (avcodec_open2(pCodecCtx, pCodec, &options) < 0) {

        printf("Unable to open codec! ");
        return -1;
    }

    avcodec_send_packet(pCodecCtx, &packet);
    avcodec_receive_frame(pCodecCtx, pFrame);

    printf("initial successfully ! ");
    return 0;
}

void ffmpeg::fillPicture(AndroidBitmapInfo *info, void *pixels, AVPicture *rgbPicture) {
    uint8_t *frameLine;
    int yy;
    for (yy = 0; yy < info->height; yy++) {
        uint8_t *line = (uint8_t *) pixels;
        frameLine = (uint8_t *) rgbPicture->data[0] + (yy * rgbPicture->linesize[0]);
        int xx;
        for (xx = 0; xx < info->width; xx++) {
            int out_offset = xx * 4;
            int in_offset = xx * 3;
            line[out_offset] = frameLine[in_offset];
            line[out_offset + 1] = frameLine[in_offset + 1];
            line[out_offset + 2] = frameLine[in_offset + 2];
            line[out_offset + 3] = 0xff;
        }
        pixels = (char *) pixels + info->stride;
    }
}



int ffmpeg::h264Decodec(jobject &bitmap) {
//    int frameFinished = 0;
//    AndroidBitmapInfo info;
//    void *pixels;
//    int ret = -1;
//    if ((ret = AndroidBitmap_getInfo(env, bitmap, &info)) < 0) {
//        LOGE("AndroidBitmap_getInfo() failed ! error");
//    }
//    while (av_read_frame(pFormatCtx, &packet) >= 0) {
//        if (packet.stream_index == videoStream) {
//            avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished, &packet);
//            if (frameFinished) {
//                LOGI("****************ffmpeg decodec ****************\n");
//                int rs = sws_scale(pSwsCtx, (const uint8_t *const *) pFrame->data, pFrame->linesize,
//                                   0, height, picture.data, picture.linesize);
//                if (rs == -1) {
//                    LOGE(
//                            "__________Can open to change to des imag_____________e\n");
//                    return -1;
//                }
//                if ((ret = AndroidBitmap_lockPixels(env, bitmap, &pixels))
//                    < 0) {
//                    LOGE("AndroidBitmap_lockPixels() failed ! error");
//                    //return -1;
//                }
//                //pixels = picture.data[0] + info.stride;
//                fillPicture(&info, pixels, &picture);
//                AndroidBitmap_unlockPixels(env, bitmap);
//            }
//
//        }
//
//    }
    return 1;
}

int ffmpeg::render() {

    av_read_frame(pFormatCtx,&packet);
    avcodec_send_packet(pCodecCtx,&packet);

    ANativeWindow_setBuffersGeometry(window,width,height,WINDOW_FORMAT_RGBA_8888);

    ANativeWindow_Buffer *buffer=NULL;


    int32_t locked = ANativeWindow_lock(window,buffer,NULL);

    return 0;
}

int ffmpeg::renderPic() {
    if (window==NULL){
        LOGE("window can not be NULL");
        return -1;
    }
    if (ANativeWindow_setBuffersGeometry(window,width,height,WINDOW_FORMAT_RGBA_8888)<0){
        LOGE("could not set buffers geometry.\n");
        return -1;
    }
    LOGI("Start Display. \n");
    AVFrame *frame = av_frame_alloc();

    return 0;
}

const char *rtspURL;
ffmpeg *ffmpeg1;

extern "C" JNIEXPORT void JNICALL
Java_cn_tonyandmoney_tina_camera_support_view_FFmpegSurfaceView_initial(JNIEnv *env,
                                                                        jobject instance,
                                                                        jstring _url) {
    rtspURL = env->GetStringUTFChars(_url, 0);
    LOGI("%s", rtspURL);
    ffmpeg1 = new ffmpeg();
    ffmpeg1->initial((char *) rtspURL, env);
    jclass clz = env->GetObjectClass(instance);
    jmethodID mid = env->GetMethodID(clz, "setBitmapSize", "(II)V");
    env->CallVoidMethod(instance, mid, ffmpeg1->width, ffmpeg1->height);
}

extern "C" JNIEXPORT void JNICALL
Java_cn_tonyandmoney_tina_camera_support_view_FFmpegSurfaceView_play(JNIEnv *env,
                                                                     jobject instance,
                                                                     jobject surface) {
    ANativeWindow *window = ANativeWindow_fromSurface(env,surface);
    ffmpeg1->window=window;
    ffmpeg1->render();
}