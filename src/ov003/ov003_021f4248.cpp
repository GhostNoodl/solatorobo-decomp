#include "types.h"
#include "ov003/Prop.h"

extern "C" {

extern void Heap_Free(void *p);

Ov003PropResMdl *Ov003ActVt_021fa5f8_Dtor(Ov003PropResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0218c928(self);
    return self;
}

Ov003PropResMdl *Ov003ActVt_021fa5f8_DtorDelete(Ov003PropResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

Ov003PropResMdl *Ov003ActVt_021fa5a0_Dtor(Ov003PropResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0218c928(self);
    return self;
}

Ov003PropResMdl *Ov003ActVt_021fa5a0_DtorDelete(Ov003PropResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

Ov003PropRes *Ov003ActVt_021fa548_Dtor(Ov003PropRes *self) {
    func_ov000_0218ea20(&self->res);
    func_ov000_0218c928(self);
    return self;
}

Ov003PropRes *Ov003ActVt_021fa548_DtorDelete(Ov003PropRes *self) {
    func_ov000_0218ea20(&self->res);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
