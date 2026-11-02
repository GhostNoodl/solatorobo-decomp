#ifndef OV003_ACTOR_H
#define OV003_ACTOR_H

// The ov003 actor class (ctor Ov003Actor_Ctor, 0xf0 bytes): an ov000 Actor with the fields
// 0xac..0xef that the ov003 actor code sets up. The actor classes of ov009 and ov011..ov014
// derive from it; their own fields start at 0xf0. The ov003 actor code (ctor, dtor, update,
// message, hit and spawn helpers) uses it directly; a few ov003 TUs still keep local views of
// sub-objects or of ov003 subclasses (see docs/MATCHING.md, round shB).

#include "types.h"
#include "ov000/ActorBase.h"

struct ActorEx;

// Spawn parameters of an ov003 actor (Ov003Actor::unk_b0).
struct Ov003Param {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a_0 : 3;
    u16 unk_0a_3 : 2;
    u16 unk_0a_5 : 1;
    u16 unk_0a_6 : 1;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 1;
    u16 unk_0a_11 : 1;
    u16 unk_0a_12 : 1;
    u16 unk_0a_13 : 1;
    u16 unk_0a_14 : 2;
    u16 unk_0c_0 : 5;
    u16 unk_0c_5 : 1;
    u16 unk_0c_6 : 10;
    u8 unk_0e[2];
    const char *unk_10[2];
};

// An entry of the ov003 actor table (0x10 bytes) that Ov003_LookupEntry looks up by id
// (Ov003Actor::unk_c4).
struct Ov003Entry {
    u8 idx : 4;
    u8 type : 3;
    u8 unk_00_7 : 1;
    u8 kind : 2;
    u8 unk_01_2 : 1;
    u8 unk_01_3 : 2;
    u8 unk_01_5 : 3; // initial Ov003Actor::unk_ea_0 when non-zero
    union {
        u8 unk_02;
        struct {
            u8 unk_02_0 : 1;
            u8 unk_02_1 : 7;
        };
    };
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    s16 unk_06;
    s16 unk_08;
    u16 unk_0a;
    s16 unk_0c;
    s16 unk_0e;
};

// The block at Ov003Actor::unk_d0 (0x70 bytes, allocated by the ov003 actor): two part models and
// their matrices.
struct Ov003SubD0 {
    MtxFx43 mtx[2];
    u8 idx[2];
    union {
        u16 unk_62[2];
        struct {
            u16 target_id;
            u16 unk_64;
        };
    };
    u8 unk_66[2];
    Model0218fe1c *models[2];
};

class Ov003Actor : public Actor {
public:
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae;
    u8 unk_af;
    Ov003Param *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    VecFx32 unk_b8;
    Ov003Entry *unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    // 0xd0..0xee as Ov003Actor_Ctor sets them.
    Ov003SubD0 *unk_d0;
    void *unk_d4;
    union {
        void *unk_d8;
        void (*nameFunc)(void *names, u16 kind); // fills Actor::unk_34 in place of Ov003Res_SetNames
    };
    u16 unk_dc;
    u16 target_id;  // id of the actor this one tracks; 0xffff for none
    u32 unk_e0; // effect ids (EffectObj::id), killed by the dtor
    u32 unk_e4;
    u16 unk_e8;
    union {
        u16 unk_ea; // or-ed whole by several ov009 members
        struct {
            u16 unk_ea_0 : 3;
            u16 unk_ea_3 : 3;
            u16 unk_ea_6 : 2;
            u16 unk_ea_8 : 1;
            u16 unk_ea_9 : 1;
            u16 unk_ea_10 : 1;
            u16 unk_ea_11 : 1;
            u16 unk_ea_12 : 1;
            u16 unk_ea_13 : 1;
            u16 unk_ea_14 : 1;
            u16 unk_ea_15 : 1;
        };
    };
    union {
        u8 unk_ec; // cleared whole by the ctor
        struct {
            u8 unk_ec_0 : 1;
            u8 unk_ec_1 : 1;
            u8 unk_ec_2 : 6;
        };
    };
    u8 unk_ed;
    union {
        u16 unk_ee; // cleared whole by the ctor
        struct {
            u16 unk_ee_0 : 1;
            u16 unk_ee_1 : 1;
            u16 unk_ee_2 : 2;
            u16 unk_ee_4 : 1;
            u16 unk_ee_5 : 1;
            u16 unk_ee_6 : 1;
            u16 unk_ee_7 : 2;
            u16 unk_ee_9 : 2;
            u16 unk_ee_11 : 1;
            u16 unk_ee_12 : 4;
        };
    };
};
SIZE_ASSERT(Ov003Actor, 0xf0);

// The ov003 actor API (defined in src/ov003), declared once for the overlays.
// Ov003Actor_DtorBase keeps void *: the overlay dtors that call it take void *self.
extern "C" {
Ov003Actor *Ov003Actor_Ctor(Ov003Actor *self);
Ov003Entry *Ov003_LookupEntry(u32 id);
void *Ov003Actor_DtorBase(void *self);
void Ov003Actor_Init(Ov003Actor *self);
void Ov003Actor_Start(Ov003Actor *self);
u16 Ov003Actor_Draw(Ov003Actor *self);
void Ov003Actor_Animate(Ov003Actor *self);
void Ov003Actor_Update(Ov003Actor *self);
void Ov003Actor_SelectState(Ov003Actor *self);
void Ov003Actor_RunState(Ov003Actor *self);
void Ov003Actor_StateIdle(Ov003Actor *self);
void Ov003Actor_StateMove(Ov003Actor *self);
void Ov003Actor_StateHeld(Ov003Actor *self);
void Ov003Actor_StateThrown(Ov003Actor *self);
void Ov003Actor_StateFly(Ov003Actor *self);
void Ov003Actor_StateAttack(Ov003Actor *self);
void Ov003Actor_StateShoot(Ov003Actor *self);
void Ov003Actor_StateHurt(Ov003Actor *self);
void Ov003Actor_StateKnockBack(Ov003Actor *self);
void Ov003Actor_StateDown(Ov003Actor *self);
void Ov003Actor_StateDie(Ov003Actor *self);
void Ov003Actor_State20(Ov003Actor *self);
u8 Ov003Actor_ApplyHit(Ov003Actor *self, ActorMsgHit *hit);
void Ov003Actor_SetColor(Ov003Actor *self, u16 color);
void Ov003Actor_FadeColor(Ov003Actor *self, u16 color, u16 color2, u16 frames);
void Ov003Actor_SetAlpha(Ov003Actor *self, u8 alpha);
Actor *Ov003Actor_SpawnAtSelf(Actor *self, s32 kind, s32 v);
Actor *Ov003Actor_SpawnChild(Ov003Actor *self, s32 kind, const VecFx32 *pos, const void *rot, Actor *other);
void Ov003Actor_Defeat(Ov003Actor *self, BOOL release, BOOL mark, BOOL sound);
void Ov003Actor_ScaleStats(Ov003Actor *self, const void *scale);
BOOL Ov003Actor_CanAct(Ov003Actor *self);
void Ov003Actor_SpawnScatterFx(Actor *self, s32 range, s32 fx, s32 base, s32 top);
void Ov003Actor_SetMotion(Actor *self, s32 speed, s32 velY, s32 friction, s32 gravity);
ActorEx *Ov003ActorEx_Ctor(ActorEx *self);
Actor *Ov003_SpawnById(u16 id);
}

#endif
