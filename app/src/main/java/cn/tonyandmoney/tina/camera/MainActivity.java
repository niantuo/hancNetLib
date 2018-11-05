package cn.tonyandmoney.tina.camera;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.sun.jna.NativeLong;

import cn.tonyandmoney.tina.camera.constants.Constants;
import cn.tonyandmoney.tina.camera.support.HancNetSupport;
import cn.tonyandmoney.tina.camera.support.INetCallback;
import cn.tonyandmoney.tina.camera.support.NativeLibrary;
import cn.tonyandmoney.tina.camera.support.entity.MsgHeaderInfo;

public class MainActivity extends AppCompatActivity {
    private final String TAG = MainActivity.class.getSimpleName();

    private EditText mUserText;
    private EditText mPwdText;
    private EditText mIpText;
    private EditText mPortText;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mUserText = findViewById(R.id.username);
        mPwdText = findViewById(R.id.userPwd);
        mIpText = findViewById(R.id.serverIp);
        mPortText = findViewById(R.id.serverPort);
        Button mLoginBtn = findViewById(R.id.loginBtn);
        mLoginBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                login();
            }
        });
        boolean result = HancNetSupport.getInstance().init();
        Log.i(TAG, String.format("init errCode:%s", result));
        if (result) {
            Toast.makeText(this, "SDK初始化成功。", Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(this, "SDK初始化失败。", Toast.LENGTH_LONG).show();
        }
    }


    private void login() {
        String username = mUserText.getText().toString();
        String password = mPwdText.getText().toString();
        String ip = mIpText.getText().toString();
        String port = mPortText.getText().toString();

        if (TextUtils.isEmpty(ip)) {
            Toast.makeText(this, "请输入服务器IP", Toast.LENGTH_LONG).show();
            return;
        }
        if (TextUtils.isEmpty(port)) {
            Toast.makeText(this, "请输入服务器端口", Toast.LENGTH_LONG).show();
            return;
        }
        if (TextUtils.isEmpty(username)) {
            Toast.makeText(this, "请输入用户名", Toast.LENGTH_LONG).show();
            return;
        }
        if (TextUtils.isEmpty(password)) {
            Toast.makeText(this, "请输入用户密码", Toast.LENGTH_LONG).show();
            return;
        }
        int result = HancNetSupport.getInstance().loginToServer(ip, Integer.parseInt(port), username, password);
        Log.i(TAG, String.format("login username:%s,password: %s, ip:%s,port:%s,result:%s", username, password, ip, port, result));
        if (result < 0) {
            Toast.makeText(this, "登陆失败。", Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(this, "登陆成功。", Toast.LENGTH_LONG).show();
        }
    }
}
