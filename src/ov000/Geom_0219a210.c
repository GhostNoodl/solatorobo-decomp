#include "types.h"
#include "ov000/Vec.h"

void func_02012be8(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
s32 func_01ffbd6c(VecFx32 *from, VecFx32 *to, u32 mask, s32 a, s32 b, s32 c);

static inline s32 FX_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle) {
    s32 c;
    s32 s;
    s32 z;
    s32 x;
    VecFx32 r;

    if (pos == NULL || ofs == NULL) {
        return;
    }
    angle >>= 4;
    s = FX_SinCosTable_[angle * 2];
    c = FX_SinCosTable_[angle * 2 + 1];
    x = 0;
    z = 0;
    if (ofs->x != 0) {
        x += FX_Mul(c, ofs->x);
        z += FX_Mul(-s, ofs->x);
    }
    if (ofs->z != 0) {
        x += FX_Mul(s, ofs->z);
        z += FX_Mul(c, ofs->z);
    }
    r.x = x;
    r.y = ofs->y;
    r.z = z;
    func_02012be8(pos, &r, pos);
}

s32 func_ov000_0219a2f4(VecFx32 *pos, s32 up, s32 down) {
    VecFx32 a;
    VecFx32 b;
    s32 ret;

    a.x = pos->x;
    a.y = pos->y;
    a.z = pos->z;
    b.x = pos->x;
    b.y = pos->y;
    b.z = pos->z;
    a.y += up;
    b.y += down;
    ret = func_01ffbd6c(&a, &b, 0x20000000, 0, 0, -1);
    if (ret != -0x1000) {
        pos->y = b.y;
    }
    return ret;
}
