#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
#include "types.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

void func_ov000_02155d8c(UiList *self) {
    s32 n = ++self->unk_cc;
    s32 v;
    if (n < 0x14) {
        self->unk_d0 += LO_FX_MUL(0x6000 - self->unk_d0, 0x19a);
    } else if (n < 0x32) {
        self->unk_d0 += LO_FX_MUL(0 - self->unk_d0, 0xcd);
    } else {
        self->unk_cc = 0;
        self->unk_d0 = 0;
    }

}

}
