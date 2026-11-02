#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_02217d3a[];
extern void *func_ov000_02191318(void *a, s32 b);
extern Ov003Actor *func_ov000_0219bf90(void);
extern void Actor_TurnToActor(Actor *self, Actor *target, s32 a);
extern s32 Interp_SinLerp(s32 a, s32 b, s32 c);

static inline void Ov014_TimerTick(ActorSub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02212dd4(Ov014Act_0221267c *self) {
    ActorSub40 *s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        self->fsm->timer = 120;
        break;
    case 1: {
        u16 t = s->timer;
        u8 b = Interp_SinLerp(FX_Div(t << 12, 0x78000), 0x1f000, 0) >> 12;
        self->model->alpha = b;
        self->unk_2e6 = b;
        if (t == 50) {
            func_02065f88(0xcb, &self->pos)->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        }
        if (t == 20) {
            VecFx32 v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += 0x2000;
            func_02065f88(0x38a, &v)->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        }
        Actor_TurnToActor(self, func_ov000_0219bf90(), 0x400);
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
