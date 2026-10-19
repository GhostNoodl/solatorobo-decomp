#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_0221722c[];
extern Ov014Vec data_ov014_022164a0[];
extern void func_ov003_021daab0(void *p);
extern void func_ov000_0219763c(void *self);
extern void func_ov000_02194074(void *self);
extern void func_ov003_021da940(void *p);
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);

void func_ov014_021fc220(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov003_021daab0(FLD(void *, self, 0xd0));
    }
    func_ov000_0219763c(self);
}

#pragma force_active on
Ov014Actor *func_ov014_021fc24c(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_0221722c;
    FLD(s32, self, 0xf8) = 0;
    FLD(void *, self, 0x100) = NULL;
    FLD(s32, self, 0xf4) = 0;
    FLD(u8, self, 0xfd) = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free100(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x100) != NULL) {
        void *p = FLD(void *, self, 0x100);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0x100) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_021fc280(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_0221722c;
    Ov014_Free100(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_021fc2f0(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_0221722c;
    Ov014_Free100(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_021fc368(Ov014Actor *self) {
    s32 *p;
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(u8, self, 0xfc) = self->unk_18;
    FLD(s32, self, 0xdc) = 0x1000;
    FLD(s32, self, 0xe0) = 0x1000;
    FLD(s32, self, 0xe4) = 0x1000;
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
    }
    self->unk_44->unk_1c = Ov014_FxMul(self->unk_64, 0x2800);
    p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(s32 *, self, 0x100) = p;
    m = self->unk_38;
    {
        s32 y = FLD(Ov014Vec, m, 0xa8).y;
        s32 z = FLD(Ov014Vec, m, 0xa8).z;
        FLD(Ov014Vec, self, 0xe8).x = FLD(Ov014Vec, m, 0xa8).x;
        FLD(Ov014Vec, self, 0xe8).y = y;
        FLD(Ov014Vec, self, 0xe8).z = z;
    }
    Ov014_VecCopy(&FLD(Ov014Vec, m, 0xa8), &data_ov014_022164a0[4]);
    func_ov000_02198360(self->unk_40, 1, 0);
}

extern Ov014Vec data_ov014_022164dc;
extern Ov014Vec data_ov014_022164b8;
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void func_ov003_021dacfc(void *p);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern u16 FX_Atan2(s32 x, s32 z);
extern Ov014Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014f_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_021fc464(Ov014Actor *self) {
    switch (FLD(u8, self, 0xfc)) {
    case 0: {
        Ov014Sub40 *s = self->unk_40;
        switch (s->state) {
        case 0: {
            Ov014V *e;
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            e = func_02065f88(0x322, &self->pos);
            FLD(s32, e, 0x3c) = 0x2000;
            func_ov003_021da9ac(FLD(void *, self, 0x100), 0, e);
            {
                Ov014Vec v = {0, 0, 0};
                v.x = func_02040528(0x9000);
                v.z = func_02040528(0x259a);
                VEC_Add(&v, &data_ov014_022164dc, &FLD(Ov014Vec, self, 0xd0));
            }
            {
                s64 sq;
                dx = self->pos.x - FLD(s32, self, 0xd0);
                dz = self->pos.z - FLD(s32, self, 0xd8);
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, FLD(s32, self, 0xd4) - self->pos.y);
            self->unk_9c = Ov014f_FxMul64(OV014_SIN(a), 0x4cd);
            self->unk_a0 = Ov014f_FxMul64(OV014_COS(a), 0x4cd);
            self->rot[0] = FX_Atan2(self->pos.y - FLD(s32, self, 0xd4), r);
            self->unk_40->state++;
            break;
        }
        case 1:
            FLD(s32, self, 0xf4) += 0xcd;
            if (FLD(s32, self, 0xf4) >= FLD(s32, self, 0xe8)) {
                FLD(s32, self, 0xf4) = FLD(s32, self, 0xe8);
                s->state++;
            }
            {
                u8 *m = (u8 *)self->unk_38;
                s32 f = FLD(s32, self, 0xf4);
                FLD(s32, m, 0xa8) = f;
                FLD(s32, m, 0xac) = f;
                FLD(s32, m, 0xb0) = f;
            }
            break;
        case 2:
            if (!func_ov003_021daa0c(FLD(void *, self, 0x100), 0)) {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = true;
                n->unk_22_1 = true;
                func_ov000_02198360(self->unk_40, 0xb, 0);
            }
            break;
        }
        break;
    }
    case 1: {
        Ov014Sub40 *s = self->unk_40;
        switch (s->state) {
        case 0: {
            Ov014V *e;
            Ov014Actor *t;
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            VEC_Add(&self->pos, &data_ov014_022164b8, &self->pos);
            e = func_02065f88(0x322, &self->pos);
            e->v0c(0x2000);
            FLD(s32, e, 0xc8) = -1;
            func_ov003_021da9ac(FLD(void *, self, 0x100), 0xff, e);
            {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 0;
                n->unk_22_1 = 0;
            }
            t = data_ov000_021ccd68 != NULL ? func_ov000_0218e6d0(data_ov000_021ccd68, 0x1000, 0x1000) : NULL;
            FLD(s32, self, 0xd0) = t->pos.x;
            FLD(s32, self, 0xd4) = t->pos.y;
            FLD(s32, self, 0xd8) = t->pos.z;
            {
                s64 sq;
                dx = self->pos.x - FLD(s32, self, 0xd0);
                dz = self->pos.z - FLD(s32, self, 0xd8);
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, FLD(s32, self, 0xd4) - self->pos.y);
            self->unk_9c = Ov014f_FxMul64(OV014_SIN(a), 0x4cd);
            self->unk_a0 = Ov014f_FxMul64(OV014_COS(a), 0x4cd);
            self->rot[0] = FX_Atan2(self->pos.y - FLD(s32, self, 0xd4), r);
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x77, &self->pos, 0);
            self->unk_40->state++;
            break;
        }
        case 1:
            FLD(s32, self, 0xf4) += 0x52;
            if (FLD(s32, self, 0xf4) >= FLD(s32, self, 0xe8) + 0x1000) {
                s->timer = 0;
                self->unk_40->state++;
            }
            {
                u8 *m = (u8 *)self->unk_38;
                s32 f = FLD(s32, self, 0xf4);
                FLD(s32, m, 0xa8) = f;
                FLD(s32, m, 0xac) = f;
                FLD(s32, m, 0xb0) = f;
            }
            {
                Ov014Sub40 *w = self->unk_40;
                w->timer++;
                if (w->timer % 15 == 0) {
                    u8 *m = (u8 *)self->unk_38;
                    FLD(u16, m, 0xb6) = 0x7c1f;
                    FLD(u16, m, 0xb8) = 0x7c1f;
                    FLD(u16, m, 0xba) = 6;
                    FLD(u16, m, 0xbc) = 5;
                }
            }
            break;
        case 2: {
            u16 t;
            s->timer++;
            t = s->timer;
            if (t > 100) {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = true;
                n->unk_22_1 = true;
                self->unk_40->timer = 0;
                func_ov000_02198360(self->unk_40, 0xb, 0);
            }
            if (t % 15 == 0) {
                u8 *m = (u8 *)self->unk_38;
                FLD(u16, m, 0xb6) = 0x7c1f;
                FLD(u16, m, 0xb8) = 0x7c1f;
                FLD(u16, m, 0xba) = 6;
                FLD(u16, m, 0xbc) = 5;
            }
            break;
        }
        }
        break;
    }
    }
    func_ov003_021dacfc(FLD(void *, self, 0x100));
}

}
