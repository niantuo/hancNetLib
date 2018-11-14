//
// Created by niantuo on 2018/11/15.
//

#include "Decoder.h"
#include <inttypes.h>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

typedef struct _RenderParam{
    SwsContext * swsContext;
    AVCodecContext *avCodecContext;
};

int Decoder::decoder(const char *data, int length, void (*Display)(AVFrame *)) {
    int cur_size = length;
    int ret = 0;


    return 0;
}


void Display(AVFrame *frame, void*param, void*ctx){


}