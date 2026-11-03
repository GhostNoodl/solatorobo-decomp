#include "ov002/ov002.h"
#include "ov002/StaffRoll.h"

extern "C" {

void Ov002Vt_021f0f2c_Clear(Ov002StaffLoader *self) {
    self->type = 0;
    self->script = NULL;
}

void Ov002Vt_021f0f2c_Unload(void) {
}

}
