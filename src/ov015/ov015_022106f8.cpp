#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);
s32 FX_Div(s32 a, s32 b);
s32 func_02049210(s32 t, s32 a, s32 b);

BOOL func_ov015_022106f8(u8 *self) {
    BOOL r = FALSE;
    switch (FLD(s32, self, 0x13c)) {
    case 0:
        FLD(s32, self, 0x140) = FLD(s32, self, 0x8);
        FLD(s32, self, 0x13c)++;
    case 1:
        if (--FLD(s32, self, 0x140) < 0) {
            FLD(s32, self, 0x140) = 0x28;
            FLD(s32, self, 0x13c)++;
            FLD(u8, self, 0x4) = 1;
        }
        break;
    case 2: {
        s32 t = FX_Div(FLD(s32, self, 0x140) << 12, 0x28000);
        FLD(s32, self, 0x1c) = 0x50000;
        FLD(s32, self, 0x20) = func_02049210(t, -0x46000, -0x66000);
        FLD(s32, self, 0x24) = -0x333;
        if (--FLD(s32, self, 0x140) >= 0) {
            break;
        }
        FLD(s32, self, 0x140) = 0;
        FLD(s32, self, 0x13c)++;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
    }
    case 3: {
        s32 y = Ov015_FxMul(FX_SinCosTable_[((FLD(s32, self, 0x140) * 0x3fff / 40) >> 4) * 2], 0x6000) - 0x46000;
        FLD(s32, self, 0x1c) = 0x50000;
        FLD(s32, self, 0x20) = y;
        FLD(s32, self, 0x24) = -0x333;
        FLD(s32, self, 0x140)++;
        if (FLD(s32, self, 0x140) > 0x28) {

            FLD(s32, self, 0x140) = 0x28;
            r = TRUE;
        }
        break;
    }
    }
    return r;
}


extern u8 *data_02097dc8;
s32 func_0204c2f4(void *p, s32 n, void *src);
void func_ov000_0215bb14(void *a, void *b);
void func_ov015_0220866c(u8 *self, void *msg);

BOOL func_ov015_02210860(u8 *self) {
    BOOL r = TRUE;
    FLD(s32, self, 0x1c) = 0x50000;
    FLD(s32, self, 0x20) = Ov015_FxMul(FX_SinCosTable_[((FLD(s32, self, 0x140) * 0x3fff / 80) >> 4) * 2], 0x6000) - 0x46000;
    FLD(s32, self, 0x24) = -0x333;
    FLD(s32, self, 0x140) = (FLD(s32, self, 0x140) + 1) % 80;
    VCALL(FLD(u8 *, self, 0x28))->v1c();
    VCALL(FLD(u8 *, self, 0x2c))->v1c();
    if (VCALL(FLD(u8 *, self, 0x28))->v0c() && (FLD(u16, data_02097dc8, 0x12) & 1)) {
        s32 n = ++FLD(s32, self, 0xb4);
        if (n < FLD(s32, self, 0xb0)) {
            if (FLD(u8 *, self, 0x28) != NULL && ((void **)(self + 0x30))[n] != NULL) {
                u8 *o;
                func_0204c2f4(self + 0xb8, 0x80, ((void **)(self + 0x30))[n]);
                func_ov000_0215bb14(FLD(u8 *, self, 0x28), self + 0xb8);
                VCALL(FLD(u8 *, self, 0x28))->v70();
                FLD(u32, FLD(u8 *, FLD(u8 *, self, 0x28), 0x84), 0x4) |= 0x4000000;
                o = FLD(u8 *, self, 0x28);
                VCALL(FLD(u8 *, o, 0x84))->v1c(FLD(s16, o, 0x64) + FLD(s32, o, 0x24) - 0x14, FLD(s16, o, 0x66) + FLD(s32, o, 0x28) - 0xc, -0xcbd);
                func_ov015_0220866c(FLD(u8 *, self, 0x2c), ((void **)(self + 0x30))[n]);
            }
        } else {
            r = FALSE;
        }
    }
    return r;
}

}
