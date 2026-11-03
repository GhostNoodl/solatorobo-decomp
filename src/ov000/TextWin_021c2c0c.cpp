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

void func_ov000_021c2c0c(ListRowGauge *self, u32 text) {
    TextWin *win;
    {
        void *saved = gSysState->cur;
        TextWin *p;
        gSysState->cur = gSysState->heapHi;
        p = self->label;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->label = NULL;
        }
        gSysState->cur = saved;
    }
    self->label = TextWin_New();
    self->label->font = 8;
    win = self->label;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    gGfxMgr->unk_004 = win->font;
    self->label->unk_4_8 = 0x1e;
    self->label->unk_vf14();
    self->label->noVram = 1;
    self->label->flag24 = 1;
    *(u32 *)((u8 *)self->label + 4) |= 0x400000; // bit 22 of the flags word
    self->label->rendering = 1;
}

}
