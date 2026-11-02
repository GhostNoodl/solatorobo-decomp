#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {


void func_ov009_021fc51c(Ov009ActVt_02216348 *self) {
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
                    func_0204a028(data_02097e4c, 0x1e, &self->pos, 0xc);
                }
                func_ov000_02198360(self->fsm, 1, 0);
                self->velY = 0;
                self->gravity = 0;
                self->friction = 0x800;
            } else {
                st = self->fsm;
                st->timer++;
                if (st->timer > 0x46) {
                    self->fsm->timer = 0x46;
                    if (!(self->hit->unk_54 & 0x20000000)) {
                        func_ov000_02198360(self->fsm, 0x15, 0);
                    }
                }
            }
        }
        break;
    }
    Actor_Move(self, 0);
    if (self->hit != NULL) {
        func_ov000_021987b8(self->hit, 1, 0, 0);
    }
}

}
