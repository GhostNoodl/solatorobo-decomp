#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e06c4(void *self) {
    *(VFunc **)self = data_ov002_021efe7c;
    func_ov002_021da430(self);
    return self;
}

void *func_ov002_021e06e4(void *self) {
    *(VFunc **)self = data_ov002_021eff30;
    func_ov002_021df1c4(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021e070c(void *self) {
    *(VFunc **)self = data_ov002_021eff30;
    func_ov002_021df1c4(self);
    return self;
}

void *func_ov002_021e072c(void *self) {
    *(VFunc **)self = data_ov002_021efef0;
    func_ov002_021dddd0(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021e0754(void *self) {
    *(VFunc **)self = data_ov002_021efef0;
    func_ov002_021dddd0(self);
    return self;
}

void *func_ov002_021e0774(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    func_ov002_021dbdb8(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021e079c(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    func_ov002_021dbdb8(self);
    return self;
}

void *func_ov002_021e07bc(void *self) {
    *(VFunc **)self = data_ov002_021eff50;
    func_ov002_021db64c(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov002_021e07e4(void *self) {
    return FIELD(self, 0x14, s32) == 0x32;
}

void func_ov002_021e07f8(void) {
}

void *func_ov002_021e07fc(void *self) {
    *(VFunc **)self = data_ov002_021eff50;
    func_ov002_021db64c(self);
    return self;
}

void *func_ov002_021e081c(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021eff74;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObject *));
    HEAP_POP(saved);
    func_0203de1c(self);
    return self;
}

BOOL func_ov002_021e08c8(void *self) {
    return FIELD(self, 0x18, s32) == 3;
}

void *func_ov002_021e08dc(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021eff74;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObject *));
    HEAP_POP(saved);
    return self;
}

void *func_ov002_021e0980(void *self) {
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
    return self;
}

void *func_ov002_021e0a1c(void *self) {
    *(VFunc **)self = data_ov002_021efed4;
    func_ov002_021d8e90(self);
    func_ov002_021e0b08_inline(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021e0a70(void *self) {
    *(VFunc **)self = data_ov002_021efed4;
    func_ov002_021d8e90(self);
    func_ov002_021e0b08_inline(self);
    return self;
}

void *func_ov002_021e0abc(void *self) {
    *(VFunc **)self = data_ov002_021efe9c;
    func_ov002_021d7ed8(self);
    func_ov002_021e0b08_inline(self);
    return self;
}

void *func_ov002_021e0b08(void *self) {
    void *prev;
    void *next;
    *(VFunc **)self = data_ov002_021efeb8;
    prev = FIELD(self, 0x70, void *);
    if (prev != NULL) {
        FIELD(prev, 0x74, void *) = FIELD(self, 0x74, void *);
    }
    next = FIELD(self, 0x74, void *);
    if (next != NULL) {
        FIELD(next, 0x70, void *) = FIELD(self, 0x70, void *);
    }
    return self;
}

void *func_ov002_021e0b38(void *self) {
    *(VFunc **)self = data_ov002_021efe4c;
    func_ov002_021d6ec4(self);
    return self;
}

void *func_ov002_021e0b58(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x4, VObject *));
    HEAP_POP(saved);
    return self;
}

void *func_ov002_021e0bbc(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x4, VObject *));
    HEAP_POP(saved);
    func_0203de1c(self);
    return self;
}

}
