#include "ov002/ov002.h"

extern "C" {

void func_ov002_021da2fc(void) {
    void *p;
    if (data_ov002_021f0f90[1] != NULL) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*(VObject **)&data_ov002_021f0f90[1]);
        HEAP_POP(saved);
    }
    p = func_0203dd9c(0x14);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021efe7c;
        FIELD(p, 4, s32) = 0;
        FIELD(p, 8, s32) = 0;
        FIELD(p, 0xc, s32) = 0;
        FIELD(p, 0x10, u8) = 0;
    }
    data_ov002_021f0f90[1] = p;
}

void func_ov002_021da39c(void) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*(VObject **)&data_ov002_021f0f90[1]);
    HEAP_POP(saved);
}

void *func_ov002_021da3f8(void *self) {
    *(VFunc **)self = data_ov002_021efe7c;
    func_ov002_021da430(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021da420(void) {
    return data_ov002_021f0f90[1];
}

}
