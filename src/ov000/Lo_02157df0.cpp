#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

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
    Heap_Free(p);
}

void func_ov000_02157df0(UiList021cb4a8 *self) {
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_d4 != NULL) {
            u8 *p = self->unk_d4;
            if (p != NULL) {
                Free02157df0(p);
            }
            self->unk_d4 = NULL;
        }
        LO_HEAP_POP(saved);
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_d8 != NULL) {
            u8 *p = self->unk_d8;
            if (p != NULL) {
                Free02157df0(p);
            }
            self->unk_d8 = NULL;
        }
        LO_HEAP_POP(saved);
    }
}
}
