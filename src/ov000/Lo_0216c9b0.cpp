#include "ov000/LoCommon.h"
#include "ov000/Obj0216c954.h"

extern "C" {

void Obj0216c9b0_Release(Obj0216c954 *self) {
    u32 saved;
    Obj021c2114 *p;
    LO_HEAP_PUSH(saved);
    p = self->effect;
    if (p) {
        if (p) {
            Obj021c2114_Release(p);
            Heap_Free(p);
        }
        self->effect = NULL;
    }
    LO_HEAP_POP(saved);
    HEAP_DELETE_MODEL(self->model);
    Obj0216c954_Init(self, 0, 0);
}

}
