#include "Main/Gfx/FieldMsg.h"

typedef struct {
    u8 pad_00[0x34];
    TextWin *unk_34;
} Obj021c2c0c;

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

void func_ov000_021c2c0c(Obj021c2c0c *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->unk_34;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->unk_34 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_34 = TextWin_New();
    self->unk_34->font = 8;
    win = self->unk_34;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    self->unk_34->unk_4_8 = 0x1e;
    self->unk_34->unk_vf14();
    self->unk_34->noVram = 1;
    self->unk_34->flag24 = 1;
    *(u32 *)((u8 *)self->unk_34 + 4) |= 0x400000; // bit 22 of the flags word
    self->unk_34->rendering = 1;
}

}
