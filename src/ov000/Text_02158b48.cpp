#include "ov000/LoCommon.h"
#include "Main/Gfx/FieldMsg.h"
#include "nitro/std.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {
extern char data_ov000_021cabf4[];
void UiList_Setup(UiList *self);

void Lo021cb3a8_Setup(Lo021cb3a8 *self) {
    u16 line;
    BOOL done;
    char *p;
    char *s;
    UiListItem *n;
    self->posX = (0x100 - self->width) >> 1;
    line = 0;
    done = FALSE;
    if (self->str == NULL) {
        self->strSize = STD_GetStringLength(self->srcStr) + 1;
        self->str = (char *)Heap_AllocHi(self->strSize, 4);
        STD_CopyString(self->str, self->srcStr);
    }
    s = self->str;
    do {
        p = STD_SearchString(s, data_ov000_021cabf4);
        if (p != NULL) {
            *p = 0;
        } else {
            done = TRUE;
        }
        self->vfunc_74(s, line, 0xffff, 0xffff);
        s = p + 1;
        line++;
    } while (!done && *s != 0);
    UiList_Setup(self);
    self->panel->width = (self->width - 0x10) << 12;
    for (n = self->items; n != NULL; n = (UiListItem *)((u8 *)n->next)) {
        if (n->id == 0) {
            break;
        }
    }
    self->vfunc_a8(n);
}
}

extern "C" {
void TextWin_RenderToVram(void *p);

void Lo021cb3a8_SetText(Lo021cb3a8 *self, s32 arg) {
    TextWin *p;
    HEAP_DELETE(TextWin *, self->text, p->unk_vf04());
    p = (TextWin *)Heap_Alloc(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        TextWin_Init(p);
    }
    self->text = p;
    p->font = 8;
    p = self->text;
    p->str = arg;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = p->font;
    self->text->flags |= 0x40;
    self->text->flags |= 0x1000000;
    self->text->flags |= 0x400000;
    self->text->flags |= 0x40000000;
    self->text->flags |= 0x4;
    TextWin_RenderToVram(self->text);
}
}
