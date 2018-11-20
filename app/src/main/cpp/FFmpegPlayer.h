//
// Created by niantuo on 2018/11/15.
//

#ifndef HANCNETLIB_DECODER_H
#define HANCNETLIB_DECODER_H

#define LOG_TAG "Decoder"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include <android/log.h>
#include <jni.h>

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}
/**
 * 播放状态，为准备就绪，准备就绪，播放中，暂停中。没有已停止。
 */
enum PLAY_STATUS {
    UN_READY = 1,
    READY = 2,
    PLAYING = 4,
};

class FFmpegPlayer {

public:


    FFmpegPlayer(JNIEnv *env,jobject instance, int dstW, int dstH, int id);

    ~FFmpegPlayer();

    void play(const char* url);

    int pull(AVFormatContext *ctx,AVCodecParameters *parameters,int v_index,int a_index);

    void initial(JNIEnv*env,jobject surface);

    int readyPull(const char *url);

    int release(JNIEnv *env);

private:
    ANativeWindow *window = NULL;
    jobject instance;

    int dstW;
    int dstH;

    bool isLoop = true;
    PLAY_STATUS status = UN_READY;
    int id=-1;
    pthread_mutex_t mutex;

    void onReady(JNIEnv *env,int id);

    void onPlay();

    void onStop(int code, const char *message);

    void onPause();

    void onError(int code, const char *errMsg);


};


#endif //HANCNETLIB_DECODER_H
