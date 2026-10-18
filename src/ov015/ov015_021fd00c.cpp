#include "ov015/ov015.h"

extern "C" {

void func_ov015_021fb240(Ov015VecC *dst, const Ov015VecC *src);
void func_ov015_021fd288(void *self);
void func_ov015_021fd634(void *self);
void func_ov015_021fd900(void *self);
void func_ov015_021fe218(void *self);
void func_ov015_021fe548(void *self);
void func_ov015_021fe814(void *self);
void func_ov015_021feb34(void *self);
void func_ov015_021fee54(void *self);
void func_ov015_021ff044(void *self);
s32 FX_Div(s32 a, s32 b);
extern u8 data_ov015_0221253c[];
s32 VEC_Mag(const Ov015Vec *v);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Add(const void *a, const void *b, void *out);
void VEC_Normalize(void *src, void *dst);

void func_ov015_021fd00c(u8 *self, s32 mode, const Ov015VecC *v) {
    if (FLD(s32, self, 0x17c) != mode) {
        if (mode == 2) {
            FLD(s32, self, 0x19c) = 0x78;
        } else if (mode == 3) {
            FLD(s32, self, 0x19c) = 0xf0;
        } else {
            FLD(s32, self, 0x19c) = 0;
        }
    }
    FLD(s32, self, 0x17c) = mode;
    func_ov015_021fb240((Ov015VecC *)(self + 0x180), v);
    switch (mode) {
    case 1:
        func_ov015_021fd288(self);
        break;
    case 0:
        func_ov015_021fd634(self);
        break;
    case 2:
        func_ov015_021fd900(self);
        break;
    case 3:
        func_ov015_021fe218(self);
        break;
    case 4:
        func_ov015_021fe548(self);
        break;
    case 5:
        func_ov015_021fe814(self);
        break;
    case 6:
        func_ov015_021feb34(self);
        break;
    case 7:
        func_ov015_021fee54(self);
        break;
    case 8:
        func_ov015_021ff044(self);
        break;
    }
}

void func_ov015_021fd0f4(u8 *self, Ov015Vec *out) {
    Ov015Vec a = FLD(Ov015Vec, self, 0x8);
    Ov015Vec b = FLD(Ov015Vec, self, 0x14);
    s32 lim = FX_SinCosTable_[0x71];
    Ov015Vec e;
    Ov015Vec c;
    Ov015Vec d;

    Ov015Vec f;
    s32 ld, le, dot, r;
    VEC_Add(self + 0x180, data_ov015_0221253c, &c);
    d.x = c.x - a.x;
    d.y = c.y - a.y;
    d.z = c.z - a.z;
    ld = VEC_Mag(&d);
    e.x = b.x - a.x;
    e.y = b.y - a.y;
    e.z = b.z - a.z;
    le = VEC_Mag(&e);
    dot = (s32)(((s64)e.x * d.x + (s64)e.y * d.y + (s64)e.z * d.z + 0x800) >> 12);
    r = FX_Div(dot, Ov015_FxMul(ld, le));
    if (r < 0) r = -r;
    if (r >= lim) {
        *out = b;
        return;
    }
    f.x = d.x - e.x;
    f.y = d.y - e.y;
    f.z = d.z - e.z;
    VEC_MultAdd(0x52, &f, &e, &e);
    VEC_Normalize(&e, &e);
    VEC_MultAdd(ld, &e, &a, out);
}

}
