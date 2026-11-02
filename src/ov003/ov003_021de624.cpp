#include "types.h"
#include "ov003/ActEx.h"

extern "C" {

extern void Heap_Free(void *p);

ActorEx *Ov003ActVt_021f7fac_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f7fac_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f7e7c_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f7e7c_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f7f14_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f7f14_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

} // extern "C"
