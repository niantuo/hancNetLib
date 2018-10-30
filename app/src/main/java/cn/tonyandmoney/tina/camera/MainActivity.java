package cn.tonyandmoney.tina.camera;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.sun.jna.NativeLong;

import cn.tonyandmoney.tina.camera.constants.Constants;
import cn.tonyandmoney.tina.camera.support.HancNetSupport;
import cn.tonyandmoney.tina.camera.support.INetCallback;
import cn.tonyandmoney.tina.camera.support.JNAHancNetLibrary;
import cn.tonyandmoney.tina.camera.support.NativeLibrary;
import cn.tonyandmoney.tina.camera.support.callback.IDemoCallback;
import cn.tonyandmoney.tina.camera.support.entity.MsgHeaderInfo;
import cn.tonyandmoney.tina.camera.utils.ByteUtils;

public class MainActivity extends AppCompatActivity implements INetCallback {
    private final String TAG = MainActivity.class.getSimpleName();

    private final JNAHancNetLibrary mHancNetLib = JNAHancNetLibrary.INSTANCE;
    private EditText mUserText;
    private EditText mPwdText;
    private EditText mIpText;
    private EditText mPortText;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mUserText =findViewById(R.id.username);
        mPwdText = findViewById(R.id.password);
        mIpText = findViewById(R.id.serverIp);
        mPortText = findViewById(R.id.serverPort);


        boolean result = mHancNetLib.HancNetSDK_Init();
        NativeLong dwUser = new NativeLong(23456);
        int errCode = JNAHancNetLibrary.INSTANCE.HancNetSDK_Connect(Constants.ServerIp, Constants.ServerPort, "1234", 4, 3000, this, dwUser);
        Log.i(TAG,"errCode:"+errCode);

        MsgHeaderInfo headerInfo = new MsgHeaderInfo();
        headerInfo.nType = Constants.TYPE_LOGIN;
        headerInfo.nFrom = Constants.FROM_MOBILE;

        NativeLibrary.INSTANCE.testCallback(new IDemoCallback() {
            @Override
            public void onCallback(String test) {
                Log.i(TAG,"onCallback: "+test);
            }
        },headerInfo);
    }


    private void login(){
        String username = mUserText.getText().toString();
        String password = mPwdText.getText().toString();
        String ip = mIpText.getText().toString();
        String port = mPortText.getText().toString();

        if (TextUtils.isEmpty(ip)){
            Toast.makeText(this,"请输入服务器IP",Toast.LENGTH_LONG).show();
            return;
        }
        if (TextUtils.isEmpty(port)){
            Toast.makeText(this,"请输入服务器端口",Toast.LENGTH_LONG).show();
            return;
        }
        if (TextUtils.isEmpty(username)){
            Toast.makeText(this,"请输入用户名",Toast.LENGTH_LONG).show();
            return;
        }
        if (TextUtils.isEmpty(password)){
            Toast.makeText(this,"请输入用户密码",Toast.LENGTH_LONG).show();
            return;
        }
        mHancNetLib.HancNetSDK_CommunicateWithServerTcp()



    }

    @Override
    public void invoke(int lUserID, String pBuf, int nBufLen, NativeLong dwUser) {
        Log.i(TAG, "invoke: " + lUserID);
    }
}
