#include "Main/Gfx/TextWin.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ModelPart.h"
#include "ov000/Vec.h"
#include "Main/Res/ResArc.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits021bca00;

extern "C" {
extern const char *data_0208cc94;
extern const char *data_0208cc88;
extern const u32 data_0208ba70[];
extern void *data_02149ef8;
void *Heap_Alloc(u32 size);
void func_0204c7d0(void *p);
u32 MsgRes_GetString(void *p, s32 a);
u32 Text_Measure(u32 a, u32 b, u32 c, u32 *d, u32 *e, BOOL f);
void func_0204ca70(void *p);
void func_ov000_02184508(void *p);
BOOL func_02054f10(void *p, s32 a);
s32 FX_Div(s32 a, s32 b);
BOOL func_ov000_021bc474(void *self);

static inline s32 Lo_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline TextWin *Lo_TextWinNew(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void Lo_SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
}

struct Obj021bca00 {
    Bits021bca00 unk_00;
    s32 unk_04;
    u8 unk_08[0x4];
    s32 unk_0c;
    TextWin *unk_10;
    Model *unk_14;
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20[0x8];
    s32 unk_28;
};

BOOL func_ov000_021bca00(Obj021bca00 *self) {
    switch (self->unk_0c) {
    case 0: {
        void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        Model *m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            const char *arc;
            const char *name;
            name = data_0208cc88;
            arc = data_0208cc94;
            func_02041218(&m->pltt);
            func_02041440(m, name, 0);
            STD_CopyString(m->name, arc);
        }
        self->unk_14 = (Model *)m;
        func_020417e0((Model *)m, res);
        self->unk_14->flags |= 2;
        MODEL_FLAGS(self->unk_14)->unk_19 = 1;
        MODEL_FLAGS(self->unk_14)->alpha = 0x1e;
        func_02041d9c(self->unk_14, 0, 0x1d);
        self->unk_10 = Lo_TextWinNew();
        self->unk_10->font = 4;
        Lo_SetText(self->unk_10, MsgRes_GetString(data_02149ef8, 0x118));
        self->unk_10->color0 = 0x7fff;
        self->unk_10->color1 = 0x67f;
        self->unk_10->unk_78 = 0x7000;
        self->unk_10->noVram = 1;
        self->unk_10->flag24 = 1;
        self->unk_10->unk_vf14();
        self->unk_10->unk_4_8 = 0x1e;
        self->unk_10->unk_4_30 = 1;
        self->unk_10->rendering = 1;
        func_0204ca70(self->unk_10);
        func_ov000_02184508(data_ov000_021ccd54);
        self->unk_0c = 1;
        break;
    }
    case 1:
        if (!func_02054f10(self->unk_14, 0xffff)) {
            break;
        }
        self->unk_0c = 2;
    case 2: {
        s32 r;
        if (self->unk_04 == 2) {
            self->unk_00.b0 = 1;
        } else if (self->unk_00.b1) {
            self->unk_00.b0 = 0;
        } else {
            self->unk_00.b0 = 1;
        }
        if (self->unk_28 == 0x1000) {
            self->unk_18 += 0x1000;
        }
        r = FX_Div(self->unk_18, 0x3c000);
        if (r >= 0x1000) {
            if (self->unk_18 > 0x50000) {
                r = 0;
                self->unk_18 = r;
            } else {
                r = 0x1000;
            }
        }
        self->unk_1c = Lo_FxMul64(FX_SinCosTable_[((r << 14) >> 16) * 2], 0x6000);
        func_ov000_021bc474(self);
        break;
    }
    }
    return TRUE;
}

}
