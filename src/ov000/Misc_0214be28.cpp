#include "types.h"

extern "C" {

extern void *gDataRes;

u32 DataRes_GetCount(void *a, s32 b);
u16 func_ov000_0214bcc4(s32 kind, s32 idx);

BOOL func_ov000_0214be28(s32 kind) {
    u16 i;
    u32 count = DataRes_GetCount(gDataRes, 1);

    for (i = 0; i < count; i++) {
        if (func_ov000_0214bcc4(kind, i) != 0xffff) {
            return TRUE;
        }
    }
    return FALSE;
}

}
