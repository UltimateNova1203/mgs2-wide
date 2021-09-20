#pragma once
#include "../include/CPatch.h"
#include "../include/SimpleIni.h"

void mgs2_ini_create_config();
void mgs2_ini_create_fov();
void mgs2_borders(bool borders_enable, bool borders_cinematic);
void mgs2_camera(float aspect_ratio);
void mgs2_dof();
void mgs2_fmv(float aspect_ratio);
void mgs2_fov(float aspect_ratio);
void mgs2_hud(float aspect_ratio);