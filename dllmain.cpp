// dllmain.cpp : Defines the entry point for the DLL application.
// Includes https://github.com/brofield/simpleini
// Includes https://github.com/ExOptsTeam/NFSUExOpts/blob/master/includes/CPatch.h
#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "SimpleIni.h"
#include "CPatch.h"

bool is_game_running;
float aspect_ratio_4x3 = float(4) / float(3);
float aspect_ratio_16x9 = float(16) / float(9);
float aspect_ratio_16x10 = float(16) / float(10);

void mgs2_wide_borders(float aspect_ratio, bool borders_enabled, bool borders_cinematic) {
    int borders_bottom;
    int borders_top;
    int a_borders_top = 0x005A137A;
    int a_borders_bottom = 0x005A13B5;

    if (borders_enabled == false) {
        borders_bottom = 0;
        borders_top = 0;
    }

    if (borders_enabled == true && borders_cinematic == true) {
        borders_bottom = (int)200;
        borders_top = (int)600;
    }

    if (borders_enabled == true && borders_cinematic == false) {
        borders_bottom = (int)480;
        borders_top = (int)480;
    }

    CPatch::SetShort(a_borders_bottom, borders_bottom);
    CPatch::SetShort(a_borders_top, borders_top);
}

void mgs2_wide_fmv(float aspect_ratio) {
    int fmv_borders_bottom;
    int fmv_borders_top;
    int a_fmv_borders_top = 0x0057D295;
    int a_fmv_borders_bottom = 0x0057D28F;
    char a_fmv_resize_opcode = 0x0057D263;

    if (aspect_ratio == aspect_ratio_4x3) {
        fmv_borders_bottom = 524;
        fmv_borders_top = 970;
    }
    if (aspect_ratio == aspect_ratio_16x9) {
        fmv_borders_bottom = 620;
        fmv_borders_top = 0;
        }
    if (aspect_ratio == aspect_ratio_16x10) {
        fmv_borders_bottom = 580;
        fmv_borders_top = 330;
    }

    CPatch::SetInt(a_fmv_borders_bottom, fmv_borders_bottom);
    CPatch::SetInt(a_fmv_borders_top, fmv_borders_top);
}

void mgs2_wide_fov(float aspect_ratio) {
    int a_fov_culling = 0x008A9E5B;
    int a_fov_world = 0x008A9EF5;
    int a_fov_particles = 0x008A9F48;

    if (aspect_ratio != aspect_ratio_4x3) {

        float display_fov_step_1 = float(aspect_ratio) - float(aspect_ratio_4x3);
        float display_fov_step_2 = float(display_fov_step_1) / float(2);
        float display_fov = float(1) - float(display_fov_step_2);

        CPatch::SetFloat(a_fov_culling, display_fov);
        CPatch::SetFloat(a_fov_world, display_fov);
        CPatch::SetFloat(a_fov_particles, display_fov);
    }
}

//void mgs2_wide_hud() {
//    char a_weapon_ammo_bullets_1 = 0x0041BC08;
//    char a_weapon_ammo_bullets_2 = 0x0041BC16;
//
//    CPatch::SetChar(a_weapon_ammo_bullets_1, 28);
//    CPatch::SetChar(a_weapon_ammo_bullets_2, 28);
//}

//void mgs2_drebin() {
//    BYTE* in_game = (BYTE*)0x00A18C24;
//    short* m9 = (short*)0x0118B06E;
//    short* m9_max = (short*)0x0118B0B6;
//    short* usp = (short*)0x0118B070;
//    short* usp_max = (short*)0x0118B0B8;
//    short* socom = (short*)0x0118B072;
//    short* socom_max = (short*)0x0118B0BA;
//    short* psg1 = (short*)0x0118B074;
//    short* psg1_max = (short*)0x0118B0BC;
//    short* rgb6 = (short*)0x0118B076;
//    short* rgb6_max = (short*)0x0118B0BE;
//    short* nikita = (short*)0x0118B078;
//    short* nikita_max = (short*)0x0118B0C0;
//    short* stinger = (short*)0x0118B07A;
//    short* stinger_max = (short*)0x0118B0C2;
//    short* claymore = (short*)0x0118B07C;
//    short* claymore_max = (short*)0x0118B0C4;
//    short* c4 = (short*)0x0118B07E;
//    short* c4_max = (short*)0x0118B0C6;
//    short* chaff = (short*)0x0118B080;
//    short* chaff_max = (short*)0x0118B0C8;
//    short* stun = (short*)0x0118B082;
//    short* stun_max = (short*)0x0118B0CA;
//    short* dmic = (short*)0x0118B084;
//    short* dmic_max = (short*)0x0118B0CC;
//    short* hfblade = (short*)0x0118B086;
//    short* hfblade_max = (short*)0x0118B0CE;
//    short* coolant = (short*)0x0118B088;
//    short* coolant_max = (short*)0x0118B0D0;
//    short* aks74u = (short*)0x0118B08A;
//    short* aks74u_max = (short*)0x0118B0D2;
//    short* magazine = (short*)0x0118B08C;
//    short* magazine_max = (short*)0x0118B0D4;
//    short* grenade = (short*)0x0118B08E;
//    short* grenade_max = (short*)0x0118B0D6;
//    short* m4 = (short*)0x0118B090;
//    short* m4_max = (short*)0x0118B0D8;
//    short* psg1t = (short*)0x0118B092;
//    short* psg1t_max = (short*)0x0118B0DA;
//    short* dmic_zoom = (short*)0x0118B090;
//    short* dmic_zoom_max = (short*)0x0118B0D8;
//    short* book = (short*)0x0118B092;
//    short* book_max = (short*)0x0118B0DA;
//
//    while (is_game_running == true) {
//        if (*in_game == 1) {
//            if (*m9 != 65535) {
//                CPatch::SetShort(*m9, *m9_max);
//            }
//
//            if (*usp != 65535) {
//                CPatch::SetShort(*usp, *usp_max);
//            }
//
//            if (*socom != 65535) {
//                CPatch::SetShort(*socom, *socom_max);
//            }
//
//            if (*psg1 != 65535) {
//                CPatch::SetShort(*psg1, *psg1_max);
//            }
//
//            if (*rgb6 != 65535) {
//                CPatch::SetShort(*rgb6, *rgb6_max);
//            }
//
//            if (*nikita != 65535) {
//                CPatch::SetShort(*nikita, *nikita_max);
//            }
//
//            if (*stinger != 65535) {
//                CPatch::SetShort(*stinger, *stinger_max);
//            }
//
//            if (*claymore != 65535) {
//                CPatch::SetShort(*claymore, *claymore_max);
//            }
//
//            if (*c4 != 65535) {
//                CPatch::SetShort(*c4, *c4_max);
//            }
//
//            if (*chaff != 65535) {
//                CPatch::SetShort(*chaff, *chaff_max);
//            }
//
//            if (*stun != 65535) {
//                CPatch::SetShort(*stun, *stun_max);
//            }
//
//            if (*dmic != 65535) {
//                CPatch::SetShort(*dmic, *dmic_max);
//            }
//
//            if (*hfblade != 65535) {
//                CPatch::SetShort(*hfblade, *hfblade_max);
//            }
//
//            if (*coolant != 65535) {
//                CPatch::SetShort(*coolant, *coolant_max);
//            }
//
//            if (*aks74u != 65535) {
//                CPatch::SetShort(*aks74u, *aks74u_max);
//            }
//
//            if (*magazine != 65535) {
//                CPatch::SetShort(*magazine, *magazine_max);
//            }
//
//            if (*grenade != 65535) {
//                CPatch::SetShort(*grenade, *grenade_max);
//            }
//
//            if (*m4 != 65535) {
//                CPatch::SetShort(*m4, *m4_max);
//            }
//
//            if (*psg1t != 65535) {
//                CPatch::SetShort(*psg1t, *psg1t_max);
//            }
//
//            if (*dmic_zoom != 65535) {
//                CPatch::SetShort(*dmic_zoom, *dmic_zoom_max);
//            }
//
//            if (*book != 65535) {
//                CPatch::SetShort(*book, *book_max);
//            }
//            
//        }
//    }
//    Sleep(100);
//}

//void mgs2_cheats_solidus_torture() {
//    bool is_enabled;
//    //BYTE* a_stageid = (BYTE*)0x00A08198;
//    //BYTE* a_iscutscene = (BYTE*)0x00A15644;
//    //WORD* a_o2value = (WORD*)0x0118AEBE;
//
//    is_enabled = true;
//    //while (is_enabled == true) {
//    //    if (a_iscutscene == 0) {
//    //        if (*a_stageid == 65) {
//    //            if (*a_o2value < 2600 && *a_o2value > 0) {
//    //                *a_o2value = 2600;
//    //            }
//    //        }
//
//    //        if (*a_stageid == 64) {
//    //            if (*a_o2value < 360 && *a_o2value > 0) {
//    //                *a_o2value = 360;
//    //            }
//    //        }
//    //    }
//    //    Sleep(100);
//    //}
//
//    BYTE* StageID = (BYTE*)0x00A08198;
//    BYTE* isCutscene = (BYTE*)0x00A15644; //(Byte)
//    WORD* O2Value = (WORD*)0x0118AEBE; //(2Byte)
//
//    while (is_enabled == false) {
//        if (*StageID == 65) {
//            if (*isCutscene == 0) {
//                if (*O2Value > 0) {
//                    if (*O2Value < 2600) {
//                        *O2Value = 2600;
//                    }
//                }
//            }
//        }
//
//        if (*StageID == 64) {
//            if (*isCutscene == 0) {
//                if (*O2Value > 0) {
//                    if (*O2Value < 360) {
//                       *O2Value = 360;
//                    }
//                }
//            }
//        }
//        Sleep(100);
//    }
//}

void mgs2_ini_create() {
    CSimpleIniA ini;

    //Display Section
    ini.SetLongValue("display", "horizontal", 1920, "; The displays width, Default \"1920\"");
    ini.SetLongValue("display", "vertical", 1080, "; The displays height, Default \"1080\"");
    ini.SetBoolValue("display", "preserve_fov", "true", "; Adjust the FOV to match display, Default \"true\"");

    //Borders Section
    ini.SetBoolValue("borders", "enabled", "true", "; Enables borders in cutscenes, Default \"true\"");
    ini.SetBoolValue("borders", "cinematic", "false", "; Uses cinematic size borders, Default \"true\"");

    //Cheats Section
    //ini.SetBoolValue("cheats", "drebin", "false", "; Gives max ammo for weapons you have, Default \"false\"");
    //ini.SetBoolValue("cheats", "solidus", "false", "; Gives infinite O2 during Solidus torture sequence, Default \"false\"");
    SI_Error update = ini.SaveFile("mgs2-config.ini");
    if (update < 0) {
        MessageBox(0, L"We couldn't create the needed config file for the mod!", L"Metal Gear Solid 2 : SUBSTANCE", MB_ICONERROR | MB_OK);
    }
}

void mgs2_main() {
    CSimpleIniA ini;
    SI_Error config = ini.LoadFile("mgs2-config.ini");
    if (config < 0) {
        mgs2_ini_create();
    }

    //Display Section
    int display_horizontal = ini.GetLongValue("display", "horizontal", 1920);
    int display_vertical = ini.GetLongValue("display", "vertical", 1080);
    bool display_preserve_fov = ini.GetBoolValue("display", "preserve_fov", "true");

    //Borders Section
    bool borders_enabled = ini.GetBoolValue("borders", "enabled", "true");
    bool borders_cinematic = ini.GetBoolValue("borders", "cinematic", "true");

    //Cheats Section
    //bool drebin_enabled = ini.GetBoolValue("cheats", "drebin", "false");
    //bool solidus_enabled = ini.GetBoolValue("cheats", "solidus", "false");

    float aspect_ratio = float(display_horizontal) / float(display_vertical);

    mgs2_wide_borders(aspect_ratio, borders_enabled, borders_cinematic);
    mgs2_wide_fmv(aspect_ratio);
    mgs2_wide_fov(aspect_ratio);

    //if (drebin_enabled == true) {
    //    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&mgs2_drebin, 0, 0, NULL);
    //}
    //if (solidus_enabled == true) {
    //    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&mgs2_solidus, 0, 0, NULL);
    //}
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  fdwReason, LPVOID lpReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        is_game_running = true;
        mgs2_main();
    }

    return TRUE;
}