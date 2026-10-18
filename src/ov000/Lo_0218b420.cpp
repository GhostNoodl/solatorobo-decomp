#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
} Bits0218b420;

void func_ov000_0218b420(u8 *self) {
    s32 na, a, nb, b, c, nc, y;
    if (!LFLD(Bits0218b420, self, 0xa2).b2) {
        na = 0x80000000;
        a = 0x7fffffff;
    } else {
        a = LFLD(s32, self, 0x7c);
        na = -a;
    }
    if (!LFLD(Bits0218b420, self, 0xa2).b1) {
        nb = 0x80000000;
        b = 0x7fffffff;
    } else {
        b = LFLD(s32, self, 0x74);
        nb = -b;
    }
    LFLD(s32, self, 0x48) = na;
    LFLD(s32, self, 0x54) = a;
    LFLD(s32, self, 0x44) = nb;
    if (!LFLD(Bits0218b420, self, 0xa2).b2) {
        nc = 0x80000000;
        c = 0x7fffffff;
    } else {
        c = LFLD(s32, self, 0x80);
        nc = -c;
    }
    y = LFLD(s32, self, 0x78);
    LFLD(s32, self, 0x60) = nc;
    LFLD(s32, self, 0x4c) = nb;
    LFLD(s32, self, 0x50) = b;
    LFLD(s32, self, 0x58) = b;
    LFLD(s32, self, 0x5c) = -y;
    LFLD(s32, self, 0x64) = -y;
    LFLD(s32, self, 0x68) = y;
    LFLD(s32, self, 0x6c) = c;
    LFLD(s32, self, 0x70) = y;
}
}
