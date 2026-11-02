#include "ov014/ov014.h"

extern "C" {

void func_ov014_02213ce4(void) {
}

void *func_ov014_02213ce8(Ov014Watch *self) {
    Heap_Free(self);
    return self;
}

}
