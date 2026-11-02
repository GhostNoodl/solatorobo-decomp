#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

extern "C" {
extern void *data_ov000_021ccd64;
s32 FX_Div(s32 a, s32 b);
s32 Group_GetSpawnPositions(void *mgr, s32 max, VecFx32 *out, s32 kind, u16 id);

static inline s32 DistSq(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    return (s32)((((s64)dx * dx + (s64)dy * dy + (s64)dz * dz) + 0x800) >> 12);
}

struct Obj0216d474 {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0c[0x8];
    s32 unk_14;
    s32 unk_18;
    u8 unk_1c[0x8];
    s32 unk_24;
    u8 unk_28[0x2];
    u16 unk_2a;
};

void func_ov000_0216d474(Obj0216d474 *self) {
    VecFx32 pts[0x20];
    s32 n;
    s32 i;
    s32 maxd;
    if (self->unk_08 == 2) {
        self->unk_14 = 0x7fffffff;
        return;
    }
    n = Group_GetSpawnPositions(data_ov000_021ccd64, 0x20, pts, self->unk_2a >> 12, self->unk_2a);
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
    self->unk_14 = LO_FX_MUL(maxd, 0x333);
    self->unk_18 = FX_Div(LO_FX_MUL(maxd, 0x800 - 0x333), self->unk_24 << 12);
}
}
