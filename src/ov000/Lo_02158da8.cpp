#include "ov000/LoCommon.h"

extern "C" {

void func_0203df0c(void *p);
BOOL func_ov000_02152a58(void *self);
BOOL func_ov000_021580e8(void *self);
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

void func_ov000_02158da8(void *self) {
    if (LFLD(void *, self, 0xe4) != NULL) {
        func_0203df0c(LFLD(void *, self, 0xe4));
        LFLD(void *, self, 0xe4) = NULL;
    }
    LO_FREE_V(self, 0xec);
}

BOOL func_ov000_02158e14(void *self) {
    BOOL r = func_ov000_021580e8(self);
    void *p = LFLD(void *, self, 0xec);
    if (p != NULL && !LoSubReady(p)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02158e80(VObj *self, s32 n, s32 b) {
    s8 old = LFLD(s8, self, 0xb1);
    LFLD(s8, self, 0xb1) = old - (s8)n;
    LFLD(s8, self, 0xb0) = old;
    if (LFLD(s8, self, 0xb1) < 0) {
        LFLD(s8, self, 0xb1) = 0;
    }
    self->vfunc_bc(LFLD(s8, self, 0xb1) - LFLD(s8, self, 0xb0), b);
    LFLD(u16, self, 0xa2) = 4;
}

}
