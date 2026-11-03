#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
#include "types.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

void func_ov000_0215dae0(Lo021cae48 *self) {
    s32 st = self->state;
    s32 d;
    s32 a;
    if (st == 0) {
        return;
    }
    if (st != 2) {
        return;
    }
    self->openTime = self->openLen;
    self->openRatio = 0x1000;
    d = LO_FX_MUL((self->value - self->shown) << 12, 0xf6);
    a = d < 0 ? -d : d;
    if (a < 0x1000) {
        self->shown = self->value;
    } else {
        self->shown += d >> 12;
    }
    if (((self->flags << 30) >> 31) == 1) {
        self->state = 1;
    }
}

}
