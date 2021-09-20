#pragma once
#include "../include/common.h"
#include <string>

void mgs2_camera(float aspect_ratio) {
    /*CSimpleIniA ini_fov;

    SI_Error load_fov = ini_fov.LoadFile("mgs2-fov.ini");
    if (load_fov < 0) {
        mgs2_ini_create_fov();
    }*/
    
    float aspect_ratio_4x3 = float(4) / float(3);
    float aspect_ratio_16x9 = float(16) / float(9);
    float aspect_ratio_16x10 = float(16) / float(10);

    int a_camera_zoom = 0x008a9d6c;
    int a_is_codec = 0x00A15688;
    int *is_codec = &a_is_codec;
    int a_is_demo = 0x00A15644;
    int* is_demo = &a_is_demo;

    float display_fov = float(aspect_ratio_4x3) / float(aspect_ratio);

    if (*is_demo == 1) {
        /*int a_demo_id = 0x00A15648;
        int* demo_id = &a_demo_id;
        std::string s_demo_id = std::to_string(a_demo_id);
        char const* pchar = s_demo_id.c_str();
        float camera_zoom = ini_fov.GetLongValue("demo", pchar, 1);*/

        CPatch::SetFloat(a_camera_zoom, display_fov);
    }

    else if (*is_codec == 1) {
        CPatch::SetFloat(a_camera_zoom, 1);
    }

    else {
        CPatch::SetFloat(a_camera_zoom, display_fov);
    }
}