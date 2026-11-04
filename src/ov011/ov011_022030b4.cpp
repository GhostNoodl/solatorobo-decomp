#include "ov011/ov011.h"

extern "C" {

extern void *gSndMgr;
extern const char data_ov011_02207bd8[];
u16 ActorGroup_CountKind(void *g, u16 id);
void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
void Shared_SetEventActor(u16 a, u16 b);
void StageVars_SetEventScript(s32 a);
void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);
void Actor_DropStateMsgs(Actor *self, u8 a);
void Body_Update(void *a, s32 b, s32 c, s32 d);

void Ov011ActVt_02207b34_Update(Ov003Actor *self) {
    BOOL ok;
    void *g;
    if (!Ov011_GameIdle()) {
        return;
    }
    self->unk_93_4 = 1;
    ok = TRUE;
    g = ActorMgr_GetGroup(gActorMgr, 0x5000);
    if (g != NULL && ActorGroup_CountKind(g, 0x5807) >= 1) {
        ok = FALSE;
    }
    if (ok) {
        Ov003Actor *pl;
        self->target = 0xffff;
        pl = (Ov003Actor *)ActorMgr_FindPlayer();
        if (pl == NULL) {
            return;
        }
        self->target = pl->id;
        self->fsm->flags |= 0x4000;
    } else {
        Ov003Actor_Update(self);
    }
}

void Ov011ActVt_02207b34_StateAttack2(Ov003Actor *self) {
    ActorSub40 *s;
    u8 a;
    s32 v;
    self->unk_ee_2 = 1;
    self->vfunc_64();
    s = self->fsm;
    if (s->current == 1) {
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
        return;
    }
    a = self->unk_3c->unk_19;
    v = self->unk_3c->unk_14;
    if (a == 0xff) {
        a = 15;
    }
    if (s->st == 10) {
        v += FX_Mul(0x6000 - v, 0x333);
        if (a >= 25) {
            a = 25;
        } else {
            a++;
        }
    } else if (s->st == 20) {
        Actor *t;
        if (a <= 15) {
            a = 15;
        } else {
            a--;
            v += FX_Mul(self->radius * 2 - v, 0x59a);
            self->unk_94_1 = 1;
        }
        t = Ov011_FindActor(self->target);
        if (t != NULL) {
            Actor_TurnToActor(self, t, 0x400);
        }
    }
    self->unk_3c->unk_14 = v;
    self->unk_3c->unk_19 = a;
}

void Ov011Actor_StateAttack2(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

void Ov011ActVt_02207b34_State20(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov011_02207bd8, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->model->visible = 0;
        self->fsm->st++;
        break;
    case 1: {
        EffectObj *p;
        if (++s->timer <= 120) {
            return;
        }
        SndMgr_PlayVolume(gSndMgr, 50, 100, -1, -1);
        p = Effect_SpawnId(50 + 0x358, &self->pos);
        p->SetScaleXYZ(0x1666, 0x1666, 0x1666);
        p->AddPosXYZ(0, 0x1000, 0);
        self->model->visible = 1;
        self->model->alpha = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 2:
        if (++s->timer > 60) {
            Shared_SetEventActor(self->kind, self->id);
            StageVars_SetEventScript(4);
            gSceneCmd->stageFlags = 1;
            self->model->alpha = 0x1f;
            History_SetState(self->fsm, 1, 0);
        } else if (self->fsm->timer > 30) {
            u8 v = self->model->alpha + 1;
            if (v > 0x1f) {
                v = 0x1f;
            }
            self->model->alpha = v;
        }
        break;
    }
}

void Ov011ActVt_02207b34_StateKnockBack(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
    }
    Ov003Actor_StateKnockBack(self);
}

void Ov011ActVt_02207b34_StateDown(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
        if (*self->hp == 0) {
            ActorMgr_BroadcastKind(gActorMgr, 0x5807, 0x15);
            ActorMgr_BroadcastKind(gActorMgr, 0x4803, 0x15);
        }
    }
    Ov003Actor_StateDown(self);
}

void Ov011ActVt_02207b34_StateDie(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        EffectObj *p;
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
        p = Effect_SpawnId(0x69, &self->pos);
        if (p != NULL) {
            p->SetScaleAll(0x2400);
            p->AddPosXYZ(0, 0x1000, 0);
        }
    }
    Ov003Actor_StateDie(self);
}

void Ov011ActVt_02207a88_Start(Ov003Actor *self) {
    Ov003Actor_Start(self);
    Actor_DropStateMsgs(self, 0xb);
}

void Ov011ActVt_02207a88_State20(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        self->speed = 0x59a;
        self->velY = 0;
        self->gravity = 5;
        self->friction = 0x1400 - 0x59a;
        self->moveYaw = self->rot_y;
        Model0218fe1c_SetAnim(self->model, data_ov011_02207bd8, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x2000);
        SndMgr_PlayVolume(gSndMgr, 0x29, -1, -1, -1);
        self->fsm->st++;
        break;
    case 1:
        if (++s->timer > 60) {
            self->gravity = 0x29;
            History_SetState(self->fsm, 4, 0);
        }
        Actor_Move(self, 0);
        Body_Update(self->hit, 0, 0, 0);
        break;
    }
}

Ov003Actor *Ov011ActVt_02207b34_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov011ActVt_02207b34_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov011ActVt_02207a88_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov011ActVt_02207a88_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov011Act7cf8_Start(Ov011Act7cf8 *self) {
    void *saved;
    Ov003Actor_Start(self);
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->hit != NULL) {
        void *p = self->hit;
        if (p != NULL) {
            HitSphere_Unlink_0203f2b8(p);
            Heap_Free(p);
        }
        self->hit = NULL;
    }
    gSysState->cur = saved;
    Ov011_VecSet(&self->unk_44->unk_0c, 0, -0x333, -self->radius >> 1);
    self->unk_f0.x = 0;
    self->unk_f0.y = 0;
    self->unk_f0.z = 0;
    self->unk_84.x = 0;
    self->unk_84.y = 0;
    self->unk_84.z = 0;
    self->unk_ea_6 = 1;
}

void Ov011Act7cf8_SelectState(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    u64 f = s->flags;
    if (f == 0) {
        return;
    }
    if ((f & 0x200000) == 0) {
        return;
    }
    History_SetState(s, 0x15, 0);
}

}
