#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efe7c_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efe7c;
    func_ov002_021da430(self);
    return self;
}

void *Ov002Vt_021eff30_DtorDelete(Obj021eff30 *self) {
    *(VFunc **)self = data_ov002_021eff30;
    func_ov002_021df1c4(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021eff30_Dtor(Obj021eff30 *self) {
    *(VFunc **)self = data_ov002_021eff30;
    func_ov002_021df1c4(self);
    return self;
}

void *Ov002Vt_021efef0_DtorDelete(Obj021efef0 *self) {
    *(VFunc **)self = data_ov002_021efef0;
    func_ov002_021dddd0(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021efef0_Dtor(Obj021efef0 *self) {
    *(VFunc **)self = data_ov002_021efef0;
    func_ov002_021dddd0(self);
    return self;
}

void *Ov002Vt_021eff10_DtorDelete(Obj021eff10 *self) {
    *(VFunc **)self = data_ov002_021eff10;
    func_ov002_021dbdb8(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021eff10_Dtor(Obj021eff10 *self) {
    *(VFunc **)self = data_ov002_021eff10;
    func_ov002_021dbdb8(self);
    return self;
}

void *Ov002Vt_021eff50_DtorDelete(Obj021eff50 *self) {
    *(VFunc **)self = data_ov002_021eff50;
    func_ov002_021db64c(self);
    Heap_Free(self);
    return self;
}

BOOL func_ov002_021e07e4(Obj021eff50 *self) {
    return self->unk_14 == 0x32;
}

void func_ov002_021e07f8(void) {
}

void *Ov002Vt_021eff50_Dtor(Obj021eff50 *self) {
    *(VFunc **)self = data_ov002_021eff50;
    func_ov002_021db64c(self);
    return self;
}

void *Ov002Vt_021eff74_DtorDelete(Obj021eff74 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021eff74;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObj *));
    HEAP_POP(saved);
    Heap_Free(self);
    return self;
}

BOOL func_ov002_021e08c8(Obj021eff74 *self) {
    return self->unk_18 == 3;
}

void *Ov002Vt_021eff74_Dtor(Obj021eff74 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021eff74;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObj *));
    HEAP_POP(saved);
    return self;
}

void *Ov002Vt_021efe6c_Dtor(void *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efe6c;
    func_ov002_021d9504(self);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (FIELD(self, 0x8c, void *) != NULL) {
        Heap_Free(FIELD(self, 0x8c, void *));
        FIELD(self, 0x8c, void *) = NULL;
    }
    HEAP_POP(saved);
    return self;
}

void *Ov002Vt_021efed4_DtorDelete(Obj021efed4 *self) {
    *(VFunc **)self = data_ov002_021efed4;
    func_ov002_021d8e90(self);
    func_ov002_021e0b08_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021efed4_Dtor(Obj021efed4 *self) {
    *(VFunc **)self = data_ov002_021efed4;
    func_ov002_021d8e90(self);
    func_ov002_021e0b08_inline(self);
    return self;
}

void *Ov002Vt_021efe9c_Dtor(Obj021efe9c *self) {
    *(VFunc **)self = data_ov002_021efe9c;
    func_ov002_021d7ed8(self);
    func_ov002_021e0b08_inline(self);
    return self;
}

void *Ov002Vt_021efeb8_Dtor(Obj021efeb8 *self) {
    void *prev;
    void *next;
    *(VFunc **)self = data_ov002_021efeb8;
    prev = self->unk_70;
    if (prev != NULL) {
        FIELD(prev, 0x74, void *) = self->unk_74;
    }
    next = self->unk_74;
    if (next != NULL) {
        FIELD(next, 0x70, void *) = self->unk_70;
    }
    return self;
}

void *Ov002Vt_021efe4c_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efe4c;
    func_ov002_021d6ec4(self);
    return self;
}

void *Ov002Vt_021f001c_Dtor(void *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x4, VObj *));
    HEAP_POP(saved);
    return self;
}

void *Ov002Vt_021f001c_DtorDelete(void *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x4, VObj *));
    HEAP_POP(saved);
    Heap_Free(self);
    return self;
}

}
