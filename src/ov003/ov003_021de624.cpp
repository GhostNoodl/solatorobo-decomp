#include "types.h"
#include "ov003/ActEx.h"

extern "C" {

extern void Heap_Free(void *p);

ActorEx *Ov003ActVt_021f7fac_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f7fac_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f7e7c_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f7e7c_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f7f14_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f7f14_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
