#include "types.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct ResSet ResSet;

typedef struct {
    s16 state;
} AnimRes;

typedef struct {
    u8 unk_00[0x2];
    u16 type : 3;
    u16 unk_02_3 : 13;
} ActorExParam;

typedef struct {
    u8 unk_00[0x9a];
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 11;
} Obj48;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct {
    const void *vtbl;
    u8 unk_04[0x1c];
    u16 unk_20;
    u8 unk_22[0x1a];
    void *unk_3c;
    u8 unk_40[0x8];
    Obj48 *unk_48;
    void *unk_4c;
    u8 unk_50[0x8];
    void *unk_58;
    u8 unk_5c[0x14];
    VecFx32 pos;
    u8 unk_7c[0x30];
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae;
    u8 unk_af;
    ActorExParam *unk_b0;
    ResSet *res[2];
    void *unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    u16 unk_cc_0 : 1;
    u16 unk_cc_1 : 1;
    u16 unk_cc_2 : 1;
    u16 unk_cc_3 : 1;
    u16 unk_cc_4 : 1;
    u16 unk_cc_5 : 1;
    u16 unk_cc_6 : 10;
} ActorEx;

extern "C" {

extern const u8 data_ov000_021cc480[];
extern HeapState *data_02097dd0;
extern void *data_0214a420;

void func_ov000_0218c2d4(void *self);
void func_ov000_0218c928(void *self);
ResSet *func_ov000_0218ea20(ResSet *self);
void func_0203de1c(void *ptr);
void func_02065804(void *mgr, void *handle);
BOOL func_ov000_0218cf5c(void *self);
BOOL func_ov000_0218f110(AnimRes *res);
BOOL func_ov000_0218d850(void *self);
void *func_ov000_02199ba0(void *p);
void *func_ov000_0219bf90(void);
void func_0203f364(Obj48 *obj);
void func_0203f8d8(void *obj);
void func_ov000_0219864c(Obj48 *obj, VecFx32 *pos, s32 c);

static inline void ResSet_Delete(ResSet *res) {
    if (res != NULL) {
        func_ov000_0218ea20(res);
        func_0203de1c(res);
    }
}

static inline void ActorEx_Init(ActorEx *self) {
    s32 i;

    func_ov000_0218c2d4(self);
    self->vtbl = data_ov000_021cc480;
    self->unk_ac = 0xff;
    self->unk_ad = 0xff;
    self->unk_ae = 0xff;
    self->unk_b0 = NULL;
    for (i = 0; i < 2; i++) {
        self->res[i] = NULL;
    }
    *((u16 *)self + 0x66) = 0;
    self->unk_bc = NULL;
    self->unk_c0 = 0;
    self->unk_c4 = 0;
    self->unk_c8 = 0;
    self->unk_cc_3 = 1;
    self->unk_cc_4 = 1;
    self->unk_cc_5 = 1;
}

static inline void ActorEx_Destroy(ActorEx *self) {
    s32 i;

    self->vtbl = data_ov000_021cc480;
    for (i = 0; i < 2; i++) {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (self->res[i] != NULL) {
            ResSet_Delete(self->res[i]);
            self->res[i] = NULL;
        }
        data_02097dd0->current = saved;
    }
    if (self->unk_bc != NULL) {
        func_02065804(data_0214a420, self->unk_bc);
    }
    func_ov000_0218c928(self);
}

ActorEx *func_ov000_02194074(ActorEx *self) {
    ActorEx_Init(self);
    return self;
}

ActorEx *func_ov000_021940e4(ActorEx *self) {
    ActorEx_Init(self);
    return self;
}

ActorEx *func_ov000_02194154(ActorEx *self) {
    ActorEx_Destroy(self);
    return self;
}

ActorEx *func_ov000_021941f4(ActorEx *self) {
    ActorEx_Destroy(self);
    func_0203de1c(self);
    return self;
}

ActorEx *func_ov000_0219429c(ActorEx *self) {
    ActorEx_Destroy(self);
    return self;
}

}

typedef struct {
    s32 m[4][3];
} Mtx43_0219433c;

typedef struct {
    u16 a;
    u16 b;
} Pair0219433c;

typedef struct {
    u8 a;
    u8 b;
    u8 kind;
    u8 d;
    u16 e;
    u16 f;
    struct {
        Pair0219433c p;
    } gh;
    u32 i;
} Hdr0219433c;

typedef struct {
    Pair0219433c p[2];
} Ids0219433c;

typedef struct {
    u8 kind;
    u8 pad;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 4;
    u16 b8 : 1;
    u16 rest : 7;
} Param0219433c;

typedef struct {
    Hdr0219433c hdr;
    Ids0219433c ids;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 frest : 6;
    u8 pad19[7];
    Mtx43_0219433c mtx;
} Sub0219433c;

typedef struct {
    Hdr0219433c hdr;
    Ids0219433c ids;
    Param0219433c param;
} Data0219433c;

typedef struct {
    u8 pad[0x12];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 10;
    u16 b12 : 2;
    u16 rest : 2;
} Info0219433c;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec0219433c;

typedef struct {
    u8 pad00[0xe];
    u16 id;
    u8 pad10[0x10];
    u16 unk_20;
    u8 pad22[0x12];
    void *unk_34;
    u8 pad38[4];
    void *unk_3c;
    void *unk_40;
    u8 pad44[8];
    Sub0219433c *unk_4c;
    u8 pad50[0x20];
    Vec0219433c pos;
    u16 rx;
    u16 ry;
    u16 rz;
    u8 pad82[0x11];
    u8 b93_0 : 7;
    u8 b93_7 : 1;
    u8 pad94[0x1c];
    Param0219433c *unk_b0;
    void *res[2];
    u8 padbc[0x10];
    u16 cc_0 : 1;
    u16 cc_1 : 1;
    u16 cc_2 : 1;
    u16 cc_3 : 1;
    u16 cc_4 : 1;
    u16 cc_5 : 11;
} Actor0219433c;

extern "C" {
extern const s16 FX_SinCosTable_[];
void *func_0203dd9c(u32 size);
Info0219433c *func_0206fef8(u16 id);
Data0219433c *func_020704b4(u16 id);
void *func_ov000_0218e9c4(void *p);
void func_ov000_02193e5c(void *p, u16 id);
void *func_ov000_021919c8(void *p);
void func_ov000_02191b70(void *p);
void *func_ov000_02198328(void *p);
void *func_ov000_02199b00(void *p);
void func_ov000_02198360(void *p, s32 a, s32 b);
void MTX_Identity43_(Mtx43_0219433c *m);
void MTX_RotX43_(Mtx43_0219433c *m, s32 s, s32 c);
void MTX_RotY43_(Mtx43_0219433c *m, s32 s, s32 c);
void MTX_RotZ43_(Mtx43_0219433c *m, s32 s, s32 c);
void MTX_Concat43(Mtx43_0219433c *a, Mtx43_0219433c *b, Mtx43_0219433c *out);
void MI_Copy48B(const void *src, void *dst);

#define SIN0219433c(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS0219433c(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void *NewRes0219433c(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    return p;
}

static inline void *NewA0219433c(void) {
    void *p = func_0203dd9c(0x1c);
    if (p != NULL) {
        p = func_ov000_021919c8(p);
    }
    return p;
}

static inline void *NewB0219433c(void) {
    void *p = func_0203dd9c(0x14);
    if (p != NULL) {
        p = func_ov000_02198328(p);
    }
    return p;
}

static inline Sub0219433c *NewSub0219433c(void) {
    void *p = func_0203dd9c(0x5c);
    if (p != NULL) {
        p = func_ov000_02199b00(p);
    }
    return (Sub0219433c *)p;
}

static inline void CopyHdr0219433c(Hdr0219433c *d, const Hdr0219433c *s) {
    d->a = s->a;
    d->b = s->b;
    d->kind = s->kind;
    d->d = s->d;
    d->e = s->e;
    d->f = s->f;
    d->gh = s->gh;
    d->i = s->i;
}

static inline void CopyIds0219433c(Ids0219433c *d, const Ids0219433c *s) {
    *d = *s;
}

static inline void SetMtx0219433c(Actor0219433c *self, Sub0219433c *sub) {
    Mtx43_0219433c t;
    Mtx43_0219433c m;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL set = FALSE;
    sub->f0 = TRUE;
    ry = self->ry;
    rz = self->rz;
    rx = self->rx;
    MTX_Identity43_(&m);
    if (ry != 0) {
        MTX_RotY43_(&m, SIN0219433c(ry), COS0219433c(ry));
        set = TRUE;
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, SIN0219433c(rx), COS0219433c(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, SIN0219433c(rx), COS0219433c(rx));
            set = TRUE;
        }
    }
    if (rz != 0) {
        if (set) {
            MTX_RotZ43_(&t, SIN0219433c(rz), COS0219433c(rz));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotZ43_(&m, SIN0219433c(rz), COS0219433c(rz));
        }
    }
    m.m[3][0] = self->pos.x;
    m.m[3][1] = self->pos.y;
    m.m[3][2] = self->pos.z;
    MI_Copy48B(&m, &self->unk_4c->mtx);
}

void func_ov000_0219433c(Actor0219433c *self) {
    Info0219433c *info = func_0206fef8(self->id);
    Data0219433c *d = func_020704b4(self->id);
    s32 i;
    self->unk_b0 = &d->param;
    if (info->b0 || info->b1 || self->unk_b0->b3) {
        self->unk_34 = NewRes0219433c();
        func_ov000_02193e5c(self->unk_34, self->id);
    }
    if (info->b12 != 0) {
        self->unk_3c = NewA0219433c();
        func_ov000_02191b70(self->unk_3c);
    }
    self->unk_40 = NewB0219433c();
    if (d->hdr.a != 0) {
        Sub0219433c *o = NewSub0219433c();
        self->unk_4c = o;
        if (d != NULL) {
            CopyHdr0219433c(&o->hdr, &d->hdr);
        }
        if (&d->ids != NULL) {
            CopyIds0219433c(&o->ids, &d->ids);
        }
        if (self->unk_b0->b8) {
            SetMtx0219433c(self, self->unk_4c);
        }
        if (d->hdr.kind == 2) {
            self->cc_2 = TRUE;
        }
        self->unk_4c->f1 = TRUE;
        if (self->unk_20 == 0xffff && d->hdr.a != 1) {
            func_ov000_02198360(self->unk_40, 10, 0);
        }
    }
    if (self->unk_4c != NULL) {
        for (i = 0; i < 2; i++) {
            u16 id = ((u16 *)&self->unk_4c->ids)[i + 2];
            if (id != 0xffff && (u16)(id & 0xf000) != 0) {
                self->res[i] = NewRes0219433c();
                func_ov000_02193e5c(self->res[i], id);
            }
        }
    }
    if (self->unk_b0->kind == 0x19) {
        self->cc_3 = FALSE;
        self->cc_4 = FALSE;
    }
    self->b93_7 = TRUE;
}

}
