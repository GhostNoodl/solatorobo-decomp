#include "ov002/ov002.h"

extern "C" {

void Task021efa1c_UpdateActive(Task021efa1c *self) {
    u16 k = data_02097dc8->trig;
    if (k & 0x800) {
        u8 *g = (u8 *)data_02097e48.queue;
        if (FIELD(g, 0, Bits16).b3) {
            FIELD(g, 0x6, u16) = 0x8000;
            FIELD(g, 0x8, u16) = 10;
            FIELD(g, 0x2, u16) = 0;
        }
        g = (u8 *)data_02097e48.queue;
        FIELD(g, 0x80, u16) = 0x8000;
        FIELD(g, 0x7c, u16) = 0;
    }
    if (!(k & 2)) {
        return;
    }
    SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    data_ov002_021f0f84[0] = self->unk_3c->unk_a0->index;
    self->vfunc_0c(0);
}

}
