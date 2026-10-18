#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov002_021efc24[];

Task50 *func_ov002_021d54f0(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021efc24;
    HEAP_PUSH(saved);
    Task_deleteModel(self);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x4c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x50));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x54));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x58));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x5c));
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

}
