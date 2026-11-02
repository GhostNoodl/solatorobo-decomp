#include "ov006/ov006.h"
#include "ov006/Racer.h"
#include "nitro/fx.h"

extern "C" {

BOOL Model_IsReady(Model *a, int b);

void Ov006Marker_Update(Ov006Marker *self) {
    VecFx32 d;
    if (!self->active) {
        if (self->model == NULL) {
            return;
        }
        if (!Model_IsReady(self->model, 0xffff)) {
            return;
        }
        self->active = 1;
    }
    if (self->smooth) {
        d.x = self->target.x - self->cur.x;
        d.y = self->target.y - self->cur.y;
        d.z = self->target.z - self->cur.z;
        VEC_MultAdd(0x466, &d, &self->cur, &self->cur);
    } else {
        self->cur.x = self->target.x;
        self->cur.y = self->target.y;
        self->cur.z = self->target.z;
    }
}

}
