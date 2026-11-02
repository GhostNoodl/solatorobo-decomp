#include "ov006/Marker.h"

extern "C" {

BOOL Model_IsReady(void *a, int b);

void ov006_MarkerSet_Update(ov006_MarkerSet *self) {
    int i;
    if (!self->unk4) {
        if (self->model == NULL) {
            return;
        }
        if (!Model_IsReady(self->model, 0xffff)) {
            return;
        }
        self->unk4 = 1;
    }
    for (i = 0; i < 4; i++) {
        ov006_Marker_Update(&self->markers[i]);
    }
}

}
