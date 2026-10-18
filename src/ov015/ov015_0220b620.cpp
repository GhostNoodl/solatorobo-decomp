#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212f20[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);

void *func_ov015_0220b620(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220b658(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

BOOL func_ov015_0220b698(u8 *self, u8 *p) {
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0xc) = 0x50;
    FLD(s32, self, 0x10) = FLD(u16, p, 0xd4);
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e47, 0x19a, 0);
    func_ov000_02191618(p + 0x244);
    FLD(u16, p, 0x104) = 0x800;
    FLD(s32, p, 0xbc) = 1;
    return TRUE;
}

u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e55[];
extern u8 data_ov015_02212e4e[];
extern u8 data_ov015_02212e61[];
extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
s32 FX_Div(s32 a, s32 b);
BOOL func_ov000_02191120(void *p);
void func_ov000_021915a0(void *a);
void func_ov015_0220bb68(u8 *self, u8 *p);
void func_ov015_0220be38(u8 *self, u8 *p);
static inline void Ov015_SpeedB6f0(u8 *p) {
    s32 r;
    s32 sp = FLD(s32, p, 0xe8);
    s32 s = FLD(u16, p, 0xd0) << 12;
    if (sp < 0xe10000) {
        r = Ov015_FxMul(s, 0x1000);
    } else if (sp < 0x1c20000) {
        r = Ov015_FxMul(s, 0xccd);
    } else {
        r = Ov015_FxMul(s, 0xb33);
    }
    FLD(s32, p, 0xdc) = r;
}
BOOL func_ov015_0220b6f0(u8 *self, u8 *p) {
    Ov015Vec b;
    Ov015Vec a;
    FLD(u8 *, self, 0x4) = p;
    switch (FLD(s32, self, 0x8)) {
    case 0:
        func_ov015_0220bb68(self, p);
        if (func_ov000_02191120(p + 0x244)) {
            func_ov000_02190cb0(p + 0x244, data_ov015_02212e4e, 0x19a, 0);
            func_ov000_021915a0(p + 0x244);
            FLD(u16, p, 0x104) = 0x1000;
            FLD(s32, self, 0x8) = 1;
            FLD(s32, self, 0xc) = FLD(s32, self, 0x10);
        }
        break;
    case 1: {
        Ov015V *e;
        u8 *q;
        {
            s32 c = FLD(s32, self, 0xc);
            s32 t = FLD(s32, self, 0x10);
            Ov015VecC v(FLD(Ov015VecC, p, 0x40));
            if (t - c >= 0x3c) {
                s32 r = FX_Div(c << 12, t >> 12);
                u16 idx = Ov015_FxMul(0x1000 - r, 0x2ffff) >> 12;
                v.y = Ov015_FxMul(FX_SinCosTable_[(idx >> 4) * 2], 0xccd) + 0x4000;
            }
            FLD(Ov015VecC, p, 0x40) = v;
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
        if (FLD(s32, self, 0xc) % 50 == 0) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (FLD(s32, self, 0xc) <= 0) {
            FLD(u16, p, 0x104) = 0x800;
            FLD(s32, self, 0x8) = 2;
            FLD(s32, self, 0xc) = 0x50;
            func_ov000_02190cb0(p + 0x244, data_ov015_02212e61, 0x19a, 0);
            func_ov000_02191618(p + 0x244);
            FLD(u16, p, 0x104) = 0x800;
            e = func_020657b0(data_0214a420, FLD(void *, self, 0x14));
            if (e != NULL) {
                u32 saved;
                HEAP_PUSH(saved);
                if (e != NULL) {
                    if (e != NULL) {
                        e->v04();
                    }
                }
                HEAP_POP(saved);
            }
        }
        break;
    }
    case 2:
        func_ov015_0220be38(self, p);
        if (func_ov000_02191120(p + 0x244)) {
            Ov015_SpeedB6f0(p);
            return FALSE;
        }
        break;
    }
    FLD(s32, self, 0xc)--;
    if (FLD(s32, self, 0xc) <= 0) {
        FLD(s32, self, 0xc) = 0;
    }
    FLD(s32, p, 0xbc) = 1;
    return TRUE;
}

}
