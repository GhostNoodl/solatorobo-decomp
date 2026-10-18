#include "ov000/VObj.h"

extern "C" {

void func_ov000_021645a4(void *self) {
    u8 *p = *(u8 **)((u8 *)self + 0x30);
    if (p != NULL) {
        *p = 1;
    }
}

}
