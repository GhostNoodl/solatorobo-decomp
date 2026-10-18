#include "ov000/ModelPart.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 rest : 28;
    s32 x;
    s32 y;
    s32 color;
    s32 w;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    Model *model;
} Obj0215eab4;

extern "C" {

BOOL func_02054f10(void *a, int b);
void func_ov000_0215ed18(Obj0215eab4 *self);

void func_ov000_0215eab4(Obj0215eab4 *self) {
    s32 x;
    s32 y;
    if (!func_02054f10(self->model, 0xffff)) {
        return;
    }
    if (!self->b3) {
        func_ov000_0215ed18(self);
    }
    x = self->x;
    y = self->y;
    if (self->b0) {
        x -= self->w >> 1;
    }
    self->model->unk_150 = self->color;
    if (self->b3) {
        x -= (self->unk_18 << 12) + 0x80000 - self->unk_24;
        y -= 0x60000;
        Model_SetPos(self->model, x, y);
        Model_PlayPart(self->model, 0);
    } else {
        x += self->unk_18 << 12;
        y += self->unk_1c << 12;
        Model_SetPos(self->model, x, y);
        Model_PlayPart(self->model, 5);
    }
}

}
