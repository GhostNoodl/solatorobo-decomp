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

struct Obj02163254 {
    u8 unk_00[0x28];
    s32 unk_28;
};

void func_ov000_02163254(Obj02163254 *self) {
    LO_FREE_V(self, 0x20);
    LO_FREE_V(self, 0x24);
    self->unk_28 = 4;
}

}
