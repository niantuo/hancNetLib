package cn.tonyandmoney.tina.camera.support;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.NativeLong;
import com.sun.jna.ptr.IntByReference;

import cn.tonyandmoney.tina.camera.support.callback.RealDataCallBackEx;

/**
 * 采用JNA的方式调用C++本地库
 */
public interface JNAHancNetLibrary extends Library {

    JNAHancNetLibrary INSTANCE = (JNAHancNetLibrary) Native.loadLibrary("HancNetSDK", JNAHancNetLibrary.class);

    boolean HancNetSDK_Init();

    int HancNetSDK_Connect(String ip, int port, String cmd, int cmdSize, int timeout, INetCallback callback, NativeLong dwUser);

    boolean HancNetSDK_DisConnect(int sessionId,String stopCmd,int cmdSize);

    boolean HancNetSDK_SendData(int nSession ,String pData , int nLen);

    int HancNetSDK_CommunicateWithServerTcp(String szIP,int nPort,String pSendBuf,int nSendLen,String[] ppRecvBuf,IntByReference pRecvLen,
                                            int nTimeOut ,boolean bGetData );
    boolean HancNetSDK_DataRelease(int nSession);


    //视频点播
    int NVMS_MEDIA_PLAY(String szURL , int nParam , RealDataCallBackEx callBackEx, int dwUser);
    boolean NVMS_PTZ_CONTROL(int nRealPlay,int  dwPTZCommand,int  dwParam1,int  dwParam2,int  dwParam3);
    boolean NVMS_SEND_DATA(int nRealPlay,int nType ,String pBuff ,int nSize);
    boolean NVMS_STOP_MEDIA_PLAY(int nRealPlay);

}
