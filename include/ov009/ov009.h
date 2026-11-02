#ifndef OV009_H
#define OV009_H

#include "types.h"
#include "nitro/std.h"
#include "nitro/fx.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Field.h"
#include "ov000/Actor.h"

#define OV009_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov009V {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    virtual s32 v24(...);
    virtual s32 v28(...);
    virtual s32 v2c(...);
    virtual s32 v30(...);
    virtual s32 v34(...);
    virtual s32 v38(...);
    virtual s32 v3c(...);
    virtual s32 v40(...);
    virtual s32 v44(...);
    virtual s32 v48(...);
    virtual s32 v4c(...);
    virtual s32 v50(...);
    virtual s32 v54(...);
    virtual s32 v58(...);
    virtual s32 v5c(...);
    virtual s32 v60(...);
    virtual s32 v64(...);
    virtual s32 v68(...);
    virtual s32 v6c(...);
    virtual s32 v70(...);
    virtual s32 v74(...);
    virtual s32 v78(...);
    virtual s32 v7c(...);
    virtual s32 v80(...);
    virtual s32 v84(...);
    virtual s32 v88(...);
    virtual s32 v8c(...);
    virtual s32 v90(...);
    virtual s32 v94(...);
    virtual s32 v98(...);
    virtual s32 v9c(...);
    virtual s32 va0(...);
    virtual s32 va4(...);
    virtual s32 va8(...);
    virtual s32 vac(...);
    virtual s32 vb0(...);
    virtual s32 vb4(...);
    virtual s32 vb8(...);
    virtual s32 vbc(...);
    virtual s32 vc0(...);
    virtual s32 vc4(...);
    virtual s32 vc8(...);
    virtual s32 vcc(...);
    virtual s32 vd0(...);
    virtual s32 vd4(...);
    virtual s32 vd8(...);
    virtual s32 vdc(...);
    virtual s32 ve0(...);
    virtual s32 ve4(...);
    virtual s32 ve8(...);
    virtual s32 vec(...);
    virtual s32 vf0(...);
    virtual s32 vf4(...);
    virtual s32 vf8(...);
    virtual s32 vfc(...);
    virtual s32 v100(...);
    virtual s32 v104(...);
    virtual s32 v108(...);
    virtual s32 v10c(...);
    virtual s32 v110(...);
    virtual s32 v114(...);
    virtual s32 v118(...);
    virtual s32 v11c(...);
    virtual s32 v120(...);
    virtual s32 v124(...);
    virtual s32 v128(...);
    virtual s32 v12c(...);
    virtual s32 v130(...);
    virtual s32 v134(...);
    virtual s32 v138(...);
    virtual s32 v13c(...);
    virtual s32 v140(...);
    virtual s32 v144(...);
    virtual s32 v148(...);
    virtual s32 v14c(...);
    virtual s32 v150(...);
    virtual s32 v154(...);
    virtual s32 v158(...);
    virtual s32 v15c(...);
    virtual s32 v160(...);
    virtual s32 v164(...);
    virtual s32 v168(...);
    virtual s32 v16c(...);
    virtual s32 v170(...);
    virtual s32 v174(...);
    virtual s32 v178(...);
    virtual s32 v17c(...);
    virtual s32 v180(...);
    virtual s32 v184(...);
    virtual s32 v188(...);
    virtual s32 v18c(...);
    virtual s32 v190(...);
    virtual s32 v194(...);
    virtual s32 v198(...);
    virtual s32 v19c(...);
    virtual s32 v1a0(...);
    virtual s32 v1a4(...);
    virtual s32 v1a8(...);
    virtual s32 v1ac(...);
    virtual s32 v1b0(...);
    virtual s32 v1b4(...);
    virtual s32 v1b8(...);
    virtual s32 v1bc(...);
    virtual s32 v1c0(...);
    virtual s32 v1c4(...);
    virtual s32 v1c8(...);
    virtual s32 v1cc(...);
    virtual s32 v1d0(...);
    virtual s32 v1d4(...);
    virtual s32 v1d8(...);
    virtual s32 v1dc(...);
    virtual s32 v1e0(...);
    virtual s32 v1e4(...);
    virtual s32 v1e8(...);
    virtual s32 v1ec(...);
    virtual s32 v1f0(...);
    virtual s32 v1f4(...);
    virtual s32 v1f8(...);
    virtual s32 v1fc(...);
};

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

typedef VecFx32 Ov009Vec;

// 12-byte block: assigning one copies with ldm/stm (as Ov010Blk12 / Ov011Blk12)
struct Ov009Blk12 {
    s32 w[3];
};
#define OV009_BLKCPY(dst, src) (*(Ov009Blk12 *)(dst) = *(const Ov009Blk12 *)(src))

#define OV009_SINCOS FX_SinCosTable_
#define OV009_SIN(a) (OV009_SINCOS[((a) >> 4) * 2])
#define OV009_COS(a) (OV009_SINCOS[((a) >> 4) * 2 + 1])

// View of the Main EffectObj (Main/Effect/Effect.h) with its real virtual
// signatures, for the objects returned by func_02065f88, using ov009's vector
// type. vf0c takes one argument at these call sites.
class Ov009Eff {
public:
    virtual void Dtor();
    virtual void Delete();
    virtual void SetParam(s32 param);
    virtual void vf0c(s32 v);
    virtual void SetScale(const Ov009Vec *scale);
    virtual void SetScaleXYZ(s32 x, s32 y, s32 z);
    virtual void SetPos(const Ov009Vec *pos);
    virtual void SetPosXYZ(s32 x, s32 y, s32 z);
    virtual void AddPos(const Ov009Vec *delta);
    virtual void AddPosXYZ(s32 x, s32 y, s32 z);
    virtual void vf28();
    virtual void vf2c();
    virtual void SetRot(const void *rot);
    virtual void SetRotXYZ(u16 x, u16 y, u16 z);
};

struct Ov009Sub38 {
    void *unk_00;
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov009Vec unk_78; // position
    u8 unk_84[0x24];
    Ov009Vec scale;
    u16 unk_b4;
    u8 unk_b6[0x8];
    u8 alpha;
    u8 unk_bf[0x3];
    union {
        u16 unk_c2; // or-ed whole in Ov009ActVt_02217844_Start
        struct {
            u16 unk_c2_0 : 1;
            u16 unk_c2_1 : 4;
            u16 unk_c2_5 : 1;
            u16 unk_c2_6 : 2;
            u16 unk_c2_8 : 1;
            u16 unk_c2_9 : 2;
            u16 unk_c2_11 : 5;
        };
    };
    s16 anim_state;
    u8 unk_c6[0x1e];
    u32 unk_e4;
};

struct Ov009Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};

// A read through a const view, which MWCC does not merge with an earlier plain read of the state.
static inline u16 Ov009Sub40_State(const Ov009Sub40 *s) {
    return s->state;
}

// Two bytes of the unk_50 block (at +8).
typedef struct Ov009Pair {
    u8 a;
    u8 b;
} Ov009Pair;

// Sets b by copying the pair out and back, so a is reloaded and stored again as well.
static inline void Ov009Pair_SetB(Ov009Pair *p, u8 b) {
    Ov009Pair v;
    v = *p;
    v.b = b;
    *p = v;
}

struct Ov009Sub44 {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 2;
    u16 unk_22_4 : 12;
};

struct Ov009Sub48 {
    u8 unk_00[0x30];
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    u8 unk_4c[0x4];
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    Ov009Vec unk_68;
    u8 unk_74[0x26];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 10;
};

struct Ov009Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

// The ov000 Target object at Ov009Obj::unk_4c (Target_02199b00.c; Target_Get looks up
// the actor whose id is in target).
struct Ov009Target {
    u8 type;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u8 unk_0c[0x4];
    u16 kinds[2];
    u16 ids[2];
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 target;
    u16 unk_1e;
    u8 unk_20[0x24];
    Ov009Vec dest;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
};
SIZE_ASSERT(Ov009Target, 0x5c);

// The object base shared by the ov003 actor (Ov009Actor, built by func_ov003_021d0c1c) and the
// ov000 actor (Ov009ActorEx, built by ActorEx_Ctor): the fields below 0xac.
class Ov009Obj : public Ov009V {
public:
    void *unk_04;
    u32 unk_08;
    u16 id;
    u16 kind;
    u8 unk_10[0x8];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0xe];
    u32 unk_30;
    u8 *unk_34;
    Ov009Sub38 *unk_38;
    Ov009V *unk_3c;
    Ov009Sub40 *unk_40;
    Ov009Sub44 *unk_44;
    Ov009Sub48 *unk_48;
    Ov009Target *unk_4c;
    u16 *unk_50;
    u8 unk_54[0x4];
    void *unk_58;
    u8 unk_5c[0x4];
    void *unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov009Vec pos;
    u16 rot[3];
    u8 unk_82[0x2];
    Ov009Vec unk_84;
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_93_4 : 1;
    u8 unk_93_5 : 3;
    u8 unk_94_0 : 1;
    u8 unk_94_1 : 2;
    u8 unk_94_3 : 5;
    u8 unk_95[0x3];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

// Common actor base (the ov003 actor class); subclass fields start at 0xf0.
class Ov009Actor : public Ov009Obj {
public:
    u8 unk_ac[0x2];
    u8 unk_ae;
    u8 unk_af;
    Ov009Param *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov009Vec unk_b8;
    s32 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    // 0xd0..0xee as func_ov003_021d0c1c sets them.
    void *unk_d0;
    void *unk_d4;
    void *unk_d8;
    u16 unk_dc;
    u16 target_id;  // id of the actor this one tracks; 0xffff for none
    void *unk_e0;
    void *unk_e4;
    u16 unk_e8;
    union {
        u16 unk_ea; // or-ed whole by several members
        struct {
        u16 unk_ea_0 : 3;
        u16 unk_ea_3 : 3;
        u16 unk_ea_6 : 2;
        u16 unk_ea_8 : 2;
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

// The ov000 actor base (ActorEx_Ctor): 0xd0 bytes, with its own fields from 0xac.
class Ov009ActorEx : public Ov009Obj {
public:
    u8 unk_ac[0x4];
    Ov009Param *unk_b0;
    void *unk_b4[2];
    void *unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    u8 unk_cc[0x2];
    u16 unk_ce;
};

// The 0x138-byte animation object (func_ov000_0218e9c4); unk_00 is negative until it is ready.
struct Ov009Names {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 ownMdl : 1;
    u8 ownAnm : 1;
    u8 unk_03_3 : 1;
    u8 ownEv : 1;
    u8 unk_03_5 : 3;
    u8 unk_04[0xc];
    char mdlDir[0x20];
    char mdlName[0x1c];
    char anmDir[0x20];
    char anmName[0x58];
    char evDir[0x20];
    char evName[0x20];
    u8 unk_104[0x34];
};

class Ov009Multi : public Ov009Actor {
public:
    Ov009Sub38 models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    Ov009Vec unk_494;
};

struct Ov009Path {
    Ov009Vec start;
    Ov009Vec end;
};


static inline BOOL Ov009Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov009Game_IsIdle(FieldState *g) {
    if (Ov009Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov009_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov009Game_IsIdle(g);
    }
    return TRUE;
}

extern "C" {
void *Heap_Alloc(u32 size); // Main/Gfx/ObjPool.h
void Heap_Free(void *ptr);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void *func_ov003_021d0edc(void *self);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_021915a0(void *a);
s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_ov000_0219a2f4(Ov009Vec *v, s32 y, s32 b);
BOOL func_ov000_02191120(void *p);
void func_ov003_021d5348(Ov009Actor *self);
void func_ov003_021d3a88(Ov009Actor *self);
void func_ov003_021d5900(Ov009Actor *self);
void func_ov003_021d6054(Ov009Actor *self);
void func_ov003_021d0fc0(Ov009Actor *self);
void func_ov003_021d3524(Ov009Actor *self);
void func_ov003_021d3600(Ov009Actor *self);
void func_ov003_021d112c(Ov009Actor *self);
void func_ov003_021d1e8c(Ov009Actor *self);
void func_ov003_021d4b68(Ov009Actor *self);
u16 func_ov003_021d16cc(Ov009Actor *self);
void func_ov003_021d1b88(Ov009Actor *self);
void func_ov003_021d0c1c(Ov009Actor *self);
char *func_0207011c(void *res);
char *func_020701d4(void *res);
u8 *func_02070558(void *res);
}

// Actor class of Ov009Act_02200b48_Ctor (vtable data_ov009_02216d20).
class Ov009Act_02200b48 : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u16 unk_f6;
    u8 unk_f8[0x4];
    u8 unk_fc;
    u8 unk_fd[0x23];
    Ov009Vec unk_120;
};
SIZE_ASSERT(Ov009Act_02200b48, 0x12c);

// Actor class of Ov009Act_02202788_Ctor (vtable data_ov009_02216e78).
class Ov009Act_02202788 : public Ov009Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
    s32 unk_f4;
    u8 unk_f8[0x4];
    u8 unk_fc;
    u8 unk_fd[0x23];
    Ov009Vec unk_120;
};
SIZE_ASSERT(Ov009Act_02202788, 0x12c);

// Actor class with vtable data_ov009_022163f4 (built inline by the ov003 factory).
class Ov009ActVt_022163f4 : public Ov009Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
};
SIZE_ASSERT(Ov009ActVt_022163f4, 0xf8);

// Actor class with vtable data_ov009_022164a0 (built inline by the ov003 factory).
class Ov009ActVt_022164a0 : public Ov009Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
};
SIZE_ASSERT(Ov009ActVt_022164a0, 0xf4);

// Actor class with vtable data_ov009_022165f8 (built inline by the ov003 factory).
class Ov009ActVt_022165f8 : public Ov009Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6[0x2];
    s32 unk_f8;
};
SIZE_ASSERT(Ov009ActVt_022165f8, 0xfc);

// Actor class with vtable data_ov009_022166a4 (built inline by the ov003 factory).
class Ov009ActVt_022166a4 : public Ov009Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
    Ov009Vec unk_f4;
    Ov009Vec unk_100;
};
SIZE_ASSERT(Ov009ActVt_022166a4, 0x10c);

// Actor class with vtable data_ov009_02216750 (built inline by the ov003 factory).
class Ov009ActVt_02216750 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
    Ov009Vec unk_fc;
};
SIZE_ASSERT(Ov009ActVt_02216750, 0x108);

// Actor class with vtable data_ov009_02216a00 (built inline by the ov003 factory).
class Ov009ActVt_02216a00 : public Ov009Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
};
SIZE_ASSERT(Ov009ActVt_02216a00, 0xf4);

// Actor class with vtable data_ov009_02216bc8 (built inline by the ov003 factory).
class Ov009ActVt_02216bc8 : public Ov009Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u16 unk_f4;
    u16 unk_f6;
    s32 unk_f8;
    s32 unk_fc;
    Ov009Vec unk_100;
    u8 unk_10c[0x3c];
};
SIZE_ASSERT(Ov009ActVt_02216bc8, 0x148);

// Actor class with vtable data_ov009_02216dcc (built inline by the ov003 factory).
class Ov009ActVt_02216dcc : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6;
    u8 unk_f7;
};
SIZE_ASSERT(Ov009ActVt_02216dcc, 0xf8);

// Actor class with vtable data_ov009_02217128 (built inline by the ov003 factory).
class Ov009ActVt_02217128 : public Ov009Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
    Ov009Vec unk_f8;
    Ov009Vec unk_104;
};
SIZE_ASSERT(Ov009ActVt_02217128, 0x110);

// Actor class with vtable data_ov009_022171d4 (built inline by the ov003 factory).
class Ov009ActVt_022171d4 : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6[0x2];
    Ov009Vec unk_f8;
};
SIZE_ASSERT(Ov009ActVt_022171d4, 0x104);

// Actor class with vtable data_ov009_022172e4 (built inline by the ov003 factory).
class Ov009ActVt_022172e4 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
    u16 unk_fc;
    u16 unk_fe;
};
SIZE_ASSERT(Ov009ActVt_022172e4, 0x100);

// Actor class with vtable data_ov009_02217390 (built inline by the ov003 factory).
class Ov009ActVt_02217390 : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6[0x2];
    Ov009Vec unk_f8;
};
SIZE_ASSERT(Ov009ActVt_02217390, 0x104);

// Actor class with vtable data_ov009_02217640 (built inline by the ov003 factory).
class Ov009ActVt_02217640 : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6;
    u8 unk_f7;
    s32 unk_f8;
    Ov009Vec unk_fc;
    Ov009Vec unk_108;
};
SIZE_ASSERT(Ov009ActVt_02217640, 0x114);

// Actor class with vtable data_ov009_022176ec (built inline by the ov003 factory).
class Ov009ActVt_022176ec : public Ov009Actor {
public:
    Ov009Vec unk_f0;
};
SIZE_ASSERT(Ov009ActVt_022176ec, 0xfc);

// Actor class with vtable data_ov009_022178f0 (built inline by the ov003 factory).
class Ov009ActVt_022178f0 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
    Ov009Vec unk_fc;
    u16 unk_108;
    u16 unk_10a;
    s32 unk_10c;
};
SIZE_ASSERT(Ov009ActVt_022178f0, 0x110);

// Actor class with vtable data_ov009_02217a00 (built inline by the ov003 factory).
// The 0x140 layout shared by the classes with vtables 02217a00 and 02217d5c,
// which also share their member functions (func_ov009_02211e6c, 02211f9c, 0221268c, 022127f8).
class Ov009ActSpin : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2; // angle
    s32 unk_f4; // from func_ov000_021909a8; the model's unk_50 points here
    u8 unk_f8;
    u8 unk_f9[0x23];
    Ov009Vec unk_11c;
    Ov009Vec unk_128;
    Ov009Vec unk_134; // pos at setup; func_ov009_0221268c bobs around it
};
OV009_SIZE(Ov009ActSpin, 0x140);

class Ov009ActVt_02217a00 : public Ov009ActSpin {
};
SIZE_ASSERT(Ov009ActVt_02217a00, 0x140);

// Actor class with vtable data_ov009_02217aac (built inline by the ov003 factory).
class Ov009ActVt_02217aac : public Ov009Actor {
public:
    Ov009Vec unk_f0;
    u8 unk_fc;
    u8 unk_fd;
    u8 unk_fe;
    u8 unk_ff;
    void *unk_100;
    void *unk_104;
};
SIZE_ASSERT(Ov009ActVt_02217aac, 0x108);

// Actor class with vtable data_ov009_02217b58 (built inline by the ov003 factory).
// The 0x110 layout shared by the classes with vtables 02217b58 and 02217f60,
// which also share func_ov009_0220d2d8 and func_ov009_0220d5f8.
class Ov009ActPair110 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
    Ov009Vec unk_fc;
    u8 unk_108;
    u8 unk_109[0x3];
    s32 unk_10c;
};
OV009_SIZE(Ov009ActPair110, 0x110);

class Ov009ActVt_02217b58 : public Ov009ActPair110 {
};
SIZE_ASSERT(Ov009ActVt_02217b58, 0x110);

// Actor class with vtable data_ov009_02217c04 (built inline by the ov003 factory).
class Ov009ActVt_02217c04 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02217c04, 0xfc);

// Actor class with vtable data_ov009_02217cb0 (built inline by the ov003 factory).
class Ov009ActVt_02217cb0 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02217cb0, 0xfc);

// Actor class with vtable data_ov009_02217d5c (built inline by the ov003 factory).
class Ov009ActVt_02217d5c : public Ov009ActSpin {
};
SIZE_ASSERT(Ov009ActVt_02217d5c, 0x140);

// Actor class with vtable data_ov009_02217e08 (built inline by the ov003 factory).
class Ov009ActVt_02217e08 : public Ov009Actor {
public:
    s32 unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02217e08, 0xf4);

// Actor class with vtable data_ov009_02217eb4 (built inline by the ov003 factory).
class Ov009ActVt_02217eb4 : public Ov009Actor {
public:
    Ov009Vec unk_f0;
    Ov009Vec unk_fc;
    u8 unk_108;
    u8 unk_109;
    u8 unk_10a[0x2];
};
SIZE_ASSERT(Ov009ActVt_02217eb4, 0x10c);

// Actor class with vtable data_ov009_02217f60 (built inline by the ov003 factory).
class Ov009ActVt_02217f60 : public Ov009ActPair110 {
};
SIZE_ASSERT(Ov009ActVt_02217f60, 0x110);

// Actor class with vtable data_ov009_0221802c (built inline by the ov003 factory).
class Ov009ActExVt_0221802c : public Ov009ActorEx {
public:
    u32 unk_d0;
    u8 unk_d4;
    u8 unk_d5[0x3];
    s32 unk_d8;
};
SIZE_ASSERT(Ov009ActExVt_0221802c, 0xdc);

// Actor class with vtable data_ov009_022181f4 (built inline by the ov003 factory).
class Ov009ActExVt_022181f4 : public Ov009ActorEx {
public:
    u16 unk_d0;
    u16 unk_d2;
};
SIZE_ASSERT(Ov009ActExVt_022181f4, 0xd4);

// Actor class with vtable data_ov009_0221828c (built inline by the ov003 factory).
class Ov009ActExVt_0221828c : public Ov009ActorEx {
public:
    u16 unk_d0;
    u16 unk_d2;
};
SIZE_ASSERT(Ov009ActExVt_0221828c, 0xd4);

// Actor class with vtable data_ov009_02216348 (built inline by the ov003 factory).
class Ov009ActVt_02216348 : public Ov009Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
};
SIZE_ASSERT(Ov009ActVt_02216348, 0xf4);

// Actor class with vtable data_ov009_02216c74 (built inline by the ov003 factory).
class Ov009ActVt_02216c74 : public Ov009Actor {
public:
    void *unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02216c74, 0xf4);

// Actor class with vtable data_ov009_0221707c (built inline by the ov003 factory, which clears unk_104).
class Ov009ActVt_0221707c : public Ov009Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u8 unk_f4;
    s8 unk_f5;
    u8 unk_f6[0x2];
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    void *unk_104;
    s32 unk_108;
};

// An actor holding one animation and one model (factory 0x5414 and 0x31c class).
class Ov009ActModel : public Ov009Actor {
public:
    Ov009Names anim;
    Ov009Sub38 model;
};
OV009_SIZE(Ov009ActModel, 0x310);
OV009_SIZE(Ov009Sub38, 0xe8);
OV009_SIZE(Ov009Names, 0x138);

// Actor class with vtable 02217844 (built inline by the ov003 factory, 0x5414).
class Ov009ActVt_02217844 : public Ov009ActModel {
};

// Actor class with vtable 02217594 (built inline by the ov003 factory).
class Ov009ActVt_02217594 : public Ov009ActModel {
public:
    u16 step;
    u8 unk_312;
    u8 unk_313;
    s32 unk_314; // effect handle (func_020657b0)
    u8 unk_318;
    u8 unk_319[0x3];
};
OV009_SIZE(Ov009ActVt_02217594, 0x31c);
SIZE_ASSERT(Ov009ActVt_0221707c, 0x10c);

#endif
