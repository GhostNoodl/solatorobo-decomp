#include "ov002/ov002.h"

extern "C" {

void Obj021efed4_Init(Obj021efed4 *self) {
    self->unk_78 = NULL;
    self->unk_7c = NULL;
    self->unk_80 = NULL;
    self->unk_84 = NULL;
    self->unk_88 = NULL;
    self->unk_8c = NULL;
    self->unk_90 = NULL;
    self->unk_94 = 0;
    self->unk_98 = 0;
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0x1000;
    self->unk_a8 = 0;
    self->unk_ac = 0;
    self->unk_b0 = NULL;
}

void Obj021efed4_Release(Obj021efed4 *self) {
    Vram_FreeRes((void *)*self->unk_78);
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
                    TexObj_Release((Model *)p);
                    PlttRes_Release((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                self->unk_90 = NULL;
            }
        }
        HEAP_POP(saved);
    }
}

void Ov002Vt_021efed4_Setup(Obj021efed4 *self) {
    func_ov002_021d7c04_inline(self);
    self->unk_a8 = Param_GetEntry(self->unk_48)[2];
}

}
