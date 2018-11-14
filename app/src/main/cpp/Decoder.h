//
// Created by niantuo on 2018/11/15.
//

#ifndef HANCNETLIB_DECODER_H
#define HANCNETLIB_DECODER_H

#include <libavformat/avformat.h>


class Decoder {

    int decoder(const char* data,int length, void(*Display)(AVFrame *frame));
};


#endif //HANCNETLIB_DECODER_H
