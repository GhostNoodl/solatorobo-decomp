#include "ov002/ov002.h"

extern "C" {

Obj021efe8c *Ov002Vt_021efe8c_Dtor(Obj021efe8c *self) {
    Ov002Vt_021efe3c_Dtor(&self->mdl);
    return self;
}

Obj021efe8c *Ov002Vt_021efe8c_DtorDelete(Obj021efe8c *self) {
    Ov002Vt_021efe3c_Dtor(&self->mdl);
    Heap_Free(self);
    return self;
}

void Obj021efe8c_SyncAnmFrame(Obj021efe8c *self) {
    s32 v = self->mdl.frame;
    if (self->mdl.anm[0] != NULL) {
        self->mdl.anm[0]->frame = v;
    }
    if (self->mdl.anm[1] != NULL) {
        self->mdl.anm[1]->frame = v;
    }
    if (self->mdl.anm[2] != NULL) {
        self->mdl.anm[2]->frame = v;
    }
    self->mdl.frame = (self->mdl.frame + 0x1000) % self->mdl.frameCount;
}

Obj021efe5c *Ov002Vt_021efe5c_Dtor(Obj021efe5c *self) {
    TexObj_Release(&self->model);
    PlttRes_Release(&self->model.pltt);
    Ov002Vt_021efe3c_Dtor(&self->mdl);
    return self;
}

Obj021efe5c *Ov002Vt_021efe5c_DtorDelete(Obj021efe5c *self) {
    TexObj_Release(&self->model);
    PlttRes_Release(&self->model.pltt);
    Ov002Vt_021efe3c_Dtor(&self->mdl);
    Heap_Free(self);
    return self;
}

void Obj021efe5c_SyncAnmFrame(Obj021efe5c *self) {
    s32 v = self->mdl.frame;
    if (self->mdl.anm[0] != NULL) {
        self->mdl.anm[0]->frame = v;
    }
    if (self->mdl.anm[1] != NULL) {
        self->mdl.anm[1]->frame = v;
    }
    if (self->mdl.anm[2] != NULL) {
        self->mdl.anm[2]->frame = v;
    }
    self->mdl.frame = (self->mdl.frame + 0x1000) % self->mdl.frameCount;
    self->unk_1d8 = (u16)(self->unk_1d8 + 1);
}

}
