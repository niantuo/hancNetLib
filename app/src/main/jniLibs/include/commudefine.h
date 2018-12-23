//commudefine.h

#if !defined(AFX_COMMUDEFINE_H)
#define AFX_COMMUDEFINE_H

#pragma once
#define MAXSTATECHAN  32
#define MAXDATAS      16

//定义宏
//数据库表宏定义
#define REGIONTABLE        1   //区域表
#define RECORDTABLE        2   //视频设备表
#define VIDEOCHANTABLE     3   //视频通道表
#define PRESETTABLE        4   //预置位列表

#define UNIONSOURTABLE     5  //报警源
#define UNIONCHANTABLE     6  //报警联动
#define UNIONPLANTABLE	   7  //报警计划

#define DMATRIXSVRTABLE          8  //矩阵设备
#define DMATRIXSCREENTABLE       9  //矩阵输出

#define MAPTABLE                  10  //电子地图
#define NODEMAPTABLE              11  //地图节点

#define USERGROUPTABLE            12  //用户组
#define USERTABLE                 13  //用户
#define USERGROUPRIGHTTABLE		  14 //用户组通道权限

#define TIMEPLANTABLE             15  //计划模版
#define RECORDPLANTABLE           16 //录象计划

#define EVENTLOGTABLE             17  //报警日志
#define OPERATELOGTABLE           18  //操作日志

#define USERVIDEOGROUP            19 //用户自定义视频分组,20150702


#define DEVGROUPTABLE			  20 //系统分组
#define DEVGROUPCHANTABLE		  21 //系统组通道

#define INTVSVRTABLE			  22 //智能分析服务器
#define INTVCHANTABLE			  23 //智能分析通道

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
#define NORECORD		1

#define ALL_NODE			    0//不考虑ID获取表全部数据
#define CURRENT_NODE			1//当前所在节点
#define PARENT_NODE			    2//父节点
#define CALLSUB_NODE			3//从父节点向下找

typedef enum _UPDATE_DATA_TYPE
{
	UPDATE_DEFENCE = 1,  //更新防区
	UPDATE_GROUP,        //更新分组
	UPDATE_BASE,         //区域设备通道
	UPDATE_SERVER,       //服务器
	UPDATE_RULE,         //规则
	UPDATE_RECORD,       //录象配置
}UPDATE_DATA_TYPE;


typedef enum _ENUM_DATABASE_TABLE
{
	REGION_TABLE = 1,//区域表
	DEVICE_TABLE ,  //设备列表
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

typedef enum _NOTIFY_TYPE
{
	NOTIFY_CLIENT = 0,  //客户端
	NOTIFY_APP,       //手机app
	NOTIFY_CMS,       //上级平台
	NOTIFY_UNIONSVR,       //联动服务
	NOTIFY_INTVSVR,       //智能服务
	NOTIFY_MSG,       //短信
	NOTIFY_MAIL,      //邮件
}NOTIFY_TYPE;


typedef enum _ALARMGROUP_NOTIFY
{
	NOTIFY_ALLCLIENT = 0xff,  //所有
	NOTIFY_REGION = 1,  //通知本级区域
	NOTIFY_PARENT,        //通知上级区域
	NOTIFY_GROUP_CLIENT,
	NOTIFY_MOBIAPP,
	NOTIFY_EMAIL,
	NOTIFY_MESSAGE,
}ALARMGROUP_NOTIFY;

//权限
typedef enum _USERGROUP_RIGHT
{
	RIGHT_LIVE = 0,  //实时
	RIGHT_RECORD,    //回放
	RIGHT_PTZ,       //云台
	RIGHT_MATRIX,    //矩阵
	RIGHT_LOG,       //日志
	RIGHT_OPERATION, //运维
	RIGHT_TIME,      //时间控制
	RIGHT_MAP,        
}USERGROUP_RIGHT;

//操作日志宏定义20150808

typedef enum _OPERATION_TYPE_
{
	OP_LOGIN  =  1,     //登录
	OP_LOGOUT ,         //注销
	OP_LOGOUT_ABNORMAL, //非正常退出
	OP_LOGIN_TRY,       //试图登陆
	OP_LOGIN_FAILD,     //登陆失败
	OP_LIVE,            //访问视频
	OP_LIVE_STOP,       //关闭视频
	OP_PLAYBACK,        //访问录像
	OP_PLAYBACK_STOP,   //关闭视频
	OP_PTZ_START,       //云台控制
	OP_PTZ_STOP,        //云台控制停
	OP_SPEEK_START,     //启动对讲
	OP_SPEEK_STOP,      //停止对讲
	OP_REMOTE_DOOROPEN,      //远程开门
	OP_REMOTE_DOORCLOSE,      //远程关门
}OPERATION_TYPE;

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
///////////////////////////
//区域、用户与权限管理
///////////////////////////

typedef struct _msg_region_base
{
	int nID;
	char szName[50];
	int nParentID;
	char szDescription[100]; //描述
	bool bCenter;
	char szIP[16];
	int  nPort ;

	bool bEnable;

#if USEUPDATE
	char szSerial[40];
	unsigned int unIndex ;
	unsigned int unUpdateTime ;
#endif

}MSG_REGION_BASE, * LPMSG_REGION_BASE;


typedef struct _msg_tree_region_base
{
	int  nID;
	char szName[50];
	int  nParentID;
	char szDescription[100]; //描述
	unsigned int unIndex ;
	bool bEnable ;//有权限使用的区域
	bool bDisable ;//禁用的范围，只为获得路径
}MSG_TREE_REGION_BASE, * LPMSG_TREE_REGION_BASE;

//分组
typedef struct _msg_tree_group_base
{
	int  nID  ;
	char szName[50] ;
	int  nType ;  //组类型
	int  nParentID ;
	int  nRegionID ; //区域id
	unsigned int unIndex ;
	bool bEnable ;//有权限使用的区域
}MSG_TREE_GROUP_BASE, * LPMSG_TREE_GROUP_BASE;


//分组
typedef struct _msg_devgroup_base
{
	int  nID  ;
	char szName[50] ;
	int  nType ;  //组类型
	int  nParentID ;
	int  nRegionID ; //区域id
	unsigned int unIndex ;
}MSG_DEVGROUP_BASE, * LPMSG_DEVGROUP_BASE;
//通道分组
typedef struct _msg_changroup_base
{
	int  nID  ;
	int   nDevID ; //设备ID
	int  nChan  ;
	int  nDevType ;
	int  nChanType ;
	int   nGroupID ; //组ID
	unsigned int unIndex ;
}MSG_CHANGROUP_BASE, * LPMSG_CHANGROUP_BASE;

typedef struct _msg_user_info  //登录信息
{
	char szUser[100] ;	
	char szPass[100] ;	
	char szCenterIP[50] ;	
}MSG_USER_INFO, * LPMSG_USER_INFO;


typedef struct _msg_user_login_info  //登录信息
{
	char szUser[100] ;	
	int  nUserID ;
	int  nUserGroupID ;
	int  nRight ;       //权限
	int  nPrority ;     //职能级别
	int  nAlarmRight ;
	int  nRegionID ;
	bool bUseDetailRight ;
}MSG_USER_LOGIN_INFO, * LPMSG_USER_LOGIN_INFO;

typedef struct _msg_usergroup_base
{
	int  nID;				//用户ID
	char szName[16];		//组名
	int  nRegionID;			//区域内部编号
	int  nPriority;			//级别	
	int  nOperateRight;		//操作权限
	bool bUseDetailRight;
    
}MSG_USERGROUP_BASE, * LPMSG_USERGROUP_BASE;

typedef struct _msg_usergroupright_base
{
	int  nID;				//ID
	int  nUserGroupid;		//用户组编号
	int  nAreaid;			//角色管理的范围
	int  nType;             //区域类型
}MSG_USERGROUPRIGHT_BASE, * LPMSG_USERGROUPRIGHT_BASE;

typedef struct _msg_userinfo_base
{
	int  nID;				//用户ID
	char szUser[16];		//用户名
	char szPass[16];		//用户密码
	int  nUserGroupID ;		//所属用户组ID
	int  nAlarmRight ;
	char szRealName[20];
	char szCellphone[12];
	char szOfficephone[20];
	char szHomephone[20];

}MSG_USERINFO_BASE, * LPMSG_USERINFO_BASE;


typedef struct _msg_user_base
{
	int  nID;				//用户ID
	char szUser[16];		//用户名
	char szPass[16];		//用户密码
	int  nRegionID;			//区域内部编号
	BYTE  nPriority;		//级别	
	int   nOperateRight;	//操作权限
	int   nAlarmRight;		//接警权限
	unsigned int nLoginTime;      //记录登陆时间，用于查询
	bool bUseDetailRight;
	int  nUserGroupID ;
	int  nLoginFrom ;
	int  nDataBaseType ;

#if USEUPDATE
	int nGroupID ;
#endif
}MSG_USER_BASE, * LPMSG_USER_BASE;

typedef struct _msg_userright_base
{
	int nID ;
	int nVistorRegionID ;
	int nRegionType ;
}MSG_USERRIGHT_BASE, * LPMSG_USERRIGHT_BASE;

///////////////////////////////////
//视频设备
///////////////////////////////////
//视频设备(录像机、相机)


//视频设备信息
typedef struct _msg_recorddevice_base
{
	DWORD  nID;			    //内部编号
	char szName[50];        //服务器名称
	char szSerial[40];      //序列号
	char   nHardType;			//硬件类型，0，IPC，1，DVS，2，采集服务器，3，报警设备
	char  nLinkType ;        //联网方式
	char  nServerType;		//服务器类型0:海康 1：大华
	char szIP[50];	        //服务器地址/域名
	int  nPort;		        //服务器端口
	char szUser[20];		//用户名
	char szPass[20];		//用户密码

#if USEUPDATE
	char szRemark[100];		//备注
#else
	char szRemark[200];		//备注
#endif
	int    nRegionID;			//区域内部编号
	
	SHORT  nStorePos ;
	SHORT  nMatixPos ;
	char   nSetAlarm ;

	unsigned int unIndex ;
#if USEUPDATE
	unsigned int unUpdateTime; //更新时间   -- updatetime
#endif
	unsigned int nStatus ;
	
}MSG_RECORDDEVICE_BASE, * LPMSG_RECORDDEVICE_BASE;


//视频通道节点
typedef struct _msg_video_record_base
{
	DWORD  nID ;
	int   nChan;		    //通道号
	char  szName[40];	    //节点文本
	int   nStorePos;		//存储中的通道索引
	int   nDeviceID ;	    //父节点ID
	int   nMatrixPos;		//矩阵索引号
	char  nSetAlarm ;
	char  nLevel;		//报警级别
	int   nType;        //通道类型
	char  szPass[20];
	bool  bDuplex ;
	int nParam1;
    int nParam2;
    int nParam3;
    int nParam4;
#if USEUPDATE
	char szRemark[100];		//备注
	unsigned int unUpdateTime; //更新时间   -- updatetime
#endif

#if USEUPDATEFORCVR
	char szSerial[40];
#endif

#if USEUPDATE
	char szIP[20];
	char szUser[20];
	int  nPort ;//视频通道的情况下nParam1表示设备类型，nParam2表示是否报警
#endif
	unsigned int unIndex ;
	unsigned int  nStatus ;
}MSG_VIDEO_RECORD_BASE, * LPMSG_VIDEO_RECORD_BASE; 




//////////////////////////////////
//矩阵设备
/////////////////////////////////
//数字矩阵信息
typedef struct _msg_matrixsvr_base
{
	int   nID ;
	char  szName[100];
	char  szIp[50];
	int   nPort ;
	int   nRegionID ;
	char   nMatrixType ;
	char   nScreenNum ;
}MSG_MATRIXSVR_BASE , * LPMSG_MATRIXSVR_BASE;


typedef struct _msg_screen_matrixsvr_base
{	
	int   nID ; //ID号
	char  szName[50];
	char   nScreenNum ;//监视器号
	char   nSubScreenNum ;//子窗口个数量,20150812实际现在是数据库存放的索引号=系统编号
	int   nMatrixID ;	//矩阵主机
	unsigned short   nX ;
	unsigned short   nY ;
	unsigned short   nW ;
	unsigned short   nH ;
}MSG_SCREEN_MATRIXSVR_BASE, * LPMSG_SCREEN_MATRIXSVR_BASE;

//////////////////////////
//地图
//////////////////////////
//地图信息
typedef struct _msg_map_base
{
	int  nID;			//地图编号
	char szName[50];	//地图名称
	char  nMapType;
	int  nParentID;		//父区域内部编号
	int  nRegionID;		//父区域内部编号
	int  nImageType;
	int  nImageSize ;   //地图数据大小
}MSG_MAP_BASE, * LPMSG_MAP_BASE;

typedef struct _msg_node_map_base
{
	int  nID;			//节点内部编号
	char  nType;			//类型0:地图 2：通道
	char szName[50];	//区域名称
	int  nDeviceID;     //类型为2时，代表设备ID,类型为0时，代表地图的ID
	char  nDeviceType;	//设备类型
	int   nChan ;        //通道号
	char  nChanType;		//通道类型, 0为视频通道，1为输入通道
	char  nNodeType ;    //图标类型,可使用不同的图标标识地图
	int  nMapID;		//父区域内部编号
	int  nX;
	int  nY;
	int  nNextX;
	int  nNextY;
}MSG_NODE_MAP_BASE, * LPMSG_NODE_MAP_BASE;

//////////////////////////////
//存储
//////////////////////////////
typedef struct _msg_recordsvr_base
{
	int  nID;
	char szIP[16];
	int  nPort;
	char  nServerType;
	char szUser[16];
	char szPass[16];
	int  nRegionID;
}MSG_RECORDSVR_BASE, * LPMSG_RECORDSVR_BASE;


//////////////////////////////////
//流媒体
/////////////////////////////////
typedef struct _msg_mediasrv_base
{
	int  nID;
	char szIP[16];
	int  nPort;
	int  nRegionID;

	char nWorkMode;
	char szPush[50];

}MSG_MEDIASRV_BASE, * LPMSG_MEDIASRV_BASE;

//通讯数据头，用于服务器间的数据通讯,所有向关设备，均使用此头进行通讯
typedef struct _msg_head_info
{
	BYTE   nType ;          //信息类型:=0或略，1报警，2，状态，3，设备事件,4,登录
	                       //5，资源请求，6,系统通知，7，推送信息，8，推送处理，9，推送文件，10,写日志
	                       //10,推送流式数据，11，响应
	BYTE   nFrom ;          //类型来源:=0或略，1，客户端，2中心服务器，3，流媒体服务器，4，存储服务器，5，报警服务器，6，解码服务器，7，诊断，8，智能分析,9，服务器的延伸
    BYTE   nTo ;            //送往用户的类型
	int   nFromClientID ;  //发送信息的用户，ID为用户系统中编号，用于客户端的通讯
	int   nToClientID ;    //接受信息的用户，ID为用户系统中编号，用于客户端的通讯
}MSG_HEAD_INFO, * LPMSG_HEAD_INFO;

typedef struct _msg_vca_rect{
	USHORT		x;
	USHORT		y;
	USHORT		w;
	USHORT		h;
}MSG_VCA_RECT,*LPMSG_VCA_RECT;	

//预置位信息
typedef struct _msg_preset_base
{
	int    nID ;   //预置位自身IP
	char    nDeviceID ;//和通道ID二选一
	int    nChan     ;//和通道ID二选一
	char   szName[100];	//名称
	char    nIndex;		//预置点编号
	unsigned int nStayTime;		//停留时间
}MSG_PRESET_BASE, * LPMSG_PRESET_BASE; 


//智能分析服务器
typedef struct _msg_intvsrv_base
{
	int  nID;
	char szIP[16];
	int  nRegionID;
	int  nPort;
	int  nPortCfg;
	char szUser[20];
	char szPass[20];
}MSG_INTVSRV_BASE, * LPMSG_INTVSRV_BASE;

typedef struct _msg_intvchan_base
{
	int  nID;
	int  nIntvID;
	int  nDevID;
	int  nChan;
	char  nStream;
	char  nStyle;

}MSG_INTVCHAN_BASE, * LPMSG_INTVCHAN_BASE;



//短连接的命令数据

typedef struct _msg_time_base
{
	WORD  dwYear;
	WORD  dwMonth;
	WORD  dwDay;
	WORD  dwHour;
	WORD  dwMinute;
	WORD  dwSecond;
}MSG_TIME_BASE,*LPMSG_TIME_BASE;
//20150701
typedef struct _msg_dev_query
{
	int  nType ;        //类型：0，全部，1，根据区域查找，2，根据设备查找，3根据通道查找
	int  nRegionID ;    //区域ID
	int  nDeviceID;	    //设备ID
	char  nDeviceType ;  //设备类型
	int   nChanNo;		//通道号
	char  nChanType;     //通道类型
}MSG_DEV_QUERY, * LPMSG_DEV_QUERY;

typedef struct _msg_time_query
{
	MSG_TIME_BASE tmStart ;
	MSG_TIME_BASE tmStop ;
	bool bUser ;
}MSG_TIME_QUERY,*LPMSG_TIME_QUERY;

typedef struct _msg_dboperate_info  //执行SQL语句
{
	int nType ;	   //1增加，2修改，3删除,4查询
	SHORT nTable ;   //表的类型
	char nNodeType ;//节点类型,0，本级节点，1，父节点，2，当前节点以下节点
	int nNodeID ;  //节点ID
}MSG_DBOPERATE_INFO, * LPMSG_DBOPERATE_INFO;

typedef struct _msg_sql_info  //执行SQL语句
{
	int nType ;	   //1增加，2修改，3删除,4查询
	SHORT nTable ;   //表的类型
	char szSQL[1024] ;//直接执行SQL语句
}MSG_SQL_INFO, * LPMSG_SQL_INFO;


/*短连接数据交互*/

//20150720 接报警联动计划 

typedef struct _msg_plan_info  //20150629计划
{
	BYTE bPlans[7][48];        //计划
}MSG_PLAN_INFO, * LPMSG_PLAN_INFO;

typedef struct _msg_union_plan  
{
	int   nID ;
	int   nSourceID;	
	DWORD  nAlarmType ;
	MSG_PLAN_INFO plan ;
}MSG_UNION_PLAN, * LPMSG_UNION_PLAN;

typedef struct _msg_union_plan_new  
{
	int   nID ;
	int   nDevID;		//设备ID
	int   nChan ;  //通道号
	char  nDevType ;     //设备类型0:dvr 1:外围设备
	char  nChanType ;    //
	int   nAlarmType ;

	MSG_PLAN_INFO plan ;
}MSG_UNION_PLAN_NEW, * LPMSG_UNION_PLAN_NEW;

typedef struct _msg_union_source  //20150629通道关联信息
{
	int    nID ;
	int    nDeviceID;		//设备ID
	int    nChan ;  //通道号
	char   nDeviceType ;     //设备类型0:dvr 1:外围设备
	char   nChanType ;    //通道类型 0：视频通道 ，1：开关量输入通道，2：开关量输出通道，3：模拟量通道
	int    nRegionID; 
	int    nMatrixSvrID;  //设备ID
	int    nMatrixScreenNum; //屏ID 
	int    nMatrixSubScreeNum; //子屏号 
	bool   bUnionMatrix; //关联矩阵

}MSG_UNION_SOURCE, * LPMSG_UNION_SOURCE;


//20150629
typedef struct _msg_union_chan  //20150629通道关联信息
{
	int   nID ;
	int   nSourceID ;
	int   nDeviceID;		//设备ID
	int   nChan ;  //通道号
	char  nDeviceType ;     //设备类型0:dvr 1:外围设备
	char  nChanType ;    //
	char  nActionType ;      //动作类型
	int   nParam1 ;     //动作参数1
	int   nParam2 ;     //动作参数2
	int   nParam3 ;     //动作参数3
	int   nParam4 ;     //动作参数3
}MSG_UNION_CHAN, * LPMSG_UNION_CHAN;

typedef struct _msg_union_chan_new  //20150629通道关联信息
{
	int   nID ;
	int   nDevID;		//设备ID
	int   nChan ;  //通道号
	char  nDevType ;     //设备类型0:dvr 1:外围设备
	char  nChanType ;    //
	int   nAlarmType ;

	int   nUnionDevID;		//设备ID
	int   nUnionChan ;  //通道号
	char  nUnionDevType ;     //设备类型0:dvr 1:外围设备
	char  nUnionChanType ;    //

	char  nActionType ;      //动作类型
	int   nParam1 ;     //动作参数1
	int   nParam2 ;     //动作参数2
	int   nParam3 ;     //动作参数3
	int   nParam4 ;     //动作参数3
}MSG_UNION_CHAN_NEW, * LPMSG_UNION_CHAN_NEW;

typedef struct _msg_plan_templ  //20150629计划
{
	MSG_PLAN_INFO plan;        //计划
	int           nID ;
	char          szName[100] ;
}MSG_PLAN_TEMPL, * LPMSG_PLAN_TEMPL;

typedef struct _msg_record_plan  //20150629录像计划
{
	int   nID ;
	int   nDeviceID;		//设备ID
	int   nChan ;           //通道号
	char   nRecordType ;     //录象方式
	MSG_PLAN_INFO plan;        //计划
}MSG_RECORD_PLAN, * LPMSG_RECORD_PLAN;

typedef struct _msg_user_videonode
{
	int   nDeviceID ;          //设备ID
	char   nDeviceType ;
	int   nChan;               //通道号
	char   nChanType ;
}MSG_USER_VIDEONODE, * LPMSG_USER_VIDEONODE;

typedef struct _msg_user_videogroup
{
	MSG_USER_VIDEONODE msgGroupNode[32] ;
	int                nSize ;
	int                nID ;
	int                nUserID ;
	char               szGroupName[100] ;
	char                nType ;//0:在管理中进行设置，1：用户自己增加的私人组，不同的表
}MSG_USER_VIDEOGROUP, * LPMSG_USER_VIDEOGROUP;

//查询返回的结果记录表，20150720新加
typedef struct _msg_response_head
{
	int   nRecordSize ;//数据个数
	BYTE  byTableType ;//表类型
}MSG_RESPONSE_HEAD, * LPMSG_RESPONSE_HEAD;


//给存储服务器的通道结构
typedef struct _msg_storechan_base
{
	SHORT  iPos ;	//盘阵中保存的序号
	char szChanName[100];
	int   iChan;
	char  nStreamType ;
	char szDevIP[50];
	int  iDevPort ;
	char szDevUser[16];
	char szDevPass[16];
	char  iDeviceType;
	DWORD dwID;
}MSG_STORECHAN_BASE , *LPMSG_STORECHAN_BASE;

//操作日志记录
typedef struct _msg_operate_base
{
	int   nUserID;		//操作人
	int   nAlarmID;      //增加对报警记录的操作
	int   nDeviceID;	    //设备ID
	char  nDeviceType;   //设备类型
	int   nChan ;        //通道号
	char  nChanType;		//通道类型
//	char  szContent[100];//描述
	char  nOperateType ; //操作类型
	char  nAction ;      //动作
//	unsigned int unLogTime ;
}MSG_OPERATE_BASE, * LPMSG_OPERATE_BASE;

//系统服务器
typedef struct _msg_systemsrv_base
{
	int  nID;
	char szIP[16];
	int  nPort;
#if USEUPDATE
	int  nPort2;
#endif
	int  nServerType;
	char szSerial[40];      //序列号
	char szUser[20];
	char szPass[20];
	int  nFactoryType ;
	int  nRegionID;
	int  nState ;//状态
	int  nEmergencyStatus ;//应急存储是否在线
#if USEUPDATE
	char szDescription[100] ;
	unsigned int unUpdateTime;
#endif
}MSG_SYSTEMSRV_BASE, * LPMSG_SYSTEMSRV_BASE;

//服务器下面的通道
typedef struct _msg_serverchan_base
{
	int  nID  ;
	int   nDevID ; //设备ID
	int  nChan  ;
	int  nDevType ;
	int  nChanType ;
	int   nParentID ; //服务器ID
	unsigned int unIndex ;
}MSG_SERVERCHAN_BASE, * LPMSG_SERVERCHAN_BASE;

//手机专用结构体
//区域
typedef struct _msg_mobi_region_base
{
	int nID;
	char szName[50];
	int nParentID;
}MSG_MOBI_REGION_BASE, * LPMSG_MOBI_REGION_BASE;

//视频通道
typedef struct _msg_mobi_chan_base
{
	int  nID;
	int  nChan ;
	int  nDevID ;
	int  nRegionID;
	char szName[50];
	char szMediaUrl[255] ;//媒体访问串
	char szRecordUrl[255] ;//媒体回放访问串，如果没有存储服务器则不需要
}MSG_MOBI_CHAN_BASE, * LPMSG_MOBI_CHAN_BASE;

//更新录像机的区域
typedef struct _msg_update_region
{
	int nDeviceID ;
	int nDeviceType ;
	int nRegionID ;
}MSG_UPDATE_REGION, * LPMSG_UPDATE_REGION;

//服务器状态
typedef struct _msg_server_status{
    WORD  wAuthChan ;//授权通道
	WORD  wLinkChan ;//连接通道
	WORD  wLinkUser ;//连接用户
	WORD  wStatus ;  //0:正常，1:停止
}MSG_SERVER_STATUS , *LPMSG_SERVER_STATUS;

//通知指令
typedef struct _msg_notify_info
{
	char  nType ;        //通知类型
	char  nMessage;	    //消息 ，0成功，1失败，2恢复，3退出
}MSG_NOTIFY_INFO, * LPMSG_NOTIFY_INFO;

//人员信息
typedef struct _msg_person_info
{
	int nID ;
	int nGroupID ;
	char szName[100] ;
	int  nSex ;
	int  nAge ;
	char szPhone1[20] ;
	char szPhone2[20] ;
	char szBirthday[20] ; 
	char szIdentify[50] ;
	char szAddress[200] ;
	char szMemo[200] ;

	char szCardNum[20];

	//照片
	char *pImageBuf ;
	int  nImageSize ;
	//特征数据
	int  nFeatureSize ;
}MSG_PERSON_INFO, *LPMSG_PERSON_INFO;

typedef struct _msg_operatelog_base
{
	int   nID;	//操作用户
	int   nDeviceID;	    //设备ID
	int   nDeviceType;   //设备类型
	int   nChan ;        //通道号
	int   nChanType;		//通道类型
	int   nOperateType ; //操作类型
	int   nAction ;      //动作
    unsigned int   nLogTime; 
	unsigned int   nOperationID; 
}MSG_OPERATELOG_BASE, * LPMSG_OPERATELOG_BASE;

//权限结构
typedef struct _MSG_RIGHT_DETAIL
{
        int  nDeviceID ;
        int  nChan ;
        char nChanType ;
        unsigned int unOpRight ;//设备访问权限按位取就可以
        unsigned int unExOpRight ;//超过32位权限，使用这个预留权限字段
}MSG_RIGHT_DETAIL, *LPMSG_RIGHT_DETAIL;

typedef struct _msg_dev_config  //20150629录像计划
{
	int   nID ;
	int   nDeviceID;		//设备ID
	int   nChan ;           //通道号
	char  nChanType ;     //录象方式
	char  nConfigType ;     //录象方式
	char  szConfig[1024] ;
}MSG_DEV_CONFIG, * LPMSG_DEV_CONFIG;

//报警分组
typedef struct _msg_alarm_group
{
        int  nID ;
        int  nType ;
        int  nGroupID ;
		int  nRegionID ;
		bool bUsed ;
}MSG_ALARM_GROUP, *LPMSG_ALARM_GROUP;

typedef struct _msg_alarm_group_chan
{
        int  nID ;
        int  nDevID ;
		int  nDevType ;
        int  nChan ;
		int  nChanType ;
		int  nAlarmType ;
		int  nAlarmGroupID ;
		bool bUsed ;
}MSG_ALARM_GROUP_CHAN, *LPMSG_ALARM_GROUP_CHAN;


typedef struct _msg_alarm_group_union_chan
{
        int  nID ;
		int  nAlarmGroupID ;
        int  nDevID ;
		int  nDevType ;
        int  nChan ;
		int  nChanType ;
		int  nActionType ;
		int  nParam1 ;
		int  nParam2 ;
		int  nParam3 ;
		int  nParam4 ;
		
		bool bUsed ;
}MSG_ALARM_GROUP_UNION_CHAN, *LPMSG_ALARM_GROUP_UNION_CHAN;

typedef struct _msg_alarm_group_plan
{
        int  nID ;
		int  nAlarmGroupID ;
		int  nDayofWeek ;
		unsigned int  unStart ;
		unsigned int  unStop ;
		bool bUsed ;
}MSG_ALARM_GROUP_PLAN, *LPMSG_ALARM_GROUP_PLAN;


typedef struct _msg_alarm_group_notify
{
        int  nID ;
		int  nAlarmGroupID ;
		int  nNotifyType;
		char szParam1[30];
		char szParam2[30];
		char szParam3[30];
		char szParam4[30];
		int  nParam1 ;
		int  nParam2 ;
		int  nParam3 ;
		int  nParam4 ;
}MSG_ALARM_GROUP_NOTIFY, *LPMSG_ALARM_GROUP_NOTIFY;


#endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      