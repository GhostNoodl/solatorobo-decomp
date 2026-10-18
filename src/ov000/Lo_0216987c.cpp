#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02172f7c(void *self, void *arg);

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

void func_ov000_0216987c(VObj *self) {
    LO_FREE_M(self, 0xa4);
    LO_FREE_M(self, 0xa0);
    self->vfunc_14();
}

}
