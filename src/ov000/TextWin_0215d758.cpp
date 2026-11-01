#include "Main/Gfx/FieldMsg.h"
#include "ov000/ObjLayouts.h"
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
void *func_ov000_02154128(u8 *self, void *req, void *buf, u16 *count);

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

void func_ov000_0215d758(Lo021cae48 *self) {
    u16 *ent = &data_ov000_021cabe0[self->unk_84 * 2];
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
    self->unk_90 = (Model *)(m);
    func_020417e0(self->unk_90, func_02034d88(func_02035d5c(m + 0x2c), (u8 *)self->unk_90 + 0x4c));
    LFLD(u32, self->unk_90, 0x6c) |= 2;
    func_02041d9c(self->unk_90, 0, 6);
    if (self->unk_84 != 4) {
        func_02041d9c(self->unk_90, 0, ent[0]);
    }
    func_02041c5c((u8 *)self->unk_90, (void *)func_ov000_02154128);
    res = data_02149ef8;
    win = TextWin_New();
    self->unk_94 = win;
    win->unk_28 = 4;
    SetText(self->unk_94, func_0204c0e8(res, ent[1]));
    self->unk_94->unk_2c = 0;
    self->unk_94->unk_74 = 0x77df;
    self->unk_94->unk_76 = 0x67e;
    self->unk_94->noVram = 1;
    self->unk_94->flag24 = 1;
    *(u32 *)((u8 *)self->unk_94 + 4) |= 0x400000;
    self->unk_94->unk_78 = 0x9000;
    self->unk_94->unk_4_30 = 1;
    self->unk_94->rendering = 1;
    self->unk_48 = 0x4cc2;
    self->unk_24 = 0x60;
    self->unk_28 = 0xe;
    LFLD(Bits0215d758, self, 0xc).b0 = 1;
}
}
