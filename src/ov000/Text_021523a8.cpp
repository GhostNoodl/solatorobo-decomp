#include "ov000/LoCommon.h"
#include "Main/Gfx/TextWin.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {
extern u8 data_0208ba70[];
void func_0204c7d0(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);


void UiObj_SetTitle(UiObj *self, s32 arg) {
    TextWin *p;
    LO_FREE_V(self, 0x14);
    p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    self->title = (VObj *)p;
    p->font = 8;
    p = (TextWin *)self->title;
    p->str = arg;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = ((s32)p->font);
    LFLD(u16, self->title, 0x74) = 0x7fff;
    LFLD(u16, self->title, 0x76) = 0x67f;
    LFLD(u32, self->title, 0x4) |= 0x40;
    LFLD(u32, self->title, 0x4) |= 0x1000000;
    LFLD(u32, self->title, 0x4) |= 0x400000;
    LFLD(u32, self->title, 0x4) |= 0x40000000;
    LFLD(u32, self->title, 0x4) |= 0x4;
    func_0204ca70(((u8 *)self->title));
}

void UiObj_SetCaption(UiObj *self, const char *src) {
    TextWin *p;
    char buf[0x100];
    char *d;
    LO_FREE_V(self, 0x18);
    p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    self->caption = (VObj *)p;
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
    LFLD(s32, self->caption, 0x28) = 4;
    p = (TextWin *)self->caption;
    p->str = (u32)buf;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = ((s32)p->font);
    LFLD(u32, self->caption, 0x4) |= 0x40;
    LFLD(u32, self->caption, 0x4) |= 0x1000000;
    LFLD(u32, self->caption, 0x4) |= 0x400000;
    LFLD(u32, self->caption, 0x4) |= 0x40000000;
    LFLD(u32, self->caption, 0x4) |= 0x4;
    func_0204ca70(((u8 *)self->caption));
    LFLD(char *, self->caption, 0x24) = NULL;
    self->scrollPos = 0;
    self->scrollLen = LFLD(s32, self->caption, 0x44) + 0x40;
    if (self->scrollLen + 0x68 < 0x100) {
        self->scrollLen = 0x98;
    }
}
}
