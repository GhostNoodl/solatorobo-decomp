#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220abf8(Ov009ActVt_02217390 *self) {
    if (self->fsm->st == 0) {
        self->hit->unk_30 = 0;
        if (self->unk_1a == 1 && self->target != 0xffff) {
            ActorSub48 *s48 = self->hit;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
            s48 = self->hit;
            s48->unk_9a_2 = 0;
            s48->unk_9a_5 = 0;
        }
    }
    func_ov003_021d3a88(self);
}

}
