#include "Main/Gfx/FieldMsg.h"
#include "ov000/LoTicker.h"

extern "C" {

void func_0204ca70(TextWin *win);
void *Heap_Alloc(u32 size);

static inline TextWin *LoTextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

typedef struct {
    u32 lo : 22;
    u32 b22 : 1;
    u32 hi : 9;
} LoTwBits;

void func_ov000_0216bae4(LoTextHolder *self, void *text) {
    TextWin *win;
    if (self->win) {
        self->count++;
        return;
    }
    if (!text) {
        text = self->text;
    } else {
        self->text = text;
    }
    if (!text) {
        return;
    }
    win = LoTextWin_New();
    win->font = 4;
    win->str = (u32)text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    win->color0 = 0x2b9f;
    win->color1 = 0xc7f;
    win->noVram = 1;
    ((LoTwBits *)((u8 *)win + 4))->b22 = 1;
    win->posZ = -0x1000;
    win->flag24 = 1;
    win->rendering = 1;
    win->unk_4_30 = 1;
    func_0204ca70(win);
    self->win = win;
    self->count = 1;
}

}
