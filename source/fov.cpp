#pragma once
#include "../include/common.h"

void mgs2_fov(float aspect_ratio) {
    float aspect_ratio_4x3 = float(4) / float(3);
    float aspect_ratio_16x9 = float(16) / float(9);
    float aspect_ratio_16x10 = float(16) / float(10);

    int a_fov_culling = 0x008A9E5B;
    int a_fov_world = 0x008A9EF5;
    int a_fov_particles = 0x008A9F48;
    int a_alpha_size_width = 0x008C0B6C;
    int a_alpha_size_height = 0x008C0BA4;

    if (aspect_ratio != aspect_ratio_4x3) {
        float display_fov = float(aspect_ratio_4x3) / float(aspect_ratio);

        CPatch::SetFloat(a_fov_culling, display_fov);
        CPatch::SetFloat(a_fov_world, display_fov);
        CPatch::SetFloat(a_fov_particles, display_fov);
        CPatch::SetFloat(a_alpha_size_width, display_fov);
    }
}