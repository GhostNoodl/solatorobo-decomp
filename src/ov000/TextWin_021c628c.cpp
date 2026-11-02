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
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
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
        data_02097dd0->cur = data_02097dd0->heapHi;
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
    self->unk_a0->font = 8;
    win = self->unk_a0;
    win->str = text;
    win->unk_4c = func_0204c4fc(win->font, win->spacing, win->str, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    self->unk_a0->noVram = 1;
    self->unk_a0->unk_4_8 = 0x1e;
    self->unk_a0->flag24 = 1;
    *(u32 *)((u8 *)self->unk_a0 + 4) |= 0x400000; // bit 22 of the flags word
    self->unk_a0->rendering = 1;
}

struct Obj021c628cS {
    u8 unk_00[0x10];
    Model *unk_10;
    u8 unk_14[0x18];
    s32 unk_2c;
    u8 unk_30[0x28];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64[0x4];
    s16 unk_68;
    u8 unk_6a[0x1a];
    u8 *unk_84;
    u8 *unk_88;
    u8 unk_8c[0x10];
    u8 *unk_9c;
    void *unk_a0;
    s32 unk_a4;
    u8 unk_a8[0xc];
    s32 unk_b4;
};

static inline u8 *Obj021c628c_GetItem(Obj021c628cS *self, s32 n) {
    u8 *p;
    s32 i;
    for (p = self->unk_84, i = 0; p != NULL; p = LFLD(u8 *, p, 0x28), i++) {
        if (i == n) {
            break;
        }
    }
    return p;
}

void func_ov000_021c628c(Obj021c628cS *self) {
    u8 *p;
    u8 *o;

    self->unk_2c = 1;
    {
        s32 z = self->unk_68;
        self->unk_58 = -0x100;
        self->unk_5c = 0;
        self->unk_60 = z;
    }
    p = Obj021c628c_GetItem(self, 0);
    self->unk_88 = p;
    if (p != NULL) {
        self->unk_b4 = LFLD(s32, p, 0x1c);
    }
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(self->unk_10, 0, 4);
    }
    self->unk_88 = self->unk_84;
    o = (u8 *)Heap_Alloc(0x2c);
    if (o != NULL) {
        func_ov000_0215ec44(o);
    }
    self->unk_9c = o;
    LFLD(s32, o, 0x10) = self->unk_a4 << 12;
    func_ov000_0215e8b0(self->unk_9c);
    if (self->unk_a0 != NULL) {
        return;
    }
    {
        u32 t = (u32)data_ov000_021cc9e9;
        Obj021c628c_SetText((Obj021c628c *)self, t);
    }
}
}
