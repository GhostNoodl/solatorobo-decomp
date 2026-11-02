#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ActorMarker.h"

extern "C" {

void ActorMarker_SetPos(ActorMarker *self, VecFx32 *v, s32 dy) {
    if (self->work.state == 10) {
        return;
    }
    self->flags |= 4;
    self->work.pos.x = v->x;
    self->work.pos.y = v->y;
    self->work.pos.z = v->z;
    self->work.pos.y += dy;
}

}
