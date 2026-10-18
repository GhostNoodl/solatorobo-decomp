#include "ov000/HeapScope.h"

typedef struct {
    u8 pad_00[0xf4];
    void *unk_f4;
    void *unk_f8;
    void *unk_fc;
} Obj021c5508;

extern "C" {

void func_ov000_0215f548(void *p);

void func_ov000_021c5508(Obj021c5508 *self) {
    HEAP_DELETE_FN(self->unk_f4, func_ov000_0215f548);
    HEAP_DELETE_FN(self->unk_f8, func_ov000_0215f548);
    HEAP_DELETE_FN(self->unk_fc, func_ov000_0215f548);
}

}
