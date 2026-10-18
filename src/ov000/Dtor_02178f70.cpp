#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cbde0[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_02178f70(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x54);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbde0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x5, 0xc8);
    return obj;
}

}
