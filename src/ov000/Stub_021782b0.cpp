#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021ccd34[];

void func_ov000_021782b0(void) {
}

BOOL func_ov000_021782b4(void) {
    VObj *obj = (VObj *)(*(u8 **)(data_ov000_021ccd34 + 0x10) + 8);
    return obj->vfunc_2c() ? TRUE : FALSE;
}

}
