#include "types.h"
#include "ov003/Actor.h"

extern "C" {

typedef struct {
    u16 start;
    u16 pad;
    u32 pad2;
} Ov003Range;

typedef struct {
    Ov003Entry *ptr;
    u32 pad;
} Ov003RangePtr;

extern Ov003Range data_ov003_021f45e8[];
extern Ov003RangePtr data_ov003_021f45ec[];

Ov003Entry *Ov003_LookupEntry(u32 id) {
    Ov003Entry *ret = NULL;
    s32 i;
    for (i = 0; i < 11; i++) {
        if (data_ov003_021f45e8[i + 1].start > id) {
            if (data_ov003_021f45e8[i].start <= id) {
                ret = data_ov003_021f45ec[i].ptr + (id - data_ov003_021f45e8[i].start);
            }
            break;
        }
    }
    return ret;
}

}
