package cn.tonyandmoney.tina.camera.support.callback;

import com.sun.jna.Callback;

/**
 * 视频播放回调
 */
public interface RealDataCallBackEx extends Callback{


    void realDataCallback(int nRealHandle, int nDataType, String pBuffer,int dwBufSize,int nDeviceType , int dwUser);
}
