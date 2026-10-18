#include "ov000/VObj.h"

extern "C" {

void func_ov000_02168ea4(void *self) {
    *(s32 *)((u8 *)self + 0xa8) = 0x0;
    *(s32 *)((u8 *)self + 0x9c) = 0x0;
    *(s32 *)((u8 *)self + 0xa0) = 0x0;
    *(s32 *)((u8 *)self + 0xa4) = 0x0;
}

s32 func_ov000_02168ebc(VObj *self) {
    return self->vfunc_14();
}

void func_ov000_02168ed0(void *self) {
    *(u32 *)((u8 *)self + 0xc) &= ~0x8;
}

}
