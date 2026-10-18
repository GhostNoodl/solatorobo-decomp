#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 pad_00[0xc];
    VObj *unk_0c;
    VObj *unk_10;
    void *unk_14;
} Obj021bacf4;

extern "C" {

void func_ov000_021bacf4(Obj021bacf4 *self) {
    HEAP_DELETE_VOBJ(self->unk_0c);
    HEAP_DELETE_VOBJ(self->unk_10);
    HEAP_DELETE_MODEL(self->unk_14);
}

}
