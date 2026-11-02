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

void func_ov002_021d7ed8(Obj021efe9c *self) {
    void *saved;
    HEAP_PUSH(saved);
    if (self->unk_80 != NULL) {
        Heap_Free(self->unk_80);
        self->unk_80 = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (self->unk_88 != NULL) {
        Heap_Free(self->unk_88);
        self->unk_88 = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (self->unk_8c != NULL) {
        Heap_Free(self->unk_8c);
        self->unk_8c = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    if (self->unk_90 != NULL) {
        Heap_Free(self->unk_90);
        self->unk_90 = NULL;
    }
    HEAP_POP(saved);
    func_0203f0b4(*FIELD(self, 0x78, void **));
}

void func_ov002_021d7fb8(Obj021efe9c *self) {
    func_ov002_021d7c04_inline(self);
    if (self->unk_ac != 2) {
        self->unk_ac = 2;
        self->unk_a4 = 0;
        self->unk_a8 = 5;
    }
}

void func_ov002_021d802c(Obj021efe9c *self) {
    switch (self->unk_a0) {
    case 0:
        func_ov002_021d8148(self);
        self->unk_a0 = 0xa;
    case 0xa:
        if (FIELD(self, 0x88, s32 *) != NULL) {
            *FIELD(self, 0x88, s32 *) = self->unk_94;
        }
        if (FIELD(self, 0x8c, s32 *) != NULL) {
            *FIELD(self, 0x8c, s32 *) = self->unk_94;
        }
        if (FIELD(self, 0x90, s32 *) != NULL) {
            *FIELD(self, 0x90, s32 *) = self->unk_94;
        }
        self->unk_94 = (self->unk_94 + 0x1000) % self->unk_98;
        break;
    }
}

}
