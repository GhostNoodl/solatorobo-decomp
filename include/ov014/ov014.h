#ifndef OV014_H
#define OV014_H

#include "types.h"
#include "nitro/std.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov014V {
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
// A resource name and its frame count (data_ov014_022173e0, defined in ov014_02216ff0.cpp).
struct Ov014Res { const char *name; u16 n; };

struct Ov014Flags {
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

struct Ov014Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct Ov014Vec16 {
    s16 x;
    s16 y;
    s16 z;
};

// Three u16 angles.
struct Ov014Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov014Vec {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov014_VecSet(Ov014Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov014_VecCopy(Ov014Vec *d, const Ov014Vec *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov014_VecCopyYZ(Ov014Vec *d, const Ov014Vec *s) {
    s32 y = s->y;
    s32 z = s->z;
    d->x = s->x;
    d->y = y;
    d->z = z;
}

static inline s32 Ov014_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

struct Ov014Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    Ov014Vec v;
};

// NitroSDK sin/cos table: s16 sin,cos pairs
extern "C" const s16 FX_SinCosTable_[];
#define OV014_SINCOS FX_SinCosTable_
#define OV014_SIN(a) (OV014_SINCOS[((a) >> 4) * 2])
#define OV014_COS(a) (OV014_SINCOS[((a) >> 4) * 2 + 1])

struct Ov014Sub38 {
    void *unk_00;
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov014Vec unk_78;
    u8 unk_84[0x24];
    Ov014Vec unk_a8;
    u8 unk_b4[0x2];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be;
    u8 unk_bf[0x2];
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 4;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 2;
    u16 unk_c2_8 : 1;
    u16 unk_c2_9 : 2;
    u16 unk_c2_11 : 5;
    s16 unk_c4;
    u8 unk_c6[0x1a];
    void *unk_e0;
    u8 unk_e4[0x4];
};

struct Ov014Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};

// Reads through a const view: MWCC does not merge these with an earlier plain read of the same field,
// so a state machine re-reads state/timer where the target does (instead of `volatile` casts).
static inline u16 Ov014Sub40_State(const Ov014Sub40 *s) {
    return s->state;
}

static inline u16 Ov014Sub40_Timer(const Ov014Sub40 *s) {
    return s->timer;
}

struct Ov014Sub44 {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
};

struct Ov014Sub48 {
    u8 unk_00[0x30];
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    Ov014Vec unk_68;
    u8 unk_74[0x26];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 10;
};

struct Ov014Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

// The ov000 Target object at Ov014Obj::unk_4c (Target_02199b00.c; Target_Get looks up
// the actor whose id is in target).
struct Ov014Target {
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
    Ov014Vec dest;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
};
SIZE_ASSERT(Ov014Target, 0x5c);

// One step of an Ov014Act_02209280 action script (8 bytes; the actor's step points at the current one).
struct Ov014Step {
    s16 kind;
    u16 time;
    u16 unk_04;
    u16 unk_06;
};

// The object base shared by the ov003 actor (Ov014Actor, built by func_ov003_021d0c1c) and the
// ov000 actor (Ov014ActorEx, built by ActorEx_Ctor): the fields below 0xac.
class Ov014Obj : public Ov014V {
public:
    u8 unk_04[0x8];
    u16 id;
    u16 kind;
    u8 unk_10[0x6];
    union {
        u8 unk_16; // read and written whole in func_ov014_022049e8
        struct {
            u8 flags_0 : 1;
            u8 flags_1 : 1;
            u8 flags_2 : 6;
        };
    };
    u8 unk_17;
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x2];
    u32 unk_24;
    u8 unk_28[0x8];
    u32 unk_30;
    u8 unk_34[0x4];
    Ov014Sub38 *unk_38;
    Ov014V *unk_3c;
    Ov014Sub40 *unk_40;
    Ov014Sub44 *unk_44;
    Ov014Sub48 *unk_48;
    Ov014Target *unk_4c;
    u16 *unk_50;
    u8 unk_54[0x8];
    void *unk_5c;
    void *unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov014Vec pos;
    u16 rot[3];
    u8 unk_82[0x2];
    Ov014Vec unk_84;
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
class Ov014Actor : public Ov014Obj {
public:
    u8 unk_ac[0x4];
    Ov014Param *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov014Vec unk_b8;
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
class Ov014ActorEx : public Ov014Obj {
public:
    u8 unk_ac[0x4];
    Ov014Param *unk_b0;
    void *unk_b4[2];
    void *unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    u8 unk_cc[0x4];
};

struct Ov014Names {
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

struct Ov014Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

class Ov014Multi : public Ov014Actor {
public:
    Ov014Sub38 models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    Ov014Vec unk_494;
};

struct Ov014Path {
    Ov014Vec start;
    Ov014Vec end;
};

struct Ov014Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
    u8 unk_ad[0x27];
    s32 unk_d4;
    u8 unk_d8[0xb4];
    u8 unk_18c;
    u8 unk_18d;
    u8 unk_18e;
    u8 unk_18f;
    union {
        u8 unk_190;
        struct {
            u8 unk_190_0 : 2;
            u8 unk_190_2 : 1;
            u8 unk_190_3 : 1;
            u8 unk_190_4 : 1;
            u8 unk_190_5 : 3;
        };
    };
};

extern "C" {
extern Ov014Game54 *data_ov000_021ccd54;
extern Ov014Heap *data_02097dd0;
}

static inline BOOL Ov014Game_IsBusy(Ov014Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov014Game_IsIdle(Ov014Game54 *g) {
    if (Ov014Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov014_GameIdle(void) {
    Ov014Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov014Game_IsIdle(g);
    }
    return TRUE;
}

extern "C" {
void Heap_Free(void *p);
void *Heap_Alloc(u32 size);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void *func_ov003_021d0edc(void *self);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
void VEC_MultAdd(s32 scale, const Ov014Vec *dir, const Ov014Vec *base, Ov014Vec *out);
s32 VEC_Distance(const Ov014Vec *a, const Ov014Vec *b);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_ov000_0219a2f4(Ov014Vec *v, s32 y, s32 b);
BOOL func_01ffc198(const Ov014Vec *pos, const Ov014Vec *target, s32 dist);
BOOL func_ov000_02191120(void *p);
void func_ov003_021d5348(Ov014Actor *self);
void func_ov003_021d3a88(Ov014Actor *self);
void func_ov003_021d5900(Ov014Actor *self);
void func_ov003_021d6054(Ov014Actor *self);
void func_ov003_021d0fc0(Ov014Actor *self);
void func_ov003_021d3524(Ov014Actor *self);
void func_ov003_021d3600(Ov014Actor *self);
void func_ov003_021d112c(Ov014Actor *self);
void func_ov003_021d1e8c(Ov014Actor *self);
void func_ov003_021d4b68(Ov014Actor *self);
u16 func_ov003_021d16cc(Ov014Actor *self);
void func_ov003_021d1b88(Ov014Actor *self);
void func_ov003_021d0c1c(Ov014Actor *self);
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
static inline void Ov014_FreeFx(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
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

static inline s32 *Ov014_NewFx(void) {
    s32 *p = (s32 *)Heap_Alloc(4);
    if (p != NULL) {
        *p = 0;
    }
    return p;
}

// Actor class of Ov014Act_021fa6a0_Ctor (vtable data_ov014_02217114).
class Ov014Act_021fa6a0 : public Ov014Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
    Ov014Vec unk_f8;
    Ov014Vec unk_104;
    Ov014Vec unk_110;
    s16 unk_11c;
    u8 unk_11e;
    u8 unk_11f;
    u32 unk_120;
    Ov014Names unk_124;
    u8 unk_228[0xac];
    Ov014Vec unk_2d4;
    u8 unk_2e0[0x24];
    s32 unk_304;
    s32 unk_308;
    s32 unk_30c;
    u8 unk_310[0x2];
    u16 unk_312;
    u16 unk_314;
    u16 unk_316;
    u16 unk_318;
    u8 unk_31a[0x4];
    Ov014Flags unk_31e;
    u8 unk_320[0x24];
    u8 *unk_344;
    u8 unk_348[0xc];
    u8 *unk_354;
    u8 unk_358[0xc];
    s16 unk_364;
    u8 unk_366[0x2];
};
SIZE_ASSERT(Ov014Act_021fa6a0, 0x368);

// Actor class of Ov014Act_021fd4d4_Ctor (vtable data_ov014_02217588).
class Ov014Act_021fd4d4 : public Ov014Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    s32 unk_f4;
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa[0x2];
    void *unk_fc;
    u8 unk_100[0x2c];
    Ov014Vec unk_12c;
    u8 unk_138;
    u8 unk_139;
    s16 unk_13a;
    u8 *unk_13c;
    u8 unk_140[0xc];
    u8 *unk_14c;
    void *unk_150;
    Ov014Actor *unk_154;
    u8 unk_158[0x4];
    u8 *unk_15c;
    u8 unk_160[0xc];
    u8 *unk_16c;
    void *unk_170;
    Ov014Actor *unk_174;
    u8 unk_178[0x4];
};
SIZE_ASSERT(Ov014Act_021fd4d4, 0x17c);

// Actor class of Ov014Act_0220011c_Ctor (vtable data_ov014_022174dc).
class Ov014Act_0220011c : public Ov014Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    u32 unk_f4;
    u8 unk_f8;
    u8 unk_f9;
    u16 unk_fa;
    u16 unk_fc;
    u8 unk_fe;
    u8 unk_ff;
    void *unk_100;
    u8 *unk_104;
    u8 unk_108[0xc];
    u8 *unk_114;
    u8 unk_118[0xc];
};
SIZE_ASSERT(Ov014Act_0220011c, 0x124);

// Actor class of Ov014Act_02201b94_Ctor (vtable data_ov014_02217430).
class Ov014Act_02201b94 : public Ov014Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    u32 unk_f4;
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa[0x2];
    void *unk_fc;
    u8 unk_100[0x2c];
    s16 unk_12c;
    u8 unk_12e;
    u8 unk_12f;
    s32 unk_130;
    u8 unk_134[0xc];
    u8 *unk_140;
    u8 unk_144[0xc];
    u16 unk_150;
    u8 unk_152;
    u8 unk_153;
    u8 unk_154[0x1ac];
    Ov014Vec unk_300;
    u8 unk_30c[0x24];
    s32 unk_330;
    s32 unk_334;
    s32 unk_338;
    u8 unk_33c[0xe];
    Ov014Flags unk_34a;
    u8 unk_34c[0x24];
};
SIZE_ASSERT(Ov014Act_02201b94, 0x370);

// Actor class of Ov014Act_0221267c_Ctor (vtable data_ov014_02217dc0).
class Ov014Act_0221267c : public Ov014Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x1f4];
    u8 unk_2e6;
    u8 unk_2e7[0x29];
    u16 unk_310;
    u16 unk_312;
    u8 unk_314[0x28];
    Ov014Vec unk_33c;
    s32 unk_348;
    u16 unk_34c;
    u8 unk_34e[0x2];
    s32 unk_350;
    u8 unk_354;
    u8 unk_355[0x3];
};
SIZE_ASSERT(Ov014Act_0221267c, 0x358);

// Actor class of Ov014Act_02209280_Ctor (vtable data_ov014_02217968).
class Ov014Act_02209280 : public Ov014Actor {
public:
    Ov014Step *step;
    u32 unk_f4;
    u16 unk_f8;
    u8 unk_fa[0x2];
    u8 unk_fc;
    u8 unk_fd[0x3];
    s32 unk_100;
    s32 unk_104;
    u8 unk_108[0x24];
    Ov014Vec unk_12c;
    s32 unk_138;
    u8 unk_13c[0x24];
    s32 unk_160;
    s32 unk_164;
    s32 unk_168;
    s32 unk_16c;
    u8 unk_170[0x24];
    s32 unk_194;
    s32 unk_198;
    s32 unk_19c;
    u16 unk_1a0;
    u16 unk_1a2;
    u8 unk_1a4;
    u8 unk_1a5;
    u8 unk_1a6[0x2];
    s32 unk_1a8;
    s32 unk_1ac;
    s32 unk_1b0;
    Ov014Vec unk_1b4;
    u8 unk_1c0;
    u8 unk_1c1[0xb];
    u8 *unk_1cc;
    void *unk_1d0;
    void *unk_1d4;
    u8 unk_1d8[0x4];
    void *unk_1dc;
    void *unk_1e0;
    s32 unk_1e4;
    s32 unk_1e8;
    s32 unk_1ec;
    s32 unk_1f0;
    u16 unk_1f4;
    u16 unk_1f6;
};
SIZE_ASSERT(Ov014Act_02209280, 0x1f8);

// Actor class of Ov014Act_0220f9d0_Ctor (vtable data_ov014_02217e6c).
class Ov014Act_0220f9d0 : public Ov014Actor {
public:
    u8 unk_f0[0x28];
    Ov014Vec unk_118;
    u8 unk_124;
    u8 unk_125[0xb];
    u8 *unk_130;
    void *unk_134;
    void *unk_138;
    u8 unk_13c[0x4];
    u8 *unk_140;
    s32 unk_144;
    u16 unk_148;
    u16 unk_14a;
    u16 unk_14c;
    u16 unk_14e;
    u16 unk_150;
    u8 unk_152[0x2];
    void *unk_154;
    void *unk_158;
    u8 unk_15c[0x2];
    s16 unk_15e;
    u8 unk_160[0xc];
    u8 unk_16c;
    u8 unk_16d[0x13];
    u8 unk_180;
    u8 unk_181[0x3];
};
SIZE_ASSERT(Ov014Act_0220f9d0, 0x184);

// Actor class of Ov014ActEx_02208618_Ctor (vtable data_ov014_02217708).
class Ov014ActEx_02208618 : public Ov014ActorEx {
public:
    u32 unk_d0;
    u8 unk_d4;
    u8 unk_d5[0x3];
    s32 *unk_d8;
};
SIZE_ASSERT(Ov014ActEx_02208618, 0xdc);

// Actor class of Ov014ActEx_0220d70c_Ctor (vtable data_ov014_02217bdc).
class Ov014ActEx_0220d70c : public Ov014ActorEx {
public:
    void *unk_d0;
    void *unk_d4;
    Ov014Vec16 unk_d8; // state durations, copied from the spawn data at 0x18
    u8 unk_de[0x2];
};
SIZE_ASSERT(Ov014ActEx_0220d70c, 0xe0);

// Actor class of Ov014ActEx_0220dcf4_Ctor (vtable data_ov014_02217b44).
class Ov014ActEx_0220dcf4 : public Ov014ActorEx {
public:
    void *unk_d0;
    u8 unk_d4;
    u8 unk_d5;
    s16 unk_d6;
    s16 unk_d8;
    s16 unk_da;
};
SIZE_ASSERT(Ov014ActEx_0220dcf4, 0xdc);

// Actor class of Ov014ActEx_021fbd64_Ctor (vtable data_ov014_022172c4).
class Ov014ActEx_021fbd64 : public Ov014ActorEx {
public:
    void *unk_d0;
};
SIZE_ASSERT(Ov014ActEx_021fbd64, 0xd4);

// Actor class of Ov014ActEx_021fc24c_Ctor (vtable data_ov014_0221722c).
class Ov014ActEx_021fc24c : public Ov014ActorEx {
public:
    Ov014Vec unk_d0;
    s32 unk_dc;
    s32 unk_e0;
    s32 unk_e4;
    Ov014Vec unk_e8;
    s32 unk_f4;
    u32 unk_f8;
    u8 unk_fc;
    u8 unk_fd;
    u8 unk_fe;
    u8 unk_ff;
    void *unk_100;
};
SIZE_ASSERT(Ov014ActEx_021fc24c, 0x104);

// Actor class of Ov014ActEx_02206c68_Ctor (vtable data_ov014_02217670).
class Ov014ActEx_02206c68 : public Ov014ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
    u16 unk_d8;
    u8 unk_da[0x2];
    void *unk_dc;
};
SIZE_ASSERT(Ov014ActEx_02206c68, 0xe0);

// Actor class of Ov014ActEx_0220774c_Ctor (vtable data_ov014_022177a0).
class Ov014ActEx_0220774c : public Ov014ActorEx {
public:
    u32 unk_d0;
    s32 unk_d4;
    void *unk_d8;
};
SIZE_ASSERT(Ov014ActEx_0220774c, 0xdc);

// Actor class of Ov014ActEx_0220eca0_Ctor (vtable data_ov014_02217aac).
class Ov014ActEx_0220eca0 : public Ov014ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
    Ov014Vec unk_d8;
    s32 unk_e4;
    s32 unk_e8;
    s32 unk_ec;
    s16 unk_f0;
    s16 unk_f2;
    s16 unk_f4;
    u8 unk_f6[0x2];
};
SIZE_ASSERT(Ov014ActEx_0220eca0, 0xf8);

// Actor class of Ov014ActEx_022142fc_Ctor (vtable data_ov014_02217fb0).
class Ov014ActEx_022142fc : public Ov014ActorEx {
public:
    Ov014Vec unk_d0;
    s32 unk_dc;
    s32 unk_e0;
};
SIZE_ASSERT(Ov014ActEx_022142fc, 0xe4);

// Actor class of Ov014ActEx_022152e8_Ctor (vtable data_ov014_02217f18).
class Ov014ActEx_022152e8 : public Ov014ActorEx {
public:
    Ov014Vec unk_d0;
    Ov014Vec unk_dc;
    s32 unk_e8;
    s32 unk_ec;
    u16 unk_f0;
    u8 unk_f2[0x2];
    s32 unk_f4;
};
SIZE_ASSERT(Ov014ActEx_022152e8, 0xf8);

// The ov000-factory classes with vtables data_ov014_022178d0 (0xe8 bytes, exactly this class) and
// data_ov014_02217838 (Ov014ActExVt_02217838): both scale in from 0 to the model's scale.
class Ov014ActExGrow : public Ov014ActorEx {
public:
    u32 flags;      // 0x1000: remove, 0x200000: hit
    Ov014Vec scale; // the model's scale, saved at start
    s32 cur_scale;
    u8 timer;
    u8 unk_e5[0x3];
};
SIZE_ASSERT(Ov014ActExGrow, 0xe8);

class Ov014ActExVt_02217838 : public Ov014ActExGrow {
public:
    void *fx; // handle of the effect spawned at full size
};
SIZE_ASSERT(Ov014ActExVt_02217838, 0xec);

#endif
