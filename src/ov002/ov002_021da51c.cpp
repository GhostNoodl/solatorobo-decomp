#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efe6c_DtorDelete(Obj021efe6c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efe6c;
    Obj021efe6c_FreePieces(self);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (((void *)self->cam) != NULL) {
        Heap_Free(((void *)self->cam));
        self->cam = NULL;
    }
    HEAP_POP(saved);
    Heap_Free(self);
    return self;
}

}
