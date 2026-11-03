#include "ov006/Caption.h"

extern "C" {

// Same caption draw as the inline in ov006_021e1bb4.cpp, with the statements
// in the order that reproduces the target's scheduling.
void func_ov006_021e0b80(ov006_Caption *self) {
    if (self->visible) {
        const ov006_CaptionEntry *e = &ov006_CaptionTable[self->kind];
        TextWin *anim = self->label;
        s32 x;
        s32 y;
        s32 bx = self->textX;
        s32 by = self->textY;
        bx += 0x80;
        x = self->x + self->ofsX;
        y = self->y + self->ofsY;
        s32 w = e->width;
        w -= anim->width;
        s32 h = e->height;
        bx += w >> 1;
        h -= anim->height;
        by += 0x60;
        by += h >> 1;
        anim->unk_vf20(x + bx, y + by);
        self->label->Render();
        if (self->model != NULL) {
            ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
            Model_PlayPart(self->model, e->part);
        }
    }
}

}
