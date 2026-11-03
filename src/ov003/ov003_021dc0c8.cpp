#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Shot.h"

extern "C" {

extern Ov003BeamDef data_ov003_021f49ec[];
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);

void Ov003Shot_ResetTimers(Ov003Shot *self) {
    self->age = 0;
    self->trailTimer = 0;
    self->stepTimer = 0;
    self->step = 0;
    self->lockTimer = 0;
}

void Ov003Shot_State0a(Ov003Shot *self) {
    History_SetState(self->fsm, 0x15, 0);
}

void Ov003Shot_StateDie(Ov003Shot *self) {
    if (self->fsm->st == 0) {
        s32 v = self->def->hitRadius;
        if (v >= 0) {
            self->radius = v << 4;
        }
        v = self->def->hitHeight;
        if (v >= 0) {
            self->height = v << 4;
            self->centerY = (v << 4) >> 1;
        }
    }
    ActorEx_StateDie(self);
}

void Ov003Shot_StateHeld(Ov003Shot *self) {
    if (self->fsm->st == 0) {
        if (self->def->stopFly && self->unk_bc != NULL) {
            EffectMgr_Kill(gEffectMgr, self->unk_bc);
            self->unk_bc = NULL;
        }
        self->age = 0;
    }
    ActorEx_StateHeld(self);
}

void Ov003ActVt_021f7d4c_Start(Ov003Beam *self) {
    Ov003BeamDef *def;
    u8 i;
    ActorEx_Start(self);
    def = self->beamDef;
    if (def == NULL) {
        def = &data_ov003_021f49ec[self->unk_18];
    }
    self->def = def;
    for (i = 0; i < 2; i++) {
        self->scales[i].x = 0;
        self->scales[i].y = 0;
        self->scales[i].z = 0;
        self->layers[i] = NULL;
    }
    def = self->def;
    self->unk_84.x = def->offset.x;
    self->unk_84.y = def->offset.y;
    self->unk_84.z = def->offset.z;
    if (def->sound >= 0) {
        SndMgr_PlayAt(gSndMgr, 0x5c, &self->pos, 0);
        SndMgr_PlayAt(gSndMgr, self->def->sound, &self->pos, 0);
    }
    History_SetState(self->fsm, 0xb, 0);
}

void Ov003Beam_StateThrown(Ov003Beam *self) {
    u8 i;
    ActorSub40 *t;
    u16 st = self->fsm->st;
    switch (st) {
    case 0:
        Ov003Beam_UpdateLayer(self, 1, st);
        Ov003Beam_UpdateLayer(self, 0, st);
        if (self->fsm->timer >= 3) {
            Ov003Beam_Fire(self);
        }
        t = self->fsm;
        t->timer++;
        if (t->timer >= self->def->duration || self->unk_1a == 1) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 1:
        Ov003Beam_UpdateLayer(self, 1, st);
        Ov003Beam_UpdateLayer(self, 0, st);
        if (self->scales[1].x == 0 && self->scales[1].y == 0) {
            for (i = 0; i < 2; i++) {
                EffectObj *fx = Effect_Find_020657b0(gEffectMgr, self->layers[i]);
                if (fx != NULL) {
                    fx->alpha = FX_Div(0, 0x1f000);
                    EffectObj_StopLoop(fx);
                }
            }
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
}

void Ov003Beam_StateDie(Ov003Beam *self) {
    if (self->fsm->st == 0) {
        EffectMgr_Kill(gEffectMgr, self->layers[1]);
        EffectMgr_Kill(gEffectMgr, self->layers[0]);
    }
    ActorEx_StateDie(self);
}

}
