#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "ov000/LoTimer.h"



extern "C" {

void func_02041c18(void *m, int a);
void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg);

static inline void LoPlace(LoTimer *self, s32 x, s32 y) {
    MODEL_FLAGS(self->unk_10)->unk_21 = 1;
    self->unk_10->unk_150 = -0x1f80;
    Model_SetPos(self->unk_10, x << 12, y << 12);
}

void LoTimer_Draw(LoTimer *self) {
    Model *m;
    s32 st = self->state;
    s32 s;
    if (st != 7 && st != 8 && st != 9) {
        return;
    }
    {
        s32 y;
        s32 x;
        x = (LO_FX_MUL(self->slide, 0x80000) >> 12) - 0x80;
        y = (self->unk_4c - 0x60000) >> 12;
        if (self->b10 == 1) {
            LoPlace(self, x + 0xbd, y + 0x1e + (self->unk_3c >> 12));
            Model_PlayPart(self->unk_10, 0xf);
            MODEL_FLAGS(self->unk_10)->unk_21 = 0;
        }
        MODEL_FLAGS(self->unk_10)->alpha = 0x1e;
        self->unk_10->unk_150 = -0x2000;
        Model_SetPos(self->unk_10, (x + 0xff) << 12, (y + 0x18) << 12);
        Model_PlayPart(self->unk_10, 0xc);
        func_02041c18(self->unk_14, self->shownTime);
        Model_SetPos(self->unk_14, (x + 0xf7) << 12, (y + 0x24) << 12);
        m = self->unk_14;
        Model_PlayPart(m, 0x1f);
        if (self->b8 == 1) {
            s = LO_FX_MUL(self->unk_3c, 0x1000);
            MTX_Identity22_(&self->unk_14->mtx[0]);
            MTX_ScaleApply22(&self->unk_14->mtx[0], &self->unk_14->mtx[0], s + 0x1000, s + 0x1000);
            self->unk_14->color = 0x1098;
            Model_PlayPartF(self->unk_14, 0x1e, 1);
        } else {
            if (self->b9 == 1) {
                self->unk_14->color = 0x1098;
            }
            Model_PlayPart(self->unk_14, 0x1e);
        }
        self->unk_14->color = 0x7fff;
        if (self->unk_28 == 0) {
            return;
        }
        Model_SetPos(self->unk_14, (x + 0xc9) << 12, (y + 9) << 12);
        Model_PlayPart(self->unk_14, 0x20);
        func_02041c18(self->unk_14, self->unk_28);
        Model_SetPos(self->unk_14, (x + 0xf7) << 12, (y + 0xf) << 12);
        Model_PlayPart(self->unk_14, 0x1f);
        if (self->b11 == 1) {
            self->unk_14->mtxFunc = (void *)func_ov000_0216d9dc;
            if (self->b12 == 1) {
                self->unk_14->color = 0x7792;
            }
            Model_PlayPartF(self->unk_14, 0x1e, 1);
            self->unk_14->color = 0x7fff;
            self->unk_14->mtxFunc = NULL;
        } else {
            Model_PlayPart(self->unk_14, 0x1e);
        }
    }
}

}
