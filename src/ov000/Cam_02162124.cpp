#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021cabc8[];
extern u8 data_ov000_021cabd8[];
extern u8 data_ov000_021cac02[];
void func_ov000_0218e9c4(void *p);
void func_ov000_0218ea20(void *p);
void func_02009e24(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void MI_CpuFill8(void *dst, u8 value, u32 size);
void func_ov000_0218fe1c(void *p);
void func_02043548(void *p);
void MTX_Identity44_(void *m);

u8 *func_ov000_02162124(u8 *self) {
    LFLD(void *, self, 0) = data_ov000_021cabc8;
    LFLD(void *, self, 4) = data_ov000_021cabd8;
    func_02009e24(self + 0x7c, 2, 0x138, func_ov000_0218e9c4, func_ov000_0218ea20);
    func_02009e24(self + 0x2ec, 2, 0x138, func_ov000_0218e9c4, func_ov000_0218ea20);
    LFLD(u8, self, 8) = 0x14;
    LFLD(u8, self, 9) = 0;
    LFLD(u8, self, 0xa) = 0;
    MI_CpuFill8(self + 0xb, 0, 0x20);
    MI_CpuFill8(self + 0x2b, 0, 0x18);
    MI_CpuFill8(self + 0x43, 0, 0x20);
    MI_CpuFill8(self + 0x63, 0, 0x18);
    LFLD(u8, self, 0x7b) = 0;
    func_ov000_0218fe1c(self + 0x55c);
    func_02043548(self + 0x644);
    MTX_Identity44_(self + 0x668);
    LFLD(s32, self, 0x6a8) = 0;
    LFLD(s32, self, 0x6ac) = 0;
    LFLD(s32, self, 0x6b0) = 0;
    LFLD(s32, self, 0x6b4) = 0x1000;
    LFLD(s32, self, 0x6b8) = 0;
    LFLD(u8, self, 0x6bc) = 0;
    LFLD(void *, self, 0x6c0) = data_ov000_021cac02;
    LFLD(s32, self, 0x6c4) = 0;
    LFLD(u16, self, 0x6c8) = 0x1000;
    LFLD(s32, self, 0x6cc) = 0;
    LFLD(s32, self, 0x6d0) = 0;
    LFLD(s32, self, 0x6d4) = 0;
    LFLD(s32, self, 0x6d8) = 0;
    LFLD(s32, self, 0x6dc) = 0;
    LFLD(s32, self, 0x6e0) = 0;
    LFLD(u16, self, 0x6e4) = 0;
    LFLD(u16, self, 0x6e6) = 0;
    LFLD(u16, self, 0x6e8) = 0;
    LFLD(s32, self, 0x6ec) = 0;
    LFLD(s32, self, 0x6f0) = 0;
    LFLD(s32, self, 0x6f4) = 0;
    LFLD(s32, self, 0x6f8) = 0;
    LFLD(s32, self, 0x6fc) = 0;
    LFLD(s32, self, 0x700) = 0;
    LFLD(s32, self, 0x704) = 0;
    return self;
}

}
