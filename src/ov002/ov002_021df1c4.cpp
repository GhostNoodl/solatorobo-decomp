#include "ov002/ov002.h"

extern "C" {

void func_ov002_021df1c4(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x14, VObject *));
    HEAP_POP(saved);
}

void *Ov002Vt_021efe9c_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021efe9c;
    func_ov002_021d7ed8(self);
    func_ov002_021e0b08_inline(self);
    Heap_Free(self);
    return self;
}

}
