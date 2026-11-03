#include "ov015/ov015.h"

extern "C" {

extern u8 Ov015Obj292c_vtbl[];
void Ov015Obj292c_DtorBase(Ov015Obj292c *self);
extern u8 Ov015Obj290_vtbl[];
void func_ov015_02211a18(void);
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);

void Ov015Obj30_Init(Ov015Obj30 *self) {
    Ov015Obj30_Clear(self);
}

void Ov015Obj30_Free(Ov015Obj30 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_14);
    HEAP_POP(saved);
    Ov015Obj30_Clear(self);
}

void *Ov015Obj292c_DtorDelete(Ov015Obj292c *self) {
    SET_VT(self, Ov015Obj292c_vtbl);
    Ov015Obj292c_DtorBase(self);
    Heap_Free(self);
    return self;
}

void *Ov015Obj290_DtorDelete(Ov015Obj290 *self) {
    SET_VT(self, Ov015Obj290_vtbl);
    func_ov015_02211a18();
    Model0218fe1c_FreeAnims(&self->model);
    ResSet_ReleaseAll(&self->res);
    Heap_Free(self);
    return self;
}

}
