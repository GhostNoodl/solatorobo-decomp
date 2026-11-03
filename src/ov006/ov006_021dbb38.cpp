#include "ov006/Label.h"

extern "C" {

extern u8 Ov006Vt_021ec25c_vtbl[];
extern u8 ResHandle_vtbl[];

ov006_ResLoader *Ov006Vt_021ec25c_DtorDelete(ov006_ResLoader *self) {
    *(void **)self = Ov006Vt_021ec25c_vtbl;
    if (self->res.name[0] != 0 || self->res.arcName[0] != 0) {
        self->res.vfunc_0c();
    }
    self->res.vfunc_08();
    *(void **)&self->res = ResHandle_vtbl;
    self->res.vfunc_0c();
    Heap_Free(self);
    return self;
}

}
