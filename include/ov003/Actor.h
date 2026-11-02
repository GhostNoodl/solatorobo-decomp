#ifndef OV003_ACTOR_H
#define OV003_ACTOR_H

// The ov003 actor class (ctor func_ov003_021d0c1c, 0xf0 bytes): an ov000 Actor with the fields
// 0xac..0xef that the ov003 actor code sets up. The actor classes of ov009 and ov011..ov014
// derive from it; their own fields start at 0xf0. The ov003 sources still use their own local
// views of it, so they do not include this header.

#include "types.h"
#include "ov000/ActorBase.h"

// Spawn parameters of an ov003 actor (Ov003Actor::unk_b0).
struct Ov003Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

// The block at Ov003Actor::unk_d0 (allocated by the ov003 actor; holds two models at 0x68).
struct Ov003SubD0 {
    u8 unk_00[0x62];
    u16 target_id;
    u8 unk_64[0x4];
    void *unk_68[2];
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
    s32 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    // 0xd0..0xee as func_ov003_021d0c1c sets them.
    Ov003SubD0 *unk_d0;
    void *unk_d4;
    void *unk_d8;
    u16 unk_dc;
    u16 target_id;  // id of the actor this one tracks; 0xffff for none
    void *unk_e0;
    void *unk_e4;
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
            u16 unk_ea_11 : 3;
            u16 unk_ea_14 : 1;
            u16 unk_ea_15 : 1;
        };
    };
    u8 unk_ec_0 : 1;
    u8 unk_ec_1 : 1;
    u8 unk_ec_2 : 6;
    u8 unk_ed;
    u16 unk_ee_0 : 1;
    u16 unk_ee_1 : 1;
    u16 unk_ee_2 : 2;
    u16 unk_ee_4 : 1;
    u16 unk_ee_5 : 1;
    u16 unk_ee_6 : 1;
    u16 unk_ee_7 : 2;
    u16 unk_ee_9 : 7;
};
SIZE_ASSERT(Ov003Actor, 0xf0);

// The ov003 actor API (defined in src/ov003), declared once for the overlays.
// func_ov003_021d0edc keeps void *: the ActorEx-based classes call it too.
extern "C" {
void func_ov003_021d0c1c(Ov003Actor *self);
void *func_ov003_021d0edc(void *self);
void func_ov003_021d0fc0(Ov003Actor *self);
void func_ov003_021d112c(Ov003Actor *self);
u16 func_ov003_021d16cc(Ov003Actor *self);
void func_ov003_021d1b88(Ov003Actor *self);
void func_ov003_021d1e8c(Ov003Actor *self);
void func_ov003_021d2e28(Ov003Actor *self);
void func_ov003_021d3008(Ov003Actor *self);
void func_ov003_021d3524(Ov003Actor *self);
void func_ov003_021d3600(Ov003Actor *self);
void func_ov003_021d36fc(Ov003Actor *self);
void func_ov003_021d3a88(Ov003Actor *self);
void func_ov003_021d3d28(Ov003Actor *self);
void func_ov003_021d452c(Ov003Actor *self);
void func_ov003_021d4b68(Ov003Actor *self);
void func_ov003_021d4fd8(Ov003Actor *self);
void func_ov003_021d5348(Ov003Actor *self);
void func_ov003_021d5900(Ov003Actor *self);
void func_ov003_021d6054(Ov003Actor *self);
void func_ov003_021d64f0(Ov003Actor *self);
u8 func_ov003_021d6548(Ov003Actor *self, void *p);
void func_ov003_021d6868(Ov003Actor *self, s32 a);
void func_ov003_021d68e0(Ov003Actor *self, s32 a, s32 b, s32 c);
void func_ov003_021d6954(Ov003Actor *self, u8 a);
void func_ov003_021d6a3c(Ov003Actor *self, s32 a, s32 b, s32 c);
void func_ov003_021d6bac(Ov003Actor *self, const void *p);
BOOL func_ov003_021da03c(Ov003Actor *self);
void func_ov003_021da108(Ov003Actor *self, s32 a, s32 b, s32 c, s32 d);
void func_ov003_021da2c8(Ov003Actor *self, s32 a, s32 b, s32 c, s32 d);
void *func_ov003_021dae44(Ov003Actor *self);
}

#endif
