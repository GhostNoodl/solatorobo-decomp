#ifndef MAIN_HIT_HITSPHERE_H
#define MAIN_HIT_HITSPHERE_H

#include "types.h"

extern "C" {

typedef struct HitVec {
    int x;
    int y;
    int z;
} HitVec;

typedef struct HitSphere {
    /* 0x00 */ HitVec pos;
    /* 0x0c */ HitVec unk_0c;
    /* 0x18 */ HitVec push;
    /* 0x24 */ u8 active;
    /* 0x25 */ u8 unk_25;
    /* 0x28 */ u32 group;
    /* 0x2c */ u32 mask;
    /* 0x30 */ int unk_30;
    /* 0x34 */ int unk_34;
    /* 0x38 */ int radius;
    /* 0x3c */ int unk_3c;
    /* 0x40 */ struct HitSphere *next;
} HitSphere;

void func_0203f260(HitSphere *hit);
void func_0203f324(HitSphere *hit);

}

#endif
