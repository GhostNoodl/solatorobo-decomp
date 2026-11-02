#include "Main/Gfx/FieldMsg.h"
#include "ov000/ListRow.h"

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

void func_ov000_021c2c0c(ListRowGauge *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->label;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->label = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->label = TextWin_New();
    self->label->font = 8;
    win = self->label;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    self->label->unk_4_8 = 0x1e;
    self->label->unk_vf14();
    self->label->noVram = 1;
    self->label->flag24 = 1;
    *(u32 *)((u8 *)self->label + 4) |= 0x400000; // bit 22 of the flags word
    self->label->rendering = 1;
}

}
