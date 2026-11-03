#include "Main/Gfx/FieldMsg.h"
#include "ov000/ListRow.h"

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = TextWin_vtbl;
        TextWin_Init(win);
    }
    return win;
}

void func_ov000_021c5fd0(ListRowLabel *self, u32 text) {
    TextWin *win;
    {
        void *saved = gSysState->cur;
        TextWin *p;
        gSysState->cur = gSysState->heapHi;
        p = self->text;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->text = NULL;
        }
        gSysState->cur = saved;
    }
    self->text = TextWin_New();
    self->text->font = 8;
    win = self->text;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    gGfxMgr->unk_004 = win->font;
    self->text->unk_2c = 0;
    self->text->noVram = 1;
    self->text->flag24 = 1;
    *(u32 *)((u8 *)self->text + 4) |= 0x400000; // bit 22 of the flags word
    self->text->rendering = 1;
}

}
