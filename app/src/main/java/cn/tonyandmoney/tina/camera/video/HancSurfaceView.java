package cn.tonyandmoney.tina.camera.video;

import android.content.Context;
import android.graphics.Canvas;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.IOException;
import java.nio.ByteBuffer;

/**
 * 封装一下，让这个能播放h264裸流
 */
public class HancSurfaceView extends SurfaceView implements SurfaceHolder.Callback {

    private SurfaceHolder mHolder;
    private Canvas mCanvas;
    private boolean mIsDrawing;
    private MediaCodec mMediaCodec;
    private MediaFormat mFormat;
    private boolean isInitOk=false;

    public HancSurfaceView(Context context) {
        super(context);
    }

    public HancSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public HancSurfaceView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    private void init(){
        try {
            mMediaCodec = MediaCodec.createDecoderByType("video/avc");
            mFormat = MediaFormat.createVideoFormat("video/avc",720,1280);
        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        mMediaCodec.configure(mFormat,holder.getSurface(),null,0);

    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }


    private boolean onFrame(ByteBuffer byteBuffer,int length){
        int index = mMediaCodec.dequeueInputBuffer(-1);
        if (index>-1){
            ByteBuffer inputBuffer = mMediaCodec.getInputBuffer(index);
            inputBuffer.clear();
            inputBuffer.put(byteBuffer);
            mMediaCodec.queueInputBuffer(index,0,length,0,0);
        }else {
            return false;
        }
        MediaCodec.BufferInfo bufferInfo  = new MediaCodec.BufferInfo();
        int outputIndex = mMediaCodec.dequeueOutputBuffer(bufferInfo,100);
        while (outputIndex>-1){
            mMediaCodec.releaseOutputBuffer(outputIndex,true);
            outputIndex = mMediaCodec.dequeueOutputBuffer(bufferInfo,0);
        }
        return true;
    }

}
