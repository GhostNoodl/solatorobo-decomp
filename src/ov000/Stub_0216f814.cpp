#include "ov000/VObj.h"

extern "C" {

void func_ov000_0216f23c(void *p, s32 a);

void func_ov000_0216f814(void *self) {
    func_ov000_0216f23c((u8 *)self + 8, 1);
}

void func_ov000_0216f828(void *self) {
    *(s32 *)((u8 *)self + 0x20) = 0x0;
    *(s32 *)((u8 *)self + 0x24) = 0x0;
    *(s32 *)((u8 *)self + 0x28) = 0x0;
    *(s32 *)((u8 *)self + 0x2c) = 0x0;
    *(s32 *)((u8 *)self + 0x30) = 0x0;
}

}
