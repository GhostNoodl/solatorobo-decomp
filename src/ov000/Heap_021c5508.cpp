#include "ov000/HeapScope.h"
#include "ov000/UiObj.h"

typedef struct {
    u8 pad_00[0xf4];
    UiLabel *unk_f4;
    UiLabel *unk_f8;
    UiLabel *unk_fc;
} Obj021c5508;

extern "C" {

void func_ov000_021c5508(Obj021c5508 *self) {
    HEAP_DELETE(UiLabel *, self->unk_f4, func_ov000_0215f548(p); Heap_Free(p));
    HEAP_DELETE(UiLabel *, self->unk_f8, func_ov000_0215f548(p); Heap_Free(p));
    HEAP_DELETE(UiLabel *, self->unk_fc, func_ov000_0215f548(p); Heap_Free(p));
}

}
