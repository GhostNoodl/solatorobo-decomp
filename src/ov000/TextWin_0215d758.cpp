#include "Main/Gfx/FieldMsg.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits0215d758;

extern "C" {
extern u16 data_ov000_021cabe0[];
extern void *data_0208cc88;
extern void *data_0208cc94;
extern void *data_02149ef8;
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_02041c5c(void *model, void *fn);
u32 func_0204c0e8(void *a, s32 b);
void *func_ov000_02154128(void);

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

void func_ov000_0215d758(u8 *self) {
    u16 *ent = &data_ov000_021cabe0[LFLD(s32, self, 0x84) * 2];
    u8 *m;
    void *res;
    TextWin *win;
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *arc_;
        void *name_;
        name_ = data_0208cc88;
        arc_ = data_0208cc94;
        func_02041218(m + 0x88);
        func_02041440((Model *)m, (const char *)name_, 0);
        STD_CopyString((char *)m + 0x2c, (const char *)arc_);
    }
    LFLD(u8 *, self, 0x90) = m;
    func_020417e0(LFLD(Model *, self, 0x90), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0x90) + 0x4c));
    LFLD(u32, LFLD(u8 *, self, 0x90), 0x6c) |= 2;
    func_02041d9c(LFLD(Model *, self, 0x90), 0, 6);
    if (LFLD(s32, self, 0x84) != 4) {
        func_02041d9c(LFLD(Model *, self, 0x90), 0, ent[0]);
    }
    func_02041c5c(LFLD(u8 *, self, 0x90), (void *)func_ov000_02154128);
    res = data_02149ef8;
    win = TextWin_New();
    LFLD(TextWin *, self, 0x94) = win;
    win->unk_28 = 4;
    SetText(LFLD(TextWin *, self, 0x94), func_0204c0e8(res, ent[1]));
    LFLD(TextWin *, self, 0x94)->unk_2c = 0;
    LFLD(TextWin *, self, 0x94)->unk_74 = 0x77df;
    LFLD(TextWin *, self, 0x94)->unk_76 = 0x67e;
    LFLD(TextWin *, self, 0x94)->noVram = 1;
    LFLD(TextWin *, self, 0x94)->flag24 = 1;
    *(u32 *)((u8 *)LFLD(TextWin *, self, 0x94) + 4) |= 0x400000;
    LFLD(TextWin *, self, 0x94)->unk_78 = 0x9000;
    LFLD(TextWin *, self, 0x94)->unk_4_30 = 1;
    LFLD(TextWin *, self, 0x94)->rendering = 1;
    LFLD(u16, self, 0x48) = 0x4cc2;
    LFLD(s32, self, 0x24) = 0x60;
    LFLD(s32, self, 0x28) = 0xe;
    LFLD(Bits0215d758, self, 0xc).b0 = 1;
}
}
