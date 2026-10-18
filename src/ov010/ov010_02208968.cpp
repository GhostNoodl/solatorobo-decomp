#include "ov010/ov010.h"

extern "C" {

extern void func_ov010_022046ac(void *self);

BOOL func_ov010_02208968(void *self, s32 *out) {
    *out = 9;
    return TRUE;
}

void func_ov010_02208978(void *self, s32 *out) {
    out[0] = 0x905;
    out[1] = 0x906;
    out[2] = 0x904;
    out[3] = 0x900;
    out[4] = 0x903;
    out[5] = 0x900;
    out[7] = 0x902;
}

void func_ov010_022089b4(void *self) {
    func_ov010_022046ac(self);
    FLD(u8, self, 0xf3) = FLD(s16, self, 0x18) == 2;
}

}
