#include "ov006/ov006.h"
#include "ov006/Racer.h"

extern "C" {

BOOL func_ov000_02198360(ActorSub40 *a, int b, int c);
void func_ov000_0218d7e8(Actor *a, u8 b);

void Ov006ActVt_021ec4f4_SelectState(Ov006Racer *self) {
    ActorSub40 *p = self->fsm;
    if (p->flags & 2) {
        func_ov000_02198360(p, 1, 0);
    } else if (p->flags & 0x40000) {
        func_ov000_02198360(p, 0x12, 1);
    } else if (p->flags & 4) {
        func_ov000_02198360(p, 2, 0);
    }
    func_ov000_0218d7e8(self, self->fsm->current);
}

}
