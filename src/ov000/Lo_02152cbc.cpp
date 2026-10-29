#include "ov000/LoCommon.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 func_0204045c(void);
void func_ov000_0215f0ec(void *p, void *q);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void func_ov000_02152cbc(void *self) {
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(s32, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x1c) = 8;
    LFLD(s32, self, 0x20) = 1;
    LFLD(s32, self, 0x24) = 0x80;
    LFLD(s32, self, 0x28) = 0;
    LFLD(s32, self, 0x2c) = 0;
    LFLD(s32, self, 0x30) = 0;
    LFLD(s32, self, 0x34) = 0xc000;
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0xc000;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s16, self, 0x48) = 0;
    LFLD(s16, self, 0x4a) = 0xb;
    LFLD(s32, self, 0x58) = 0;
    LFLD(s32, self, 0x5c) = 0;
    LFLD(s32, self, 0x60) = 0;
    LFLD(s16, self, 0x64) = 0;
    LFLD(s16, self, 0x66) = 0;
    LFLD(s16, self, 0x68) = 0;
    LFLD(s32, self, 0x54) = 0x14;
    LFLD(s32, self, 0x6c) = 0;
    LFLD(s32, self, 0x70) = 0;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x7c) = 0;
    LFLD(s32, self, 0x80) = 0;
}

}
