#include "ov003/GmObj.h"

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BigMtx;

typedef struct {
    u8 unk_00[0x98];
} Ov003BigRObj;

typedef struct {
    u8 unk_00[0x84];
    void **unk_84;
} Ov003BigRes;

typedef struct {
    u16 unk_00;
    u16 ang;
    Ov003Vec3 v;
} Ov003BigEnt;

typedef struct {
    void *unk_00;
    void *mdl;
    u8 unk_08[0xac];
    u16 unk_b4;
    u8 unk_b6[0xc];
    u16 unk_c2_0 : 7;
    u16 unk_c2_7 : 1;
} Ov003BigMdl;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x18];
    Ov003BigRes *unk_34;
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x20];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec3 pos;
    u16 rot[3];
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x38];
    u16 unk_cc_0 : 1;
    u8 unk_ce[2];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003BigMdl sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    Ov003BigRObj obj0[4];
    Ov003BigRObj obj1[4];
    Ov003BigRObj obj2[3];
    Ov003Vec3 unk_af4[3];
    u8 unk_b18;
} Ov003Big;

typedef struct {
    s16 unk_00;
    u16 ang;
    Ov003Vec3 v;
} Ov003BigEnt2;

typedef struct {
    Ov003Vec3 pos;
    u16 unk_0c;
    u16 mask;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    union { u8 flags; struct { u8 f_0 : 1; u8 f_1 : 1; u8 f_2 : 1; u8 f_3 : 1; } b; };
} Ov003BigQuery;

typedef struct {
    Ov003BigQuery *q;
} Ov003BigFinder;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x60];
    Ov003Vec3 pos;
    u16 rot[3];
} Ov003BigTgt;

typedef struct {
    Ov003Vec3 pos;
    u8 unk_0c[4];
    s32 unk_10;
} Ov003BigHit;

typedef struct {
    Ov003Vec3 pos;
    u16 rot[3];
    s32 unk_14;
} Ov003BigWarp;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern const Ov003BigEnt2 data_ov003_021f6230[][4];
extern void func_01ffc9fc(Ov003Vec3 *dst, const Ov003Vec3 *src, u16 angle);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);
extern void func_0203f990(Ov003BigRObj *o, void *res);
extern void MTX_Identity43_(Ov003BigMtx *m);
extern void MTX_RotX43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BigMtx *a, Ov003BigMtx *b, Ov003BigMtx *out);
extern void func_0203f9dc(Ov003BigRObj *o, Ov003BigMtx *m);
extern void func_0203f9b8(Ov003BigRObj *o, s32 a);
extern void func_0203f8d8(Ov003BigRObj *o);
extern void func_0203f920(Ov003BigRObj *o);
extern s32 func_ov000_0219a2f4(Ov003Vec3 *pos, s32 a, s32 b);
extern char data_ov003_021f85a7[];
extern char data_ov003_021f85ac[];
extern void *data_02097e4c;
extern s32 func_ov000_021993fc(Ov003BigFinder *f, Ov003BigQuery *q, Ov003BigHit **out, s32 max);
extern Ov003BigTgt *func_ov000_021985c0(Ov003BigHit *h);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_0204a028(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_0218d398(Ov003BigTgt *o, u16 id, s32 a, s32 b, s32 c, void *p);
extern Ov003BigTgt *func_ov000_0218d240(Ov003Big *self);
extern void VEC_MultAdd(s32 a, Ov003Vec3 *v1, Ov003Vec3 *v2, Ov003Vec3 *dst);
extern u16 func_01ffc128(u16 cur, u16 tgt, s32 step, s32 a, s32 b);
void func_ov003_021e51f8(Ov003Big *self, u32 t);

static inline void Ov003BigQuery_Init(Ov003BigQuery *q) {
    q->mask = 0;
    q->unk_10 = 0xffff;
    q->unk_12 = 0;
    q->unk_14 = 0;
    q->unk_18 = 0;
    q->unk_1c = 0;
    q->unk_20 = 0;
    q->unk_24 = 0;
    q->unk_28 = 0xffff;
    q->flags = 0;
}

static inline void Ov003Big_Sub(Ov003Vec3 *d, Ov003Vec3 *a, Ov003Vec3 *b) {
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
}

#define OV003BIG_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BIG_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Big_SetMtx(Ov003BigRObj *o, Ov003Vec3 *v, u16 rx, u16 ry, u16 rz) {
    Ov003BigMtx m;
    Ov003BigMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BIG_SIN(rz), OV003BIG_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            set = TRUE;
        }
    }
    m.tx = v->x;
    m.ty = v->y;
    m.tz = v->z;
    func_0203f9dc(o, &m);
    func_0203f9b8(o, 0x119a);
    func_0203f8d8(o);
}

static inline void *Ov003Big_Res(Ov003BigRes *r) {
    return r->unk_84 != NULL ? *r->unk_84 : NULL;
}

static inline void Ov003Big_Approach(Ov003BigWarp *w, Ov003BigTgt *o, Ov003Big *self) {
    Ov003Vec3 d;
    w->pos.x = o->pos.x;
    w->pos.y = o->pos.y;
    w->pos.z = o->pos.z;
    Ov003Big_Sub(&d, &w->pos, &self->pos);
    VEC_MultAdd(0xc00, &d, &self->pos, &w->pos);
    w->rot[0] = o->rot[0];
    w->rot[1] = o->rot[1];
    w->rot[2] = o->rot[2];
    w->rot[1] = func_01ffc128(self->rot[1], w->rot[1], 0x400, 1, 0x8000);
}

void func_ov003_021e4b18(Ov003Big *self) {
    Ov003BigTgt *found = NULL;
    switch (self->work->state) {
    case 0:
        self->unk_90 = 0xffff;
        self->work->state++;
        break;
    case 1: {
        Ov003BigHit *list[0x20];
        Ov003BigQuery q;
        Ov003BigWarp w;
        Ov003BigFinder f;
        u8 b;
        s32 n;
        u8 kind;
        s32 i;
        Ov003BigQuery_Init(&q);
        q.pos.x = self->pos.x;
        q.pos.y = self->pos.y;
        q.pos.z = self->pos.z;
        q.unk_0c = 0;
        q.unk_28 = self->unk_0c;
        q.unk_1c = self->unk_64 + 0x400;
        q.unk_18 = 0;
        q.unk_20 = 0;
        q.unk_24 = 0x2800;
        q.b.f_1 = 1;
        q.b.f_2 = 1;
        q.b.f_3 = 1;
        q.mask = 0x10;
        q.unk_10 = 0xffff;
        f.q = NULL;
        n = func_ov000_021993fc(&f, &q, list, 0x20);
        kind = 0;
        for (i = 0; i < n; i++) {
            Ov003BigHit *h = list[i];
            if (h != NULL && h->pos.y - h->unk_10 - self->pos.y - self->unk_68 <= 0x666) {
                Ov003BigTgt *o = func_ov000_021985c0(h);
                if (o != NULL) {
                    u8 k = 0;
                    if (o->unk_0e == 0x404b) {
                        k = 1;
                    } else if (o->unk_0e == 0x404c) {
                        k = 2;
                    } else if (o->unk_0e == 0x404d) {
                        k = 3;
                    }
                    if (k != 0) {
                        if (self->unk_90 == o->unk_0c) {
                            kind = k;
                            found = o;
                            break;
                        }
                        if (k == self->unk_93_1) {
                            kind = k;
                            found = o;
                        } else if (kind == 0 && found == NULL) {
                            kind = k;
                            found = o;
                        }
                    }
                }
            }
        }
        if (self->unk_93_1 != kind) {
            if (kind != 0 && self->unk_93_1 == 0) {
                func_ov000_02190cb0(self->model, data_ov003_021f85a7, 0x1000, 0);
                func_0204a028(data_02097e4c, 0xd, &self->pos, -0xf);
                self->unk_90 = found->unk_0c;
                self->unk_93_1 = kind;
                self->unk_18 = kind;
                b = 0;
                func_ov000_0218d398(found, self->unk_0c, 0xd, 1, 1, &b);
                self->unk_b18 = self->unk_93_1 - 1;
                self->work->state = 10;
            } else {
                func_ov000_02190cb0(self->model, data_ov003_021f85ac, 0x1000, 0);
                func_0204a028(data_02097e4c, 0xd, &self->pos, -0xf);
                self->unk_18 = 0;
                self->unk_93_1 = 0;
                self->unk_90 = 0xffff;
                for (i = 0; i < 3; i++) {
                    func_0203f920(&self->obj2[i]);
                }
                for (i = 0; i < 4; i++) {
                    if (self->unk_1a == 0 || i <= 1) {
                        func_0203f8d8(&self->obj1[i]);
                    }
                }
                self->work->state = 20;
            }
        }
        if (self->unk_93_1 != 0 && found != NULL) {
            self->unk_90 = found->unk_0c;
            w.unk_14 = 0;
            Ov003Big_Approach(&w, found, self);
            func_ov000_0218d398(found, self->unk_0c, 7, 1, 0x18, &w);
            func_0203f920(&self->obj2[self->unk_b18]);
            if (func_ov000_0219a2f4(&self->unk_af4[self->unk_b18], 0x1000, -0x5000) == -0x1000) {
                func_0203f8d8(&self->obj2[self->unk_b18]);
            }
        }
        break;
    }
    case 10: {
        Ov003BigWarp w;
        Ov003BigTgt *o = func_ov000_0218d240(self);
        Ov003Work *wk;
        if (o == NULL) {
            self->work->state = 0;
            break;
        }
        w.unk_14 = 0;
        wk = self->work;
        wk->timer++;
        if (wk->timer < 6) {
            Ov003Big_Approach(&w, o, self);
        } else {
            w.pos.x = self->pos.x;
            w.pos.y = self->pos.y;
            w.pos.z = self->pos.z;
            w.pos.y -= 0x800;
            w.rot[0] = self->rot[0];
            w.rot[1] = self->rot[1];
            w.rot[2] = self->rot[2];
            self->work->state++;
            self->work->timer = 0;
        }
        func_ov000_0218d398(o, self->unk_0c, 7, 1, 0x18, &w);
        break;
    }
    case 11: {
        Ov003Work *wk = self->work;
        wk->timer++;
        if (wk->timer > 0x24) {
            Ov003BigTgt *o = func_ov000_0218d240(self);
            if (o != NULL) {
                u8 b = 1;
                func_ov000_0218d398(o, self->unk_0c, 0xd, 1, 1, &b);
            }
            self->work->timer = 0xffff;
            self->work->state = 1;
        }
        func_ov003_021e51f8(self, self->work->timer);
        break;
    }
    case 20:
        self->work->timer = 0x24;
        self->work->state++;
    case 21: {
        Ov003Work *wk = self->work;
        if (wk->timer != 0) {
            wk->timer--;
        }
        if (wk->timer == 0) {
            self->work->state = 0;
        }
        func_ov003_021e51f8(self, self->work->timer);
        break;
    }
    }
}

void func_ov003_021e51f8(Ov003Big *self, u32 t) {
    Ov003Vec3 v;
    if (t == 0) {
        s32 i;
        for (i = 0; i < 4; i++) {
            self->unk_428[i].x = self->pos.x;
            self->unk_428[i].y = self->pos.y;
            self->unk_428[i].z = self->pos.z;
            self->unk_458[i] = 0;
            self->unk_468[i] = 0;
            func_0203f920(&self->obj0[i]);
        }
        for (i = 0; i < 3; i++) {
            func_0203f920(&self->obj2[i]);
        }
        for (i = 0; i < 4; i++) {
            if (self->unk_1a == 0 || i <= 1) {
                func_0203f8d8(&self->obj1[i]);
            }
        }
    } else if (t == 0xffff) {
        s32 i;
        func_0203f920(&self->obj1[0]);
        func_0203f920(&self->obj1[self->unk_b18 + 1]);
        func_0203f920(&self->obj2[self->unk_b18]);
        if (func_ov000_0219a2f4(&self->unk_af4[self->unk_b18], 0x1000, -0x5000) == -0x1000) {
            func_0203f8d8(&self->obj2[self->unk_b18]);
        }
        for (i = 0; i < 4; i++) {
            const Ov003BigEnt2 *e = &data_ov003_021f6230[self->unk_b18][i];
            if (e->unk_00 >= 0) {
                u16 rz;
                u16 rx;
                u16 ry;
                void *r;
                func_01ffc9fc(&v, &e->v, self->rot[1]);
                VEC_Add(&v, &self->pos, &v);
                self->unk_428[i].x = v.x;
                self->unk_428[i].y = v.y;
                self->unk_428[i].z = v.z;
                self->unk_458[i] = 0x1000;
                self->unk_468[i] = 0x1f;
                rz = self->rot[2];
                ry = self->rot[1] + e->ang;
                rx = self->rot[0];
                { Ov003BigRes *q = (Ov003BigRes *)&self->res; if (e->unk_00 != 0) q = (Ov003BigRes *)&self->res2; r = Ov003Big_Res(q); }
                func_0203f990(&self->obj0[i], r);
                Ov003Big_SetMtx(&self->obj0[i], &v, rx, ry, rz);
            } else {
                self->unk_468[i] = 0;
            }
        }
    } else {
        if (t <= 12 && data_ov003_021f6230[self->unk_b18][0].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][0].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[0]);
            self->unk_458[0] = (s32)(t << 12) / 12;
            self->unk_468[0] = (s32)(t * 31) / 12;
        }
        if (t >= 6 && t <= 18 && data_ov003_021f6230[self->unk_b18][1].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][1].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[1]);
            self->unk_458[1] = (s32)((t - 6) << 12) / 12;
            self->unk_468[1] = (s32)((t - 6) * 31) / 12;
        }
        if (t >= 12 && t <= 24 && data_ov003_021f6230[self->unk_b18][2].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][2].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[2]);
            self->unk_458[2] = (s32)((t - 12) << 12) / 12;
            self->unk_468[2] = (s32)((t - 12) * 31) / 12;
        }
        if (t >= 18 && t <= 30 && data_ov003_021f6230[self->unk_b18][3].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][3].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[3]);
            self->unk_458[3] = (s32)((t - 18) << 12) / 12;
            self->unk_468[3] = (s32)((t - 18) * 31) / 12;
        }
    }
}

}
