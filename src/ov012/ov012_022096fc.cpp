#include "ov012/ov012.h"

extern "C" {
void func_ov012_022096fc(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
    }
    func_ov003_021d452c(self);
}
}
