#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220ae4c(Ov009Actor *self) {
    Ov009Sub44 *s44;
    func_ov003_021d112c(self);
    FLD(u16, self, 0xfc) = self->rot[1];
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    self->unk_b8 = self->pos;
    FLD(u16, self, 0xea) |= 0x1000;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    FLD(u16, self, 0xfe) = 0;
}

}
