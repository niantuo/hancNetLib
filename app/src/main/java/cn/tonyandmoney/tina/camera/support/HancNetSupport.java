package cn.tonyandmoney.tina.camera.support;

import android.graphics.Bitmap;
import android.util.Log;

import java.nio.ByteBuffer;

/**
 * 调用本地库
 * javap -s 类名，查看方法签名
 */
public class HancNetSupport {
    private final static String TAG = HancNetSupport.class.getSimpleName();
    private final static int BUFFER_SIZE = 2048;

    private ByteBuffer mBuffer ;

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

    private HancNetSupport(){
        mBuffer = ByteBuffer.allocateDirect(BUFFER_SIZE);
    }


    public native boolean init();
    public native int loginToServer(String ip,int port,String username,String password);

    public native int startMediaPlay(Object buffer,int len,int session);

    public void callback(String message){
        Log.i(TAG,"JNI callback: "+message);
    }


    public void callback(int value,String message){
        Log.i(TAG,String.format("callback type:%s content:%s",value,message));
    }

}
