#include "ov002/ov002.h"

extern "C" {

VObject *func_ov002_021d5860(VObject *self) {
    *(VFunc **)self = data_ov000_021caec8;
    self->v0x2c();
    *(VFunc **)self = data_ov000_021cac60;
    self->v0x2c();
    func_0203de1c(self);
    return self;
}

void func_ov002_021d58ac(void) {
}

BOOL func_ov002_021d58b0(void) {
    return TRUE;
}

}
