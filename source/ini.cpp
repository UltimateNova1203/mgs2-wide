#pragma once
#include "../include/common.h"

void mgs2_ini_create_config() {
    CSimpleIniA ini_config;

    MessageBox(0, L"Could not find \"mgs2-config.ini\", we will create it now...", L"Metal Gear Solid 2 : SUBSTANCE", MB_ICONINFORMATION | MB_OK);

    //Display Section
    ini_config.SetValue("display", NULL, NULL, "; Display Section");
    ini_config.SetLongValue("display", "horizontal", 16, "; The aspect ratio width, Default \"16\"");
    ini_config.SetLongValue("display", "vertical", 9, "; The aspect ratio height, Default \"9\"");
    ini_config.SetBoolValue("display", "fix_fov", true, "; Adjust the FOV to match display, Default \"true\"");
    ini_config.SetBoolValue("display", "fix_dof", true, "; Fixes the Depth of Field issue, Default \"true\"");
    ini_config.SetBoolValue("display", "fix_fmv", true, "; Adjusts FMV size to match display size, Default \"true\"");
    ini_config.SetBoolValue("display", "camera_zoom", true, "; Adjusts the Camera Zoom to hide out of bounds, Default \"true\"");

    //Borders Section
    ini_config.SetValue("borders", NULL, NULL, "; Borders Section");
    ini_config.SetBoolValue("borders", "enabled", true, "; Enables borders in cutscenes, Default \"true\"");
    ini_config.SetBoolValue("borders", "cinematic", true, "; Uses cinematic size borders, Default \"true\"");

    //Cheats Section
    ini_config.SetValue("cheats", NULL, NULL, "; Cheats Section");
    ini_config.SetBoolValue("cheats", "drebin", false, "; Gives max ammo for weapons you have, Default \"false\"");
    ini_config.SetBoolValue("cheats", "solidus", false, "; Gives infinite O2 during Solidus torture sequence, Default \"false\"");

    SI_Error update_config = ini_config.SaveFile("mgs2-config.ini");
    if (update_config < 0) {
        MessageBox(0, L"Could not create \"mgs2-config.ini\"!", L"Metal Gear Solid 2 : SUBSTANCE", MB_ICONERROR | MB_OK);
    }
}

void mgs2_ini_create_fov() {
    CSimpleIniA ini_fov;

    MessageBox(0, L"Could not find \"mgs2-fov.ini\", we will create it now...", L"Metal Gear Solid 2 : SUBSTANCE", MB_ICONINFORMATION | MB_OK);

    //FMV Section
    ini_fov.SetValue("fmv", NULL, NULL, "; FMV Section");

    //Demo Section
    ini_fov.SetValue("demo", NULL, NULL, "; Demo Section");
    ini_fov.SetLongValue("demo", "79681824", 1, "; Tanker - Infiltration");
    ini_fov.SetLongValue("demo", "76325088", 1, "; Tanker - Mission Objective");
    ini_fov.SetLongValue("demo", "76325024", 1, "; Tanker - Snake sees Marines");
    ini_fov.SetLongValue("demo", "76325088", 1, "; Tanker - Snake sees Gurlukovich");
    ini_fov.SetLongValue("demo", "76324880", 1, "; Tanker - Snake hears Kasatka");
    ini_fov.SetLongValue("demo", "78976376", 1, "; Tanker - Bridge Scene");
    ini_fov.SetLongValue("demo", "80097936", 1, "; Tanker - Olga Pre-fight");
    ini_fov.SetLongValue("demo", "80097984", 1, "; Tanker - Olga Post-fight");
    ini_fov.SetLongValue("demo", "80924128", 1, "; Tanker - Snake vs Soldiers Pre-fight");
    ini_fov.SetLongValue("demo", "80924208", 1, "; Tanker - Snake vs Soldiers Post-fight");
    ini_fov.SetLongValue("demo", "76112448", 1, "; Tanker - Snake sees Holds");
    ini_fov.SetLongValue("demo", "82394064", 1, "; Tanker - Snake sees Ray (Lower Right)");
    ini_fov.SetLongValue("demo", "81506352", 1, "; Tanker - Ocelot Hijacks Ray 1");
    ini_fov.SetLongValue("demo", "81506320", 1, "; Tanker - Ocelot Hijacks Ray 2");
    ini_fov.SetLongValue("demo", "80329968", 1, "; Tanker - Ocelot Hijacks Ray 3");
    ini_fov.SetLongValue("demo", "81349952", 1, "; Tanker - Ocelot Hijacks Ray 4");
    ini_fov.SetLongValue("demo", "78296624", 1, "; Tanker - Ocelot Escapes");

    ini_fov.SetLongValue("demo", "81324272", 1, "; Plant - Infiltration");
    ini_fov.SetLongValue("demo", "76508272", 1, "; Plant - Mission Objective");
    ini_fov.SetLongValue("demo", "76508400", 1, "; Plant - Skull Suit Overview");
    ini_fov.SetLongValue("demo", "76508320", 1, "; Plant - Snake Elevator");
    ini_fov.SetLongValue("demo", "76508384", 1, "; Plant - Node Registration");
    ini_fov.SetLongValue("demo", "80972816", 1, "; Plant - Elevator Up");
    ini_fov.SetLongValue("demo", "79415888", 1, "; Plant - PLANT Structure");

    //Stage Section
    ini_fov.SetValue("stage", NULL, NULL, "; Stage Section");

    SI_Error update_fov = ini_fov.SaveFile("mgs2-fov.ini");
    if (update_fov < 0) {
        MessageBox(0, L"Could not create \"mgs2-fov.ini\"!", L"Metal Gear Solid 2 : SUBSTANCE", MB_ICONERROR | MB_OK);
    }
}
