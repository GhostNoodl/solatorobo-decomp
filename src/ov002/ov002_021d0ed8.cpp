#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d0ed8(Task50 *self) {
    if (!(FIELD(data_02097dc8, 0x12, u16) & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    data_ov002_021f0f84[1] = FIELD(self->unk_3c, 0xa8, s32);
    self->v0xc(0);
}

}
