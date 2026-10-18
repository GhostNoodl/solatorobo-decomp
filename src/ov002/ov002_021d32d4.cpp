#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d32d4(Task50 *self) {
    self->unk_20 = 0x1000;
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    func_ov002_021e4904((u8 *)self + 0x94);
    func_ov002_021e4b80((u8 *)self + 0xac);
    FIELD(self, 0xbc, s32) = 0;
    FIELD(self, 0xc0, s32) = 0;
    FIELD(self, 0xc4, s32) = 0;
    FIELD(self, 0xc8, s32) = 0;
    FIELD(self, 0xcc, s32) = -1;
}

}
