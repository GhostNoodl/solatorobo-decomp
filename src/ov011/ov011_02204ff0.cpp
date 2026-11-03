#include "ov011/ov011.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

#pragma force_active on
void Ov011Act7da4_Update(Ov011Act7da4 *self) {
    Ov003Actor *pl;
    u16 pct;
    self->unk_93_4 = 1;
    if (self->hp[0] == 0) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov003Actor *)ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    self->target = pl->id;
    if (self->fsm->current != 1) {
        return;
    }
    pct = self->hp[0] * 100 / self->hp[1];
    switch (self->unk_b4) {
    case 0:
    case 1:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        if (pct <= 0x46) {
            self->fsm->flags |= 0x20000;
        } else {
            self->fsm->flags |= 0x4000;
        }
        if (pct <= 0x4b) {
            self->unk_b6 = (pct >> 2) + 100;
            self->unk_b4 = 2;
        } else if (self->unk_b4 == 0) {
            self->unk_b6 = (pct >> 2) + 100;
            self->unk_b4++;
        } else {
            self->unk_b6 = (pct >> 2) + 0x78;
            self->unk_b4 = 0;
        }
        break;
    case 2:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        self->fsm->flags |= 0x8000;
        self->unk_b6 = (pct >> 2) + 100;
        if (pct <= 0x28) {
            self->unk_b4++;
        } else {
            self->unk_b4 = 1;
        }
        break;
    case 3:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        self->fsm->flags |= 0x10000;
        self->unk_b6 = (pct >> 2) + 0x5a;
        self->unk_b4 = 0;
        break;
    }
}
#pragma force_active reset


int func_02043d9c(void *p);

#pragma force_active on
void Ov011Act7da4_Draw(Ov011Act7da4 *self) {
    u8 v = gGfxSys->unk_8b0[3];
    func_02043d9c(gGfxSys->unk_8b0);
    self->model->polyId = v;
    Ov003Actor_Draw(self);
}
#pragma force_active reset
}
