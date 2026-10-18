#include "ov000/VObj.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 30;
} Bits021c6140;

typedef struct {
    u8 unk_00[0x84];
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c;
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[4];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
    s32 unk_b8;
    s32 unk_bc;
    s32 unk_c0;
    Bits021c6140 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    s32 unk_d0;
} Obj021c6140;

extern "C" {

void func_ov000_021c6140(Obj021c6140 *self) {
    s32 zero = 0;
    self->unk_84 = zero;
    self->unk_88 = zero;
    self->unk_8c = zero;
    self->unk_90 = zero;
    self->unk_94 = zero;
    self->unk_9c = zero;
    self->unk_a0 = zero;
    self->unk_a4 = 0xd2;
    self->unk_a8 = 0x18;
    self->unk_ac = zero;
    self->unk_b0 = zero;
    self->unk_b4 = 0xb4;
    self->unk_b8 = zero;
    self->unk_bc = zero;
    self->unk_c0 = zero;
    {
        Bits021c6140 f;
        *(u32 *)&f = zero;
        f.b1 = 1;
        self->unk_c4 = f;
    }
    self->unk_c8 = zero;
    self->unk_cc = zero;
    self->unk_d0 = zero;
}

}
