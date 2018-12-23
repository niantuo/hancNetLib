#ifndef __HC_NETWORK
#define __HC_NETWORK


extern "C"
{

    bool HancNetSDK_Init();

    int HancNetSDK_Connect(char *szIP, int nPort, char *pLinkCmd, int nCmdSize, int nTimeOut,
                       void(*NetCallback)(int lUserID, char *pBuf, int nBufLen, long dwUser),
                       long dwUser);
    bool HancNetSDK_DisConnect(int nSession, char *pStopCmd, int nCmdSize);
    bool HancNetSDK_SendData(int nSession, char *pData, int nLen);

    int HancNetSDK_CommunicateWithServerTcp(char *szIP, int nPort, char *pSendBuf, int nSendLen,
                                        char **ppRecvBuf, int &pRecvLen,
                                        int nTimeOut = 3000, bool bGetData = false);
    bool HancNetSDK_DataRelease(int nSession);

    bool IntvClientRelease(int nSession);

//视频点播
    int NVMS_MEDIA_PLAY(char *szURL, int nParam,
                    void(*RealDataCallBackEx)(int nRealHandle, int nDataType, char *pBuffer,
                                              int dwBufSize, int nDeviceType, int dwUser),
                    int dwUser);
    bool NVMS_PTZ_CONTROL(int nRealPlay, int dwPTZCommand, int dwParam1, int dwParam2, int dwParam3);
    bool NVMS_SEND_DATA(int nRealPlay, int nType, char *pBuff, int nSize);
    bool NVMS_STOP_MEDIA_PLAY(int nRealPlay);
}


#endif // __HC_NETWORK
