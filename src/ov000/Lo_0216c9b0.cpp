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
            func_ov000_021c216c(p);
            Heap_Free(p);
        }
        self->effect = NULL;
    }
    LO_HEAP_POP(saved);
    HEAP_DELETE_MODEL(self->model);
    func_ov000_0216c954(self, 0, 0);
}

}
