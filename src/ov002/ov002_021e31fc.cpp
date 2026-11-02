#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void func_ov002_021e31fc(Obj021f002c *self) {
    Model *model;
    s32 x;
    s32 y;
    s32 z;
    if (self->state != 1) {
        return;
    }
    if (!self->shown) {
        return;
    }
    y = self->y + ((self->height - self->text->height) << 11);
    z = self->z;
    x = self->x;
    if (self->model != NULL) {
        Model_SetPos(self->model, ((x >> 12) - 0x7b) << 12, ((y >> 12) - 0x59) << 12);
        self->model->unk_150 = z;
        model = self->model;
        Model_PlayPart(model, self->part);
        x += 0xc000;
    }
    self->text->vfunc_20(x >> 12, y >> 12);
    self->text->posZ = z;
    self->text->vfunc_90();
}

}
