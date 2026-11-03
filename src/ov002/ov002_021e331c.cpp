#include "ov002/ov002.h"

extern "C" {

extern VFunc TextWin_vtbl[];

void TextWin_Init(void *p);

s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);

void Obj021f002c_CreateText(Obj021f002c *self) {
    Ov002Text2 *p;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->text);
        HEAP_POP(saved);
    }
    p = (Ov002Text2 *)Heap_Alloc(0xb8);
    if (p != NULL) {
        *(VFunc **)p = TextWin_vtbl;
        TextWin_Init(p);
    }
    self->text = p;
    p->font = 8;
    p = self->text;
    p->str = (s32)self->str;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, p->unk_37 != 0);
    gGfxMgr->unk_004 = p->font;
    self->text->flags = (self->text->flags & ~0x1f00) | 0x1e00;
    self->text->flags |= 0x40;
    self->text->vfunc_14();
    self->text->flags |= 0x1000000;
    self->text->flags |= 0x400000;
    self->text->flags |= 0x200000;
    self->text->unk_2c = self->unk_44 ? 0 : 0xe;
    self->text->flags |= 0x4;
}

}
