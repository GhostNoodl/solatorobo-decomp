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
extern const u32 TextWinEx_vtbl[];
void func_0204f49c(void *win);
void TextWin_RenderToVram(TextWin *win);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = TextWin_vtbl;
        TextWin_Init(win);
    }
    return win;
}

static inline TextWinEx *TextWinEx_New(void) {
    TextWinEx *win = (TextWinEx *)Heap_Alloc(0x3dc);
    if (win != NULL) {
        *(const u32 **)win = TextWin_vtbl;
        TextWin_Init(win);
        *(const u32 **)win = TextWinEx_vtbl;
        func_0204f49c(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    gGfxMgr->unk_004 = win->font;
}

static inline void SetPages(TextWinEx *win, u32 text) {
    win->unk_3d8 = text;
    win->page = 0;
    win->numPages = 1;
}

struct Obj0215bb14 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0xc];
    u32 unk_1c;
    u8 unk_20[0x44];
    s16 unk_64;
    s16 unk_66;
    u8 unk_68[0x1c];
    TextWin *unk_84;
};

void Obj0215bb14_SetText(Obj0215bb14 *self, u32 text) {
    BOOL flag;
    self->unk_0c &= ~0x40000;
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if ((VObj *)self->unk_84 != NULL) {
            VObj *p_ = (VObj *)self->unk_84;
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            self->unk_84 = NULL;
        }
        gSysState->cur = saved;
    }
    if (self->unk_0c & 0x80000) {
        TextWin *win = TextWin_New();
        self->unk_84 = win;
        win->font = self->unk_1c;
        self->unk_84->spacing = self->vfunc_3c();
        SetText(self->unk_84, text);
        self->unk_84->noVram = 1;
        self->unk_84->flag24 = 1;
        self->unk_84->unk_4_30 = 1;
        self->unk_84->rendering = 1;
    } else {
        TextWinEx *win = TextWinEx_New();
        self->unk_84 = (TextWin *)(win);
        win->font = self->unk_1c;
        ((TextWinEx *)self->unk_84)->spacing = self->vfunc_3c();
        SetPages((TextWinEx *)self->unk_84, text);
    }
    {
        s32 dx = self->vfunc_30();
        s32 dy = self->vfunc_34();
        self->unk_84->unk_vf20(self->unk_64 + dx, self->unk_66 + dy);
    }
    self->unk_84->unk_2c = 0;
    *(u32 *)((u8 *)self->unk_84 + 4) |= 0x800000;
    flag = FALSE;
    if (LFLD(Bits0215bb14, self, 0xc).b6) {
        flag = TRUE;
    }
    if (flag) {
        self->unk_84->flag31 = 1;
    }
    if (self->unk_0c & 0x80000) {
        TextWin_RenderToVram(self->unk_84);
    }
}

}
