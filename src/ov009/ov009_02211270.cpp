#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179b4[];
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_02211270(Ov009ActVt_02217aac *self) {
    Ov009Actor *t;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    }
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    Actor_TurnToActor(self, t, self->unk_b0->unk_02);
}

}
