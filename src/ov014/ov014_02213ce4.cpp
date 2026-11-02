#include "ov014/ov014.h"

extern "C" {

void func_ov014_02213ce4(void) {
}

void *Ov014Watch_DtorDelete(Ov014Watch *self) {
    Heap_Free(self);
    return self;
}

}
