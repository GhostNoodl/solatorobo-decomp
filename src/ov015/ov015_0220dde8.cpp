#include "ov015/ov015.h"

extern "C" {

extern u8 Ov015Vt_02212f64_vtbl[];
extern u8 Ov015StageMdl_vtbl[];
void *ResSet_Init(void *a);
void *Model0218fe1c_Init(void *a);
void *Model0218fe1c_FreeAnims(void *a);
void *ResSet_ReleaseAll(void *a);

void *Ov015StageMdl_Ctor(Ov015StageMdl *self) {
    s32 i;
    SET_VT(self, Ov015Vt_02212f64_vtbl);
    Ov002Obj_Init(self);
    SET_VT(self, Ov015StageMdl_vtbl);
    ResSet_Init(&self->res0);
    Model0218fe1c_Init(&self->mdl0);
    ResSet_Init(&self->res1);
    Model0218fe1c_Init(&self->mdl1);
    self->unk_490 = 0x1000;
    self->slot = -1;
    self->unk_498 = 0xffff;
    self->unk_4d0.x = 0;
    self->unk_4d0.y = 0;
    self->unk_4d0.z = 0;
    MTX_Identity33_(&self->unk_4dc);
    self->unk_3a4 = 0;
    self->unk_500.x = 0x1000;
    self->unk_500.y = 0x1000;
    self->unk_500.z = 0x1000;
    self->unk_50c = 0x1000;
    self->unk_510 = NULL;
    self->unk_514 = NULL;
    for (i = 0; i < 8; i++) {
        self->slots[i].anim = NULL;
        self->slots[i].endTime = 0;
    }
    self->unk_518 = NULL;
    self->unk_51c = NULL;
    self->unk_520 = NULL;
    return self;
}

void *Ov015StageMdl_Dtor(Ov015StageMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl1);
    ResSet_ReleaseAll(&self->res1);
    Model0218fe1c_FreeAnims(&self->mdl0);
    ResSet_ReleaseAll(&self->res0);
    SET_VT(self, Ov015Vt_02212f64_vtbl);
    Ov002Obj_Detach(self);
    return self;
}

void *Ov015StageMdl_DtorDelete(Ov015StageMdl *self) {
    Model0218fe1c_FreeAnims(&self->mdl1);
    ResSet_ReleaseAll(&self->res1);
    Model0218fe1c_FreeAnims(&self->mdl0);
    ResSet_ReleaseAll(&self->res0);
    SET_VT(self, Ov015Vt_02212f64_vtbl);
    Ov002Obj_Detach(self);
    Heap_Free(self);
    return self;
}

}
