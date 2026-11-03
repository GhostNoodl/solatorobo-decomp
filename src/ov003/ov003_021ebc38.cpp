#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/ActorApi.h"
#include "Main/Sys/SysState.h"



typedef struct {
    u8 unk_00[0x64];
    s32 radius;
    u8 unk_68[8];
    VecFx32 pos;
} Ov003LiftPlayer;

// The lift (vtable data_ov003_021f979c). Actor::unk_1a selects the one with a model; unk_302
// counts frames.
typedef Ov003ActExHome Ov003Lift;

extern "C" {

extern char data_ov003_021f998f[];
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);
extern BOOL ResSet_UpdateLoad(ActorRes *p);
extern BOOL Model0218fe1c_SetRes(void *anim, ActorRes *res, s32 a, s32 b);
extern void Model0218fe1c_SetAnimByIndex(void *anim, s32 a, s32 b, s32 c);
extern void Model0218fe1c_SetLoop(void *anim);
extern void HitSphere_Unlink_0203f2b8(void *p);
extern void Heap_Free(void *p);
extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void *func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *a, void *b);
extern Ov003LiftPlayer *ActorMgr_FindPlayer(void);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern void Obj02190758_SetRot(void *anim, void *p, s32 a);
extern BOOL Model021903b4_Draw(void *anim);
extern void ActorMarker_Draw(void *p);

void Ov003ActVt_021f979c_Init(Ov003Lift *self) {
    ActorEx_Init(self);
    if (self->unk_1a != 0) {
        ResSet_SetFile(&self->res, data_ov003_021f998f, 1, 1, 0, 0);
        self->res.unk_00 = 0;
    }
    self->homePos.x = self->pos.x;
    self->homePos.y = self->pos.y;
    self->homePos.z = self->pos.z;
    self->homeRot.x = self->rot.x;
    self->homeRot.y = self->rot.y;
    self->homeRot.z = self->rot.z;
    History_SetState(self->fsm, 1, 0);
}

BOOL Ov003ActVt_021f979c_IsReady(Ov003Lift *self) {
    BOOL r = ActorEx_IsReady(self);
    if (self->unk_1a != 0 && self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
        r = FALSE;
    }
    return r;
}

void Ov003ActVt_021f979c_Start(Ov003Lift *self) {
    ActorEx_Start(self);
    if (self->unk_1a != 0) {
        Model0218fe1c_SetRes(&self->mdl, &self->res, 0, 1);
        self->mdl.actor_id = self->id;
        self->mdl.scale.x = 0x1c00;
        self->mdl.scale.y = 0x1c00;
        self->mdl.scale.z = 0x1c00;
        Model0218fe1c_SetAnimByIndex(&self->mdl, 0, 0x1000, 0);
        Model0218fe1c_SetLoop(&self->mdl);
        self->fxOffset.x = 0;
        self->fxOffset.y = 0x1800;
        self->fxOffset.z = 0x1800;
    } else {
        void *p;
        void *old = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->hit;
        if (p != NULL) {
            if (p != NULL) {
                HitSphere_Unlink_0203f2b8(p);
                Heap_Free(p);
            }
            self->hit = NULL;
        }
        data_02097dd0->cur = old;
        self->fxOffset.x = 0;
        self->fxOffset.y = 0x1800;
        self->fxOffset.z = 0x800;
    }
    func_01ffc9fc(&self->fxOffset, &self->fxOffset, self->rot.y);
    self->unk_302 = 0;
}

void Ov003ActVt_021f979c_Animate(Ov003Lift *self) {
    if (self->unk_cc_7) {
        if (self->unk_bc != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        if (self->model != NULL) {
            Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
        }
        return;
    }
    if (self->unk_1a != 0) {
        Model0218fe1c_UpdateAnim(&self->mdl, (void *)0x1000);
    }
    if (!(self->unk_302 & 0x7f)) {
        Ov003LiftPlayer *pl = ActorMgr_FindPlayer();
        if (pl != NULL && Hit_DiffInSphere(&pl->pos, &self->pos, pl->radius + 0xf000)) {
            EffectObj *fx = Effect_SpawnId(0xcc, &self->pos);
            if (fx != NULL) {
                self->unk_bc = fx->id;
            }
        }
    }
    self->unk_302++;
}

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasEvent(FieldState *g) {
    return g->event != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasEvent(data_ov000_021ccd54) ? TRUE : FALSE;
}

BOOL Ov003ActVt_021f979c_Draw(Ov003Lift *self) {
    BOOL r = TRUE;
    BOOL done = FALSE;
    if (self->unk_cc_7) {
        done = ActorEx_Draw(self);
        if (self->unk_1a != 0) {
            self->mdl.alpha = self->model->alpha;
        }
    }
    if (self->unk_1a != 0) {
        self->mdl.trans.x = self->homePos.x;
        self->mdl.trans.y = self->homePos.y;
        self->mdl.trans.z = self->homePos.z;
        Obj02190758_SetRot(&self->mdl, &self->homeRot, 0);
        r = Model021903b4_Draw(&self->mdl);
    }
    if (!done && self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        ActorMarker_Draw(self->unk_5c);
    }
    return r;
}
}
