#ifndef OV003_GMOBJ_H
#define OV003_GMOBJ_H

#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

extern "C" void NNS_G3dRenderObjRemoveAnmObj(void *a, void *b);

typedef struct {
    u16 state;
    u16 timer;
    u8 unk_04[0xf];
    u8 kind;
} Ov003Work;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    u8 unk_58[0x42];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003Ctl;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

typedef struct {
    u8 unk_00[0x2c];
    u32 unk_2c;
} Ov003ColState;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
    u8 unk_a2_1 : 4;
    u8 unk_a2_5 : 1;
    u8 unk_a2_6 : 1;
} Ov003Unit;

typedef struct {
    void *unk_00;
} Ov003ModelRes;

typedef struct {
    u8 unk_00[0xc];
    Ov003ModelRes *unk_0c;
} Ov003ModelHdr;

typedef struct {
    void *unk_00;
    u8 unk_04[0x104];
    u8 unk_108;
    u8 unk_109[7];
    u8 unk_110;
    u8 unk_111_0 : 1;
    u8 unk_111_1 : 1;
} Ov003Anim;

typedef struct {
    Ov003Vec3 pos;
    u8 unk_0c[0x16];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Sub44;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003Kind;

typedef struct {
    u8 unk_00[0x18];
    u8 unk_18_0 : 5;
    u8 unk_18_5 : 1;
    u8 unk_19[3];
    u16 unk_1c;
    u8 unk_1e[0x22];
    Ov003Kind *unk_40;
} Ov003Part;

typedef struct {
    Ov003Vec3 pos;
    s32 unk_0c;
} Ov003PathPt;

typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
} Ov003SpawnInfo;

typedef struct {
    Ov003ModelHdr *unk_00;
    u8 unk_04[0xc];
    Ov003Anim *unk_10;
    u8 unk_14[0x10];
    u8 unk_24[0x54];
    Ov003Vec3 pos;
    u8 unk_84[0x24];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xa];
    u8 unk_be;
    u8 unk_bf[3];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
    u8 unk_ad[0x1d];
    u8 unk_ca;
    u8 unk_cb[9];
    void *unk_d4;
} Ov003Game54;

typedef struct Ov003Obj {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x8];
    s16 unk_18;
    s16 unk_1a;
    s16 kind;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *model;
    u8 unk_3c[4];
    Ov003Work *work;
    Ov003Sub44 *unk_44;
    Ov003Ctl *ctl;
    Ov003Part *unk_4c;
    u8 unk_50[0xc];
    void *unk_5c;
    void *unk_60;
    s32 unk_64;
    u8 unk_68[4];
    s32 unk_6c;
    Ov003Vec3 pos;
    u8 unk_7c[0x8];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 1;
    u16 unk_cc_1 : 2;
    u16 unk_cc_3 : 1;
    u16 unk_cc_4 : 4;
    u16 unk_cc_8 : 1;
    s16 unk_ce;
    union {
        s16 res;
        u16 unk_d0;
    };
    u8 unk_d2;
    u8 unk_d3;
    Ov003Vec3 unk_d4;
    u8 unk_e0[0xec];
    void **unk_1cc;
    u8 unk_1d0[0x20];
    u8 unk_1f0[0x18];
    void *unk_208;
    u8 unk_20c;
    u8 unk_20d[3];
    s32 unk_210;
} Ov003Obj;

class Ov003Fx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetSpeed(s32 v);
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
};

class Ov003ObjV {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

static inline void Ov003Obj_Destroy(Ov003Obj *self) {
    ((Ov003ObjV *)self)->Destroy();
}

static inline void Ov003Model_ResetAnim(Ov003Model *m) {
    Ov003Anim *a = m->unk_10;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(m->unk_24, a->unk_00);
        a->unk_108 = 0;
        a->unk_110 = 0xff;
        a->unk_111_0 = 0;
        a->unk_111_1 = 0;
    }
}

static inline void Ov003Model_SetScale(Ov003Model *m, s32 s) {
    m->unk_a8 = s;
    m->unk_ac = s;
    m->unk_b0 = s;
}

static inline void Ov003Model_SetScale3(Ov003Model *m, s32 x, s32 y, s32 z) {
    m->unk_a8 = x;
    m->unk_ac = y;
    m->unk_b0 = z;
}

static inline void Ov003Sub44_Clear(Ov003Sub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

static inline void Ov003Sub44_Set(Ov003Sub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 1;
        s->unk_22_1 = 1;
    }
}

static inline s32 Ov003Kind_Get(Ov003Kind *k) {
    return k != NULL ? k->kind : 0;
}

#endif
