#ifndef OV003_ACTEX_H
#define OV003_ACTEX_H

// ov003 actors of the ActorEx family (dtor func_ov000_0219429c) that keep members in place
// (round acC). The sizes and member offsets come from their allocations in func_ov000_02192b24,
// which constructs the members right after ActorEx_Ctor; the dtors destroy them in reverse order.
// The ov003 actors allocated with NEW_BASIC(0xd0, ...) are plain ActorEx objects.

#include "ov000/ObjLayouts.h"
#include "ov000/Model0218fe1c.h"

// A HitMesh embedded in an actor (0x98 bytes; its dtor Ov003HitMesh_Dtor detaches it with
// HitMesh_Detach).
typedef struct Ov003HitMesh {
    u8 unk_00[0x98];
} Ov003HitMesh;

// One ActorRes after the ActorEx part (vtables 021f8c28 and 021f89c8 are this size; 021f8a60
// (0x20c), 021f8768 (0x214) and 021f8638 (0x218) add fields after it).
class Ov003ActExRes : public ActorEx {
public:
    ActorRes res; // ctor func_ov000_0218e9c4, dtor func_ov000_0218ea20
};
SIZE_ASSERT(Ov003ActExRes, 0x208);

// An ActorRes and a model (vtables 021f9834, 021f979c and 021f9704; the dtors in
// ov003_021ebff8.cpp destroy both).
class Ov003ActExResMdl : public Ov003ActExRes {
public:
    Model0218fe1c mdl; // ctor func_ov000_0218fe1c, dtor func_ov000_0218fee4
};
SIZE_ASSERT(Ov003ActExResMdl, 0x2f0);

// Vtables 021f9834 (ov003_021eab10.cpp, ov003_021eae44.cpp) and 021f979c (ov003_021ebc38.cpp),
// 0x304 bytes. The model is drawn at homePos / homeRot, saved from pos and rot by Init.
class Ov003ActExHome : public Ov003ActExResMdl {
public:
    VecFx32 homePos;
    Rot16 homeRot;
    u16 unk_302; // 021f979c: frames, for the effect every 0x80
};
SIZE_ASSERT(Ov003ActExHome, 0x304);

// The state func_ov000_02197ee0 walks an actor with: a step, a timer and the point it heads to.
typedef struct Ov003AiState {
    u16 st;
    u16 timer;
    VecFx32 pos;
} Ov003AiState;

// Vtable 021f8898 (0xe0 bytes; func_ov000_02192b24 clears ai.st and ai.timer): an ActorEx that
// walks with func_ov000_02197ee0 and runs to ai.pos (ov003_021e0e8c.cpp).
class Ov003ActExWalk : public ActorEx {
public:
    Ov003AiState ai;
};
SIZE_ASSERT(Ov003ActExWalk, 0xe0);

// Vtable 021f9704 (ov003_021eae44.cpp, ov003_021eba54.cpp), 0x314 bytes; func_ov000_02192b24
// clears ai.st when it builds it. hasModel is set by Init when Actor::unk_1a is not 0: the actor
// then loads the resources and draws the model, rotated by rotOfs, which eases toward rotGoal.
class Ov003ActExSway : public Ov003ActExResMdl {
public:
    Rot16 rotOfs;
    Rot16 rotGoal;
    Ov003AiState ai;
    s32 unk_30c; // frames counted by Ov003ActExSway_StateHeld
    u8 hasModel;
};
SIZE_ASSERT(Ov003ActExSway, 0x314);

// A model after the ActorEx part (vtable 021f953c, ov003_021f7848.cpp): Draw draws mdl count
// times around pos, turnStep apart from turnAngle (which turns by turnSpeed each frame).
class Ov003ActExMdl : public ActorEx {
public:
    Model0218fe1c mdl;
    u8 count; // Actor::unk_18, 1..3
    u8 unk_1b9;
    u16 turnSpeed;
    u16 turnAngle;
    u16 turnStep; // 0x10000 / count
};
SIZE_ASSERT(Ov003ActExMdl, 0x1c0);

// Vtable 021f8af8: two ActorRes, a model and three HitMesh arrays (ov003_021e0e8c.cpp). Draw
// draws the model again at each copyPos with copyScale and copyAlpha (none while copyAlpha is 0);
// meshC[i] is linked only while meshCPos[i] is on the ground.
class Ov003ActExMesh : public ActorEx {
public:
    ActorRes res;
    ActorRes res2;
    Model0218fe1c mdl;
    VecFx32 copyPos[4];
    s32 copyScale[4];
    u8 copyAlpha[4];
    Ov003HitMesh meshA[4];
    Ov003HitMesh meshB[4];
    Ov003HitMesh meshC[3];
    VecFx32 meshCPos[3];
    u8 unk_b18; // Actor::unk_93_1 - 1
};
SIZE_ASSERT(Ov003ActExMesh, 0xb1c);

// Plain 0xd0-byte ActorEx objects (NEW_BASIC(0xd0, ...) in func_ov000_02192b24), named by the
// files that use them. Actor::unk_18 is the value func_ov000_02197d80 loads from the save and
// func_ov000_02197dec stores.
// - The lever (vtables 021f9ea8 and 021f9ce0): unk_93_1 is the position shown, unk_1c selects the
//   long sound and unk_ce counts its frames.
// - The switch (vtables 021f7fac and 021f7f14): unk_1a selects how it is driven, unk_93_1 is the
//   state last shown and unk_ce a delay before the target is tested again.
// - The bomb (vtable 021f8480): fsm->timer counts the fuse frames.
typedef ActorEx Ov003Lever;
typedef ActorEx Ov003Switch;
typedef ActorEx Ov003Bomb;

// An ActorEx with a looping sound (vtables 021f8350 and 021f83e8, 0xd4 bytes; ov003_021df370.cpp,
// ov003_021dec88.cpp): seq is the handle func_02049afc returns, stopped with SndMgr_StopSeqArc.
class Ov003ActExSeq : public ActorEx {
public:
    s32 seq;
};
SIZE_ASSERT(Ov003ActExSeq, 0xd4);

// The bridge (vtable 021f9e10, 0xd4 bytes; ov003_021eeb04.cpp, ov003_021eeecc.cpp). unk_18 is the
// saved value (func_ov000_02197d80); unk_93_1 is set while the bridge is down. Its model, built at the
// first start, sits at pos raised by unk_1c << 4; the hit sphere is made then too.
class Ov003Bridge : public ActorEx {
public:
    Model0218fe1c *anim;
};
SIZE_ASSERT(Ov003Bridge, 0xd4);

// The gimmick (vtable 021f99e8, ctor Ov003ActVt_021f99e8_Ctor, 0x214 bytes: NEW_CTOR in
// func_ov000_02192b24; ov003_021ec130.cpp, ov003_021ec9e0.cpp). Kinds 0x4064 and 0x4065.
// ActorEx::unk_ce_u is a counter (Ov003ActVt_021f99e8_StateDie counts it down) and unk_cf_u the state
// (1 once Ov003ActVt_021f99e8_StateDie has swapped the model; 0, 2, 3 follow the 0x4064 model's direction).
class Ov003Gimmick : public ActorEx {
public:
    Rot16 rotOfs; // added to rot for the 0x4064 effect
    u16 unk_d6; // frames until the 0x4064 effect starts again
    u8 vals[3]; // set by message 0xe (index, value)
    u8 unk_db;
    ActorRes res; // ctor func_ov000_0218e9c4
};
SIZE_ASSERT(Ov003Gimmick, 0x214);

extern "C" {
ActorEx *func_ov000_0219429c(ActorEx *self); // ActorEx dtor
ActorRes *func_ov000_0218ea20(ActorRes *self); // ActorRes dtor
Model0218fe1c *func_ov000_0218fee4(Model0218fe1c *self); // Model0218fe1c dtor
}

#endif
