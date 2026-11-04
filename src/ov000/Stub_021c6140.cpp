#include "ov000/TextList.h"

extern "C" {

void TextList_Init(TextList *self) {
    s32 zero = 0;
    self->rows = NULL;
    self->cur = NULL;
    self->decided = zero;
    self->count = zero;
    self->index = zero;
    self->panel = NULL;
    self->panelText = NULL;
    self->panelWidth = 0xd2;
    self->panelY = 0x18;
    self->bounceTime = zero;
    self->bounce = zero;
    self->rowWidth = 0xb4;
    self->dir = zero;
    self->timer = zero;
    self->lift = zero;
    {
        TextListFlags f;
        *(u32 *)&f = zero;
        f.showCursor = 1;
        self->listFlags = f;
    }
    self->onDecide = NULL;
    self->onCursor = NULL;
    self->unk_d0 = zero;
}

}
