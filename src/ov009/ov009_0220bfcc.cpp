#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215ee4[];
extern void func_ov000_0218ddd4(Ov009Actor *self, const Ov009Vec *v, s32 a);

void func_ov009_0220bfcc(Ov009Actor *self) {
    u8 k = FLD(u8, self, 0xf7);
    if (k == 0) {
        Ov009Vec v;
        Ov009Param *p;
        if (self->unk_40->state == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[1], 0x2ab, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        }
        v = self->unk_b8;
        p = self->unk_b0;
        self->unk_9c = p->unk_00;
        func_ov000_0218ddd4(self, &v, p->unk_02);
    } else if (k == 1) {
        func_ov003_021d3600(self);
    }
}

}
