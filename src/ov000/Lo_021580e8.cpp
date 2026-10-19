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

void func_ov000_02158120(VObj *self, s32 delta, s32 arg) {
    s8 sel = LFLD(s8, self, 0xb1);
    s32 off = 0;
    LFLD(s8, self, 0xb0) = sel;
    LFLD(s8, self, 0xb1) = LFLD(s8, self, 0xb1) - (s8)delta;
    if (LFLD(s16, self, 0x9c) <= LFLD(s32, self, 0x20)) {
        if (LFLD(s8, self, 0xb1) <= 0) {
            LFLD(s8, self, 0xb1) = 0;
        }
    } else if (LFLD(s16, LFLD(void *, self, 0x98), 4) == 0) {
        if (LFLD(s8, self, 0xb1) <= 0) {
            LFLD(s8, self, 0xb1) = 0;
        }
    } else {
        off = LFLD(s8, self, 0xb1) - 1;
        if (off < 0) {
            if (off + LFLD(s16, LFLD(void *, self, 0x98), 4) >= 0) {
                LFLD(s8, self, 0xb1) = 1;
            } else {
                LFLD(s8, self, 0xb1) = 0;
                off = -LFLD(s16, LFLD(void *, self, 0x98), 4);
            }
        } else {
            off = 0;
        }
    }
    self->vfunc_bc(off, arg);
    LFLD(s16, self, 0xa2) = 4;
}

}
