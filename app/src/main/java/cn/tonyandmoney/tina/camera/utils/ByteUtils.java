package cn.tonyandmoney.tina.camera.utils;

public class ByteUtils {

    /**
     * 获取 UnsignedByte
     *
     * @param value  原数字
     * @return 无符号字节
     */
    public static int getUnsignedByte(byte value) {
        return value & 0xFF;
    }

    /**
     * 将data字节型数据转换为0~65535 (0xFFFF 即 WORD)。
     * @param data
     * @return
     */
    public int getUnsignedByte (short data){
        return data&0x0FFFF ;
    }

    /**
     * 将int数据转换为0~4294967295 (0xFFFFFFFF即DWORD)。
     * @param data
     * @return
     */
    public long getUnsignedIntt (int data){ //
        return data&0xFFFFFFFF;
    }
}
