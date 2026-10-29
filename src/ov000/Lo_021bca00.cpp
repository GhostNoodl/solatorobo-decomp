#include "Main/Gfx/TextWin.h"
#include "ov000/ModelPart.h"
#include "ov000/Vec.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits021bca00;

extern "C" {
extern void *data_0208cc94;
extern void *data_0208cc88;
extern const u32 data_0208ba70[];
extern void *data_02149ef8;
extern void *data_ov000_021ccd54;
void *func_0203dd9c(u32 size);
void func_02041218(void *a);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
char *STD_CopyString(char *dst, const char *src);
void func_0204c7d0(void *p);
u32 func_0204c0e8(void *p, s32 a);
u32 func_0204c4fc(u32 a, u32 b, u32 c, u32 *d, u32 *e, BOOL f);
void func_0204ca70(void *p);
void func_ov000_02184508(void *p);
BOOL func_02054f10(void *p, s32 a);
s32 FX_Div(s32 a, s32 b);
BOOL func_ov000_021bc474(void *self);

static inline s32 Lo_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline TextWin *Lo_TextWinNew(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void Lo_SetText(TextWin *win, u32 text) {
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
}

BOOL func_ov000_021bca00(u8 *self) {
    switch (LFLD(s32, self, 0xc)) {
    case 0: {
        void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        u8 *m = (u8 *)func_0203dd9c(0x160);
        if (m != NULL) {
            void *arc;
            void *name;
            name = data_0208cc88;
            arc = data_0208cc94;
            func_02041218(m + 0x88);
            func_02041440((Model *)m, (const char *)name, 0);
            STD_CopyString((char *)m + 0x2c, (const char *)arc);
        }
        LFLD(Model *, self, 0x14) = (Model *)m;
        func_020417e0((Model *)m, res);
        LFLD(Model *, self, 0x14)->flags |= 2;
        MODEL_FLAGS(LFLD(Model *, self, 0x14))->unk_19 = 1;
        MODEL_FLAGS(LFLD(Model *, self, 0x14))->alpha = 0x1e;
        func_02041d9c(LFLD(Model *, self, 0x14), 0, 0x1d);
        LFLD(TextWin *, self, 0x10) = Lo_TextWinNew();
        LFLD(TextWin *, self, 0x10)->unk_28 = 4;
        Lo_SetText(LFLD(TextWin *, self, 0x10), func_0204c0e8(data_02149ef8, 0x118));
        LFLD(TextWin *, self, 0x10)->unk_74 = 0x7fff;
        LFLD(TextWin *, self, 0x10)->unk_76 = 0x67f;
        LFLD(TextWin *, self, 0x10)->unk_78 = 0x7000;
        LFLD(TextWin *, self, 0x10)->noVram = 1;
        LFLD(TextWin *, self, 0x10)->flag24 = 1;
        LFLD(TextWin *, self, 0x10)->unk_vf14();
        LFLD(TextWin *, self, 0x10)->unk_4_8 = 0x1e;
        LFLD(TextWin *, self, 0x10)->unk_4_30 = 1;
        LFLD(TextWin *, self, 0x10)->rendering = 1;
        func_0204ca70(LFLD(TextWin *, self, 0x10));
        func_ov000_02184508(data_ov000_021ccd54);
        LFLD(s32, self, 0xc) = 1;
        break;
    }
    case 1:
        if (!func_02054f10(LFLD(Model *, self, 0x14), 0xffff)) {
            break;
        }
        LFLD(s32, self, 0xc) = 2;
    case 2: {
        s32 r;
        if (LFLD(s32, self, 4) == 2) {
            LFLD(Bits021bca00, self, 0).b0 = 1;
        } else if (LFLD(Bits021bca00, self, 0).b1) {
            LFLD(Bits021bca00, self, 0).b0 = 0;
        } else {
            LFLD(Bits021bca00, self, 0).b0 = 1;
        }
        if (LFLD(s32, self, 0x28) == 0x1000) {
            LFLD(s32, self, 0x18) += 0x1000;
        }
        r = FX_Div(LFLD(s32, self, 0x18), 0x3c000);
        if (r >= 0x1000) {
            if (LFLD(s32, self, 0x18) > 0x50000) {
                r = 0;
                LFLD(s32, self, 0x18) = r;
            } else {
                r = 0x1000;
            }
        }
        LFLD(s32, self, 0x1c) = Lo_FxMul64(FX_SinCosTable_[((r << 14) >> 16) * 2], 0x6000);
        func_ov000_021bc474(self);
        break;
    }
    }
    return TRUE;
}

}
