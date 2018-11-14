package cn.tonyandmoney.tina.camera;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;

import cn.tonyandmoney.tina.camera.support.view.FFmpegSurfaceView;

public class VideoActivity extends AppCompatActivity {

    private FFmpegSurfaceView fmpegSurfaceView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video_layout);
        fmpegSurfaceView = findViewById(R.id.videoView);
        String url = "rtsp://192.168.0.101:554/user=admin&password=&channel=1&stream=0.sdp?real_stream";
        findViewById(R.id.btnPlay).setOnClickListener(v -> {
            fmpegSurfaceView.startPlay(url);
        });
    }
}
