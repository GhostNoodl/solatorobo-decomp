#include "ov000/LoCommon.h"

extern "C" {


void Lo021cb744_Release(VObj *self) {
    LO_FREE_M(self, 0x9c);
    LO_FREE_M(self, 0xa0);
    self->vfunc_14();
}

}
