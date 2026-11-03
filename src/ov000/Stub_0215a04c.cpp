#include "ov000/ObjLayouts.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {


void Lo021cb5a8_Init(Lo021cb5a8 *self) {
    self->unk_d4 = -1;
    self->dl = NULL;
    self->dlSize = 0;
}

void Lo021cb5a8_Release(Lo021cb5a8 *self) {
    if (self->dl != NULL) {
        Heap_FreeHi(self->dl);
        self->dl = NULL;
    }
}

}
