#ifndef OV003_BLINK_H
#define OV003_BLINK_H

// Views the blinking / drifting light actors of ov003 021f2f60 and 021f3198 read: the spawn info of
// their kind and the player. The actors are Ov003PropBlink / Ov003PropDrift (ov003/Prop.h).

#include "types.h"
#include "nitro/fx.h"

typedef struct {
    u8 unk_00[0x10];
    s16 scale;
    u16 unk_12_0 : 11;
    u16 flip : 1;
} Ov003BlinkInfo;

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
} Ov003BlinkTarget;

#endif
