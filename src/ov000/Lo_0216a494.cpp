#include "ov000/LoCommon.h"

extern "C" {


static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

void func_ov000_0216a494(VObj *self) {
    LO_FREE_M(self, 0x9c);
    LO_FREE_M(self, 0xa0);
    self->vfunc_14();
}

}
