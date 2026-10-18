#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void func_ov000_0215fe1c(void *self, s32 a, s32 b, ...);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

void func_ov000_02168ee0(void *self) {
    LFLD(s32, self, 0x28) = 0;
    LFLD(s32, self, 0x30) = 0xc000;
    LFLD(s32, self, 0x50) = 0x30;
    LFLD(s32, self, 0x54) = 4;
    LFLD(u32, self, 0xc) |= 0x240;
    LFLD(s32, self, 0x58) = 1;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x7c) = -0x2000;
    func_ov000_0215fdfc(self, 1, data_ov000_021c9b28);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9b2e);
}

}
