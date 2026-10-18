#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
void func_ov000_0216bae4(void *dst, void *src);
BOOL func_02054f10(void *a, s32 b);
BOOL func_0203e63c(void *p);
void func_ov000_0215eab4(void *p);

static inline BOOL LoResDone(u8 *o) {
    if (LFLD(void *, o, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, o, 0x6c))) {
        LFLD(void *, o, 0x6c) = NULL;
    } else {
        return LBIT(o, 4).b6 ? FALSE : TRUE;
    }
    return TRUE;
}

BOOL func_ov000_02152a58(void *self) {
    BOOL ok = TRUE;
    if (LFLD(void *, self, 0x10) && !func_02054f10(LFLD(void *, self, 0x10), 0xffff)) {
        ok = FALSE;
    }
    if (LFLD(u8 *, self, 0x14) && !LoResDone(LFLD(u8 *, self, 0x14))) {
        ok = FALSE;
    }
    if (LFLD(u8 *, self, 0x18) && !LoResDone(LFLD(u8 *, self, 0x18))) {
        ok = FALSE;
    }
    return ok;
}

}
