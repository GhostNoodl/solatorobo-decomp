#include "ov000/LoCommon.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
extern u8 *data_ov000_021ccd54;
void func_02011820(void *m);
void func_02011994(void *m, s32 s, s32 c);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

void func_ov000_0216e574(void *self) {
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(s32, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 1;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
    LFLD(s32, self, 0x2c) = 0;
    LFLD(s32, self, 0x30) = 0;
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(u16, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
}

}
