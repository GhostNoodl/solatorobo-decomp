#include "Main/Gfx/FieldMsg.h"

typedef struct {
    u8 pad_00[0x30];
    TextWin *unk_30;
} Obj021c5fd0;

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

void func_ov000_021c5fd0(Obj021c5fd0 *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->unk_08;
        p = self->unk_30;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->unk_30 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_30 = TextWin_New();
    self->unk_30->unk_28 = 8;
    win = self->unk_30;
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
    self->unk_30->unk_2c = 0;
    self->unk_30->noVram = 1;
    self->unk_30->flag24 = 1;
    *(u32 *)((u8 *)self->unk_30 + 4) |= 0x400000; // bit 22 of the flags word
    self->unk_30->rendering = 1;
}

}
