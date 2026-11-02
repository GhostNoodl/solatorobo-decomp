#ifndef OV003_BLINK_H
#define OV003_BLINK_H

// The blinking / drifting light actors of ov003 021f2f60 and 021f3198 (views of the actor, its
// model and its spawn info).

#include "types.h"
#include "nitro/fx.h"

typedef struct {
    u8 unk_00[0x78];
    VecFx32 pos;
    u8 unk_84[0x24];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u8 unk_b4[0xa];
    u8 alpha;
    u8 unk_bf[3];
    u16 visible : 1;
    u16 unk_c2_1 : 2;
    u16 flip : 1;
    u16 shadow : 1;
} Ov003BlinkModel;

typedef struct {
    u8 unk_00[0x10];
    s16 scale;
    u16 unk_12_0 : 11;
    u16 flip : 1;
} Ov003BlinkInfo;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[8];
    u16 pattern;
    u16 angleA;
    u16 angleB;
    s16 unk_1e;
    u8 unk_20[0x18];
    Ov003BlinkModel *model;
    u8 unk_3c[0x34];
    VecFx32 pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[0x30];
    union {
        struct {
            VecFx32 offset;
            s32 phase;
        } drift;
        struct {
            s32 radius;
            u16 phase;
        } blink;
    } u;
} Ov003Blink;

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
} Ov003BlinkTarget;

#endif
