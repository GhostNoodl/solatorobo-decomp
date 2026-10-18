#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220abf8(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_48->unk_30 = 0;
        if (self->unk_1a == 1 && self->unk_90 != 0xffff) {
            Ov009Sub48 *s48 = self->unk_48;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
            s48 = self->unk_48;
            s48->unk_9a_2 = 0;
            s48->unk_9a_5 = 0;
        }
    }
    func_ov003_021d3a88(self);
}

}
