#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_022177a0[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void *data_ov000_021ccd64;
extern void *data_0214a420;
extern void func_ov003_021daa6c(void *p, s32 a);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern Ov014V *func_020657b0(void *a, void *b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

void func_ov014_022075f4(Ov014Actor *self) {
    // volatile read keeps the state reload in case 1 (no CSE with the switch value)
    switch (*(volatile u16 *)&self->unk_40->state) {
    case 0:
        func_ov003_021daa6c(FLD(void *, self, 0xdc), 0xfe);
        self->unk_40->state++;
        break;
    case 1:
        if (FLD(s32, self, 0xd4) > 0) {
            Ov014V *o;
            FLD(s32, self, 0xd4) += -0x266;
            if (FLD(s32, self, 0xd4) <= 0) {
                FLD(s32, self, 0xd4) = 0;
            }
            o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xdc), 0xff));
            if (o != NULL) {
                o->v14(FLD(s32, self, 0xd4), FLD(s32, self, 0xd4), FLD(s32, self, 0xd4));
            }
        } else {
            self->unk_40->state++;
        }
        break;
    case 2: {
        u8 c;
        func_ov003_021daa6c(FLD(void *, self, 0xdc), 0xff);
        c = 10;
        func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, &c);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        self->unk_40->state++;
        break;
    }
    }
}

#pragma force_active on
Ov014Actor *func_ov014_0220774c(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_022177a0;
    FLD(s32, self, 0xd0) = 0;
    FLD(void *, self, 0xd8) = NULL;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_02207778(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022177a0;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_022077e8(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022177a0;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02207860(Ov014Actor *self) {
    func_ov000_02194758(self);
    FLD(s32 *, self, 0xd8) = Ov014_NewFx();
    FLD(s32, self, 0xd4) = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

void func_ov014_0220789c(Ov014Actor *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(FLD(void *, self, 0xd8));
}

#define OV014_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

struct Ov014HitBox {
    Ov014Vec min;
    Ov014Vec max;
    u16 rot[3];
    u16 unk_1e;
    u32 unk_20;
    Ov014Vec v;
    s32 unk_30;
};

struct Ov014Swing {
    Ov014Vec v;
    s32 unk_0c;
};

struct Ov014PlFlags {
    u32 b0 : 1;
    u32 b1 : 1;
};

extern Ov014Swing data_ov014_02216a40[];
extern u8 data_ov014_0221764f[];
extern u8 data_ov014_0221765b[];
extern u8 data_ov014_02217640[];
extern u8 data_ov014_022169d4[];
extern u8 data_ov014_02216a1c[];
extern Ov014Vec data_ov014_022169e0;
extern Ov014Vec data_ov014_02216a10;
extern void *data_02097e4c;
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern Ov014V *func_02066774(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *e);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern s32 FX_Div(s32 a, s32 b);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void func_02049f44(void *mgr, s32 id, Ov014Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0219aca8(Ov014Actor *a, Ov014Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov014_0220840c(Ov014Actor *self);
extern u8 *func_ov000_0219bf90(void);
extern void VEC_Normalize(const Ov014Vec *in, Ov014Vec *out);
extern BOOL func_01ffc318(Ov014Vec *a, Ov014Vec *pos, Ov014Vec *min, Ov014Vec *max, u16 *rot);
extern void func_ov000_0219b808(u16 id, Ov014Vec *pos, Ov014HitBox *box, s32 a, s32 b);

static inline void Ov014_HitFrom(Ov014Actor *self, Ov014HitBox *box, Ov014Vec *d, Ov014Vec *from, Ov014Vec *at) {
    d->x = self->pos.x - from->x;
    d->y = self->pos.y - from->y;
    d->z = self->pos.z - from->z;
    d->y = 0;
    VEC_Normalize(d, d);
    box->v.x = d->x = OV014_FXMUL_K(d->x, 0x2b8);
    box->v.y = d->y = OV014_FXMUL_K(d->y, 0x2b8);
    box->v.z = d->z = OV014_FXMUL_K(d->z, 0x2b8);
    box->unk_30 = -1;
    func_ov000_0219b808(self->id, at, box, 0, 0);
}

void func_ov014_022078b4(Ov014Actor *self) {
    Ov014Vec pos;
    Ov014HitBox box;
    Ov014Vec d;
    Ov014Vec v2;
    Ov014Swing *tbl;
    Ov014Actor *t;
    Ov014V *e;
    u8 *pl;
    u8 i;
    tbl = data_ov014_02216a40;
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        u8 *g;
        self->pos.y += 0x266;
        e = func_02066774(data_ov014_02217640, data_ov014_0221764f, 0, &self->pos);
        e->v10(data_ov014_022169d4);
        FLD(u8, e, 0x28) = 0;
        e->v24(0, 0x19a, 0);
        FLD(s32, e, 0xc8) = -1;
        func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xff, e);
        g = (u8 *)data_ov000_021ccd54;
        FLD(Ov014Flags8, g, 0x190).b2 = 1;
        FLD(Ov014Flags8, g, 0x190).b3 = 1;
        FLD(Ov014Flags8, g, 0x190).b4 = 1;
        FLD(u8, g, 0x18d) = 7;
        FLD(u8, g, 0x18e) = 10;
        FLD(u8, g, 0x18f) = 10;
        FLD(u8, g, 0x18c) = 1;
        self->unk_40->state++;
    }
    case 1: {
        s16 n = self->unk_18;
        if (FLD(s32, self, 0xd4) < 0x9000) {
            FLD(s32, self, 0xd4) += 0xf6;
            if (FLD(s32, self, 0xd4) >= 0x9000) {
                FLD(s32, self, 0xd4) = 0x9000;
            }
            e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xff));
            if (e != NULL) {
                e->v0c(FLD(s32, self, 0xd4));
            }
        } else if (n == 3) {
            self->unk_40->state++;
        }
        if (!func_ov003_021daa0c(FLD(void *, self, 0xd8), 0xfd)) {
            e = func_02065f88(0x646, &self->pos);
            e->v0c(0x2000);
            func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xfd, e);
            n = n + 1;
            self->unk_18 = n;
            if (n == 3) {
                MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
                func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
            }
        }
        if (!func_ov003_021daa0c(FLD(void *, self, 0xd8), 0xf8)) {
            e = func_02065f88(0x68, &self->pos);
            e->v0c(0x8000);
            FLD(s32, e, 0x7c) = FX_Div(0x8000, 0x1f000);
            func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xf8, e);
        }
        break;
    }
    case 2:
        if (!func_ov003_021daa0c(FLD(void *, self, 0xd8), 0xfd)) {
            u8 *g = (u8 *)data_ov000_021ccd54;
            FLD(u8, g, 0x18c) = 0;
            FLD(u8, g, 0x18d) = 0;
            FLD(u8, g, 0x18e) = 0;
            FLD(u8, g, 0x18f) = 0;
            e = func_02065f88(0x391, &self->pos);
            e->v20(data_ov014_02216a1c);
            e->v10(data_ov014_022169d4);
            FLD(s32, e, 0x7c) = FX_Div(0x1d000, 0x1f000);
            func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xf9, e);
            self->unk_40->state++;
        }
        break;
    case 3:
        if (FLD(s32, self, 0xd4) > 0) {
            FLD(s32, self, 0xd4) += -0xb33;
            if (FLD(s32, self, 0xd4) <= 0) {
                FLD(s32, self, 0xd4) = 0;
            }
            e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xff));
            if (e != NULL) {
                e->v0c(FLD(s32, self, 0xd4));
            }
            e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xf9));
            if (e != NULL) {
                e->v0c(FLD(s32, e, 0x40) + 0x4cd);
            }
        } else {
            func_ov003_021daa6c(FLD(void *, self, 0xd8), 0xfe);
            func_ov003_021daa6c(FLD(void *, self, 0xd8), 0xff);
            self->unk_40->state++;
        }
        break;
    case 4: {
        Ov014Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 5) {
            func_ov003_021daa6c(FLD(void *, self, 0xd8), 0xf9);
            i = 0;
            e = func_02066774(data_ov014_02217640, data_ov014_0221765b, i, &self->pos);
            e->v10(data_ov014_022169d4);
            FLD(u8, e, 0x28) = i;
            func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xfc, e);
            for (; i < 2; i++) {
                e = func_02065f88(0x68, &self->pos);
                e->v20(&tbl[i]);
                e->v10(data_ov014_022169d4);
                func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xfb - i, e);
            }
            func_02065f88(0x322, &self->pos)->v0c(0x8000);
            func_ov000_0218996c(0x14, 0x32);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 5:
        e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xfc));
        if (e != NULL) {
            s32 v = FLD(s32, e, 0x40);
            if (v < 0xa000) {
                v += 0x1800;
                if (v >= 0xa000) {
                    func_ov000_0218996c(0xf, 0x32);
                    func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
                    func_02049f44(data_02097e4c, 0x7a, &self->pos, 0);
                    func_02049f44(data_02097e4c, 0x5a, &self->pos, 0);
                    v = 0xa000;
                }
                e->v0c(v);
            }
            func_ov000_0219aca8(self, self, FLD(Ov014Param *, self, 0x4c)->unk_08, FLD(u16, FLD(Ov014Param *, self, 0x4c), 0xa), 0, 0, 0x6800, 0, 0x328, 0x1000);
        } else if (!(FLD(u32, self, 0xd0) & 0x200000)) {
            FLD(u32, self, 0xd0) |= 0x200000;
        }
        for (i = 0; i < 2; i++) {
            e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xfb - i));
            if (e != NULL) {
                e->v0c(FLD(s32, e, 0x40) + tbl[i].unk_0c);
            } else if (!(FLD(u32, self, 0xd0) & 0x400000)) {
                FLD(u32, self, 0xd0) |= 0x400000;
            }
        }
        break;
    }
    if ((FLD(u32, self, 0xd0) & 0x400000) && (FLD(u32, self, 0xd0) & 0x200000)) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
    e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xf8));
    if (e != NULL) {
        s32 v = FLD(s32, e, 0x40) + -0x59a;
        if (v <= 0) {
            FLD(s32, e, 0x1c) = 4;
        } else {
            e->v0c(v);
        }
    }
    if (self->unk_40->state > 3) {
        return;
    }
    if (*t->unk_50 == 0) {
        return;
    }
    func_ov014_0220840c(self);
    pos = t->pos;
    box.unk_1e = 2;
    box.unk_20 = 0x20000000;
    box.rot[0] = self->rot[0];
    box.rot[1] = self->rot[1];
    box.rot[2] = self->rot[2];
    pl = func_ov000_0219bf90();
    if (pl != NULL && (FLD(Ov014PlFlags, pl, 0xb24).b1 ? TRUE : FALSE) == TRUE) {
        box.min.x = -0xf000;
        box.min.y = -0x800;
        box.min.z = -0xf000;
        box.max.x = 0xf000;
        box.max.y = 0x800;
        box.max.z = 0xf000;
        Ov014_HitFrom(self, &box, &d, &pos, &self->pos);
    } else if (pl != NULL && (FLD(Ov014PlFlags, pl, 0xb24).b1 ? TRUE : FALSE) == FALSE) {
        box.min.x = -0x1000;
        box.min.y = -0x800;
        box.min.z = -0x1000;
        box.max.x = 0x1000;
        box.max.y = 0x800;
        box.max.z = 0x1000;
        v2 = FLD(Ov014Vec, pl, 0x75c);
        if (func_01ffc318(&v2, &self->pos, &data_ov014_022169e0, &data_ov014_02216a10, self->rot)) {
            Ov014_HitFrom(self, &box, &d, &v2, &v2);
        }
        if (func_01ffc318(&pos, &self->pos, &data_ov014_022169e0, &data_ov014_02216a10, self->rot)) {
            Ov014_HitFrom(self, &box, &d, &pos, &pos);
        }
    }
}

}
