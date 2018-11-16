//
// Created by niantuo on 2018/11/15.
//

#ifndef HANCNETLIB_FFMPEG_H
#define HANCNETLIB_FFMPEG_H
#define LOG_TAG "FFmpeg"

#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include <android/bitmap.h>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
}



class ffmpeg {

public:

    friend class Video;
    int width;
    int height;
    ANativeWindow *window;

    ffmpeg();
    int initial(char * url, JNIEnv *e);
    int h264Decodec(jobject & bitmap);
    void fillPicture(AndroidBitmapInfo* info, void *pixels, AVPicture *rgbPicture);
    virtual ~ffmpeg();


    int render();

    int renderPic();

private:
    AVFormatContext *pFormatCtx;
    AVCodecContext *pCodecCtx;
    AVFrame *pFrame;
    AVPacket packet;
    SwsContext * pSwsCtx;
    int videoStream;

    char * rtspURL;
    JNIEnv *env;


};


#endif //HANCNETLIB_FFMPEG_H
