#ifndef MAIN_HIT_HITSPHERE_H
#define MAIN_HIT_HITSPHERE_H

#include "types.h"
#include "nitro/fx.h"

extern "C" {

typedef struct HitSphere {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ VecFx32 prev;
    /* 0x18 */ VecFx32 push;
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
void HitSphere_Link(HitSphere *hit);

}

#endif
