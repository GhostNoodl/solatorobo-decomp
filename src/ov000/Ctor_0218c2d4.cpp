#include "types.h"

#define F(type, off) (*(type *)((u8 *)self + (off)))

extern "C" {
extern u8 data_ov000_021cc3b4[];
void func_0203db10(void *p);

u8 *func_ov000_0218c2d4(u8 *self) {
    s32 i;
    F(void *, 0) = data_ov000_021cc3b4;
    func_0203db10(self + 0x24);
    F(s32, 0x4) = 0;
    F(s32, 0x8) = 0;
    F(u16, 0xc) = 0xffff;
    F(u16, 0xe) = 0xffff;
    F(u16, 0x20) = 0xffff;
    F(s32, 0x10) = 0;
    F(u8, 0x14) = 1;
    F(u8, 0x15) = 2;
    F(u8, 0x16) = 0;
    F(u8, 0x17) = 0xff;
    for (i = 0; i < 4; i++) {
        ((u16 *)(self + 0x18))[i] = 0;
    }
    F(s16, 0x22) = -1;
    F(s32, 0x2c) = 0;
    F(s32, 0x30) = 0;
    F(s32, 0x34) = 0;
    F(s32, 0x38) = 0;
    F(s32, 0x3c) = 0;
    F(s32, 0x40) = 0;
    F(s32, 0x44) = 0;
    F(s32, 0x48) = 0;
    F(s32, 0x4c) = 0;
    F(s32, 0x50) = 0;
    F(s32, 0x54) = 0;
    F(s32, 0x58) = 0;
    F(s32, 0x5c) = 0;
    F(s32, 0x60) = 0;
    F(s32, 0x64) = 0;
    F(s32, 0x68) = 0;
    F(s32, 0x6c) = 0;
    F(s32, 0x70) = 0;
    F(s32, 0x74) = 0;
    F(s32, 0x78) = 0;
    F(u16, 0x7c) = 0;
    F(u16, 0x7e) = 0;
    F(u16, 0x80) = 0;
    F(u16, 0x90) = 0xffff;
    F(u8, 0x92) = 0;
    F(u8, 0x93) = 0;
    F(u8, 0x94) = 0;
    F(u16, 0x96) = 0;
    F(u16, 0x98) = 0;
    F(s32, 0x9c) = 0;
    F(s32, 0xa0) = 0;
    F(s32, 0xa4) = 0;
    F(s32, 0xa8) = 0;
    return self;
}
}
