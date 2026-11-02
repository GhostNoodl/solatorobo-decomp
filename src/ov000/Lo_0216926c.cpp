#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

u32 Rand_GetGlobal(void);

void func_ov000_0216926c(Lo021cb7ec *self) {
    self->unk_a0 = -1;
    LO_FREE_M(self, 0x9c);
    self->unk_0c_3 = 0;
}

}
