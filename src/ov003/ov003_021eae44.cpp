#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/Unit.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"



typedef struct {
    u8 unk_00[0x4c];
    u8 *unk_4c;
} Ov003Snd;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
    u8 unk_17[0x4d];
    s32 radius;
    u8 unk_68[4];
    s32 unk_6c;
    VecFx32 pos;
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
    u8 unk_94[0xa90];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003Player;

extern "C" {

extern void *gGroup;
extern char data_ov003_021f995c[];
extern char data_ov003_021f9967[];
extern char data_ov003_021f996d[];
extern char data_ov003_021f9978[];
extern Ov003Player *ActorMgr_FindPlayer(void);
extern void ActorMarker_Draw(void *p);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL ResSet_UpdateLoad(ActorRes *res);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *anim, ActorRes *res, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
extern void *Heap_Alloc(u32 size);
extern ActorSub4c *Target_Init(void *p);
extern void *func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *a, void *b);
extern void Obj02190758_SetRot(Model0218fe1c *anim, Rot16 *rot, s32 a);
extern BOOL Model021903b4_Draw(Model0218fe1c *anim);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern Ov003Snd *gDataRes;
extern s32 DataRes_GetTable(Ov003Snd *s, s32 a);
extern u16 DataRes_ReadBitsAt_02059544(Ov003Snd *s, u8 *p, s32 a, s32 b, u16 c);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *m, s32 a);
extern void Model0218fe1c_SetAnim3(Model0218fe1c *m, s32 a, s32 b, s32 c);
extern void HitSphere_Unlink_0203f364(ActorSub48 *ctl);
extern void Model0218fe1c_SetLoop(void *model);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 a);
extern s32 Rand_PlusMinus(s32 max);
extern u16 Angle_Approach(u16 target, u16 cur, s32 step, u32 a, u16 b);
extern char data_ov003_021f9983[];
extern char data_ov003_021f9989[];
extern s32 Hit_CastSegment(VecFx32 *a, VecFx32 *b, u32 c, s32 d, s32 e, s32 f);
extern void Body_Update(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);

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
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}







static inline BOOL Ov003_GameIdle2(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        BOOL busy = FALSE;
        if (g->head != g->tail) {
            busy = TRUE;
        }
        if (busy) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void Ov003ActExHome_Animate(Ov003ActExHome *self) {
    if (!self->unk_cc_7) {
        return;
    }
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
    }
    Model0218fe1c_UpdateAnim(&self->mdl, (void *)0x1000);
}

BOOL Ov003ActVt_021f9834_Draw(Ov003ActExHome *self) {
    BOOL r;
    BOOL done = FALSE;
    if (self->unk_cc_7) {
        if (self->targetObj->unk_03 != 11) {
            done = ActorEx_Draw(self);
        }
        self->mdl.alpha = self->model->alpha;
    }
    self->mdl.trans.x = self->homePos.x;
    self->mdl.trans.y = self->homePos.y;
    self->mdl.trans.z = self->homePos.z;
    Obj02190758_SetRot(&self->mdl, &self->homeRot, 0);
    r = Model021903b4_Draw(&self->mdl);
    if (r && !done && self->unk_5c != NULL && Ov003_GameIdle2()) {
        ActorMarker_Draw(self->unk_5c);
    }
    return r;
}

void Ov003ActVt_021f9704_Init(Ov003ActExSway *self) {
    ActorEx_Init(self);
    self->hasModel = 0;
    if (self->unk_1a != 0) {
        char *name;
        self->hasModel = 1;
        name = data_ov003_021f996d;
        if (self->unk_1a == 3 || (self->unk_1a == 1 && (gActorMgr->frame & 1))) {
            name = data_ov003_021f9978;
        }
        ResSet_SetFile(&self->res, name, 1, 0, 0, 0);
        self->res.unk_00 = 0;
    }
    self->rotOfs.x = 0;
    self->rotOfs.y = 0;
    self->rotOfs.z = 0;
    self->rotGoal.x = 0;
    self->rotGoal.y = 0;
    self->rotGoal.z = 0;
    self->unk_30c = 0;
}

BOOL Ov003ActVt_021f9704_IsReady(Ov003ActExSway *self) {
    BOOL r = ActorEx_IsReady(self);
    Ov003Unit *u;
    if (self->hasModel && self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
        r = FALSE;
    }
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_6 = 0;
    }
    return r;
}

void Ov003ActVt_021f9704_Start(Ov003ActExSway *self) {
    u8 *x;
    BOOL f;
    s32 v;
    ActorEx_Start(self);
    if (self->hasModel) {
        Model0218fe1c_SetRes(&self->mdl, &self->res, 0, 1);
        self->mdl.actor_id = self->id;
        self->mdl.scale.x = 0x2000;
        self->mdl.scale.y = 0x2000;
        self->mdl.scale.z = 0x2000;
        self->targetObj->type = 15;
        self->targetObj->unk_01 = 1;
        self->targetObj->unk_03 = 0;
        self->targetObj->unk_02 = 1;
        self->targetObj->unk_18_1 = 0;
        self->hit->radius = 0x1000;
    }
    v = self->unk_18;
    f = FALSE;
    if (v < 0) {
        f = TRUE;
    }
    if (v >= 0x40) {
        f = TRUE;
    }
    if (!f) {
        x = gDataRes->unk_4c;
        if (DataRes_ReadBitsAt_02059544(gDataRes, x + 0x150, DataRes_GetTable(gDataRes, 10), 1, v)) {
            f = TRUE;
        }
    }
    if (!f) {
        return;
    }
    {
        AnimCtrl *a = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (a != NULL) {
            self->model->unk_c2_6 = 1;
            Model0218fe1c_SetAnim3(self->model, 0, 0x1000, 0);
            if (a->cur != NULL) {
                a->cur->frame = 0x1000;
            }
            a->paused = 1;
        }
    }
    self->unk_18 = -1;
}

BOOL Ov003ActVt_021f9704_Draw(Ov003ActExSway *self) {
    BOOL r = FALSE;
    if (self->hasModel) {
        Rot16 rot;
        rot.x = self->rot.x;
        rot.y = self->rot.y;
        rot.z = self->rot.z;
        if (self->fsm->current == 1) {
            rot.x += self->rotOfs.x;
            rot.y += self->rotOfs.y;
            rot.z += self->rotOfs.z;
        }
        Obj02190758_SetRot(&self->mdl, &rot, 0);
        self->mdl.trans.x = self->pos.x;
        self->mdl.trans.y = self->pos.y;
        self->mdl.trans.z = self->pos.z;
        r = Model021903b4_Draw(&self->mdl);
        if (r && self->unk_5c != NULL && Ov003_GameIdle2()) {
            ActorMarker_Draw(self->unk_5c);
        }
    } else if (Ov003_GameIdle() || self->unk_17 == 0xff) {
        r = ActorEx_Draw(self);
    }
    return r;
}

void Ov003ActVt_021f9704_Update(Ov003ActExSway *self) {
    Ov003Player *pl;
    ActorSub48 *ctl;
    if (self->hasModel) {
        return;
    }
    if (!Ov003_GameIdle()) {
        Actor *o = Actor_GetTarget(self);
        if (o != NULL) {
            Actor_TurnToActor(self, o, 0x400);
        }
    } else {
        func_ov000_02197ee0(self, &self->ai, 0x400, 0x333, 0x6000);
    }
    pl = ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    if (!pl->unk_93_4) {
        return;
    }
    if (self->unk_44 != NULL) {
        self->unk_44->unk_22_1 = 0;
    }
    ctl = self->hit;
    if (ctl == NULL) {
        return;
    }
    ctl->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(ctl);
}

static inline void Ov003Sub44_Clear(ActorSub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

void Ov003ActExSway_StateIdle(Ov003ActExSway *self) {
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov003_021f9983, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, (s16)(Rand_PlusMinus(0x59a) + 0x1000));
    }
    ActorEx_StateIdle(self);
    self->unk_93_0 = 0;
    if (self->hasModel) {
        u16 n = 0x100 - (u8)gActorMgr->frame;
        if (n < 0x60) {
            self->rotGoal.x = 0;
            self->rotGoal.z = 0;
        } else if ((n & 7) == 0) {
            self->rotGoal.x = Rand_PlusMinus(n) << 2;
            self->rotGoal.z = Rand_PlusMinus(n) << 2;
        }
        self->rotOfs.x = Angle_Approach(self->rotGoal.x, self->rotOfs.x, 0x8cd, 1, 0x8000);
        self->rotOfs.z = Angle_Approach(self->rotGoal.z, self->rotOfs.z, 0x8cd, 1, 0x8000);
    } else {
        Ov003Sub44_Clear(self->unk_44);
    }
}

static inline BOOL Ov003Player_Flag(Ov003Player *pl) {
    return pl->unk_93_4 ? TRUE : FALSE;
}

void Ov003ActExSway_StateMove(Ov003ActExSway *self) {
    VecFx32 a;
    VecFx32 b;
    VecFx32 v;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f9989, 0x2ab, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x2800);
        Model0218fe1c_SetLoop(self->model);
        Ov003Sub44_Clear(self->unk_44);
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->fsm->timer >= 10) {
            if (self->unk_44 == NULL) {
                break;
            }
            BOOL on = FALSE;
            Ov003Player *pl = ActorMgr_FindPlayer();
            ActorSub44 *s;
            if (pl != NULL && pl->unk_b24_1 && !Ov003Player_Flag(pl)) {
                a.x = self->pos.x;
                a.y = self->pos.y;
                a.z = self->pos.z;
                b.x = pl->pos.x;
                b.y = pl->pos.y;
                b.z = pl->pos.z;
                a.y += self->height;
                b.y += pl->unk_6c;
                if (Hit_CastSegment(&a, &b, -1, 0, 0, -1) == -0x1000) {
                    on = TRUE;
                }
            }
            s = self->unk_44;
            if (!on) {
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
            } else {
                s->unk_22_0 = 1;
                s->unk_22_1 = 1;
            }
        } else {
            self->fsm->timer = ((const ActorSub40 *)self->fsm)->timer + 1;
        }
        break;
    }
    self->hit->unk_9a_5 = 1;
    self->speed = 0x400;
    v.x = self->ai.pos.x;
    v.y = self->ai.pos.y;
    v.z = self->ai.pos.z;
    Actor_MoveToPos(self, &v, 0x333);
    Body_Update(self->hit, 1, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        return;
    }
    History_SetState(self->fsm, 4, 0);
}


}
