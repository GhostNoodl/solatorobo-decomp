#ifndef OV011_H
#define OV011_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov011V {
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
struct Ov011Flags {
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

struct Ov011Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct Ov011Vec {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov011_VecSet(Ov011Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// 12-byte block: assigning one copies with ldm/stm
struct Ov011Blk12 {
    s32 w[3];
};
#define OV011_BLKCPY(dst, src) (*(Ov011Blk12 *)(dst) = *(const Ov011Blk12 *)(src))

static inline s32 Ov011_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

// NitroSDK sin/cos table: s16 sin,cos pairs
extern "C" const s16 FX_SinCosTable_[];
#define OV011_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV011_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

struct Ov011Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov011Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

extern "C" {
extern Ov011Game54 *data_ov000_021ccd54;
extern Ov011Heap *data_02097dd0;
extern void *data_ov000_021ccd68;
void func_0203de1c(void *p);
void *func_0203dd9c(u32 size);
void func_0203de50(void *p);
void *func_0203dddc(u32 size);
void func_02009f64(void *arr, s32 count, u32 size, void *dtor);
void *func_ov000_0218e640(void *mgr, u16 id);
void *func_ov000_0219bf90(void);
void func_ov003_021da40c(void *p);
void func_ov003_021da48c(void *p, s32 a);
}

static inline BOOL Ov011Game_IsBusy(Ov011Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov011Game_IsIdle(Ov011Game54 *g) {
    if (Ov011Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov011_GameIdle(void) {
    Ov011Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov011Game_IsIdle(g);
    }
    return TRUE;
}

static inline void *Ov011_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

struct Ov011Node {
    u16 id;
    u8 unk_02[0x2];
    Ov011Node *next;
};

struct Ov011LNode {
    u8 unk_00[0xc];
    Ov011LNode *next;
};

struct Ov011PNode {
    Ov011Vec v;
    Ov011PNode *next;
};

struct Ov011Ent {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
    u8 unk_01[0x3];
    Ov011PNode *unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20[0x4];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u16 unk_30;
    u8 unk_32[0x2];
    s32 unk_34;
};

static inline BOOL Ov011_ActorValid(u16 id) {
    void *a;
    void *pl;
    a = Ov011_FindActor(id);
    if (a == NULL) {
        return FALSE;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return FALSE;
    }
    if (FLD(u16, pl, 0xb1c) == FLD(u16, a, 0xc)) {
        return FALSE;
    }
    if (!(FLD(u32, FLD(void *, a, 0x48), 0x50) & 0x20000000)) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov011_NodeValid(Ov011Node *n) {
    BOOL r = FALSE;
    if (n != NULL) {
        r = Ov011_ActorValid(n->id);
    }
    return r;
}

struct Ov011E38 : public Ov011V {
    u8 unk_04[0x34];
};

struct Ov011E30 : public Ov011V {
    u8 unk_04[0x2c];
};

struct Ov011List {
    u8 unk_00[0x8];
    void *actor;
    Ov011Node *head;
};

static inline void Ov011_SetLerp(s32 *p, s32 from, s32 to, s32 frames) {
    p[1] = to;
    p[0] = from;
    p[2] = (to - p[0]) / frames;
}

static inline Ov011PNode *Ov011_PushNode(Ov011PNode *head, Ov011PNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

struct Ov011Tw {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s32 unk_04;
    Ov011Vec v08;
    Ov011Vec v14;
    Ov011Vec v20;
};

struct Ov011TwObj {
    Ov011V *vt;
    Ov011Tw tw;
};

struct Ov011Model2 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    void *model;
    u8 m0c[0x30];
    u8 m3c[0x24];
};

#define OV011_TWV(p) ((Ov011V *)(p))
#define OV011_TW(p) ((Ov011Tw *)((u8 *)(p) + 4))

struct Ov011Sub38 {
    void *unk_00;
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov011Vec unk_78;
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

struct Ov011Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};

struct Ov011Sub44 {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
};

struct Ov011Sub48 {
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
    Ov011Vec unk_68;
    u8 unk_74[0x26];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 10;
};

struct Ov011Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

// Common actor base (the ov003 actor class); subclass fields start at 0xf0.
class Ov011Actor : public Ov011V {
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
    Ov011Sub38 *unk_38;
    Ov011V *unk_3c;
    Ov011Sub40 *unk_40;
    Ov011Sub44 *unk_44;
    Ov011Sub48 *unk_48;
    u8 unk_4c[0x4];
    u16 *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[0x8];
    Ov011Vec pos;
    u16 rot[3];
    u8 unk_82[0x2];
    Ov011Vec unk_84;
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
    Ov011Param *unk_b0;
    u8 unk_b4[0x2];
    u16 unk_b6;
    Ov011Vec unk_b8;
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

#endif
