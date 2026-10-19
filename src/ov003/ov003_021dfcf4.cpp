#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003FvVec;

typedef struct {
    s32 m[3][3];
} Ov003FvMtx;

typedef struct {
    u8 r, g, b;
} Ov003FvCol;

typedef struct {
    u16 state;
    u16 timer;
} Ov003FvWork;

typedef struct {
    s32 state;
    u8 unk_04[0xc];
    s32 queue[16];
    u8 unk_50[0x40];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
    u8 unk_ad[0x1d];
    Ov003FvCol unk_ca;
} Ov003FvGame;

typedef struct {
    u8 unk_00[0x14];
    u8 unk_14;
} Ov003FvLv;

typedef struct {
    u8 unk_00[0x44];
    Ov003FvCol col44;
    u8 unk_47[0x21];
    Ov003FvCol col;
} Ov003FvArea;

typedef struct {
    u8 unk_00[0x14];
    Ov003FvLv *lv;
    Ov003FvArea *area;
    u8 unk_1c[0x1d4];
    u16 unk_1f0;
} Ov003FvCtx;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x74e];
    Ov003FvVec unk_75c;
    u8 unk_768[0xa];
    Ov003FvCol unk_772;
    u8 unk_775[0x3af];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003FvPlayer;

typedef struct {
    u16 flag0 : 1;
    u8 unk_02[0x6e];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Ov003FvSnd;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 unk_1a;
    u8 unk_1c[0x24];
    Ov003FvWork *work;
    u8 unk_44[0x2c];
    Ov003FvVec pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[4];
    Ov003FvVec unk_84;
    u8 unk_90[0xc];
    s32 unk_9c;
    s32 unk_a0;
} Ov003Fv;

extern "C" {

extern Ov003FvGame *data_ov000_021ccd54;
extern Ov003FvCtx *data_ov000_021ccd6c;
extern Ov003FvSnd *data_02097e48;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
extern void func_02049564(void *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern void func_ov000_0218999c(s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern Ov003FvPlayer *func_ov000_0219bf90(void);
extern void func_ov000_021b6b4c(Ov003FvCtx *ctx, u16 a, Ov003FvVec *v);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_0203cc58(s32 a, s32 b, s32 c);
extern void func_ov000_02188140(Ov003FvGame *g, s32 a, s32 b, s32 c);
extern void func_ov000_02188ca0(Ov003FvCol *c, s32 a);
extern void MTX_RotY33_(Ov003FvMtx *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov003FvVec *v, const Ov003FvMtx *m, Ov003FvVec *out);

static inline BOOL Ov003Fv_HasEvent(Ov003FvGame *g, s32 id) {
    s32 i = g->unk_90;
    while (i != g->unk_94) {
        if (g->queue[i] == id) {
            return TRUE;
        }
        i++;
        if (i >= 16) {
            i = 0;
        }
    }
    return FALSE;
}

static inline u8 Ov003Fv_Level(Ov003FvLv *lv) {
    return lv != NULL ? lv->unk_14 : 0;
}

static inline Ov003FvCol *Ov003Fv_PlCol(Ov003FvPlayer *p) {
    return &p->unk_772;
}

static inline BOOL Ov003Fv_SameCol(const Ov003FvCol *a, const Ov003FvCol *b) {
    BOOL r = FALSE;
    if (a->r == b->r && a->g == b->g && a->b == b->b) {
        r = TRUE;
    }
    return r;
}

static inline void Ov003Fv_Bgm(Ov003FvSnd *q, u16 id) {
    if (q->flag0 == 1 && q->unk_74 == 0xffff && q->unk_72 == id) {
        return;
    }
    q->unk_74 = id;
    q->unk_70 = 0;
}

void func_ov003_021df8fc(Ov003Fv *self) {
    u8 r;
    Ov003FvGame *gm;
    Ov003FvPlayer *pl;
    Ov003FvArea *area;
    Ov003FvWork *w;
    u8 g;
    u8 b;
    Ov003FvVec d;
    Ov003FvVec v;
    Ov003FvMtx m;
    Ov003FvCol col;
    w = self->work;
    switch (w->state) {
    case 0:
        func_02049564(data_02097e4c, 1, 1);
        func_ov000_02187a20(data_ov000_021ccd54, 2);
        self->unk_84.x = 0;
        self->unk_84.y = 0;
        self->unk_84.z = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->work->state++;
        return;
    case 1:
        if (Ov003Fv_HasEvent(data_ov000_021ccd54, 0x25)) {
            return;
        }
        func_ov000_0218996c(5, 0xf);
        func_02049a48(data_02097e4c, 0x46, -1, -1, -1);
        self->work->state++;
        return;
    case 2:
        w->timer++;
        if (w->timer > 300 && self->unk_1a == 0) {
            area = data_ov000_021ccd6c->area;
            if (Ov003Fv_Level(data_ov000_021ccd6c->lv) >= 2) {
                pl = func_ov000_0219bf90();
                if (!(pl->unk_b24_1 ? TRUE : FALSE) && Ov003Fv_SameCol(&data_ov000_021ccd54->unk_ca, Ov003Fv_PlCol(pl))) {
                    data_ov000_021ccd6c->unk_1f0 = self->unk_0e;
                    d.x = pl->unk_75c.x;
                    d.y = pl->unk_75c.y;
                    d.z = pl->unk_75c.z;
                    d.x -= self->pos.x;
                    d.y -= self->pos.y;
                    d.z -= self->pos.z;
                    func_ov000_021b6b4c(data_ov000_021ccd6c, pl->unk_0c, &d);
                }
                func_020627a0(self->unk_0e, self->unk_0c);
                func_020627dc(4);
                data_ov000_021ccd54->unk_ac = 1;
                r = area->col44.r;
                g = area->col44.g;
                b = area->col44.b;
                {
                    gm = data_ov000_021ccd54;
                    if (r == 0xff) {
                        r = gm->unk_ca.r;
                    }
                    if (g == 0xff) {
                        g = gm->unk_ca.g;
                    }
                    if (b == 0xff) {
                        b = gm->unk_ca.b;
                    }
                }
                func_0203cc58(0x3c000, 2, 0);
                func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
                col.r = r;
                col.g = g;
                col.b = b;
                func_ov000_02188ca0(&col, 1);
            }
            self->work->state++;
        }
        if (self->work->timer == 0x20) {
            Ov003Fv_Bgm(data_02097e48, 0x222);
        }
        if (self->work->timer == 0x60) {
            func_02049a48(data_02097e4c, 0x223, -1, -1, -1);
        }
        if ((self->work->timer & 0x3f) == 0) {
            func_ov000_0218999c(3, 10);
        }
        break;
    }
    self->unk_9c += 2;
    if (self->unk_9c > 0x266) {
        self->unk_9c = 0x266;
    }
    self->unk_a0 += self->unk_9c;
    if (self->unk_a0 > 0xc800) {
        self->unk_a0 -= 0xc800;
    }
    MTX_RotY33_(&m, FX_SinCosTable_[(self->rotY >> 4) * 2], FX_SinCosTable_[(self->rotY >> 4) * 2 + 1]);
    v.x = -self->unk_a0;
    v.y = 0;
    v.z = 0;
    MTX_MultVec33(&v, &m, &self->unk_84);
}


void func_ov003_021dfcf4(Ov003Fv *self) {
    u8 r;
    Ov003FvGame *gm;
    Ov003FvPlayer *pl;
    Ov003FvArea *area;
    Ov003FvWork *w;
    u8 g;
    u8 b;
    Ov003FvVec d;
    Ov003FvVec v;
    Ov003FvMtx m;
    Ov003FvCol col;
    w = self->work;
    switch (w->state) {
    case 0:
        func_02049564(data_02097e4c, 1, 1);
        func_ov000_02187a20(data_ov000_021ccd54, 2);
        self->unk_84.x = 0;
        self->unk_84.y = 0;
        self->unk_84.z = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->work->state++;
        return;
    case 1:
        if (Ov003Fv_HasEvent(data_ov000_021ccd54, 0x25)) {
            return;
        }
        func_ov000_0218999c(5, 0xf);
        func_02049a48(data_02097e4c, 0x46, -1, -1, -1);
        self->work->state++;
        return;
    case 2:
        w->timer++;
        if (w->timer > 300 && self->unk_1a == 0) {
            area = data_ov000_021ccd6c->area;
            if (Ov003Fv_Level(data_ov000_021ccd6c->lv) >= 3) {
                pl = func_ov000_0219bf90();
                if (!(pl->unk_b24_1 ? TRUE : FALSE) && Ov003Fv_SameCol(&data_ov000_021ccd54->unk_ca, Ov003Fv_PlCol(pl))) {
                    data_ov000_021ccd6c->unk_1f0 = self->unk_0e;
                    d.x = pl->unk_75c.x;
                    d.y = pl->unk_75c.y;
                    d.z = pl->unk_75c.z;
                    d.x -= self->pos.x;
                    d.y -= self->pos.y;
                    d.z -= self->pos.z;
                    func_ov000_021b6b4c(data_ov000_021ccd6c, pl->unk_0c, &d);
                }
                func_020627a0(self->unk_0e, self->unk_0c);
                func_020627dc(4);
                data_ov000_021ccd54->unk_ac = 1;
                r = area->col.r;
                g = area->col.g;
                b = area->col.b;
                {
                    gm = data_ov000_021ccd54;
                    if (r == 0xff) {
                        r = gm->unk_ca.r;
                    }
                    if (g == 0xff) {
                        g = gm->unk_ca.g;
                    }
                    if (b == 0xff) {
                        b = gm->unk_ca.b;
                    }
                }
                func_0203cc58(0x3c000, 2, 0);
                func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
                col.r = r;
                col.g = g;
                col.b = b;
                func_ov000_02188ca0(&col, 1);
            }
            self->work->state++;
        }
        if (self->work->timer == 0x20) {
            Ov003Fv_Bgm(data_02097e48, 0x222);
        }
        if (self->work->timer == 0x60) {
            func_02049a48(data_02097e4c, 0x223, -1, -1, -1);
        }
        if ((self->work->timer & 0x3f) == 0) {
            func_ov000_0218999c(3, 10);
        }
        break;
    }
    self->unk_9c += 2;
    if (self->unk_9c > 0x266) {
        self->unk_9c = 0x266;
    }
    self->unk_a0 += self->unk_9c;
    if (self->unk_a0 > 0xc800) {
        self->unk_a0 -= 0xc800;
    }
    MTX_RotY33_(&m, FX_SinCosTable_[(self->rotY >> 4) * 2], FX_SinCosTable_[(self->rotY >> 4) * 2 + 1]);
    v.x = self->unk_a0;
    v.y = 0;
    v.z = 0;
    MTX_MultVec33(&v, &m, &self->unk_84);
}

}
