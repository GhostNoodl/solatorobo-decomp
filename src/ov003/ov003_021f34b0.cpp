#include "types.h"
#include "ov003/ActorApi.h"
#include "ov003/Prop.h"

extern "C" {

extern u32 data_ov003_021fa648;
extern void Ov000ActVt_021cc7cc_Start(Ov003Prop *self);
extern void *Tbl_FindEntry_0206fef8(u16 kind);
extern void __cxa_vec_cleanup(void *arr, int count, int size, void *dtor);
extern void Ov000ActVt_021cc7cc_Init(Ov003Prop *self);
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL Actor_IsReady(Actor *self);
extern BOOL ResSet_UpdateLoad(ActorRes *p);
extern void Heap_Free(void *p);
extern void func_ov000_021b4b0c(void *p);

void Ov003ActVt_021fa2e0_Start(Ov003Prop *self) {
    s32 x;
    s32 y;
    s32 z;
    Model0218fe1c *model;
    Ov000ActVt_021cc7cc_Start(self);
    Tbl_FindEntry_0206fef8(self->kind);
    model = self->model;
    x = model->scale.x;
    y = model->scale.y;
    if (self->unk_18 != 0) {
        x = self->unk_18 << 4;
    }
    z = model->scale.z;
    if (self->unk_1a != 0) {
        y = self->unk_1a << 4;
    }
    if (self->unk_1c != 0) {
        z = self->unk_1c << 4;
    }
    model->scale.x = x;
    model->scale.y = y;
    model->scale.z = z;
}

void func_ov003_021f3508(void) {

}

Ov003Prop *Ov003ActVt_021fa4f0_Dtor(Ov003Prop *self) {
    Actor_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa4f0_DtorDelete(Ov003Prop *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa498_Dtor(Ov003Prop *self) {
    Actor_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa498_DtorDelete(Ov003Prop *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003PropMulti *Ov003ActVt_021fa390_Dtor(Ov003PropMulti *self) {
    __cxa_vec_cleanup(self->mdl, 6, sizeof(Model0218fe1c), (void *)Model0218fe1c_FreeAnims);
    __cxa_vec_cleanup(self->res, 8, sizeof(ActorRes), (void *)ResSet_ReleaseAll);
    Actor_DtorBase(self);
    return self;
}

Ov003PropMulti *Ov003ActVt_021fa390_DtorDelete(Ov003PropMulti *self) {
    __cxa_vec_cleanup(self->mdl, 6, sizeof(Model0218fe1c), (void *)Model0218fe1c_FreeAnims);
    __cxa_vec_cleanup(self->res, 8, sizeof(ActorRes), (void *)ResSet_ReleaseAll);
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa440_Dtor(Ov003Prop *self) {
    Actor_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa440_DtorDelete(Ov003Prop *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa3e8_Dtor(Ov003Prop *self) {
    Actor_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa3e8_DtorDelete(Ov003Prop *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa338_Dtor(Ov003Prop *self) {
    Actor_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa338_DtorDelete(Ov003Prop *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa2e0_Dtor(Ov003Prop *self) {
    Actor_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa2e0_DtorDelete(Ov003Prop *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021fa5f8_Init(Ov003PropResMdl *self) {
    Ov000ActVt_021cc7cc_Init(self);
    if (self->kind == 0x6a01) {
        return;
    }
    ResSet_SetFile(&self->res, &data_ov003_021fa648, 1, 1, 0, 0);
    self->res.unk_00 = 0;
}

} // extern "C"
