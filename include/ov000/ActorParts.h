#ifndef OV000_ACTORPARTS_H
#define OV000_ACTORPARTS_H

// Sub-objects every ov000 actor points to (C-compatible, shared with History_0219830c.c).

#include "types.h"
#include "ov000/Vec.h"

#define HISTORY_LEN 7

// An actor's rotation (Actor::rot, three binary angles).
typedef struct ActorRot {
    u16 x;
    u16 y;
    u16 z;
} ActorRot;

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

// Reads through a const view: MWCC does not merge these with an earlier plain read of the same
// field, so a state machine re-reads the state or timer where the target does.
static inline u16 ActorSub40_State(const ActorSub40 *s) {
    return s->st;
}

static inline u16 ActorSub40_Timer(const ActorSub40 *s) {
    return s->timer;
}

// The block at Actor::unk_44 (0x24 bytes; func_ov000_021984f4 sets it up).
typedef struct ActorSub44 {
    VecFx32 pos;
    VecFx32 unk_0c;
    u8 unk_18[0x4];
    s32 unk_1c;
    u16 unk_20;
    union {
        u16 unk_22; // or-ed whole by the ov003 shot
        struct {
            u16 unk_22_0 : 1;
            u16 unk_22_1 : 1;
            u16 unk_22_2 : 2;
            u16 unk_22_4 : 1;
            u16 unk_22_5 : 11;
        };
    };
} ActorSub44;

// The actor's hit-point block (Actor::hp as u16[], Actor::hpObj as a struct).
typedef struct ActorHp {
    u16 cur; // hp[0]
    u16 max; // hp[1]
    u16 unk_04; // hp[2]
    u16 dmg; // hp[3]: damage taken
    u8 kind; // damage kind
    u8 kind2;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} ActorHp;

// The actor's collision sphere (Actor::hit, ctor func_ov000_021985e8, 0x9c bytes). It starts with a
// Main HitSphere (func_0203f260, HitSphere_Link; the names up to radius are HitSphere's) and follows
// its owner actor (func_ov000_0219864c).
typedef struct ActorSub48 {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 push; // push-out from other spheres and the map (func_0203f3d0)
    u8 active; // linked into the sphere list
    u8 unk_25;
    u8 unk_26[0x2];
    u32 unk_28;
    u8 unk_2c[0x4];
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
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c[0xc];
    u16 owner; // id of the actor the sphere follows
    union {
        u16 unk_9a; // or-ed whole by the ov003 shot
        struct {
            u16 unk_9a_0 : 1;
            u16 unk_9a_1 : 1;
            u16 unk_9a_2 : 1;
            u16 unk_9a_3 : 1;
            u16 unk_9a_4 : 1;
            u16 unk_9a_5 : 1;
            u16 unk_9a_6 : 1;
            u16 unk_9a_7 : 1;
            u16 unk_9a_8 : 1;
            u16 unk_9a_9 : 1;
            u16 unk_9a_10 : 6;
        };
    };
} ActorSub48;
SIZE_ASSERT(ActorSub48, 0x9c);

#endif
