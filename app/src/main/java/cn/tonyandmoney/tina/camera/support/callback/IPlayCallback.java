package cn.tonyandmoney.tina.camera.support.callback;

/**
 * 播放器的回调
 */
public interface IPlayCallback {

    void onReady(int id);

    /**
     * 播放停止的回调
     *
     * @param code    如果大于-1，表示正常停止。
     * @param message
     */
    void onStop(int code, String message);

    void onError(int code,String errMsg);

    void onPlay();

    void onPause();
}
