#include "ov000/VObj.h"

extern "C" {

void func_0204b438(void *ptr);
void Heap_Free(void *ptr);

void *func_ov000_02189b14(void *self) {
    func_0204b438(self);
    return self;
}

void *func_ov000_02189b28(void *self) {
    func_0204b438(self);
    Heap_Free(self);
    return self;
}

}
