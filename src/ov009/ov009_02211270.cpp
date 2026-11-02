#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022179b4[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void func_ov009_02211270(Ov009ActVt_02217aac *self) {
    Ov003Actor *t;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    }
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    Actor_TurnToActor(self, t, self->unk_b0->unk_02);
}

}
