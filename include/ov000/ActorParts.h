#ifndef OV000_ACTORPARTS_H
#define OV000_ACTORPARTS_H

// Sub-objects every ov000 actor points to (C-compatible, shared with History_0219830c.c).

#include "types.h"
#include "ov000/Vec.h"

#define HISTORY_LEN 7

// The actor's state block (Actor::fsm, ctor History_Init, 0x14 bytes): the step and
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

// The actor's collision sphere (Actor::hit, ctor func_ov000_021985e8, 0x9c bytes). It starts with a
// Main HitSphere (func_0203f260, HitSphere_Link; the names up to radius are HitSphere's) and follows
// its owner actor (func_ov000_0219864c).
typedef struct ActorSub48 {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 push; // push-out from other spheres and the map (func_0203f3d0)
    u8 active; // linked into the sphere list
    u8 unk_25;
    u8 unk_26[0xa];
    u32 unk_30;
    u32 unk_34;
    s32 radius;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    VecFx32 offset;
    VecFx32 check;
    u8 unk_74[0xc];
    s32 unk_80;
    u8 unk_84[0x4];
    s32 unk_88;
    u8 unk_8c[0xc];
    u16 owner; // id of the actor the sphere follows
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
