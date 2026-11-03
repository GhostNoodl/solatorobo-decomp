#include "ov014/ov014.h"

extern "C" {


void Ov014ActEx_0220774c_StateDie(Ov014ActEx_0220774c *self) {
    FieldState *g;
    if (self->fsm->st != 0) {
        return;
    }
    Ov003FxList_KillAll(self->unk_d8);
    g = gSceneCmd;
    g->cam.base.shakeRandom = 0;
    g->cam.base.shakeTime = 0;
    g->cam.base.shakeLen = 0;
    g->cam.base.shakeCur = 0;
    Group_UpdateActor(gGroup, 0, self);
    self->vfunc_08();
}

}
