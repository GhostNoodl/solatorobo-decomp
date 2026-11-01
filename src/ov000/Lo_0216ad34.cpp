#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b);
u32 func_0204045c(void);

struct Obj0216ad34 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    u16 unk_14;
    u8 unk_16[0x2];
    s32 unk_18;
    s32 unk_1c;
};

void func_ov000_0216ad34(Obj0216ad34 *self) {
    LO_FREE_M(self, 0xc);
    self->unk_00 = 0;
    self->unk_04 = 2;
    self->unk_08 = -1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

}
