#include <jni.h>
#include <string>
#include "cJSON.h"
#include "JNIHancNet.h"


/**
 * 回调java 字符类型的数据。
 * 一般是json 格式的字符串。必须定义好格式。
 */
void CallJavaWithString(JNIEnv *env, jobject instance, char *message) {
    jclass clz = env->GetObjectClass(instance);
    jmethodID callbackId = env->GetMethodID(clz, "callback", "(Ljava/lang/String;)V");
    jstring jMessage = env->NewStringUTF(message);
    env->CallVoidMethod(instance, callbackId, jMessage);
}


/**
 * 传值。回调java
 */
void CallJavaWithIntString(JNIEnv *env, jobject instance, int type, char *message) {
    jclass clz = env->GetObjectClass(instance);
    jmethodID callbackId = env->GetMethodID(clz, "callback", "(ILjava/lang/String;)V");
    jstring jMessage = env->NewStringUTF(message);
    env->CallVoidMethod(instance, callbackId, type, jMessage);
}

/**
 * 登陆到服务端，如何从返回的数据中拿到设备信息呢？
 * @param ip
 * @param port
 * @param username
 * @param pass
 * @return
 */
extern "C"
int login(JNIEnv *env, jobject instance, char *ip, int port, char *username, char *pass) {
    MSG_HEAD_INFO head;
    memset(&head, 0, sizeof(MSG_HEAD_INFO));

    head.nType = CMS_MSG_LOGIN_EX;
    head.nFrom = CMS_LOGIN_CLIENT;

    MSG_USER_INFO user;
    memset(&user, 0, sizeof(MSG_USER_INFO));
    sprintf(user.szUser, "%s", username);
    sprintf(user.szPass, "%s", pass);

    int bufSize = sizeof(MSG_HEAD_INFO) + sizeof(MSG_USER_INFO);

    char *buf = new char[bufSize];
    memcpy(buf, &head, sizeof(MSG_HEAD_INFO));
    memcpy(buf + sizeof(MSG_HEAD_INFO), &user, sizeof(MSG_USER_INFO));

    char *ppRecvBuf = NULL;
    int pRecvLen = 0;
    int nSession = HancNetSDK_CommunicateWithServerTcp(ip, port, buf, bufSize, &ppRecvBuf, pRecvLen, 15000, true);


    //ppRecvBuf就是得到的设备列表

    MSG_RESPONSE_HEAD response_head;

    if (nSession>-1&&ppRecvBuf!=NULL){
        memcpy(&response_head,ppRecvBuf, sizeof(MSG_RESPONSE_HEAD));

        MSG_USER_BASE userBase;
        memcpy(&userBase,ppRecvBuf+ sizeof(MSG_RESPONSE_HEAD), sizeof(MSG_USER_BASE));
        //生成json字符串，回调给前端。
        cJSON *root = cJSON_CreateObject();
        cJSON_AddItemToObject(root, "nId", cJSON_CreateNumber(userBase.nID));
        cJSON_AddItemToObject(root, "username", cJSON_CreateString(userBase.szUser));
        cJSON_AddItemToObject(root,"password",cJSON_CreateString(userBase.szPass));
        cJSON_AddItemToObject(root,"regionId",cJSON_CreateNumber(userBase.nRegionID));
        cJSON_AddItemToObject(root,"nPriority",cJSON_CreateNumber(userBase.nPriority));
        cJSON_AddItemToObject(root,"nOperateRight",cJSON_CreateNumber(userBase.nOperateRight));
        cJSON_AddItemToObject(root,"nAlarmRight",cJSON_CreateNumber(userBase.nAlarmRight));
        cJSON_AddItemToObject(root,"nLoginTime",cJSON_CreateNumber(userBase.nLoginTime));
        cJSON_AddItemToObject(root,"bUseDetailRight",cJSON_CreateBool(userBase.bUseDetailRight));
        cJSON_AddItemToObject(root,"nUserGroupId",cJSON_CreateNumber(userBase.nUserGroupID));
        cJSON_AddItemToObject(root,"nLoginFrom",cJSON_CreateNumber(userBase.nLoginFrom));
        cJSON_AddItemToObject(root,"nDataBaseType",cJSON_CreateNumber(userBase.nDataBaseType));
        cJSON_AddItemToObject(root,"nGroupId",cJSON_CreateNumber(userBase.nGroupID));
        CallJavaWithIntString(env, instance, nSession, cJSON_Print(root));
    }
    if (nSession > 0) {
        HancNetSDK_DataRelease(nSession);
    }
    return nSession;
}

/**
 * 初始化SDK
 * @return
 */
extern "C"
JNIEXPORT jboolean JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_init(JNIEnv *env, jobject instance) {
    return static_cast<jboolean>(HancNetSDK_Init());
}


/**
 * 登陆到服务器获取设备数据
 * @return
 */
extern "C"
JNIEXPORT jint JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_loginToServer(JNIEnv *env, jobject instance,
                                                                      jstring ip_, jint port,
                                                                      jstring username_,
                                                                      jstring password_) {
    const char *ip = env->GetStringUTFChars(ip_, 0);
    const char *username = env->GetStringUTFChars(username_, 0);
    const char *password = env->GetStringUTFChars(password_, 0);


    return login(env, instance, const_cast<char *>(ip), port, const_cast<char *>(username),
                 const_cast<char *>(password));

//    env->ReleaseStringUTFChars(ip_, ip);
//    env->ReleaseStringUTFChars(username_, username);
//    env->ReleaseStringUTFChars(password_, password);
}

/**
 * 修改buffer中的值，Android端也同样会变化，用来传递视频信息。
 */
extern "C"
JNIEXPORT jint JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_startMediaPlay(JNIEnv *env,
                                                                       jobject instance,
                                                                       jobject buffer, jint len,
                                                                       jint session) {

    unsigned char *pBuffer = (unsigned char *) (env->GetDirectBufferAddress(buffer));
    if (pBuffer == NULL) {
        CallJavaWithIntString(env, instance, -1, const_cast<char *>("buffer 未初始化。"));
    } else {


    }

}