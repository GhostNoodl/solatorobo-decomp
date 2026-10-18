#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e0e78(void *self) {
    int i;
    *(VFunc **)self = data_ov002_021f000c;
    for (i = 0; i < 4; i++) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(((VObject **)((u8 *)self + 8))[i]);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 4, VObject *));
        HEAP_POP(saved);
    }
    return self;
}

void *func_ov002_021e0f34(void *self) {
    int i;
    *(VFunc **)self = data_ov002_021f000c;
    for (i = 0; i < 4; i++) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(((VObject **)((u8 *)self + 8))[i]);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 4, VObject *));
        HEAP_POP(saved);
    }
    func_0203de1c(self);
    return self;
}

}
