#pragma once
#include "../include/common.h"

void mgs2_fmv(float aspect_ratio) {
    float aspect_ratio_4x3 = float(4) / float(3);
    float aspect_ratio_16x9 = float(16) / float(9);
    float aspect_ratio_16x10 = float(16) / float(10);

    int fmv_borders_bottom;
    int fmv_borders_top;
    int a_fmv_borders_top = 0x0057D295;
    int a_fmv_borders_bottom = 0x0057D28F;
    //char a_fmv_resize_opcode = 0x0057D263;

    if (aspect_ratio == aspect_ratio_4x3) {
        fmv_borders_bottom = 524;
        fmv_borders_top = 970;
    }
    
    else if (aspect_ratio == aspect_ratio_16x9) {
        fmv_borders_bottom = 620;
        fmv_borders_top = 0;
    }

    else if (aspect_ratio == aspect_ratio_16x10) {
        fmv_borders_bottom = 580;
        fmv_borders_top = 330;
    }

    else {
        fmv_borders_bottom = 480;
        fmv_borders_top = 480;
    }

    CPatch::SetInt(a_fmv_borders_bottom, fmv_borders_bottom);
    CPatch::SetInt(a_fmv_borders_top, fmv_borders_top);
}