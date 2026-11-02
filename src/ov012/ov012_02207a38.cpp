#include "ov012/ov012.h"

extern "C" {
void Ov012ActEx_02207018_StateDie(Ov012ActEx_02207018 *self) {
    if (self->unk_d0 & 0x200000) {
        if (!Ov003FxList_Has(self->fxList, 0xfe) && !Ov003FxList_Has(self->fxList, 0xff)) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        Ov003FxList_Prune(self->fxList);
        return;
    }
    if (self->fsm->st == 0) {
        self->radius = 0x3000;
        Ov003FxList_Kill(self->fxList, 0xfa);
        Effect_SpawnId(0x69, &self->pos)->SetScaleAll(0x2000);
    }
    ActorEx_StateDie(self);
}
}

extern "C" {
Ov012ActExVt_0220b150 *Ov012ActExVt_0220b150_DtorDelete(Ov012ActExVt_0220b150 *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
Ov012ActExVt_0220b150 *Ov012ActExVt_0220b150_Dtor(Ov012ActExVt_0220b150 *self) {
    ActorEx_DtorBase(self);
    return self;
}
}

extern "C" {
Ov012ActExVt_0220b1e8 *Ov012ActExVt_0220b1e8_DtorDelete(Ov012ActExVt_0220b1e8 *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_d8);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
Ov012ActExVt_0220b1e8 *Ov012ActExVt_0220b1e8_Dtor(Ov012ActExVt_0220b1e8 *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_d8);
    ActorEx_DtorBase(self);
    return self;
}
}
