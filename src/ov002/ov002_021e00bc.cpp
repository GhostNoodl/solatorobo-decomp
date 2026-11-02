#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e00bc(Obj021eff30 *self) {
    u16 k = data_02097dc8->trig;
    void *w;
    u8 *q;
    if (k & 1) {
        self->unk_18 = 0x28;
        func_02049a48(data_02097e4c, 0xf, -1, -1, -1);
        return;
    }
    if (!(k & 2) && !(k & 0x20)) {
        return;
    }
    {
        void *r = func_0206ec48(FIELD(self->unk_10, 0x48, u16));
        w = self->unk_04;
        func_ov000_0215bb14(FIELD(w, 0x20, void *), r);
        FIELD(w, 0x20, VObj *)->vfunc_70();
    }
    q = FIELD(self->unk_04, 4, u8 *);
    q[0x74] = 7;
    q[0x75] = 1;
    func_ov002_021e019c(self, self->unk_1c, self->unk_20);
    self->unk_18 = 0;
    func_02049a48(data_02097e4c, 0xf, -1, -1, -1);
}

}
