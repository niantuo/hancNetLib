package cn.tonyandmoney.tina.camera.support;

import android.util.Log;

/**
 * 调用本地库
 */
public class HancNetSupport {
    private final static String TAG = HancNetSupport.class.getSimpleName();

    static {
        System.loadLibrary("HancNetSDK");
        System.loadLibrary("net-lib");
    }

    private static HancNetSupport mSupport;

    public static HancNetSupport getInstance() {
        if (mSupport == null) {
            mSupport = new HancNetSupport();
        }
        return mSupport;
    }


    public native boolean hancNetSDKInit();

    public native String libName();

    public native int hancConnect(String ip,int port,String cmd,int timeout,long dwUser);

    /**
     * C#端的回调
     *
     * @param lUserID 用户id
     * @param pBuf    服务端返送会的的数据
     * @param nBufLen 数据长度
     * @param dwUser  用户自定义的数据，原样返回
     */
    private void netCallback(int lUserID, String pBuf, int nBufLen, long dwUser) {
        Log.i(TAG, "netCallback" + lUserID);
    }
}
