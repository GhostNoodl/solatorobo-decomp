#include "ov000/LoCommon.h"
#include "ov000/Obj0216c954.h"

extern "C" {

void func_ov000_0216c954(Obj0216c954 *self, u16 kind, s32 mode) {
    self->flags = 0;
    self->show = 0;
    self->state = 2;
    self->kind = kind;
    self->mode = mode;
    self->model = NULL;
    self->effect = NULL;
    self->range = 0;
    self->unk_18 = 0;
    self->count = 0;
    self->total = 0;
    self->part = 0xffff;
    self->findKind = 0xffff;
    self->frame = 0;
    self->ratio = 0;
    self->bounceFrame = 0;
    self->bounce = 0;
}

}
