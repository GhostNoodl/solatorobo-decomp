#include "ov000/LoCommon.h"
#include "Main/Gfx/TextWin.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {
extern u8 data_0208ba70[];
void TextWin_Init(TextWin *win);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_RenderToVram(TextWin *win);


void UiObj_SetTitle(UiObj *self, s32 arg) {
    TextWin *p;
    HEAP_DELETE(TextWin *, self->title, p->unk_vf04());
    p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        TextWin_Init(p);
    }
    self->title = p;
    p->font = 8;
    p = self->title;
    p->str = arg;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = ((s32)p->font);
    self->title->color0 = 0x7fff;
    self->title->color1 = 0x67f;
    self->title->flags |= 0x40;
    self->title->flags |= 0x1000000;
    self->title->flags |= 0x400000;
    self->title->flags |= 0x40000000;
    self->title->flags |= 0x4;
    TextWin_RenderToVram(self->title);
}

void UiObj_SetCaption(UiObj *self, const char *src) {
    TextWin *p;
    char buf[0x100];
    char *d;
    HEAP_DELETE(TextWin *, self->caption, p->unk_vf04());
    p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        TextWin_Init(p);
    }
    self->caption = p;
    d = buf;
    while (*src != 0) {
        if (*src != '\n') {
            *d++ = *src;
        } else {
            *d++ = ' ';
        }
        src++;
    }
    *d = 0;
    self->caption->font = 4;
    p = self->caption;
    p->str = (u32)buf;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = ((s32)p->font);
    self->caption->flags |= 0x40;
    self->caption->flags |= 0x1000000;
    self->caption->flags |= 0x400000;
    self->caption->flags |= 0x40000000;
    self->caption->flags |= 0x4;
    TextWin_RenderToVram(self->caption);
    self->caption->str = 0;
    self->scrollPos = 0;
    self->scrollLen = self->caption->width + 0x40;
    if (self->scrollLen + 0x68 < 0x100) {
        self->scrollLen = 0x98;
    }
}
}
