#include "ov012/ov012.h"

extern "C" {
void func_ov012_022054cc(Ov012Actor *self);
void func_ov012_022032f4(Ov012Actor *self) {
    u32 f;
    if (FLD(u32, self, 0xf0) & 0x400) {
        Ov012_ResetF0(self);
    }
    f = FLD(u32, self, 0xf0);
    if (!(f & 0x400000)) {
        if (f & 1) {
            f ^= 1;
        }
        if (f & 0x200000) {
            f ^= 0x200000;
        }
        if (f != 0) {
            Ov012_ResetF0(self);
            FLD(u32, self, 0xf0) |= 0x200000;
        }
    }
    if (FLD(u32, self, 0xf0) & 0x400000) {
        Ov012Actor *o = func_ov000_0219bf90();
        if (o != NULL && !func_ov000_021b4738(o)) {
            func_ov012_022054cc(self);
        }
    }
    if (self->unk_40->state == 0) {
        func_ov003_021daab0(FLD(void *, self, 0x100));
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[0], 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    }
    if (self->unk_93_4) {
        Ov012Actor *t = func_ov000_0218d240(self);
        Ov012Vec v;
        v.x = t->pos.x;
        v.y = t->pos.y;
        v.z = t->pos.z;
        func_ov000_0218d918(self, &v, 0xcd);
    }
    func_ov003_021d3524(self);
}
}
