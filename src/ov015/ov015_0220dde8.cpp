#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212f64[];
extern u8 data_ov015_02212f3c[];
void func_ov002_021e4cd8(void *self);
void func_ov000_0218e9c4(void *a);
void func_ov000_0218fe1c(void *a);
void MTX_Identity33_(void *a);
void func_ov002_021e4d4c(void *self);
void func_ov000_0218fee4(void *a);
void func_ov000_0218ea20(void *a);

void *func_ov015_0220dde8(u8 *self) {
    s32 i;
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4cd8(self);
    SET_VT(self, data_ov015_02212f3c);
    func_ov000_0218e9c4(self + 0x4c);
    func_ov000_0218fe1c(self + 0x184);
    func_ov000_0218e9c4(self + 0x26c);
    func_ov000_0218fe1c(self + 0x3a8);
    FLD(u16, self, 0x490) = 0x1000;
    FLD(s32, self, 0x494) = -1;
    FLD(u16, self, 0x498) = 0xffff;
    FLD(s32, self, 0x4d0) = 0;
    FLD(s32, self, 0x4d4) = 0;
    FLD(s32, self, 0x4d8) = 0;
    MTX_Identity33_(self + 0x4dc);
    FLD(u16, self, 0x3a4) = 0;
    FLD(s32, self, 0x500) = 0x1000;
    FLD(s32, self, 0x504) = 0x1000;
    FLD(s32, self, 0x508) = 0x1000;
    FLD(s32, self, 0x50c) = 0x1000;
    FLD(s32, self, 0x510) = 0;
    FLD(s32, self, 0x514) = 0;
    for (i = 0; i < 8; i++) {
        ((Ov015SlotHost *)self)->slots[i].a = 0;
        ((Ov015SlotHost *)self)->slots[i].b = 0;
    }
    FLD(s32, self, 0x518) = 0;
    FLD(s32, self, 0x51c) = 0;
    FLD(s32, self, 0x520) = 0;
    return self;
}

void *func_ov015_0220deb8(u8 *self) {
    func_ov000_0218fee4(self + 0x3a8);
    func_ov000_0218ea20(self + 0x26c);
    func_ov000_0218fee4(self + 0x184);
    func_ov000_0218ea20(self + 0x4c);
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);

    return self;
}

void *func_ov015_0220defc(u8 *self) {
    func_ov000_0218fee4(self + 0x3a8);
    func_ov000_0218ea20(self + 0x26c);
    func_ov000_0218fee4(self + 0x184);
    func_ov000_0218ea20(self + 0x4c);
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
    func_0203de1c(self);
    return self;
}

}
