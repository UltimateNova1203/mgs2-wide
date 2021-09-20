#pragma once
#include "../include/common.h"

void mgs2_hud(float aspect_ratio) {
    char a_weapon_ammo_bullets_1 = 0x0041BC08;
    char a_weapon_ammo_bullets_2 = 0x0041BC16;

    CPatch::SetChar(a_weapon_ammo_bullets_1, 28);
    CPatch::SetChar(a_weapon_ammo_bullets_2, 28);
}