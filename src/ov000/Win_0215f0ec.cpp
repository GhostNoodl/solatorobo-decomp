#include "Main/Gfx/FieldMsg.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"
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
    Model *model;
} Obj0215f0ec;

extern "C" {
extern Entry0215f0ec data_02fe0188[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
void func_02041c20(void *model, s32 a, void *b);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
}

void func_ov000_0215f0ec(Obj0215f0ec *self, u32 text) {
    Entry0215f0ec *e;
    TextWin *win;
    if (self->model != NULL) {
        return;
    }
    e = &data_02fe0188[self->idx];
    if (self->flags.b4 ? TRUE : FALSE) {
        MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
    } else {
        MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
    }
    {
        ResList *a = func_02035d5c(self->model->name);
        void *b = func_02034d88(a, self->model->unk_04c);
        func_020417e0((Model *)self->model, b);
    }
    self->model->flags |= 2;
    func_02041d9c((Model *)self->model, 0, e->id);
    func_02041c20(self->model, e->id, self);
    win = TextWin_New();
    self->win = win;
    win->font = 4;
    SetText(self->win, text);
    self->win->color0 = 0x77df;
    self->win->color1 = 0x67e;
    self->win->noVram = 1;
    self->win->flag24 = 1;
    *(u32 *)((u8 *)self->win + 4) |= 0x400000;
    self->win->unk_78 = 0x9000;
    self->win->unk_4_30 = 1;
    self->win->rendering = 1;
    self->unk_18 = e->unk_0c >> 12;
}

}
