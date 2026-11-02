#include "ov002/ov002.h"

extern "C" {

VObject *Ov002Vt_021f0f2c_DtorDelete(VObject *self) {
    *(VFunc **)self = data_ov002_021f0f2c;
    self->v0xc();
    *(VFunc **)self = (VFunc *)data_0208b318;
    self->v0xc();
    Heap_Free(self);
    return self;
}

VObject *Ov002Vt_021f0e14_DtorDelete(VObject *self) {
    *(VFunc **)self = data_ov002_021f0e14;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    Heap_Free(self);
    return self;
}

VObject *Ov002Vt_021f0e14_Dtor(VObject *self) {
    *(VFunc **)self = data_ov002_021f0e14;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    return self;
}

VObject *Ov002Vt_021f0e84_DtorDelete(VObject *self) {
    *(VFunc **)self = data_ov002_021f0e84;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    Heap_Free(self);
    return self;
}

VObject *Ov002Vt_021f0e84_Dtor(VObject *self) {
    *(VFunc **)self = data_ov002_021f0e84;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    return self;
}

VObject *Ov002Vt_021f0ebc_DtorDelete(VObject *self) {
    *(VFunc **)self = data_ov002_021f0ebc;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0e4c;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    Heap_Free(self);
    return self;
}

VObject *Ov002Vt_021f0ebc_Dtor(VObject *self) {
    *(VFunc **)self = data_ov002_021f0ebc;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0e4c;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    return self;
}

VObject *Ov002Vt_021f0e4c_DtorDelete(VObject *self) {
    *(VFunc **)self = data_ov002_021f0e4c;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    Heap_Free(self);
    return self;
}

VObject *Ov002Vt_021f0e4c_Dtor(VObject *self) {
    *(VFunc **)self = data_ov002_021f0e4c;
    self->v0x14();
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    return self;
}

VObject *Ov002Vt_021f0ef4_Dtor(VObject *self) {
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    return self;
}

VObject *Ov002Vt_021f0f2c_Dtor(VObject *self) {
    *(VFunc **)self = data_ov002_021f0f2c;
    self->v0xc();
    *(VFunc **)self = (VFunc *)data_0208b318;
    self->v0xc();
    return self;
}

}
