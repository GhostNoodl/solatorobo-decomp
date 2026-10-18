#include "ov000/LoCommon.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
BOOL func_0203e63c(void *p);
BOOL func_ov000_021580e8(void *self);

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

static inline BOOL LoPartReady(u8 *q) {
    BOOL r = TRUE;
    if (LFLD(u8 *, q, 0x24) && !LoResDone(LFLD(u8 *, q, 0x24))) {
        r = FALSE;
    }
    if (LFLD(void *, q, 0x28) && !func_02054f10(LFLD(void *, q, 0x28), 0xffff)) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_02157fc0(void *self) {
    BOOL ok = func_ov000_021580e8(self);
    if (LFLD(u8 *, self, 0xd4) && !LoPartReady(LFLD(u8 *, self, 0xd4))) {
        ok = FALSE;
    }
    if (LFLD(u8 *, self, 0xd8) && !LoPartReady(LFLD(u8 *, self, 0xd8))) {
        ok = FALSE;
    }
    return ok;
}

}
