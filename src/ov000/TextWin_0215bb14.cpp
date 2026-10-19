#include "Main/Gfx/FieldMsg.h"
#include "Main/Res/ResMgr.h"
#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 rest : 25;
} Bits0215bb14;

extern "C" {
extern const u32 data_0208bb1c[];
void func_0204f49c(void *win);
void func_0204ca70(TextWin *win);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline TextWinEx *TextWinEx_New(void) {
    TextWinEx *win = (TextWinEx *)func_0203dd9c(0x3dc);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
        *(const u32 **)win = data_0208bb1c;
        func_0204f49c(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
}

static inline void SetPages(TextWinEx *win, u32 text) {
    win->unk_3d8 = text;
    win->page = 0;
    win->numPages = 1;
}

void func_ov000_0215bb14(VObj *self, u32 text) {
    BOOL flag;
    LFLD(u32, self, 0xc) &= ~0x40000;
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        if (LFLD(VObj *, self, 0x84) != NULL) {
            VObj *p_ = LFLD(VObj *, self, 0x84);
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            LFLD(VObj *, self, 0x84) = NULL;
        }
        data_02097dd0->cur = saved;
    }
    if (LFLD(u32, self, 0xc) & 0x80000) {
        TextWin *win = TextWin_New();
        LFLD(TextWin *, self, 0x84) = win;
        win->unk_28 = LFLD(u32, self, 0x1c);
        LFLD(TextWin *, self, 0x84)->unk_38 = self->vfunc_3c();
        SetText(LFLD(TextWin *, self, 0x84), text);
        LFLD(TextWin *, self, 0x84)->noVram = 1;
        LFLD(TextWin *, self, 0x84)->flag24 = 1;
        LFLD(TextWin *, self, 0x84)->unk_4_30 = 1;
        LFLD(TextWin *, self, 0x84)->rendering = 1;
    } else {
        TextWinEx *win = TextWinEx_New();
        LFLD(TextWinEx *, self, 0x84) = win;
        win->unk_28 = LFLD(u32, self, 0x1c);
        LFLD(TextWinEx *, self, 0x84)->unk_38 = self->vfunc_3c();
        SetPages(LFLD(TextWinEx *, self, 0x84), text);
    }
    {
        s32 dx = self->vfunc_30();
        s32 dy = self->vfunc_34();
        LFLD(TextWin *, self, 0x84)->unk_vf20(LFLD(s16, self, 0x64) + dx, LFLD(s16, self, 0x66) + dy);
    }
    LFLD(TextWin *, self, 0x84)->unk_2c = 0;
    *(u32 *)((u8 *)LFLD(TextWin *, self, 0x84) + 4) |= 0x800000;
    flag = FALSE;
    if (LFLD(Bits0215bb14, self, 0xc).b6) {
        flag = TRUE;
    }
    if (flag) {
        LFLD(TextWin *, self, 0x84)->flag31 = 1;
    }
    if (LFLD(u32, self, 0xc) & 0x80000) {
        func_0204ca70(LFLD(TextWin *, self, 0x84));
    }
}

}
