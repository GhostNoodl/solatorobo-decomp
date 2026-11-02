#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u16 state;
    u16 timer;
} Ov003FvWork;

typedef struct {
    u8 unk_00[0x14];
    u8 unk_14;
} Ov003FvLv;

typedef struct {
    u8 unk_00[0x44];
    FieldId col44;
    u8 unk_47[0x21];
    FieldId col;
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
    VecFx32 unk_75c;
    u8 unk_768[0xa];
    FieldId unk_772;
    u8 unk_775[0x3af];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003FvPlayer;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 unk_1a;
    u8 unk_1c[0x24];
    Ov003FvWork *work;
    u8 unk_44[0x2c];
    VecFx32 pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[4];
    VecFx32 unk_84;
    u8 unk_90[0xc];
    s32 unk_9c;
    s32 unk_a0;
} Ov003Fv;

extern "C" {

extern Ov003FvCtx *data_ov000_021ccd6c;
extern const s16 FX_SinCosTable_[];
extern void SndMgr_LoadHeapState(SndMgr *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern void func_ov000_0218999c(u8 a, u8 b);
extern void func_ov000_0218996c(u8 a, u8 b);
extern Ov003FvPlayer *func_ov000_0219bf90(void);
extern void func_ov000_021b6b4c(Ov003FvCtx *ctx, u16 a, VecFx32 *v);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_0203cc58(s32 a, s32 b, s32 c);
extern void func_ov000_02188140(FieldState *g, s32 a, s32 b, s32 c);
extern void func_ov000_02188ca0(FieldId *c, s32 a);

static inline BOOL Ov003Fv_HasEvent(FieldState *g, s32 id) {
    s32 i = g->head;
    while (i != g->tail) {
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

static inline FieldId *Ov003Fv_PlCol(Ov003FvPlayer *p) {
    return &p->unk_772;
}

static inline BOOL Ov003Fv_SameCol(const FieldId *a, const FieldId *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

static inline void Ov003Fv_Bgm(SndQueue *q, u16 id) {
    if (q->flag0 == 1 && q->unk_74 == 0xffff && q->unk_72 == id) {
        return;
    }
    q->unk_74 = id;
    q->unk_70 = 0;
}

void func_ov003_021df8fc(Ov003Fv *self) {
    u8 r;
    FieldState *gm;
    Ov003FvPlayer *pl;
    Ov003FvArea *area;
    Ov003FvWork *w;
    u8 g;
    u8 b;
    VecFx32 d;
    VecFx32 v;
    MtxFx33 m;
    FieldId col;
    w = self->work;
    switch (w->state) {
    case 0:
        SndMgr_LoadHeapState(data_02097e4c, 1, 1);
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
                data_ov000_021ccd54->stageFlags = 1;
                r = area->col44.c[0];
                g = area->col44.c[1];
                b = area->col44.c[2];
                {
                    gm = data_ov000_021ccd54;
                    if (r == 0xff) {
                        r = gm->unk_ca.c[0];
                    }
                    if (g == 0xff) {
                        g = gm->unk_ca.c[1];
                    }
                    if (b == 0xff) {
                        b = gm->unk_ca.c[2];
                    }
                }
                func_0203cc58(0x3c000, 2, 0);
                func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
                col.c[0] = r;
                col.c[1] = g;
                col.c[2] = b;
                func_ov000_02188ca0(&col, 1);
            }
            self->work->state++;
        }
        if (self->work->timer == 0x20) {
            Ov003Fv_Bgm(data_02097e48.queue, 0x222);
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
    FieldState *gm;
    Ov003FvPlayer *pl;
    Ov003FvArea *area;
    Ov003FvWork *w;
    u8 g;
    u8 b;
    VecFx32 d;
    VecFx32 v;
    MtxFx33 m;
    FieldId col;
    w = self->work;
    switch (w->state) {
    case 0:
        SndMgr_LoadHeapState(data_02097e4c, 1, 1);
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
                data_ov000_021ccd54->stageFlags = 1;
                r = area->col.c[0];
                g = area->col.c[1];
                b = area->col.c[2];
                {
                    gm = data_ov000_021ccd54;
                    if (r == 0xff) {
                        r = gm->unk_ca.c[0];
                    }
                    if (g == 0xff) {
                        g = gm->unk_ca.c[1];
                    }
                    if (b == 0xff) {
                        b = gm->unk_ca.c[2];
                    }
                }
                func_0203cc58(0x3c000, 2, 0);
                func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
                col.c[0] = r;
                col.c[1] = g;
                col.c[2] = b;
                func_ov000_02188ca0(&col, 1);
            }
            self->work->state++;
        }
        if (self->work->timer == 0x20) {
            Ov003Fv_Bgm(data_02097e48.queue, 0x222);
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
