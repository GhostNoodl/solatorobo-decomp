#include "Main/Save/SaveBase.h"

extern "C" {

void *SaveBase_DtorDelete(SaveBase *s) {
    *(u32 **)s = data_0208b614;
    s->Finalize();
    Heap_Free(s);
    return s;
}

void *SaveBase_Dtor(SaveBase *s) {
    *(u32 **)s = data_0208b614;
    s->Finalize();
    return s;
}

}
