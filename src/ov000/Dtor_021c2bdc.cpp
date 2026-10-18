#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac0c[];
void func_0203de1c(void *ptr);

void func_ov000_021c2bb0(void *self) {
    *(s32 *)((u8 *)self + 0x18) = 0xf;
    *(s32 *)((u8 *)self + 0x30) = 0;
    *(s32 *)((u8 *)self + 0x34) = 0;
    *(s32 *)((u8 *)self + 0x38) = 0x64;
    *(s32 *)((u8 *)self + 0x3c) = 0x24;
    *(u8 *)((u8 *)self + 0x40) = 0;
}

VObj *func_ov000_021c2bdc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

}
