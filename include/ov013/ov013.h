#ifndef OV013_H
#define OV013_H

#include "types.h"
#include "nitro/std.h"
#include "nitro/fx.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Field.h"
#include "ov000/Actor.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov013V {
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

// Generic bitfield views
struct Ov013Flags {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 1;
    u16 b15 : 1;
};

struct Ov013Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

typedef VecFx32 Ov013Vec;

static inline void Ov013_VecSet(Ov013Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov013_VecCopy(Ov013Vec *d, const Ov013Vec *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov013_VecCopyYZ(Ov013Vec *d, const Ov013Vec *s) {
    s32 y = s->y;
    s32 z = s->z;
    d->x = s->x;
    d->y = y;
    d->z = z;
}

struct Ov013Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    Ov013Vec v;
};

#define OV013_SINCOS FX_SinCosTable_
#define OV013_SIN(a) (OV013_SINCOS[((a) >> 4) * 2])
#define OV013_COS(a) (OV013_SINCOS[((a) >> 4) * 2 + 1])

struct Ov013Sub38 {
    void *unk_00;
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov013Vec unk_78;
    u8 unk_84[0x24];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xa];
    u8 unk_be;
    u8 unk_bf[0x3];
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 4;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 2;
    u16 unk_c2_8 : 1;
    u16 unk_c2_9 : 2;
    u16 unk_c2_11 : 5;
    s16 unk_c4;
    u8 unk_c6[0x22];
};

struct Ov013Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};

// A read through a const view, which MWCC does not merge with an earlier plain read of the timer.
static inline u16 Ov013Sub40_Timer(const Ov013Sub40 *s) {
    return s->timer;
}

struct Ov013Sub44 {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
};

struct Ov013Sub48 {
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
    u8 unk_5c[0x4];
    s32 unk_60;
    u8 unk_64[0x4];
    Ov013Vec unk_68;
    u8 unk_74[0x26];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
    u16 unk_9a_7 : 9;
};

struct Ov013Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

class Ov013Actor;
// The ov000 Target object at Ov013Obj::unk_4c (Target_02199b00.c; Target_Get looks up
// the actor whose id is in target).
struct Ov013Target {
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
    Ov013Vec dest;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
};
SIZE_ASSERT(Ov013Target, 0x5c);

// The object base shared by the ov003 actor (Ov013Actor, built by func_ov003_021d0c1c) and the
// ov000 actor (Ov013ActorEx, built by ActorEx_Ctor): the fields below 0xac.
class Ov013Obj : public Ov013V {
public:
    u8 unk_04[0x4];
    Ov013Actor *unk_08;
    u16 id;
    u16 kind;
    u8 unk_10[0x4];
    u8 unk_14;
    u8 unk_15;
    Ov013Flags8 unk_16;
    u8 unk_17;
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0xe];
    u32 unk_30;
    u8 unk_34[0x4];
    Ov013Sub38 *unk_38;
    Ov013V *unk_3c;
    Ov013Sub40 *unk_40;
    Ov013Sub44 *unk_44;
    Ov013Sub48 *unk_48;
    Ov013Target *unk_4c;
    u16 *unk_50;
    u8 unk_54[0x8];
    void *unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov013Vec pos;
    u16 rot[3];
    u8 unk_82[0x2];
    Ov013Vec unk_84;
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_93_4 : 1;
    u8 unk_93_5 : 3;
    u8 unk_94_0 : 1;
    u8 unk_94_1 : 2;
    u8 unk_94_3 : 5;
    u8 unk_95;
    u16 unk_96;
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

// Common actor base (the ov003 actor class); subclass fields start at 0xf0.
class Ov013Actor : public Ov013Obj {
public:
    u8 unk_ac[0x4];
    Ov013Param *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov013Vec unk_b8;
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
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
    u16 unk_ea_6 : 2;
    u16 unk_ea_8 : 2;
    u16 unk_ea_10 : 1;
    u16 unk_ea_11 : 3;
    u16 unk_ea_14 : 1;
    u16 unk_ea_15 : 1;
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
class Ov013ActorEx : public Ov013Obj {
public:
    u8 unk_ac[0x4];
    Ov013Param *unk_b0;
    void *unk_b4[2];
    void *unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    u16 unk_cc;
    u16 unk_ce;
};

struct Ov013Names {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 unk_03_1 : 1;
    u8 unk_03_2 : 1;
    u8 unk_03_3 : 1;
    u8 unk_03_4 : 1;
    u8 unk_03_5 : 3;
    u8 unk_04[0xc];
    char unk_10[0x20];
    char unk_30[0x1c];
    char unk_4c[0x20];
    char unk_6c[0x58];
    char unk_c4[0x20];
    char unk_e4[0x20];
};

class Ov013Multi : public Ov013Actor {
public:
    Ov013Sub38 models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    Ov013Vec unk_494;
};

struct Ov013Path {
    Ov013Vec start;
    Ov013Vec end;
};

static inline BOOL Ov013Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov013Game_IsIdle(FieldState *g) {
    if (Ov013Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov013_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov013Game_IsIdle(g);
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
s32 func_ov000_0219a2f4(Ov013Vec *v, s32 y, s32 b);
BOOL func_ov000_02191120(void *p);
void func_ov003_021d5348(Ov013Actor *self);
void func_ov003_021d3a88(Ov013Actor *self);
void func_ov003_021d5900(Ov013Actor *self);
void func_ov003_021d6054(Ov013Actor *self);
void func_ov003_021d0fc0(Ov013Actor *self);
void func_ov003_021d3524(Ov013Actor *self);
void func_ov003_021d3600(Ov013Actor *self);
void func_ov003_021d112c(Ov013Actor *self);
void func_ov003_021d1e8c(Ov013Actor *self);
void func_ov003_021d4b68(Ov013Actor *self);
u16 func_ov003_021d16cc(Ov013Actor *self);
void func_ov003_021d1b88(Ov013Actor *self);
void func_ov003_021d0c1c(Ov013Actor *self);
char *func_0207011c(void *res);
char *func_020701d4(void *res);
u8 *func_02070558(void *res);
}
extern "C" {
void func_ov000_021953b4(void *self);
void func_ov003_021dacfc(void *p);
void *func_ov000_0219429c(void *self);
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *a, s32 b);
}

extern "C" void *func_ov003_021da940(void *p);

// Frees the effect handle at self+off with the default heap selected.
static inline void Ov013_FreeFx(void *self, u32 off) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (FLD(void *, self, off) != NULL) {
        void *p = FLD(void *, self, off);
        if (p != NULL) {
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline s32 *Ov013_NewFx(void) {
    s32 *p = (s32 *)Heap_Alloc(4);
    if (p != NULL) {
        *p = 0;
    }
    return p;
}

// Actor class of Ov013_DtorDc (vtable data_ov013_0220bbb8).
class Ov013ActEx_02204454 : public Ov013ActorEx {
public:
    u16 unk_d0;
    u16 unk_d2;
    u16 unk_d4;
    u8 unk_d6[0x2];
    void *unk_d8;
    Ov013Names *unk_dc;
    void *unk_e0;
    u8 unk_e4[0x18];
};
SIZE_ASSERT(Ov013ActEx_02204454, 0xfc);

// Actor class of Ov013ActEx_021fdb70_Ctor (vtable data_ov013_0220b738).
class Ov013ActEx_021fdb70 : public Ov013ActorEx {
public:
    s32 unk_d0;
    u8 unk_d4;
    u8 unk_d5[0x3];
};
SIZE_ASSERT(Ov013ActEx_021fdb70, 0xd8);

// Actor class of Ov013Act_021fea8c_Ctor (vtable data_ov013_0220b9a0).
class Ov013Act_021fea8c : public Ov013Actor {
public:
    Ov013Flags8 unk_f0;
    u8 unk_f1;
    u16 unk_f2;
    u16 unk_f4;
    u16 unk_f6;
    u16 unk_f8;
    u16 unk_fa;
    u16 unk_fc;
    u8 unk_fe[0x2];
    s32 unk_100;
    s32 unk_104;
    Ov013Vec unk_108;
    Ov013Vec unk_114;
    void *unk_120;
    void *unk_124;
    void *unk_128;
    u8 unk_12c[0x30];
    u8 unk_15c;
    u8 unk_15d;
    u8 unk_15e[0x2];
};
SIZE_ASSERT(Ov013Act_021fea8c, 0x160);

// Actor class of Ov013ActEx_02205ae4_Ctor (vtable data_ov013_0220ba88).
class Ov013ActEx_02205ae4 : public Ov013ActorEx {
public:
    u16 unk_d0;
    u16 unk_d2;
    Ov013Vec unk_d4;
    u8 unk_e0[0x10];
};
SIZE_ASSERT(Ov013ActEx_02205ae4, 0xf0);

// Actor class of Ov013ActEx_022065ac_Ctor (vtable data_ov013_0220bb20).
class Ov013ActEx_022065ac : public Ov013ActorEx {
public:
    u8 unk_d0[0x24];
    u8 unk_f4;
    u8 unk_f5;
    u16 unk_f6;
};
SIZE_ASSERT(Ov013ActEx_022065ac, 0xf8);

// Actor class of Ov013Act_02207968_Ctor (vtable data_ov013_0220bd2c).
class Ov013Act_02207968 : public Ov013Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    s32 unk_f4;
    Ov013Vec unk_f8;
    Ov013Vec unk_104;
    u8 unk_110;
    u8 unk_111;
    u8 unk_112[0x2];
};
SIZE_ASSERT(Ov013Act_02207968, 0x114);

// Actor class of Ov013ActEx_0220a4e0_Ctor (vtable data_ov013_0220bf4c).
class Ov013ActEx_0220a4e0 : public Ov013ActorEx {
public:
    s32 unk_d0;
    Ov013Vec unk_d4;
};
SIZE_ASSERT(Ov013ActEx_0220a4e0, 0xe0);

// Actor class of Ov013ActEx_0220a9a8_Ctor (vtable data_ov013_0220beb4).
class Ov013ActEx_0220a9a8 : public Ov013ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
};
SIZE_ASSERT(Ov013ActEx_0220a9a8, 0xd8);

// The ov000-factory class with vtable data_ov013_0220b7d0 (0xdc bytes).
class Ov013ActExVt_0220b7d0 : public Ov013ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
    s32 unk_d8;
};
SIZE_ASSERT(Ov013ActExVt_0220b7d0, 0xdc);

// Actor class with vtable data_ov013_0220b5e0 (built inline by the ov003 factory).
class Ov013ActVt_0220b5e0 : public Ov013Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
    u8 unk_f8;
    u8 unk_f9[0x3];
};
SIZE_ASSERT(Ov013ActVt_0220b5e0, 0xfc);

// Actor class with vtable data_ov013_0220bc80 (built inline by the ov003 factory).
class Ov013ActVt_0220bc80 : public Ov013Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
    Ov013Vec unk_f4;
    Ov013Vec unk_100;
};
SIZE_ASSERT(Ov013ActVt_0220bc80, 0x10c);

// Actor class with vtable data_ov013_0220bdd8 (built inline by the ov003 factory).
class Ov013ActVt_0220bdd8 : public Ov013Actor {
public:
    Ov013Vec unk_f0;
    u8 unk_fc;
    u8 unk_fd;
    u16 unk_fe;
};
SIZE_ASSERT(Ov013ActVt_0220bdd8, 0x100);

struct Ov013Pole {
    Ov013Vec v;
    u8 on;
    u8 pad[3];
};

// The ov003-factory class with vtable data_ov013_0220b68c (0x13c bytes).
class Ov013Boss : public Ov013Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u8 side;
    u8 unk_f3;
    u16 unk_f4;
    u8 unk_f6[2];
    s32 unk_f8;
    Ov013Pole poles[4];
};
SIZE_ASSERT(Ov013Boss, 0x13c);

#endif
