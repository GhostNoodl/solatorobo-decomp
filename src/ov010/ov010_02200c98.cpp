#include "ov010/ov010.h"

extern "C" {

static inline s32 Ov010_ClampS(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return hi;
    }
    if (x < lo) {
        return lo;
    }
    return x;
}

BOOL func_ov010_02200c98(u8 *o) {
    BOOL r = FALSE;
    s32 v;
    switch (FLD(u16, o, 0x6c)) {
    case 0:
        FLD(s32, o, 0x14) = 0;
        FLD(u16, o, 0x6e) = 0;
        FLD(u16, o, 0x6c) = 1;
    case 1:
        if (FLD(u16, o, 0x6e) < 9) {
            FLD(s32, o, 0x14) += 0x238e;
            v = Ov010_ClampS(FLD(s32, o, 0x14), 0, 0x14000);
            FLD(s32, o, 0x14) = v;
            FLD(u16, o, 0x6e)++;
            break;
        }
        FLD(u16, o, 0x6c) = 2;
    case 2:
        if (FLD(u16, o, 0x6e) < 0xb) {
            v = 0x14000;
            FLD(s32, o, 0x14) = v;
            (*(volatile u16 *)(o + 0x6e))++;
            break;
        }
        FLD(u16, o, 0x6c) = 3;
    case 3:
        if (FLD(u16, o, 0x6e) < 0x14) {
            FLD(s32, o, 0x14) -= 0x238e;
            v = Ov010_ClampS(FLD(s32, o, 0x14), 0, 0x14000);
            FLD(s32, o, 0x14) = v;
            FLD(u16, o, 0x6e)++;
            break;
        }
        FLD(u16, o, 0x6e) = 0;
        FLD(u16, o, 0x6c) = 4;
        break;
    case 4:
        FLD(s32, o, 0x14) = 0;
        r = TRUE;
        break;
    }
    return r;
}

}
