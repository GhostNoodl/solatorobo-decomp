#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cbb60[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

void func_ov000_0217a86c(void *self) {
    VObj *obj = *(VObj **)((u8 *)self + 0x48);
    if (obj != NULL) {
        obj->vfunc_20();
    }
}

VObj *func_ov000_0217a88c(void) {
    VObj *obj = (VObj *)func_0203dd9c(0xc4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbb60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x8, 0xc8);
    return obj;
}

}
