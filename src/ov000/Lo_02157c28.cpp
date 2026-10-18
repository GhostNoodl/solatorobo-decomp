#include "ov000/LoCommon.h"

extern "C" {

void func_0203df0c(void *p);
BOOL func_ov000_02152a58(void *self);
BOOL func_02054f10(void *p, s32 a);
BOOL func_0203e63c(void *p);
void func_ov000_0215429c(void *self);
void func_ov000_0215f0ec(void *p, s32 a);

static inline BOOL LoSubReady(void *p) {
    if (LFLD(void *, p, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, p, 0x6c))) {
        LFLD(void *, p, 0x6c) = NULL;
    } else {
        return LBIT(p, 4).b6 == 0 ? TRUE : FALSE;
    }
    return TRUE;
}

void func_ov000_02157c28(void *self) {
    s32 v;
    LFLD(s16, self, 0x64) = (LFLD(u32, self, 0xc) & 0x4000000) ? 0 : 0xc;
    LFLD(s32, self, 0x24) = 0x100 - LFLD(s16, self, 0x64) * 2;
    func_ov000_0215429c(self);
    v = LFLD(s32, self, 0x24);
    LFLD(s32, self, 0x2c) = 1;
    LFLD(s32, self, 0x58) = v + 0x10;
    LFLD(s32, self, 0x5c) = 0;
    LFLD(s32, self, 0x60) = 0;
    LFLD(s32, LFLD(void *, self, 0xac), 0x10) = (v - 0x10) << 12;
}

void func_ov000_02157c90(void *self, s32 a) {
    void *p = func_0203dd9c(0x2c);
    if (p != NULL) {
        LFLD(s32, p, 0x0) = 0;
        LFLD(s32, p, 0x4) = 0;
        LFLD(s32, p, 0x8) = 0;
        LFLD(s32, p, 0xc) = 0;
        LFLD(s32, p, 0x10) = 0;
        LFLD(s32, p, 0x14) = 0x80;
        LFLD(s32, p, 0x18) = 6;
        LFLD(s32, p, 0x24) = 0;
        LFLD(s32, p, 0x28) = 0;
    }
    LFLD(void *, self, 0xd4) = p;
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        LFLD(u32, LFLD(void *, self, 0xd4), 0) |= 0x10;
    }
    func_ov000_0215f0ec(LFLD(void *, self, 0xd4), a);
    LFLD(s32, LFLD(void *, self, 0xd4), 0x14) = LFLD(s32, LFLD(void *, LFLD(void *, self, 0xd4), 0x24), 0x44) + 0x10;
}

}
