#include "ov002/ov002.h"

extern "C" {

VObj *Ov002Vt_021f0f2c_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov002_021f0f2c;
    self->vfunc_0c();
    *(VFunc **)self = (VFunc *)data_0208b318;
    self->vfunc_0c();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e14_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov002_021f0e14;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e14_Dtor(VObj *self) {
    *(VFunc **)self = data_ov002_021f0e14;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0e84_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov002_021f0e84;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e84_Dtor(VObj *self) {
    *(VFunc **)self = data_ov002_021f0e84;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0ebc_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov002_021f0ebc;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0e4c;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0ebc_Dtor(VObj *self) {
    *(VFunc **)self = data_ov002_021f0ebc;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0e4c;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0e4c_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov002_021f0e4c;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

VObj *Ov002Vt_021f0e4c_Dtor(VObj *self) {
    *(VFunc **)self = data_ov002_021f0e4c;
    self->vfunc_14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0ef4_Dtor(VObj *self) {
    *(VFunc **)self = data_ov002_021f0ef4;
    self->vfunc_14();
    return self;
}

VObj *Ov002Vt_021f0f2c_Dtor(VObj *self) {
    *(VFunc **)self = data_ov002_021f0f2c;
    self->vfunc_0c();
    *(VFunc **)self = (VFunc *)data_0208b318;
    self->vfunc_0c();
    return self;
}

}
