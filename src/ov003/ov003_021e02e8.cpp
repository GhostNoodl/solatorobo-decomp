#include "types.h"

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003SpotKind;

typedef struct {
    u8 unk_00[0x40];
    Ov003SpotKind *unk_40;
    u8 unk_44[0x4f];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x3c];
    u8 unk_d0[0x30];
    u8 unk_100;
} Ov003Spot;

typedef struct {
    s32 x, y, z;
} Ov003LampVec;

typedef struct {
    s32 m[12];
} Ov003LampMtx;

typedef struct {
    Ov003LampVec pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk_14;
} Ov003LampMsg;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003LampRot;

class Ov003LampPtcl {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003LampRot *r);
};

class Ov003LampFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34(s32 x, s32 y, s32 z);
};

extern "C" {

typedef struct {
    void *vtbl;
    void *owner;
    u32 flags;
    u8 unk_0c[0x18];
    void (*func)(void *);
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x1b];
    u8 unk_ae;
} Ov003Obj;

extern void *data_ov000_021ccd68;
extern Ov003Spot *func_ov000_0218e6d0(void *mgr, s32 a, s32 b);
extern void NNS_G3dGetCurrentMtx(void *p, s32 a);
extern void MI_Copy48B(void *a, void *b);

typedef struct {
    s32 x, y, z;
} Ov003LnVec;

typedef struct {
    s32 m[9];
} Ov003LnMtx;

typedef struct {
    u8 unk_00[0x78];
    Ov003LnVec pos;
} Ov003LnModel;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003LnKind;

typedef struct {
    u8 unk_00[0x38];
    Ov003LnModel *model;
    u8 unk_3c[4];
    Ov003LnKind *unk_40;
    u8 unk_44[0x2c];
    Ov003LnVec pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[4];
    Ov003LnVec offset;
} Ov003Line;


extern const s16 FX_SinCosTable_[];
extern void VEC_Add(const Ov003LnVec *a, const Ov003LnVec *b, Ov003LnVec *out);
extern void MTX_RotY33_(Ov003LnMtx *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov003LnVec *v, const Ov003LnMtx *m, Ov003LnVec *out);
extern BOOL func_ov000_021903b4(Ov003LnModel *model);
extern BOOL func_ov000_02194c08(void *self);

static inline void Ov003Ln_Draw(Ov003Line *self, const Ov003LnVec *p) {
    Ov003LnModel *m = self->model;
    m->pos.x = p->x;
    m->pos.y = p->y;
    m->pos.z = p->z;
    func_ov000_021903b4(self->model);
}

static inline void Ov003Ln_Sub(const Ov003LnVec *a, const Ov003LnVec *b, Ov003LnVec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

BOOL func_ov003_021e00e8(Ov003Line *self) {
    Ov003LnVec p;
    Ov003LnVec d;
    Ov003LnMtx m;
    VEC_Add(&self->pos, &self->offset, &p);
    MTX_RotY33_(&m, FX_SinCosTable_[(self->rotY >> 4) * 2], FX_SinCosTable_[(self->rotY >> 4) * 2 + 1]);
    d.x = 0xc800;
    d.y = 0;
    d.z = 0;
    MTX_MultVec33(&d, &m, &d);
    switch (self->unk_40->kind) {
    default:
        func_ov000_02194c08(self);
        break;
    case 0x21:
        Ov003Ln_Draw(self, &p);
        VEC_Add(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        VEC_Add(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        break;
    case 0x22:
        Ov003Ln_Draw(self, &p);
        Ov003Ln_Sub(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        Ov003Ln_Sub(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        break;
    }
    return TRUE;
}

void func_ov003_021e02e8(Ov003Obj *self) {
    u8 buf[0x30];
    Ov003Spot *p;
    s32 id;
    u8 b;
    if (data_ov000_021ccd68 == NULL) {
        p = NULL;
    } else {
        p = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x404f);
    }
    if (p == NULL || (b = p->unk_100) == 0xff) {
        return;
    }
    if (self->flags & 0x10) {
        id = self->unk_ae;
    } else {
        id = -1;
    }
    if (b != id) {
        return;
    }
    NNS_G3dGetCurrentMtx(buf, 0);
    MI_Copy48B(buf, p->unk_d0);
}

void func_ov003_021e0370(Ov003Obj *self) {
    self->func = (void (*)(void *))func_ov003_021e02e8;
    self->unk_92 = 3;
}

typedef struct {
    u8 unk_00[0x24];
    u8 unk_24[0x9e];
    u16 unk_c2_0 : 5;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 2;
    u16 unk_c2_8 : 1;
} Ov003LampModel;

typedef struct {
    u16 state;
    u16 timer;
} Ov003LampWork;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x2a];
    Ov003LampModel *model;
    u8 unk_3c[4];
    Ov003LampWork *work;
    u8 unk_44[0x14];
    void *unk_58;
    u8 unk_5c[0x14];
    Ov003LampVec pos;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x4e];
    u8 unk_d0[0x24];
    Ov003LampVec unk_f4;
    u8 unk_100;
} Ov003Lamp;

typedef struct {
    u16 unk_00_0 : 1;
    u8 unk_02[0x6e];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Ov003Game48;

extern Ov003Game48 *data_02097e48;
extern char data_ov003_021f851c[];
extern char data_ov003_021f8525[];
extern void func_ov000_02194758(void *self);
extern s32 func_ov000_021909a8(void *model, s32 a, const char *name);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *fn);
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);

void func_ov003_021e0388(Ov003Lamp *self) {
    Ov003LampModel *m;
    Ov003Game48 *g;
    func_ov000_02194758(self);
    self->unk_100 = func_ov000_021909a8(self->model, 0, data_ov003_021f851c);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, func_ov003_021e0370);
    m->unk_c2_5 = 0;
    self->model->unk_c2_8 = 1;
    func_ov000_02190cb0(self->model, data_ov003_021f8525, 0x1000, 0);
    func_ov000_021915a0(self->model);
    g = data_02097e48;
    if (g->unk_00_0 != 1 || g->unk_74 != 0xffff || g->unk_72 != 0x4e) {
        g->unk_74 = 0x4e;
        g->unk_70 = 0;
    }
}

extern Ov003LampFx *func_02065f88(s32 id, const Ov003LampVec *pos);
extern s32 func_02040528(s32 max);
extern void func_0203f9dc(void *p, Ov003LampMtx *m);
extern void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, void *e);

void func_ov003_021e0448(Ov003Lamp *self) {
    Ov003Spot *p;
    Ov003LampWork *w;
    Ov003LampMtx m;
    Ov003LampMsg msg;
    Ov003LampMtx m2;
    u8 k;
    if (data_ov000_021ccd68 == NULL) {
        p = NULL;
    } else {
        p = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x404e);
    }
    w = self->work;
    switch (w->state) {
    case 0:
        if (p != NULL && p->unk_93_1 != 0) {
            w->timer = 0;
            self->work->state++;
            break;
        }
        w->timer++;
        if ((w->timer & 0x3f) == 0) {
            Ov003LampFx *fx = func_02065f88(0x325, &self->unk_f4);
            fx->SetRot(func_02040528(0x1800), func_02040528(0x800) - 0x800, func_02040528(0x1800));
            fx->v34(0, 0x4000, 0);
        }
        break;
    case 1:
        if ((w->timer & 0x3f) == 0) {
            Ov003LampFx *fx = func_02065f88(0x322, &self->unk_f4);
            fx->SetRot(func_02040528(0x1800), func_02040528(0x800) - 0x800, func_02040528(0x1800));
        }
        self->work->timer++;
        break;
    }
    MI_Copy48B(self->unk_d0, &m);
    m.m[10] -= 0x800;
    func_0203f9dc(self->unk_58, &m);
    if (p == NULL) {
        return;
    }
    if (p->unk_40 != NULL) {
        k = p->unk_40->kind;
    } else {
        k = 0;
    }
    if (k != 1) {
        return;
    }
    msg.pos.x = self->unk_f4.x;
    msg.pos.y = self->unk_f4.y;
    msg.pos.z = self->unk_f4.z;
    msg.rx = self->unk_7c;
    msg.ry = self->unk_7e;
    msg.rz = self->unk_80;
    msg.unk_14 = 0;
    func_ov000_0218d398(p, self->unk_0c, 7, 1, sizeof(msg), &msg);
    MI_Copy48B(self->unk_d0, &m2);
    func_ov000_0218d398(p, self->unk_0c, 8, 1, sizeof(m2), &m2);
}

extern void *data_02097e4c;
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, Ov003LampVec *pos, s32 a);
extern Ov003LampPtcl *func_ov000_0219b71c(Ov003LampVec *pos, Ov003LampVec *v, s32 a, s32 b, s32 c, s32 d);

void func_ov003_021e06a8(Ov003Lamp *self) {
    Ov003LampWork *w = self->work;
    s32 a;
    s32 b;
    Ov003LampVec sc;
    Ov003LampVec p;
    Ov003LampRot r;
    Ov003LampPtcl *fx;
    w->timer++;
    if (w->timer & 0xf) {
        return;
    }
    a = -1;
    b = 100;
    switch (self->work->timer & 0x3f) {
    case 0:
        func_ov000_0218996c(6, 10);
        a = 0x131;
        break;
    case 0x10:
        a = 0x322;
        b = 0x4b;
        break;
    case 0x20:
        func_ov000_0218996c(8, 0xf);
        a = 0x131;
        break;
    case 0x30:
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        a = 3;
        b = 0x19;
        break;
    }
    sc.x = 0x3800;
    sc.y = 0x3000;
    sc.z = 0x3800;
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.y += 0x5800;
    fx = func_ov000_0219b71c(&p, &sc, 0x800, 0x1000, a, b);
    r.x = self->unk_7c;
    r.y = self->unk_7e;
    r.z = self->unk_80;
    r.y += 0x8000;
    fx->SetRot(&r);
}

}
