#include "ov000/VObj.h"

extern "C" {

BOOL func_ov000_0214c6a0(void *self) {
    return (*(u32 *)((u8 *)self + 0xc) & 0x30000) != 0;
}

}
