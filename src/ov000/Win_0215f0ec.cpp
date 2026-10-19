#include "Main/Gfx/FieldMsg.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 id;
    u8 pad_02[0xa];
    s32 unk_0c;
    u8 pad_10[0x8];
} Entry0215f0ec;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
} Flags0215f0ec;

typedef struct {
    Flags0215f0ec flags;
    s32 idx;
    u8 pad_08[0x10];
    s32 unk_18;
    u8 pad_1c[8];
    TextWin *win;
    u8 *model;
} Obj0215f0ec;

extern "C" {
extern Entry0215f0ec data_02fe0188[];
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_02041c20(void *model, s32 a, void *b);

#define LO_MODEL_NEW(out, NAME, ARC)                 \
    do {                                             \
        u8 *m_ = (u8 *)func_0203dd9c(0x160);         \
        if (m_) {                                    \
            void *arc_;                              \
            void *name_;                             \
            name_ = NAME;                            \
            arc_ = ARC;                              \
            func_02041218(m_ + 0x88);                \
            func_02041440((Model *)m_, (const char *)name_, 0); \
            STD_CopyString((char *)m_ + 0x2c, (const char *)arc_); \
        }                                            \
        out = m_;                                    \
    } while (0)

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

void func_ov000_0215f0ec(Obj0215f0ec *self, u32 text) {
    Entry0215f0ec *e;
    TextWin *win;
    if (self->model != NULL) {
        return;
    }
    e = &data_02fe0188[self->idx];
    if (self->flags.b4 ? TRUE : FALSE) {
        LO_MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
    } else {
        LO_MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
    }
    {
        void *a = func_02035d5c(self->model + 0x2c);
        void *b = func_02034d88(a, self->model + 0x4c);
        func_020417e0((Model *)self->model, b);
    }
    LFLD(u32, self->model, 0x6c) |= 2;
    func_02041d9c((Model *)self->model, 0, e->id);
    func_02041c20(self->model, e->id, self);
    win = TextWin_New();
    self->win = win;
    win->unk_28 = 4;
    SetText(self->win, text);
    self->win->unk_74 = 0x77df;
    self->win->unk_76 = 0x67e;
    self->win->noVram = 1;
    self->win->flag24 = 1;
    *(u32 *)((u8 *)self->win + 4) |= 0x400000;
    self->win->unk_78 = 0x9000;
    self->win->unk_4_30 = 1;
    self->win->rendering = 1;
    self->unk_18 = e->unk_0c >> 12;
}

}
