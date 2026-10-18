#include "ov000/VObj.h"

extern "C" {

void func_ov000_021c2090(void *self);

void func_ov000_021c2078(void *self) {
    *(void (**)(void *))((u8 *)self + 0x24) = func_ov000_021c2090;
    *((u8 *)self + 0x92) = 2;
}

}
