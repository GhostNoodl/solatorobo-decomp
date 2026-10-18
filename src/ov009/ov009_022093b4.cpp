#include "ov009/ov009.h"

extern "C" {

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_022093b4(Ov009Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    self->unk_38->unk_c2_0 = 0;
    FLD(Ov009Bits16, self, 0x2ea).b0 = 0;
    self->unk_40->state++;
}

}
