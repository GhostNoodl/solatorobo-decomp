#include "ov002/ov002.h"

extern "C" {

void Obj021efe6c_Init(Obj021efe6c *self) {
    self->field = NULL;
    MI_CpuFill8((u8 *)self + 8, 0, 0x64);
    self->pieces = NULL;
    self->cells = NULL;
    self->unk_74 = 0;
    self->unk_75 = 0;
    MI_CpuFill8((u8 *)self + 0x76, 0, 10);
    MI_CpuFill8((u8 *)self + 0x80, 0, 10);
    self->unk_8a = 0;
    self->cam = NULL;
    self->unk_90 = 0;
    self->unk_94 = 0;
    self->unk_98.x = 0;
    self->unk_98.y = 0;
    self->unk_98.z = 0;
    self->unk_a4.x = 0;
    self->unk_a4.y = 0;
    self->unk_a4.z = 0;
    self->unk_b0.x = 0;
    self->unk_b0.y = 0;
    self->unk_b0.z = 0;
    self->unk_bc.x = 0;
    self->unk_bc.y = 0;
    self->unk_bc.z = 0;
}

void *Ov002Vt_021efe4c_DtorDelete(Obj021efe4c *self) {
    *(VFunc **)self = data_ov002_021efe4c;
    Obj021efe4c_Release(self);
    Heap_Free(self);
    return self;
}

void Obj021efe6c_FreePieces(Obj021efe6c *self) {
    Obj021efeb8 *o = self->pieces;
    while (o != NULL) {
        Obj021efeb8 *next = o->next;
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->vfunc_04();
            }
        }
        HEAP_POP(saved);
        o = next;
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (((void *)self->cells) != NULL) {
            Heap_Free(((void *)self->cells));
            self->cells = NULL;
        }
        HEAP_POP(saved);
    }
}

void *Ov002Vt_021efeb8_DtorDelete(Obj021efeb8 *self) {
    func_ov002_021e0b08_inline(self);
    Heap_Free(self);
    return self;
}

}
