#include "ov000/LoCommon.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/TextWin.h"
#include "ov000/UiObj.h"


extern "C" {

extern UiLabelStyle UiLabel_StyleTable[];
BOOL Model_IsReady(void *model, u32 id);
void func_ov000_0215f970(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx0);

void UiLabel_Draw(UiLabel *self) {
    s32 pos[3];
    TextWin *t;
    UiLabelStyle *e;

    if (!Model_IsReady(self->model, 0xffff)) {
        return;
    }
    e = &UiLabel_StyleTable[self->style];
    pos[0] = self->x;
    pos[1] = self->y;
    pos[2] = self->z;
    if (self->bits.centered) {
        pos[0] -= self->width >> 1;
    }
    self->model->unk_158 = (void *)func_ov000_0215f970;
    self->model->flags |= 0x80000;
    self->model->flags |= 0x200000;
    MODEL_FLAGS(self->model)->alpha = 0x1e;
    {
        s32 px = pos[0];
        s32 py = pos[1];
        Model *o = self->model;
        o->x = px << 12;
        o->y = py << 12;
    }
    self->model->unk_150 = pos[2] - 0x40;
    Model_PlayPart(self->model, e->part);
    self->model->unk_158 = NULL;
    pos[2] -= 0x80;
    func_ov000_0215f618(self, pos);
    t = self->text;
    pos[0] += (self->width - (s32)t->width) >> 1;
    pos[1] += (self->height - (s32)t->height) >> 1;
    t->posZ = self->z;
    self->text->unk_vf20(pos[0] - 1, pos[1] - 1);
    self->text->Render();
}

}
