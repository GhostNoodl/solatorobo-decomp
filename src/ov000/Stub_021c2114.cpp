#include "ov000/VObj.h"
#include "ov000/Obj0216c954.h"

extern "C" {

void Obj021c2114_Ctor(Obj021c2114 *self) {
    self->flags = 0;
    self->state = 1;
    self->res = NULL;
    self->model = NULL;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->rx = 0;
    self->ry = 0;
    self->rz = 0;
    self->ofs.x = 0;
    self->ofs.y = 0;
    self->ofs.z = 0;
    self->target.x = 0;
    self->target.y = 0;
    self->target.z = 0;
    self->fadeFrame = 0;
    self->fade = 0;
    self->pulseFrame = 0;
    self->pulse = 0;
}

}
