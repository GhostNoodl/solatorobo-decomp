#include "ov000/LoCommon.h"

struct LoDE { s32 d; s32 *e; };
extern "C" {

u32 func_0204045c(void);
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

struct Obj0216912c {
    u8 unk_00[0x58];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    u8 unk_70[0x10];
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c[0x14];
    s32 unk_a0;
    u16 unk_a4;
    u8 unk_a6[0x2];
    s32 unk_a8;
    s32 unk_ac;
};

void func_ov000_0216912c(Obj0216912c *self, s32 a, s32 b, s32 c, LoDE de) {
    if (self->unk_a0 != a) {
        self->unk_a0 = a;
        self->unk_5c = 0;
        self->unk_60 = 0;
        self->unk_64 = 0;
        self->unk_68 = 0;
        self->unk_6c = 0x1000;
        self->unk_58 = b;
    }
    if (c < (self->unk_64 >> 12)) {
        self->unk_a8 = 10;
        self->unk_ac = self->unk_5c;
        self->unk_a4 = func_0204045c();
    }
    if (self->unk_60 == 0) {
        self->unk_5c = c << 12;
    }
    func_ov000_0215fe1c(self, c, de.d);
    self->unk_80 = de.e[0];
    self->unk_84 = de.e[1];
    self->unk_88 = de.e[2];
    LBIT(self, 0xc).b1 = 0;
    LBIT(self, 0xc).b16 = 1;
}

}
