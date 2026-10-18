#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220a560(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        self->pos.y = FLD(s32, self, 0xfc) - 0xc00;
        FLD(u8, self->unk_38, 0xbe) = 0;
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->state++;
        break;
    case 1: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x1f) {
            if (self->unk_1a == 0) {
                func_ov000_02198360(self->unk_40, 1, 0);
            } else {
                func_ov000_02198360(self->unk_40, 0x10, 0);
            }
            self->unk_40->timer = 0x1f;
        }
        FLD(u8, self->unk_38, 0xbe) = self->unk_40->timer;
        self->pos.y = self->pos.y + ((FLD(s32, self, 0xfc) - self->pos.y) >> 2);
        break;
    }
    }
    self->unk_48->unk_9a_4 = 0;
    self->unk_48->unk_9a_5 = 0;
}

extern u8 data_ov009_022172cd[];
extern void func_ov003_021d36fc(Ov009Actor *self);
extern void func_ov000_02191618(void *model);
extern void func_ov000_021911c8(void *model, s32 a);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220a654(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u16, self, 0xf0) = 0;
    }
    func_ov003_021d36fc(self);
    if (self->unk_40->state == 2) {
        self->unk_40->timer = 0;
    }
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    FLD(u16, self, 0xf0)++;
    if (FLD(u16, self, 0xf0) > 0xf0) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_022172cd, 0x29, 0);
    func_ov000_02191618(self->unk_38);
    func_ov000_021911c8(self->unk_38, 0x200);
}

}
