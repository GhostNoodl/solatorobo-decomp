#include "ov009/ov009.h"

extern "C" {

extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);

void func_ov009_0220e434(Ov009Actor *self) {
    Ov009Vec d;
    d.x = FLD(Ov009Vec, self, 0xf0).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0xf0).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0xf0).z - self->pos.z;
    func_02012fb8(0x7b, &d, &self->pos, &self->pos);
    if (func_02013068(&self->pos, &FLD(Ov009Vec, self, 0xf0)) >= 0xcd) {
        return;
    }
    func_ov000_02198360(self->unk_40, 1, 0);
    self->pos = FLD(Ov009Vec, self, 0xf0);
    self->unk_b6 = 0x96;
    func_020627a0(self->kind, self->id);
    func_020627dc(4);
    FLD(u8, data_ov000_021ccd54, 0xac) = 1;
}

}
