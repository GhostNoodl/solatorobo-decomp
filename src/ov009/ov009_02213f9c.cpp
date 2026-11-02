#include "ov009/ov009.h"

extern "C" {

void Ov009ActVt_02217cb0_StateKnockBack(Ov009ActVt_02217cb0 *self) {
    Ov003Actor_StateKnockBack(self);
    self->unk_94_1 = 0;
}

void Ov009ActSpin_StateKnockBack(Ov003Actor *self) {
    self->vfunc_7c();
}

void Ov009ActVt_02217aac_StateKnockBack(Ov009ActVt_02217aac *self) {
    self->vfunc_7c();
}

void Ov009ActVt_02217c04_StateKnockBack(Ov009ActVt_02217c04 *self) {
    self->vfunc_7c();
}

void Ov009ActPair110_StateKnockBack(Ov009ActVt_02217b58 *self) {
    self->vfunc_7c();
}

void Ov009ActVt_02217eb4_StateKnockBack(Ov009ActVt_02217eb4 *self) {
    self->vfunc_7c();
}

void Ov009ActVt_02217f60_StateKnockBack(Ov009ActVt_02217f60 *self) {
    self->vfunc_7c();
}

Ov009ActVt_02217f60 *Ov009ActVt_02217f60_Dtor(Ov009ActVt_02217f60 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217f60 *Ov009ActVt_02217f60_DtorDelete(Ov009ActVt_02217f60 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217eb4 *Ov009ActVt_02217eb4_Dtor(Ov009ActVt_02217eb4 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217eb4 *Ov009ActVt_02217eb4_DtorDelete(Ov009ActVt_02217eb4 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217b58 *Ov009ActPair110_Dtor(Ov009ActVt_02217b58 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217b58 *Ov009ActPair110_DtorDelete(Ov009ActVt_02217b58 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217e08 *Ov009ActVt_02217e08_Dtor(Ov009ActVt_02217e08 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217e08 *Ov009ActVt_02217e08_DtorDelete(Ov009ActVt_02217e08 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217c04 *Ov009ActVt_02217c04_Dtor(Ov009ActVt_02217c04 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217c04 *Ov009ActVt_02217c04_DtorDelete(Ov009ActVt_02217c04 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217aac *Ov009ActVt_02217aac_Dtor(Ov009ActVt_02217aac *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217aac *Ov009ActVt_02217aac_DtorDelete(Ov009ActVt_02217aac *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217a00 *Ov009ActSpin_Dtor(Ov009ActVt_02217a00 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217a00 *Ov009ActSpin_DtorDelete(Ov009ActVt_02217a00 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217d5c *Ov009ActVt_02217d5c_Dtor(Ov009ActVt_02217d5c *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217d5c *Ov009ActVt_02217d5c_DtorDelete(Ov009ActVt_02217d5c *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217cb0 *Ov009ActVt_02217cb0_Dtor(Ov009ActVt_02217cb0 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217cb0 *Ov009ActVt_02217cb0_DtorDelete(Ov009ActVt_02217cb0 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

}
