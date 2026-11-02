#include "ov002/ov002.h"

extern "C" {

void func_ov002_021df1c4(Obj021eff30 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x14, VObj *));
    HEAP_POP(saved);
}

void *Ov002Vt_021efe9c_DtorDelete(Obj021efe9c *self) {
    *(VFunc **)self = data_ov002_021efe9c;
    func_ov002_021d7ed8(self);
    func_ov002_021e0b08_inline(self);
    Heap_Free(self);
    return self;
}

}
