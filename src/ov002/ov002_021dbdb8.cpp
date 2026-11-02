#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dbdb8(Obj021eff10 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_08);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_0c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    {
        Model *p = self->unk_10;
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(&p->pltt);
                Heap_Free(p);
            }
            self->unk_10 = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_14);
    HEAP_POP(saved);
}

}
