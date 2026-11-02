#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
u32 Rand_GetGlobal(void);

void func_ov000_02169d40(Lo021cb798 *self) {
    s32 s = self->unk_04;
    s32 v;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 2;
        }
    }
    if (FX_Div(self->unk_5c, self->unk_60) <= self->unk_4c) {
        self->unk_44 += 0x222000;
        if (self->unk_44 >= 0x8000000) {
            self->unk_44 -= 0x8000000;
        }
        self->unk_48 = FX_SinCosTable_[((s32)(u16)(self->unk_44 >> 12) >> 4) * 2];
    } else {
        self->unk_44 = 0;
        self->unk_48 = 0;
    }
    if (self->unk_04 == 0xa) {
        if (++self->unk_a9 > 0x1e) {
            if (!((self->unk_0c & 0x10000) ? TRUE : FALSE)) {
                self->unk_0c_1 = 1;
            }
        }
        self->unk_0c_16 = 0;
    }
    if (self->unk_ac == 0) {
        return;
    }
    if (self->unk_ac & 1) {
        self->unk_aa = Rand_GetGlobal();
    }
    self->unk_ac--;
}

}
