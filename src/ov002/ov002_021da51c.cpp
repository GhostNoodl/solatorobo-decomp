#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efe6c_DtorDelete(void *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efe6c;
    func_ov002_021d9504(self);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (FIELD(self, 0x8c, void *) != NULL) {
        Heap_Free(FIELD(self, 0x8c, void *));
        FIELD(self, 0x8c, void *) = NULL;
    }
    HEAP_POP(saved);
    Heap_Free(self);
    return self;
}

}
