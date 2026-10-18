#include "ov015/ov015.h"

extern "C" {

extern void *data_ov015_02212db8[];
void func_0203f364(void *a);
extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];
s32 func_02012ab8(s32 a, s32 b);
void func_02012d78(void *src, void *dst);
void func_02012fb8(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
s32 func_02049130(s32 t, s32 a, s32 b);
u16 func_0201319c(s32 x, s32 z);
extern u8 data_ov015_02212ecc[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191318(void *a, s32 b);
extern u8 data_ov015_02212e68[];
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02191120(void *p);
void *func_ov015_0220a0c8(u8 *self);
void func_ov000_021915a0(void *a);

BOOL func_ov015_0220d280(u8 *self, u8 *p) {
    s32 i;
    FLD(s32, p, 0x108) = 0;
    func_0203f364(p + 0x568);
    Ov015_DeleteFound(data_0214a420, FLD(void *, self, 0x8));
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    return TRUE;
}

void func_ov015_0220d328(u8 *self, u8 *o) {
    Ov015Vec d;
    Ov015Vec p;
    Ov015Vec q;
    Ov015V *e;
    s32 t = 0x1000 - func_02012ab8(FLD(s32, self, 0x10) << 12, 0x5a000);
    d = FLD(Ov015Vec, self, 0x1c);
    d.y = Ov015_FxMul(FX_SinCosTable_[((Ov015_FxMul(t, 0x7fff000) >> 12) >> 4) * 2], 0x800);
    func_02012d78(&d, &d);
    func_02012d78(&d, o + 0x9c);
    p = FLD(Ov015Vec, o, 0x40);
    func_02012fb8(FLD(s32, self, 0xc), (Ov015Vec *)(self + 0x1c), &p, &p);
    p.y = func_02049130(t, -0x32000, 0x1ccd);
    if (p.y > 0) p.y = 0;
    FLD(Ov015Vec, o, 0x40) = p;
    FLD(s32, o, 0x108) = 2;
    e = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, o + 0x40);
        FLD(s32, e, 0xd4) = 3;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        FLD(void *, self, 0x8) = FLD(void *, e, 0x24);
    }
    q.x = FLD(s32, o, 0x40);
    q.y = FLD(s32, o, 0x44) > 0 ? 0 : FLD(s32, o, 0x44);
    q.z = FLD(s32, o, 0x48);
    e->v18(&q);
    e->v10(o + 0x70);
    e->v34(0, func_0201319c(FLD(s32, o, 0x9c), FLD(s32, o, 0xa4)), 0);
    if (FLD(s32, self, 0x10) == 0x3c) {
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x55, -1, -1, -1);
    }
}

void func_ov015_0220d578(u8 *self, u8 *o) {
    Ov015Vec d;
    Ov015Vec p;
    Ov015Vec q;
    Ov015V *e;
    s32 t = 0x1000 - func_02012ab8(FLD(s32, self, 0x10) << 12, 0x5a000);
    d = FLD(Ov015Vec, self, 0x1c);
    d.y = Ov015_FxMul(FX_SinCosTable_[(((Ov015_FxMul(t, 0x7fff000) >> 12) + 0x7fff) >> 4) * 2], 0x800);
    func_02012d78(&d, &d);
    func_02012d78(&d, o + 0x9c);
    p = FLD(Ov015Vec, o, 0x40);
    func_02012fb8(FLD(s32, self, 0xc), (Ov015Vec *)(self + 0x1c), &p, &p);
    p.y = func_02049130(t, 0x1ccd, -0x32000);
    if (p.y < -0x32000) p.y = -0x32000;
    FLD(Ov015Vec, o, 0x40) = p;
    FLD(s32, o, 0x108) = 2;
    if (FLD(s32, self, 0x10) == 0x3c) {
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x55, -1, -1, -1);
    }
    e = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, o + 0x40);
        FLD(s32, e, 0xd4) = 3;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        FLD(void *, self, 0x8) = FLD(void *, e, 0x24);
    }
    q.x = FLD(s32, o, 0x40);
    q.y = FLD(s32, o, 0x44) > 0 ? 0 : FLD(s32, o, 0x44);
    q.z = FLD(s32, o, 0x48);
    e->v18(&q);
    e->v10(o + 0x70);
    e->v34(0, func_0201319c(FLD(s32, o, 0x9c), FLD(s32, o, 0xa4)), 0);
}

static inline void Ov015_VecSet(Ov015Vec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
BOOL func_ov015_0220d7d0(u8 *self, Ov015Vec *out, Ov015Vec *pos) {
    u8 *a = FLD(u8 *, self, 0x3c);
    BOOL r = TRUE;
    if (pos->x > FLD(s32, a, 0xb0)) {
        Ov015_VecSet(out, -0x1000, 0, 0);
        r = FALSE;
    } else if (pos->x < FLD(s32, a, 0xac)) {
        r = FALSE;
        Ov015_VecSet(out, 0x1000, 0, 0);
    } else if (pos->z > FLD(s32, a, 0xb4)) {
        r = FALSE;
        Ov015_VecSet(out, 0, 0, -0x1000);
    } else if (pos->z < FLD(s32, a, 0xb8)) {
        r = FALSE;
        Ov015_VecSet(out, 0, 0, 0x1000);
    } else {
        Ov015_VecSet(out, 0, 0, 0);
    }
    return r;
}

void func_ov015_0220d878(u8 *self) {
    SET_VT(self, data_ov015_02212ecc);
    FLD(s32, self, 0x4) = 0;
}

void *func_ov015_0220d890(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220d8a0(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

BOOL func_ov015_0220d8c0(u8 *self, u8 *p) {
    Ov015VecC v;
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e47, 0x19a, 0);
    func_ov000_02191318(p + 0x244, 0x7000);
    FLD(u16, p, 0x104) = 0x800;
    v = *(Ov015VecC *)(p + 0x9c);
    v.y = 0;
    func_02012d78(&v, p + 0x9c);
    FLD(s32, self, 0x4) = 1;
    return TRUE;
}

BOOL func_ov015_0220d940(u8 *self, u8 *p) {
    switch (FLD(s32, self, 0x4)) {
    case 1: {
        s32 z = FLD(s32, p, 0x48);
        s32 x = FLD(s32, p, 0x40);
        FLD(s32, p, 0x108) = 0;
        FLD(s32, p, 0x40) = x;
        FLD(s32, p, 0x44) = 0;
        FLD(s32, p, 0x48) = z;
        if (FLD(s16, p, 0x308) == 1) {
            u8 *o;
            Ov015Vec v;
            FLD(s16, p, 0x308) = 0;
            v.x = x;
            v.z = z;
            v.y = 0;
            o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, &v);
            VCALL(o)->v10(p + 0x70);
            FLD(s32, o, 0xd4) = 3;
            FLD(u8, o, 0x28) = 0;
            FLD(s32, o, 0x50) = -0xc8000;
            FLD(s32, o, 0x3c) = 0x800;
            func_02049a48(data_02097e4c, 0x1b, -1, -1, -1);
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (func_ov000_02191120(p + 0x244)) {
            func_ov000_02190cb0(p + 0x244, data_ov015_02212e0d, 0x19a, 0);
            FLD(u16, p, 0x104) = 0x800;
            FLD(s32, self, 0x4) = 2;
        }
        break;
    }
    case 2:
        if (func_ov000_02191120(p + 0x244)) {
            void *q = func_0203dd9c(0x2c);
            if (q != NULL) {
                q = func_ov015_0220a0c8((u8 *)q);
            }
            FLD(void *, p, 0xf0) = q;
            FLD(s32, p, 0xec) = 2;
        }
        break;
    }
    return TRUE;
}

BOOL func_ov015_0220daac(u8 *self, u8 *p) {
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e0d, 0x19a, 0);
    FLD(u16, p, 0x104) = 0x800;
    func_ov000_021915a0(p + 0x244);
    FLD(s32, p, 0x108) = 0;
    return TRUE;
}

}
