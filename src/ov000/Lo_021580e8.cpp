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

BOOL func_ov000_021580e8(void *self) {
    BOOL r = func_ov000_02152a58(self);
    if (LFLD(void *, self, 0xb4) != NULL && !func_02054f10(LFLD(void *, self, 0xb4), 0xffff)) {
        r = FALSE;
    }
    return r;
}

}
