#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179b4[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_02210ba8(Ov009Actor *self) {
    Ov009Actor *t;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    }
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    func_ov000_0218d988(self, t, self->unk_b0->unk_02);
}

extern void func_ov000_0218ddd4(Ov009Actor *self, const Ov009Vec *v, s32 a);

void func_ov009_02210c18(Ov009Actor *self) {
    Ov009Param *p;
    Ov009Vec v;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    p = self->unk_b0;
    self->unk_9c = p->unk_00;
    v = self->unk_b8;
    func_ov000_0218ddd4(self, &v, p->unk_02);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    func_ov000_0219a2f4(&self->pos, 0x5000, -0xa000);
    self->pos.y += 0x4800;
}

}
