//
// Created by Administrator on 2018/10/16.
//
#include <jni.h>
#include <string>
#include <dlfcn.h>



void *handle;


extern "C" JNIEXPORT jboolean JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_hancNetSDKInit(
        JNIEnv *env,
        jobject ){
    if (handle){
        return static_cast<jboolean>(true);
    }
    handle=dlopen("net-lib",RTLD_LAZY);
    bool (*sdkInit)();
    sdkInit=(bool(*)())dlsym(handle,"HancNetSDK_Init");
    return static_cast<jboolean>((*sdkInit)());
}


