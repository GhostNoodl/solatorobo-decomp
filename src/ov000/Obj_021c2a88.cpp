#include "ov000/LoCommon.h"
#include "Main/Gfx/FieldMsg.h"

extern "C" {

struct Obj021c2a88 {
    u8 unk_00[0x38];
    TextWin *unk_38;
    u8 unk_3c[0x4];
    s32 unk_40;
};

void func_ov000_021c2a88(Obj021c2a88 *self, s32 arg) {
    TextWin *p;
    if (self->unk_38 == NULL) {
        p = (TextWin *)Heap_Alloc(0xb8);
        if (p != NULL) {
            VOBJ_SET_VTABLE(p, data_0208ba70);
            func_0204c7d0(p);
        }
        self->unk_38 = p;
    }
    self->unk_38->unk_vf08();
    self->unk_38->font = 8;
    p = self->unk_38;
    p->str = arg;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = p->font;
    self->unk_38->flags = (self->unk_38->flags & ~0x1f00) | 0x1e00;
    self->unk_38->unk_vf14();
    self->unk_38->flags |= 0x40;
    self->unk_38->flags |= 0x1000000;
    self->unk_38->flags |= 0x400000;
    self->unk_38->flags |= 0x200000;
    self->unk_38->flags |= 0x4;
    self->unk_40 = arg;
}
}
