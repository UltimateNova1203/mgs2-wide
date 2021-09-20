#pragma once
#include "../include/common.h"

void mgs2_camera(float aspect_ratio) {
    float aspect_ratio_4x3 = float(4) / float(3);
    float aspect_ratio_16x9 = float(16) / float(9);
    float aspect_ratio_16x10 = float(16) / float(10);

    int a_camera_zoom = 0x008a9d6c;
    int a_is_codec = 0x00A15688;
    int *is_codec = &a_is_codec;
    float display_fov = float(aspect_ratio_4x3) / float(aspect_ratio);

    if (*is_codec == 0) {
        CPatch::SetFloat(a_camera_zoom, display_fov);
    }

    if (*is_codec == 1) {
        CPatch::SetFloat(a_camera_zoom, 1);
    }
}