#include "ov011/ov011.h"

extern "C" {


#pragma force_active on
void Ov011SceneActor_StateIdle(Ov011SceneActor *self) {
    if (self->fsm->st == 0) {
        Ov011Scene *c = self->scene;
        if (c->b0 && c->b2) {
            c->unk_04 = 1;
            c->b2 = 0;
        }
    }
    if (!self->unk_f0_0) {
        Ov011Sa108 *p = self->unk_108;
        p->b0 = 0;
        p->b1 = 0;
        p->unk_02 = 0x1000;
        p->unk_04 = 0x1000;
    }
    Ov003Actor_StateIdle(self);
}
#pragma force_active reset
}
