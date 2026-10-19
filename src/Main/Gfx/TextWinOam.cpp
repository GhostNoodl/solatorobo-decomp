#include "Main/Gfx/TextWin.h"

extern "C" {

typedef struct TextWinOam {
    /* 0x0 */ u32 y : 8;
    /* 0x0 */ u32 attr0 : 8;
    /* 0x0 */ u32 x : 9;
    /* 0x0 */ u32 attr1 : 7;
    /* 0x4 */ u32 charName : 10;
    /* 0x4 */ u32 attr2 : 22;
} TextWinOam;

TextWinOam *func_0204fc4c(TextWin *win, const u16 *cmd, TextWinOam *oam, u16 *count) {
    u16 n = *count;
    TextWinOam *last = &oam[n - 1];
    if (*cmd == 2) {
        u32 name = last->charName;
        s32 flags = win->unk_70;
        n = 1;
        if (flags & 1) {
            oam->charName = name;
        }
        if (flags & 2) {
            oam->charName = name - 1;
        }
        if (flags & 0x400) {
            oam->charName = name - 2;
        }
        if (flags & 0x800) {
            oam->charName = name - 3;
        }
        if (flags & 0x200) {
            oam->charName = name - 4;
        }
        if (flags & 0x100) {
            oam->charName = name - 5;
        }
        oam->x = 0;
        oam->y = 0;
    }
    *count = n;
    return oam;
}

}
