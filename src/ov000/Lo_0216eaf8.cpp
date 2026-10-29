#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void func_ov000_0216e894(void *self);

void func_ov000_0216eaf8(void *self) {
    s32 t;
    if (LBIT(self, 0).b8 == 1) {
        return;
    }
    if (LBIT(self, 0).b10 == 1) {
        if (!LBIT(self, 0).b16) {
            func_02049a48(data_02097e4c, 0x21, -1, -1, -1);
            LBIT(self, 0).b16 = 1;
        }
        LFLD(s32, self, 0x3c) -= LFLD(s32, self, 0x38);
        LFLD(s32, self, 0x38) -= 0x4c5;
        if (LFLD(s32, self, 0x3c) > 0) {
            LFLD(s32, self, 0x3c) = 0;
            LFLD(s32, self, 0x34) = LO_FX_MUL(LFLD(s32, self, 0x34), 0xc00);
            if (LFLD(s32, self, 0x34) < 0x1000) {
                LBIT(self, 0).b11 = 1;
                LFLD(s32, self, 0x34) = 0;
            }
            LFLD(s32, self, 0x38) = LFLD(s32, self, 0x34);
        }
    }
    if (LBIT(self, 0).b11 != 1) {
        return;
    }
    LFLD(s32, self, 0x40) += 0x1000;
    t = FX_Div(LFLD(s32, self, 0x40), 0x2d000);
    if (t >= 0x1000) {
        t = 0x1000;
        if (LFLD(s32, self, 0x40) >= 0x55000) {
            LBIT(self, 0).b5 = 0;
            func_ov000_0216e894(self);
        }
    }
    LFLD(u16, self, 0x44) = ((s32)FX_SinCosTable_[(((s32)(t << 14)) >> 16) * 2] << 16) >> 12;
    if (LFLD(u16, self, 0x44) >= 0x4000) {
        LBIT(self, 0).b12 = 1;
        LFLD(s32, self, 0x28) = LFLD(s32, self, 0x1c);
    }
}

}
