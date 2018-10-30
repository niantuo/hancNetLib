package cn.tonyandmoney.tina.camera.support;

import com.sun.jna.Callback;
import com.sun.jna.NativeLong;

/**
 * 回调函数
 */
public interface INetCallback extends Callback {

    void invoke(int lUserID, String pBuf, int nBufLen, NativeLong dwUser);
}
