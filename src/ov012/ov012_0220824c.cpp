#include "ov012/ov012.h"

extern "C" {
void func_ov012_0220824c(Ov012Actor *self) {
    if (self->unk_40->state == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x600, &self->pos, 0);
    }
    func_ov003_021d452c(self);
}
}
