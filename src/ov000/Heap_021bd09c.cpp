#include "ov000/HeapScope.h"

typedef struct {
    u8 pad_00[4];
    void *unk_04;
    u8 pad_08[4];
    void *unk_0c;
    u8 pad_10[4];
    void *unk_14;
} Data021bd09c;

extern "C" {

extern Data021bd09c data_ov000_021ccd74;

void func_ov000_021bd09c(void) {
    HEAP_DELETE_MODEL(data_ov000_021ccd74.unk_0c);
    HEAP_DELETE_MODEL(data_ov000_021ccd74.unk_14);
    HEAP_DELETE_MODEL(data_ov000_021ccd74.unk_04);
}

}
