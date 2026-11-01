#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

static inline s32 LoApproach(s32 cur, s32 target, s32 rate) {
    return cur + (s32)(((s64)(target - cur) * rate + 0x800) >> 12);
}

void func_ov000_0215ae80(LoBase021cafc0_021cb0b8 *self) {
    u8 *o;
    s32 n;
    if (self->unk_04 != 2) {
        return;
    }
    self->unk_30 = self->unk_34;
    self->unk_38 = 0x1000;
    self->vfunc_c4();
    o = self->unk_ac;
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
