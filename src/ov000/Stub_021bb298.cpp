#include "ov000/VObj.h"

extern "C" {

void func_ov000_021bb248(void *self);

void func_ov000_021bb298(void *self) {
    *(void (**)(void *))((u8 *)self + 0x1c) = func_ov000_021bb248;
    *((u8 *)self + 0x90) = 2;
}

}
