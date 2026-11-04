#include "types.h"

extern "C" {

extern void *gDataRes;

u32 DataRes_GetCount(void *a, s32 b);
u16 Quest_GetAvailable(s32 kind, s32 idx);

BOOL Quest_HasAvailable(s32 kind) {
    u16 i;
    u32 count = DataRes_GetCount(gDataRes, 1);

    for (i = 0; i < count; i++) {
        if (Quest_GetAvailable(kind, i) != 0xffff) {
            return TRUE;
        }
    }
    return FALSE;
}

}
