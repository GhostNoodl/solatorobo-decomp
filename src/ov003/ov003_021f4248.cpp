#include "types.h"
#include "ov003/Prop.h"

extern "C" {

extern void Heap_Free(void *p);

Ov003PropResMdl *Ov003ActVt_021fa5f8_Dtor(Ov003PropResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    Actor_DtorBase(self);
    return self;
}

Ov003PropResMdl *Ov003ActVt_021fa5f8_DtorDelete(Ov003PropResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003PropResMdl *Ov003ActVt_021fa5a0_Dtor(Ov003PropResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    Actor_DtorBase(self);
    return self;
}

Ov003PropResMdl *Ov003ActVt_021fa5a0_DtorDelete(Ov003PropResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003PropRes *Ov003ActVt_021fa548_Dtor(Ov003PropRes *self) {
    ResSet_ReleaseAll(&self->res);
    Actor_DtorBase(self);
    return self;
}

Ov003PropRes *Ov003ActVt_021fa548_DtorDelete(Ov003PropRes *self) {
    ResSet_ReleaseAll(&self->res);
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
