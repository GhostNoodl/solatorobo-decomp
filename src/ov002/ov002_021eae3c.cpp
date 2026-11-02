#include "ov002/ov002.h"

extern "C" {

void func_ov002_021eae3c(void *self) {
    func_ov002_021eae48(self);
}

void func_ov002_021eae48(void *self) {
    {
        void *saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x40, void *) != NULL) {
            Heap_FreeArray(FIELD(self, 0x40, void *));
            FIELD(self, 0x40, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x44, void *) != NULL) {
            Heap_FreeArray(FIELD(self, 0x44, void *));
            FIELD(self, 0x44, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x48, void *) != NULL) {
            Heap_FreeArray(FIELD(self, 0x48, void *));
            FIELD(self, 0x48, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x4c, void *) != NULL) {
            Heap_FreeArray(FIELD(self, 0x4c, void *));
            FIELD(self, 0x4c, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
}

}
