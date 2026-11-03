#include "ov002/ov002.h"

extern "C" {

void Obj021efe7c_Create(void) {
    Obj021efe7c *p;
    if (data_ov002_021f0f90.top != NULL) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(data_ov002_021f0f90.top);
        HEAP_POP(saved);
    }
    p = (Obj021efe7c *)Heap_Alloc(sizeof(Obj021efe7c));
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021efe7c_vtbl;
        p->board = NULL;
        p->unk_08 = NULL;
        p->unk_0c = 0;
        p->unk_10 = 0;
    }
    data_ov002_021f0f90.top = p;
}

void Obj021efe7c_Delete(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(data_ov002_021f0f90.top);
    HEAP_POP(saved);
}

Obj021efe7c *Ov002Vt_021efe7c_DtorDelete(Obj021efe7c *self) {
    *(VFunc **)self = Ov002Vt_021efe7c_vtbl;
    Obj021efe7c_Release(self);
    Heap_Free(self);
    return self;
}

Obj021efe7c *Obj021efe7c_Get(void) {
    return data_ov002_021f0f90.top;
}

}
