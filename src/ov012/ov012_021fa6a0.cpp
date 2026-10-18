#include "ov012/ov012.h"

extern "C" {
extern u8 data_ov012_0220ac9c[];

#pragma force_active on
Ov012Actor *func_ov012_021fa6a0(Ov012Actor *self) {
    u8 i;
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220ac9c;
    func_ov000_0218e9c4((u8 *)self + 0x174);
    func_ov000_0218fe1c((u8 *)self + 0x2ac);
    FLD(s32, self, 0x10c) = 0x40;
    FLD(u8, self, 0x110) = 0;
    FLD(u8, self, 0x136) = 0;
    FLD(u8, self, 0x137) = 0;
    FLD(s16, self, 0x112) = 0;
    for (i = 0; i < 3; i++) {
        ((s32 *)((u8 *)self + 0x13c))[i] = -1;
    }
    FLD(u8, self, 0x3af) = 0;
    FLD(u8, self, 0x3ae) = 0;
    FLD(u16, self, 0x170) = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 data_ov012_0220ac9c[];
void *func_ov012_021fa724(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ac9c;
    Ov012_StopSnd();
    func_ov000_0218fee4((u8 *)self + 0x2ac);
    func_ov000_0218ea20((u8 *)self + 0x174);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
extern u8 data_ov012_0220ac9c[];
void *func_ov012_021fa794(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ac9c;
    Ov012_StopSnd();
    func_ov000_0218fee4((u8 *)self + 0x2ac);
    func_ov000_0218ea20((u8 *)self + 0x174);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}
