#include <jni.h>
#include <string>
#include <hancnetsdk.h>

#define CMS_LOGIN_CLIENT  1
#define CMS_LOGIN_MOBI                            15 //手机端
#define CMS_MSG_LOGIN                      9 //登录

//通讯数据头，用于服务器间的数据通讯,所有向关设备，均使用此头进行通讯
typedef struct _msg_head_info {
    unsigned char nType;
    unsigned char nFrom;
    unsigned char nTo;
    int nFromClientID;  //预留
    int nToClientID;    //预留
} MSG_HEAD_INFO, *LPMSG_HEAD_INFO;

typedef struct _msg_user_info  //登录信息
{
    char szUser[100];
    char szPass[100];
    char szCenterIP[50];    //预留
} MSG_USER_INFO, *LPMSG_USER_INFO;



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
    head.nType = CMS_MSG_LOGIN;
    head.nFrom = CMS_LOGIN_MOBI;

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
    int nSession = HancNetSDK_CommunicateWithServerTcp(ip, port, buf, bufSize, &ppRecvBuf, pRecvLen,
                                                       5000, true);
    //ppRecvBuf就是得到的设备列表
    if (nSession > 0) {
        HancNetSDK_DataRelease(nSession);
    }

   jclass  clz = env->GetObjectClass(instance);
    jmethodID  callbackId = env->GetMethodID(clz,"callback","");

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


    return login(env,instance,const_cast<char *>(ip), port, const_cast<char *>(username),
                 const_cast<char *>(password));

//    env->ReleaseStringUTFChars(ip_, ip);
//    env->ReleaseStringUTFChars(username_, username);
//    env->ReleaseStringUTFChars(password_, password);
}
