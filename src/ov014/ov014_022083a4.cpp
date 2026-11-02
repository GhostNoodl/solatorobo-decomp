#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov003_021daab0(void *p);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

void func_ov014_022083a4(Ov014ActEx_0220774c *self) {
    Ov014Game54 *g;
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov003_021daab0(self->unk_d8);
    g = data_ov000_021ccd54;
    g->unk_18c = 0;
    g->unk_18d = 0;
    g->unk_18e = 0;
    g->unk_18f = 0;
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    self->v08();
}

}
