package cn.tonyandmoney.tina.camera.support;

/**
 * 调用本地库
 * javap -s 类名，查看方法签名
 */
public class HancNetSupport {
    private final static String TAG = HancNetSupport.class.getSimpleName();

    static {
        System.loadLibrary("net-lib");
    }

    private static HancNetSupport mSupport;

    public static HancNetSupport getInstance() {
        if (mSupport == null) {
            mSupport = new HancNetSupport();
        }
        return mSupport;
    }


    public native boolean init();
    public native int loginToServer(String ip,int port,String username,String password);


    public void callback(){

    }


}
