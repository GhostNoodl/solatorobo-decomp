#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d2c2c(Task50 *self) {
    if (!(FIELD(data_02097dc8, 0x12, u16) & 2)) {
        return;
    }
    if (self->unk_48 != 0) {
        FIELD(self->unk_48, 0xc, u32) |= 2;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    self->v0xc(0);
}

}
