#include "ov000/LoCommon.h"
#include "nitro/std.h"

extern "C" {


struct LoInitEC44Self {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
};

static inline void LoInitEC44(LoInitEC44Self *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_1c = 0;
    self->unk_18 = 0;
    self->unk_10 = 0x80000;
    self->unk_14 = 0xf000;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
}

void func_ov000_0215f514(void *p) {
    LFLD(s32, p, 0x0) = 0;
    LFLD(s32, p, 0x4) = 0;
    LFLD(s32, p, 0x8) = 0;
    LFLD(s32, p, 0xc) = 0;
    LFLD(s32, p, 0x10) = 0;
    LFLD(s32, p, 0x14) = 0x80;
    LFLD(s32, p, 0x18) = 6;
    LFLD(s32, p, 0x24) = 0;
    LFLD(s32, p, 0x28) = 0;
}

}
