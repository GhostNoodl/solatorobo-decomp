#include "Main/Gfx/FieldMsg.h"
#include "Main/Res/ResMgr.h"
#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern u8 *data_ov000_021ccd6c;
char *func_0206e200(u32 a);
void func_0204ca14(TextWin *win, s32 a);
BOOL STD_CompareString(const char *a, const char *b);
s32 FX_Div(s32 a, s32 b);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
}

void func_ov000_02167d64(u8 *self) {
    char *str = func_0206e200(LFLD(u32, data_ov000_021ccd6c, 0x14));
    TextWin *win;
    switch (LFLD(s32, self, 0x44)) {
    case 4:
        {
            void *saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->unk_08;
            if (LFLD(VObj *, self, 0x40) != NULL) {
                VObj *p_ = LFLD(VObj *, self, 0x40);
                if (p_ != NULL) {
                    p_->vfunc_04();
                }
                LFLD(VObj *, self, 0x40) = NULL;
            }
            data_02097dd0->cur = saved;
        }
        LFLD(s32, self, 0x48) = 0;
        LFLD(s32, self, 0x4c) = 0;
        if (str == NULL || str[0] == 0) {
            return;
        }
        win = TextWin_New();
        LFLD(TextWin *, self, 0x40) = win;
        win->unk_28 = 7;
        LFLD(TextWin *, self, 0x40)->unk_2c = 0;
        LFLD(TextWin *, self, 0x40)->unk_34 = 0;
        SetText(LFLD(TextWin *, self, 0x40), (u32)str);
        func_0204ca14(LFLD(TextWin *, self, 0x40), 8);
        LFLD(TextWin *, self, 0x40)->rendering = 1;
        LFLD(s32, self, 0x44) = 8;
        return;
    case 3:
        str = NULL;
    case 8:
        if (str == NULL || str[0] == 0 || STD_CompareString((const char *)LFLD(TextWin *, self, 0x40)->unk_24, str) != 0) {
            LFLD(s32, self, 0x48) -= 0x1000;
        } else {
            LFLD(s32, self, 0x48) += 0x1000;
        }
        LFLD(s32, self, 0x4c) = FX_Div(LFLD(s32, self, 0x48), 0xc000);
        if (LFLD(s32, self, 0x4c) < 0) {
            LFLD(s32, self, 0x48) = 0;
            LFLD(s32, self, 0x4c) = 0;
            LFLD(s32, self, 0x44) = 4;
            return;
        }
        if (LFLD(s32, self, 0x4c) > 0x1000) {
            LFLD(s32, self, 0x48) = 0xc000;
            LFLD(s32, self, 0x4c) = 0x1000;
            LFLD(s32, self, 0x44) = 7;
        }
        return;
    case 7:
        if (str != NULL && str[0] != 0 && STD_CompareString((const char *)LFLD(TextWin *, self, 0x40)->unk_24, str) == 0) {
            return;
        }
        LFLD(s32, self, 0x44) = 3;
        break;
    }
}

}
