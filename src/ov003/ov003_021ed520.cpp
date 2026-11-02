#include "types.h"
#include "ov003/ActorApi.h"
#include "ov003/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActEx.h"
#include "ov003/Shot.h"
#include "ov003/Unit.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov003_021f9fd0[];
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s16 a, u8 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *p, s16 a);
extern void Heap_Free(void *p);

Ov003Gimmick *Ov003ActVt_021f99e8_DtorDelete(Ov003Gimmick *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Gimmick *Ov003ActVt_021f99e8_Dtor(Ov003Gimmick *self) {
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9bb0_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9bb0_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9c48_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9c48_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9b18_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9b18_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003HomingShot *Ov003ActVt_021f9a80_Dtor(Ov003HomingShot *self) {
    Ov003ActorEx_Ctor(self);
    return self;
}

Ov003HomingShot *Ov003ActVt_021f9a80_DtorDelete(Ov003HomingShot *self) {
    Ov003ActorEx_Ctor(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f9f40_Init(ActorEx *self) {
    Ov003Unit *unit;
    ActorEx_InitActor(self);
    self->unk_ce = 0;
    unit = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
}

void Ov003ActVt_021f9f40_Start(ActorEx *self) {
    ActorEx_Start(self);
    if (self->model != NULL) {
        Model0218fe1c_SetAnim(self->model, data_ov003_021f9fd0, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x4cd);
    }
    self->fsm->timer = 10;
}

}
