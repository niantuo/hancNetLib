package cn.tonyandmoney.tina.camera.support.view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class FFmpegSurfaceView extends SurfaceView implements SurfaceHolder.Callback {

    static {
        System.loadLibrary("net-lib");
    }

    private final static String TAG = FFmpegSurfaceView.class.getSimpleName();

    private Bitmap bitmap;
    private Matrix matrix;
    private SurfaceHolder mHolder;
    private int width;
    private int height;
    private boolean mPlayFlag = false;

    public native void play(Bitmap bitmap);

    public native void initial(String url);


    public void setBitmapSize(int width, int height) {
        Log.i(TAG, String.format("w: %s h: %s", width, height));
        bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
    }

    public FFmpegSurfaceView(Context context) {
        super(context);
        init();
    }

    public FFmpegSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public FFmpegSurfaceView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    private void init() {
        mHolder = getHolder();
        mHolder.addCallback(this);
        matrix = new Matrix();
        bitmap = Bitmap.createBitmap(640, 480, Bitmap.Config.ARGB_8888);
    }

    /**
     * 两个线程。
     * @param url
     */
    public void startPlay(final String url) {
        mPlayFlag = true;
        new Thread(()->{
            initial(url);
            play(bitmap);
        }).start();
        new Thread(() -> {
            while (mPlayFlag) {
                refresh();
            }
        }).start();
    }

    public void stopPlay() {
        mPlayFlag = false;
    }

    private void refresh() {
        Canvas canvas = mHolder.lockCanvas(null);
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        paint.setStyle(Paint.Style.FILL);
        int mWidth = bitmap.getWidth();
        int mHeight = bitmap.getHeight();
        matrix.reset();
        matrix.setScale((float) width / mWidth, (float) height
                / mHeight);
        canvas.drawBitmap(bitmap, matrix, paint);
        mHolder.unlockCanvasAndPost(canvas);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        stopPlay();
        if (!bitmap.isRecycled())
            bitmap.recycle();
    }
}
