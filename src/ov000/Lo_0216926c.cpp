#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b);
u32 func_0204045c(void);

void func_ov000_0216926c(Lo021cb7ec *self) {
    self->unk_a0 = -1;
    LO_FREE_M(self, 0x9c);
    LBIT(self, 0xc).b3 = 0;
}

}
