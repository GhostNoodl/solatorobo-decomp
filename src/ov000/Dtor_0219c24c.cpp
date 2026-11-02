#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"

extern "C" {

extern u8 data_ov000_021cc774[];
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);
void HitSphere_Unlink_0203f2b8(void *p);
void *Actor_DtorBase(void *p);

u8 *Robo021ca458_Dtor(Robo021ca458 *self) {
    LFLD(void *, self, 0x00) = data_ov000_021cc774;
    HEAP_DELETE_FN(self->unk_998, Model0218fe1c_FreeAnims);
    HEAP_DELETE_FN(self->unk_99c, ResSet_ReleaseAll);
    HEAP_DELETE_MARKER(self->unk_9b0);
    HEAP_DELETE_MARKER(self->unk_9b4);
    self->model = NULL;
    self->unk_34 = 0;
    self->hit = NULL;
    ResSet_ReleaseAll(&self->res3);
    Model0218fe1c_FreeAnims(&self->mdl2);
    HitSphere_Unlink_0203f2b8(&self->hit1);
    ResSet_ReleaseAll(&self->res2);
    ResSet_ReleaseAll(&self->res1);
    Model0218fe1c_FreeAnims(&self->mdl1);
    HitSphere_Unlink_0203f2b8(&self->hit0);
    ResSet_ReleaseAll(&self->res0);
    Model0218fe1c_FreeAnims(&self->mdl0);
    Actor_DtorBase(self);
    return (u8 *)self;
}

u8 *Robo021ca458_DtorDelete(Robo021ca458 *self) {
    LFLD(void *, self, 0x00) = data_ov000_021cc774;
    HEAP_DELETE_FN(self->unk_998, Model0218fe1c_FreeAnims);
    HEAP_DELETE_FN(self->unk_99c, ResSet_ReleaseAll);
    HEAP_DELETE_MARKER(self->unk_9b0);
    HEAP_DELETE_MARKER(self->unk_9b4);
    self->model = NULL;
    self->unk_34 = 0;
    self->hit = NULL;
    ResSet_ReleaseAll(&self->res3);
    Model0218fe1c_FreeAnims(&self->mdl2);
    HitSphere_Unlink_0203f2b8(&self->hit1);
    ResSet_ReleaseAll(&self->res2);
    ResSet_ReleaseAll(&self->res1);
    Model0218fe1c_FreeAnims(&self->mdl1);
    HitSphere_Unlink_0203f2b8(&self->hit0);
    ResSet_ReleaseAll(&self->res0);
    Model0218fe1c_FreeAnims(&self->mdl0);
    Actor_DtorBase(self);
    Heap_Free(self);
    return (u8 *)self;
}

}
