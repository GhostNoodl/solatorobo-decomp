#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"
#include "ov003/ActorApi.h"
#include "Main/Sys/FieldState.h"

extern "C" {

extern void *gActorMgr;
extern const char *data_ov003_021f7a48[][2];
extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s16 a, u8 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *model);
extern BOOL Model0218fe1c_IsAnimDelayed(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimDelay(Model0218fe1c *model, u16 a, BOOL b);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);
extern u16 func_ov000_02198da8(ActorSub48 *ctl, u16 a);
extern void Field_ShakeCamera(u8 a, u8 b);
extern void Actor_Move(Actor *self, s32 a);
extern void Actor_MoveToPos(Actor *self, const VecFx32 *v, s32 a);
extern void Body_Update(ActorSub48 *ctl, s32 a, s32 b, s32 c);

static inline BOOL Ov003Kb_GameBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Kb_GameIsIdle(FieldState *g) {
    if (Ov003Kb_GameBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Kb_GameIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Kb_GameIsIdle(g);
    }
    return TRUE;
}

static inline Actor *Ov003Kb_FindUnit(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov003Actor_StateAttack(Ov003Actor *self) {
    Actor *pl;
    ActorSub40 *w;
    BOOL f;
    if (!Ov003Kb_GameIdle()) {
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        History_SetState(self->fsm, 1, 0);
        return;
    }
    pl = Ov003Kb_FindUnit(self->target);
    w = self->fsm;
    switch (w->st) {
    case 0:
        if (self->unk_ee_2 >= 3) {
            self->unk_ee_2 = 0;
        }
        Model0218fe1c_SetAnim(self->model, data_ov003_021f7a48[self->unk_ee_2][self->unk_ee_4], 0x400, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        Actor_TurnToActor(self, pl, self->unk_b0->unk_02);
        if (self->model->anim_state == 1) {
            self->fsm->st = 10;
        }
        break;
    case 10: {
        ActorSub48 *ctl;
        BOOL a, b, c;
        f = FALSE;
        if (self->model->anim_state >= 10) {
            w->timer = self->model->anim_state;
        }
        if (self->model->unk_e4 & 0x8000000) {
            Model0218fe1c_SetAnimDelay(self->model, 3, 0);
        }
        ctl = self->hit;
        a = FALSE;
        b = FALSE;
        c = FALSE;
        if (ctl->unk_50 & 0x40000000) {
            a = TRUE;
        }
        if (ctl->unk_58 != 0) {
            b = TRUE;
        }
        if (self->unk_c4 != NULL && self->unk_c4->type == 1 && a) {
            if ((u16)(func_ov000_02198da8(ctl, self->moveYaw) - self->moveYaw - 0x4c00) < 0x6800) {
                c = TRUE;
            } else {
                a = FALSE;
            }
        }
        if (b || a || c) {
            self->moveYaw += 0x8000;
            self->speed >>= 1;
            self->friction = 0xc00;
            if (self->velY > 0) {
                self->velY = 0;
            }
            self->gravity = 0x52;
        }
        if (c) {
            ActorHp *t;
            Field_ShakeCamera(0xc, 0x1e);
            SndMgr_PlayAt(gSndMgr, 0x17, &self->pos, 0);
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            self->unk_ec_0 = 1;
            self->unk_94_1 = self->unk_c4->unk_02_0;
            self->hpObj->unk_04 = 0xffff;
            t = self->hpObj;
            t->dmg = 0;
            t->kind = 0;
            t->kind2 = 0x31;
            History_SetState(self->fsm, 0x13, 0);
            break;
        }
        if ((self->velY == 0 || !(self->hit->unk_54 & 0x20000000)) && (self->unk_c4 == NULL || self->unk_c4->type == 0)) {
            if (Model0218fe1c_IsAnimDone(self->model)) {
                f = TRUE;
            }
        }
        if (self->unk_c4 != NULL && (self->unk_c4->type == 2 || self->unk_c4->type == 5)) {
            ActorSub40 *w2 = self->fsm;
            if (w2->timer != 0) {
                w2->timer--;
            }
            if (w2->timer == 0) {
                if (Model0218fe1c_IsAnimDone(self->model)) {
                    f = TRUE;
                }
            }
        }
        if (f) {
            const char *name = data_ov003_021f7a60;
            ActorSub40 *w2;
            if (self->unk_ee_0) {
                name = data_ov003_021f7a66;
            }
            Model0218fe1c_SetAnim(self->model, name, 0xcd, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st = 0x14;
            w2 = self->fsm;
            if (w2->timer < 0x1e) {
                w2->timer = 0x1e;
            }
            self->friction = 0xc00;
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            self->unk_ec_0 = 1;
        }
        if (self->unk_c4 != NULL) {
            self->unk_94_1 = self->unk_c4->unk_02_0;
        }
        break;
    }
    case 0x14:
        self->unk_ec_0 = 1;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            History_SetState(self->fsm, 1, 0);
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
    if (Model0218fe1c_IsAnimDelayed(self->model)) {
        return;
    }
    f = TRUE;
    if (self->unk_c4 != NULL && (u8)(self->unk_c4->type + 0xfc) <= 1) {
        if (pl != NULL) {
            VecFx32 v;
            v.x = pl->pos.x;
            v.y = pl->pos.y;
            v.z = pl->pos.z;
            Actor_MoveToPos(self, &v, 0);
        }
        f = FALSE;
    } else {
        Actor_Move(self, 0);
        if (self->unk_c4 != NULL && self->unk_c4->type == 1) {
            f = FALSE;
        }
    }
    Body_Update(self->hit, f, 0, 0);
    if (self->velY < 0) {
        ActorSub48 *ctl = self->hit;
        if (ctl->unk_50 & 0x20000000) {
            self->velY = 0;
            if (ctl->unk_50 & 0x400) {
                Effect_SpawnId(0x2bc, &self->pos);
                Effect_SpawnId(0x2bd, &self->pos);
                SndMgr_PlayAt(gSndMgr, 0x3d, &self->pos, 0);
                self->gravity = 0;
                self->speed = 0;
            }
        }
    }
}

}
