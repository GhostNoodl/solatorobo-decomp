#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern u8 data_ov000_021c985c[];

struct Obj021627ac {
    u8 unk_00[0x644];
    s32 unk_644;
    s32 unk_648;
    s32 unk_64c;
    s32 unk_650;
    s32 unk_654;
    s32 unk_658;
    s32 unk_65c;
    s32 unk_660;
    s32 unk_664;
    u8 unk_668[0x40];
    s32 unk_6a8;
    s32 unk_6ac;
    s32 unk_6b0;
    s32 unk_6b4;
    u8 unk_6b8[0x34];
    s32 unk_6ec;
    s32 unk_6f0;
    s32 unk_6f4;
    s32 unk_6f8;
    s32 unk_6fc;
    s32 unk_700;
};

static inline void SetFrustum021627ac(Obj021627ac *self, s32 x, s32 y, s32 z, s32 s) {
    self->unk_6a8 = x;
    self->unk_6ac = y;
    self->unk_6b0 = z;
    self->unk_6b4 = s;
    MTX_FrustumW(LO_FX_MUL(self->unk_6ac + 0xf5c, s), LO_FX_MUL(self->unk_6ac - 0xf5c, s), LO_FX_MUL(self->unk_6a8 - 0x147b, s), LO_FX_MUL(self->unk_6a8 + 0x147b, s), 0x1000, 0x1e000, 0x1000, (MtxFx44 *)((u8 *)self + 0x668));
}

void func_ov000_021627ac(Obj021627ac *self) {
    self->unk_644 = 0x20cd;
    self->unk_648 = 0;
    self->unk_64c = 0x7ca4;
    self->unk_650 = LFLD(s32, data_ov000_021c985c, 0x50);
    self->unk_654 = LFLD(s32, data_ov000_021c985c, 0x54);
    self->unk_658 = LFLD(s32, data_ov000_021c985c, 0x58);
    self->unk_65c = 0;
    self->unk_660 = 0x1000;
    self->unk_664 = 0;
    SetFrustum021627ac(self, -0x8f6, 0x785, 0, 0x3d7);
    self->unk_6ec = 0x99a;
    self->unk_6f0 = 0;
    self->unk_6f4 = 0;
    self->unk_6f8 = -0x99a;
    self->unk_6fc = 0;
    self->unk_700 = 0;
}

struct Obj02162910 {
    u8 unk_00[0x644];
    s32 unk_644;
    s32 unk_648;
    s32 unk_64c;
    s32 unk_650;
    s32 unk_654;
    s32 unk_658;
    s32 unk_65c;
    s32 unk_660;
    s32 unk_664;
};

void func_ov000_02162910(Obj02162910 *self, const VecFx32 *eye, const VecFx32 *at, const VecFx32 *up) {
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
    self->unk_654 = ay;
    self->unk_644 = ex;
    self->unk_648 = ey;
    self->unk_64c = ez;
    self->unk_650 = ax;
    self->unk_654 = ay;
    self->unk_658 = az;
    self->unk_65c = ux;
    self->unk_660 = uy;
    self->unk_664 = uz;
}

}
