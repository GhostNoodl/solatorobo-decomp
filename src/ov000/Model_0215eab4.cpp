#include "ov000/ModelPart.h"
#include "ov000/UiObj.h"


extern "C" {

BOOL Model_IsReady(void *a, int b);
void func_ov000_0215ed18(UiPanel *self);

void Obj0215eab4_Draw(UiPanel *self) {
    s32 x;
    s32 y;
    if (!Model_IsReady(self->model, 0xffff)) {
        return;
    }
    if (!self->bits.b3) {
        func_ov000_0215ed18(self);
    }
    x = self->x;
    y = self->y;
    if (self->bits.centered) {
        x -= self->width >> 1;
    }
    self->model->unk_150 = self->z;
    if (self->bits.b3) {
        x -= (self->dx << 12) + 0x80000 - self->unk_24;
        y -= 0x60000;
        Model_SetPos(self->model, x, y);
        Model_PlayPart(self->model, 0);
    } else {
        x += self->dx << 12;
        y += self->dy << 12;
        Model_SetPos(self->model, x, y);
        Model_PlayPart(self->model, 5);
    }
}

}
