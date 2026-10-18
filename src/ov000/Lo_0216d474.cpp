#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

extern "C" {
extern void *data_ov000_021ccd64;
s32 FX_Div(s32 a, s32 b);
s32 func_ov000_0218c040(void *mgr, s32 max, VecFx32 *out, s32 kind, u16 id);

static inline s32 DistSq(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    return (s32)((((s64)dx * dx + (s64)dy * dy + (s64)dz * dz) + 0x800) >> 12);
}

void func_ov000_0216d474(u8 *self) {
    VecFx32 pts[0x20];
    s32 n;
    s32 i;
    s32 maxd;
    if (LFLD(s32, self, 0x8) == 2) {
        LFLD(s32, self, 0x14) = 0x7fffffff;
        return;
    }
    n = func_ov000_0218c040(data_ov000_021ccd64, 0x20, pts, LFLD(u16, self, 0x2a) >> 12, LFLD(u16, self, 0x2a));
    if (n == 0) {
        return;
    }
    maxd = 0;
    {
        VecFx32 c = {0, 0, 0};
        for (i = 0; i < n; i++) {
            s32 d = DistSq(&c, &pts[i]);
            if (maxd < d) {
                maxd = d;
            }
        }
    }
    if (maxd == 0) {
        return;
    }
    LFLD(s32, self, 0x14) = LO_FX_MUL(maxd, 0x333);
    LFLD(s32, self, 0x18) = FX_Div(LO_FX_MUL(maxd, 0x800 - 0x333), LFLD(s32, self, 0x24) << 12);
}
}
