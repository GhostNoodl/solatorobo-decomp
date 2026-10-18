#include "types.h"
#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline void Arrive02155ac4(VObj *self, u8 *tgt) {
    if (LFLD(u8 *, self, 0x98) == tgt) {
        if (LFLD(s8, self, 0xb3) > 1) {
            LFLD(s8, self, 0xb2) = 0;
        }
    } else {
        LFLD(s8, self, 0xb2) = 10;
        LFLD(s8, self, 0xb3) = 2;
    }
}

void func_ov000_02155ac4(VObj *self) {
    s32 w = self->vfunc_40();
    u8 *cur;
    u8 *tgt;
    if (LFLD(u32, self, 0xc) & 0x300000) {
        if (LFLD(u32, self, 0xc) & 0x100000) {
            LFLD(s16, self, 0xa0) -= LFLD(s16, self, 0xa2);
            if (LFLD(s16, self, 0xa0) > -w) {
                return;
            }
            self->vfunc_c0();
        } else {
            LFLD(s16, self, 0xa0) += LFLD(s16, self, 0xa2);
            if (LFLD(s16, self, 0xa0) < w) {
                return;
            }
            self->vfunc_c0();
        }
        return;
    }
    tgt = LFLD(u8 *, self, 0xa4);
    cur = LFLD(u8 *, self, 0x98);
    if (cur == tgt) {
        LFLD(s16, self, 0x9e) = 0;
        return;
    }
    if (LFLD(s16, tgt, 4) > LFLD(s16, cur, 4)) {
        LFLD(s16, self, 0x9e) -= LFLD(s16, self, 0xa2);
        if (LFLD(s16, self, 0x9e) > -w) {
            return;
        }
        LFLD(s16, self, 0x9e) += (s16)w;
        LFLD(u8 *, self, 0x98) = LFLD(u8 *, cur, 0x2c);
        Arrive02155ac4(self, tgt);
    } else {
        LFLD(s16, self, 0x9e) += LFLD(s16, self, 0xa2);
        if (LFLD(s16, self, 0x9e) < w) {
            return;
        }
        LFLD(s16, self, 0x9e) -= (s16)w;
        LFLD(u8 *, self, 0x98) = LFLD(u8 *, cur, 0x28);
        Arrive02155ac4(self, tgt);
    }
}
}
