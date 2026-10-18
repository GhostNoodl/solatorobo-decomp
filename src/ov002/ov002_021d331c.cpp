#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d331c(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x3c, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x40, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0xc4, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278((u8 *)p + 0x88);
                func_0203de1c(p);
            }
            FIELD(self, 0xc4, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc8, VObject *));
    HEAP_POP(saved);
    func_ov002_021e4b80((u8 *)self + 0xac);
}

}
