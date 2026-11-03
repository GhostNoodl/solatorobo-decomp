#include "ov002/ov002.h"

extern "C" {

VObj *Ov002Vt_021f0f2c_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0f2c_vtbl;
    self->vfunc_0c();
    *(VFunc **)self = (VFunc *)ResHandle_vtbl;
    self->vfunc_0c();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e14_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0e14_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e14_Dtor(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0e14_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0e84_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0e84_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e84_Dtor(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0e84_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0ebc_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0ebc_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0e4c_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0ebc_Dtor(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0ebc_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0e4c_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0e4c_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0e4c_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e4c_Dtor(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0e4c_vtbl;
    self->vfunc_14();
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0ef4_Dtor(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0f2c_Dtor(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0f2c_vtbl;
    self->vfunc_0c();
    *(VFunc **)self = (VFunc *)ResHandle_vtbl;
    self->vfunc_0c();
    return self;
}

}
