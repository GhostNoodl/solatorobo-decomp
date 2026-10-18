#include "ov000/LoCommon.h"

extern "C" {

static inline void Free02157df0(u8 *p) {
    LO_FREE_V(p, 0x24);
    LO_FREE_M(p, 0x28);
    LFLD(s32, p, 0x0) = 0;
    LFLD(s32, p, 0x4) = 0;
    LFLD(s32, p, 0x8) = 0;
    LFLD(s32, p, 0xc) = 0;
    LFLD(s32, p, 0x10) = 0;
    LFLD(s32, p, 0x14) = 0x80;
    LFLD(s32, p, 0x18) = 6;
    LFLD(s32, p, 0x24) = 0;
    LFLD(s32, p, 0x28) = 0;
    func_0203de1c(p);
}

void func_ov000_02157df0(u8 *self) {
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(u8 *, self, 0xd4) != NULL) {
            u8 *p = LFLD(u8 *, self, 0xd4);
            if (p != NULL) {
                Free02157df0(p);
            }
            LFLD(u8 *, self, 0xd4) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(u8 *, self, 0xd8) != NULL) {
            u8 *p = LFLD(u8 *, self, 0xd8);
            if (p != NULL) {
                Free02157df0(p);
            }
            LFLD(u8 *, self, 0xd8) = NULL;
        }
        LO_HEAP_POP(saved);
    }
}
}
