#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_ov000_021984f4(void *a, Ov014Vec *b, s32 c);

void func_ov014_02209ecc(Ov014Actor *self) {
    u16 k = FLD(u16, self, 0xb4);
    if (k != 100 && k != 110) {
        self->unk_48->unk_60 = FLD(s32, self, 0x6c) >> 1;
        self->unk_48->unk_38 = self->unk_64;
    } else {
        self->unk_48->unk_60 = 0x1000;
        self->unk_48->unk_38 = 0x1000;
    }
    func_ov000_0219864c(self->unk_48, 0, 0);
}

void func_ov014_02209f24(Ov014Actor *self) {
    Ov014Vec v;
    u16 k;
    Ov014_VecCopy(&v, &self->pos);
    k = FLD(u16, self, 0xb4);
    if (k != 100 && k != 110) {
        v.y += 0x5000;
        v.z += 0x2000;
        func_ov000_021984f4(self->unk_44, &v, 0);
    } else {
        v.y += 0x1000;
        func_ov000_021984f4(self->unk_44, &v, 0);
    }
}

}
