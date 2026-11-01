#include "types.h"
#include "ov000/ObjLayouts.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline BOOL Cond1_02155c38(LoBase021caac8_021caec8 *self) {
    u8 *p = self->unk_98;
    if (p == NULL) {
        return TRUE;
    }
    return LFLD(s16, p, 4) == 0;
}

static inline BOOL Cond2_02155c38(LoBase021caac8_021caec8 *self) {
    u8 *p = self->unk_98;
    if (p == NULL) {
        return TRUE;
    }
    if (LFLD(s16, p, 4) == self->unk_9c - self->unk_20 || self->unk_9c < self->unk_20) {
        return TRUE;
    }
    return FALSE;
}

void func_ov000_02155c38(LoBase021caac8_021caec8 *self) {
    if (++self->unk_c4 < 0x18) {
        self->unk_c8 += (s32)(((s64)(0x3000 - self->unk_c8) * (s64)0x148 + 0x800) >> 12);
    } else if (self->unk_c4 < 0x40) {
        self->unk_c8 += (s32)(((s64)(-self->unk_c8) * (s64)0xcd + 0x800) >> 12);
    } else {
        self->unk_c4 = 0;
        self->unk_c8 = 0;
    }
    if (Cond1_02155c38(self)) {
        self->unk_c2 -= 4;
    } else {
        self->unk_c2 += 4;
    }
    if (self->unk_c2 < 0) {
        self->unk_c2 = 0;
    } else if (self->unk_c2 > 30) {
        self->unk_c2 = 30;
    }
    if (Cond2_02155c38(self)) {
        self->unk_c3 -= 4;
    } else {
        self->unk_c3 += 4;
    }
    if (self->unk_c3 < 0) {
        self->unk_c3 = 0;
    } else if (self->unk_c3 > 30) {
        self->unk_c3 = 30;
    }
}
}
