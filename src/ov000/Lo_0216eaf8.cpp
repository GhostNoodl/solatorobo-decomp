#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/LoTimer.h"

extern "C" {

extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];

void func_ov000_0216eaf8(LoTimer *self) {
    s32 t;
    if (self->b8 == 1) {
        return;
    }
    if (self->b10 == 1) {
        if (!self->b16) {
            SndMgr_PlayVolume(data_02097e4c, 0x21, -1, -1, -1);
            self->b16 = 1;
        }
        self->unk_3c -= self->unk_38;
        self->unk_38 -= 0x4c5;
        if (self->unk_3c > 0) {
            self->unk_3c = 0;
            self->unk_34 = LO_FX_MUL(self->unk_34, 0xc00);
            if (self->unk_34 < 0x1000) {
                self->b11 = 1;
                self->unk_34 = 0;
            }
            self->unk_38 = self->unk_34;
        }
    }
    if (self->b11 != 1) {
        return;
    }
    self->unk_40 += 0x1000;
    t = FX_Div(self->unk_40, 0x2d000);
    if (t >= 0x1000) {
        t = 0x1000;
        if (self->unk_40 >= 0x55000) {
            self->b5 = 0;
            LoTimer_Finish(self);
        }
    }
    self->unk_44 = ((s32)FX_SinCosTable_[(((s32)(t << 14)) >> 16) * 2] << 16) >> 12;
    if (self->unk_44 >= 0x4000) {
        self->b12 = 1;
        self->unk_28 = self->time;
    }
}

}
