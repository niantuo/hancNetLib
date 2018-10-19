package cn.tonyandmoney.tina.camera;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import cn.tonyandmoney.tina.camera.support.HancNetSupport;

public class MainActivity extends AppCompatActivity {
    private final String TAG = MainActivity.class.getSimpleName();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(HancNetSupport.getInstance().libName());
        boolean success = HancNetSupport.getInstance().hancNetSDKInit();
        Log.i(TAG, "init " + success);

        HancNetSupport.getInstance().hancConnect("127.0.0.1",99,"what",3000,1234567);
    }

}
