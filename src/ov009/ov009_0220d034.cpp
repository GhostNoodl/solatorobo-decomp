#include "ov009/ov009.h"

extern "C" {

extern Model0218fe1c *func_ov000_0218fee4(Model0218fe1c *p);
extern void *func_ov000_0218ea20(void *p);

void Ov009ActVt_02217640_StateKnockBack(Ov009ActVt_02217640 *self) {
    self->vfunc_7c();
}

void Ov009ActVt_02217594_StateKnockBack(Ov009ActVt_02217594 *self) {
    self->vfunc_7c();
}

void Ov009ActVt_022178f0_StateKnockBack(Ov009ActVt_022178f0 *self) {
    self->vfunc_7c();
}

Ov009ActVt_022178f0 *Ov009ActVt_022178f0_Dtor(Ov009ActVt_022178f0 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022178f0 *Ov009ActVt_022178f0_DtorDelete(Ov009ActVt_022178f0 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217844 *Ov009ActVt_02217844_Dtor(Ov009ActVt_02217844 *self) {
    func_ov000_0218fee4(&self->modelObj);
    func_ov000_0218ea20(&self->anim);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217844 *Ov009ActVt_02217844_DtorDelete(Ov009ActVt_02217844 *self) {
    func_ov000_0218fee4(&self->modelObj);
    func_ov000_0218ea20(&self->anim);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009Multi *Ov009Multi_Dtor(Ov009Multi *self) {
    __cxa_vec_cleanup(self->models, 4, 0xe8, (void *)func_ov000_0218fee4);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009Multi *Ov009Multi_DtorDelete(Ov009Multi *self) {
    __cxa_vec_cleanup(self->models, 4, 0xe8, (void *)func_ov000_0218fee4);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_02217798_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_02217798_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217594 *Ov009ActVt_02217594_Dtor(Ov009ActVt_02217594 *self) {
    func_ov000_0218fee4(&self->modelObj);
    func_ov000_0218ea20(&self->anim);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217594 *Ov009ActVt_02217594_DtorDelete(Ov009ActVt_02217594 *self) {
    func_ov000_0218fee4(&self->modelObj);
    func_ov000_0218ea20(&self->anim);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217390 *Ov009ActVt_02217390_Dtor(Ov009ActVt_02217390 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217390 *Ov009ActVt_02217390_DtorDelete(Ov009ActVt_02217390 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022172e4 *Ov009ActVt_022172e4_Dtor(Ov009ActVt_022172e4 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022172e4 *Ov009ActVt_022172e4_DtorDelete(Ov009ActVt_022172e4 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022176ec *Ov009ActVt_022176ec_Dtor(Ov009ActVt_022176ec *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022176ec *Ov009ActVt_022176ec_DtorDelete(Ov009ActVt_022176ec *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217640 *Ov009ActVt_02217640_Dtor(Ov009ActVt_02217640 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217640 *Ov009ActVt_02217640_DtorDelete(Ov009ActVt_02217640 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_022174e8_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_022174e8_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

}
