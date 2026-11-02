#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e2f04(Model *self, void *unused, u8 *entries, u16 *count) {
    u16 n = *count;
    int i;
    for (i = 0; i < n; i++) {
        Bits021e2f04 *e = (Bits021e2f04 *)(entries + i * 8 + 4);
        e->nib = FIELD(self, 0x70, s32) + e->nib;
    }
    *count = n;
    return entries;
}

void func_ov002_021e2f54(Obj021f002c *self) {
    self->height = 0xf;
    self->width = 0x78;
    self->model = NULL;
    self->text = NULL;
    self->id = 0xffff;
    self->part = 0;
    self->str = data_ov002_021effde;
    self->unk_40 = data_ov002_021effeb;
    self->unk_44 = 1;
    self->hasModel = 0;
    self->state = 2;
}

}
