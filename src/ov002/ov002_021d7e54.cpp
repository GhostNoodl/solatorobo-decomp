#include "ov002/ov002.h"

extern "C" {

void Obj021efe9c_Init(Obj021efe9c *self) {
    self->unk_78 = NULL;
    self->unk_7c = NULL;
    self->unk_80 = NULL;
    self->unk_84 = 0;
    self->unk_88 = NULL;
    self->unk_8c = NULL;
    self->unk_90 = NULL;
    self->unk_94 = 0;
    self->unk_98 = 0;
    self->unk_9c = FX_Div(0x1f000, 0x1f000);
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 5;
    self->unk_ac = 0xb;
    self->unk_b0.x = 0;
    self->unk_b0.y = 0;
    self->unk_b0.z = 0;
    self->unk_bc.x = 0;
    self->unk_bc.y = 0;
    self->unk_bc.z = 0;
    self->unk_c8 = 0;
    self->unk_cc = 0;
    self->unk_cd = 0;
    self->unk_d0 = 0;
}

void Obj021efe9c_Release(Obj021efe9c *self) {
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
    Vram_FreeRes((void *)*self->unk_78);
}

void Ov002Vt_021efe9c_Setup(Obj021efe9c *self) {
    func_ov002_021d7c04_inline(self);
    if (self->unk_ac != 2) {
        self->unk_ac = 2;
        self->unk_a4 = 0;
        self->unk_a8 = 5;
    }
}

void Ov002Vt_021efe9c_Update(Obj021efe9c *self) {
    switch (self->unk_a0) {
    case 0:
        func_ov002_021d8148(self);
        self->unk_a0 = 0xa;
    case 0xa:
        if (self->unk_88 != NULL) {
            self->unk_88->frame = self->unk_94;
        }
        if (self->unk_8c != NULL) {
            self->unk_8c->frame = self->unk_94;
        }
        if (self->unk_90 != NULL) {
            ((NNSG3dAnmObj *)self->unk_90)->frame = self->unk_94; // this class's third animation
        }
        self->unk_94 = (self->unk_94 + 0x1000) % self->unk_98;
        break;
    }
}

}
