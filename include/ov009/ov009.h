#ifndef OV009_H
#define OV009_H

#include "types.h"
#include "nitro/std.h"

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

struct Ov009Vec {
    s32 x;
    s32 y;
    s32 z;
};

// 12-byte block: assigning one copies with ldm/stm (as Ov010Blk12 / Ov011Blk12)
struct Ov009Blk12 {
    s32 w[3];
};
#define OV009_BLKCPY(dst, src) (*(Ov009Blk12 *)(dst) = *(const Ov009Blk12 *)(src))

static inline s32 Ov009_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

// NitroSDK sin/cos table: s16 sin,cos pairs
extern "C" const s16 FX_SinCosTable_[];
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
    Ov009Vec unk_78;
    u8 unk_84[0x3e];
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 4;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 2;
    u16 unk_c2_8 : 1;
    u16 unk_c2_9 : 2;
    u16 unk_c2_11 : 5;
    u8 unk_c4[0x24];
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
    u8 unk_58[0x8];
    s32 unk_60;
    u8 unk_64[0x4];
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

// Common actor base (the ov003 actor class); subclass fields start at 0xf0.
class Ov009Actor : public Ov009V {
public:
    u8 unk_04[0x8];
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
    u8 unk_34[0x4];
    Ov009Sub38 *unk_38;
    Ov009V *unk_3c;
    Ov009Sub40 *unk_40;
    Ov009Sub44 *unk_44;
    Ov009Sub48 *unk_48;
    u8 unk_4c[0x4];
    u16 *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[0x8];
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
    u8 unk_ac[0x4];
    Ov009Param *unk_b0;
    u8 unk_b4[0x2];
    u16 unk_b6;
    Ov009Vec unk_b8;
    s32 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    u8 unk_d0[0x1a];
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

struct Ov009Names {
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

struct Ov009Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
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

struct Ov009Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x3c];
    s32 unk_d4;
};

extern "C" {
extern Ov009Game54 *data_ov000_021ccd54;
extern Ov009Heap *data_02097dd0;
}

static inline BOOL Ov009Game_IsBusy(Ov009Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov009Game_IsIdle(Ov009Game54 *g) {
    if (Ov009Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov009_GameIdle(void) {
    Ov009Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov009Game_IsIdle(g);
    }
    return TRUE;
}

extern "C" {
void func_0203de1c(void *p);
void *func_0203dd9c(u32 size);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void *func_ov003_021d0edc(void *self);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 func_02040528(s32 max);
s32 func_02040498(s32 max);
void VEC_MultAdd(s32 scale, const Ov009Vec *dir, const Ov009Vec *base, Ov009Vec *out);
s32 VEC_Distance(const Ov009Vec *a, const Ov009Vec *b);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_ov000_0219a2f4(Ov009Vec *v, s32 y, s32 b);
BOOL func_01ffc198(const Ov009Vec *pos, const Ov009Vec *target, s32 dist);
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

#endif
