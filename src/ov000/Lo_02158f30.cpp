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

void func_ov000_02158f30(VObj *self, s32 n, s32 b) {
    s8 old = LFLD(s8, self, 0xb1);
    s16 max = LFLD(s16, self, 0x9c);
    s32 m = LFLD(s32, self, 0x20);
    LFLD(s8, self, 0xb0) = old;
    if (max > m) {
        LFLD(s8, self, 0xb1) = old + (s8)n;
        if (LFLD(s8, self, 0xb1) + m > max) {
            LFLD(s8, self, 0xb1) = max - m;
        }
    }
    self->vfunc_bc(LFLD(s8, self, 0xb1) - LFLD(s8, self, 0xb0), b);
    LFLD(u16, self, 0xa2) = 4;
}

void func_ov000_02158f98(VObj *self, s32 n, s32 b) {
    s8 old = LFLD(s8, self, 0xb1);
    LFLD(s8, self, 0xb0) = old;
    if (LFLD(u32, self, 0xc) & 0x20000) {
        LFLD(s8, self, 0xb1) = old + (s8)n;
        if (LFLD(s8, self, 0xb1) + LFLD(s32, self, 0x20) > LFLD(s16, self, 0x9c)) {
            LFLD(s8, self, 0xb1) = LFLD(s16, self, 0x9c) - LFLD(s32, self, 0x20);
        }
    }
    self->vfunc_bc(LFLD(s8, self, 0xb1) - LFLD(s8, self, 0xb0), b);
    LFLD(u16, self, 0xa2) = 8;
}

}
