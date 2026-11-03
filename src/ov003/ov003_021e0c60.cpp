#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"

extern "C" {

extern char data_ov003_021f8537[];
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *p);
extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void *Tbl_GetResFile(s32 id);
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL ResSet_UpdateLoad(ActorRes *p);
extern void Heap_Free(void *p);

void Ov003ActVt_021f82b8_State21(ActorEx *self) {
    ActorSub44 *part;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f8537, 0x1000, 0);
        part = self->unk_44;
        if (part != NULL) {
            part->unk_22_0 = 0;
            part->unk_22_1 = 0;
        }
        self->fsm->st++;
    case 1:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st = 0x7fff;
        break;
    }
}

ActorEx *Ov003ActVt_021f8480_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8480_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8188_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8188_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8220_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8220_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f80f0_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f80f0_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8058_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f8058_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f82b8_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f82b8_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f8a60_Init(Ov003ActExRes *self) {
    ActorEx_Init(self);
    ResSet_SetFile(&self->res, Tbl_GetResFile(0x4801), 1, 0, 0, 0);
    self->res.unk_00 = 0;
    self->targetObj->unk_1e = 3;
}

} // extern "C"
