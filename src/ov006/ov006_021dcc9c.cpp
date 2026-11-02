#include "ov006/ov006.h"
#include "ov006/Racer.h"

extern "C" {

void Ov006Marker_SetFrame(Ov006Marker *self, int idx, u8 flag) {
    if (idx < 0 || idx > 4) {
        return;
    }
    self->frame = idx;
    self->alt = flag;
}

}
