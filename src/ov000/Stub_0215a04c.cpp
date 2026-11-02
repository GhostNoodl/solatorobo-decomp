#include "ov000/ObjLayouts.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {


void func_ov000_0215a04c(Lo021cb5a8 *self) {
    self->unk_d4 = -1;
    self->dl = NULL;
    self->dlSize = 0;
}

void func_ov000_0215a064(Lo021cb5a8 *self) {
    if (self->dl != NULL) {
        Heap_FreeHi(self->dl);
        self->dl = NULL;
    }
}

}
