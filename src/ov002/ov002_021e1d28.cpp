#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e1d28(void *self) {
    u32 saved;
    void *p;
    s32 i;
    HEAP_PUSH(saved);
    p = FIELD(self, 0x4, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0x4, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = FIELD(self, 0x8, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0x8, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = FIELD(self, 0xc, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0xc, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = FIELD(self, 0x10, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0x10, void *) = NULL;
    }
    HEAP_POP(saved);
    for (i = 0; i < 5; i++) {
        u32 saved2;
        HEAP_PUSH(saved2);
        DELETE_VOBJ((&FIELD(self, 0x14, VObject *))[i]);
        HEAP_POP(saved2);
    }
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x28, VObject *));
    HEAP_POP(saved);
}

}
