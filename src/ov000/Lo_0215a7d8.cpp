#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


extern "C" {

void func_ov000_0215a8c8(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);

void func_ov000_0215a7d8(Lo021cb5a8 *self, s32 unused, s32 *pos) {
    s16 z = self->posZ - 0x100;
    self->model->unk_158 = (void *)func_ov000_0215a8c8;
    self->model->flags |= 0x80000;
    self->model->flags |= 0x200000;
    MODEL_FLAGS(self->model)->alpha = 0x1e;
    {
        s32 px = pos[0];
        s32 py = pos[1];
        u8 *o = (u8 *)self->model;
        LFLD(s32, o, 0xfc) = px;
        LFLD(s32, o, 0x100) = py;
    }
    self->model->unk_150 = z;
    Model_PlayPart(self->model, 8);
    self->model->unk_158 = NULL;
}

}
