#include "ov002/ov002.h"

extern "C" {

extern Vec3 data_ov002_021ef0f8;

extern Vec3 data_ov002_021ef0d4;

void VEC_Add(void *a, void *b, void *c);

BOOL func_ov002_021e75f0(void *self) {
    void *n;
    void *c;
    u8 *m;
    n = NULL;
    c = FIELD(self, 0xc8, void *);
    if (c == NULL) {
        n = func_ov002_021e4ee4(self, 3, -1);
    } else if (FIELD(c, 0xe8, Bits8).b1) {
        n = func_ov002_021e4ee4(self, 3, FIELD(c, 0x18, s32));
    }
    if (n != NULL) {
        if (FIELD(self, 0xc8, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0xc8, void *));
        }
        func_ov002_021e61b4(n);
        FIELD(self, 0xc8, void *) = n;
    }
    m = FIELD(self, 0xc8, u8 *);
    if (m != NULL) {
        Vec3 pos;
        Vec3 a = data_ov002_021ef0f8;
        Vec3 b = data_ov002_021ef0d4;
        pos.x = FIELD(m, 0xdc, s32);
        pos.y = FIELD(m, 0xe0, s32);
        pos.z = FIELD(m, 0xe4, s32);
        MTX_MultVec33(&a, m + 0xb8, &a);
        VEC_Add(&pos, &a, &a);
        MTX_MultVec33(&b, m + 0xb8, &b);
        FIELD(self, 0x50, Vec3) = pos;
        FIELD(self, 0x5c, Vec3) = a;
        FIELD(self, 0x68, Vec3) = b;
    }
    return TRUE;
}

void func_ov002_021e772c(void *self, s32 deg) {
    s32 idx;
    FIELD(self, 0xb8, u16) = (u16)(((s64)deg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    FIELD(self, 0xb4, s32) = deg;
    idx = (u16)(FIELD(self, 0xb8, u16) >> 1);
    FIELD(self, 0xba, s16) = FX_SINCOS_TABLE[(idx >> 4) * 2];
    FIELD(self, 0xbc, s16) = FX_SINCOS_TABLE[(idx >> 4) * 2 + 1];
}

}
