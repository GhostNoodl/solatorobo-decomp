#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 lo, s32 hi);

void func_ov000_0216a438(void *self, s32 lo, s32 hi, u8 v) {
    if (*(s32 *)((u8 *)self + 0x60) == 0) {
        *(s32 *)((u8 *)self + 0x5c) = hi << 12;
    }
    func_ov000_0215fe1c(self, lo, hi);
    *(u8 *)((u8 *)self + 0xac) = v;
    *(u32 *)((u8 *)self + 0xc) = (*(u32 *)((u8 *)self + 0xc) & ~2) | 0x10000;
}

void func_ov000_0216a474(void *self) {
    *(s32 *)((u8 *)self + 0x9c) = 0;
    *(s32 *)((u8 *)self + 0xa0) = 0;
    *(u8 *)((u8 *)self + 0xa4) = 0;
    *(s16 *)((u8 *)self + 0xa6) = 0;
    *(s32 *)((u8 *)self + 0xa8) = 0;
    *(u8 *)((u8 *)self + 0xac) = 0;
}

}
