#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179b4[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_02211270(Ov009Actor *self) {
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
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    func_ov000_0218d988(self, t, self->unk_b0->unk_02);
}

}
