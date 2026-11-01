#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

extern "C" {

#define OB(self) LBIT(self, 0xc)

s32 func_ov000_0215fe60(ObjBase021cac0c_021cb6f0 *self) {
    s32 spd = 0x385;
    if (!self->vfunc_34()) {
        return 1;
    }
    switch (self->unk_04) {
    case 4:
        self->vfunc_1c();
        self->unk_04 = 5;
    case 5:
        if (self->vfunc_20()) {
            self->unk_04 = 6;
            self->vfunc_34();
        }
        break;
    case 7:
        self->vfunc_28();
        self->unk_04 = 6;
        break;
    case 0:
        self->vfunc_24();
        self->unk_04 = 1;
        break;
    case 1:
        OB(self).b0 = 1;
        if (OB(self).b1 == 1) {
            self->unk_04 = 7;
            break;
        }
        self->unk_04 = 8;
    case 8:
        self->unk_2c += 0x1000;
        self->unk_34 = FX_Div(self->unk_2c, self->unk_30);
        if (self->unk_34 >= 0x1000) {
            OB(self).b0 = 0;
            self->unk_2c = self->unk_30;
            self->unk_34 = 0x1000;
            self->unk_04 = 3;
        }
        spd = 0xcd;
        break;
    case 2:
        OB(self).b0 = 1;
        self->unk_04 = 9;
    case 9:
        self->unk_2c -= 0x1000;
        self->unk_34 = FX_Div(self->unk_2c, self->unk_30);
        if (self->unk_34 <= 0) {
            self->unk_2c = 0;
            self->unk_34 = 0;
            self->unk_04 = 7;
            return 0;
        }
        break;
    case 3:
        OB(self).b0 = 0;
        self->unk_04 = 10;
    case 10:
        self->unk_2c = self->unk_30;
        self->unk_34 = 0x1000;
        break;
    }
    if (OB(self).b7) {
        s32 tgt = self->unk_64;
        s32 d = tgt - self->unk_5c;
        if ((d < 0 ? -d : d) <= 0x1000) {
            self->unk_5c = tgt;
        } else {
            s32 step = LO_FX_MUL(d, spd);
            if ((step < 0 ? -step : step) < 0x1000) {
                step = step > 0 ? 0x1000 : -0x1000;
            }
            self->unk_5c += step;
        }
    } else {
        self->unk_5c = self->unk_64;
    }
    if (OB(self).b8) {
        if (self->unk_5c < self->unk_68) {
            self->unk_68 -= self->unk_6c;
            self->unk_6c += 0x100;
        } else {
            self->unk_68 = self->unk_5c;
            self->unk_6c = 0x1000;
        }
    }
    if (OB(self).b4) {
        s32 v;
        if (FX_Div(self->unk_5c, self->unk_60) <= self->unk_4c) {
            self->unk_44 += 0x222000;
            if (self->unk_44 >= 0x8000000) {
                self->unk_44 -= 0x8000000;
            }
            v = FX_SinCosTable_[((u16)(self->unk_44 >> 12) >> 4) * 2];
        } else {
            self->unk_44 = 0;
            v = 0;
        }
        self->unk_48 = v;
    }
    self->vfunc_38();
    if (OB(self).b6) {
        self->vfunc_2c();
        self->vfunc_30();
    }
    return 1;
}

}
