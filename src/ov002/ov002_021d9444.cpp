#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d9444(void *self) {
    FIELD(self, 4, s32) = 0;
    func_02016e28((u8 *)self + 8, 0, 0x64);
    FIELD(self, 0x6c, s32) = 0;
    FIELD(self, 0x70, s32) = 0;
    FIELD(self, 0x74, u8) = 0;
    FIELD(self, 0x75, u8) = 0;
    func_02016e28((u8 *)self + 0x76, 0, 10);
    func_02016e28((u8 *)self + 0x80, 0, 10);
    FIELD(self, 0x8a, s16) = 0;
    FIELD(self, 0x8c, s32) = 0;
    FIELD(self, 0x90, s32) = 0;
    FIELD(self, 0x94, s32) = 0;
    FIELD(self, 0x98, s32) = 0;
    FIELD(self, 0x9c, s32) = 0;
    FIELD(self, 0xa0, s32) = 0;
    FIELD(self, 0xa4, s32) = 0;
    FIELD(self, 0xa8, s32) = 0;
    FIELD(self, 0xac, s32) = 0;
    FIELD(self, 0xb0, s32) = 0;
    FIELD(self, 0xb4, s32) = 0;
    FIELD(self, 0xb8, s32) = 0;
    FIELD(self, 0xbc, s32) = 0;
    FIELD(self, 0xc0, s32) = 0;
    FIELD(self, 0xc4, s32) = 0;
}

void *func_ov002_021d94dc(void *self) {
    *(VFunc **)self = data_ov002_021efe4c;
    func_ov002_021d6ec4(self);
    func_0203de1c(self);
    return self;
}

void func_ov002_021d9504(void *self) {
    VObject *o = FIELD(self, 0x6c, VObject *);
    while (o != NULL) {
        VObject *next = FIELD(o, 0x70, VObject *);
        u32 saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v0x4();
            }
        }
        HEAP_POP(saved);
        o = next;
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x70, void *) != NULL) {
            func_0203de1c(FIELD(self, 0x70, void *));
            FIELD(self, 0x70, void *) = NULL;
        }
        HEAP_POP(saved);
    }
}

void *func_ov002_021d959c(void *self) {
    func_ov002_021e0b08_inline(self);
    func_0203de1c(self);
    return self;
}

}
