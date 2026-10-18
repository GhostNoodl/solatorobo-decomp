#include "ov000/Actor.h"

extern "C" {

void func_ov000_0218dd8c(Actor *self, u16 base, s32 turn, s32 range) {
    if (!(data_02097dc8->unk_10 & 0xf0)) {
        return;
    }
    self->unk_98 = base + func_0203d434(data_02097dc8, range);
    func_ov000_0218dbe0(self, turn);
}

}
