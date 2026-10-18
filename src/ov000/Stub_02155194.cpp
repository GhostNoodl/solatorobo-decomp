#include "ov000/VObj.h"

extern "C" {

void func_ov000_02155194(VObj *self, void *p) {
    if (p != NULL) {
        self->vfunc_a4(*(s16 *)((u8 *)p + 4));
    } else {
        self->vfunc_a4(0);
    }
}

}
