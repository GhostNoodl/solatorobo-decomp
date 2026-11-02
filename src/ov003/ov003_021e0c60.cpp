#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"

extern "C" {

extern char data_ov003_021f8537[];
extern BOOL func_ov000_02190cb0(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern BOOL func_ov000_02191120(Model0218fe1c *p);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_0219433c(ActorEx *self);
extern void *func_0207011c(s32 id);
extern void func_ov000_0218f074(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_021946f8(ActorEx *self);
extern BOOL func_ov000_0218f110(ActorRes *p);
extern void Heap_Free(void *p);

void func_ov003_021e0c60(ActorEx *self) {
    ActorSub44 *part;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f8537, 0x1000, 0);
        part = self->unk_44;
        if (part != NULL) {
            part->unk_22_0 = 0;
            part->unk_22_1 = 0;
        }
        self->fsm->st++;
    case 1:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st = 0x7fff;
        break;
    }
}

ActorEx *Ov003ActVt_021f8480_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f8480_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8188_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f8188_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8220_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f8220_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f80f0_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f80f0_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f8058_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f8058_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f82b8_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f82b8_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f8a60_Init(Ov003ActExRes *self) {
    func_ov000_0219433c(self);
    func_ov000_0218f074(&self->res, func_0207011c(0x4801), 1, 0, 0, 0);
    self->res.unk_00 = 0;
    self->targetObj->unk_1e = 3;
}

} // extern "C"
