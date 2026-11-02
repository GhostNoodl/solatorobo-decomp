#include "types.h"

typedef void (*VFunc)(void *);


extern void Heap_Free(void *p);
extern void *func_ov000_0219429c(void *p);

void *Ov003ActVt_021f7fac_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f7fac_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f7e7c_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f7e7c_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f7f14_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f7f14_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}
