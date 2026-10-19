#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern u8 data_ov000_021c985c[];

static inline void SetFrustum021627ac(u8 *self, s32 x, s32 y, s32 z, s32 s) {
    LFLD(s32, self, 0x6a8) = x;
    LFLD(s32, self, 0x6ac) = y;
    LFLD(s32, self, 0x6b0) = z;
    LFLD(s32, self, 0x6b4) = s;
    MTX_FrustumW(LO_FX_MUL(LFLD(s32, self, 0x6ac) + 0xf5c, s), LO_FX_MUL(LFLD(s32, self, 0x6ac) - 0xf5c, s), LO_FX_MUL(LFLD(s32, self, 0x6a8) - 0x147b, s), LO_FX_MUL(LFLD(s32, self, 0x6a8) + 0x147b, s), 0x1000, 0x1e000, 0x1000, (MtxFx44 *)(self + 0x668));
}

void func_ov000_021627ac(u8 *self) {
    LFLD(s32, self, 0x644) = 0x20cd;
    LFLD(s32, self, 0x648) = 0;
    LFLD(s32, self, 0x64c) = 0x7ca4;
    LFLD(s32, self, 0x650) = LFLD(s32, data_ov000_021c985c, 0x50);
    LFLD(s32, self, 0x654) = LFLD(s32, data_ov000_021c985c, 0x54);
    LFLD(s32, self, 0x658) = LFLD(s32, data_ov000_021c985c, 0x58);
    LFLD(s32, self, 0x65c) = 0;
    LFLD(s32, self, 0x660) = 0x1000;
    LFLD(s32, self, 0x664) = 0;
    SetFrustum021627ac(self, -0x8f6, 0x785, 0, 0x3d7);
    LFLD(s32, self, 0x6ec) = 0x99a;
    LFLD(s32, self, 0x6f0) = 0;
    LFLD(s32, self, 0x6f4) = 0;
    LFLD(s32, self, 0x6f8) = -0x99a;
    LFLD(s32, self, 0x6fc) = 0;
    LFLD(s32, self, 0x700) = 0;
}

void func_ov000_02162910(u8 *self, const VecFx32 *eye, const VecFx32 *at, const VecFx32 *up) {
    s32 ex = eye->x;
    s32 ey = eye->y;
    s32 ez = eye->z;
    s32 ax = at->x;
    s32 ay = at->y;
    s32 az = at->z;
    s32 ux = up->x;
    s32 uy = up->y;
    s32 uz = up->z;
    // Storing at.y once ahead of the rest gives the original load order
    // (at is read first, with ldmib).
    LFLD(s32, self, 0x654) = ay;
    LFLD(s32, self, 0x644) = ex;
    LFLD(s32, self, 0x648) = ey;
    LFLD(s32, self, 0x64c) = ez;
    LFLD(s32, self, 0x650) = ax;
    LFLD(s32, self, 0x654) = ay;
    LFLD(s32, self, 0x658) = az;
    LFLD(s32, self, 0x65c) = ux;
    LFLD(s32, self, 0x660) = uy;
    LFLD(s32, self, 0x664) = uz;
}

}
