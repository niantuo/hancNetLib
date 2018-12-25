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
#define CMS_LOGIN_CLIENT                        1

#define REGIONTABLE        1   //区域表
#define RECORDTABLE        2   //视频设备表
#define VIDEOCHANTABLE     3   //视频通道表
#define PRESETTABLE        4   //预置位列表
#define UNIONSOURTABLE     5  //报警源
#define UNIONCHANTABLE     6  //报警联动
#define UNIONPLANTABLE       7  //报警计划
#define DMATRIXSVRTABLE          8  //矩阵设备
#define DMATRIXSCREENTABLE       9  //矩阵输出
#define MAPTABLE                  10  //电子地图
#define NODEMAPTABLE              11  //地图节点
#define USERGROUPTABLE            12  //用户组
#define USERTABLE                 13  //用户
#define USERGROUPRIGHTTABLE          14 //用户组通道权限
#define TIMEPLANTABLE             15  //计划模版
#define RECORDPLANTABLE           16 //录象计划
#define EVENTLOGTABLE             17  //报警日志
#define OPERATELOGTABLE           18  //操作日志
#define USERVIDEOGROUP            19 //用户自定义视频分组,20150702
#define DEVGROUPTABLE              20 //系统分组
#define DEVGROUPCHANTABLE          21 //系统组通道
#define INTVSVRTABLE              22 //智能分析服务器
#define INTVCHANTABLE              23 //智能分析通道
#define SERVERTABLE               24 //服务器
#define DETECTRESULTTABLE         25 //诊断详细信息
#define PERSONTABLE               26 //人员信息表
#define USERVIDEOGROUPCHAN        27 //用户自定义视频分组,20150702
#define DEVICECONFIG              28 //设备配置



//数据库操作
#define DATAADD          1   //增
#define DATADEL          2   //删
#define DATAMODIFY       3   //改
#define DATAQUERY        4   //查
#define DATAQUERYMYSELF        5//自定义查询
#define DATAQUERYMYSELFEX        6//自定义查询

//节点类型
#define NORECORD        1
#define ALL_NODE                0//不考虑ID获取表全部数据
#define CURRENT_NODE            1//当前所在节点
#define PARENT_NODE                2//父节点
#define CALLSUB_NODE            3//从父节点向下找1

#define OPERATELOGIN        1 //登录
#define OPERATELOGOUT       2 //注销
#define OPERATEDISAPPEAR    3 //非正常退出
#define OPERATETRYLOGIN     4 //试图登陆
#define OPERATELOGINFAILD   5 //登陆失败
#define OPERATEVIDEOPLAY   6 //访问视频
#define OPERATEPTZCTRL     7 //云台控制
#define OPERATEVIDEOCTRL   8 //画面控制
#define OPERATEREPLAY      9 //回放录像
#define OPERATDOWNRECORD   10 //下载录像
#define OPERATESPEEKS      11 //语音对讲
#define OPERATELISTEN      12 //声音监听
#define OPERATESWITCH      13 //开关开
#define OPERATEOPERATEDOOR 14 //门操作
#define OPERATEDOORSETUP   15 //设置门
#define OPERATEREMOTESET    16 //远程配置
#define OPERATEVIEWALARMLOG 17 //查看报警记录
#define OPERATEVIEWOPERATELOG 18 //查看操作记录
#define OPERATEVIEWDATALOG    19 //查看历史数据
#define OPERATMATRIXVIEW      20 //矩阵点播
#define OPERATMATRIXAUTO      21 //矩阵自动播放
#define OPERATMATRIXARRAY     22 //矩阵布局
#define OPERATMANAGE          23 //系统管理

//操作
#define OPERATEERROR         -1 //异常
#define OPERATEOPEN        0 //打开
#define OPERATEOFF         1 //关闭
#define OPERATEPLAN        2 //计划


//通道类型定义
#define TYPEOFALL          -1 //未指定
#define TYPEOFVIDEOCHAN     0
#define TYPEOFALARMCHAN     1
#define TYPEOFALARMOUT      2
#define TYPEOFSENSORCHAN    3
#define TYPEOFDOORCHAN      4

//设备类型
#define TYPEOFCAMERA     0
#define TYPEOFDVR        1
#define TYPEOFDATADEV      2
#define TYPEOFFIBER        3


#define USEUPDATE 1
#define USEUPDATEFORCVR 1





//区域、用户与权限管理
///////////////////////////


typedef struct _msg_tree_region_base {
    int nID;
    char szName[50];
    int nParentID;
    char szDescription[100]; //描述
    unsigned int unIndex;
    unsigned int unRight;//区域权限
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
    unsigned int unRight;//区域权限
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
#if USEUPDATE
    int nPort2;
#endif
    int nServerType;
    char szSerial[40];      //序列号
    char szUser[20];
    char szPass[20];
    int nFactoryType;
    int nRegionID;
    int nState;//状态
    int nEmergencyStatus;//应急存储是否在线
#if USEUPDATE
    char szDescription[100];
    unsigned int unUpdateTime;
#endif

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
    unsigned char nPriority;        //级别
    int nOperateRight;    //操作权限
    int nAlarmRight;        //接警权限
    unsigned int nLoginTime;      //记录登陆时间，用于查询
    bool bUseDetailRight;
    int nUserGroupID;
    int nLoginFrom;
    int nDataBaseType;
    int nGroupID;
} MSG_USER_BASE, *LPMSG_USER_BASE;

//用户组信息
typedef struct _msg_usergroup_base {
    int nID;                //用户ID
    char szName[16];        //组名
    int nRegionID;            //区域内部编号
    int nPriority;            //级别
    int nOperateRight;        //操作权限
    bool bUseDetailRight;

} MSG_USERGROUP_BASE, *LPMSG_USERGROUP_BASE;



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


//视频设备信息
typedef struct _msg_recorddevice_base {
    unsigned long nID;                //内部编号
    char szName[50];        //服务器名称
    char szSerial[40];      //序列号
    char nHardType;            //硬件类型，0，IPC，1，DVS，2，采集服务器，3，报警设备
    char nLinkType;        //联网方式
    char nServerType;        //服务器类型0:海康 1：大华
    char szIP[50];            //服务器地址/域名
    int nPort;                //服务器端口
    char szUser[20];        //用户名
    char szPass[20];        //用户密码

#if USEUPDATE
    char szRemark[100];        //备注
#else
    char szRemark[200];		//备注
#endif
    int nRegionID;            //区域内部编号

    short nStorePos;
    short nMatixPos;
    char nSetAlarm;

    unsigned int unIndex;
    unsigned int unRight;//权限
#if USEUPDATE
    unsigned int unUpdateTime; //更新时间   -- updatetime
#endif
    unsigned int nStatus;

} MSG_RECORDDEVICE_BASE, *LPMSG_RECORDDEVICE_BASE;

//视频通道节点
typedef struct _msg_video_record_base {
    unsigned long nID;
    int nChan;            //通道号
    char szName[40];        //节点文本
    int nStorePos;        //存储中的通道索引
    int nDeviceID;        //父节点ID
    int nMatrixPos;        //矩阵索引号
    char nSetAlarm;
    char nLevel;        //报警级别
    int nType;        //通道类型
    char szPass[20];
    bool bDuplex;
    int nParam1;
    int nParam2;
    int nParam3;
    int nParam4;
#if USEUPDATE
    char szRemark[100];        //备注
    unsigned int unUpdateTime; //更新时间   -- updatetime
#endif

#if USEUPDATEFORCVR
    char szSerial[40];
#endif

#if USEUPDATE
    char szIP[20];
    char szUser[20];
    int nPort;//视频通道的情况下nParam1表示设备类型，nParam2表示是否报警
#endif
    unsigned int unIndex;
    unsigned int unRight;//权限
    unsigned int nStatus;
} MSG_VIDEO_RECORD_BASE, *LPMSG_VIDEO_RECORD_BASE;


//表枚举
typedef enum _ENUM_DATABASE_TABLE {

    REGION_TABLE = 1,//区域表

    DEVICE_TABLE = 2,  //设备列表

    CHAN_TABLE = 3,        //通道表

    GROUP_TABLE = 4,

    GROUP_CHAN_TABLE = 5,

    USERGROUP_TABLE = 6,

    USER_TABLE = 7,

    ALARMGROUP_TABLE = 8,

    ALARMGROUPCHAN_TABLE,

    ALARMGROUPPLAN_TABLE,

    ALARMGROUPUNION_TABLE,

    ALARMGROUPNOTIFY_TABLE,

    SERVER_TABLE = 13,

    SERVERCHAN_TABLE,

    MATRIX_TABLE,

    SCREEN_TABLE,

    MAP_TABLE,

    NODE_MAP_TABLE,

    PERSON_TABLE,

};


#endif //HANCNETLIB_JNIHANCNET_H

