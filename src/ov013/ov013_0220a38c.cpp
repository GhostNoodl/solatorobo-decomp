#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220bf4c;
extern void *func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);

struct Ov013Pair89 {
    u8 a;
    u8 b;
};

struct Ov013Sub50a {
    u8 unk_00[0x4];
    u16 unk_04;
    u8 unk_06[0x2];
    Ov013Pair89 unk_08;
};

static inline void Ov013_SetPair(Ov013Pair89 *d, const Ov013Pair89 *s, u8 b) {
    d->a = s->a;
    d->b = b;
}

void func_ov013_0220a38c(Ov013Actor *self) {
    Ov013Sub40 *q;
    if ((((Ov013Sub50a *)self->unk_50)->unk_04 >> 12) == 5) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    q = self->unk_40;
    if (q->state == 0) {
        Ov013Sub50a *p;
        FLD(Ov013Vec, self, 0xb8) = self->pos;
        p = (Ov013Sub50a *)self->unk_50;
        if ((u8)(p->unk_08.b + 0xf0) <= 1) {
            Ov013_SetPair(&p->unk_08, &p->unk_08, 0x20);
        }
    }
    func_ov003_021d5348(self);
    if (self->unk_40->unk_13 == 4) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

void func_ov013_0220a428(Ov013Actor *self) {
    self->v80();
}

Ov013Actor *func_ov013_0220a43c(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a458(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

void func_ov013_0220a46c(Ov013Actor *self) {
    self->v7c();
}

Ov013Actor *func_ov013_0220a480(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_0220a494(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a4b0(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_0220a4c4(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a4e0(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220bf4c;
    FLD(u16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = 0;
    return self;
}

void func_ov013_0220a518(Ov013Actor *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0xb, 0);
    self->unk_48->unk_60 = -0x800;
    self->unk_48->unk_48 = self->unk_64;
}

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern char data_ov013_0220bfdc[];
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_0203f324(void *p);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov013Actor *a);
extern Ov013Actor *func_ov000_0219be1c(s32 kind, Ov013Vec *pos, u16 *rot, u16 id, u16 owner);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov013Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov013_Sqrt2(s64 sq) {
    OV013_SQRTCNT = 1;
    OV013_SQRT_PARAM = (u64)(sq << 2);
    while (OV013_SQRTCNT & 0x8000) {
    }
    return (s32)(OV013_SQRT_RESULT + 1) >> 1;
}

static inline s32 Ov013_DistXZ3(const Ov013Vec *a, const Ov013Vec *b) {
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt2(sq);
}

static inline Ov013Actor *Ov013_GetActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_0220a554(Ov013Actor *self) {
    if (Ov013_GetActor(self->unk_90) == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        s32 d;
        u16 ang;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220bfdc, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        d = Ov013_DistXZ3(&self->pos, &FLD(Ov013Vec, self, 0xd4));
        ang = FX_Atan2(d, FLD(s32, self, 0xd8) - self->pos.y);
        self->unk_9c = Ov013_FxMul(OV013_SIN(ang), 0x214);
        self->unk_a0 = Ov013_FxMul(OV013_COS(ang), 0x214);
        self->rot[0] = FX_Atan2(self->pos.y - FLD(s32, self, 0xd8), d);
        self->unk_98 = self->rot[1];
        FLD(u16, self, 0xce) = 0x12c;
        if (self->unk_48 != NULL) {
            Ov013Sub48 *m;
            self->unk_48->unk_30 = 0;
            m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
            if (FLD(s32, self, 0xd0) != 0) {
                self->unk_48->unk_38 = Ov013_FxMul(FLD(s32, self, 0xd0), self->unk_64);
            }
        }
        if (self->unk_44 != NULL) {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->unk_40->state++;
    }
    case 1: {
        Ov013Sub48 *m;
        func_ov000_0218dbe0(self, 0);
        if (FLD(u16, self, 0xce)-- == 0) {
            func_ov000_02198360(self->unk_40, 10, 0);
            return;
        }
        m = self->unk_48;
        if (m == NULL) {
            return;
        }
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x20000000) {
            Ov013V *e = func_02065f88(0x130, &self->pos);
            Ov013Actor *pl;
            e->v0c(FLD(s32, self, 0xd0));
            pl = func_ov000_0219bf90();
            if (pl != NULL && !func_ov000_021b4738(pl)) {
                Ov013Actor *a = func_ov000_0219be1c(0x4813, &self->pos, self->rot, FLD(u16, FLD(void *, self, 0x4c), 0x1c), self->unk_90);
                if (a != NULL) {
                    FLD(s32, a, 0xd4) = FLD(s32, self, 0xd0);
                }
            }
            func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
            func_ov000_02198360(self->unk_40, 10, 0);
            m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            self->unk_9c = 0;
            return;
        }
        if (func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, NULL, 0, self->unk_64, 0, 0x130, FLD(s32, self, 0xd0) >> 1)) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    }
}

}
