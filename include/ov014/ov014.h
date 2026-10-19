#ifndef OV014_H
#define OV014_H

#include "types.h"

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

struct Ov014Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};

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
    u8 unk_4c[0x4];
    u32 unk_50;
    u32 unk_54;
    u8 unk_58[0x8];
    s32 unk_60;
    u8 unk_64[0x4];
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

// Common actor base (the ov003 actor class); subclass fields start at 0xf0.
class Ov014Actor : public Ov014V {
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
    Ov014Sub38 *unk_38;
    Ov014V *unk_3c;
    Ov014Sub40 *unk_40;
    Ov014Sub44 *unk_44;
    Ov014Sub48 *unk_48;
    u8 unk_4c[0x4];
    u16 *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[0x8];
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
    u8 unk_ac[0x4];
    Ov014Param *unk_b0;
    u8 unk_b4[0x2];
    u16 unk_b6;
    Ov014Vec unk_b8;
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
    u8 unk_98[0x3c];
    s32 unk_d4;
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
void func_0203de1c(void *p);
void *func_0203dd9c(u32 size);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void func_ov003_021d0edc(void *self);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 func_02040528(s32 max);
s32 func_02040498(s32 max);
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
BOOL func_ov003_021d16cc(Ov014Actor *self);
void func_ov003_021d1b88(Ov014Actor *self);
void func_ov003_021d0c1c(Ov014Actor *self);
char *func_0207011c(void *res);
char *func_020701d4(void *res);
u8 *func_02070558(void *res);
void STD_CopyString(char *dst, const char *src);
}
extern "C" {
void func_ov000_021953b4(void *self);
void func_ov003_021dacfc(void *p);
void func_ov000_0219429c(void *self);
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *a, s32 b);
}

extern "C" void func_ov003_021da940(void *p);

// Frees the effect handle at self+off with the default heap selected.
static inline void Ov014_FreeFx(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        void *p = FLD(void *, self, off);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline s32 *Ov014_NewFx(void) {
    s32 *p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    return p;
}

#endif
