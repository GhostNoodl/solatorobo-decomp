#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220c93c(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u8, self, 0xf7) == 1) {
        self->unk_48->unk_38 = FLD(s32, self, 0xf8);
        self->rot[0] = 0;
    }
    func_ov003_021d5900(self);
}

}
