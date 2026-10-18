#include "ov002/ov002.h"

extern "C" {

VObject *func_ov002_021dded4(VObject *self) {
    *(VFunc **)self = data_ov000_021ccbe0;
    func_ov000_021c3bb0(self);
    *(VFunc **)self = data_ov000_021cac60;
    self->v0x2c();
    func_0203de1c(self);
    return self;
}

}
