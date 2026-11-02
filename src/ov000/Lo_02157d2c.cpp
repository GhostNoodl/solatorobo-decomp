#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

void func_ov000_02157d2c(UiList021cb4a8 *self, u32 text) {
    UiLabel *p = (UiLabel *)Heap_Alloc(sizeof(UiLabel));
    if (p) {
        UiLabel_Reset(p);
    }
    self->unk_d8 = p;
    if (self->flag6 ? TRUE : FALSE) {
        self->unk_d8->bits.altFrame = 1;
    }
    self->unk_d8->bits.centered = 1;
    func_ov000_0215f0ec(self->unk_d8, text);
    {
        UiLabel *q = self->unk_d8;
        q->width = q->text->width + 0x10;
    }
}

}
