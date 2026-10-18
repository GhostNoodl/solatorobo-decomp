#include "ov000/VObj.h"

extern "C" {

s32 func_ov000_021708d8(void *self) {
    return *(void **)((u8 *)self + 0x4c) != NULL ? 0x1 : 0x0;
}

}
