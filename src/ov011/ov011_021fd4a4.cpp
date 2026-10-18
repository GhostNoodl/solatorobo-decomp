#include "ov011/ov011.h"

extern "C" {

struct Ov011Fd4a4 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad0 : 6;
    u8 pad1;
    u16 id;
    u32 pad4;
    s32 unk_08;
    u8 sub[1];
};

#pragma force_active on
void func_ov011_021fd4a4(Ov011Fd4a4 *self) {
    self->b1 = 0;
    self->id = 0xffff;
    self->unk_08 = 0;
    func_ov003_021da48c(self->sub, 1);
}
#pragma force_active reset
}
