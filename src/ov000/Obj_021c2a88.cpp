#include "ov000/LoCommon.h"
#include "Main/Gfx/FieldMsg.h"
#include "ov000/ListRow.h"

extern "C" {

void Hud021cca10_SetText(Hud021cca10 *self, char *arg) {
    TextWin *p;
    if (self->text == NULL) {
        p = (TextWin *)Heap_Alloc(0xb8);
        if (p != NULL) {
            VOBJ_SET_VTABLE(p, TextWin_vtbl);
            TextWin_Init(p);
        }
        self->text = p;
    }
    self->text->unk_vf08();
    self->text->font = 8;
    p = self->text;
    p->strPtr = arg;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    gGfxMgr->unk_004 = p->font;
    self->text->flags = (self->text->flags & ~0x1f00) | 0x1e00;
    self->text->unk_vf14();
    self->text->flags |= 0x40;
    self->text->flags |= 0x1000000;
    self->text->flags |= 0x400000;
    self->text->flags |= 0x200000;
    self->text->flags |= 0x4;
    self->str = arg;
}
}
