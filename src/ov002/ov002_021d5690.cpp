#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efb04_DtorDelete(void *self) {
    *(VFunc **)self = Ov002Vt_021efb04_vtbl;
    MsgBox_Release(self);
    Heap_Free(self);
    return self;
}

}
