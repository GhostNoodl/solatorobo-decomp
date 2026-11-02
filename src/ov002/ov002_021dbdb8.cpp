#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dbdb8(Obj021eff10 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x8, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    {
        void *p = self->unk_10;
        if (p != NULL) {
            if (p != NULL) {
                func_02041558((Model *)p);
                func_02041278((PlttRes *)((u8 *)p + 0x88));
                Heap_Free(p);
            }
            self->unk_10 = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x14, VObj *));
    HEAP_POP(saved);
}

}
