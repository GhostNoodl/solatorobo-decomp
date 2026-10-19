#include "ov000/LoCommon.h"

extern "C" {

static inline s32 LoApproach(s32 cur, s32 target, s32 rate) {
    return cur + (s32)(((s64)(target - cur) * rate + 0x800) >> 12);
}

void func_ov000_0215ae80(VObj *self) {
    u8 *o;
    s32 n;
    if (LFLD(s32, self, 4) != 2) {
        return;
    }
    LFLD(s32, self, 0x30) = LFLD(s32, self, 0x34);
    LFLD(s32, self, 0x38) = 0x1000;
    self->vfunc_c4();
    o = LFLD(u8 *, self, 0xac);
    if (o == NULL) {
        return;
    }
    if (LBIT(o, 0).b3 != 1) {
        return;
    }
    n = ++LFLD(s32, o, 0x20);
    if (n < 0x12) {
        LFLD(s32, o, 0x24) = LoApproach(LFLD(s32, o, 0x24), 0x8000, 0x19a);
    } else if (n < 0x30) {
        LFLD(s32, o, 0x24) = LoApproach(LFLD(s32, o, 0x24), 0, 0xcd);
    } else {
        LFLD(s32, o, 0x20) = 0;
        LFLD(s32, o, 0x24) = 0;
    }
}

}
