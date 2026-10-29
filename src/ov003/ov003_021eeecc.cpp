#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BrMtx;

typedef struct {
    Ov003Vec pos;
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
} Ov003BrQuery;

typedef struct {
    Ov003BrQuery *q;
} Ov003BrFinder;

typedef struct {
    Ov003Vec pos;
    u8 unk_0c[4];
    s32 unk_10;
} Ov003BrHit;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 mode;
    u8 unk_1c[0x4c];
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec pos;
    u16 rot[3];
} Ov003BrTgt;

typedef struct {
    Ov003Vec pos;
    u16 rot[3];
    s32 unk_14;
} Ov003BrWarp;

class Ov003BrFx {
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
    virtual void SetScale(s32 x, s32 y, s32 z);
};

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003BrGame;

struct Ov003Bridge {
    void *vtbl;
    u8 unk_04[8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[8];
    s16 kind;
    s16 mode;
    s16 height;
    u8 unk_1e[0x1a];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[8];
    void *unk_4c;
    u8 unk_50[8];
    void *unk_58;
    u8 unk_5c[8];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov003Vec pos;
    u16 rot[3];
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 state : 3;
    u8 unk_94[0x38];
    u16 unk_cc_0 : 1;
};

extern "C" {

extern const s16 FX_SinCosTable_[];
extern void *data_02097e4c;
extern Ov003BrGame *data_ov000_021ccd54;
extern char data_ov003_021f9fd6[];
extern s32 func_ov000_021993fc(Ov003BrFinder *f, Ov003BrQuery *q, Ov003BrHit **out, s32 max);
extern Ov003BrTgt *func_ov000_021985c0(Ov003BrHit *h);
extern BOOL func_ov003_021f0a38(Ov003BrTgt *t, void *def);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d398(Ov003BrTgt *o, u16 id, s32 a, s32 b, s32 c, void *p);
extern Ov003BrTgt *func_ov000_0219bf90(void);
extern Ov003BrFx *func_02065f88(s32 id, Ov003Vec *pos);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern Ov003BrTgt *func_ov000_0218d240(Ov003Bridge *self);
extern void func_ov000_02197d80(void *self);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void MTX_Identity43_(Ov003BrMtx *m);
extern void MTX_RotX43_(Ov003BrMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BrMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BrMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BrMtx *a, Ov003BrMtx *b, Ov003BrMtx *out);
extern void func_0203f9dc(void *o, Ov003BrMtx *m);
extern void VEC_MultAdd(s32 a, Ov003Vec *v1, Ov003Vec *v2, Ov003Vec *dst);
extern BOOL func_ov000_021b4738(void);
extern void func_020627b4(void);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627ec(u16 a);
extern void func_ov000_02182590(void *p);

#define OV003BR_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BR_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003BrQuery_Init(Ov003BrQuery *q) {
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

static inline void Ov003Br_SetMtx(void *o, s32 x, s32 y, s32 z, u16 rx, u16 ry, u16 rz) {
    Ov003BrMtx m;
    Ov003BrMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BR_SIN(rz), OV003BR_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BR_SIN(ry), OV003BR_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BR_SIN(ry), OV003BR_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BR_SIN(rx), OV003BR_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BR_SIN(rx), OV003BR_COS(rx));
            set = TRUE;
        }
    }
    m.tx = x;
    m.ty = y;
    m.tz = z;
    func_0203f9dc(o, &m);
}

static inline void Ov003Br_Approach(Ov003BrWarp *w, Ov003BrTgt *t, Ov003Bridge *self) {
    Ov003Vec d;
    w->pos.x = t->pos.x;
    w->pos.y = t->pos.y;
    w->pos.z = t->pos.z;
    w->pos.y += self->height << 4;
    d.x = self->pos.x - w->pos.x;
    d.y = self->pos.y - w->pos.y;
    d.z = self->pos.z - w->pos.z;
    VEC_MultAdd(0x59a, &d, &w->pos, &w->pos);
    w->rot[0] = t->rot[0];
    w->rot[1] = t->rot[1];
    w->rot[2] = t->rot[2];
}

void func_ov003_021eeecc(Ov003Bridge *self) {
    switch (self->work->state) {
    case 0: {
        Ov003BrHit *list[0x20];
        Ov003BrQuery q;
        Ov003Vec v;
        Ov003BrFinder f;
        u8 b;
        s32 n;
        Ov003BrTgt *found = NULL;
        s32 i;
        Ov003BrTgt *pl;
        Ov003BrQuery_Init(&q);
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
        for (i = 0; i < n; i++) {
            Ov003BrHit *h = list[i];
            if (h != NULL && h->pos.y - h->unk_10 - self->pos.y - self->unk_68 <= 0x666) {
                Ov003BrTgt *o = func_ov000_021985c0(h);
                if (o != NULL && self->unk_4c != NULL && func_ov003_021f0a38(o, self->unk_4c)) {
                    found = o;
                    break;
                }
            }
        }
        if (found == NULL) {
            return;
        }
        self->unk_90 = found->unk_0c;
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f9fd6, 0x111, 0);
            func_ov000_021915a0(self->model);
            func_ov000_021911c8(self->model, 0x4cd);
        }
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        func_ov000_0218996c(5, 10);
        b = 0;
        func_ov000_0218d398(found, self->unk_0c, 0xd, 1, 1, &b);
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            v.x = pl->pos.x;
            v.y = pl->pos.y;
            v.z = pl->pos.z;
            func_02065f88(0x44f, &v)->SetScale(0, pl->unk_68, 0);
            func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
        }
        self->work->state++;
        self->work->timer = 0;
        break;
    }
    case 1: {
        Ov003Work *w = self->work;
        Ov003BrTgt *t;
        w->timer++;
        if (w->timer >= 0xf) {
            self->unk_cc_0 = 0;
            self->work->timer = 0;
            t = func_ov000_0218d240(self);
            if (t != NULL) {
                Ov003BrWarp wp;
                s16 mode;
                wp.pos.x = self->pos.x;
                wp.pos.y = self->pos.y;
                wp.pos.z = self->pos.z;
                wp.pos.y = self->pos.y + (self->height << 4);
                wp.rot[0] = t->rot[0];
                wp.rot[1] = t->rot[1];
                wp.rot[2] = t->rot[2];
                wp.unk_14 = 0;
                func_ov000_0218d398(t, self->unk_0c, 7, 1, 0x18, &wp);
                func_ov000_02197d80(self);
                mode = 1;
                if (self->kind == 0) {
                    if (self->mode == 0) {
                        if (t->mode != 0) {
                            mode = 2;
                        }
                    } else if (t->mode == 0) {
                        mode = 3;
                    } else {
                        mode = 4;
                    }
                } else if (self->mode == 0) {
                    if (t->mode == 0) {
                        mode = 5;
                    } else {
                        mode = 6;
                    }
                } else {
                    mode = 6;
                    if (t->mode != 0) {
                        mode = 5;
                    }
                }
                self->kind = mode;
                func_ov000_02197dec(self, mode, -1);
            }
            self->state = 1;
            if (self->unk_58 != NULL) {
                func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                func_ov000_0218996c(5, 10);
            }
            self->work->state = 10;
            return;
        }
        if (self->unk_58 != NULL) {
            Ov003Vec p;
            p.x = self->pos.x;
            p.y = self->pos.y - self->work->timer * 0xcd;
            p.z = self->pos.z;
            Ov003Br_SetMtx(self->unk_58, p.x, p.y, p.z, self->rot[0], self->rot[1], self->rot[2]);

        }
        t = func_ov000_0218d240(self);
        if (t != NULL) {
            Ov003BrWarp wp;
            Ov003Br_Approach(&wp, t, self);
            wp.unk_14 = 0;
            func_ov000_0218d398(t, self->unk_0c, 7, 1, 0x18, &wp);
        }
        break;
    }
    case 10:
        if (func_ov000_0219bf90() != NULL && !func_ov000_021b4738()) {
            u16 id = 0;
            Ov003BrTgt *t = func_ov000_0218d240(self);
            if (t != NULL) {
                id = t->unk_0e;
            }
            func_020627b4();
            func_020627a0(self->unk_0e, self->unk_0c);
            func_020627dc(1);
            func_020627ec(id);
            {
                u8 *ac = &data_ov000_021ccd54->unk_ac;
                *ac = 1;
                func_ov000_02182590(ac);
            }
        }
        self->work->state++;
        break;
    }
}

}
