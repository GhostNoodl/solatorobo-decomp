#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"



extern "C" {

void func_02041c18(void *model, void *arg);

static inline void LoSetPos0214e3b4(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x << 12;
    LFLD(s32, m, 0x100) = y << 12;
}

void func_ov000_0214e3b4(Lo021caac8 *self, void *arg, s32 x, s32 y, u8 depth, u8 flip) {
    if ((void *)self->unk_b4 == NULL) {
        return;
    }
    if (flip) {
        MODEL_FLAGS(self->model)->unk_19 = 1;
        self->model->unk_150 = self->posZ - 0x110;
        MODEL_FLAGS(self->model)->unk_20 = 1;
        MODEL_FLAGS(self->unk_b4)->unk_19 = 1;
        self->unk_b4->unk_150 = self->posZ - 0x110;
        MODEL_FLAGS(self->unk_b4)->unk_20 = 1;
    } else {
        MODEL_FLAGS(self->model)->unk_19 = 1;
        self->model->unk_150 = self->posZ - 0x80;
        MODEL_FLAGS(self->model)->unk_20 = 0;
        MODEL_FLAGS(self->unk_b4)->unk_19 = 1;
        self->unk_b4->unk_150 = self->posZ - 0x80;
        MODEL_FLAGS(self->unk_b4)->unk_20 = 0;
    }
    x += self->vfunc_94() - 0x80;
    LoSetPos0214e3b4(self->model, x, y - 0x59);
    Model_PlayPart(self->model, 13);
    Model_PlayPart(self->model, 12);
    MODEL_FLAGS(self->model)->unk_20 = 0;
    MODEL_FLAGS(self->unk_b4)->polygon_id = depth;
    MODEL_FLAGS(self->unk_b4)->alpha = 30;
    MODEL_FLAGS(self->unk_b4)->unk_21 = 1;
    if (self->flags & 0x800000) {
        LoSetPos0214e3b4(self->unk_b4, x - 2, y - 0x5d);
        Model_PlayPart(self->unk_b4, 7);
        x += 10;
    }
    LoSetPos0214e3b4(self->unk_b4, x - 2, y - 0x5e);
    func_02041c18(self->unk_b4, LFLD(void *, arg, 0xc));
    Model_PlayPart(self->unk_b4, 6);
}

}
