#include "ov000/HeapScope.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void Lo021ccb54_FreeLabels(Lo021ccb54 *self) {
    HEAP_DELETE(UiLabel *, self->unk_f4, UiLabel_Release(p); Heap_Free(p));
    HEAP_DELETE(UiLabel *, self->unk_f8, UiLabel_Release(p); Heap_Free(p));
    HEAP_DELETE(UiLabel *, self->unk_fc, UiLabel_Release(p); Heap_Free(p));
}

}
