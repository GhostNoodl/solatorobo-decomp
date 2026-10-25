#include "ov010/ov010.h"

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010St40 {
    u16 state;
    u16 timer;
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov010_0220f024[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern const Ov010Blk12 data_ov010_0220f0c0;
extern const Ov010Blk12 data_ov010_0220f0cc;
extern u8 *data_ov000_021ccd54;
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov000_02191618(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void *func_ov000_0219bf90(void);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(Ov010Vec *v, Ov010Mtx33 *m, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Normalize(const Ov010Vec *in, Ov010Vec *out);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d988(void *self, void *other, s32 a);
extern Ov010V *func_02066774(void *a, void *b, s32 c, void *d);
extern Ov010V *func_ov003_021da788(s32 id, void *self, Ov010Vec *ofs);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218dbe0(void *self, s32 a);

static inline s32 Ov010f_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010f_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33 m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010f_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline Ov010Vec Ov010_Center(u8 *self) {
    Ov010Vec v;
    v.x = FLD(s32, self, 0x70);
    v.y = FLD(s32, self, 0x74) + FLD(s32, self, 0x68) / 2;
    v.z = FLD(s32, self, 0x78);
    return v;
}

static inline void Ov010_ClearSpeed(u8 *self) {
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_02205444(u8 *self) {
    Ov010St40 *st = FLD(Ov010St40 *, self, 0x40);
    FLD(u8, self, 0xf2) = 1;
    switch (st->state) {
    case 0: {
        u8 k;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[2], 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        func_ov003_021d8a7c(FLD(void *, self, 0x118), 0);
        k = FLD(u8, self, 0x171);
        switch (k) {
        case 1:
            FLD(Ov010St40 *, self, 0x40)->state = 10;
            break;
        case 2:
            FLD(Ov010St40 *, self, 0x40)->state = 0x14;
            break;
        }
        func_02049f44(data_02097e4c, 0x36, self + 0x70, 0);
        break;
    }
    case 10: {
        Ov010Vec v;
        Ov010Vec d;
        Ov010Vec *t = FLD(Ov010Vec *, self, 0xf8);
        u16 ang;
        s32 y;
        d.x = FLD(s32, self, 0x70) - t->x;
        d.y = FLD(s32, self, 0x74) - t->y;
        d.z = FLD(s32, self, 0x78) - t->z;
        ang = func_ov003_021d9c38(&d);
        t = FLD(Ov010Vec *, self, 0xf8);
        y = t->y;
        Ov010f_SetRot(&v, FLD(s32, t, 0x10), ang);
        VEC_Add(&v, t, &v);
        v.y = y;
        FLD(s32, self, 0xb8) = v.x;
        FLD(s32, self, 0xbc) = v.y;
        FLD(s32, self, 0xc0) = v.z;
        FLD(s32, self, 0x150) = v.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = v.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = v.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        {
            Ov010_ClearSpeed(self);
            Ov010Vec c = Ov010_Center(self);
            func_02065f88(0x5e2, &c)->v0c(0x3000);
        }
        FLD(Ov010St40 *, self, 0x40)->state = 0xb;
        break;
    }
    case 0xb:
        func_ov010_02207828(self);
        if (FLD(Ov010St40 *, self, 0x40)->timer % 30 == 0) {
            func_02065f88(0x66, &FLD(Ov010Vec, self, 0x70))->v0c(0x2800);
        }
        FLD(Ov010St40 *, self, 0x40)->timer++;
        st = FLD(Ov010St40 *, self, 0x40);
        if (st->timer > 0x3c) {
            st->timer = 0;
            FLD(Ov010St40 *, self, 0x40)->state = 0x1e;
        }
        func_ov000_0218d988(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x14:
        st->timer++;
        st = FLD(Ov010St40 *, self, 0x40);
        if (st->timer > 0xf) {
            st->timer = 0;
            FLD(Ov010St40 *, self, 0x40)->state = 0x1e;
        }
        func_ov000_0218d988(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x1e: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010Vec c2;
        Ov010V *o2;
        *(Ov010Blk12 *)&a = data_ov010_0220f0c0;
        *(Ov010Blk12 *)&b = data_ov010_0220f0cc;
        func_ov003_021d9980(&c2, FLD(u16, self, 0x7e), &b);
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        o2 = func_02066774(data_ov010_0220f024[0xc], data_ov010_0220f024[0xa], 0, self + 0x70);
        FLD(u8, o2, 0x28) = 0;
        o2->v34(0, FLD(u16, self, 0x98), 0);
        o2->v10(&a);
        o2->v20(&c2);
        FLD(Ov010St40 *, self, 0x40)->state = 0x1f;
        func_02049f44(data_02097e4c, 0x44, self + 0x70, 0);
        break;
    }
    case 0x1f:
        st->timer++;
        st = FLD(Ov010St40 *, self, 0x40);
        if (st->timer > 0x19) {
            st->timer = 0;
            FLD(Ov010St40 *, self, 0x40)->state = 0x28;
        }
        break;
    case 0x28: {
        u8 *g;
        Ov010V *e;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[3], 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        Ov010_ClearSpeed(self);
        g = data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 0x28;
        FLD(u8, g, 0x18f) = 0x28;
        FLD(Ov010St40 *, self, 0x40)->state = 0x29;
        Ov010Vec o = {0, 0, 0};
        o.y = FLD(s32, self, 0x68) / 2;
        e = func_ov003_021da788(0x4b0, self, &o);
        e->v34(0, FLD(u16, self, 0x7e), 0);
        e->v0c(0x1800);
        if (FLD(u8, self, 0xf1) != 0) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x148), self + 0x70, 0);
        }
        func_02049f44(data_02097e4c, 0x32, self + 0x70, 0);
        break;
    }
    case 0x29: {
        Ov010Vec *t = FLD(Ov010Vec *, self, 0xf8);
        Ov010Vec f;
        s32 dx = t->x - FLD(s32, self, 0x70);
        s32 dy = t->y;
        s32 dz = t->z;
        dy -= FLD(s32, self, 0x74);
        dz -= FLD(s32, self, 0x78);
        s32 sv;
        func_ov003_021d9980(&f, FLD(u16, self, 0x98), (Ov010Vec *)&data_ov010_0220f0b4);
        if ((s32)(((s64)f.x * dx + (s64)f.y * dy + (s64)f.z * dz + 0x800) >> 12) < 0) {
            if (VEC_Distance(FLD(Ov010Vec *, self, 0xf8), &FLD(Ov010Vec, self, 0x70)) >=
                FLD(s32, FLD(u8 *, self, 0xf8), 0x10) + 0x3000) {
                FLD(Ov010St40 *, self, 0x40)->timer = 0;
                FLD(Ov010St40 *, self, 0x40)->state = 0x32;
            }
        }
        func_ov000_0219aae8(self, self, 0x8c, 0x30, 2, 0, 0, 0x800, 0x3000, 0x64, 0x1000);
        FLD(s32, self, 0x9c) += 0x266;
        sv = FLD(s32, self, 0x9c);
        FLD(s32, self, 0x9c) = sv > 0x1000 ? 0x1000 : (sv < 0 ? 0 : sv);
        func_ov000_0218dbe0(self, 0x1000);
        FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 1;
        break;
    }
    case 0x32:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[4], 0x266, 0);
        func_ov000_02191618(FLD(void *, self, 0x38));
        FLD(s32, self, 0xa4) = 0x400;
        FLD(Ov010St40 *, self, 0x40)->state = 0x33;
        break;
    case 0x33:
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            Ov010_ClearSpeed(self);
            FLD(Ov010St40 *, self, 0x40)->state = 0x3c;
        }
        func_ov000_0218dbe0(self, 0x1000);
        break;
    case 0x3c:
        FLD(u16, self, 0x7e) += 0x7fff;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(Ov010St40 *, self, 0x40)->state = 0x46;
        break;
    case 0x46:
        func_ov003_021d969c(self + 0x160, 1);
        break;
    }
}

}
