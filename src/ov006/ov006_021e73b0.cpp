#include "ov006/ov006.h"
#include "ov006/Racer.h"

extern "C" {

BOOL History_SetState(ActorSub40 *a, int b, int c);
void Actor_DropStateMsgs(Actor *a, u8 b);

void Ov006ActVt_021ec4f4_SelectState(Ov006Racer *self) {
    ActorSub40 *p = self->fsm;
    if (p->flags & 2) {
        History_SetState(p, 1, 0);
    } else if (p->flags & 0x40000) {
        History_SetState(p, 0x12, 1);
    } else if (p->flags & 4) {
        History_SetState(p, 2, 0);
    }
    Actor_DropStateMsgs(self, self->fsm->current);
}

}
