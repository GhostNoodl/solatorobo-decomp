#include "types.h"
#include "nitro/fx.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot0218a358;

extern "C" {


struct Obj0218a358 {
    u8 unk_00[0x10];
    VecFx32 unk_10;
    u8 unk_1c[0x26];
    Rot0218a358 unk_42;
    s32 unk_48;
    u8 unk_4c[0x70];
    VecFx32 unk_bc;
    u8 unk_c8[0x11];
    u8 unk_d9;
    u8 unk_da[0xe];
    s32 unk_e8;
    s32 unk_ec;
    s32 unk_f0;
    s32 unk_f4;
    Rot0218a358 unk_f8;
    s16 unk_fe;
    s16 unk_100;
    u8 unk_102[0x2];
    s32 unk_104;
    s32 unk_108;
    s32 unk_10c;
    s32 unk_110;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
};

void func_ov000_0218a358(Obj0218a358 *self, const VecFx32 *pos, const Rot0218a358 *rot, s32 dist, u8 clamp, s16 a6, s16 a7, u8 a8) {
    self->unk_d9 = a8;
    if (rot != NULL) {
        self->unk_f8 = *rot;
    } else {
        self->unk_f8 = self->unk_42;
    }
    if (dist != 0) {
        self->unk_f4 = dist;
    } else {
        self->unk_f4 = self->unk_48;
    }
    if (pos != NULL) {
        LFLD(VecFx32, self, 0xe8) = *pos;
    } else {
        self->unk_bc = self->unk_10;
    }
    self->unk_fe = a6;
    self->unk_100 = a7;
    if (!clamp) {
        return;
    }
    if (self->unk_f4 == self->unk_11c) {
        if (self->unk_e8 < self->unk_104) {
            self->unk_e8 = self->unk_104;
        } else if (self->unk_e8 > self->unk_110) {
            self->unk_e8 = self->unk_110;
        }
        if (self->unk_ec < self->unk_108) {
            self->unk_ec = self->unk_108;
        } else if (self->unk_ec > self->unk_114) {
            self->unk_ec = self->unk_114;
        }
        if (self->unk_f0 < self->unk_10c) {
            self->unk_f0 = self->unk_10c;
        } else if (self->unk_f0 > self->unk_118) {
            self->unk_f0 = self->unk_118;
        }
    } else {
        s32 t = FX_Div(self->unk_f4, self->unk_11c);
        if (t >= 0x1000) {
            t = 0x1000;
        }
        if (self->unk_e8 < self->unk_104) {
            self->unk_e8 += FX_Mul(self->unk_104 - self->unk_e8, t);
        } else if (self->unk_e8 > self->unk_110) {
            self->unk_e8 += FX_Mul(self->unk_110 - self->unk_e8, t);
        }
        if (self->unk_ec < self->unk_108) {
            self->unk_ec += FX_Mul(self->unk_108 - self->unk_ec, t);
        } else if (self->unk_ec > self->unk_114) {
            self->unk_ec += FX_Mul(self->unk_114 - self->unk_ec, t);
        }
        if (self->unk_f0 < self->unk_10c) {
            self->unk_f0 += FX_Mul(self->unk_10c - self->unk_f0, t);
        } else if (self->unk_f0 > self->unk_118) {
            self->unk_f0 += FX_Mul(self->unk_118 - self->unk_f0, t);
        }
    }
}

}
