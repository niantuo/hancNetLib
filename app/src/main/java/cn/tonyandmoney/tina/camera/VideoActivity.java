package cn.tonyandmoney.tina.camera;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;

import cn.tonyandmoney.tina.camera.support.view.FFmpegSurfaceView;
import cn.tonyandmoney.tina.camera.support.view.H264PlayerView;
import cn.tonyandmoney.tina.camera.support.view.H264SurfaceView;

public class VideoActivity extends AppCompatActivity {

    private H264PlayerView playerView;


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video_layout);
        playerView = findViewById(R.id.player);
        String url = "rtsp://192.168.0.103:554/user=admin&password=&channel=1&stream=0.sdp?real_stream";
        playerView.setUrl(url);

    }
}
