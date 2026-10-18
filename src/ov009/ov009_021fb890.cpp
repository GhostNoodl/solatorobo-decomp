#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216abc[];
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);

void func_ov009_021fb890(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Param *p;
    if (self->unk_40->state == 0) {
        u8 *anim = data_ov009_02216aaa;
        if (self->unk_ee_0) {
            anim = data_ov009_02216abc;
        }
        func_ov000_02190cb0(self->unk_38, anim, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    }
    p = self->unk_b0;
    self->unk_9c = p->unk_00;
    v = self->unk_b8;
    func_ov000_0218ddd4(self, &v, p->unk_02);
    self->pos.y += Ov009_FxMul(v.y + 0x1400 - self->pos.y, 0xcd);
    if (self->pos.y - v.y > 0x3000) {
        self->unk_48->unk_30 = 0x80000000;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    self->unk_48->unk_30 = 0xc0000000;
}

}
