#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_0221292c[];
void func_ov015_022120fc(Ov015Obj292c *self);
extern u8 data_ov015_022132e0[];
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
    SET_VT(self, data_ov015_0221292c);
    func_ov015_022120fc(self);
    Heap_Free(self);
    return self;
}

void *Ov015Obj290_DtorDelete(Ov015Obj290 *self) {
    SET_VT(self, data_ov015_022132e0);
    func_ov015_02211a18();
    Model0218fe1c_FreeAnims(&self->model);
    ResSet_ReleaseAll(&self->res);
    Heap_Free(self);
    return self;
}

}
