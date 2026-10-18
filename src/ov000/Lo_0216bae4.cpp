#include "Main/Gfx/FieldMsg.h"

extern "C" {

void func_0204ca70(TextWin *win);
void *func_0203dd9c(u32 size);

static inline TextWin *LoTextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
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

typedef struct {
    s32 cnt;
    u32 text;
    TextWin *win;
} LoTextHolder;

void func_ov000_0216bae4(LoTextHolder *self, u32 text) {
    TextWin *win;
    if (self->win) {
        self->cnt++;
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
    win->unk_28 = 4;
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
    win->unk_74 = 0x2b9f;
    win->unk_76 = 0xc7f;
    win->noVram = 1;
    ((LoTwBits *)((u8 *)win + 4))->b22 = 1;
    win->unk_70 = -0x1000;
    win->flag24 = 1;
    win->rendering = 1;
    win->unk_4_30 = 1;
    func_0204ca70(win);
    self->win = win;
    self->cnt = 1;
}

}
