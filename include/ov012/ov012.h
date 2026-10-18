#ifndef OV012_H
#define OV012_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov012V {
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
struct Ov012Flags {
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

struct Ov012Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct Ov012Vec {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov012_VecSet(Ov012Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov012_VecCopy(Ov012Vec *d, const Ov012Vec *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov012_VecCopyYZ(Ov012Vec *d, const Ov012Vec *s) {
    s32 y = s->y;
    s32 z = s->z;
    d->x = s->x;
    d->y = y;
    d->z = z;
}

static inline s32 Ov012_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

struct Ov012Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    Ov012Vec v;
};

// NitroSDK sin/cos table: s16 sin,cos pairs
extern "C" const s16 FX_SinCosTable_[];
#define OV012_SINCOS FX_SinCosTable_
#define OV012_SIN(a) (OV012_SINCOS[((a) >> 4) * 2])
#define OV012_COS(a) (OV012_SINCOS[((a) >> 4) * 2 + 1])

struct Ov012Sub38 {
    void *unk_00;
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov012Vec unk_78;
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

struct Ov012Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};

struct Ov012Sub44 {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
};

struct Ov012Sub48 {
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
    Ov012Vec unk_68;
    u8 unk_74[0x26];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 10;
};

struct Ov012Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

// Common actor base (the ov003 actor class); subclass fields start at 0xf0.
class Ov012Actor : public Ov012V {
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
    Ov012Sub38 *unk_38;
    Ov012V *unk_3c;
    Ov012Sub40 *unk_40;
    Ov012Sub44 *unk_44;
    Ov012Sub48 *unk_48;
    u8 unk_4c[0x4];
    u16 *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[0x8];
    Ov012Vec pos;
    u16 rot[3];
    u8 unk_82[0x2];
    Ov012Vec unk_84;
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
    Ov012Param *unk_b0;
    u8 unk_b4[0x2];
    u16 unk_b6;
    Ov012Vec unk_b8;
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

struct Ov012Names {
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

struct Ov012Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

class Ov012Multi : public Ov012Actor {
public:
    Ov012Sub38 models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    Ov012Vec unk_494;
};

struct Ov012Path {
    Ov012Vec start;
    Ov012Vec end;
};

struct Ov012Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x3c];
    s32 unk_d4;
};

extern "C" {
extern Ov012Game54 *data_ov000_021ccd54;
extern Ov012Heap *data_02097dd0;
}

static inline BOOL Ov012Game_IsBusy(Ov012Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov012Game_IsIdle(Ov012Game54 *g) {
    if (Ov012Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov012_GameIdle(void) {
    Ov012Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov012Game_IsIdle(g);
    }
    return TRUE;
}

extern "C" {
void func_0203de1c(void *p);
void *func_0203dd9c(u32 size);
void func_02009f64(void *arr, s32 count, u32 size, void *dtor);
void func_ov003_021d0edc(void *self);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 func_02040528(s32 max);
s32 func_02040498(s32 max);
void func_02012fb8(s32 scale, const Ov012Vec *dir, const Ov012Vec *base, Ov012Vec *out);
s32 func_02013068(const Ov012Vec *a, const Ov012Vec *b);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_ov000_0219a2f4(Ov012Vec *v, s32 y, s32 b);
BOOL func_01ffc198(const Ov012Vec *pos, const Ov012Vec *target, s32 dist);
BOOL func_ov000_02191120(void *p);
void func_ov003_021d5348(Ov012Actor *self);
void func_ov003_021d3a88(Ov012Actor *self);
void func_ov003_021d5900(Ov012Actor *self);
void func_ov003_021d6054(Ov012Actor *self);
void func_ov003_021d0fc0(Ov012Actor *self);
void func_ov003_021d3524(Ov012Actor *self);
void func_ov003_021d3600(Ov012Actor *self);
void func_ov003_021d112c(Ov012Actor *self);
void func_ov003_021d1e8c(Ov012Actor *self);
void func_ov003_021d4b68(Ov012Actor *self);
BOOL func_ov003_021d16cc(Ov012Actor *self);
void func_ov003_021d1b88(Ov012Actor *self);
void func_ov003_021d0c1c(Ov012Actor *self);
char *func_0207011c(void *res);
char *func_020701d4(void *res);
u8 *func_02070558(void *res);
void func_0201e520(char *dst, const char *src);
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
static inline void Ov012_FreeFx(void *self, u32 off) {
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

static inline s32 *Ov012_NewFx(void) {
    s32 *p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    return p;
}


extern "C" {
extern void *data_02097cdc;
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 data_ov012_0220aaf9[];
extern void func_ov000_0218e9c4(void *p);
extern void func_ov000_0218fe1c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void func_02049564(void *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern void func_020359d0(void *a, s32 b, s32 c);
extern BOOL func_ov000_0218cf5c(Ov012Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov000_021903b4(void *p);
extern s32 func_ov003_021d1c00(Ov012Actor *self, Ov012Msg *msg);
extern Ov012Actor *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_02012be8(void *a, const void *b, void *c);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov012Actor *self, const void *p);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
}

static inline void Ov012_StopSnd(void) {
    if (func_02035b90(data_ov012_0220aaf9, 7)) {
        func_02036838(data_02097cdc, data_ov012_0220aaf9, 7, 0);
    }
}


extern "C" {
extern void *data_ov000_021ccd68;
extern void func_0203f364(Ov012Sub48 *p);
extern Ov012Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void *func_ov000_0218e6d0(void *mgr, s32 a, s32 b);
extern void func_ov003_021daa6c(void *p, s32 a);
extern void func_ov003_021cf278(void *self, s32 a, s32 b);
extern void func_ov000_021984f4(void *p, s32 a, s32 b);
extern void func_ov000_0219864c(void *p, s32 a, s32 b);
extern void func_ov000_02196860(Ov012Actor *self);
extern void func_ov000_0219763c(Ov012Actor *self);
extern Ov012V *func_02065f88(s32 id, Ov012Vec *pos);
}

#define VCALL(p) ((Ov012V *)(p))


extern "C" {
extern void func_ov003_021ceedc(void *p);
extern void func_ov003_021cef0c(void *p);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL func_0204985c(void *a);
}


extern "C" {
extern void func_02049f44(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov003_021daab0(void *p);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(void *a, const void *b, s32 c, s32 d, s32 e, s32 f);
extern BOOL func_ov000_021946f8(void *self);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02194758(void *self);
}


extern "C" {
extern void *data_0214a420;
extern void *func_020657b0(void *a, void *b);
extern void func_ov000_02194074(void *self);
}


extern "C" {
extern void func_ov003_021d452c(void *self);
}


extern "C" {
extern void func_ov003_021d4fd8(void *self);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
}


extern "C" {
extern Ov012Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d46c(void *o, u16 id, s32 c);
}

static inline Ov012Actor *Ov012_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}


extern "C" {
extern void func_ov000_0218ddd4(void *self, Ov012Vec *v, s32 a);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern Ov012Actor *func_ov000_0218d240(void *self);
extern void func_ov000_0218d988(void *self, Ov012Actor *a, s32 b);
}


struct Ov012SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov012Spawn_Init(Ov012SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

struct Ov012Nib {
    u8 lo : 4;
    u8 hi : 4;
};

extern "C" {
extern Ov012Actor *func_ov000_0218bf1c(void *mgr, Ov012SpawnDesc *d, void *pos, void *rot, u16 a);
extern void func_ov000_02199b88(void *a, void *b);
extern BOOL func_ov003_021daa0c(void *p, s32 a);
extern void func_ov000_02190758(void *a, void *b, s32 c);
extern void func_ov000_02191c24(void *a, Ov012Vec *b);
extern BOOL func_ov000_02194c08(void *self);
}


struct Ov012VecC {
    s32 x;
    s32 y;
    s32 z;
    Ov012VecC() {}
    Ov012VecC(const Ov012VecC &o) : x(o.x), y(o.y), z(o.z) {}
};


extern "C" {
extern s32 func_ov000_0219a510(void *self, u16 mask, Ov012Vec *pos, s32 r, s32 a, void **list);
extern void *func_ov000_021985c0(void *p);
extern void func_ov003_021f0c60(void *self, s32 a);
extern void func_02049de8(void *a, s32 b);
extern void func_020639d4(void *e, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
}


extern "C" {
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
}

static inline void Ov012_ClearOwnerFlag(Ov012Actor *self) {
    Ov012Actor *o = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (o != NULL) {
        FLD(Ov012Flags8, o, 0xa2).b0 = 0;
    }
}


extern "C" {
extern void func_01ffc9fc(Ov012Vec *a, Ov012Vec *b, u16 ang);
extern void func_ov000_0219bebc(void *o, s16 a);
extern BOOL func_ov000_021b4738(void *o);
extern void func_ov000_0218d918(void *self, void *v, s32 a);
}


extern "C" {
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
}


static inline void *Ov012_FindRes(s32 a, s32 b) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e6d0(data_ov000_021ccd68, a, b);
}


struct Ov012Lift {
    u8 unk_00[0x394];
    Ov012Vec arr[2];
    u8 unk_3ac[2];
    u8 unk_3ae;
    u8 unk_3af;
};


extern "C" {
extern const u8 *const data_ov012_0220a3c4[];
extern const u8 *const data_ov012_0220a57c[];
}


extern "C" {
extern void func_02012d78(Ov012Vec *a, Ov012Vec *b);
extern u16 func_02013330(s32 a);
extern u16 func_0201319c(s32 a, s32 b);
extern void func_ov003_021da9ac(void *p, s32 a, void *e);
extern void *func_ov003_021daa3c(void *p, s32 a);
}


static inline void Ov012_ResetF0(Ov012Actor *self) {
    FLD(s32, self, 0x104) = 0;
    FLD(u32, self, 0xf0) = 1;
    FLD(u8, self, 0xf8) = 0;
}

static inline void Ov012Spawn_Set(Ov012SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {
extern Ov012Actor *func_ov000_02192b24(Ov012SpawnDesc *d);
extern void func_ov000_02182590(void *p);
extern void func_0203f324(Ov012Sub48 *p);
}


extern "C" {
extern void func_ov003_021d3d28(void *self);
}


extern "C" {
extern BOOL func_ov000_021983b0(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *p, s32 a, s32 b);
}


extern "C" {
extern s32 func_ov003_021d9edc(s32 kind);
}


#define OV012_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov012_Sqrt2(s64 sq) {
    OV012_SQRTCNT = 1;
    OV012_SQRT_PARAM = (u64)(sq << 2);
    while (OV012_SQRTCNT & 0x8000) {
    }
    return (s32)(OV012_SQRT_RESULT + 1) >> 1;
}

static inline s32 Ov012_DistXZ(const Ov012Vec *a, const Ov012Vec *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    return Ov012_Sqrt2((s64)dx * dx + (s64)dz * dz);
}

extern "C" {
extern Ov012Vec *func_ov000_0218d2e0(void *self);
}

#endif
