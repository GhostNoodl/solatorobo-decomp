#include "ov002/ov002.h"

extern "C" {

void Obj021efef0_Exit(Obj021efef0 *self, Obj021eff50 *dst) {
    Obj021f002c *node = (Obj021f002c *)self->unk_24;
    u16 id;
    if (node != NULL) {
        id = node->id;
    } else {
        id = 0xffff;
    }
    dst->unk_28 = self->unk_2c;
    dst->unk_2c = self->unk_30;
    dst->unk_30 = id;
    Obj021efef0_Release(self);
}

}
