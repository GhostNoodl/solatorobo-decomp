#include "types.h"

extern "C" {

extern void *data_02fe152c;

u32 func_0205975c(void *a, s32 b);
u16 func_ov000_0214bcc4(void *self, u16 index);

BOOL func_ov000_0214be28(void *self) {
    u16 i;
    u32 count = func_0205975c(data_02fe152c, 1);

    for (i = 0; i < count; i++) {
        if (func_ov000_0214bcc4(self, i) != 0xffff) {
            return TRUE;
        }
    }
    return FALSE;
}

}
