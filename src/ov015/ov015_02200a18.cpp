#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
void *func_02065f88(s32 id, void *pos);
s32 func_ov015_02200bf4(u8 *self, u8 *b, s32 c);
s32 func_ov015_022090f0(void *p);

void func_ov015_02200a18(u8 *self, u8 *b) {
    s32 spd = FLD(s32, self, 0x1c);
    s32 pos = FLD(s32, b, 0x24);
    switch (FLD(s32, b, 0x28)) {
    case 3:
        spd = -0x666;
        if ((FLD(s32, self, 0xc) >> 12) % 20 == 0) {
            Ov015V *e;
            func_02049a48(data_02097e4c, 0x59, -1, -1, -1);
            e = (Ov015V *)func_02065f88(0x325, &FLD(Ov015Vec, FLD(u8 *, self, 0x24) + 0xcd4, 0x24));
            e->v14(0x800, 0x800, 0x800);
            FLD(s32, e, 0xd4) = 2;
        }
        if (pos <= 0) {
            pos = 0;
            FLD(s32, b, 0x28) = pos;
        }
        break;
    case 2:
        spd = -0x3000;
        if (--FLD(s32, self, 0x14) <= 0) {
            FLD(s32, self, 0x14) = 0;
            FLD(s32, b, 0x28) = 0;
        }
        break;
    case 1:
        if (pos >= 0x64000 && FLD(s32, b, 0x8) != 3) {
            FLD(s32, b, 0x28) = 3;
            func_02049a48(data_02097e4c, 0x1b, -1, -1, -1);
        } else if (pos < 0x46000) {
            FLD(s32, b, 0x28) = 0;
        }
        if ((FLD(s32, self, 0xc) >> 12) % 10 == 0) {
            func_02049a48(data_02097e4c, 0x59, -1, -1, -1);
        }
        spd = func_ov015_02200bf4(self, b, spd);
        break;
    case 0:
        if (pos > 0x46000) {
            FLD(s32, b, 0x28) = 1;
            break;
        }
        spd = func_ov015_02200bf4(self, b, spd);
        break;
    }
    pos += spd;
    FLD(s32, self, 0x1c) = spd;
    if (pos < 0) {
        pos = 0;
    } else if (pos > 0x64000) {
        pos = 0x64000;
    }
    FLD(s32, b, 0x24) = pos;
}

s32 func_ov015_02200bf4(u8 *self, u8 *b, s32 c) {
    BOOL flag = TRUE;
    s32 base;
    s32 q, d, na, nb, ax, bx;
    u8 *o;
    if (FLD(s32, b, 0x14) == 1) flag = FALSE;
    base = FLD(s32, FLD(u8 *, self, 0x30), 0x30);
    d = func_ov015_022090f0(FLD(u8 *, self, 0x28) + 0xc0) - base;
    if (d < 0x800) d = 0x800;
    q = d / 120;
    o = FLD(u8 *, self, 0x30);
    ax = FLD(s32, o, 0x28);
    if (ax < 0) ax = -ax;
    na = -ax;
    bx = FLD(s32, o, 0x2c);
    if (bx < 0) bx = -bx;
    nb = -bx;
    if (FLD(s32, FLD(u8 *, self, 0x28), 0xf4) == 3) {
        c = na;
    } else if (FLD(u8, b, 0x1c) != 0) {
        s32 t3 = FLD(s32, b, 0x14);
        s32 t4 = FLD(s32, b, 0x10);
        if (!((t3 == 3 && t4 == 2) || (t3 == 2 && t4 == 3) || (t3 == 4 && t4 == 4) ||
            ((t3 != 1 && t3 != 0) && t4 == 1))) {
            FLD(s32, self, 0x20) = 0;
            c = d;
        } else {
            if (c < 0x29) c = 0x29;
            if (FLD(s32, self, 0x20) == 0) c = 0x29;
            c += q;
            FLD(s32, self, 0x20) = FLD(s32, self, 0x20) + 1;
        }
    } else if (FLD(s32, self, 0x10) <= -5) {
        FLD(s32, self, 0x20) = 0;
        c += nb;
        if (flag) {
            if (c < (na >> 1)) c = na >> 1;
        }
    }
    if (c <= d) d = c;
    if (d >= na) na = d;
    return na;
}

}
