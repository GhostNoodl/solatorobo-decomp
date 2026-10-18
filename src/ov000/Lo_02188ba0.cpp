#include "types.h"

class Obj02188ba0Cls;
typedef void (Obj02188ba0Cls::*Obj02188ba0Pmf)();

typedef struct {
    s32 state;
    u16 unk_04;
    u8 unk_06;
    u8 pad_07;
    u8 unk_08[8];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 rd;
    s32 index;
    s32 unk_98;
    Obj02188ba0Pmf unk_9c;
    u16 unk_a4;
    u16 unk_a6;
    u16 unk_a8;
    u8 pad_aa[2];
    u8 unk_ac;
    s32 unk_b0;
    u16 unk_b4;
    s32 unk_b8;
    s32 unk_bc;
    s32 unk_c0;
    u8 unk_c4;
    u8 pad_c5[3];
    u8 unk_c8;
    u8 unk_c9;
    u8 unk_ca[9];
    u8 unk_d3;
    s32 unk_d4;
    s32 unk_d8;
    s32 unk_dc;
    s32 unk_e0;
    u16 unk_e4;
    u16 unk_e6;
    u16 unk_e8;
    s32 unk_ec;
    u16 unk_f0;
    u8 pad_f2[2];
    u8 unk_f4[1];
} Obj02188ba0;

extern "C" {

void func_0203db10(void *node);
void func_ov000_02189a74(void *p);

Obj02188ba0 *func_ov000_02188ba0(Obj02188ba0 *self) {
    s32 i;
    func_0203db10(self->unk_08);
    for (i = 0; i < 0x10; i++) {
        self->kinds[i] = 0;
        self->args[i] = 0;
    }
    self->rd = 0;
    self->index = 0;
    self->unk_9c = NULL;
    self->unk_98 = 0;
    self->unk_a4 = 0;
    self->unk_a6 = 0;
    self->unk_a8 = 0;
    self->unk_ac = 0;
    self->unk_b0 = 0;
    self->unk_b4 = 0xffff;
    self->unk_b8 = 0;
    self->unk_bc = 0;
    self->unk_c0 = 0;
    self->unk_c4 = 0;
    func_ov000_02189a74(self->unk_f4);
    self->state = 2;
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_c8 = 0;
    self->unk_c9 = 0;
    self->unk_ca[0] = 0xff;
    self->unk_ca[1] = 0xff;
    self->unk_ca[2] = 0xff;
    self->unk_ca[3] = 0xff;
    self->unk_ca[4] = 0xff;
    self->unk_ca[5] = 0xff;
    self->unk_ca[6] = 0xff;
    self->unk_ca[7] = 0xff;
    self->unk_ca[8] = 0xff;
    self->unk_d3 = 0;
    self->unk_d4 = 0;
    self->unk_d8 = 0;
    self->unk_dc = 0;
    self->unk_e0 = 0;
    self->unk_e4 = 0;
    self->unk_e6 = 0;
    self->unk_e8 = 0;
    self->unk_ec = 0;
    self->unk_f0 = 0x1000;
    return self;
}

}
