#include "ov002/ov002.h"

extern "C" {

Obj021efe7c *Ov002Vt_021efe7c_Dtor(Obj021efe7c *self) {
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

void *Ov002Vt_021efe6c_Dtor(Obj021efe6c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efe6c;
    func_ov002_021d9504(self);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (((void *)self->cam) != NULL) {
        Heap_Free(((void *)self->cam));
        self->cam = NULL;
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
    Obj021efeb8 *next;
    Obj021efeb8 *prev;
    *(VFunc **)self = data_ov002_021efeb8;
    next = self->next;
    if (next != NULL) {
        next->prev = self->prev;
    }
    prev = self->prev;
    if (prev != NULL) {
        prev->next = self->next;
    }
    return self;
}

void *Ov002Vt_021efe4c_Dtor(Obj021efe4c *self) {
    *(VFunc **)self = data_ov002_021efe4c;
    func_ov002_021d6ec4(self);
    return self;
}

Ov002Caption *Ov002Vt_021f001c_Dtor(Ov002Caption *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->anim);
    HEAP_POP(saved);
    return self;
}

Ov002Caption *Ov002Vt_021f001c_DtorDelete(Ov002Caption *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f001c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->anim);
    HEAP_POP(saved);
    Heap_Free(self);
    return self;
}

}
