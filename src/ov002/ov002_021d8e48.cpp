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

void func_ov002_021d8e90(Obj021efed4 *self) {
    func_0203f0b4(*FIELD(self, 0x78, void **));
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->unk_80 != NULL) {
            Heap_Free(self->unk_80);
            self->unk_80 = NULL;
        }
        HEAP_POP(saved);
    }
    if (self->unk_88 != NULL) {
        Heap_FreeHi(self->unk_88);
        self->unk_88 = NULL;
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            void *p = self->unk_90;
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558((Model *)p);
                    func_02041278((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                self->unk_90 = NULL;
            }
        }
        HEAP_POP(saved);
    }
}

void func_ov002_021d8f4c(Obj021efed4 *self) {
    func_ov002_021d7c04_inline(self);
    self->unk_a8 = func_0206ede8(self->unk_48)[2];
}

}
