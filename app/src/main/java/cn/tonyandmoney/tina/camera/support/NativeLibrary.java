package cn.tonyandmoney.tina.camera.support;

import com.sun.jna.Library;
import com.sun.jna.Native;

import cn.tonyandmoney.tina.camera.support.callback.IDemoCallback;
import cn.tonyandmoney.tina.camera.support.entity.MsgHeaderInfo;

public interface NativeLibrary extends Library {

    NativeLibrary INSTANCE = (NativeLibrary) Native.loadLibrary("net-lib",NativeLibrary.class);

    void testCallback(IDemoCallback callback, MsgHeaderInfo info);
}
