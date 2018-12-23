//commudefine.h

#if !defined(AFX_COMMUDEFINE_H)
#define AFX_COMMUDEFINE_H

#pragma once
#define MAXSTATECHAN  32
#define MAXDATAS      16

//�����
//���ݿ��궨��
#define REGIONTABLE        1   //�����
#define RECORDTABLE        2   //��Ƶ�豸��
#define VIDEOCHANTABLE     3   //��Ƶͨ����
#define PRESETTABLE        4   //Ԥ��λ�б�

#define UNIONSOURTABLE     5  //����Դ
#define UNIONCHANTABLE     6  //��������
#define UNIONPLANTABLE	   7  //�����ƻ�

#define DMATRIXSVRTABLE          8  //�����豸
#define DMATRIXSCREENTABLE       9  //�������

#define MAPTABLE                  10  //���ӵ�ͼ
#define NODEMAPTABLE              11  //��ͼ�ڵ�

#define USERGROUPTABLE            12  //�û���
#define USERTABLE                 13  //�û�
#define USERGROUPRIGHTTABLE		  14 //�û���ͨ��Ȩ��

#define TIMEPLANTABLE             15  //�ƻ�ģ��
#define RECORDPLANTABLE           16 //¼��ƻ�

#define EVENTLOGTABLE             17  //������־
#define OPERATELOGTABLE           18  //������־

#define USERVIDEOGROUP            19 //�û��Զ�����Ƶ����,20150702


#define DEVGROUPTABLE			  20 //ϵͳ����
#define DEVGROUPCHANTABLE		  21 //ϵͳ��ͨ��

#define INTVSVRTABLE			  22 //���ܷ���������
#define INTVCHANTABLE			  23 //���ܷ���ͨ��

#define SERVERTABLE               24 //������

#define DETECTRESULTTABLE         25 //�����ϸ��Ϣ

#define PERSONTABLE               26 //��Ա��Ϣ��

#define USERVIDEOGROUPCHAN        27 //�û��Զ�����Ƶ����,20150702


#define DEVICECONFIG              28 //�豸����



//���ݿ����
#define DATAADD          1   //��
#define DATADEL          2   //ɾ
#define DATAMODIFY       3   //��
#define DATAQUERY        4   //��
#define DATAQUERYMYSELF        5//�Զ����ѯ
#define DATAQUERYMYSELFEX        6//�Զ����ѯ

//�ڵ�����
#define NORECORD		1

#define ALL_NODE			    0//������ID��ȡ��ȫ������
#define CURRENT_NODE			1//��ǰ���ڽڵ�
#define PARENT_NODE			    2//���ڵ�
#define CALLSUB_NODE			3//�Ӹ��ڵ�������

typedef enum _UPDATE_DATA_TYPE
{
	UPDATE_DEFENCE = 1,  //���·���
	UPDATE_GROUP,        //���·���
	UPDATE_BASE,         //�����豸ͨ��
	UPDATE_SERVER,       //������
	UPDATE_RULE,         //����
	UPDATE_RECORD,       //¼������
}UPDATE_DATA_TYPE;


typedef enum _ENUM_DATABASE_TABLE
{
	REGION_TABLE = 1,//�����
	DEVICE_TABLE ,  //�豸�б�
	CHAN_TABLE,        //ͨ����
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
	NOTIFY_CLIENT = 0,  //�ͻ���
	NOTIFY_APP,       //�ֻ�app
	NOTIFY_CMS,       //�ϼ�ƽ̨
	NOTIFY_UNIONSVR,       //��������
	NOTIFY_INTVSVR,       //���ܷ���
	NOTIFY_MSG,       //����
	NOTIFY_MAIL,      //�ʼ�
}NOTIFY_TYPE;


typedef enum _ALARMGROUP_NOTIFY
{
	NOTIFY_ALLCLIENT = 0xff,  //����
	NOTIFY_REGION = 1,  //֪ͨ��������
	NOTIFY_PARENT,        //֪ͨ�ϼ�����
	NOTIFY_GROUP_CLIENT,
	NOTIFY_MOBIAPP,
	NOTIFY_EMAIL,
	NOTIFY_MESSAGE,
}ALARMGROUP_NOTIFY;

//Ȩ��
typedef enum _USERGROUP_RIGHT
{
	RIGHT_LIVE = 0,  //ʵʱ
	RIGHT_RECORD,    //�ط�
	RIGHT_PTZ,       //��̨
	RIGHT_MATRIX,    //����
	RIGHT_LOG,       //��־
	RIGHT_OPERATION, //��ά
	RIGHT_TIME,      //ʱ�����
	RIGHT_MAP,        
}USERGROUP_RIGHT;

//������־�궨��20150808

typedef enum _OPERATION_TYPE_
{
	OP_LOGIN  =  1,     //��¼
	OP_LOGOUT ,         //ע��
	OP_LOGOUT_ABNORMAL, //�������˳�
	OP_LOGIN_TRY,       //��ͼ��½
	OP_LOGIN_FAILD,     //��½ʧ��
	OP_LIVE,            //������Ƶ
	OP_LIVE_STOP,       //�ر���Ƶ
	OP_PLAYBACK,        //����¼��
	OP_PLAYBACK_STOP,   //�ر���Ƶ
	OP_PTZ_START,       //��̨����
	OP_PTZ_STOP,        //��̨����ͣ
	OP_SPEEK_START,     //�����Խ�
	OP_SPEEK_STOP,      //ֹͣ�Խ�
	OP_REMOTE_DOOROPEN,      //Զ�̿���
	OP_REMOTE_DOORCLOSE,      //Զ�̹���
}OPERATION_TYPE;

#define OPERATELOGIN        1 //��¼
#define OPERATELOGOUT       2 //ע��
#define OPERATEDISAPPEAR    3 //�������˳�
#define OPERATETRYLOGIN     4 //��ͼ��½
#define OPERATELOGINFAILD   5 //��½ʧ��
#define OPERATEVIDEOPLAY   6 //������Ƶ
#define OPERATEPTZCTRL     7 //��̨����
#define OPERATEVIDEOCTRL   8 //�������

#define OPERATEREPLAY      9 //�ط�¼��
#define OPERATDOWNRECORD   10 //����¼��

#define OPERATESPEEKS      11 //�����Խ�
#define OPERATELISTEN      12 //��������
#define OPERATESWITCH      13 //���ؿ�

#define OPERATEOPERATEDOOR 14 //�Ų���
#define OPERATEDOORSETUP   15 //������

#define OPERATEREMOTESET    16 //Զ������
#define OPERATEVIEWALARMLOG 17 //�鿴������¼
#define OPERATEVIEWOPERATELOG 18 //�鿴������¼

#define OPERATEVIEWDATALOG    19 //�鿴��ʷ����

#define OPERATMATRIXVIEW      20 //����㲥
#define OPERATMATRIXAUTO      21 //�����Զ�����

#define OPERATMATRIXARRAY     22 //���󲼾�

#define OPERATMANAGE          23 //ϵͳ����

//����
#define OPERATEERROR         -1 //�쳣
#define OPERATEOPEN        0 //��
#define OPERATEOFF         1 //�ر�
#define OPERATEPLAN        2 //�ƻ�


//ͨ�����Ͷ���
#define TYPEOFALL          -1 //δָ��
#define TYPEOFVIDEOCHAN     0
#define TYPEOFALARMCHAN     1
#define TYPEOFALARMOUT      2
#define TYPEOFSENSORCHAN    3
#define TYPEOFDOORCHAN      4

//�豸����

#define TYPEOFCAMERA     0
#define TYPEOFDVR        1
#define TYPEOFDATADEV      2
#define TYPEOFFIBER        3

#define USEUPDATE 1

#define USEUPDATEFORCVR 1
///////////////////////////
//�����û���Ȩ�޹���
///////////////////////////

typedef struct _msg_region_base
{
	int nID;
	char szName[50];
	int nParentID;
	char szDescription[100]; //����
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
	char szDescription[100]; //����
	unsigned int unIndex ;
	bool bEnable ;//��Ȩ��ʹ�õ�����
	bool bDisable ;//���õķ�Χ��ֻΪ���·��
}MSG_TREE_REGION_BASE, * LPMSG_TREE_REGION_BASE;

//����
typedef struct _msg_tree_group_base
{
	int  nID  ;
	char szName[50] ;
	int  nType ;  //������
	int  nParentID ;
	int  nRegionID ; //����id
	unsigned int unIndex ;
	bool bEnable ;//��Ȩ��ʹ�õ�����
}MSG_TREE_GROUP_BASE, * LPMSG_TREE_GROUP_BASE;


//����
typedef struct _msg_devgroup_base
{
	int  nID  ;
	char szName[50] ;
	int  nType ;  //������
	int  nParentID ;
	int  nRegionID ; //����id
	unsigned int unIndex ;
}MSG_DEVGROUP_BASE, * LPMSG_DEVGROUP_BASE;
//ͨ������
typedef struct _msg_changroup_base
{
	int  nID  ;
	int   nDevID ; //�豸ID
	int  nChan  ;
	int  nDevType ;
	int  nChanType ;
	int   nGroupID ; //��ID
	unsigned int unIndex ;
}MSG_CHANGROUP_BASE, * LPMSG_CHANGROUP_BASE;

typedef struct _msg_user_info  //��¼��Ϣ
{
	char szUser[100] ;	
	char szPass[100] ;	
	char szCenterIP[50] ;	
}MSG_USER_INFO, * LPMSG_USER_INFO;


typedef struct _msg_user_login_info  //��¼��Ϣ
{
	char szUser[100] ;	
	int  nUserID ;
	int  nUserGroupID ;
	int  nRight ;       //Ȩ��
	int  nPrority ;     //ְ�ܼ���
	int  nAlarmRight ;
	int  nRegionID ;
	bool bUseDetailRight ;
}MSG_USER_LOGIN_INFO, * LPMSG_USER_LOGIN_INFO;

typedef struct _msg_usergroup_base
{
	int  nID;				//�û�ID
	char szName[16];		//����
	int  nRegionID;			//�����ڲ����
	int  nPriority;			//����	
	int  nOperateRight;		//����Ȩ��
	bool bUseDetailRight;
    
}MSG_USERGROUP_BASE, * LPMSG_USERGROUP_BASE;

typedef struct _msg_usergroupright_base
{
	int  nID;				//ID
	int  nUserGroupid;		//�û�����
	int  nAreaid;			//��ɫ����ķ�Χ
	int  nType;             //��������
}MSG_USERGROUPRIGHT_BASE, * LPMSG_USERGROUPRIGHT_BASE;

typedef struct _msg_userinfo_base
{
	int  nID;				//�û�ID
	char szUser[16];		//�û���
	char szPass[16];		//�û�����
	int  nUserGroupID ;		//�����û���ID
	int  nAlarmRight ;
	char szRealName[20];
	char szCellphone[12];
	char szOfficephone[20];
	char szHomephone[20];

}MSG_USERINFO_BASE, * LPMSG_USERINFO_BASE;


typedef struct _msg_user_base
{
	int  nID;				//�û�ID
	char szUser[16];		//�û���
	char szPass[16];		//�û�����
	int  nRegionID;			//�����ڲ����
	BYTE  nPriority;		//����	
	int   nOperateRight;	//����Ȩ��
	int   nAlarmRight;		//�Ӿ�Ȩ��
	unsigned int nLoginTime;      //��¼��½ʱ�䣬���ڲ�ѯ
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
//��Ƶ�豸
///////////////////////////////////
//��Ƶ�豸(¼��������)


//��Ƶ�豸��Ϣ
typedef struct _msg_recorddevice_base
{
	DWORD  nID;			    //�ڲ����
	char szName[50];        //����������
	char szSerial[40];      //���к�
	char   nHardType;			//Ӳ�����ͣ�0��IPC��1��DVS��2���ɼ���������3�������豸
	char  nLinkType ;        //������ʽ
	char  nServerType;		//����������0:���� 1����
	char szIP[50];	        //��������ַ/����
	int  nPort;		        //�������˿�
	char szUser[20];		//�û���
	char szPass[20];		//�û�����

#if USEUPDATE
	char szRemark[100];		//��ע
#else
	char szRemark[200];		//��ע
#endif
	int    nRegionID;			//�����ڲ����
	
	SHORT  nStorePos ;
	SHORT  nMatixPos ;
	char   nSetAlarm ;

	unsigned int unIndex ;
#if USEUPDATE
	unsigned int unUpdateTime; //����ʱ��   -- updatetime
#endif
	unsigned int nStatus ;
	
}MSG_RECORDDEVICE_BASE, * LPMSG_RECORDDEVICE_BASE;


//��Ƶͨ���ڵ�
typedef struct _msg_video_record_base
{
	DWORD  nID ;
	int   nChan;		    //ͨ����
	char  szName[40];	    //�ڵ��ı�
	int   nStorePos;		//�洢�е�ͨ������
	int   nDeviceID ;	    //���ڵ�ID
	int   nMatrixPos;		//����������
	char  nSetAlarm ;
	char  nLevel;		//��������
	int   nType;        //ͨ������
	char  szPass[20];
	bool  bDuplex ;
	int nParam1;
    int nParam2;
    int nParam3;
    int nParam4;
#if USEUPDATE
	char szRemark[100];		//��ע
	unsigned int unUpdateTime; //����ʱ��   -- updatetime
#endif

#if USEUPDATEFORCVR
	char szSerial[40];
#endif

#if USEUPDATE
	char szIP[20];
	char szUser[20];
	int  nPort ;//��Ƶͨ���������nParam1��ʾ�豸���ͣ�nParam2��ʾ�Ƿ񱨾�
#endif
	unsigned int unIndex ;
	unsigned int  nStatus ;
}MSG_VIDEO_RECORD_BASE, * LPMSG_VIDEO_RECORD_BASE; 




//////////////////////////////////
//�����豸
/////////////////////////////////
//���־�����Ϣ
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
	int   nID ; //ID��
	char  szName[50];
	char   nScreenNum ;//��������
	char   nSubScreenNum ;//�Ӵ��ڸ�����,20150812ʵ�����������ݿ��ŵ�������=ϵͳ���
	int   nMatrixID ;	//��������
	unsigned short   nX ;
	unsigned short   nY ;
	unsigned short   nW ;
	unsigned short   nH ;
}MSG_SCREEN_MATRIXSVR_BASE, * LPMSG_SCREEN_MATRIXSVR_BASE;

//////////////////////////
//��ͼ
//////////////////////////
//��ͼ��Ϣ
typedef struct _msg_map_base
{
	int  nID;			//��ͼ���
	char szName[50];	//��ͼ����
	char  nMapType;
	int  nParentID;		//�������ڲ����
	int  nRegionID;		//�������ڲ����
	int  nImageType;
	int  nImageSize ;   //��ͼ���ݴ�С
}MSG_MAP_BASE, * LPMSG_MAP_BASE;

typedef struct _msg_node_map_base
{
	int  nID;			//�ڵ��ڲ����
	char  nType;			//����0:��ͼ 2��ͨ��
	char szName[50];	//��������
	int  nDeviceID;     //����Ϊ2ʱ�������豸ID,����Ϊ0ʱ�������ͼ��ID
	char  nDeviceType;	//�豸����
	int   nChan ;        //ͨ����
	char  nChanType;		//ͨ������, 0Ϊ��Ƶͨ����1Ϊ����ͨ��
	char  nNodeType ;    //ͼ������,��ʹ�ò�ͬ��ͼ���ʶ��ͼ
	int  nMapID;		//�������ڲ����
	int  nX;
	int  nY;
	int  nNextX;
	int  nNextY;
}MSG_NODE_MAP_BASE, * LPMSG_NODE_MAP_BASE;

//////////////////////////////
//�洢
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
//��ý��
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

//ͨѶ����ͷ�����ڷ������������ͨѶ,��������豸����ʹ�ô�ͷ����ͨѶ
typedef struct _msg_head_info
{
	BYTE   nType ;          //��Ϣ����:=0���ԣ�1������2��״̬��3���豸�¼�,4,��¼
	                       //5����Դ����6,ϵͳ֪ͨ��7��������Ϣ��8�����ʹ���9�������ļ���10,д��־
	                       //10,������ʽ���ݣ�11����Ӧ
	BYTE   nFrom ;          //������Դ:=0���ԣ�1���ͻ��ˣ�2���ķ�������3����ý���������4���洢��������5��������������6�������������7����ϣ�8�����ܷ���,9��������������
    BYTE   nTo ;            //�����û�������
	int   nFromClientID ;  //������Ϣ���û���IDΪ�û�ϵͳ�б�ţ����ڿͻ��˵�ͨѶ
	int   nToClientID ;    //������Ϣ���û���IDΪ�û�ϵͳ�б�ţ����ڿͻ��˵�ͨѶ
}MSG_HEAD_INFO, * LPMSG_HEAD_INFO;

typedef struct _msg_vca_rect{
	USHORT		x;
	USHORT		y;
	USHORT		w;
	USHORT		h;
}MSG_VCA_RECT,*LPMSG_VCA_RECT;	

//Ԥ��λ��Ϣ
typedef struct _msg_preset_base
{
	int    nID ;   //Ԥ��λ����IP
	char    nDeviceID ;//��ͨ��ID��ѡһ
	int    nChan     ;//��ͨ��ID��ѡһ
	char   szName[100];	//����
	char    nIndex;		//Ԥ�õ���
	unsigned int nStayTime;		//ͣ��ʱ��
}MSG_PRESET_BASE, * LPMSG_PRESET_BASE; 


//���ܷ���������
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



//�����ӵ���������

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
	int  nType ;        //���ͣ�0��ȫ����1������������ң�2�������豸���ң�3����ͨ������
	int  nRegionID ;    //����ID
	int  nDeviceID;	    //�豸ID
	char  nDeviceType ;  //�豸����
	int   nChanNo;		//ͨ����
	char  nChanType;     //ͨ������
}MSG_DEV_QUERY, * LPMSG_DEV_QUERY;

typedef struct _msg_time_query
{
	MSG_TIME_BASE tmStart ;
	MSG_TIME_BASE tmStop ;
	bool bUser ;
}MSG_TIME_QUERY,*LPMSG_TIME_QUERY;

typedef struct _msg_dboperate_info  //ִ��SQL���
{
	int nType ;	   //1���ӣ�2�޸ģ�3ɾ��,4��ѯ
	SHORT nTable ;   //�������
	char nNodeType ;//�ڵ�����,0�������ڵ㣬1�����ڵ㣬2����ǰ�ڵ����½ڵ�
	int nNodeID ;  //�ڵ�ID
}MSG_DBOPERATE_INFO, * LPMSG_DBOPERATE_INFO;

typedef struct _msg_sql_info  //ִ��SQL���
{
	int nType ;	   //1���ӣ�2�޸ģ�3ɾ��,4��ѯ
	SHORT nTable ;   //�������
	char szSQL[1024] ;//ֱ��ִ��SQL���
}MSG_SQL_INFO, * LPMSG_SQL_INFO;


/*���������ݽ���*/

//20150720 �ӱ��������ƻ� 

typedef struct _msg_plan_info  //20150629�ƻ�
{
	BYTE bPlans[7][48];        //�ƻ�
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
	int   nDevID;		//�豸ID
	int   nChan ;  //ͨ����
	char  nDevType ;     //�豸����0:dvr 1:��Χ�豸
	char  nChanType ;    //
	int   nAlarmType ;

	MSG_PLAN_INFO plan ;
}MSG_UNION_PLAN_NEW, * LPMSG_UNION_PLAN_NEW;

typedef struct _msg_union_source  //20150629ͨ��������Ϣ
{
	int    nID ;
	int    nDeviceID;		//�豸ID
	int    nChan ;  //ͨ����
	char   nDeviceType ;     //�豸����0:dvr 1:��Χ�豸
	char   nChanType ;    //ͨ������ 0����Ƶͨ�� ��1������������ͨ����2�����������ͨ����3��ģ����ͨ��
	int    nRegionID; 
	int    nMatrixSvrID;  //�豸ID
	int    nMatrixScreenNum; //��ID 
	int    nMatrixSubScreeNum; //������ 
	bool   bUnionMatrix; //��������

}MSG_UNION_SOURCE, * LPMSG_UNION_SOURCE;


//20150629
typedef struct _msg_union_chan  //20150629ͨ��������Ϣ
{
	int   nID ;
	int   nSourceID ;
	int   nDeviceID;		//�豸ID
	int   nChan ;  //ͨ����
	char  nDeviceType ;     //�豸����0:dvr 1:��Χ�豸
	char  nChanType ;    //
	char  nActionType ;      //��������
	int   nParam1 ;     //��������1
	int   nParam2 ;     //��������2
	int   nParam3 ;     //��������3
	int   nParam4 ;     //��������3
}MSG_UNION_CHAN, * LPMSG_UNION_CHAN;

typedef struct _msg_union_chan_new  //20150629ͨ��������Ϣ
{
	int   nID ;
	int   nDevID;		//�豸ID
	int   nChan ;  //ͨ����
	char  nDevType ;     //�豸����0:dvr 1:��Χ�豸
	char  nChanType ;    //
	int   nAlarmType ;

	int   nUnionDevID;		//�豸ID
	int   nUnionChan ;  //ͨ����
	char  nUnionDevType ;     //�豸����0:dvr 1:��Χ�豸
	char  nUnionChanType ;    //

	char  nActionType ;      //��������
	int   nParam1 ;     //��������1
	int   nParam2 ;     //��������2
	int   nParam3 ;     //��������3
	int   nParam4 ;     //��������3
}MSG_UNION_CHAN_NEW, * LPMSG_UNION_CHAN_NEW;

typedef struct _msg_plan_templ  //20150629�ƻ�
{
	MSG_PLAN_INFO plan;        //�ƻ�
	int           nID ;
	char          szName[100] ;
}MSG_PLAN_TEMPL, * LPMSG_PLAN_TEMPL;

typedef struct _msg_record_plan  //20150629¼��ƻ�
{
	int   nID ;
	int   nDeviceID;		//�豸ID
	int   nChan ;           //ͨ����
	char   nRecordType ;     //¼��ʽ
	MSG_PLAN_INFO plan;        //�ƻ�
}MSG_RECORD_PLAN, * LPMSG_RECORD_PLAN;

typedef struct _msg_user_videonode
{
	int   nDeviceID ;          //�豸ID
	char   nDeviceType ;
	int   nChan;               //ͨ����
	char   nChanType ;
}MSG_USER_VIDEONODE, * LPMSG_USER_VIDEONODE;

typedef struct _msg_user_videogroup
{
	MSG_USER_VIDEONODE msgGroupNode[32] ;
	int                nSize ;
	int                nID ;
	int                nUserID ;
	char               szGroupName[100] ;
	char                nType ;//0:�ڹ����н������ã�1���û��Լ����ӵ�˽���飬��ͬ�ı�
}MSG_USER_VIDEOGROUP, * LPMSG_USER_VIDEOGROUP;

//��ѯ���صĽ����¼��20150720�¼�
typedef struct _msg_response_head
{
	int   nRecordSize ;//���ݸ���
	BYTE  byTableType ;//������
}MSG_RESPONSE_HEAD, * LPMSG_RESPONSE_HEAD;


//���洢��������ͨ���ṹ
typedef struct _msg_storechan_base
{
	SHORT  iPos ;	//�����б�������
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

//������־��¼
typedef struct _msg_operate_base
{
	int   nUserID;		//������
	int   nAlarmID;      //���ӶԱ�����¼�Ĳ���
	int   nDeviceID;	    //�豸ID
	char  nDeviceType;   //�豸����
	int   nChan ;        //ͨ����
	char  nChanType;		//ͨ������
//	char  szContent[100];//����
	char  nOperateType ; //��������
	char  nAction ;      //����
//	unsigned int unLogTime ;
}MSG_OPERATE_BASE, * LPMSG_OPERATE_BASE;

//ϵͳ������
typedef struct _msg_systemsrv_base
{
	int  nID;
	char szIP[16];
	int  nPort;
#if USEUPDATE
	int  nPort2;
#endif
	int  nServerType;
	char szSerial[40];      //���к�
	char szUser[20];
	char szPass[20];
	int  nFactoryType ;
	int  nRegionID;
	int  nState ;//״̬
	int  nEmergencyStatus ;//Ӧ���洢�Ƿ�����
#if USEUPDATE
	char szDescription[100] ;
	unsigned int unUpdateTime;
#endif
}MSG_SYSTEMSRV_BASE, * LPMSG_SYSTEMSRV_BASE;

//�����������ͨ��
typedef struct _msg_serverchan_base
{
	int  nID  ;
	int   nDevID ; //�豸ID
	int  nChan  ;
	int  nDevType ;
	int  nChanType ;
	int   nParentID ; //������ID
	unsigned int unIndex ;
}MSG_SERVERCHAN_BASE, * LPMSG_SERVERCHAN_BASE;

//�ֻ�ר�ýṹ��
//����
typedef struct _msg_mobi_region_base
{
	int nID;
	char szName[50];
	int nParentID;
}MSG_MOBI_REGION_BASE, * LPMSG_MOBI_REGION_BASE;

//��Ƶͨ��
typedef struct _msg_mobi_chan_base
{
	int  nID;
	int  nChan ;
	int  nDevID ;
	int  nRegionID;
	char szName[50];
	char szMediaUrl[255] ;//ý����ʴ�
	char szRecordUrl[255] ;//ý��طŷ��ʴ������û�д洢����������Ҫ
}MSG_MOBI_CHAN_BASE, * LPMSG_MOBI_CHAN_BASE;

//����¼���������
typedef struct _msg_update_region
{
	int nDeviceID ;
	int nDeviceType ;
	int nRegionID ;
}MSG_UPDATE_REGION, * LPMSG_UPDATE_REGION;

//������״̬
typedef struct _msg_server_status{
    WORD  wAuthChan ;//��Ȩͨ��
	WORD  wLinkChan ;//����ͨ��
	WORD  wLinkUser ;//�����û�
	WORD  wStatus ;  //0:������1:ֹͣ
}MSG_SERVER_STATUS , *LPMSG_SERVER_STATUS;

//ָ֪ͨ��
typedef struct _msg_notify_info
{
	char  nType ;        //֪ͨ����
	char  nMessage;	    //��Ϣ ��0�ɹ���1ʧ�ܣ�2�ָ���3�˳�
}MSG_NOTIFY_INFO, * LPMSG_NOTIFY_INFO;

//��Ա��Ϣ
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

	//��Ƭ
	char *pImageBuf ;
	int  nImageSize ;
	//��������
	int  nFeatureSize ;
}MSG_PERSON_INFO, *LPMSG_PERSON_INFO;

typedef struct _msg_operatelog_base
{
	int   nID;	//�����û�
	int   nDeviceID;	    //�豸ID
	int   nDeviceType;   //�豸����
	int   nChan ;        //ͨ����
	int   nChanType;		//ͨ������
	int   nOperateType ; //��������
	int   nAction ;      //����
    unsigned int   nLogTime; 
	unsigned int   nOperationID; 
}MSG_OPERATELOG_BASE, * LPMSG_OPERATELOG_BASE;

//Ȩ�޽ṹ
typedef struct _MSG_RIGHT_DETAIL
{
        int  nDeviceID ;
        int  nChan ;
        char nChanType ;
        unsigned int unOpRight ;//�豸����Ȩ�ް�λȡ�Ϳ���
        unsigned int unExOpRight ;//����32λȨ�ޣ�ʹ�����Ԥ��Ȩ���ֶ�
}MSG_RIGHT_DETAIL, *LPMSG_RIGHT_DETAIL;

typedef struct _msg_dev_config  //20150629¼��ƻ�
{
	int   nID ;
	int   nDeviceID;		//�豸ID
	int   nChan ;           //ͨ����
	char  nChanType ;     //¼��ʽ
	char  nConfigType ;     //¼��ʽ
	char  szConfig[1024] ;
}MSG_DEV_CONFIG, * LPMSG_DEV_CONFIG;

//��������
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