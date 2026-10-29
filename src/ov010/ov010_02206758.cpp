#include "ov010/ov010.h"

namespace Ov010T6974 {
extern "C" void *const data_ov010_0220f024[];
}

extern "C" {
extern void func_ov010_02206784(void *self);
extern void func_ov010_02206974(void *self);

void func_ov010_02206758(void *self) {
    switch (FLD(u8, self, 0x171)) {
    case 1:
        func_ov010_02206784(self);
        break;
    case 2:
        func_ov010_02206974(self);
        break;
    }
}

extern void *data_02097e4c;
extern u8 data_ov010_0220f024[];
extern void func_ov010_02204030(Ov010Vec *out, void *c, const Ov010Vec *target, s32 n, u16 ang);
extern void VEC_Normalize(Ov010Vec *a, Ov010Vec *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);

void func_ov010_02206784(void *self) {
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec p;
        Ov010V *e;
        u16 d;
        func_ov010_02204030(&p, FLD(void *, self, 0xf8), &FLD(Ov010Vec, self, 0x70), 4, 0);
        Ov010_VecCopy(&FLD(Ov010Vec, self, 0xb8), &p);
        FLD(s32, self, 0x150) = p.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = p.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = p.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &p);
        e->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        d = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x24), 0x800, 0);
            return;
        }
        if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x20), 0x800, 0);
        }
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
        }
        break;
    case 0x100:
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x2c), 0xcd, 0);
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

struct Ov010Mtx33f {
    s32 m[9];
};

extern u8 *data_ov000_021ccd54;
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void MTX_RotY33_(Ov010Mtx33f *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33f *m, Ov010Vec *o);
extern u16 func_ov010_02208e90(s32 a, s32 b);
extern void func_ov003_021d9d28(Ov010Vec *out, Ov010Vec *pos, u16 ang, void *c);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);

static inline s32 Ov010f_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010f_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33f m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010f_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline void Ov010f_ClearVel(void *self) {
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_02206974(void *self) {
    Ov010Vec a;
    Ov010Vec b;
    Ov010Vec c;
    if (data_ov000_021ccd54 + 0xf4 == NULL) {
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
    } else {
        u8 *t = FLD(u8 *, self, 0xf8);
        s32 cross;
        u16 ang;
        a.x = FLD(s32, self, 0x70) - FLD(s32, t, 0);
        a.y = FLD(s32, self, 0x74) - FLD(s32, t, 4);
        a.z = FLD(s32, self, 0x78) - FLD(s32, t, 8);
        VEC_Normalize(&a, &a);
        b = FLD(Ov010Vec, data_ov000_021ccd54, 0xf8);
        t = FLD(u8 *, self, 0xf8);
        b.x = FLD(s32, t, 0) - b.x;
        b.y = FLD(s32, t, 4) - b.y;
        b.z = FLD(s32, t, 8) - b.z;
        VEC_Normalize(&b, &b);
        cross = (s32)(((s64)b.z * a.x - (s64)b.x * a.z + 0x800) >> 12);
        {
            s32 dist = VEC_Distance(&FLD(Ov010Vec, self, 0x70), FLD(Ov010Vec *, self, 0xf8));
            if (cross > 0) {
                ang = 0xffff - func_ov010_02208e90(dist, *FLD(s16 *, self, 0xb0));
            } else {
                ang = func_ov010_02208e90(dist, *FLD(s16 *, self, 0xb0));
            }
        }
        func_ov003_021d9d28(&c, &FLD(Ov010Vec, self, 0x70), ang, FLD(void *, self, 0xf8));
    }
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec d;
        Ov010Vec v;
        u8 *t = FLD(u8 *, self, 0xf8);
        u16 r;
        s32 y;
        d.x = FLD(s32, self, 0x70) - FLD(s32, t, 0);
        d.y = FLD(s32, self, 0x74) - FLD(s32, t, 4);
        d.z = FLD(s32, self, 0x78) - FLD(s32, t, 8);
        r = func_ov003_021d9c38(&d);
        t = FLD(u8 *, self, 0xf8);
        y = FLD(s32, t, 4);
        Ov010f_SetRot(&v, FLD(s32, t, 0x10), r);
        VEC_Add(&v, (Ov010Vec *)t, &v);
        v.y = y;
        FLD(Ov010Vec, self, 0xb8) = v;
        FLD(s32, self, 0x150) = v.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = v.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = v.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        Ov010f_ClearVel(self);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x30;
        }
        break;
    case 0x30: {
        Ov010V *e;
        u16 d;
        Ov010f_ClearVel(self);
        FLD(s32, self, 0x9c) = Ov010f_FxMul(*FLD(s16 *, self, 0xb0), 0x1800);
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &c);
        e->v0c(0x2000);
        d = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), (const char *)Ov010T6974::data_ov010_0220f024[9], 0x800, 0);
        } else if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), (const char *)Ov010T6974::data_ov010_0220f024[8], 0x800, 0);
        }
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x31;
        FLD(u16, FLD(void *, self, 0x40), 2) = 0;
        break;
    }
    case 0x31: {
        u16 *m = FLD(u16 *, self, 0x40);
        s32 dot = (s32)(((s64)a.x * b.x + (s64)a.y * b.y + (s64)a.z * b.z + 0x800) >> 12);
        if (dot > 0xc00 || (m[1]++, m[1] > 0x12c)) {
            FLD(s32, self, 0x150) = c.x - FLD(s32, self, 0x70);
            FLD(s32, self, 0x154) = c.y - FLD(s32, self, 0x74);
            FLD(s32, self, 0x158) = c.z - FLD(s32, self, 0x78);
            VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
            FLD(s32, self, 0x9c) = 0x300;
            func_ov000_02190cb0(FLD(void *, self, 0x38), (const char *)Ov010T6974::data_ov010_0220f024[0xb], 0xcd, 0);
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x40;
        } else {
            FLD(Ov010Vec, self, 0x70) = c;
            func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
            func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
            break;
        }
    }
    case 0x40:
        if (FLD(s32, self, 0x9c) < 0x38) {
            Ov010f_ClearVel(self);
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
        }
        FLD(s32, self, 0xa4) = 0xe80;
        func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        break;
    case 0x100:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

}
