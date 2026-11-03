#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021f070c_DtorDelete(Ov002Obj021f070c *self) {
    int i;
    *(VFunc **)self = Ov002Vt_021f070c_vtbl;
    for (i = 0; i < 4; i++) {
        EffectObj *o = Effect_Find_020657b0(gEffectMgr, ((u32 *)((u8 *)self + 0x50))[i]);
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f070c_Dtor(Ov002Obj021f070c *self) {
    int i;
    *(VFunc **)self = Ov002Vt_021f070c_vtbl;
    for (i = 0; i < 4; i++) {
        EffectObj *o = Effect_Find_020657b0(gEffectMgr, ((u32 *)((u8 *)self + 0x50))[i]);
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f075c_DtorDelete(Ov002Obj021f075c *self) {
    *(VFunc **)self = Ov002Vt_021f075c_vtbl;
    Ov002Obj021f075c_FreeAnims(self);
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void Ov002Obj021f075c_Draw(void) {
}

void *Ov002Vt_021f075c_Dtor(Ov002Obj021f075c *self) {
    *(VFunc **)self = Ov002Vt_021f075c_vtbl;
    Ov002Obj021f075c_FreeAnims(self);
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f07d4_DtorDelete(Ov002Obj021f07d4 *self) {
    *(VFunc **)self = Ov002Vt_021f07d4_vtbl;
    Ov002Obj021f07d4_Release(self);
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f07d4_Dtor(Ov002Obj021f07d4 *self) {
    *(VFunc **)self = Ov002Vt_021f07d4_vtbl;
    Ov002Obj021f07d4_Release(self);
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0734_Dtor(Ov002Obj *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0684_DtorDelete(Ov002StageFile *self) {
    *(VFunc **)self = Ov002Vt_021f0684_vtbl;
    Ov002StageFile_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov002StageFile_Init(Ov002StageFile *self) {
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
