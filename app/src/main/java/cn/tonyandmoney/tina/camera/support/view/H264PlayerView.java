package cn.tonyandmoney.tina.camera.support.view;

import android.content.Context;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.util.Log;
import android.view.Gravity;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ProgressBar;
import android.widget.Toast;

import cn.tonyandmoney.tina.camera.R;
import cn.tonyandmoney.tina.camera.support.callback.IPlayCallback;

/**
 * 封装一下播放器。
 */
public class H264PlayerView extends FrameLayout implements IPlayCallback {
    private final static String TAG = H264PlayerView.class.getSimpleName();

    private H264SurfaceView mSurfaceView;
    private ProgressBar mProgressBar;
    private ImageButton mPlayBtn;
    private ImageButton mFullBtn;
    private FrameLayout mBtnLayout;

    public H264PlayerView(@NonNull Context context) {
        super(context);
        init();
    }

    public H264PlayerView(@NonNull Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public H264PlayerView(@NonNull Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    private void init() {
        mSurfaceView = new H264SurfaceView(getContext(), this);
        LayoutParams lp = new LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);
        addView(mSurfaceView, 0, lp);
        mProgressBar = new ProgressBar(getContext());

        LayoutParams layoutParams = new LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);
        mBtnLayout = new FrameLayout(getContext());
        addView(mBtnLayout, layoutParams);

        LayoutParams wrapLp = new LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        wrapLp.gravity = Gravity.CENTER;
        addView(mProgressBar, wrapLp);

        initBtns();

        setOnClickListener(v -> mBtnLayout.setVisibility(VISIBLE));

    }

    private void initBtns() {
        mPlayBtn = new ImageButton(getContext());
        mPlayBtn.setImageResource(R.drawable.ic_play_arrow_black_24dp);
        LayoutParams layoutParams = new LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        layoutParams.gravity = Gravity.START | Gravity.BOTTOM;
        layoutParams.setMargins(20, 20, 20, 20);
        mPlayBtn.setLayoutParams(layoutParams);
        mPlayBtn.setPadding(20, 20, 20, 20);
        mBtnLayout.addView(mPlayBtn);
        mBtnLayout.setBackgroundResource(R.drawable.transparent);

        mFullBtn = new ImageButton(getContext());
        LayoutParams layoutParams1 = new LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        layoutParams1.setMargins(20, 20, 20, 20);
        layoutParams1.gravity = Gravity.END | Gravity.BOTTOM;
        mFullBtn.setLayoutParams(layoutParams1);
        mFullBtn.setImageResource(R.drawable.ic_fullscreen_black_24dp);
        mFullBtn.setPadding(20, 20, 20, 20);
        mBtnLayout.addView(mFullBtn);

        mBtnLayout.setOnClickListener(v -> mBtnLayout.setVisibility(INVISIBLE));
        mPlayBtn.setOnClickListener(v -> {
            mProgressBar.setVisibility(VISIBLE);
            mSurfaceView.switchStatus();
        });
        mFullBtn.setOnClickListener(v -> fullScreen());
    }


    /**
     * 实现全屏播放
     */
    private void fullScreen() {

    }

    @Override
    protected void onFinishInflate() {
        super.onFinishInflate();
        Log.i(TAG, "onFinishInflate");
    }

    public void setUrl(String url) {
        mSurfaceView.setPath(url);
        Log.i(TAG, String.format("setUrl:%s", url));
    }

    public void startPlay() {
        mSurfaceView.startPlay();
    }

    @Override
    public void onReady(int id) {
        mProgressBar.setVisibility(GONE);
        mPlayBtn.setImageResource(R.drawable.ic_play_arrow_black_24dp);
    }

    @Override
    public void onStop(int code, String message) {
        mProgressBar.setVisibility(GONE);
        mPlayBtn.setImageResource(R.drawable.ic_play_arrow_black_24dp);
    }


    @Override
    public void onPlay() {
        mProgressBar.setVisibility(GONE);
        mPlayBtn.setImageResource(R.drawable.ic_pause_black_24dp);
    }

    @Override
    public void onPause() {
        mProgressBar.setVisibility(GONE);
        mPlayBtn.setImageResource(R.drawable.ic_play_arrow_black_24dp);
    }

    @Override
    public void onError(int code, String errMsg) {
        Log.e(TAG, String.format("onError->code:%s  errMsg:%s", code, errMsg));
        Toast.makeText(getContext(), errMsg, Toast.LENGTH_LONG).show();
    }
}
