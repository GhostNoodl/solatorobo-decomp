#include "types.h"

typedef struct {
    u16 start;
    u16 pad;
    u32 pad2;
} Ov003Range;

typedef struct {
    u8 *ptr;
    u32 pad;
} Ov003RangePtr;

extern Ov003Range data_ov003_021f45e8[];
extern Ov003RangePtr data_ov003_021f45ec[];

void *func_ov003_021d1e30(u32 id) {
    void *ret = NULL;
    s32 i;
    for (i = 0; i < 11; i++) {
        if (data_ov003_021f45e8[i + 1].start > id) {
            if (data_ov003_021f45e8[i].start <= id) {
                ret = data_ov003_021f45ec[i].ptr + (id - data_ov003_021f45e8[i].start) * 16;
            }
            break;
        }
    }
    return ret;
}
