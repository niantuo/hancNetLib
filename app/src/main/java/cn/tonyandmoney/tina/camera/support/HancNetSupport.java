package cn.tonyandmoney.tina.camera.support;

/**
 * 调用本地库
 */
public class HancNetSupport {
    static {
        System.loadLibrary("net-lib");
    }

    private static HancNetSupport mSupport;
    public static HancNetSupport getInstance(){
        if (mSupport==null){
            mSupport =new  HancNetSupport();
        }
        return mSupport;
    }


    public native boolean hancNetSDKInit();
}
