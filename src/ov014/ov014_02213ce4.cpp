#include "ov014/ov014.h"

extern "C" {

void Ov014Watch_Dtor(void) {
}

void *Ov014Watch_DtorDelete(Ov014Watch *self) {
    Heap_Free(self);
    return self;
}

}
