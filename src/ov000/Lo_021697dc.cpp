#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b);
u32 func_0204045c(void);

struct Obj021697dc {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x4c];
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    u8 unk_68[0x42];
    u16 unk_aa;
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
};

void func_ov000_021697dc(Obj021697dc *self, s32 a, s32 b) {
    if (a < (self->unk_64 >> 12)) {
        self->unk_ac = 9;
        self->unk_b0 = self->unk_5c;
        self->unk_aa = func_0204045c();
        self->unk_b4 = -1;
    }
    if (self->unk_60 == 0) {
        self->unk_5c = b << 12;
    }
    func_ov000_0215fe1c(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
