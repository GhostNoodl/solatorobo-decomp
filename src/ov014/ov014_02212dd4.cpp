#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_02217d3a[];
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *a, s32 b);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern s32 Interp_SinLerp(s32 a, s32 b, s32 c);

static inline void Ov014_TimerTick(ActorSub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void Ov014Act_0221267c_State20(Ov014Act_0221267c *self) {
    ActorSub40 *s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov014_02217d3a, 0x19a, 0);
        Model0218fe1c_SetAnimFrame(self->model, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
        self->fsm->timer = 120;
        break;
    case 1: {
        u16 t = s->timer;
        u8 b = Interp_SinLerp(FX_Div(t << 12, 0x78000), 0x1f000, 0) >> 12;
        self->model->alpha = b;
        self->mdl.alpha = b;
        if (t == 50) {
            Effect_SpawnId(0xcb, &self->pos)->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        }
        if (t == 20) {
            VecFx32 v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += 0x2000;
            Effect_SpawnId(0x38a, &v)->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        }
        Actor_TurnToActor(self, ActorMgr_FindPlayer(), 0x400);
        s = self->fsm;
        if (ActorSub40_Timer(s) == 0) {
            s->st++;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    }
    case 2: {
        ActorSub44 *n;
        s->st = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        break;
    }
    }
}

}
