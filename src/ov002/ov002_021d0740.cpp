#include "ov002/ov002.h"

extern "C" {

void MusicPlayer_UpdateActive(Task021efa1c *self) {
    u16 k = gPad->trig;
    if (k & 0x800) {
        SndQueue *g = gSndQueue.queue;
        if (g->flag3) {
            g->unk_06 = 0x8000;
            g->unk_08 = 10;
            g->unk_02 = 0;
        }
        g = gSndQueue.queue;
        g->unk_80 = 0x8000;
        g->unk_7c = 0;
    }
    if (!(k & 2)) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    data_ov002_021f0f84[0] = self->unk_3c->unk_a0->index;
    self->vfunc_0c(0);
}

}
