#include "ov000/ObjLayouts.h"

extern "C" {

void Lo021cae48_PreUpdate(Lo021cae48 *self) {
    if (self->state == 0) {
        self->shown = self->value;
    }
}

}
