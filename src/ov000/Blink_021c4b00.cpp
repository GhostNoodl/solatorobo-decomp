#include "types.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad_00[0x20];
    s32 unk_20;
    u8 pad_24[0x74];
    s32 unk_98;
    s32 unk_9c;
    u8 pad_a0[0x2c];
    s8 unk_cc;
    s8 unk_cd;
    s8 unk_ce;
    u8 pad_cf;
    s32 unk_d0;
} Obj021c4b00;

extern "C" {

void func_ov000_021c4b00(Obj021c4b00 *self) {
    if (++self->unk_ce < 0x18) {
        self->unk_d0 += FX_MUL(0x3000 - self->unk_d0, 0x148);
    } else if (self->unk_ce >= 0x40) {
        self->unk_ce = 0;
        self->unk_d0 = 0;
    } else {
        self->unk_d0 += FX_MUL(-self->unk_d0, 0xcd);
    }
    if (self->unk_9c <= 0) {
        self->unk_cc -= 4;
    } else {
        self->unk_cc += 4;
    }
    if (self->unk_cc < 0) {
        self->unk_cc = 0;
    } else if (self->unk_cc > 0x1e) {
        self->unk_cc = 0x1e;
    }
    if (self->unk_9c >= self->unk_98 - self->unk_20) {
        self->unk_cd -= 4;
    } else {
        self->unk_cd += 4;
    }
    if (self->unk_cd < 0) {
        self->unk_cd = 0;
    } else if (self->unk_cd > 0x1e) {
        self->unk_cd = 0x1e;
    }
}

}
