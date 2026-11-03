#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

void UiList_Setup(UiList *self);

void UiList021cb4a8_Setup(UiList021cb4a8 *self) {
    s32 v;
    self->posX = (self->flags & 0x4000000) ? 0 : 0xc;
    self->width = 0x100 - self->posX * 2;
    UiList_Setup(self);
    v = self->width;
    self->slideMode = 1;
    self->slideX = v + 0x10;
    self->slideY = 0;
    self->slideZ = 0;
    self->panel->width = (v - 0x10) << 12;
}

void UiList021cb4a8_SetLabel(UiList021cb4a8 *self, u32 text) {
    UiLabel *p = (UiLabel *)Heap_Alloc(sizeof(UiLabel));
    if (p != NULL) {
        UiLabel_Reset(p);
    }
    self->unk_d4 = p;
    if (self->flag6 ? TRUE : FALSE) {
        self->unk_d4->bits.altFrame = 1;
    }
    UiLabel_SetText(self->unk_d4, text);
    self->unk_d4->width = self->unk_d4->text->width + 0x10;
}

}
