#include "ov006/Label.h"

extern "C" {

extern u8 data_ov006_021ec25c[];
extern u8 data_0208b318[];

ov006_ResLoader *Ov006Vt_021ec25c_Dtor(ov006_ResLoader *self) {
    *(void **)self = data_ov006_021ec25c;
    if (self->res.name[0] != 0 || self->res.arcName[0] != 0) {
        self->res.vfunc_0c();
    }
    self->res.vfunc_08();
    *(void **)&self->res = data_0208b318;
    self->res.vfunc_0c();
    return self;
}

}
