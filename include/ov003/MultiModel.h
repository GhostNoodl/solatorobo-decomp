#ifndef OV003_MULTIMODEL_H
#define OV003_MULTIMODEL_H

// The multi-part model records of ov003 021f2374 / 021f27ec.

#include "types.h"

typedef struct {
    s16 res;
    u8 unk_02[0x136];
} Ov003MultiSlot;

typedef struct {
    u8 unk_00[4];
    void *mdl;
    u8 unk_08[0x1c];
    u8 rob[0x84];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xe];
    u16 unk_c2_0 : 4;
    u16 unk_c2_4 : 1;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 1;
    u16 unk_c2_7 : 1;
    u16 unk_c2_8 : 1;
    u8 unk_c4[0x24];
} Ov003MultiModel;

typedef struct {
    s32 m[9];
} Ov003MultiMtx33;

typedef struct {
    void *res;
    s32 x;
    s32 y;
    s32 z;
} Ov003MultiRes;

#endif
