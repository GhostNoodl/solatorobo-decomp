#include "ov000/LoCommon.h"


typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 rest : 2;
} BitByte021b8284;

extern "C" {
extern int data_02097d78[];
extern u8 *data_02097d48;
extern void *data_02097e4c;
extern char data_ov000_021cc879[];
char *func_02061f94(u16 id);
void STD_CopyString(char *dst, const char *src);
char *STD_SearchString(const char *s, const char *pat);
void func_020359fc(void *a, void *b, s32 c, s32 d);
BOOL func_02035bd4(void *a, void *b, s32 c);
void *func_02035f30(void *a, void *b, s32 c);
void *func_0203dd9c(u32 size);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
BOOL func_02054f10(void *a, s32 b);
void func_02041d8c(void *model);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 FX_Div(s32 a, s32 b);

static inline BOOL FadeIdle021b8284(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL Fade4_021b8284(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

BOOL func_ov000_021b8284(u8 *self) {
    switch (LFLD(s32, self, 0x44)) {
    case 1: {
        char *c;
        STD_CopyString((char *)self + 4, func_02061f94(LFLD(u16, self, 0x48)));
        c = STD_SearchString((char *)self + 4, data_ov000_021cc879);
        *c = 0;
        STD_CopyString((char *)self + 0x24, c + 1);
        func_020359fc(self + 4, self + 0x24, 2, 0);
        {
            BitByte021b8284 *b = (BitByte021b8284 *)(data_02097d48 + 0x8b0);
            b->b4 = 0;
            b->b5 = 1;
        }
        *(vu16 *)0x4000060 &= 0xcfdf;
        LFLD(s32, self, 0x44) = 2;
        break;
    }
    case 2:
        if (!func_02035bd4(self + 4, self + 0x24, 2)) {
            break;
        }
        LFLD(s32, self, 0x44) = 4;
    case 4: {
        void *res = func_02035f30(self + 4, self + 0x24, 2);
        u8 *p;
        u16 i;
        if (!FadeIdle021b8284() && !Fade4_021b8284()) {
            break;
        }
        p = (u8 *)func_0203dd9c(0x160);
        if (p != NULL) {
            func_02041218(p + 0x88);
            func_02041440(p, self + 0x24, 1);
            STD_CopyString((char *)p + 0x2c, (char *)self + 4);
        }
        LFLD(u8 *, self, 0x4c) = p;
        func_020417e0(LFLD(u8 *, self, 0x4c), func_02034d88(res, p + 0x4c));
        LFLD(u32, LFLD(u8 *, self, 0x4c), 0x6c) |= 2;
        {
            u8 *q = LFLD(u8 *, LFLD(u8 *, self, 0x4c), 0x28);
            LFLD(u16, self, 0x58) = q != NULL ? *LFLD(u16 *, q, 0xc) : 0;
        }
        for (i = 0; i < LFLD(u16, self, 0x58); i++) {
            func_02041d9c(LFLD(u8 *, self, 0x4c), 0, i);
        }
        LFLD(s32, self, 0x44) = 5;
        break;
    }
    case 5:
        if (!func_02054f10(LFLD(u8 *, self, 0x4c), 0xffff)) {
            break;
        }
        func_02041d8c(LFLD(u8 *, self, 0x4c));
        if (Fade4_021b8284()) {
            LFLD(s32, self, 0x50) = 0x3e7000;
        } else {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
            LFLD(s32, self, 0x50) = 0;
        }
        LFLD(s32, self, 0x44) = 7;
        break;
    case 7:
        LFLD(u32, self, 0x50) += 0x1000;
        if (LFLD(u32, self, 0x50) >= 0xa000) {
            LFLD(u32, self, 0x50) = 0xa000;
            LFLD(s32, self, 0x54) = 0x1000;
        } else {
            LFLD(s32, self, 0x54) = FX_Div(LFLD(u32, self, 0x50), 0xa000);
            break;
        }
        LFLD(s32, self, 0x44) = 0xb;
        break;
    case 11:
        if (!LBIT(self, 0).b0) {
            break;
        }
        if (!FadeIdle021b8284()) {
            LFLD(s32, self, 0x50) = 0x3e7000;
        } else {
            func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
            LFLD(s32, self, 0x50) = 0;
        }
        LFLD(s32, self, 0x44) = 0xd;
        break;
    case 13:
        LFLD(u32, self, 0x50) += 0x1000;
        if (LFLD(u32, self, 0x50) >= 0xa000) {
            LFLD(u32, self, 0x50) = 0xa000;
            LFLD(s32, self, 0x54) = 0x1000;
        } else {
            LFLD(s32, self, 0x54) = 0x1000 - FX_Div(LFLD(u32, self, 0x50), 0xa000);
            break;
        }
        if (FadeIdle021b8284() || Fade4_021b8284()) {
            LFLD(s32, self, 0x44) = 0xf;
        }
        break;
    case 15:
        LO_FREE_M(self, 0x4c);
        return FALSE;
    }
    return TRUE;
}
}
