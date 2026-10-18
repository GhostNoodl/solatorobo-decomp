#include "Main/Gfx/FieldMsg.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[0xa0];
    TextWin *unk_a0;
} Obj021c628c;

extern "C" {
extern char data_ov000_021cc9e9[];
BOOL func_ov000_02152e5c(void *self);
void func_ov000_0215ec44(void *self);
void func_ov000_0215e8b0(void *self);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void Obj021c628c_SetText(Obj021c628c *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->unk_08;
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
    self->unk_a0->unk_28 = 8;
    win = self->unk_a0;
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
    self->unk_a0->noVram = 1;
    self->unk_a0->unk_4_8 = 0x1e;
    self->unk_a0->flag24 = 1;
    *(u32 *)((u8 *)self->unk_a0 + 4) |= 0x400000; // bit 22 of the flags word
    self->unk_a0->rendering = 1;
}

static inline u8 *Obj021c628c_GetItem(u8 *self, s32 n) {
    u8 *p;
    s32 i;
    for (p = LFLD(u8 *, self, 0x84), i = 0; p != NULL; p = LFLD(u8 *, p, 0x28), i++) {
        if (i == n) {
            break;
        }
    }
    return p;
}

void func_ov000_021c628c(u8 *self) {
    u8 *p;
    u8 *o;

    LFLD(s32, self, 0x2c) = 1;
    {
        s32 z = LFLD(s16, self, 0x68);
        LFLD(s32, self, 0x58) = -0x100;
        LFLD(s32, self, 0x5c) = 0;
        LFLD(s32, self, 0x60) = z;
    }
    p = Obj021c628c_GetItem(self, 0);
    LFLD(u8 *, self, 0x88) = p;
    if (p != NULL) {
        LFLD(s32, self, 0xb4) = LFLD(s32, p, 0x1c);
    }
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(LFLD(Model *, self, 0x10), 0, 4);
    }
    LFLD(u8 *, self, 0x88) = LFLD(u8 *, self, 0x84);
    o = (u8 *)func_0203dd9c(0x2c);
    if (o != NULL) {
        func_ov000_0215ec44(o);
    }
    LFLD(u8 *, self, 0x9c) = o;
    LFLD(s32, o, 0x10) = LFLD(s32, self, 0xa4) << 12;
    func_ov000_0215e8b0(LFLD(void *, self, 0x9c));
    if (LFLD(void *, self, 0xa0) != NULL) {
        return;
    }
    {
        u32 t = (u32)data_ov000_021cc9e9;
        Obj021c628c_SetText((Obj021c628c *)self, t);
    }
}
}
