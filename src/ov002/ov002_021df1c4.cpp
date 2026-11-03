#include "ov002/ov002.h"

extern "C" {

void Obj021eff30_Release(Obj021eff30 *self) {
    void *saved;
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

void *Ov002Vt_021efe9c_DtorDelete(Obj021efe9c *self) {
    *(VFunc **)self = data_ov002_021efe9c;
    Obj021efe9c_Release(self);
    func_ov002_021e0b08_inline(self);
    Heap_Free(self);
    return self;
}

}
