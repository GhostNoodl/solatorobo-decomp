#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

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

BOOL func_ov000_02157fc0(LoBase021caac8_021cb2a8 *self) {
    BOOL ok = func_ov000_021580e8(self);
    if (self->unk_d4 && !LoPartReady(self->unk_d4)) {
        ok = FALSE;
    }
    if (self->unk_d8 && !LoPartReady(self->unk_d8)) {
        ok = FALSE;
    }
    return ok;
}

}
