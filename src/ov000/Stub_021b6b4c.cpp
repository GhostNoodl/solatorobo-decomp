#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/FieldMgr.h"

extern "C" {

void func_ov000_021b6b4c(FieldMgr *self, u16 id, const VecFx32 *v) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (id == self->ids[i]) {
            self->vecs[i] = *v;
            return;
        }
    }
    for (i = 0; i < 0x20; i++) {
        if (self->ids[i] == 0xffff) {
            self->ids[i] = id;
            self->vecs[i] = *v;
            return;
        }
    }
}

}
