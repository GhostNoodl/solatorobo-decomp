#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

#define OB(self) LBIT(self, 0xc)

s32 func_ov000_0215fe60(VObj *self) {
    s32 spd = 0x385;
    if (!self->vfunc_34()) {
        return 1;
    }
    switch (LFLD(s32, self, 4)) {
    case 4:
        self->vfunc_1c();
        LFLD(s32, self, 4) = 5;
    case 5:
        if (self->vfunc_20()) {
            LFLD(s32, self, 4) = 6;
            self->vfunc_34();
        }
        break;
    case 7:
        self->vfunc_28();
        LFLD(s32, self, 4) = 6;
        break;
    case 0:
        self->vfunc_24();
        LFLD(s32, self, 4) = 1;
        break;
    case 1:
        OB(self).b0 = 1;
        if (OB(self).b1 == 1) {
            LFLD(s32, self, 4) = 7;
            break;
        }
        LFLD(s32, self, 4) = 8;
    case 8:
        LFLD(s32, self, 0x2c) += 0x1000;
        LFLD(s32, self, 0x34) = FX_Div(LFLD(s32, self, 0x2c), LFLD(s32, self, 0x30));
        if (LFLD(s32, self, 0x34) >= 0x1000) {
            OB(self).b0 = 0;
            LFLD(s32, self, 0x2c) = LFLD(s32, self, 0x30);
            LFLD(s32, self, 0x34) = 0x1000;
            LFLD(s32, self, 4) = 3;
        }
        spd = 0xcd;
        break;
    case 2:
        OB(self).b0 = 1;
        LFLD(s32, self, 4) = 9;
    case 9:
        LFLD(s32, self, 0x2c) -= 0x1000;
        LFLD(s32, self, 0x34) = FX_Div(LFLD(s32, self, 0x2c), LFLD(s32, self, 0x30));
        if (LFLD(s32, self, 0x34) <= 0) {
            LFLD(s32, self, 0x2c) = 0;
            LFLD(s32, self, 0x34) = 0;
            LFLD(s32, self, 4) = 7;
            return 0;
        }
        break;
    case 3:
        OB(self).b0 = 0;
        LFLD(s32, self, 4) = 10;
    case 10:
        LFLD(s32, self, 0x2c) = LFLD(s32, self, 0x30);
        LFLD(s32, self, 0x34) = 0x1000;
        break;
    }
    if (OB(self).b7) {
        s32 tgt = LFLD(s32, self, 0x64);
        s32 d = tgt - LFLD(s32, self, 0x5c);
        if ((d < 0 ? -d : d) <= 0x1000) {
            LFLD(s32, self, 0x5c) = tgt;
        } else {
            s32 step = LO_FX_MUL(d, spd);
            if ((step < 0 ? -step : step) < 0x1000) {
                step = step > 0 ? 0x1000 : -0x1000;
            }
            LFLD(s32, self, 0x5c) += step;
        }
    } else {
        LFLD(s32, self, 0x5c) = LFLD(s32, self, 0x64);
    }
    if (OB(self).b8) {
        if (LFLD(s32, self, 0x5c) < LFLD(s32, self, 0x68)) {
            LFLD(s32, self, 0x68) -= LFLD(s32, self, 0x6c);
            LFLD(s32, self, 0x6c) += 0x100;
        } else {
            LFLD(s32, self, 0x68) = LFLD(s32, self, 0x5c);
            LFLD(s32, self, 0x6c) = 0x1000;
        }
    }
    if (OB(self).b4) {
        s32 v;
        if (FX_Div(LFLD(s32, self, 0x5c), LFLD(s32, self, 0x60)) <= LFLD(s32, self, 0x4c)) {
            LFLD(s32, self, 0x44) += 0x222000;
            if (LFLD(s32, self, 0x44) >= 0x8000000) {
                LFLD(s32, self, 0x44) -= 0x8000000;
            }
            v = FX_SinCosTable_[((u16)(LFLD(s32, self, 0x44) >> 12) >> 4) * 2];
        } else {
            LFLD(s32, self, 0x44) = 0;
            v = 0;
        }
        LFLD(s32, self, 0x48) = v;
    }
    self->vfunc_38();
    if (OB(self).b6) {
        self->vfunc_2c();
        self->vfunc_30();
    }
    return 1;
}

}
