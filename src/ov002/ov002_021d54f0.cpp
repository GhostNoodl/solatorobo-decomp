#include "ov002/ov002.h"

extern "C" {


Task021efc24 *Ov002TaskVt_021efc24_Dtor(Task021efc24 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efc24;
    HEAP_PUSH(saved);
    Task_deleteModel(self);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_4c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_50);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_54);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_58);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_5c);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

}
