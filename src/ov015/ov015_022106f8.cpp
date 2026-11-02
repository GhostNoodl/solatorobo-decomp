#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);
s32 FX_Div(s32 a, s32 b);
s32 func_02049210(s32 t, s32 a, s32 b);

BOOL func_ov015_022106f8(Ov015Msg *self) {
    BOOL r = FALSE;
    switch (self->unk_13c) {
    case 0:
        self->unk_140 = self->unk_08;
        self->unk_13c++;
    case 1:
        if (--self->unk_140 < 0) {
            self->unk_140 = 0x28;
            self->unk_13c++;
            self->unk_04 = 1;
        }
        break;
    case 2: {
        s32 t = FX_Div(self->unk_140 << 12, 0x28000);
        self->unk_1c = 0x50000;
        self->unk_20 = func_02049210(t, -0x46000, -0x66000);
        self->unk_24 = -0x333;
        if (--self->unk_140 >= 0) {
            break;
        }
        self->unk_140 = 0;
        self->unk_13c++;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
    }
    case 3: {
        s32 y = Ov015_FxMul(FX_SinCosTable_[((self->unk_140 * 0x3fff / 40) >> 4) * 2], 0x6000) - 0x46000;
        self->unk_1c = 0x50000;
        self->unk_20 = y;
        self->unk_24 = -0x333;
        self->unk_140++;
        if (self->unk_140 > 0x28) {

            self->unk_140 = 0x28;
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
void func_ov015_0220866c(Ov015UiText *self, void *msg);

BOOL func_ov015_02210860(Ov015Msg *self) {
    BOOL r = TRUE;
    self->unk_1c = 0x50000;
    self->unk_20 = Ov015_FxMul(FX_SinCosTable_[((self->unk_140 * 0x3fff / 80) >> 4) * 2], 0x6000) - 0x46000;
    self->unk_24 = -0x333;
    self->unk_140 = (self->unk_140 + 1) % 80;
    VCALL(self->unk_28)->v1c();
    VCALL(self->unk_2c)->v1c();
    if (VCALL(self->unk_28)->v0c() && (FLD(u16, data_02097dc8, 0x12) & 1)) {
        s32 n = ++self->unk_b4;
        if (n < self->unk_b0) {
            if (self->unk_28 != NULL && self->unk_30[n] != NULL) {
                u8 *o;
                func_0204c2f4(self->unk_b8, 0x80, self->unk_30[n]);
                func_ov000_0215bb14(self->unk_28, self->unk_b8);
                VCALL(self->unk_28)->v70();
                FLD(u32, self->unk_28->unk_84, 0x4) |= 0x4000000;
                o = ((u8 *)self->unk_28);
                VCALL(FLD(u8 *, o, 0x84))->v1c(FLD(s16, o, 0x64) + FLD(s32, o, 0x24) - 0x14, FLD(s16, o, 0x66) + FLD(s32, o, 0x28) - 0xc, -0xcbd);
                func_ov015_0220866c(self->unk_2c, self->unk_30[n]);
            }
        } else {
            r = FALSE;
        }
    }
    return r;
}

}
