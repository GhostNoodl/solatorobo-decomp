#include "ov009/ov009.h"

extern "C" {

extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);

void func_ov009_0220b48c(Ov009Actor *self) {
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    FLD(u16, self, 0xea) |= 0x1000;
    if (self->unk_48->unk_54 & 0x400) {
        return;
    }
    func_ov003_021d6a3c(self, 1, 1, 0);
}

}
