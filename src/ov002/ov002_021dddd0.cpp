#include "ov002/ov002.h"

extern "C" {

void Obj021efef0_Release(Obj021efef0 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_08);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_0c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_14);
    HEAP_POP(saved);
}

}
