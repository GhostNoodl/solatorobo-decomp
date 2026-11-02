#include "ov006/ov006.h"
#include "ov006/Racer.h"

extern "C" {

#pragma force_active on
void func_ov006_021e7390(Ov006Racer *self) {
    ActorSub40 *p = self->fsm;
    if (p != NULL) {
        p->flags |= 2;
    }
}
#pragma force_active reset

}
