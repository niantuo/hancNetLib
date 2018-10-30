package cn.tonyandmoney.tina.camera.support;

import com.sun.jna.Library;
import com.sun.jna.Native;

import cn.tonyandmoney.tina.camera.support.callback.IDemoCallback;
import cn.tonyandmoney.tina.camera.support.entity.MsgHeaderInfo;

public interface NativeLibrary extends Library {

    NativeLibrary INSTANCE = (NativeLibrary) Native.loadLibrary("net-lib", NativeLibrary.class);

    /**
     * 初始化SDK
     *
     * @return 成功返回true
     */
    boolean hancNetSdkInit();


    /**
     * 登陆到服务器
     *
     * @param ip       服务器ip
     * @param port     服务器端口
     * @param username 用户名
     * @param password 密码
     * @return 登陆返回值
     */
    int login(String ip, int port, String username, String password);

}
