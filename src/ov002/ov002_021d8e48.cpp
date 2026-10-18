#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d8e48(void *self) {
    FIELD(self, 0x78, s32) = 0;
    FIELD(self, 0x7c, s32) = 0;
    FIELD(self, 0x80, s32) = 0;
    FIELD(self, 0x84, s32) = 0;
    FIELD(self, 0x88, s32) = 0;
    FIELD(self, 0x8c, s32) = 0;
    FIELD(self, 0x90, s32) = 0;
    FIELD(self, 0x94, u8) = 0;
    FIELD(self, 0x98, s32) = 0;
    FIELD(self, 0x9c, u8) = 0;
    FIELD(self, 0xa0, s32) = 0;
    FIELD(self, 0xa4, s32) = 0x1000;
    FIELD(self, 0xa8, s16) = 0;
    FIELD(self, 0xac, s32) = 0;
    FIELD(self, 0xb0, s32) = 0;
}

void func_ov002_021d8e90(void *self) {
    func_0203f0b4(*FIELD(self, 0x78, void **));
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x80, void *) != NULL) {
            func_0203de1c(FIELD(self, 0x80, void *));
            FIELD(self, 0x80, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    if (FIELD(self, 0x88, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x88, void *));
        FIELD(self, 0x88, void *) = NULL;
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            void *p = FIELD(self, 0x90, void *);
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558(p);
                    func_02041278((u8 *)p + 0x88);
                    func_0203de1c(p);
                }
                FIELD(self, 0x90, void *) = NULL;
            }
        }
        HEAP_POP(saved);
    }
}

void func_ov002_021d8f4c(void *self) {
    func_ov002_021d7c04_inline(self);
    FIELD(self, 0xa8, u16) = func_0206ede8(FIELD(self, 0x48, u16))[2];
}

}
