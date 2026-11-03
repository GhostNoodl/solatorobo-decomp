#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/SysState.h"
#include "Main/Effect/Effect.h"

typedef struct {
    s16 state;
} AnimRes;

extern "C" {

extern const u8 ActorEx_vtbl[];

void *Actor_Ctor(Actor *self);
void *Actor_DtorBase(Actor *self);
ResSet *ResSet_ReleaseAll(ResSet *self);
void Heap_Free(void *ptr);
BOOL ResSet_UpdateLoad(AnimRes *res);
void *Target_Get(void *p);
void *ActorMgr_FindPlayer(void);
void HitSphere_Unlink_0203f364(ActorSub48 *obj);
void HitMesh_Link(void *obj);
void ActorSub48_UpdatePos(ActorSub48 *obj, VecFx32 *pos, s32 c);

static inline void ResSet_Delete(ResSet *res) {
    if (res != NULL) {
        ResSet_ReleaseAll(res);
        Heap_Free(res);
    }
}

static inline void ActorEx_CtorBody(ActorEx *self) {
    s32 i;

    Actor_Ctor(self);
    *(const void **)self = ActorEx_vtbl;
    self->unk_ac = 0xff;
    self->unk_ad = 0xff;
    self->unk_ae = 0xff;
    self->param = NULL;
    for (i = 0; i < 2; i++) {
        self->res[i] = NULL;
    }
    *((u16 *)self + 0x66) = 0;
    self->unk_bc = NULL;
    self->unk_c0 = 0;
    self->unk_c4 = 0;
    self->unk_c8 = 0;
    self->unk_cc_3 = 1;
    self->unk_cc_4 = 1;
    self->unk_cc_5 = 1;
}

static inline void ActorEx_Destroy(ActorEx *self) {
    s32 i;

    *(const void **)self = ActorEx_vtbl;
    for (i = 0; i < 2; i++) {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->res[i] != NULL) {
            ResSet_Delete(self->res[i]);
            self->res[i] = NULL;
        }
        gSysState->cur = saved;
    }
    if (self->unk_bc != NULL) {
        EffectMgr_Kill(gEffectMgr, self->unk_bc);
    }
    Actor_DtorBase(self);
}

void ActorEx_UpdateHit(ActorEx *self) {
    VecFx32 tmp;
    VecFx32 *pos;

    ActorSub48 *obj = self->hit;

    if (obj != NULL) {
        if (self->param->type == 2) {
            obj->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(obj);
        }
        pos = &self->pos;
        if (self->unk_3c != NULL && self->param->type == 3) {
            self->hit->unk_9a_4 = 1;
            tmp = self->pos;
            pos = &tmp;
        }
        ActorSub48_UpdatePos(self->hit, pos, 0);
    }
    if (self->hitMesh != NULL && self->unk_cc_0) {
        HitMesh_Link(self->hitMesh);
    }
}

}
