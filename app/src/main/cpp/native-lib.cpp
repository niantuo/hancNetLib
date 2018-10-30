#include <jni.h>
#include <string>
#include <hancnetsdk.h>

#define CMS_LOGIN_CLIENT 1
#define CMS_LOGIN_MOBI                            15 //手机端
#define CMS_MSG_LOGIN                      9 //登录

//通讯数据头，用于服务器间的数据通讯,所有向关设备，均使用此头进行通讯
typedef struct _msg_head_info
{
    unsigned char   nType ;
    unsigned char   nFrom ;
    unsigned char   nTo ;
    int   nFromClientID ;  //预留
    int   nToClientID ;    //预留
}MSG_HEAD_INFO, * LPMSG_HEAD_INFO;

typedef struct _msg_user_info  //登录信息
{
    char szUser[100] ;
    char szPass[100] ;
    char szCenterIP[50] ;	//预留
}MSG_USER_INFO, * LPMSG_USER_INFO;


extern "C" JNIEXPORT jstring JNICALL
Java_cn_tonyandmoney_tina_camera_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_cn_tonyandmoney_tina_camera_support_HancNetSupport_libName(JNIEnv *env, jobject instance) {
    std::string libName="TinaMediaPlayer";
    return env->NewStringUTF(libName.c_str());
}






int login(char *ip,int port ,char *username,char *pass)
{
    bool result=  HancNetSDK_Init();

    MSG_HEAD_INFO head ;
    memset(&head ,0,sizeof(MSG_HEAD_INFO)) ;
    head.nType = CMS_MSG_LOGIN ;
    head.nFrom = CMS_LOGIN_MOBI ;

    int sss = sizeof(head);
    int hTypeSize = sizeof(head.nType);

    MSG_USER_INFO user ;
    memset(&user ,0,sizeof(MSG_USER_INFO)) ;
    sprintf(user.szUser,"%s",username) ;
    sprintf(user.szPass,"%s",pass) ;

    int bufSize = sizeof(MSG_HEAD_INFO)+ sizeof(MSG_USER_INFO);

    char *buf = new char[bufSize] ;
    memcpy(buf,&head,sizeof(MSG_HEAD_INFO)) ;
    memcpy(buf+sizeof(MSG_HEAD_INFO),&user,sizeof(MSG_USER_INFO)) ;

    char *ppRecvBuf = new char[1024] ;
    int  pRecvLen = 0 ;
    int nSession = HancNetSDK_CommunicateWithServerTcp(ip,port,buf,bufSize,&ppRecvBuf,pRecvLen,5000 ,true);
    //ppRecvBuf就是得到的设备列表
    if (nSession>0){
        HancNetSDK_DataRelease(nSession);
    }

}

/**
 * 测试登陆
 */
extern "C" void testCallback(void(*Callback)(char * p1),MSG_HEAD_INFO *info){
    Callback(const_cast<char *>("1234"));

    char * ip  ="127.0.0.1";
    char * username="1139231185";
    char * pwd="bgy842";

    login(ip, 3000, username,pwd);



}
