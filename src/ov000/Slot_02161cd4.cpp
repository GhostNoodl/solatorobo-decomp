#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021cabd8[];
void *func_ov000_0218ea20(void *p);
void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));

// The mixed (u8 *) casts below are no-ops, but they change which
// addresses MWCC shares between the calls; this mix matches.
static inline void StopSlot(u8 *self, u8 i) {
    if (i > 2) {
        return;
    }
    func_ov000_0218ec60(self + 0x78 + i * 0x138, 0, 0, 1, 0);
    func_ov000_0218edf0((u8 *)self + 0x78 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, self + i * 0x138, 0x78) = 0;
    func_ov000_0218edf0(self + 0x2e8 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, (u8 *)self + i * 0x138, 0x2e8) = 0;
}

static inline void Dtor02161cd4(u8 *self) {
    LFLD(void *, self, 0) = data_ov000_021cabd8;
    StopSlot(self, LFLD(u8, self, 5));
    StopSlot(self, (LFLD(u8, self, 5) & 1) ^ 1);
    __cxa_vec_cleanup(self + 0x2e8, 2, 0x138, (void (*)(void *))func_ov000_0218ea20);
    __cxa_vec_cleanup(self + 0x78, 2, 0x138, (void (*)(void *))func_ov000_0218ea20);
}

u8 *func_ov000_02161cd4(u8 *self) {
    Dtor02161cd4(self);
    return self;
}

u8 *func_ov000_02161e3c(u8 *self) {
    Dtor02161cd4(self);
    func_0203de1c(self);
    return self;
}

}
