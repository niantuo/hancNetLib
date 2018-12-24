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

jstring ctojstring(JNIEnv *env, char* tmpstr) {
    jclass Class_string;
    jmethodID mid_String,mid_getBytes;
    jbyteArray bytes;
    jbyte* log_utf8;
    jstring codetype,jstr;
    Class_string = env->FindClass("java/lang/String");//获取class
    //先将gbk字符串转为java里的string格式
    mid_String = (env)->GetMethodID(Class_string, "<init>", "([BLjava/lang/String;)V");
    bytes = (env)->NewByteArray(strlen(tmpstr));
    (env)->SetByteArrayRegion(bytes, 0, strlen(tmpstr), (jbyte*)tmpstr);
    codetype = (env)->NewStringUTF("gbk");
    jstr = (jstring)(env)->NewObject(Class_string, mid_String, bytes, codetype);
    (env)->DeleteLocalRef(bytes);
    //再将string变utf-8字符串。
    mid_getBytes = (env)->GetMethodID(Class_string,"getBytes","(Ljava/lang/String;)[B");
    codetype = (env)->NewStringUTF("utf-8");
    bytes=(jbyteArray)(env)->CallObjectMethod(jstr,mid_getBytes,codetype);
    log_utf8=(env)->GetByteArrayElements(bytes,JNI_FALSE);
    return (env)->NewStringUTF(reinterpret_cast<const char *>(log_utf8));
}


/**
 * 传值。回调java
 * 1、NewStringUTF 中文异常
 * http://ftp.gnu.org/pub/gnu/libiconv/
 * 这里因为编码问题，c++包含中文，调用NewStringUTF 会导致崩溃，需要先将字符编码转为utf16,再传递给Java
 */
void CallJavaWithIntString(JNIEnv *env, jobject instance, int type, char *message) {
    jclass clz = env->GetObjectClass(instance);
    jmethodID callbackId = env->GetMethodID(clz, "callback", "(ILjava/lang/String;)V");
    jstring jMessage = ctojstring(env,message);
    env->CallVoidMethod(instance, callbackId, type, jMessage);
}

cJSON* UserToJsonObj(MSG_USER_BASE userBase) {
    //生成json字符串，回调给前端。
    cJSON *userRoot = cJSON_CreateObject();
    cJSON_AddItemToObject(userRoot, "nId", cJSON_CreateNumber(userBase.nID));
    cJSON_AddItemToObject(userRoot, "username", cJSON_CreateString(userBase.szUser));
    cJSON_AddItemToObject(userRoot, "password", cJSON_CreateString(userBase.szPass));
    cJSON_AddItemToObject(userRoot, "regionId", cJSON_CreateNumber(userBase.nRegionID));
    cJSON_AddItemToObject(userRoot, "nPriority", cJSON_CreateNumber(userBase.nPriority));
    cJSON_AddItemToObject(userRoot, "nOperateRight", cJSON_CreateNumber(userBase.nOperateRight));
    cJSON_AddItemToObject(userRoot, "nAlarmRight", cJSON_CreateNumber(userBase.nAlarmRight));
    cJSON_AddItemToObject(userRoot, "nLoginTime", cJSON_CreateNumber(userBase.nLoginTime));
    cJSON_AddItemToObject(userRoot, "bUseDetailRight", cJSON_CreateBool(userBase.bUseDetailRight));
    cJSON_AddItemToObject(userRoot, "nUserGroupId", cJSON_CreateNumber(userBase.nUserGroupID));
    cJSON_AddItemToObject(userRoot, "nLoginFrom", cJSON_CreateNumber(userBase.nLoginFrom));
    cJSON_AddItemToObject(userRoot, "nDataBaseType", cJSON_CreateNumber(userBase.nDataBaseType));
    cJSON_AddItemToObject(userRoot, "nGroupId", cJSON_CreateNumber(userBase.nGroupID));
    return userRoot;
}

cJSON * RegionToJsonArray(MSG_TREE_REGION_BASE regionBase) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "id", cJSON_CreateNumber(regionBase.nID));
    cJSON_AddItemToObject(root, "name", cJSON_CreateString(regionBase.szName));
    cJSON_AddItemToObject(root, "parentId", cJSON_CreateNumber(regionBase.nParentID));
    cJSON_AddItemToObject(root, "description", cJSON_CreateString(regionBase.szDescription));
    cJSON_AddItemToObject(root, "index", cJSON_CreateNumber(regionBase.unIndex));
    cJSON_AddItemToObject(root, "right", cJSON_CreateBool(regionBase.unRight));
    cJSON_AddItemToObject(root, "disable", cJSON_CreateBool(regionBase.bDisable));
    return root;
}

void AddToJsonArray(cJSON *array, MSG_SYSTEMSRV_BASE base) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "id", cJSON_CreateNumber(base.nID));
    cJSON_AddItemToObject(root, "ip", cJSON_CreateString(base.szIP));
    cJSON_AddItemToObject(root, "port", cJSON_CreateNumber(base.nPort));
    cJSON_AddItemToObject(root, "port2", cJSON_CreateNumber(base.nPort2));
    cJSON_AddItemToObject(root, "serverType", cJSON_CreateNumber(base.nServerType));
    cJSON_AddItemToObject(root, "serialNumber", cJSON_CreateString(base.szSerial));
    cJSON_AddItemToObject(root, "user", cJSON_CreateString(base.szUser));
    cJSON_AddItemToObject(root, "password", cJSON_CreateString(base.szPass));
    cJSON_AddItemToObject(root, "factoryType", cJSON_CreateNumber(base.nFactoryType));
    cJSON_AddItemToObject(root, "regionId", cJSON_CreateNumber(base.nRegionID));
    cJSON_AddItemToObject(root, "state", cJSON_CreateNumber(base.nState));
    cJSON_AddItemToObject(root, "nEmergencyStatus", cJSON_CreateNumber(base.nEmergencyStatus));
//    cJSON_AddItemToObject(root, "description", cJSON_CreateString(base.szDescription));
//    cJSON_AddItemToObject(root, "updateTime", cJSON_CreateNumber(base.unUpdateTime));
    cJSON_AddItemToArray(array, root);
}

void TreeGroupAddToArray(cJSON *array, MSG_TREE_GROUP_BASE base) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "id", cJSON_CreateNumber(base.nID));
    cJSON_AddItemToObject(root, "name", cJSON_CreateString(base.szName));
    cJSON_AddItemToObject(root, "type", cJSON_CreateNumber(base.nType));
    cJSON_AddItemToObject(root, "parentId", cJSON_CreateNumber(base.nParentID));
    cJSON_AddItemToObject(root, "regionId", cJSON_CreateNumber(base.nRegionID));
    cJSON_AddItemToObject(root, "index", cJSON_CreateNumber(base.unIndex));
    cJSON_AddItemToObject(root, "enable", cJSON_CreateBool(base.bEnable));
    cJSON_AddItemToArray(array, root);
}

void CHANGROUP_Add_To_Array(cJSON *array, MSG_CHANGROUP_BASE base) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "id", cJSON_CreateNumber(base.nID));
    cJSON_AddItemToObject(root, "devId", cJSON_CreateNumber(base.nDevID));
    cJSON_AddItemToObject(root, "chan", cJSON_CreateNumber(base.nChan));
    cJSON_AddItemToObject(root, "devType", cJSON_CreateNumber(base.nDevType));
    cJSON_AddItemToObject(root, "chanType", cJSON_CreateNumber(base.nChanType));
    cJSON_AddItemToObject(root, "groupId", cJSON_CreateNumber(base.nGroupID));
    cJSON_AddItemToObject(root, "index", cJSON_CreateNumber(base.unIndex));
    cJSON_AddItemToArray(array, root);
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
    int nSession = HancNetSDK_CommunicateWithServerTcp(ip, port, buf, bufSize, &ppRecvBuf, pRecvLen,
                                                       15000, true);

    if (nSession == -1) {
        return -1;
    }
    if (pRecvLen == 0) {
        HancNetSDK_DataRelease(nSession);
        return 4;
    }
    if (pRecvLen == 4) //状态
    {
        unsigned long dwStat = *((unsigned *) ppRecvBuf);
        HancNetSDK_DataRelease(nSession);
        return static_cast<int>(dwStat);
    }

    MSG_USER_BASE userBase;
    cJSON *root = cJSON_CreateObject();
    int headLen = sizeof(MSG_RESPONSE_HEAD);
    while (pRecvLen > headLen) {
        LPMSG_RESPONSE_HEAD responseHead = (LPMSG_RESPONSE_HEAD) ppRecvBuf;
        ppRecvBuf += headLen;
        pRecvLen -= headLen;
        if (responseHead->byTableType == USER_TABLE) {

            memcpy(&userBase, ppRecvBuf, sizeof(MSG_USER_BASE));
            ppRecvBuf += sizeof(MSG_USER_BASE);
            pRecvLen -= sizeof(MSG_USER_BASE);

            cJSON *userRoot = UserToJsonObj(userBase);
            CallJavaWithIntString(env, instance, nSession, cJSON_Print(userRoot));
            cJSON_AddItemToObject(root,"user",userRoot);

        } else if (responseHead->byTableType == REGIONTABLE) {
            cJSON *array = cJSON_CreateArray();
            size_t regionLen = sizeof(MSG_TREE_REGION_BASE);
            for (int i = 0; i < responseHead->nRecordSize; ++i) {
                MSG_TREE_REGION_BASE lpRegion;
                memcpy(&lpRegion, ppRecvBuf, regionLen);
                ppRecvBuf += regionLen;
                pRecvLen -= regionLen;
                cJSON *item = RegionToJsonArray(lpRegion);
                cJSON_AddItemToArray(array, item);
                const char * json = cJSON_Print(item);
                CallJavaWithIntString(env, instance, nSession, cJSON_Print(item));
            }
            cJSON_AddItemToObject(root, "regions", array);
            CallJavaWithIntString(env, instance, nSession, cJSON_Print(array));
        } else if (responseHead->byTableType == SERVER_TABLE) {
            cJSON *array = cJSON_CreateArray();
            size_t lpServerLen = sizeof(MSG_SYSTEMSRV_BASE);

            for (int i = 0; i < responseHead->nRecordSize; i++) {
                MSG_SYSTEMSRV_BASE lpServer;
                memcpy(&lpServer, ppRecvBuf, lpServerLen);
                ppRecvBuf += lpServerLen;
                pRecvLen -= lpServerLen;
                AddToJsonArray(array, lpServer);
            }
            cJSON_AddItemToObject(root, "serverList", array);
            CallJavaWithIntString(env, instance, nSession, cJSON_Print(array));
        } else if (responseHead->byTableType == GROUP_TABLE) {
            cJSON *array = cJSON_CreateArray();
            for (int i = 0; i < responseHead->nRecordSize; i++) {
                MSG_TREE_GROUP_BASE lpGroup;
                memcpy(&lpGroup, ppRecvBuf, sizeof(MSG_TREE_GROUP_BASE));
                ppRecvBuf += sizeof(MSG_TREE_GROUP_BASE);
                pRecvLen -= sizeof(MSG_TREE_GROUP_BASE);
                TreeGroupAddToArray(array, lpGroup);
            }
            cJSON_AddItemToObject(root, "group", array);
            CallJavaWithIntString(env, instance, nSession, cJSON_Print(array));
        } else if (responseHead->byTableType == GROUP_CHAN_TABLE) {
            cJSON *array = cJSON_CreateArray();
            size_t chanGroupLen = sizeof(MSG_CHANGROUP_BASE);
            for (int i = 0; i < responseHead->nRecordSize; i++) {
                MSG_CHANGROUP_BASE lpGroupChan;
                memcpy(&lpGroupChan, ppRecvBuf,chanGroupLen);
                ppRecvBuf += chanGroupLen;
                pRecvLen -= chanGroupLen;
                CHANGROUP_Add_To_Array(array, lpGroupChan);
            }
            CallJavaWithIntString(env, instance, nSession, cJSON_Print(array));
            cJSON_AddItemToObject(root, "groupChan", array);
        } else if (responseHead->byTableType == DEVICE_TABLE) {
            size_t recordDeviceLen = sizeof(MSG_RECORDDEVICE_BASE);//长度：320
            for (int i = 0; i < responseHead->nRecordSize; ++i) {

                MSG_RECORDDEVICE_BASE dev ;
                memset(&dev,0,recordDeviceLen) ;

                memcpy(&dev,ppRecvBuf,recordDeviceLen);
                ppRecvBuf += recordDeviceLen;
                pRecvLen -= recordDeviceLen;

            }
        } else if (responseHead->byTableType == VIDEOCHANTABLE) {
            for (int i = 0; i < responseHead->nRecordSize; i++) {
                MSG_VIDEO_RECORD_BASE base;
                memcpy(&base, ppRecvBuf, sizeof(MSG_VIDEO_RECORD_BASE));

                ppRecvBuf += sizeof(MSG_VIDEO_RECORD_BASE);
                pRecvLen -= sizeof(MSG_VIDEO_RECORD_BASE);

            }
        } else if (responseHead->byTableType == SERVERTABLE)//服务器
        {
            for (int i = 0; i < responseHead->nRecordSize; i++) {
                LPMSG_SYSTEMSRV_BASE lpServer = new(MSG_SYSTEMSRV_BASE);
                memset(lpServer, 0, sizeof(MSG_SYSTEMSRV_BASE));
                memcpy(lpServer, ppRecvBuf, sizeof(MSG_SYSTEMSRV_BASE));

                ppRecvBuf += sizeof(MSG_SYSTEMSRV_BASE);
                pRecvLen -= sizeof(MSG_SYSTEMSRV_BASE);

            }
        } else if (responseHead->byTableType==USERGROUP_TABLE){
            for (int i = 0; i < responseHead->nRecordSize; ++i) {
                MSG_USERGROUP_BASE usergroupBase;
                memcpy(&usergroupBase,ppRecvBuf, sizeof(MSG_USERGROUP_BASE));
                ppRecvBuf+= sizeof(MSG_USERGROUP_BASE);
                pRecvLen-= sizeof(MSG_USERGROUP_BASE);
            }
        }

    }


    CallJavaWithIntString(env, instance, nSession, cJSON_Print(root));
    HancNetSDK_DataRelease(nSession);
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