#include "types.h"
#include "ov003/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov003/Shot.h"
#include "ov003/Unit.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov003_021f9fd0[];
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02190cb0(Model0218fe1c *p, const char *name, s16 a, u8 b);
extern void func_ov000_021915a0(Model0218fe1c *p);
extern void func_ov000_021911c8(Model0218fe1c *p, s16 a);
extern void Heap_Free(void *p);
extern void *func_ov000_0218ea20(void *p);
extern ActorEx *func_ov000_0219429c(ActorEx *self);

// 021f99e8 is Ov003Gimmick (ov003_021ec130.cpp), whose ActorRes sits at 0xdc.
ActorEx *Ov003ActVt_021f99e8_DtorDelete(ActorEx *self) {
    func_ov000_0218ea20((u8 *)self + 0xdc);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f99e8_Dtor(ActorEx *self) {
    func_ov000_0218ea20((u8 *)self + 0xdc);
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9bb0_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9bb0_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9c48_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9c48_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9b18_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9b18_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov003HomingShot *Ov003ActVt_021f9a80_Dtor(Ov003HomingShot *self) {
    func_ov003_021dae44(self);
    return self;
}

Ov003HomingShot *Ov003ActVt_021f9a80_DtorDelete(Ov003HomingShot *self) {
    func_ov003_021dae44(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f9f40_Init(ActorEx *self) {
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    self->unk_ce = 0;
    unit = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
}

void Ov003ActVt_021f9f40_Start(ActorEx *self) {
    func_ov000_02194758(self);
    if (self->model != NULL) {
        func_ov000_02190cb0(self->model, data_ov003_021f9fd0, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x4cd);
    }
    self->fsm->timer = 10;
}

}
