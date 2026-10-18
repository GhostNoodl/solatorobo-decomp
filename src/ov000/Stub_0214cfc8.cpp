#include "ov000/VObj.h"

extern "C" {

void func_ov000_0214cfc8(void *self) {
    s32 i;
    for (i = 0; i < 12; i++) {
        u32 *p = ((u32 **)((u8 *)self + 0x98))[i];
        if (p != NULL) {
            p[1] |= 4;
        }
    }
}

}
