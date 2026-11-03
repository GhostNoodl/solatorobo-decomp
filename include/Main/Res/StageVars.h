#ifndef MAIN_RES_STAGEVARS_H
#define MAIN_RES_STAGEVARS_H

#include "types.h"

// The stage script variables (DTCM 0x02fe1534): the halfword array that the stage script VM
// indexes by number (Stage.cpp STAGE_VARS); the code outside the VM reads and writes single
// variables by offset.
typedef struct StageVars {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ union {
        u16 unk_02;
        u8 unk_02_bytes[2]; // saved byte by byte with unk_52..unk_5a (StageVars_Save / StageVars_Load)
    };
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1a */ s16 unk_1a;
    /* 0x1c */ s16 unk_1c;
    /* 0x1e */ u16 unk_1e;
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2a */ u16 unk_2a;
    /* 0x2c */ u16 unk_2c;
    /* 0x2e */ u16 unk_2e;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ u16 unk_32;
    /* 0x34 */ u16 posFlags;
    /* 0x36 */ s16 posX;
    /* 0x38 */ s16 posY;
    /* 0x3a */ s16 posZ;
    /* 0x3c */ u16 unk_3c;
    /* 0x3e */ u16 unk_3e;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ u16 unk_42;
    /* 0x44 */ u16 unk_44;
    // 0x46..0x4a: copied as a triple into each ObjPool entry (and StageFlags::color2) and compared
    // as a key there; ov000 compares unk_46 with a map record's 0x30 id and with FieldState::unk_cd.c[0]
    // (the first part of a FieldId).
    /* 0x46 */ u16 unk_46;
    /* 0x48 */ u16 unk_48;
    /* 0x4a */ u16 unk_4a;
    /* 0x4c */ u16 unk_4c;
    /* 0x4e */ u16 unk_4e;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ union {
        u8 unk_52_bytes[10];
        struct {
            u16 unk_52;
            u16 unk_54;
            u16 unk_56;
            u16 unk_58;
            u16 unk_5a;
        };
    };
    /* 0x5c */ u16 unk_5c;
    /* 0x5e */ u16 unk_5e;
    /* 0x60 */ u16 unk_60;
    /* 0x62 */ u16 unk_62;
    /* 0x64 */ u16 unk_64;
    /* 0x66 */ u16 unk_66;
    /* 0x68 */ u16 unk_68;
    /* 0x6a */ u16 unk_6a;
    /* 0x6c */ u16 unk_6c;
    /* 0x6e */ u16 unk_6e;
    /* 0x70 */ u16 unk_70;
    /* 0x72 */ u16 unk_72;
    /* 0x74 */ u16 unk_74;
    /* 0x76 */ u16 unk_76;
    /* 0x78 */ u16 unk_78;
    /* 0x7a */ u16 unk_7a;
    /* 0x7c */ u16 unk_7c;
    /* 0x7e */ u16 unk_7e;
    /* 0x80 */ u16 unk_80;
} StageVars;

#ifdef __cplusplus
extern "C" {
#endif
extern StageVars data_02fe1534;
#ifdef __cplusplus
}
#endif

#endif
