#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212ee8[];
extern u8 data_ov015_02212eb0[];
extern void *data_ov015_02212db8[];
extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 func_02040528(s32 max);
void VEC_Normalize(void *src, void *dst);
void func_0203f324(void *a);

u8 *func_ov015_0220c93c(u8 *self) {
    SET_VT(self, data_ov015_02212ee8);
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0xc) = 0x1000;
    FLD(s32, self, 0x10) = 0;
    FLD(s32, self, 0x14) = 0;
    FLD(s32, self, 0x18) = 0;
    FLD(s32, self, 0x1c) = 0;
    FLD(s32, self, 0x20) = 0;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    FLD(s32, self, 0x2c) = 0;
    FLD(s32, self, 0x30) = 0;
    FLD(s32, self, 0x34) = 0;
    FLD(s32, self, 0x38) = 0;
    return self;
}

void *func_ov015_0220c98c(u8 *self) {
    s32 i;
    Ov015V *o;
    u32 saved;
    SET_VT(self, data_ov015_02212ee8);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, data_ov015_02212eb0);

    return self;
}

void *func_ov015_0220ca38(u8 *self) {
    s32 i;
    Ov015V *o;
    u32 saved;
    SET_VT(self, data_ov015_02212ee8);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

static inline void Ov015_SetXZ(s32 *v, s32 x, s32 z) { v[0] = x; v[2] = z; }
BOOL func_ov015_0220caec(u8 *self, u8 *p) {
    s32 a;
    s32 x, z;
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e0d, 0x19a, 0);
    FLD(u16, p, 0x104) = 0x59a;
    func_ov000_021915a0(p + 0x244);
    FLD(s32, p, 0x108) = 1;
    FLD(s32, self, 0xc) = Ov015_FxMul(FLD(s16, p, 0xca) << 4, 0x19a) + 0x23d;
    a = func_02040528(0x1000);
    FLD(s32, self, 0x1c) = func_02040528(0x1000);
    FLD(s32, self, 0x24) = a;
    FLD(s32, self, 0x20) = 0;
    VEC_Normalize(self + 0x1c, self + 0x1c);
    VEC_Normalize(self + 0x1c, p + 0x9c);
    FLD(s32, p, 0x44) = -0x32000;
    Ov015_SetXZ((s32 *)(p + 0x40), FLD(s32, p, 0x40), FLD(s32, p, 0x48));
    func_0203f324(p + 0x568);
    FLD(s32, self, 0x14) = FLD(u16, p, 0xcc);
    FLD(s32, self, 0x18) = FLD(u16, p, 0xce);
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x10) = FLD(s32, self, 0x18);
    return TRUE;
}

s32 FX_Div(s32 a, s32 b);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Add(const void *a, const void *b, void *out);
u16 FX_Atan2(s32 x, s32 z);
BOOL func_ov015_0220d7d0(u8 *self, Ov015Vec *out, Ov015Vec *pos);
void func_ov015_0220d328(u8 *self, u8 *o);
void func_ov015_0220d578(u8 *self, u8 *o);
u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];

static inline void Ov015_Turn(u8 *self, Ov015Vec *v) {
    s32 r;
    FLD(s32, self, 0x34) = 0x3c;
    r = FX_Atan2(FLD(s32, self, 0x30), FLD(s32, self, 0x28));
    FLD(s32, self, 0x38) = FX_Atan2(v->z, v->x) - r;
    if (FLD(s32, self, 0x38) > 0x7fff) {
        FLD(s32, self, 0x38) -= 0x7fff + 0x8000;
    }
}

/* A sub-object at p + 0x568 (not an ARM immediate). */
typedef struct {
    u8 pad[0x18];
    Ov015Vec dir;
} Ov015Sub568;

typedef struct {
    u8 pad[0x568];
    Ov015Sub568 sub;
} Ov015Owner568;

BOOL func_ov015_0220cbe8(u8 *self, u8 *p) {
    Ov015Vec v0;
    Ov015Vec b;
    Ov015Vec a;
    Ov015Vec q;
    Ov015Vec n;
    Ov015Vec u;
    Ov015Vec w;
    Ov015Vec v1;
    Ov015Vec v3;
    Ov015Vec v2;
    Ov015Vec pos;
    s32 i;
    FLD(u8 *, self, 0x3c) = p;
    if (FLD(s32, self, 0x34) > 0) {
        s32 t = FX_Div(FLD(s32, self, 0x34) << 12, 0x3c000);
        s32 s = FLD(s32, self, 0x38);
        s32 x = FLD(s32, self, 0x28);
        s32 ang = Ov015_FxMul(-(s << 12), t) + (s << 12);
        s32 idx = (u16)(ang >> 12) >> 4;
        s32 sn = FX_SinCosTable_[idx * 2];
        s32 cs = FX_SinCosTable_[idx * 2 + 1];
        s32 z = FLD(s32, self, 0x30);
        FLD(s32, self, 0x1c) = Ov015_FxMul(x, cs) - Ov015_FxMul(z, sn);
        FLD(s32, self, 0x20) = 0;
        FLD(s32, self, 0x24) = Ov015_FxMul(x, sn) + Ov015_FxMul(z, cs);
        FLD(s32, self, 0x34)--;
    } else {
        FLD(s32, self, 0x34) = 0;
        if (FLD(s32, p, 0x5ac) != 0) {
            Ov015Sub568 *sub = &((Ov015Owner568 *)p)->sub;
            v0 = FLD(Ov015Vec, p, 0x40);
            VEC_MultAdd(FLD(s32, self, 0xc), &FLD(Ov015Vec, self, 0x1c), &v0, &v0);
            FLD(Ov015Vec, p, 0x40) = v0;
            FLD(s32, self, 0x28) = FLD(s32, self, 0x1c);
            FLD(s32, self, 0x30) = FLD(s32, self, 0x24);
            FLD(s32, self, 0x2c) = 0;
            VEC_Normalize(self + 0x28, self + 0x28);
            a = sub->dir;
            VEC_Normalize(&a, &a);
            VEC_Add(&a, self + 0x1c, &b);
            b.y = 0;
            VEC_Normalize(&b, &b);
            Ov015_Turn(self, &b);
        } else {
            s32 dot;
            VEC_MultAdd(FLD(s32, self, 0xc), &FLD(Ov015Vec, self, 0x1c), &FLD(Ov015Vec, p, 0x40), &q);
            if (func_ov015_0220d7d0(self, &n, &q)) goto clamp;
            FLD(s32, self, 0x28) = FLD(s32, self, 0x1c);
            FLD(s32, self, 0x2c) = FLD(s32, self, 0x20);
            FLD(s32, self, 0x30) = FLD(s32, self, 0x24);
            w = FLD(Ov015Vec, p, 0x9c);
            w.y = 0;
            VEC_Normalize(&w, &w);
            dot = (s32)(((s64)n.x * w.x + (s64)n.y * w.y + (s64)n.z * w.z + 0x800) >> 12);
            if (dot < 0) dot = -dot;
            VEC_MultAdd(dot * 2, &n, &w, &u);
            VEC_Normalize(&u, &u);
            Ov015_Turn(self, &u);
        }
    }
clamp:
    pos = FLD(Ov015Vec, p, 0x40);
    if (pos.x > FLD(s32, p, 0xb0)) {
        pos.x = 0x32000;
    } else if (pos.x < FLD(s32, p, 0xac)) {
        pos.x = -0x32000;
    }
    if (pos.z > FLD(s32, p, 0xb4)) {
        pos.z = -0x4b000;
    } else if (pos.z < FLD(s32, p, 0xb8)) {
        pos.z = -0x8c000;
    }
    FLD(Ov015Vec, p, 0x40) = pos;
    switch (FLD(s32, self, 0x4)) {
    case 0: {
        BOOL found;
        FLD(s32, p, 0xa8) = FLD(s32, self, 0xc);
        v1 = pos;
        VEC_MultAdd(FLD(s32, self, 0xc), &FLD(Ov015Vec, self, 0x1c), &v1, &v1);
        VEC_Normalize(self + 0x1c, p + 0x9c);
        if (v1.y > -0x32000) {
            v1.y -= 0x80;
        } else {
            v1.y = -0x32000;
        }
        FLD(Ov015Vec, p, 0x40) = v1;
        if (FLD(s32, self, 0x10) == 0) {
            found = FALSE;
            for (i = 0; i < 1; i++) {
                if (data_ov015_02212db8[i] == NULL) {
                    found = TRUE;
                    data_ov015_02212db8[i] = self;
                    break;
                }
            }
            if (found) {
                FLD(s32, self, 0x4) = 1;
                FLD(s32, self, 0x10) = 0x5a;
                FLD(s32, p, 0x108) = 2;
            } else {
                FLD(s32, self, 0x18) >>= 1;
                FLD(s32, self, 0x10) = FLD(s32, self, 0x18);
            }
        }
        break;
    }
    case 1:
        func_ov015_0220d328(self, p);
        if (FLD(s32, self, 0x10) == 0) {
            FLD(s32, self, 0x4) = 2;
            FLD(s32, self, 0x10) = FLD(s32, self, 0x14);
        }
        break;
    case 2: {
        Ov015V *e;
        FLD(s32, p, 0xa8) = FLD(s32, self, 0xc);
        v2 = pos;
        VEC_MultAdd(FLD(s32, self, 0xc), &FLD(Ov015Vec, self, 0x1c), &v2, &v2);
        if (v2.y < 0) {
            v2.y += 0x19a;
        } else {
            v2.y = 0;
        }
        FLD(Ov015Vec, p, 0x40) = v2;
        VEC_Normalize(self + 0x1c, p + 0x9c);
        e = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
        if (e == NULL) {
            e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, p + 0x40);
            FLD(s32, e, 0xd4) = 3;
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0xc8) = -1;
            FLD(s32, e, 0x50) = -0xc8000;
            FLD(void *, self, 0x8) = FLD(void *, e, 0x24);
        }
        v3.x = FLD(s32, p, 0x40);
        v3.y = FLD(s32, p, 0x44) > 0 ? 0 : FLD(s32, p, 0x44);
        v3.z = FLD(s32, p, 0x48);
        e->v18(&v3);
        e->v10(p + 0x70);
        e->v34(0, FX_Atan2(FLD(s32, p, 0x9c), FLD(s32, p, 0xa4)), 0);
        if (FLD(s32, self, 0x10) == 0) {
            FLD(s32, self, 0x4) = 3;
            FLD(s32, self, 0x10) = 0x5a;
        }
        break;
    }
    case 3:
        func_ov015_0220d578(self, p);
        if (FLD(s32, self, 0x10) == 0) {
            FLD(s32, self, 0x4) = 0;
            FLD(s32, self, 0x10) = FLD(s32, self, 0x18) = FLD(u16, p, 0xce);
            FLD(s32, p, 0x108) = 1;
            Ov015_DeleteFound(data_0214a420, FLD(void *, self, 0x8));
            for (i = 0; i < 1; i++) {
                if (data_ov015_02212db8[i] == self) {
                    data_ov015_02212db8[i] = NULL;
                    break;
                }
            }
        }
        break;
    }
    FLD(u8 *, self, 0x3c) = NULL;
    if (--FLD(s32, self, 0x10) <= 0) {
        FLD(s32, self, 0x10) = 0;
    }
    return TRUE;
}

}
