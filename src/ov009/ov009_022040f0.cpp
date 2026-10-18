#include "ov009/ov009.h"

extern "C" {

extern void *data_0214a420;
extern void func_02065804(void *mgr, void *p);

void func_ov009_022040f0(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_64 >>= 1;
        func_02065804(data_0214a420, FLD(void *, self, 0xf0));
        FLD(void *, self, 0xf0) = NULL;
    }
    func_ov003_021d6054(self);
}

}
