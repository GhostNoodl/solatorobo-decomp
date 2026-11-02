#include "ov002/ov002.h"

extern "C" {

void Obj021efef0_Release(Obj021efef0 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x08, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x0c, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x14, VObj *));
    HEAP_POP(saved);
}

}
