#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021f0674_Dtor(Ov002Stage *self) {
    *(VFunc **)self = Ov002Vt_021f0674_vtbl;
    Ov002Stage_Release(self);
    *(VFunc **)&self->file = Ov002Vt_021f0684_vtbl;
    func_ov002_021eae3c(&self->file);
    return self;
}

void *Ov002Vt_021f0694_DtorDelete(Ov002Obj *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0694_Dtor(Ov002Obj *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f06e4_DtorDelete(Ov002Obj021f06e4 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f06e4_Dtor(Ov002Obj021f06e4 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f07fc_DtorDelete(Ov002Cam021f07fc *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f07fc_Dtor(Ov002Cam021f07fc *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0828_DtorDelete(Ov002Cam021f0828 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0828_Dtor(Ov002Cam021f0828 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0854_DtorDelete(Ov002Cam021f0854 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0854_Dtor(Ov002Cam021f0854 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0784_DtorDelete(Ov002Obj021f0784 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0784_Dtor(Ov002Obj021f0784 *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f07ac_DtorDelete(Ov002Obj021f07ac *self) {
    *(VFunc **)self = Ov002Vt_021f07ac_vtbl;
    if (self->unk_14 != 0) {
        ResMgr_ReleaseArchive(self->unk_4c, self->unk_6c, 0);
    }
    gGfxMgr->unk_010 = 1;
    Ov002Vt_021f0ce8_Dtor(&self->msg);
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f07ac_Dtor(Ov002Obj021f07ac *self) {
    *(VFunc **)self = Ov002Vt_021f07ac_vtbl;
    if (self->unk_14 != 0) {
        ResMgr_ReleaseArchive(self->unk_4c, self->unk_6c, 0);
    }
    gGfxMgr->unk_010 = 1;
    Ov002Vt_021f0ce8_Dtor(&self->msg);
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    return self;
}

}
