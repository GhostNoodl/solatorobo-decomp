#include "ov000/LoCommon.h"
#include "ov000/Obj0216ad04.h"

extern "C" {

void Obj0216ad04_Release(Obj0216ad04 *self) {
    HEAP_DELETE_MODEL(self->model);
    self->flags = 0;
    self->state = 2;
    self->kind = -1;
    self->model = 0;
    self->value = 0;
    self->part = 0;
    self->frame = 0;
    self->ratio = 0;
}

}
