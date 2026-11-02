#include "types.h"
#include "nnsys/g3d.h"
#include "ov000/FieldMgr.h"

extern "C" {

static inline void Advance021b7838(FieldPropModel *self, NNSG3dAnmObj *a, s32 step) {
    s32 max;
    if (a != NULL) {
        a->frame += step;
        max = (((NNSG3dResAnmCommon *)a->resAnm)->numFrame << 12) - 0x1000;
        if (a->frame >= max) {
            if (self->loop) {
                max = 0;
            }
            a->frame = max;
        }
    }
}

void FieldPropModel_UpdateAnim(FieldPropModel *self, s32 speed) {
    s32 step;
    if (self->stop) {
        return;
    }
    if (self->res->anm == NULL) {
        return;
    }
    if (self->cur != 0) {
        return;
    }
    if (speed == 0x1000) {
        step = self->speed;
    } else if (self->speed == 0x1000) {
        step = speed;
    } else {
        step = (s16)(((s64)self->speed * speed + 0x800) >> 12);
    }
    Advance021b7838(self, self->anm[0], step);
    Advance021b7838(self, self->anm[1], step);
    Advance021b7838(self, self->anm[2], step);
    Advance021b7838(self, self->anm[3], step);
    Advance021b7838(self, self->anm[4], step);
}
}
