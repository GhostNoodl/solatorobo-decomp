#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dbdb8(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x8, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0x10, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278((u8 *)p + 0x88);
                func_0203de1c(p);
            }
            FIELD(self, 0x10, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x14, VObject *));
    HEAP_POP(saved);
}

}
