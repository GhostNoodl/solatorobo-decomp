#include "types.h"
#include "ov003/ActEx.h"

extern "C" {

extern void Heap_Free(void *p);

ActorEx *Ov003ActVt_021f98cc_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f98cc_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9834_Dtor(Ov003ActExResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9834_DtorDelete(Ov003ActExResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9704_Dtor(Ov003ActExResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f9704_DtorDelete(Ov003ActExResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f979c_Dtor(Ov003ActExResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    return self;
}

Ov003ActExResMdl *Ov003ActVt_021f979c_DtorDelete(Ov003ActExResMdl *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
