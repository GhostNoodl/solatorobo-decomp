#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

static inline s32 LoApproach(s32 cur, s32 target, s32 rate) {
    return cur + (s32)(((s64)(target - cur) * rate + 0x800) >> 12);
}

void LoBase021cafc0_021cb0b8_PostUpdate(LoBase021cafc0_021cb0b8 *self) {
    UiPanel *o;
    s32 n;
    if (self->state != 2) {
        return;
    }
    self->openTime = self->openLen;
    self->openRatio = 0x1000;
    self->vfunc_c4();
    o = (UiPanel *)((u8 *)self->panel);
    if (o == NULL) {
        return;
    }
    if (LBIT(o, 0).b3 != 1) {
        return;
    }
    n = ++o->unk_20;
    if (n < 0x12) {
        o->unk_24 = LoApproach(o->unk_24, 0x8000, 0x19a);
    } else if (n < 0x30) {
        o->unk_24 = LoApproach(o->unk_24, 0, 0xcd);
    } else {
        o->unk_20 = 0;
        o->unk_24 = 0;
    }
}

}
