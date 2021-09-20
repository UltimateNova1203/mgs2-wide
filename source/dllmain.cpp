// dllmain.cpp : Defines the entry point for the DLL application.
// Includes https://github.com/brofield/simpleini
// Includes https://github.com/ExOptsTeam/NFSUExOpts/blob/master/includes/CPatch.h
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "../include/common.h"
#include "../include/cheats.h"

void mgs2_main() {
    CSimpleIniA ini_config;
    CSimpleIniA ini_fov;

    SI_Error load_config = ini_config.LoadFile("mgs2-config.ini");
    if (load_config < 0) {
        mgs2_ini_create_config();
    }

    SI_Error load_fov = ini_fov.LoadFile("mgs2-fov.ini");
    if (load_fov < 0) {
        mgs2_ini_create_fov();
    }

    //Display Section
    int display_horizontal = ini_config.GetLongValue("display", "horizontal", 16);
    int display_vertical = ini_config.GetLongValue("display", "vertical", 9);
    bool display_fix_fov = ini_config.GetBoolValue("display", "fix_fov", "true");
    bool display_fix_dof = ini_config.GetBoolValue("display", "fix_dof", "true");
    bool display_fix_fmv = ini_config.GetBoolValue("display", "fix_fmv", "true");
    bool display_camera_zoom = ini_config.GetBoolValue("display", "camera_zoom", "true");

    //Borders Section
    bool borders_enable = ini_config.GetBoolValue("borders", "enabled", "true");
    bool borders_cinematic = ini_config.GetBoolValue("borders", "cinematic", "true");

    //Cheats Section
    bool cheats_drebin = ini_config.GetBoolValue("cheats", "drebin", "false");
    bool cheats_solidus = ini_config.SetBoolValue("cheats", "solidus", "false");

    float aspect_ratio = float(display_horizontal) / float(display_vertical);

    mgs2_borders(borders_enable, borders_cinematic);

    if (display_fix_fov == true) {
        mgs2_fov(aspect_ratio);
    }

    if (display_fix_dof == true) {
        mgs2_dof();
    }
    
    /*if (display_fix_fmv == true) {
    mgs2_fmv(aspect_ratio, display_fix_fmv);
    }*/

    /*if (display_camera_zoom == true) {
        mgs2_camera(aspect_ratio);
    }*/

    /*if (cheats_drebin == true) {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&mgs2_drebin, 0, 0, NULL);
    }*/

    /*if (cheats_solidus == true) {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&mgs2_solidus, 0, 0, NULL);
    }*/
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  fdwReason, LPVOID lpReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        mgs2_main();
    }

    return TRUE;
}