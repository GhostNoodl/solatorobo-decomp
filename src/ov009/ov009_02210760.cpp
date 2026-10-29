#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

void func_ov009_02210760(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d5348(self);
    if (self->unk_40->unk_13 == 1) {
        self->unk_b6 = 0x3c;
    }
}

}
