#pragma once
#include "../include/cheats.h"

void mgs2_drebin() {
    BYTE* in_game = (BYTE*)0x00A18C24;

    if (*in_game == 1) {
        // M9
        short* m9 = (short*)0x0118B06E;
        short* m9_max = (short*)0x0118B0B6;
        if (*m9 = 0) {
            CPatch::SetShort(*m9, *m9_max);
        }

        // USP
        short* usp = (short*)0x0118B070;
        short* usp_max = (short*)0x0118B0B8;
        if (*usp = 0) {
            CPatch::SetShort(*usp, *usp_max);
        }

        // SOCOM
        short* socom = (short*)0x0118B072;
        short* socom_max = (short*)0x0118B0BA;
        if (*socom = 0) {
            CPatch::SetShort(*socom, *socom_max);
        }

        // PSG1
        short* psg1 = (short*)0x0118B074;
        short* psg1_max = (short*)0x0118B0BC;
        if (*psg1 = 0) {
            CPatch::SetShort(*psg1, *psg1_max);
        }

        // RGB6
        short* rgb6 = (short*)0x0118B076;
        short* rgb6_max = (short*)0x0118B0BE;
        if (*rgb6 = 0) {
            CPatch::SetShort(*rgb6, *rgb6_max);
        }

        // Nikita
        short* nikita = (short*)0x0118B078;
        short* nikita_max = (short*)0x0118B0C0;
        if (*nikita = 0) {
            CPatch::SetShort(*nikita, *nikita_max);
        }

        // Stinger
        short* stinger = (short*)0x0118B07A;
        short* stinger_max = (short*)0x0118B0C2;
        if (*stinger = 0) {
            CPatch::SetShort(*stinger, *stinger_max);
        }

        // Claymore
        short* claymore = (short*)0x0118B07C;
        short* claymore_max = (short*)0x0118B0C4;
        if (*claymore = 0) {
            CPatch::SetShort(*claymore, *claymore_max);
        }

        // C4
        short* c4 = (short*)0x0118B07E;
        short* c4_max = (short*)0x0118B0C6;
        if (*c4 = 0) {
            CPatch::SetShort(*c4, *c4_max);
        }

        // Chaff Grenade
        short* chaff = (short*)0x0118B080;
        short* chaff_max = (short*)0x0118B0C8;
        if (*chaff = 0) {
            CPatch::SetShort(*chaff, *chaff_max);
        }

        // Stun Grenade
        short* stun = (short*)0x0118B082;
        short* stun_max = (short*)0x0118B0CA;
        if (*stun = 0) {
            CPatch::SetShort(*stun, *stun_max);
        }

        // Digital Mic
        short* dmic = (short*)0x0118B084;
        short* dmic_max = (short*)0x0118B0CC;
        if (*dmic = 0) {
            CPatch::SetShort(*dmic, *dmic_max);
        }

        // High Frequency Blade
        short* hfblade = (short*)0x0118B086;
        short* hfblade_max = (short*)0x0118B0CE;
        if (*hfblade = 0) {
            CPatch::SetShort(*hfblade, *hfblade_max);
        }

        // Coolant
        short* coolant = (short*)0x0118B088;
        short* coolant_max = (short*)0x0118B0D0;
        if (*coolant = 0) {
            CPatch::SetShort(*coolant, *coolant_max);
        }

        // AKS-74u
        short* aks74u = (short*)0x0118B08A;
        short* aks74u_max = (short*)0x0118B0D2;
        if (*aks74u = 0) {
            CPatch::SetShort(*aks74u, *aks74u_max);
        }

        // Magazine
        short* magazine = (short*)0x0118B08C;
        short* magazine_max = (short*)0x0118B0D4;
        if (*magazine = 0) {
            CPatch::SetShort(*magazine, *magazine_max);
        }

        //Grenade
        short* grenade = (short*)0x0118B08E;
        short* grenade_max = (short*)0x0118B0D6;
        if (*grenade = 0) {
            CPatch::SetShort(*grenade, *grenade_max);
        }

        // M4
        short* m4 = (short*)0x0118B090;
        short* m4_max = (short*)0x0118B0D8;
        if (*m4 = 0) {
            CPatch::SetShort(*m4, *m4_max);
        }

        // PSG1-T
        short* psg1t = (short*)0x0118B092;
        short* psg1t_max = (short*)0x0118B0DA;
        if (*psg1t = 0) {
            CPatch::SetShort(*psg1t, *psg1t_max);
        }

        // Digital Mic (Zoomed)
        short* dmic_zoom = (short*)0x0118B090;
        short* dmic_zoom_max = (short*)0x0118B0D8;
        if (*dmic_zoom = 0) {
            CPatch::SetShort(*dmic_zoom, *dmic_zoom_max);
        }

        // Book
        short* book = (short*)0x0118B092;
        short* book_max = (short*)0x0118B0DA;
        if (*book = 0) {
            CPatch::SetShort(*book, *book_max);
        }

    }
    Sleep(100);
}

void mgs2_solidus() {
    bool is_enabled;
    //BYTE* a_stageid = (BYTE*)0x00A08198;
    //BYTE* a_iscutscene = (BYTE*)0x00A15644;
    //WORD* a_o2value = (WORD*)0x0118AEBE;

    is_enabled = true;
    //while (is_enabled == true) {
    //    if (a_iscutscene == 0) {
    //        if (*a_stageid == 65) {
    //            if (*a_o2value < 2600 && *a_o2value > 0) {
    //                *a_o2value = 2600;
    //            }
    //        }

    //        if (*a_stageid == 64) {
    //            if (*a_o2value < 360 && *a_o2value > 0) {
    //                *a_o2value = 360;
    //            }
    //        }
    //    }
    //    Sleep(100);
    //}

    BYTE* StageID = (BYTE*)0x00A08198;
    BYTE* isCutscene = (BYTE*)0x00A15644; //(Byte)
    WORD* O2Value = (WORD*)0x0118AEBE; //(2Byte)

    while (is_enabled == false) {
        if (*StageID == 65) {
            if (*isCutscene == 0) {
                if (*O2Value > 0) {
                    if (*O2Value < 2600) {
                        *O2Value = 2600;
                    }
                }
            }
        }

        if (*StageID == 64) {
            if (*isCutscene == 0) {
                if (*O2Value > 0) {
                    if (*O2Value < 360) {
                       *O2Value = 360;
                    }
                }
            }
        }
        Sleep(100);
    }
}