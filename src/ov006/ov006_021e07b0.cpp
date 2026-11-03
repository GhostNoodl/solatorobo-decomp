#include "ov006/ov006.h"
#include "ov006/Caption.h"


extern "C" {

ov006_Caption *ov006_Caption_Ctor(ov006_Caption *self) {
    self->vtbl = ov006_Caption_vtbl;
    self->visible = 0;
    self->x = 0;
    self->y = 0;
    self->textX = 0;
    self->textY = 0;
    self->ofsX = 0;
    self->ofsY = 0;
    self->kind = 0;
    self->model = NULL;
    self->label = NULL;
    return self;
}

}
