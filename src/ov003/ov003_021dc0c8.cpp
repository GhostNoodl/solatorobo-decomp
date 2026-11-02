#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Shot.h"

extern "C" {

extern Ov003BeamDef data_ov003_021f49ec[];
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);

void func_ov003_021dc0c8(Ov003Shot *self) {
    self->age = 0;
    self->trailTimer = 0;
    self->stepTimer = 0;
    self->step = 0;
    self->lockTimer = 0;
}

void func_ov003_021dc0e4(Ov003Shot *self) {
    func_ov000_02198360(self->fsm, 0x15, 0);
}

void func_ov003_021dc0fc(Ov003Shot *self) {
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
    func_ov000_0219763c(self);
}

void func_ov003_021dc148(Ov003Shot *self) {
    if (self->fsm->st == 0) {
        if (self->def->stopFly && self->unk_bc != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        self->age = 0;
    }
    func_ov000_02195d88(self);
}

void Ov003ActVt_021f7d4c_Start(Ov003Beam *self) {
    Ov003BeamDef *def;
    u8 i;
    func_ov000_02194758(self);
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
        func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        func_02049f44(data_02097e4c, self->def->sound, &self->pos, 0);
    }
    func_ov000_02198360(self->fsm, 0xb, 0);
}

void func_ov003_021dc27c(Ov003Beam *self) {
    u8 i;
    ActorSub40 *t;
    u16 st = self->fsm->st;
    switch (st) {
    case 0:
        func_ov003_021dc3fc(self, 1, st);
        func_ov003_021dc3fc(self, 0, st);
        if (self->fsm->timer >= 3) {
            func_ov003_021dc840(self);
        }
        t = self->fsm;
        t->timer++;
        if (t->timer >= self->def->duration || self->unk_1a == 1) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 1:
        func_ov003_021dc3fc(self, 1, st);
        func_ov003_021dc3fc(self, 0, st);
        if (self->scales[1].x == 0 && self->scales[1].y == 0) {
            for (i = 0; i < 2; i++) {
                EffectObj *fx = func_020657b0(data_0214a420, self->layers[i]);
                if (fx != NULL) {
                    fx->alpha = FX_Div(0, 0x1f000);
                    EffectObj_StopLoop(fx);
                }
            }
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
}

void func_ov003_021dc3b8(Ov003Beam *self) {
    if (self->fsm->st == 0) {
        EffectMgr_Kill(data_0214a420, self->layers[1]);
        EffectMgr_Kill(data_0214a420, self->layers[0]);
    }
    func_ov000_0219763c(self);
}

}
