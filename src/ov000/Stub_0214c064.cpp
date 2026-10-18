#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021ccd24[];
s32 func_0204c0e8(void *a, void *b);

s32 func_ov000_0214c064(void *arg) {
    return func_0204c0e8(*(void **)((u8 *)((void **)data_ov000_021ccd24)[2] + 0xbc), arg);
}

}
