#include "ov006/Caption.h"

extern "C" {

// Same caption draw as the inline in ov006_021e1bb4.cpp, with the statements
// in the order that reproduces the target's scheduling.
void func_ov006_021e0b80(ov006_Caption *self) {
    if (self->visible) {
        const ov006_CaptionEntry *e = &data_ov006_021eb824[self->kind];
        ov006_Anim *anim = self->label;
        s32 x;
        s32 y;
        s32 bx = self->textX;
        s32 by = self->textY;
        bx += 0x80;
        x = self->x + self->ofsX;
        y = self->y + self->ofsY;
        s32 w = e->width;
        w -= *(int *)anim->unk44;
        s32 h = e->height;
        bx += w >> 1;
        h -= *(int *)anim->unk48;
        by += 0x60;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->label, 90);
        if (self->model != NULL) {
            ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
            Model_PlayPart(self->model, e->part);
        }
    }
}

}
