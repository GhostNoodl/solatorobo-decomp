#include "ov015/ov015.h"

extern "C" {

extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
extern void *data_02097e4c;
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e68[];
void *func_02049a48(void *a, int b, int c, int d, int e);
u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e55[];
s32 FX_Div(s32 a, s32 b);
s32 FX_Sqrt(s32 a);
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);

BOOL func_ov015_0220bb00(u8 *self) {
    Ov015V *o;
    u32 saved;
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x14));
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    return TRUE;
}

static inline void Ov015_Spawn0bb68(u8 *self, s32 s1, s32 s2) {
    s32 m = 0;
    u8 *o;
    Ov015Vec a;
    Ov015Vec b;
    u8 *q;
    s32 y;
    o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, FLD(u8 *, self, 0x4) + 0x40);
    FLD(s32, o, 0xd4) = 1;
    FLD(u8, o, 0x28) = 1;
    FLD(s32, o, 0x50) = -0xc8000;
    q = FLD(u8 *, self, 0x4);
    a.x = FLD(s32, q, 0x40);
    y = FLD(s32, q, 0x44);
    if (y <= 0) m = y;
    a.y = m;
    a.z = FLD(s32, q, 0x48);
    VCALL(o)->v18(&a);
    q = FLD(u8 *, self, 0x4);
    {
        s32 k = FLD(s32, q, 0x7c);
        b.x = Ov015_FxMul(FLD(s32, q, 0x70), k);
        b.y = Ov015_FxMul(FLD(s32, q, 0x74), k);
        b.z = Ov015_FxMul(FLD(s32, q, 0x78), k);
    }
    VCALL(o)->v10(&b);
    func_02049a48(data_02097e4c, s1, -1, -1, -1);
    func_02049a48(data_02097e4c, s2, -1, -1, -1);
}
void func_ov015_0220bb68(u8 *self, u8 *p) {
    Ov015VecC t(FLD(Ov015VecC, p, 0x40));
    s32 d = 0x4000 - t.y;
    if ((d < 0 ? -d : d) <= 0x19a) {
        t.y = 0x4000;
    } else {
        t.y += Ov015_FxMul(d, 0x29);
    }
    FLD(Ov015VecC, p, 0x40) = t;
    if (FLD(s32, self, 0xc) == 0x50) {
        Ov015_Spawn0bb68(self, 0x19, 0x3e);
    } else if (FLD(s32, self, 0xc) == 1) {
        Ov015_Spawn0bb68(self, 0x3e, 0x1b);
    }
}

void func_ov015_0220be38(u8 *self, u8 *p) {
    Ov015Vec a;
    Ov015Vec c;
    Ov015Vec d;
    Ov015Vec b;
    Ov015V *e;
    u8 *q;
    s32 n;
    {
        Ov015VecC t(FLD(Ov015VecC, p, 0x40));
        s32 y = t.y;
        if ((y < 0 ? -y : y) >= 0x19a) {
            t.y = 0;
        } else {
            t.y = Ov015_FxMul(y, 0xfd7);
        }
        FLD(Ov015VecC, p, 0x40) = t;
    }
    q = FLD(u8 *, self, 0x4);
    a.x = FLD(s32, q, 0x40);
    a.y = FLD(s32, q, 0x44) > 0 ? 0 : FLD(s32, q, 0x44);
    a.z = FLD(s32, q, 0x48);
    e = func_020657b0(data_0214a420, FLD(void *, self, 0x14));
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e55, 0, FLD(u8 *, self, 0x4) + 0x40);
        FLD(s32, e, 0xd4) = 1;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0x3c) = 0x800;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        e->v34(0, 0x3fff, 0);
        FLD(void *, self, 0x14) = FLD(void *, e, 0x24);
    }
    e->v18(&a);
    q = FLD(u8 *, self, 0x4);
    {
        s32 k = FLD(s32, q, 0x7c);
        b.x = Ov015_FxMul(FLD(s32, q, 0x70), k);
        b.y = Ov015_FxMul(FLD(s32, q, 0x74), k);
        b.z = Ov015_FxMul(FLD(s32, q, 0x78), k);
    }
    e->v10(&b);
    n = FLD(s32, self, 0xc);
    if (n > 0x28) {
        s32 s = Ov015_FxMul(FX_Div((0x50 - n) << 12, 0x28000), -0x99a) + 0x1000;
        c.x = Ov015_FxMul(FLD(s32, e, 0x40), s);
        c.y = Ov015_FxMul(FLD(s32, e, 0x44), s);
        c.z = Ov015_FxMul(FLD(s32, e, 0x48), s);
        e->v10(&c);
    } else if (n < 10) {
        s32 s = FX_Sqrt(Ov015_FxMul(FX_Div((10 - n) << 12, 0xa000), 0x299a) + 0x666);
        d.x = Ov015_FxMul(FLD(s32, e, 0x40), s);
        d.y = Ov015_FxMul(FLD(s32, e, 0x44), s);
        d.z = Ov015_FxMul(FLD(s32, e, 0x48), s);
        e->v10(&d);
        if (FLD(s32, self, 0xc) == 1) {
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        }
    }
}

void *func_ov015_0220c188(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220c198(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

BOOL func_ov015_0220c1b8(u8 *self, u8 *p) {
    FLD(u8 *, self, 0x18) = p;
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = 0x1e;
    FLD(s32, self, 0xc) = 0x4b0;
    FLD(s32, self, 0x10) = 0;
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e0d, 0x19a, 0);
    FLD(u16, p, 0x104) = 0x1000;
    func_ov000_021915a0(p + 0x244);
    FLD(s32, p, 0xbc) = 4;
    FLD(s32, p, 0x108) = 2;

    return TRUE;
}


BOOL func_ov015_0220c810(u8 *self);
void func_ov015_0220c6c8(u8 *self, u8 *p);
s32 func_02040498(s32 n);
void func_ov000_02191618(void *a);
void VEC_Normalize(void *src, void *dst);
extern u8 data_ov015_02212e74[];

BOOL func_ov015_0220c21c(u8 *self, u8 *p) {
    BOOL ret = TRUE;
    s32 a;
    s32 off;
    s32 t;
    s32 v;
    FLD(u8 *, self, 0x18) = p;
    if (FLD(s32, self, 0x4) != 0 && FLD(s32, self, 0x4) != 5 && !func_ov015_0220c810(self)) {
        FLD(s32, self, 0x4) = 5;
        FLD(s32, self, 0x8) = 0x5a;
        func_ov000_02190cb0(p + 0x244, data_ov015_02212e74, 0x19a, 0);
        FLD(u16, p, 0x104) = 0x800;
        func_ov000_02191618(p + 0x244);
        FLD(s32, p, 0xbc) = 0;
    }
    switch (FLD(s32, self, 0x4)) {
    case 0: {
        Ov015VecC t(FLD(Ov015VecC, p, 0x40));
        t.y -= FX_Div(0x28000, 0x1e000);
        FLD(Ov015VecC, p, 0x40) = t;
        if (FLD(s32, self, 0x8) == 0) {
            s32 s = func_02040498(1) ? 3 : 4;
            FLD(s32, self, 0x4) = s;
            FLD(s32, self, 0x14) = s == 3 ? FLD(s32, p, 0xb0) : -FLD(s32, p, 0xac);
            FLD(s32, self, 0x8) = 0x1e;
            FLD(u16, p, 0x104) = 0x800;
            FLD(s32, p, 0xbc) = 4;
        }
        break;
    }
    case 1: {
        Ov015VecC t(FLD(Ov015VecC, p, 0x40));
        t.x -= Ov015_FxMul(FLD(s16, FLD(u8 *, self, 0x18), 0xca) << 4, 0x19a) + 0x800;
        FLD(Ov015VecC, p, 0x40) = t;
        if (t.x < FLD(s32, self, 0x14)) {
            FLD(s32, self, 0x4) = 4;
            FLD(s32, self, 0x8) = 0x1e;
        }
        break;
    }
    case 2: {
        Ov015VecC t(FLD(Ov015VecC, p, 0x40));
        t.x += Ov015_FxMul(FLD(s16, FLD(u8 *, self, 0x18), 0xca) << 4, 0x19a) + 0x800;
        FLD(Ov015VecC, p, 0x40) = t;
        if (t.x > FLD(s32, self, 0x14)) {
            FLD(s32, self, 0x4) = 3;
            FLD(s32, self, 0x8) = 0x1e;
        }
        break;
    }
    case 3: {
        off = 0;
        a = Ov015_FxMul(FLD(s16, FLD(u8 *, self, 0x18), 0xca) << 4, 0x19a) + 0x800;
        t = FX_Div((FLD(s32, self, 0x8) - 0x1e) >> 1, 0xf);
        v = Ov015_FxMul(a >> 1, Ov015_FxMul(t, t));
        FLD(s32, FLD(u8 *, self, 0x18), 0xa8) = v;
        {
            Ov015VecC q(FLD(Ov015VecC, p, 0x40));
            q.x -= v;
            FLD(Ov015VecC, p, 0x40) = q;
        }
        {
            Ov015Vec d2 = FLD(Ov015Vec, p, 0x9c);
            if (d2.x > -0x1000) off = -0xcd;
            d2.z = -0x1000;
            d2.x += off;
            VEC_Normalize(&d2, p + 0x9c);
        }
        if (FLD(s32, self, 0x8) == 0xf) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (FLD(s32, self, 0x8) <= 0) {
            s32 w;
            FLD(s32, self, 0x4) = 1;
            w = FLD(s32, p, 0xac);
            if (w < 0) w = -w;
            FLD(s32, self, 0x14) = -func_02040498(w);
        }
        break;
    }
    case 4: {
        off = 0;
        a = Ov015_FxMul(FLD(s16, FLD(u8 *, self, 0x18), 0xca) << 4, 0x19a) + 0x800;
        t = FX_Div((FLD(s32, self, 0x8) - 0x1e) >> 1, 0xf);
        v = Ov015_FxMul(a >> 1, Ov015_FxMul(t, t));
        FLD(s32, FLD(u8 *, self, 0x18), 0xa8) = v;
        {
            Ov015VecC q(FLD(Ov015VecC, p, 0x40));
            q.x += v;
            FLD(Ov015VecC, p, 0x40) = q;
        }
        {
            Ov015Vec d2 = FLD(Ov015Vec, p, 0x9c);
            if (d2.x < 0x1000) off = 0xcd;
            d2.z = -0x1000;
            d2.x += off;
            VEC_Normalize(&d2, p + 0x9c);
        }
        if (FLD(s32, self, 0x8) == 0xf) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (FLD(s32, self, 0x8) <= 0) {
            FLD(s32, self, 0x4) = 2;
            FLD(s32, self, 0x14) = func_02040498(FLD(s32, p, 0xb0));
        }
        break;
    }
    case 5:
        func_ov015_0220c6c8(self, p);
        if (FLD(s32, self, 0x8) == 0) ret = FALSE;
        break;
    }
    if (--FLD(s32, self, 0x8) < 0) FLD(s32, self, 0x8) = 0;
    return ret;
}

}
