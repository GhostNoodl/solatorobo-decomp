#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void *self);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);

void func_ov000_02153fd8(void *self) {
    LO_FREE_V(self, 0x1c);
    LO_FREE_V(self, 0x20);
    LFLD(s32, self, 0) = 0;
    LFLD(s16, self, 4) = 0;
    LFLD(s16, self, 6) = 0;
    LFLD(u16, self, 8) = 0xffff;
    LFLD(u16, self, 0xa) = 0xffff;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(s32, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
    LFLD(s32, self, 0x2c) = 0;
}

}
