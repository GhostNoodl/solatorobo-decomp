#include "Main/Gfx/FieldMsg.h"
#include "ov000/TextList.h"

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        TextWin_Init(win);
    }
    return win;
}

void Obj021c64b4_SetText(TextList *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->panelText;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->panelText = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->panelText = TextWin_New();
    self->panelText->font = 8;
    win = self->panelText;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    self->panelText->noVram = 1;
    self->panelText->unk_4_8 = 0x1e;
    self->panelText->flag24 = 1;
    *(u32 *)((u8 *)self->panelText + 4) |= 0x400000; // bit 22 of the flags word
    self->panelText->rendering = 1;
}

}
