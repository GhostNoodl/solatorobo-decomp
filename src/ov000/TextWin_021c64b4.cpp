#include "Main/Gfx/FieldMsg.h"

typedef struct {
    u8 pad_00[0xa0];
    TextWin *unk_a0;
} Obj021c64b4;

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

void func_ov000_021c64b4(Obj021c64b4 *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->unk_a0;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->unk_a0 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_a0 = TextWin_New();
    self->unk_a0->font = 8;
    win = self->unk_a0;
    win->str = text;
    win->unk_4c = func_0204c4fc(win->font, win->spacing, win->str, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    self->unk_a0->noVram = 1;
    self->unk_a0->unk_4_8 = 0x1e;
    self->unk_a0->flag24 = 1;
    *(u32 *)((u8 *)self->unk_a0 + 4) |= 0x400000; // bit 22 of the flags word
    self->unk_a0->rendering = 1;
}

}
