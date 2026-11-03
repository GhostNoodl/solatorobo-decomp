#include "ov002/ov002.h"

extern "C" {

void Task021efa1c_UpdateActive(Task021efa1c *self) {
    u16 k = data_02097dc8->trig;
    if (k & 0x800) {
        SndQueue *g = data_02097e48.queue;
        if (g->flag3) {
            g->unk_06 = 0x8000;
            g->unk_08 = 10;
            g->unk_02 = 0;
        }
        g = data_02097e48.queue;
        g->unk_80 = 0x8000;
        g->unk_7c = 0;
    }
    if (!(k & 2)) {
        return;
    }
    SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    data_ov002_021f0f84[0] = self->unk_3c->unk_a0->index;
    self->vfunc_0c(0);
}

}
