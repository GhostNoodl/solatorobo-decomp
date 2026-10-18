#include "ov009/ov009.h"

extern "C" {

extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

void func_ov009_021fe1ec(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    if (st->state != 0) {
        return;
    }
    st->timer++;
    if (st->timer > 0x50) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
    VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
    self->unk_9c = Ov009_FxMul(self->unk_9c, 0xf33);
    self->unk_a0 = Ov009_FxMul(self->unk_a0, 0xf33);
    self->unk_a4 = Ov009_FxMul(self->unk_a4, 0xf33);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

extern u8 data_ov009_02216ab6[];
extern void func_ov000_021911c8(void *model, s32 a);

void func_ov009_021fe2c8(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x800);
        self->unk_48->unk_30 = 0x40000000;
        self->unk_40->state++;
    case 1:
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        self->unk_9c = Ov009_FxMul(self->unk_9c, 0xe66);
        self->unk_a0 = Ov009_FxMul(self->unk_a0, 0xe66);
        self->unk_a4 = Ov009_FxMul(self->unk_a4, 0xe66);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        break;
    }
}

}
