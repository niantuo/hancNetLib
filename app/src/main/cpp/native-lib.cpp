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
 * 初始化SDK
 * @return
 */
extern "C"
bool hancNetSdkInit() {
    return HancNetSDK_Init();
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
int login(char *ip, int port, char *username, char *pass) {
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

    char *ppRecvBuf = new char[1024];
    int pRecvLen = 0;
    int nSession = HancNetSDK_CommunicateWithServerTcp(ip, port, buf, bufSize, &ppRecvBuf, pRecvLen,
                                                       5000, true);
    //ppRecvBuf就是得到的设备列表
    if (nSession > 0) {
        HancNetSDK_DataRelease(nSession);
    }
    return nSession;
}
