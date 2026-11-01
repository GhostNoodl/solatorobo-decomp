#ifndef OV000_ACTORPARTS_H
#define OV000_ACTORPARTS_H

// Sub-objects every ov000 actor points to (C-compatible, shared with History_0219830c.c).

#include "types.h"
#include "ov000/Vec.h"

#define HISTORY_LEN 7

// The actor's state block (Actor::unk_40, ctor func_ov000_02198328, 0x14 bytes): the step and
// frame timer of the current state, flag bits, and the last states. func_ov000_02198360
// switches to a new state and pushes the old one (History_0219830c.c).
typedef struct ActorSub40 {
    u16 st;
    u16 timer;
    u64 flags;
    u8 history[HISTORY_LEN];
    u8 current;
} ActorSub40;
SIZE_ASSERT(ActorSub40, 0x14);

// The actor's movement and collision body (Actor::unk_48, ctor func_ov000_021985e8, 0x9c bytes).
typedef struct ActorSub48 {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 unk_18;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[0xa];
    u32 unk_30;
    u32 unk_34;
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    VecFx32 offset;
    VecFx32 check;
    u8 unk_74[0x24];
    u16 unk_98;
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
    u16 unk_9a_7 : 1;
    u16 unk_9a_8 : 1;
    u16 unk_9a_9 : 1;
    u16 unk_9a_10 : 6;
} ActorSub48;
SIZE_ASSERT(ActorSub48, 0x9c);

#endif
