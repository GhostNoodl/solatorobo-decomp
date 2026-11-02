#include "ov006/Marker.h"

extern "C" {

BOOL func_02054f10(void *a, int b);

void ov006_MarkerSet_Update(ov006_MarkerSet *self) {
    int i;
    if (!self->unk4) {
        if (self->model == NULL) {
            return;
        }
        if (!func_02054f10(self->model, 0xffff)) {
            return;
        }
        self->unk4 = 1;
    }
    for (i = 0; i < 4; i++) {
        ov006_Marker_Update(&self->markers[i]);
    }
}

}
