#include "types.h"
#include "ov003/ActEx.h"

extern "C" {

extern void __cxa_vec_cleanup(void *arr, int count, int size, void *dtor);
Ov003HitMesh *Ov003HitMesh_Dtor(Ov003HitMesh *self);

extern void Heap_Free(void *p);
extern void HitMesh_Detach(Ov003HitMesh *p);

void Ov003ActVt_021f8f20_StateThrown(ActorEx *self) {
    self->vfunc_60();
}

void Ov003ActVt_021f8f20_StateFly(ActorEx *self) {
    self->vfunc_60();
}

Ov003ActExRes *Ov003ActVt_021f8a60_Dtor(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f8a60_DtorDelete(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9050_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9050_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f8638_Dtor(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f8638_DtorDelete(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8df0_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8df0_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f8c28_Dtor(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f8c28_DtorDelete(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f89c8_Dtor(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExRes *Ov003ActVt_021f89c8_DtorDelete(Ov003ActExRes *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8800_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8800_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8fb8_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8fb8_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8cc0_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8cc0_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8b90_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8b90_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExMesh *Ov003ActVt_021f8af8_Dtor(Ov003ActExMesh *self) {
    __cxa_vec_cleanup(self->meshC, 3, sizeof(Ov003HitMesh), (void *)Ov003HitMesh_Dtor);
    __cxa_vec_cleanup(self->meshB, 4, sizeof(Ov003HitMesh), (void *)Ov003HitMesh_Dtor);
    __cxa_vec_cleanup(self->meshA, 4, sizeof(Ov003HitMesh), (void *)Ov003HitMesh_Dtor);
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res2);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003HitMesh *Ov003HitMesh_Dtor(Ov003HitMesh *self) {
    HitMesh_Detach(self);
    return self;
}

Ov003ActExMesh *Ov003ActVt_021f8af8_DtorDelete(Ov003ActExMesh *self) {
    __cxa_vec_cleanup(self->meshC, 3, sizeof(Ov003HitMesh), (void *)Ov003HitMesh_Dtor);
    __cxa_vec_cleanup(self->meshB, 4, sizeof(Ov003HitMesh), (void *)Ov003HitMesh_Dtor);
    __cxa_vec_cleanup(self->meshA, 4, sizeof(Ov003HitMesh), (void *)Ov003HitMesh_Dtor);
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->res2);
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8930_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8930_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8898_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8898_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f86d0_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f86d0_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8f20_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8f20_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8e88_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8e88_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8d58_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8d58_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
