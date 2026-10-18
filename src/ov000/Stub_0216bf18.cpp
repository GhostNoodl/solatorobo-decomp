#include "ov000/VObj.h"

extern "C" {

void func_ov000_0216bec8(void);

void func_ov000_0216bf18(void *self) {
    *(void **)((u8 *)self + 0x1c) = (void *)func_ov000_0216bec8;
    *(u8 *)((u8 *)self + 0x90) = 2;
}

}
