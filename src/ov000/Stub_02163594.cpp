#include "ov000/VObj.h"

extern "C" {

void func_ov000_02163594(void *self) {
    VObj *obj = *(VObj **)((u8 *)self + 0x20);
    if (obj != NULL) {
        obj->vfunc_90();
    }
}

}
