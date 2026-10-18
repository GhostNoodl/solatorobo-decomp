#include "ov000/Actor.h"

extern "C" {

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
