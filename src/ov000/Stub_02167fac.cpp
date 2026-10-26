#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b);

void func_ov000_02167fac(void *self, s32 a, s32 b) {
    func_ov000_0215fe1c(self, a, b);
    *(u32 *)((u8 *)self + 0xc) = (*(u32 *)((u8 *)self + 0xc) & ~2) | 0x10000;
}

void func_ov000_02167fcc(void *self) {
    *(s32 *)((u8 *)self + 0x9c) = 0x0;
}

}
