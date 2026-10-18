#include "ov000/VObj.h"

extern "C" {

void func_ov000_02153f30(VObj *self, s32 a) {
    self->vfunc_14(a);
    *(s32 *)((u8 *)self + 0x70) = a - 0x110;
    *(u32 *)((u8 *)self + 4) |= 0x200000;
}

void func_ov000_02153f60(VObj *self, s32 a) {
    self->vfunc_18(a);
    *(s32 *)((u8 *)self + 0x70) = a - 0x80;
    *(u32 *)((u8 *)self + 4) &= ~0x200000;
}

}
