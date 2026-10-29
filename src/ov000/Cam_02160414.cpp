#include "types.h"
#include "nitro/fx.h"

typedef struct {
    u8 pad_00[0x74];
    s32 unk_74;
    s32 unk_78;
    u8 pad_7c[4];
    VecFx32 unk_80;
    s32 unk_8c;
    s32 unk_90;
} Cam02160414;

extern "C" {
int func_0204061c(s32 *out, VecFx32 *pos);

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_ov000_02160414(Cam02160414 *self) {
    s32 scr[2];
    VecFx32 pos;
    s32 dx;
    s32 dy;
    s32 d;
    s32 k;

    pos = self->unk_80;
    func_0204061c(scr, &pos);
    scr[0] <<= 12;
    scr[1] <<= 12;
    d = FX_Mul(scr[0] - self->unk_8c, scr[0] - self->unk_8c) + FX_Mul(scr[1] - self->unk_90, scr[1] - self->unk_90);
    dx = scr[0] - self->unk_8c;
    dy = scr[1] - self->unk_90;
    if (ABS(d) > 0x800000) {
        k = 0x1000;
    } else if (ABS(d) > 0x400000) {
        k = 0xc00;
    } else {
        k = 0x800;
    }
    self->unk_8c += FX_Mul(dx, k);
    self->unk_90 += FX_Mul(dy, k);
    self->unk_74 = self->unk_8c >> 12;
    self->unk_78 = self->unk_90 >> 12;
}
}
