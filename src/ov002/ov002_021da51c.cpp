#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021da51c(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021efe6c;
    func_ov002_021d9504(self);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (FIELD(self, 0x8c, void *) != NULL) {
        func_0203de1c(FIELD(self, 0x8c, void *));
        FIELD(self, 0x8c, void *) = NULL;
    }
    HEAP_POP(saved);
    func_0203de1c(self);
    return self;
}

}
