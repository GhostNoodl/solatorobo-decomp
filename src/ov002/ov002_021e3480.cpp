#include "ov002/ov002.h"

extern "C" {

void Ov002RowList_Setup(Ov002RowList *self) {
    LoBase021ccb54_021ccbe0_Setup(self);
    self->height = self->rows * 15 + 0xc;
    self->shape = data_ov002_021ef038;
    self->shapeCount = 5;
    self->unk_b4 -= 0xc000;
    self->unk_b0 = self->width - (self->unk_b4 >> 12) + 0xc;
    self->unk_90->width = self->unk_b0 << 12;
    self->unk_b8 = 0x6000;
    self->unk_c0 = (self->height - 8) << 12;
    Obj021c4ab8_UpdateScrollBar(self);
}

}
