package cn.tonyandmoney.tina.camera.support.view;

import android.annotation.SuppressLint;
import android.content.Context;
import android.text.TextUtils;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.Toast;

import cn.tonyandmoney.tina.camera.support.callback.IPlayCallback;
import io.reactivex.Single;
import io.reactivex.SingleOnSubscribe;
import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.disposables.Disposable;
import io.reactivex.functions.BiConsumer;
import io.reactivex.schedulers.Schedulers;

/**
 * 不能通过布局添加view。
 * 实际上应该是没有停止播放这种说法的，要不就是暂停
 */
@SuppressLint("ViewConstructor")
public class H264SurfaceView extends SurfaceView implements SurfaceHolder.Callback,
        BiConsumer<Integer, Throwable>, IPlayCallback {

    static {
        System.loadLibrary("net-lib");
    }

    private final static String TAG = H264SurfaceView.class.getSimpleName();


    public native int init(Surface surface, int w, int h);

    public native int play(String url, int id);

    public native int release(int id);

    private IPlayCallback mCallback;
    private Disposable mDisposable;
    private String path;
    private int mWidth;
    private int mHeight;
    private int id;


    public H264SurfaceView(Context context, IPlayCallback callback) {
        super(context);
        this.mCallback = callback;
        getHolder().addCallback(this);
    }


    /**
     * 是否准备完成。
     *
     * @return 准备完成，
     */
    @Override
    public void onReady(int id) {
        this.id = id;
        Log.i(TAG, String.format("onReady:%s", id));
        AndroidSchedulers.mainThread().scheduleDirect(() -> mCallback.onReady(id));
    }

    @Override
    public void onPause() {
        Log.i(TAG, "onPause");
        AndroidSchedulers.mainThread().scheduleDirect(() -> mCallback.onPause());
    }

    @Override
    public void onPlay() {
        Log.i(TAG, "onPlay");
        AndroidSchedulers.mainThread().scheduleDirect(() -> mCallback.onPlay());
    }

    @Override
    public void onStop(int code, String message) {
        Log.i(TAG, String.format("onStop->code: %s,message: %s", code, message));
        AndroidSchedulers.mainThread().scheduleDirect(() -> mCallback.onStop(code, message));
    }

    public void setPath(String path) {
        this.path = path;
    }

    public String getPath() {
        return path;
    }

    public void startPlay() {
        if (TextUtils.isEmpty(path)) {
            Toast.makeText(getContext(), "无效链接。", Toast.LENGTH_LONG).show();
            return;
        }
        if (id < 0) {
            Toast.makeText(getContext(), "播放器初始化失败。", Toast.LENGTH_LONG).show();
            return;
        }
        mDisposable = Single.create((SingleOnSubscribe<Integer>) emitter -> {
            emitter.onSuccess(play(path, id));
        }).subscribeOn(Schedulers.newThread())
                .unsubscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(this);
    }

    @Override
    public void onError(int code, String errMsg) {
        mCallback.onError(code, errMsg);
    }

    public void switchStatus() {
        startPlay();
    }

    /**
     * 如果成功，则不要管。如果错误，则显示。
     *
     * @param integer
     * @param throwable
     */
    @Override
    public void accept(Integer integer, Throwable throwable) {
        Log.i(TAG, "" + integer, throwable);
        if (throwable != null) {
            mCallback.onError(-1, throwable.getMessage() == null ? throwable.getMessage() : "播放错误。");
        }
    }


    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        mWidth = holder.getSurfaceFrame().width();
        mHeight = holder.getSurfaceFrame().height();
        id = init(holder.getSurface(),mWidth,mHeight);
    }

    /**
     * 这里应该要通知native代码，尺寸变化
     *
     * @param holder holder
     * @param format 格式
     * @param width  宽
     * @param height 高
     */
    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        mWidth = width;
        mHeight = height;
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        this.id = release(id);
    }

    /**
     * 一定要销毁内存
     */
    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        if (mDisposable != null && !mDisposable.isDisposed()) {
            mDisposable.dispose();
        }
        if (this.id > 0) {
            release(id);
        }
    }
}
