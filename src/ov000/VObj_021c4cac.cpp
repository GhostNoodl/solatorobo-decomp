#include "ov000/VObj.h"

class Obj021c4cac : public VObj {
public:
    u8 pad_04[8];
    u32 unk_0c;
    u8 pad_10[0xe0];
    u8 unk_f0;
};

extern "C" {

void func_ov000_021c4cac(Obj021c4cac *self, s32 a, s32 b, s32 c) {
    self->vfunc_60(a, b, c);
    self->vfunc_64(a, b, c);
    if (self->unk_f0 != 0) {
        self->vfunc_74(a, b, c);
    }
    self->vfunc_70(a, b, c);
    if (self->unk_0c & 0x40000) {
        self->vfunc_78(a, b, c);
        self->vfunc_7c(a, b, c);
        self->vfunc_80(a, b, c);
    }
}

}
