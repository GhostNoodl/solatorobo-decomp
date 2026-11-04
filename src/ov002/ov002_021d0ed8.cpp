#include "ov002/ov002.h"

extern "C" {

void TheaterMenu_UpdateActive(Task021ef89c *self) {
    if (!(gPad->trig & 2)) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    data_ov002_021f0f84[1] = FIELD(self->unk_3c, 0xa8, s32);
    self->vfunc_0c(0);
}

}
