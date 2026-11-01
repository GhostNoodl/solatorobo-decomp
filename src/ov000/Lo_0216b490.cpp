#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b);
u32 func_0204045c(void);

struct Obj0216b490 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c[0x8];
    s32 unk_14;
    s32 unk_18;
};

void func_ov000_0216b490(Obj0216b490 *self) {
    LO_FREE_M(self, 0x8);
    self->unk_00 = 0;
    self->unk_04 = 2;
    self->unk_08 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
}

void func_ov000_0216b508(void *self, s32 a, s32 b) {
    LBIT(self, 0).b1 = a != 0 ? 1 : 0;
    LBIT(self, 0).b3 = b != 0 ? 1 : 0;
    LBIT(self, 0).b2 = 1;
}

}
