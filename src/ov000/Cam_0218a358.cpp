#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec0218a358;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot0218a358;

extern "C" {

s32 FX_Div(s32 a, s32 b);

static inline s32 FX_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov000_0218a358(u8 *self, const Vec0218a358 *pos, const Rot0218a358 *rot, s32 dist, u8 clamp, s16 a6, s16 a7, u8 a8) {
    LFLD(u8, self, 0xd9) = a8;
    if (rot != NULL) {
        LFLD(Rot0218a358, self, 0xf8) = *rot;
    } else {
        LFLD(Rot0218a358, self, 0xf8) = LFLD(Rot0218a358, self, 0x42);
    }
    if (dist != 0) {
        LFLD(s32, self, 0xf4) = dist;
    } else {
        LFLD(s32, self, 0xf4) = LFLD(s32, self, 0x48);
    }
    if (pos != NULL) {
        LFLD(Vec0218a358, self, 0xe8) = *pos;
    } else {
        LFLD(Vec0218a358, self, 0xbc) = LFLD(Vec0218a358, self, 0x10);
    }
    LFLD(s16, self, 0xfe) = a6;
    LFLD(s16, self, 0x100) = a7;
    if (!clamp) {
        return;
    }
    if (LFLD(s32, self, 0xf4) == LFLD(s32, self, 0x11c)) {
        if (LFLD(s32, self, 0xe8) < LFLD(s32, self, 0x104)) {
            LFLD(s32, self, 0xe8) = LFLD(s32, self, 0x104);
        } else if (LFLD(s32, self, 0xe8) > LFLD(s32, self, 0x110)) {
            LFLD(s32, self, 0xe8) = LFLD(s32, self, 0x110);
        }
        if (LFLD(s32, self, 0xec) < LFLD(s32, self, 0x108)) {
            LFLD(s32, self, 0xec) = LFLD(s32, self, 0x108);
        } else if (LFLD(s32, self, 0xec) > LFLD(s32, self, 0x114)) {
            LFLD(s32, self, 0xec) = LFLD(s32, self, 0x114);
        }
        if (LFLD(s32, self, 0xf0) < LFLD(s32, self, 0x10c)) {
            LFLD(s32, self, 0xf0) = LFLD(s32, self, 0x10c);
        } else if (LFLD(s32, self, 0xf0) > LFLD(s32, self, 0x118)) {
            LFLD(s32, self, 0xf0) = LFLD(s32, self, 0x118);
        }
    } else {
        s32 t = FX_Div(LFLD(s32, self, 0xf4), LFLD(s32, self, 0x11c));
        if (t >= 0x1000) {
            t = 0x1000;
        }
        if (LFLD(s32, self, 0xe8) < LFLD(s32, self, 0x104)) {
            LFLD(s32, self, 0xe8) += FX_Mul(LFLD(s32, self, 0x104) - LFLD(s32, self, 0xe8), t);
        } else if (LFLD(s32, self, 0xe8) > LFLD(s32, self, 0x110)) {
            LFLD(s32, self, 0xe8) += FX_Mul(LFLD(s32, self, 0x110) - LFLD(s32, self, 0xe8), t);
        }
        if (LFLD(s32, self, 0xec) < LFLD(s32, self, 0x108)) {
            LFLD(s32, self, 0xec) += FX_Mul(LFLD(s32, self, 0x108) - LFLD(s32, self, 0xec), t);
        } else if (LFLD(s32, self, 0xec) > LFLD(s32, self, 0x114)) {
            LFLD(s32, self, 0xec) += FX_Mul(LFLD(s32, self, 0x114) - LFLD(s32, self, 0xec), t);
        }
        if (LFLD(s32, self, 0xf0) < LFLD(s32, self, 0x10c)) {
            LFLD(s32, self, 0xf0) += FX_Mul(LFLD(s32, self, 0x10c) - LFLD(s32, self, 0xf0), t);
        } else if (LFLD(s32, self, 0xf0) > LFLD(s32, self, 0x118)) {
            LFLD(s32, self, 0xf0) += FX_Mul(LFLD(s32, self, 0x118) - LFLD(s32, self, 0xf0), t);
        }
    }
}

}
