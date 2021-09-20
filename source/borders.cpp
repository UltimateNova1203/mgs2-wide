#pragma once
#include "../include/common.h"

void mgs2_borders(bool borders_enable, bool borders_cinematic) {
    int borders_bottom;
    int borders_top;
    int a_borders_bottom = 0x005A13B5;
    int a_borders_top = 0x005A137A;

    if (borders_enable == true) {
        if (borders_cinematic == true) {
            borders_bottom = 200;
            borders_top = 600;
        }

        if (borders_cinematic == false) {
            borders_bottom = 480;
            borders_top = 480;
        }
    }

    else if (borders_enable == false) {
        borders_bottom = 0;
        borders_top = 0;
    }

    else {
        borders_bottom = 480;
        borders_top = 480;
    }

    CPatch::SetShort(a_borders_bottom, borders_bottom);
    CPatch::SetShort(a_borders_top, borders_top);
}