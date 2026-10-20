#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 flags;
    u8 pad4[0xc];
    VecFx32 pos;
    u8 pad1c[8];
    VecFx32 ofs;
    u8 pad30[8];
    VecFx32 tgt;
    u8 pad44[0x10];
} Eff0216ca70;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 cnt : 4;
    u32 rest : 25;
    s32 state;
    s32 unk_08;
    void *model;
    Eff0216ca70 *eff;
    s32 unk_14;
    u8 pad18[4];
    u16 unk_1c;
    u8 pad1e[0xa];
    u16 unk_28;
    u16 unk_2a;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
} Obj0216ca70;

typedef struct {
    u8 pad[0x68];
    s32 h;
    u8 pad6c[4];
    VecFx32 pos;
} Pl0216ca70;

extern "C" {

extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd30;
extern s32 data_02097d78[5];
extern VecFx32 data_ov000_021c9af8;
extern void *data_0208cc94;
extern void *data_0208cc88;
extern void *data_ov000_021ccd64;
BOOL func_0203dc9c(void *node, BOOL recurse);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_021705a0(void *p, s32 a);
void func_ov000_021c2114(void *p);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c34(void *a, int b, void *c, void *d);
BOOL func_02054f10(void *a, s32 b);
void func_ov000_0216c800(void);
void func_ov000_0216d474(Obj0216ca70 *self);
s32 FX_Div(s32 a, s32 b);
Pl0216ca70 *func_ov000_0219bf90(void);
s32 func_ov000_0218c040(void *mgr, s32 max, VecFx32 *out, s32 kind, u16 id);
s32 func_0204061c(s32 *out, const VecFx32 *pos);
void func_ov000_021c194c(Eff0216ca70 *p);

static inline BOOL LoGBusy(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL LoD78Idle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

static inline BOOL Busy(void) {
    BOOL r;
    void *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 9)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0xa)) {
        r = TRUE;
    } else if (LFLD(void *, mgr, 0x11c) == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021705a0(LFLD(void *, mgr, 0x11c), 0);
    }
    return r;
}

static inline s32 MulK(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 DistSq(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    return (s32)((((s64)dx * dx + (s64)dy * dy + (s64)dz * dz) + 0x800) >> 12);
}

BOOL func_ov000_0216ca70(Obj0216ca70 *self) {
    VecFx32 pts[0x20];
    s32 i;
    s32 scr[2];
    s32 best;
    Pl0216ca70 *pl;
    Eff0216ca70 *e;
    VecFx32 *p;
    void *res;
    void *m;
    s32 n;
    s32 maxd;
    s32 d;
    s32 v;
    s32 x;
    s32 y;
    s32 z;
    u16 id;

    if (func_0203dc9c(data_ov000_021ccd54 + 8, TRUE)) {
        self->b2 = 0;
        self->cnt = 0;
        self->state = 4;
    } else if (!self->b0 && !LoGBusy(data_ov000_021ccd54) && !Busy() && LoD78Idle()) {
        if (self->cnt++ > 3) {
            self->cnt = 4;
            self->b2 = 1;
        }
    } else if (self->state == 7) {
        self->b2 = 0;
        self->cnt = 0;
    }
    switch (self->state) {
    case 2:
        self->state = 4;
        break;
    case 3:
        return FALSE;
    case 4:
        self->b1 = 0;
        self->unk_30 = 0x1000;
        self->unk_2c = 0;
        if (self->b2) {
            self->b1 = 1;
            self->state = 5;
        } else if (self->b0) {
            self->state = 3;
        }
        break;
    case 5:
        self->state = 6;
        if (self->eff == NULL && self->model == NULL) {
            id = self->unk_1c;
            self->unk_2a = id;
            switch (id >> 12) {
            case 4:
                if (id == 0x400a) {
                    self->unk_28 = 0xf;
                } else {
                    self->unk_28 = 0xffff;
                }
                break;
            case 1:
            case 2:
            case 3:
            case 5:
            case 6:
                self->unk_28 = 0xffff;
                break;
            }
            if (self->unk_08 != 0) {
                VecFx32 ofs = data_ov000_021c9af8;
                e = (Eff0216ca70 *)func_0203dd9c(0x54);
                if (e) {
                    func_ov000_021c2114(e);
                }
                self->eff = e;
                e->flags |= 4;
                self->eff->ofs = ofs;
            }
            if (self->unk_28 != 0xffff) {
                res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
                m = func_0203dd9c(0x160);
                if (m) {
                    void *name = data_0208cc88;
                    func_02041218((u8 *)m + 0x88);
                    func_02041440(m, name, 0);
                }
                self->model = m;
                func_020417e0(m, res);
                LFLD(u32, self->model, 0x6c) |= 2;
                func_02041d9c(self->model, 0, 0xd);
                func_02041d9c(self->model, 0, 0xe);
                func_02041d9c(self->model, 0, self->unk_28);
                func_02041d9c(self->model, 0, 6);
                func_02041d9c(self->model, 0, 8);
                func_02041c34(self->model, 6, (void *)func_ov000_0216c800, self);
            }
            func_ov000_0216d474(self);
        }
        break;
    case 6:
        if (self->model == NULL || func_02054f10(self->model, 0xffff)) {
            self->unk_2c = 0;
            self->unk_30 = 0x1000;
            self->state = 8;
        }
        break;
    case 8:
        self->unk_30 = FX_Div(++self->unk_2c << 12, 0x19000);
        if (self->unk_30 >= 0x1000) {
            self->unk_30 = 0x1000;
            self->unk_2c = 0;
            if (self->b1) {
                self->state = 7;
            } else {
                self->state = 4;
                break;
            }
        }
        self->unk_30 = FX_SinCosTable_[((self->unk_30 << 14) >> 16) * 2];
        if (self->b1) {
            self->unk_30 = 0x1000 - self->unk_30;
        }
    case 7:
        if (++self->unk_34 < 0x18) {
            v = self->unk_38;
            self->unk_38 = v + MulK(0x3000 - v, 0x148);
        } else if (self->unk_34 >= 0x40) {
            self->unk_34 = 0;
            self->unk_38 = 0;
        } else {
            v = self->unk_38;
            self->unk_38 = v + MulK(-v, 0xcd);
        }
        if (!self->b2) {
            self->b1 = 0;
            self->state = 8;
        }
        break;
    }
    if (self->eff != NULL) {
        if (self->b2) {
            self->eff->flags |= 2;
            pl = func_ov000_0219bf90();
            {
                VecFx32 c;
                c.x = pl->pos.x;
                c.y = pl->pos.y + LO_FX_MUL(pl->h, 0xc00);
                c.z = pl->pos.z;
                self->eff->pos = *(VecFx32 *)&c;
                n = func_ov000_0218c040(data_ov000_021ccd64, 0x20, pts, self->unk_2a >> 12, self->unk_2a);
                if (n != 0) {
                    maxd = self->unk_14;
                    for (i = 0, best = 0; i < n; i++) {
                        d = DistSq(&c, &pts[i]);
                        if (maxd > d) {
                            best = i + 1;
                            maxd = d;
                        }
                    }
                    if (best != 0) {
                        z = func_0204061c(scr, &pts[best - 1]);
                        if (z < -0xf000 || z > 0 || scr[0] < -0x20 || scr[0] > 0x120 || scr[1] < -0x20 || scr[1] > 0x100) {
                            e = self->eff;
                            p = &pts[best - 1];
                            e->tgt.x = p->x;
                            e->tgt.y = p->y;
                            e->tgt.z = p->z;
                        } else {
                            self->eff->flags &= ~2;
                        }
                    } else {
                        self->eff->flags &= ~2;
                    }
                } else {
                    self->eff->flags &= ~2;
                }
            }
        } else {
            self->eff->flags &= ~2;
        }
        func_ov000_021c194c(self->eff);
    }
    return TRUE;
}

}
