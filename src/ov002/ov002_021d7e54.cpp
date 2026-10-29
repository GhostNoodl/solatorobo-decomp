#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d7e54(void *self) {
    FIELD(self, 0x78, s32) = 0;
    FIELD(self, 0x7c, s32) = 0;
    FIELD(self, 0x80, s32) = 0;
    FIELD(self, 0x84, s32) = 0;
    FIELD(self, 0x88, s32) = 0;
    FIELD(self, 0x8c, s32) = 0;
    FIELD(self, 0x90, s32) = 0;
    FIELD(self, 0x94, s32) = 0;
    FIELD(self, 0x98, s32) = 0;
    FIELD(self, 0x9c, s32) = FX_Div(0x1f000, 0x1f000);
    FIELD(self, 0xa0, s32) = 0;
    FIELD(self, 0xa4, s32) = 0;
    FIELD(self, 0xa8, s32) = 5;
    FIELD(self, 0xac, s32) = 0xb;
    FIELD(self, 0xb0, s32) = 0;
    FIELD(self, 0xb4, s32) = 0;
    FIELD(self, 0xb8, s32) = 0;
    FIELD(self, 0xbc, s32) = 0;
    FIELD(self, 0xc0, s32) = 0;
    FIELD(self, 0xc4, s32) = 0;
    FIELD(self, 0xc8, s32) = 0;
    FIELD(self, 0xcc, u8) = 0;
    FIELD(self, 0xcd, u8) = 0;
    FIELD(self, 0xd0, s32) = 0;
}

void func_ov002_021d7ed8(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    if (FIELD(self, 0x80, void *) != NULL) {
        func_0203de1c(FIELD(self, 0x80, void *));
        FIELD(self, 0x80, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (FIELD(self, 0x88, void *) != NULL) {
        func_0203de1c(FIELD(self, 0x88, void *));
        FIELD(self, 0x88, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (FIELD(self, 0x8c, void *) != NULL) {
        func_0203de1c(FIELD(self, 0x8c, void *));
        FIELD(self, 0x8c, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (FIELD(self, 0x90, void *) != NULL) {
        func_0203de1c(FIELD(self, 0x90, void *));
        FIELD(self, 0x90, void *) = NULL;
    }
    HEAP_POP(saved);
    func_0203f0b4(*FIELD(self, 0x78, void **));
}

void func_ov002_021d7fb8(void *self) {
    func_ov002_021d7c04_inline(self);
    if (FIELD(self, 0xac, s32) != 2) {
        FIELD(self, 0xac, s32) = 2;
        FIELD(self, 0xa4, s32) = 0;
        FIELD(self, 0xa8, s32) = 5;
    }
}

void func_ov002_021d802c(void *self) {
    switch (FIELD(self, 0xa0, s32)) {
    case 0:
        func_ov002_021d8148(self);
        FIELD(self, 0xa0, s32) = 0xa;
    case 0xa:
        if (FIELD(self, 0x88, s32 *) != NULL) {
            *FIELD(self, 0x88, s32 *) = FIELD(self, 0x94, s32);
        }
        if (FIELD(self, 0x8c, s32 *) != NULL) {
            *FIELD(self, 0x8c, s32 *) = FIELD(self, 0x94, s32);
        }
        if (FIELD(self, 0x90, s32 *) != NULL) {
            *FIELD(self, 0x90, s32 *) = FIELD(self, 0x94, s32);
        }
        FIELD(self, 0x94, s32) = (FIELD(self, 0x94, s32) + 0x1000) % FIELD(self, 0x98, s32);
        break;
    }
}

}
