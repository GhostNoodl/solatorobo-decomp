#include "ov000/Actor.h"

extern "C" {

void func_ov000_0218dab0(Actor *self, Actor *other, s32 step) {
    s32 dx;
    s32 dz;
    s32 oy;
    if (other == self) {
        return;
    }
    dx = self->pos.x - other->pos.x;
    dz = self->pos.z - other->pos.z;
    oy = other->pos.y;
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    self->rot_x = func_01ffc128(FX_Atan2(self->pos.y - oy, (s32)(REG_SQRT_RESULT + 1) >> 1), self->rot_x, step, 1, 0x8000);
}

void func_ov000_0218db58(Actor *self, u16 angle, u16 center, u16 range, s32 step) {
    u16 diff = angle - center;
    if (diff > 0x8000) {
        if (diff < (u16)-range) {
            angle = angle - (u16)(diff - (u16)-range);
        }
    } else if (diff > range) {
        angle = angle - (u16)(diff - range);
    }
    self->rot_y = func_01ffc128(angle, self->rot_y, step, 1, 0x8000);
}

}
