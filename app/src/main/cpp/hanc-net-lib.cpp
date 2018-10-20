//
// Created by Administrator on 2018/10/16.
//
#include <jni.h>
#include <dlfcn.h>
#include <string>
#include <hancnetsdk.h>
#include <android/log.h>


#define TAG  "tina-hanc-net"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)


jstring CStr2Jstring(JNIEnv *env, const char *pat) {
    // 定义java String类 strClass
    jclass strClass = (env)->FindClass("Ljava/lang/String;");
    // 获取java String类方法String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    // 建立byte数组
    jbyteArray bytes = (env)->NewByteArray((jsize) strlen(pat));
    // 将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, (jsize) strlen(pat), (jbyte *) pat);
    //设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("GB2312");
    //将byte数组转换为java String,并输出
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);

}

char *Jstring2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1); //new char[alen+1];
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);

    return rtn;
}

JavaVM *g_VM;
jobject jClz;
bool mNeedDetach;

/**
 * 网络回调
 * @param sessionId
 * @param pBuf
 * @param nBufLen
 * @param dwUser
 */
void NetCallback(int sessionId, char *pBuf, int nBufLen, long dwUser) {

    JNIEnv *env;

    //获取当前native线程是否有没有被附加到jvm环境中
    int getEnvStat = (g_VM)->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (getEnvStat == JNI_EDETACHED) {
        //如果没有， 主动附加到jvm环境中，获取到env
        if ((g_VM)->AttachCurrentThread(&env, NULL) != 0) {
            return;
        }
        mNeedDetach = JNI_TRUE;
    }

    //通过全局变量g_obj 获取到要回调的类
    jclass javaClass = (env)->GetObjectClass(jClz);

    if (javaClass == 0) {
        LOGI("Unable to find class");
        (g_VM)->DetachCurrentThread();
        return;
    }


    jmethodID javaCallbackId = (env)->GetMethodID(javaClass, "netCallback", "(JJ)I");
    if (javaCallbackId == NULL) {
        LOGI("Unable to find method:netCallback");
        return;
    }


    //执行回调
    (env)->CallIntMethod(jClz, javaCallbackId, 1, 1);

    //释放当前线程
    if (mNeedDetach) {
        (g_VM)->DetachCurrentThread();
    }
    env = NULL;

}


extern "C"
JNIEXPORT jstring JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_libName(JNIEnv *env, jobject) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jboolean JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_hancNetSDKInit(JNIEnv *env, jobject thiz) {
    bool success = HancNetSDK_Init();
    (env)->GetJavaVM(&g_VM);
    jClz = (env)->NewGlobalRef(thiz);
    LOGI("Init jClz:%p,success:%d", &jClz, success);
    return static_cast<jboolean>(success);
}

extern "C"
JNIEXPORT jint JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_hancConnect(JNIEnv *env, jobject thiz,
                                                                    jstring zIp, jint zPort,
                                                                    jstring zCmd, jint timeout,
                                                                    jlong dwUser) {
    char *ip = const_cast<char *>(env->GetStringUTFChars(zIp, 0));
    char *cmd = const_cast<char *>(env->GetStringUTFChars(zCmd, 0));
    env->ReleaseStringUTFChars(zIp, ip);
    env->ReleaseStringUTFChars(zCmd, cmd);
    jClz = (env)->NewGlobalRef(thiz);
    LOGI("Connect jClz:%p", &jClz);
    void (*callback)(int _, char *pBuf, int nBufLen, long dwUser);
    callback = NetCallback;
    int cmdSize = strlen(cmd);
    int port = zPort;
    int errorCode = HancNetSDK_Connect(ip, port, cmd, cmdSize, timeout, callback,
                                          static_cast<long>(dwUser));
    return errorCode;
}





