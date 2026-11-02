#include "ov002/ov002.h"

extern "C" {

void func_ov002_021deb2c(Obj021efef0 *self, Obj021eff50 *dst) {
    void *node = FIELD(self, 0x24, void *);
    u16 id;
    if (node != NULL) {
        id = FIELD(node, 0x38, u16);
    } else {
        id = 0xffff;
    }
    dst->unk_28 = self->unk_2c;
    dst->unk_2c = self->unk_30;
    dst->unk_30 = id;
    Obj021efef0_Release(self);
}

}
