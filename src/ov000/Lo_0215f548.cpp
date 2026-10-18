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

void func_ov000_0215f548(void *self) {
    LO_FREE_V(self, 0x24);
    LO_FREE_M(self, 0x28);
    LFLD(s32, self, 0) = 0;
    LFLD(s32, self, 4) = 0;
    LFLD(s32, self, 8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(s32, self, 0x14) = 0x80;
    LFLD(s32, self, 0x18) = 6;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
}

}
