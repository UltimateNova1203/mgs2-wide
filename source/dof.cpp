#pragma once
#include "../include/common.h"

void mgs2_dof() {
    int a_dof_shift_right = 0x00DB7060;
    int a_dof_shift_down = 0x00DB7064;

    CPatch::SetInt(a_dof_shift_right, 1);
    CPatch::SetInt(a_dof_shift_down, 1);
}