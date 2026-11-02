#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021f070c_DtorDelete(Ov002Obj021f070c *self) {
    int i;
    *(VFunc **)self = data_ov002_021f070c;
    for (i = 0; i < 4; i++) {
        EffectObj *o = func_020657b0(data_0214a420, ((u32 *)((u8 *)self + 0x50))[i]);
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f070c_Dtor(Ov002Obj021f070c *self) {
    int i;
    *(VFunc **)self = data_ov002_021f070c;
    for (i = 0; i < 4; i++) {
        EffectObj *o = func_020657b0(data_0214a420, ((u32 *)((u8 *)self + 0x50))[i]);
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f075c_DtorDelete(Ov002Obj021f075c *self) {
    *(VFunc **)self = data_ov002_021f075c;
    func_ov002_021e5d88(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void func_ov002_021eaaa4(void) {
}

void *Ov002Vt_021f075c_Dtor(Ov002Obj021f075c *self) {
    *(VFunc **)self = data_ov002_021f075c;
    func_ov002_021e5d88(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f07d4_DtorDelete(Ov002Obj021f07d4 *self) {
    *(VFunc **)self = data_ov002_021f07d4;
    func_ov002_021e51f8(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f07d4_Dtor(Ov002Obj021f07d4 *self) {
    *(VFunc **)self = data_ov002_021f07d4;
    func_ov002_021e51f8(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0734_Dtor(Ov002Obj *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0684_DtorDelete(Ov002StageFile *self) {
    *(VFunc **)self = data_ov002_021f0684;
    func_ov002_021eae3c(self);
    Heap_Free(self);
    return self;
}

void func_ov002_021eacd0(Ov002StageFile *self) {
    self->unk_04 = NULL;
    self->data = NULL;
    MIi_CpuClear32(0, (u8 *)self + 0x10, 0x30);
    self->links = NULL;
    self->unk_44 = NULL;
    self->unk_48 = NULL;
    self->unk_4c = NULL;
    self->linkCount = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = NULL;
}

}
