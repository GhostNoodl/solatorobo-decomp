#include "Main/Gfx/FieldMsg.h"
#include "Main/Res/ResMgr.h"
#include "ov000/VObj.h"
#include "ov000/FieldMgr.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
char *func_0206e200(LangBlockB *b);
void TextWin_InitLines(TextWin *win, s32 a);
s32 FX_Div(s32 a, s32 b);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        TextWin_Init(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
}

struct Obj02167d64 {
    u8 unk_00[0x40];
    TextWin *unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
};

void func_ov000_02167d64(Obj02167d64 *self) {
    char *str = func_0206e200(data_ov000_021ccd6c->blockB);
    TextWin *win;
    switch (self->unk_44) {
    case 4:
        {
            void *saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->heapHi;
            if ((VObj *)self->unk_40 != NULL) {
                VObj *p_ = (VObj *)self->unk_40;
                if (p_ != NULL) {
                    p_->vfunc_04();
                }
                self->unk_40 = NULL;
            }
            data_02097dd0->cur = saved;
        }
        self->unk_48 = 0;
        self->unk_4c = 0;
        if (str == NULL || str[0] == 0) {
            return;
        }
        win = TextWin_New();
        self->unk_40 = win;
        win->font = 7;
        self->unk_40->unk_2c = 0;
        self->unk_40->unk_34 = 0;
        SetText(self->unk_40, (u32)str);
        TextWin_InitLines(self->unk_40, 8);
        self->unk_40->rendering = 1;
        self->unk_44 = 8;
        return;
    case 3:
        str = NULL;
    case 8:
        if (str == NULL || str[0] == 0 || STD_CompareString((const char *)self->unk_40->str, str) != 0) {
            self->unk_48 -= 0x1000;
        } else {
            self->unk_48 += 0x1000;
        }
        self->unk_4c = FX_Div(self->unk_48, 0xc000);
        if (self->unk_4c < 0) {
            self->unk_48 = 0;
            self->unk_4c = 0;
            self->unk_44 = 4;
            return;
        }
        if (self->unk_4c > 0x1000) {
            self->unk_48 = 0xc000;
            self->unk_4c = 0x1000;
            self->unk_44 = 7;
        }
        return;
    case 7:
        if (str != NULL && str[0] != 0 && STD_CompareString((const char *)self->unk_40->str, str) == 0) {
            return;
        }
        self->unk_44 = 3;
        break;
    }
}

}
