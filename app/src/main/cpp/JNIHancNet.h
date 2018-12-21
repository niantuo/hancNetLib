//
// Created by niantuo on 2018/11/18.
//

#ifndef HANCNETLIB_JNIHANCNET_H
#define HANCNETLIB_JNIHANCNET_H

#define CMS_MSG_INVALID                    0 //未知指令
#define CMS_MSG_ALARM                      1 //报警
#define CMS_MSG_STATUS                     2 //状态
#define CMS_MSG_COMMAND                    3 //指令
#define CMS_MSG_NOTIFY                     4 //通知
#define CMS_MSG_PROCESS                    5 //处理
#define CMS_MSG_MESSAGE                    6 //文字信息
#define CMS_MSG_FILE                       7 //文件
#define CMS_MSG_LOG                        8 //日志
#define CMS_MSG_LOGIN                      9 //登录
#define CMS_MSG_RELOADDATA                 10 //复位数据
#define CMS_MSG_GETFILE                    11 //获取文件
#define CMS_MSG_WRITEFILE                  12 //写文件
#define CMS_MSG_DELETEFILE                 13 //删除文件
#define CMS_MSG_DETECT                     14 //智能检测
#define CMS_MSG_INTV                       15 //智能分析报警
#define CMS_MSG_OPERATION                  16 //操作指令
#define CMS_MSG_DBOPERATION                17 //数据库操作
#define CMS_MSG_LOGIN_EX                   18 //登陆，短连接主要是用于获取数据
#define CMS_MSG_SQLOPERATION               19 //执行SQL语句


#define CMS_LOGIN_MOBI                            15 //手机端
#define CMS_LOGIN_CLIENT                      1


#include <hancnetsdk.h>


//区域、用户与权限管理
///////////////////////////


typedef struct _msg_tree_region_base {
    int nID;
    char szName[50];
    int nParentID;
    char szDescription[100]; //描述
    unsigned int unIndex;
    bool bEnable;//有权限使用的区域
    bool bDisable;//禁用的范围，只为获得路径
} MSG_TREE_REGION_BASE, *LPMSG_TREE_REGION_BASE;


//分组
typedef struct _msg_tree_group_base {
    int nID;
    char szName[50];
    int nType;  //组类型
    int nParentID;
    int nRegionID; //区域id
    unsigned int unIndex;
    bool bEnable;//有权限使用的区域
} MSG_TREE_GROUP_BASE, *LPMSG_TREE_GROUP_BASE;


//通道分组
typedef struct _msg_changroup_base {
    int nID;
    int nDevID; //设备ID
    int nChan;
    int nDevType;
    int nChanType;
    int nGroupID; //组ID
    unsigned int unIndex;
} MSG_CHANGROUP_BASE, *LPMSG_CHANGROUP_BASE;


//系统服务器

typedef struct _msg_systemsrv_base {

    int nID;

    char szIP[16];

    int nPort;
    int nPort2;
    int nServerType;

    char szSerial[40];      //序列号

    char szUser[20];

    char szPass[20];

    int nFactoryType;

    int nRegionID;

    int nState;//状态

    int nAuthChans;

    int nLinkChans;

    int nLinkUsers;
    char szDescription[100];

    unsigned int unUpdateTime;

    long lUserID;

} MSG_SYSTEMSRV_BASE, *LPMSG_SYSTEMSRV_BASE;

typedef struct _msg_user_info  //登录信息
{
    char szUser[100];
    char szPass[100];
    char szCenterIP[50];
} MSG_USER_INFO, *LPMSG_USER_INFO;


typedef struct _msg_user_login_info  //登录信息
{
    char szUser[100];
    int nUserID;
    int nUserGroupID;
    int nRight;       //权限
    int nPrority;     //职能级别
    int nAlarmRight;
    int nRegionID;
    bool bUseDetailRight;
} MSG_USER_LOGIN_INFO, *LPMSG_USER_LOGIN_INFO;


typedef struct _msg_user_base {
    int nID;                //用户ID
    char szUser[16];        //用户名
    char szPass[16];        //用户密码
    int nRegionID;            //区域内部编号
    short nPriority;        //级别
    int nOperateRight;    //操作权限
    int nAlarmRight;        //接警权限
    unsigned int nLoginTime;      //记录登陆时间，用于查询
    bool bUseDetailRight;
    int nUserGroupID;
    int nLoginFrom;
    int nDataBaseType;

    int nGroupID;
} MSG_USER_BASE, *LPMSG_USER_BASE;

//通讯数据头，用于服务器间的数据通讯,所有向关设备，均使用此头进行通讯
typedef struct _msg_head_info {
    unsigned char nType;          //信息类型:=0或略，1报警，2，状态，3，设备事件,4,登录
    //5，资源请求，6,系统通知，7，推送信息，8，推送处理，9，推送文件，10,写日志
    //10,推送流式数据，11，响应
    unsigned char nFrom;          //类型来源:=0或略，1，客户端，2中心服务器，3，流媒体服务器，4，存储服务器，5，报警服务器，6，解码服务器，7，诊断，8，智能分析,9，服务器的延伸
    unsigned char nTo;            //送往用户的类型
    int nFromClientID;  //发送信息的用户，ID为用户系统中编号，用于客户端的通讯
    int nToClientID;    //接受信息的用户，ID为用户系统中编号，用于客户端的通讯
} MSG_HEAD_INFO, *LPMSG_HEAD_INFO;

typedef struct _msg_sql_info  //执行SQL语句
{
    int nType;       //1增加，2修改，3删除,4查询
    short nTable;   //表的类型
    char szSQL[1024];//直接执行SQL语句
//	int nID ;         //用于同步
} MSG_SQL_INFO, *LPMSG_SQL_INFO;

//查询返回的结果记录表，
typedef struct _msg_response_head {
    int nRecordSize;//数据个数
    unsigned char byTableType;//表类型

} MSG_RESPONSE_HEAD, *LPMSG_RESPONSE_HEAD;

//表枚举
typedef enum _ENUM_DATABASE_TABLE {

    REGION_TABLE = 1,//区域表

    DEVICE_TABLE,  //设备列表

    CHAN_TABLE,        //通道表

    GROUP_TABLE,

    GROUP_CHAN_TABLE,

    USERGROUP_TABLE,

    USER_TABLE,

    ALARMGROUP_TABLE,

    ALARMGROUPCHAN_TABLE,

    ALARMGROUPPLAN_TABLE,

    ALARMGROUPUNION_TABLE,

    ALARMGROUPNOTIFY_TABLE,

    SERVER_TABLE,

    SERVERCHAN_TABLE,

    MATRIX_TABLE,

    SCREEN_TABLE,

    MAP_TABLE,

    NODE_MAP_TABLE,

    PERSON_TABLE,

};




#endif //HANCNETLIB_JNIHANCNET_H
