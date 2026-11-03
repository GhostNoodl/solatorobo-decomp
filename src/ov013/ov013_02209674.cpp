#include "ov013/ov013.h"

extern "C" {

extern void *gSndMgr;
extern char data_ov013_0220be82[];
extern void HitSphere_Link(ActorSub48 *p);
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *a, s32 b);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 a);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline void Ov013_Land(Ov013Act_02207968 *self) {
    Model0218fe1c_SetAnim(self->model, data_ov013_0220be82, 0x155, 0);
    Model0218fe1c_SetAnimFrame(self->model, 0x96000);
    SndMgr_PlayAtPitch(gSndMgr, 0x39, &self->pos, 2);
    self->unk_f0 = 2;
    History_SetState(self->fsm, 1, 0);
    self->fsm->st = 7;
}

void Ov013Act_02207968_StateHeld(Ov013Act_02207968 *self) {
    ActorSub48 *m;
    ActorSub44 *n;
    if (self->fsm->st == 0) {
        self->unk_110 = 0;
    }
    Ov003Actor_StateHeld(self);
    if (self->fsm->current != 10) {
        return;
    }
    self->targetObj->target = 0xffff;
    m = self->hit;
    m->unk_9a_0 = 1;
    m->unk_9a_3 = 1;
    HitSphere_Link(m);
    n = self->unk_44;
    n->unk_22_0 = 1;
    n->unk_22_1 = 1;
    Ov013_Land(self);
}

void Ov013Act_02207968_StateFly(Ov013Act_02207968 *self) {
    Ov003Actor *t;
    Ov003Actor_StateFly(self);
    if (self->fsm->current != 1) {
        return;
    }
    t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Actor_TurnToActor(self, t, 0x1000);
    Ov013_Land(self);
}

void Ov013Act_02207968_StateHurt(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        if (self->pos.y < 0x4800) {
            self->pos.y = 0x4800;
        }
        SndMgr_PlayAt(gSndMgr, 0x63, &self->pos, 0);
    }
    Ov003Actor_StateHurt(self);
    if (self->pos.y < 0x4800) {
        self->pos.y = 0x4800;
    }
    if (self->fsm->current != 1) {
        return;
    }
    Ov013_Land(self);
}

void Ov013Act_02207968_StateKnockBack(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        if (self->pos.y < 0x4800) {
            self->pos.y = 0x4800;
        }
        SndMgr_PlayAt(gSndMgr, 0x63, &self->pos, 0);
    }
    Ov003Actor_StateHurt(self);
    if (self->pos.y < 0x4800) {
        self->pos.y = 0x4800;
    }
    if (self->fsm->current != 1) {
        return;
    }
    Ov013_Land(self);
}

void Ov013Act_02207968_StateDown(Ov013Act_02207968 *self) {
    ActorSub48 *m;
    if (self->fsm->st == 0) {
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        self->rot_x = 0;
        SndMgr_PlayAt(gSndMgr, 0x63, &self->pos, 0);
    }
    Ov003Actor_StateDown(self);
    if (self->fsm->current == 0x14) {
        return;
    }
    Ov013_Land(self);
}

void Ov013Act_02207968_StateDie(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        EffectObj *fx;
        ActorMgr_BroadcastKind(gActorMgr, 0x4811, 10);
        ActorMgr_BroadcastKind(gActorMgr, 0x4813, 10);
        fx = Effect_SpawnId(0x69, &self->pos);
        if (fx != NULL) {
            fx->SetScaleAll(0x3000);
            fx->AddPosXYZ(0, self->centerY, 0);
        }
    }
    Ov003Actor_StateDie(self);
}

}
