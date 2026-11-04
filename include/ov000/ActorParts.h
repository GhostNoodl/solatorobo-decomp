#ifndef OV000_ACTORPARTS_H
#define OV000_ACTORPARTS_H

// Sub-objects every ov000 actor points to (C-compatible, shared with History_0219830c.c).

#include "types.h"
#include "ov000/Vec.h"
#include "Main/Math/Rot16.h"

#define HISTORY_LEN 7

// An actor's rotation (Actor::rot, three binary angles).
typedef Rot16 ActorRot;

// The actor's state block (Actor::fsm, ctor History_Init, 0x14 bytes): the step and
// frame timer of the current state, flag bits, and the last states. History_SetState
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

// The block at Actor::unk_44 (0x24 bytes; Obj021984c8_UpdatePos sets it up).
typedef struct ActorSub44 {
    VecFx32 pos;
    VecFx32 unk_0c;
    u8 unk_18[0x4];
    s32 unk_1c; // added to the hit distance (func_ov000_0219aca8)
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
    s32 (*unk_10)(s32 dmg); // applied to the damage this actor deals (Hit_Apply)
    u32 unk_14;
    s32 (*unk_18)(s32 dmg); // applied to the damage this actor takes (Hit_Apply)
} ActorHp;

// The actor's collision sphere (Actor::hit, ctor ActorSub48_Init, 0x9c bytes). It starts with a
// Main HitSphere (HitSphere_Init, HitSphere_Link; the names up to radius are HitSphere's) and follows
// its owner actor (ActorSub48_UpdatePos).
typedef struct ActorSub48 {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 push; // push-out from other spheres and the map (HitSphere_Collide)
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
    VecFx32 unk_74; // contact point of the last map hit (Body_Update); unk_80..88: its normal
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

// The actor's resource block (Actor::unk_34, 0x138 bytes, ctor ResSet_Init); the robot embeds four.
typedef struct ActorRes {
    s16 unk_00; // negative until the resources are loaded
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 unk_03_1 : 1;
    u8 unk_03_2 : 1;
    u8 unk_03_3 : 1;
    u8 unk_03_4 : 1;
    u8 unk_03_5 : 1;
    u8 unk_03_6 : 2;
    // From 0x0c, five 0x3c-byte entries (a handle, a 0x20-byte name and a 0x18-byte extension;
    // ResSet_Init clears them). The ov003 actors read entries 2 and 4.
    u8 unk_04[0x8];
    void **unk_0c; // entry 0's handle
    char unk_10[0x20]; // entry 0's name
    char unk_30[0x18]; // entry 0's extension
    void **unk_48; // entry 1's handle
    char unk_4c[0x20]; // entry 1's name
    char unk_6c[0x18]; // entry 1's extension
    u32 *unk_84; // entry 2's handle
    char unk_88[0x20]; // entry 2's name
    char unk_a8[0x18]; // entry 2's extension
    u32 *unk_c0;
    u8 unk_c4[0x38];
    void **unk_fc; // entry 4's handle
    char unk_100[0x20]; // entry 4's name
    char unk_120[0x18]; // entry 4's extension
} ActorRes;
SIZE_ASSERT(ActorRes, 0x138);

#endif
