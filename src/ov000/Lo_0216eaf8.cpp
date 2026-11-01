#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void func_ov000_0216e894(void *self);

struct Obj0216eaf8 {
    u8 unk_00[0x1c];
    s32 unk_1c;
    u8 unk_20[0x8];
    s32 unk_28;
    u8 unk_2c[0x8];
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    u16 unk_44;
};

void func_ov000_0216eaf8(Obj0216eaf8 *self) {
    s32 t;
    if (LBIT(self, 0).b8 == 1) {
        return;
    }
    if (LBIT(self, 0).b10 == 1) {
        if (!LBIT(self, 0).b16) {
            func_02049a48(data_02097e4c, 0x21, -1, -1, -1);
            LBIT(self, 0).b16 = 1;
        }
        self->unk_3c -= self->unk_38;
        self->unk_38 -= 0x4c5;
        if (self->unk_3c > 0) {
            self->unk_3c = 0;
            self->unk_34 = LO_FX_MUL(self->unk_34, 0xc00);
            if (self->unk_34 < 0x1000) {
                LBIT(self, 0).b11 = 1;
                self->unk_34 = 0;
            }
            self->unk_38 = self->unk_34;
        }
    }
    if (LBIT(self, 0).b11 != 1) {
        return;
    }
    self->unk_40 += 0x1000;
    t = FX_Div(self->unk_40, 0x2d000);
    if (t >= 0x1000) {
        t = 0x1000;
        if (self->unk_40 >= 0x55000) {
            LBIT(self, 0).b5 = 0;
            func_ov000_0216e894(self);
        }
    }
    self->unk_44 = ((s32)FX_SinCosTable_[(((s32)(t << 14)) >> 16) * 2] << 16) >> 12;
    if (self->unk_44 >= 0x4000) {
        LBIT(self, 0).b12 = 1;
        self->unk_28 = self->unk_1c;
    }
}

}
