#include "ov015/ov015.h"

extern "C" {

extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
s32 FX_Div(s32 a, s32 b);
s32 func_02049130(s32 t, s32 a, s32 b);
void MTX_RotY33_(void *m, s32 s, s32 c);
void MTX_MultVec33(void *a, void *b, void *c);
void VEC_Normalize(void *src, void *dst);
void func_ov015_0220afcc(u8 *self);
void func_ov015_0220b1b8(u8 *self);

BOOL func_ov015_0220ab84(u8 *self, s32 a) {
    Ov015V *o;
    u32 saved;
    FLD(s32, self, 0x20) = a;
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x24));
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x28));
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

void func_ov015_0220ac40(u8 *self, u8 *p) {
    Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
    Ov015VecC dir(*(Ov015VecC *)(p + 0x9c));
    s32 m[9];
    s32 t = FX_Div(FLD(s16, self, 0x6) << 12, 0x14000);
    s32 b = Ov015_FxMul(FLD(s16, FLD(u8 *, self, 0x20), 0xca) << 4, 0x19a) + 0x800;
    s32 d = Ov015_FxMul(func_02049130(Ov015_FxMul(FLD(s32, self, 0x18), FLD(s32, self, 0x18)), b / 5, b), t);
    FLD(s32, p, 0xa8) = d;
    FLD(s32, p, 0x40) = pos.x + d;
    FLD(s32, p, 0x44) = pos.y;
    FLD(s32, p, 0x48) = pos.z;
    MTX_RotY33_(m, FX_SinCosTable_[0xfbb * 2], FX_SinCosTable_[0xfbb * 2 + 1]);
    MTX_MultVec33(&dir, m, &dir);
    VEC_Normalize(&dir, p + 0x9c);
    func_ov015_0220afcc(self);
    func_ov015_0220b1b8(self);
}

void func_ov015_0220ad68(u8 *self, u8 *p) {
    Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
    Ov015VecC dir(*(Ov015VecC *)(p + 0x9c));
    s32 m[9];
    s32 t = FX_Div(FLD(s16, self, 0x6) << 12, 0x14000);
    s32 b = Ov015_FxMul(FLD(s16, FLD(u8 *, self, 0x20), 0xca) << 4, 0x19a) + 0x800;
    s32 d = Ov015_FxMul(func_02049130(Ov015_FxMul(FLD(s32, self, 0x18), FLD(s32, self, 0x18)), b / 5, b), t);
    FLD(s32, p, 0xa8) = d;
    FLD(s32, p, 0x40) = pos.x - d;
    FLD(s32, p, 0x44) = pos.y;
    FLD(s32, p, 0x48) = pos.z;
    MTX_RotY33_(m, FX_SinCosTable_[0x44 * 2], FX_SinCosTable_[0x44 * 2 + 1]);
    MTX_MultVec33(&dir, m, &dir);
    VEC_Normalize(&dir, p + 0x9c);
    func_ov015_0220afcc(self);
    func_ov015_0220b1b8(self);
}

BOOL func_ov015_0220ae90(u8 *self) {
    u8 *p = FLD(u8 *, self, 0x20);
    s32 acc = FLD(s16, p, 0xd2);
    s32 dec = FLD(s32, p, 0xe0);
    Ov015Stat *st = &data_ov015_0221332c;
    if ((u32)self & 3) {
        dec = FLD(s32, p, 0xe0);
    }
    s32 lim;
    s32 sp;
    s32 v;
    FLD(s32, self, 0x10) = FLD(s32, self, 0xc);
    if (st->unk_1c != 0 && st->unk_28 != 3) {
        FLD(s32, self, 0xc) -= dec;
        FLD(s16, self, 0xa) = 10;
        FLD(s16, self, 0x1c) = 6;
    } else {
        if (FLD(s16, self, 0xa) <= 0) {
            FLD(s32, self, 0xc) += acc << 4;
        } else {
            FLD(s16, self, 0xa)--;
        }
        FLD(s16, self, 0x1c)--;
        if (FLD(s16, self, 0x1c) <= 0) {
            FLD(s16, self, 0x1c) = 0;
        }
    }
    v = FLD(u16, p, 0xd0) << 12;
    sp = FLD(s32, p, 0xe8);
    if (sp < 0xe10000) {
        lim = Ov015_FxMul(v, 0x1000);
    } else if (sp < 0x1c20000) {
        lim = Ov015_FxMul(v, 0xccd);
    } else {
        lim = Ov015_FxMul(v, 0xb33);
    }
    if (FLD(s32, self, 0xc) > lim) {
        FLD(s32, self, 0xc) = lim;
    }
    FLD(s32, p, 0xdc) = FLD(s32, self, 0xc);
    return FLD(s32, self, 0xc) <= 0;
}

}
