#include "ov000/LoCommon.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
extern u8 *data_ov000_021ccd54;
void MTX_Identity43_(void *m);
void MTX_RotY43_(void *m, s32 s, s32 c);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

void func_ov000_0216c954(void *self, u16 a, s32 b) {
    LFLD(u32, self, 0) = 0;
    LBIT(self, 0).b2 = 0;
    LFLD(s32, self, 0x4) = 2;
    LFLD(u16, self, 0x1c) = a;
    LFLD(s32, self, 0x8) = b;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(s32, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(u16, self, 0x28) = 0xffff;
    LFLD(u16, self, 0x2a) = 0xffff;
    LFLD(s32, self, 0x2c) = 0;
    LFLD(s32, self, 0x30) = 0;
    LFLD(s32, self, 0x34) = 0;
    LFLD(s32, self, 0x38) = 0;
}

}
