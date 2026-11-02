#include "ov006/Label.h"

extern "C" {

void ov006_Label_Close(ov006_Label *self) {
    self->unkE8 = 1;
}

}
