#include "ov014/ov014.h"

extern "C" {

extern void Ov003FxList_KillAll(void *p);

void func_ov014_022083a4(Ov014ActEx_0220774c *self) {
    FieldState *g;
    if (self->unk_40->state != 0) {
        return;
    }
    Ov003FxList_KillAll(self->unk_d8);
    g = data_ov000_021ccd54;
    g->cam.base.shakeRandom = 0;
    g->cam.base.shakeTime = 0;
    g->cam.base.shakeLen = 0;
    g->cam.base.shakeCur = 0;
    func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
    self->v08();
}

}
