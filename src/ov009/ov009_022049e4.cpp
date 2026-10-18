#include "ov009/ov009.h"

extern "C" {

void func_ov009_022049e4(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u8, self, 0xf3) == 1) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

}
