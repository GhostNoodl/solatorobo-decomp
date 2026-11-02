#include "types.h"
#include "ov003/ActorApi.h"
#include "ov003/ActEx.h"

extern "C" {

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
} Ov003Player;

extern Ov003Player *ActorMgr_FindPlayer(void);
extern void *Heap_Alloc(u32 size);
extern ActorSub4c *Target_Init(ActorSub4c *p);
extern void *func_0203db40(PauseNode *p);
extern void Model0218fe1c_UpdateAnim(Model0218fe1c *a, void *b);
extern void Heap_Free(void *p);

ActorEx *Ov003ActVt_021f92dc_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f92dc_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f940c_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f940c_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f94a4_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f94a4_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9114_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9114_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f91ac_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f91ac_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExMdl *Ov003ActVt_021f953c_DtorDelete(Ov003ActExMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003ActExMdl *Ov003ActVt_021f953c_Dtor(Ov003ActExMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9244_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9244_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f95d4_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f95d4_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f966c_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f966c_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9374_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

ActorEx *Ov003ActVt_021f9374_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f98cc_Start(ActorEx *self) {
    Ov003Player *player;
    ActorEx_Start(self);
    self->unk_ce = 0;
    player = ActorMgr_FindPlayer();
    if (player == NULL) {
        return;
    }
    if (!player->unk_16_2) {
        return;
    }
    if (self->targetObj == NULL) {
        ActorSub4c *part = (ActorSub4c *)Heap_Alloc(sizeof(ActorSub4c));
        if (part != NULL) {
            part = Target_Init(part);
        }
        self->targetObj = part;
    }
    self->targetObj->unk_03 = 10;
    self->targetObj->type = 7;
    self->targetObj->unk_01 = 4;
    self->targetObj->unk_02 = 0;
}

void Ov003ActVt_021f98cc_Animate(ActorEx *self) {
    if (self->unk_cc_7 && self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
    }
}

} // extern "C"
