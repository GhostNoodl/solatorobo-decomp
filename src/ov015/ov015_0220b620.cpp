#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212f20[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);

void *func_ov015_0220b620(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220b658(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

BOOL func_ov015_0220b698(u8 *self, u8 *p) {
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0xc) = 0x50;
    FLD(s32, self, 0x10) = FLD(u16, p, 0xd4);
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e47, 0x19a, 0);
    func_ov000_02191618(p + 0x244);
    FLD(u16, p, 0x104) = 0x800;
    FLD(s32, p, 0xbc) = 1;
    return TRUE;
}

}
