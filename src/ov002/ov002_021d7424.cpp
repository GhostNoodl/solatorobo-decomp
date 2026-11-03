#include "ov002/ov002.h"

extern "C" {

void Ov002_PlaySe(int se) {
    SndMgr_PlayVolume(gSndMgr, se, -1, -1, -1);
}

Ov002Mdl021efe3c *Ov002Vt_021efe3c_Ctor(Ov002Mdl021efe3c *self) {
    *(VFunc **)self = Ov002Vt_021efe3c_vtbl;
    self->arc = NULL;
    self->name = NULL;
    self->anmName = NULL;
    self->file = NULL;
    self->mdl = NULL;
    self->renderObj = NULL;
    self->texTask = 0;
    self->anm[0] = NULL;
    self->anm[1] = NULL;
    self->anm[2] = NULL;
    self->frame = 0;
    self->frameCount = 0;
    self->trans.x = 0;
    self->trans.y = 0;
    self->trans.z = 0;
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    MTX_Identity33_(&self->rot);
    return self;
}

Ov002Mdl021efe3c *Ov002Vt_021efe3c_Dtor(Ov002Mdl021efe3c *self) {
    *(VFunc **)self = Ov002Vt_021efe3c_vtbl;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->renderObj != NULL) {
            Heap_Free(self->renderObj);
            self->renderObj = NULL;
        }
        HEAP_POP(saved);
    }
    if (self->anm[0] != NULL) {
        Heap_FreeHi(self->anm[0]);
        self->anm[0] = NULL;
    }
    if (self->anm[1] != NULL) {
        Heap_FreeHi(self->anm[1]);
        self->anm[1] = NULL;
    }
    if (self->anm[2] != NULL) {
        Heap_FreeHi(self->anm[2]);
        self->anm[2] = NULL;
    }
    Vram_FreeRes(self->file->data);
    return self;
}

Ov002Mdl021efe3c *Ov002Vt_021efe3c_DtorDelete(Ov002Mdl021efe3c *self) {
    *(VFunc **)self = Ov002Vt_021efe3c_vtbl;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->renderObj != NULL) {
            Heap_Free(self->renderObj);
            self->renderObj = NULL;
        }
        HEAP_POP(saved);
    }
    if (self->anm[0] != NULL) {
        Heap_FreeHi(self->anm[0]);
        self->anm[0] = NULL;
    }
    if (self->anm[1] != NULL) {
        Heap_FreeHi(self->anm[1]);
        self->anm[1] = NULL;
    }
    if (self->anm[2] != NULL) {
        Heap_FreeHi(self->anm[2]);
        self->anm[2] = NULL;
    }
    Vram_FreeRes(self->file->data);
    Heap_Free(self);
    return self;
}

}
