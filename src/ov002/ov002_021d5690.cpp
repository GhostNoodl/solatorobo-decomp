#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efb04_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021efb04;
    MsgBox_Release(self);
    Heap_Free(self);
    return self;
}

}
