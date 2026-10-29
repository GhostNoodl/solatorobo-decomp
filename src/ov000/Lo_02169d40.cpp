#include "ov000/LoCommon.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
u32 func_0204045c(void);

void func_ov000_02169d40(void *self) {
    s32 s = LFLD(s32, self, 4);
    s32 v;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            LFLD(s32, self, 4) = 2;
        }
    }
    if (FX_Div(LFLD(s32, self, 0x5c), LFLD(s32, self, 0x60)) <= LFLD(s32, self, 0x4c)) {
        LFLD(s32, self, 0x44) += 0x222000;
        if (LFLD(s32, self, 0x44) >= 0x8000000) {
            LFLD(s32, self, 0x44) -= 0x8000000;
        }
        LFLD(s32, self, 0x48) = FX_SinCosTable_[((s32)(u16)(LFLD(s32, self, 0x44) >> 12) >> 4) * 2];
    } else {
        LFLD(s32, self, 0x44) = 0;
        LFLD(s32, self, 0x48) = 0;
    }
    if (LFLD(s32, self, 4) == 0xa) {
        if (++LFLD(u8, self, 0xa9) > 0x1e) {
            if (!((LFLD(u32, self, 0xc) & 0x10000) ? TRUE : FALSE)) {
                LBIT(self, 0xc).b1 = 1;
            }
        }
        LBIT(self, 0xc).b16 = 0;
    }
    if (LFLD(u32, self, 0xac) == 0) {
        return;
    }
    if (LFLD(u32, self, 0xac) & 1) {
        LFLD(u16, self, 0xaa) = func_0204045c();
    }
    LFLD(u32, self, 0xac)--;
}

}
