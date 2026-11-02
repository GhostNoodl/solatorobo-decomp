#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dddd0(void *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x08, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x0c, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x14, VObject *));
    HEAP_POP(saved);
}

}
