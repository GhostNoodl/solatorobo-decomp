#include "ov000/VObj.h"

extern "C" {

void func_02016e28(void *dst, s32 val, u32 size);

void func_ov000_0215e4fc(void *self) {
    func_02016e28((u8 *)self + 0xd8, 0, 0x100);
    *(u32 *)((u8 *)self + 0x1dc) = 0;
    *(u16 *)((u8 *)self + 0x1d8) = 0xffff;
    *(u16 *)((u8 *)self + 0x1e0) = 0;
}

s32 func_ov000_0215e534(VObj *self) {
    return self->vfunc_28();
}

}
