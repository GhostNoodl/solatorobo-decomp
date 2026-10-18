#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
s32 func_02012ab8(s32 a, s32 b);
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
        s32 t = func_02012ab8(FLD(s32, self, 0x140) << 12, 0x28000);
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

}
