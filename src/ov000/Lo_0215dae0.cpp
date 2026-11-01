#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
#include "types.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215dae0(Lo021cae48 *self) {
    s32 st = self->unk_04;
    s32 d;
    s32 a;
    if (st == 0) {
        return;
    }
    if (st != 2) {
        return;
    }
    self->unk_30 = self->unk_34;
    self->unk_38 = 0x1000;
    d = LO_FX_MUL((self->unk_8c - self->unk_88) << 12, 0xf6);
    a = d < 0 ? -d : d;
    if (a < 0x1000) {
        self->unk_88 = self->unk_8c;
    } else {
        self->unk_88 += d >> 12;
    }
    if (((self->unk_0c << 30) >> 31) == 1) {
        self->unk_04 = 1;
    }
}

}
