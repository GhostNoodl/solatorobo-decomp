#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e00bc(Obj021eff30 *self) {
    u16 k = data_02097dc8->trig;
    Obj021eff50 *w;
    u8 *q;
    if (k & 1) {
        self->unk_18 = 0x28;
        SndMgr_PlayVolume(data_02097e4c, 0xf, -1, -1, -1);
        return;
    }
    if (!(k & 2) && !(k & 0x20)) {
        return;
    }
    {
        void *r = Param_Get(self->unk_10->unk_48);
        w = self->owner;
        Obj0215bb14_SetText(w->unk_20, r);
        w->unk_20->vfunc_70();
    }
    q = ((u8 *)self->owner->board);
    q[0x74] = 7;
    q[0x75] = 1;
    func_ov002_021e019c(self, self->unk_1c, self->unk_20);
    self->unk_18 = 0;
    SndMgr_PlayVolume(data_02097e4c, 0xf, -1, -1, -1);
}

}
