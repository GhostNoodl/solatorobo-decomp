#include "ov000/VObj.h"

extern "C" {

void func_ov000_021c1478(void *self);

void func_ov000_021c14dc(void *self) {
    *(void (**)(void *))((u8 *)self + 0x1c) = func_ov000_021c1478;
    *((u8 *)self + 0x90) = 2;
}

}
