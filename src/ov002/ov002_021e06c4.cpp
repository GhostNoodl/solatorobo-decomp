#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efe7c_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efe7c;
    func_ov002_021da430(self);
    return self;
}

void *Ov002Vt_021eff30_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021eff30;
    func_ov002_021df1c4(self);
    func_0203de1c(self);
    return self;
}

void *Ov002Vt_021eff30_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021eff30;
    func_ov002_021df1c4(self);
    return self;
}

void *Ov002Vt_021efef0_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021efef0;
    func_ov002_021dddd0(self);
    func_0203de1c(self);
    return self;
}

void *Ov002Vt_021efef0_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efef0;
    func_ov002_021dddd0(self);
    return self;
}

void *Ov002Vt_021eff10_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    func_ov002_021dbdb8(self);
    func_0203de1c(self);
    return self;
}

void *Ov002Vt_021eff10_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    func_ov002_021dbdb8(self);
    return self;
}

void *Ov002Vt_021eff50_DtorDelete(void *self) {
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

void *Ov002Vt_021eff50_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021eff50;
    func_ov002_021db64c(self);
    return self;
}

void *Ov002Vt_021eff74_DtorDelete(void *self) {
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

void *Ov002Vt_021eff74_Dtor(void *self) {
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

void *Ov002Vt_021efe6c_Dtor(void *self) {
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

void *Ov002Vt_021efed4_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021efed4;
    func_ov002_021d8e90(self);
    func_ov002_021e0b08_inline(self);
    func_0203de1c(self);
    return self;
}

void *Ov002Vt_021efed4_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efed4;
    func_ov002_021d8e90(self);
    func_ov002_021e0b08_inline(self);
    return self;
}

void *Ov002Vt_021efe9c_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efe9c;
    func_ov002_021d7ed8(self);
    func_ov002_021e0b08_inline(self);
    return self;
}

void *Ov002Vt_021efeb8_Dtor(void *self) {
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

void *Ov002Vt_021efe4c_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efe4c;
    func_ov002_021d6ec4(self);
    return self;
}

void *Ov002Vt_021f001c_Dtor(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x4, VObject *));
    HEAP_POP(saved);
    return self;
}

void *Ov002Vt_021f001c_DtorDelete(void *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x4, VObject *));
    HEAP_POP(saved);
    func_0203de1c(self);
    return self;
}

}
