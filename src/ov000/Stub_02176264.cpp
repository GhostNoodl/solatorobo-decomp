#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cbee0[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021ccd34[];
void func_ov000_02176208(void);
void *func_0203dd9c(u32 size);

void func_ov000_02176264(void) {
    *(void **)(data_ov000_021ccd34 + 0x18) = (void *)func_ov000_02176208;
}

VObj *func_ov000_0217627c(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x15c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbee0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x4, 0xc8);
    return obj;
}

}
