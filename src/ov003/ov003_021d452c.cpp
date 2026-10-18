#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003KbVec;

typedef struct {
    u16 state;
    u16 timer;
} Ov003KbWork;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x3e];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003KbCtl;

typedef struct {
    u16 unk_00;
    u8 unk_02[2];
    u16 unk_04;
    u16 unk_06;
    u8 unk_08;
    u8 unk_09;
} Ov003KbTgt;

typedef struct {
    u8 unk_00[2];
    s16 unk_02;
    u8 unk_04[6];
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
} Ov003KbB0;

typedef struct {
    u8 unk_00_0 : 4;
    u8 unk_00_4 : 3;
    u8 unk_01;
    u8 unk_02_0 : 1;
} Ov003KbC4;

typedef struct {
    u8 unk_00[0x70];
    Ov003KbVec pos;
} Ov003KbUnit;

typedef struct {
    u8 unk_00[0xc4];
    s16 unk_c4;
    u8 unk_c6[0x1e];
    u32 unk_e4;
} Ov003KbModel;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003KbGame;

typedef struct {
    u8 unk_00[0x38];
    Ov003KbModel *model;
    u8 unk_3c[4];
    Ov003KbWork *work;
    u8 unk_44[4];
    Ov003KbCtl *ctl;
    u8 unk_4c[4];
    Ov003KbTgt *tgt;
    u8 unk_54[0x1c];
    Ov003KbVec pos;
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92[2];
    u8 unk_94_0 : 1;
    u8 unk_94_1 : 2;
    u8 unk_95[3];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003KbB0 *unk_b0;
    u8 unk_b4[0x10];
    Ov003KbC4 *unk_c4;
    u8 unk_c8[0x22];
    u16 unk_ea_0 : 3;
    u8 unk_ec_0 : 1;
    u8 unk_ed;
    u16 unk_ee_0 : 1;
    u16 unk_ee_1 : 1;
    u16 unk_ee_2 : 2;
    u16 unk_ee_4 : 1;
} Ov003Kb;

extern "C" {

extern Ov003KbGame *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern const char *data_ov003_021f7a48[][2];
extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern Ov003KbUnit *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(void *self, Ov003KbUnit *target, s32 a);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern BOOL func_ov000_02191120(void *model);
extern BOOL func_ov000_02191508(void *model);
extern void func_ov000_02191418(void *model, s32 a, s32 b);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern u16 func_ov000_02198da8(Ov003KbCtl *ctl, u16 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049f44(void *mgr, s32 id, Ov003KbVec *pos, s32 a);
extern void *func_02065f88(s32 id, Ov003KbVec *pos);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_ov000_0218ddd4(void *self, Ov003KbVec *v, s32 a);
extern void func_ov000_021987b8(Ov003KbCtl *ctl, s32 a, s32 b, s32 c);

static inline BOOL Ov003Kb_GameBusy(Ov003KbGame *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Kb_GameIsIdle(Ov003KbGame *g) {
    if (Ov003Kb_GameBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Kb_GameIdle(void) {
    Ov003KbGame *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Kb_GameIsIdle(g);
    }
    return TRUE;
}

static inline Ov003KbUnit *Ov003Kb_FindUnit(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov003_021d452c(Ov003Kb *self) {
    Ov003KbUnit *pl;
    Ov003KbWork *w;
    BOOL f;
    if (!Ov003Kb_GameIdle()) {
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        func_ov000_02198360(self->work, 1, 0);
        return;
    }
    pl = Ov003Kb_FindUnit(self->unk_90);
    w = self->work;
    switch (w->state) {
    case 0:
        if (self->unk_ee_2 >= 3) {
            self->unk_ee_2 = 0;
        }
        func_ov000_02190cb0(self->model, data_ov003_021f7a48[self->unk_ee_2][self->unk_ee_4], 0x400, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
        break;
    case 1:
        func_ov000_0218d988(self, pl, self->unk_b0->unk_02);
        if (self->model->unk_c4 == 1) {
            self->work->state = 10;
        }
        break;
    case 10: {
        Ov003KbCtl *ctl;
        BOOL a, b, c;
        f = FALSE;
        if (self->model->unk_c4 >= 10) {
            w->timer = self->model->unk_c4;
        }
        if (self->model->unk_e4 & 0x8000000) {
            func_ov000_02191418(self->model, 3, 0);
        }
        ctl = self->ctl;
        a = FALSE;
        b = FALSE;
        c = FALSE;
        if (ctl->flags & 0x40000000) {
            a = TRUE;
        }
        if (ctl->unk_58 != 0) {
            b = TRUE;
        }
        if (self->unk_c4 != NULL && self->unk_c4->unk_00_4 == 1 && a) {
            if ((u16)(func_ov000_02198da8(ctl, self->unk_98) - self->unk_98 - 0x4c00) < 0x6800) {
                c = TRUE;
            } else {
                a = FALSE;
            }
        }
        if (b || a || c) {
            self->unk_98 += 0x8000;
            self->unk_9c >>= 1;
            self->unk_a4 = 0xc00;
            if (self->unk_a0 > 0) {
                self->unk_a0 = 0;
            }
            self->unk_a8 = 0x52;
        }
        if (c) {
            Ov003KbTgt *t;
            func_ov000_0218996c(0xc, 0x1e);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            self->unk_ec_0 = 1;
            self->unk_94_1 = self->unk_c4->unk_02_0;
            self->tgt->unk_04 = 0xffff;
            t = self->tgt;
            t->unk_06 = 0;
            t->unk_08 = 0;
            t->unk_09 = 0x31;
            func_ov000_02198360(self->work, 0x13, 0);
            break;
        }
        if ((self->unk_a0 == 0 || !(self->ctl->unk_54 & 0x20000000)) && (self->unk_c4 == NULL || self->unk_c4->unk_00_4 == 0)) {
            if (func_ov000_02191120(self->model)) {
                f = TRUE;
            }
        }
        if (self->unk_c4 != NULL && (self->unk_c4->unk_00_4 == 2 || self->unk_c4->unk_00_4 == 5)) {
            Ov003KbWork *w2 = self->work;
            if (w2->timer != 0) {
                w2->timer--;
            }
            if (w2->timer == 0) {
                if (func_ov000_02191120(self->model)) {
                    f = TRUE;
                }
            }
        }
        if (f) {
            const char *name = data_ov003_021f7a60;
            Ov003KbWork *w2;
            if (self->unk_ee_0) {
                name = data_ov003_021f7a66;
            }
            func_ov000_02190cb0(self->model, name, 0xcd, 0);
            func_ov000_021915a0(self->model);
            self->work->state = 0x14;
            w2 = self->work;
            if (w2->timer < 0x1e) {
                w2->timer = 0x1e;
            }
            self->unk_a4 = 0xc00;
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            self->unk_ec_0 = 1;
        }
        if (self->unk_c4 != NULL) {
            self->unk_94_1 = self->unk_c4->unk_02_0;
        }
        break;
    }
    case 0x14:
        self->unk_ec_0 = 1;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            func_ov000_02198360(self->work, 1, 0);
        }
        self->ctl->unk_9a_5 = 1;
        break;
    }
    if (func_ov000_02191508(self->model)) {
        return;
    }
    f = TRUE;
    if (self->unk_c4 != NULL && (u8)(self->unk_c4->unk_00_4 + 0xfc) <= 1) {
        if (pl != NULL) {
            Ov003KbVec v;
            v.x = pl->pos.x;
            v.y = pl->pos.y;
            v.z = pl->pos.z;
            func_ov000_0218ddd4(self, &v, 0);
        }
        f = FALSE;
    } else {
        func_ov000_0218dbe0(self, 0);
        if (self->unk_c4 != NULL && self->unk_c4->unk_00_4 == 1) {
            f = FALSE;
        }
    }
    func_ov000_021987b8(self->ctl, f, 0, 0);
    if (self->unk_a0 < 0) {
        Ov003KbCtl *ctl = self->ctl;
        if (ctl->flags & 0x20000000) {
            self->unk_a0 = 0;
            if (ctl->flags & 0x400) {
                func_02065f88(0x2bc, &self->pos);
                func_02065f88(0x2bd, &self->pos);
                func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
                self->unk_a8 = 0;
                self->unk_9c = 0;
            }
        }
    }
}

}
