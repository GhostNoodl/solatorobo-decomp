#include "ov000/VObj.h"

extern "C" {

void func_ov000_021bd300(void *self) {
    s32 *p = (s32 *)((u8 *)self + 0x68);
    if (*p == 10) {
        *p = 4;
    }
}

}
