package cn.tonyandmoney.tina.camera.support.entity;

import com.sun.jna.Structure;

import java.util.ArrayList;
import java.util.List;

import cn.tonyandmoney.tina.camera.utils.ByteUtils;

/**
 * 发送给后端的消息的头消息
 * c++  unsigned char 占1个字节，在java中可以用byte来表示
 * 传递的数据刚好能对的上。
 */
public class MsgHeaderInfo extends Structure {

    public static class ByReference extends MsgHeaderInfo implements Structure.ByReference {

    }

    public byte nType = 22;
    public byte nFrom = 32;
    public byte nTo = 10;
    public int nFromClientID = 8;
    public int nToClientID = 1;

    public MsgHeaderInfo() {

    }


    @Override
    protected List getFieldOrder() {
        List<String> fields = new ArrayList<>();
        fields.add("nType");
        fields.add("nFrom");
        fields.add("nTo");
        fields.add("nFromClientID");
        fields.add("nToClientID");
        return fields;
    }
}
