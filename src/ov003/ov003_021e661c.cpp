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
    u16 unk_9a;
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
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Sub44;

typedef struct {
    u8 unk_00[0x18];
    u8 unk_18_0 : 5;
    u8 unk_18_5 : 1;
    u8 unk_19[3];
    u16 unk_1c;
} Ov003Part;

typedef struct {
    Ov003Vec3 pos;
    s32 unk_0c;
} Ov003PathPt;

typedef struct {
    Ov003ModelHdr *unk_00;
    u8 unk_04[0xc];
    Ov003Anim *unk_10;
    u8 unk_14[0x10];
    u8 unk_24[0x84];
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
    u8 unk_64[0xc];
    Ov003Vec3 pos;
    u8 unk_7c[0x8];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
    s16 unk_ce;
    s16 res;
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

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern Ov003Game54 *data_ov000_021ccd54;
extern char data_ov003_021f8574[];
extern Ov003PathPt *const data_ov003_021f85c0[];
extern Ov003Part *func_ov000_02199ba0(Ov003Part *p);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_02190e98(void *model, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_02191618(void *model);
extern void func_ov000_02191318(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void func_0204a028(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627ec(s32 a);
extern s32 func_02040498(s32 max);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02191008(void *p);

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

void func_ov003_021e661c(Ov003Obj *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->work, 0x20, 0);
    func_ov000_02191008(self->model);
}

void func_ov003_021e6644(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        func_0204a028(data_02097e4c, 0x25, &self->pos, -0xf);
        self->work->state++;
    case 1: {
        Ov003Work *w = self->work;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        self->model->unk_be = t;
        Ov003Model_SetScale(self->model, 0x3000 - t * 0x19a);
        if (t <= 20) {
            return;
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        func_020627ec(1);
        data_ov000_021ccd54->unk_ac = 1;
        func_ov000_02198360(self->work, 1, 0);
        break;
    }
    }
}

void func_ov003_021e671c(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        Ov003Model_ResetAnim(self->model);
        self->work->state++;
    case 1: {
        Ov003Work *w = self->work;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        s = t * 0x7b;
        self->model->unk_be = 25 - t;
        Ov003Model_SetScale3(self->model, s + 0x1000, (s >> 1) + 0x1000, s + 0x1000);
        if (t <= 15) {
            return;
        }
        self->work->state++;
        self->work->timer = 0;
        break;
    }
    case 2: {
        Ov003Work *w = self->work;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        s = t * 0x252;
        self->model->unk_be = 15 - t;
        Ov003Model_SetScale3(self->model, 0x1733 - s, s + 0x1733, 0x1733 - s);
        if (t <= 10) {
            return;
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        func_020627ec(100);
        data_ov000_021ccd54->unk_ac = 1;
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        Ov003Obj_Destroy(self);
        break;
    }
    }
}

}
