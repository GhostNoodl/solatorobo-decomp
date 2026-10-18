#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x2c];
    u8 unk_2c[0xca];
    u8 unk_f6_0 : 2;
    u8 unk_f6_2 : 1;
    u8 unk_f6_3 : 5;
} Obj021b7e34;

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad_00[0xf8];
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10c;
    s32 unk_110;
} Obj021b7e60;

extern "C" {

BOOL func_ov000_021b75e0(void *p);

void func_ov000_021b7e34(Obj021b7e34 *self) {
    self->unk_f6_2 = func_ov000_021b75e0(self->unk_2c);
}

void func_ov000_021b7e60(Obj021b7e60 *self, s32 x) {
    s32 a = FX_MUL(x, -0xc3000);
    s32 c;
    self->unk_100 = FX_MUL(x, -0x4e000);
    c = FX_MUL(x, 0xc3000);
    self->unk_f8 = x;
    self->unk_fc = a;
    self->unk_104 = a;
    self->unk_108 = c;
    self->unk_110 = c;
    self->unk_10c = FX_MUL(x, 0x4e000);
}

}
