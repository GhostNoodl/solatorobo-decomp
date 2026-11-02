#include "types.h"
#include "ov003/ActEx.h"

extern "C" {

extern void Heap_Free(void *p);

ActorEx *Ov003ActVt_021f98cc_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f98cc_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9834_Dtor(Ov003ActExResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9834_DtorDelete(Ov003ActExResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9704_Dtor(Ov003ActExResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9704_DtorDelete(Ov003ActExResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f979c_Dtor(Ov003ActExResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f979c_DtorDelete(Ov003ActExResMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
