#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {


void Ov009ActVt_02216348_StateFly(Ov009ActVt_02216348 *self) {
    ActorSub40 *st;
    switch (ActorSub40_State(self->fsm)) {
    case 0:
        self->fsm->st++;
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
    case 1:
        if (self->velY < 0) {
            if (self->hit->unk_50 & 0x20000000) {
                if (self->velY < -0xcd) {
                    SndMgr_PlayAtPitch(data_02097e4c, 0x1e, &self->pos, 0xc);
                }
                History_SetState(self->fsm, 1, 0);
                self->velY = 0;
                self->gravity = 0;
                self->friction = 0x800;
            } else {
                st = self->fsm;
                st->timer++;
                if (st->timer > 0x46) {
                    self->fsm->timer = 0x46;
                    if (!(self->hit->unk_54 & 0x20000000)) {
                        History_SetState(self->fsm, 0x15, 0);
                    }
                }
            }
        }
        break;
    }
    Actor_Move(self, 0);
    if (self->hit != NULL) {
        Body_Update(self->hit, 1, 0, 0);
    }
}

}
