#include "ov006/ov006.h"
#include "ov000/ObjLayouts.h"

// The ov006 item actors (vtables data_ov006_021ec54c, 5e4, 67c, 714, 7ac) are plain ActorEx
// objects (0xd0 bytes, built by Factory_New4000).

extern "C" {

ActorEx *ActorEx_DtorBase(ActorEx *self);

void Ov006ActorEx_UpdateMode1(void) {
}

void func_ov006_021eb5c8(void) {
}

void Ov006ActorEx_State23(void) {
}

void Ov006ActorEx_State22(void) {
}

void Ov006ActorEx_State21(void) {
}

void Ov006ActorEx_State20(void) {
}

void Ov006ActorEx_StateHurt(void) {
}

void Ov006ActorEx_State0e(void) {
}

void Ov006ActorEx_StateMove(void) {
}

ActorEx *Ov006ActVt_021ec7ac_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov006ActVt_021ec7ac_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov006ActVt_021ec54c_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov006ActVt_021ec54c_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov006ActVt_021ec5e4_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov006ActVt_021ec5e4_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov006ActVt_021ec67c_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov006ActVt_021ec67c_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov006ActVt_021ec714_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov006ActVt_021ec714_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

}
