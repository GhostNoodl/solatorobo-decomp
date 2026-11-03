#include "ov000/LoCommon.h"

extern "C" {


void Lo021cb798_Release(VObj *self) {
    LO_FREE_M(self, 0xa4);
    LO_FREE_M(self, 0xa0);
    self->vfunc_14();
}

}
