#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cbfe0[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_02175e04(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x48);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbfe0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x3, 0x3e8);
    return obj;
}

}
