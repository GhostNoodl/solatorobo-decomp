#include "ov000/Actor.h"

extern "C" {

void func_ov000_0218dd8c(Actor *self, u16 base, s32 turn, s32 range) {
    if (!(data_02097dc8->unk_10 & 0xf0)) {
        return;
    }
    self->unk_98 = base + func_0203d434(data_02097dc8, range);
    func_ov000_0218dbe0(self, turn);
}

void func_ov000_0218ddd4(Actor *self, const VecFx32 *target, s32 turn) {
    VecFx32 d;
    d.x = target->x - self->pos.x;
    d.y = target->y - self->pos.y;
    d.z = target->z - self->pos.z;
    d.y = 0;
    if (func_01ffc4ec(&d, self->unk_9c, 0x2800)) {
        self->pos.x = target->x;
        self->pos.z = target->z;
        return;
    }
    self->unk_98 = FX_Atan2(d.x, d.z);
    func_ov000_0218dbe0(self, turn);
}

}
