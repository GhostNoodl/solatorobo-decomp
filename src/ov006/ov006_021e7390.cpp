#include "ov006/ov006.h"
#include "ov006/Racer.h"

extern "C" {

#pragma force_active on
void Ov006Racer_RequestIdle(Ov006Racer *self) {
    ActorSub40 *p = self->fsm;
    if (p != NULL) {
        p->flags |= 2;
    }
}
#pragma force_active reset

}
