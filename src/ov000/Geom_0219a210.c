#include "types.h"
#include "ov000/Vec.h"

s32 Hit_CastSegment(VecFx32 *from, VecFx32 *to, u32 mask, s32 a, s32 b, s32 c);

void Geom_AddRotatedOffset(VecFx32 *pos, const VecFx32 *ofs, s32 angle) {
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
    VEC_Add(pos, &r, pos);
}

s32 Geom_SnapToGround(VecFx32 *pos, s32 up, s32 down) {
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
    ret = Hit_CastSegment(&a, &b, 0x20000000, 0, 0, -1);
    if (ret != -0x1000) {
        pos->y = b.y;
    }
    return ret;
}

u16 Hit_FindOpenDir(VecFx32 *pos, s32 radius, u16 angle, s32 n, u8 flag, u32 mask) {
    VecFx32 a;
    VecFx32 b;
    u16 result;
    u16 base;
    u16 step;
    s32 i;
    s32 x, z, s, c;

    a.x = pos->x;
    a.y = pos->y;
    a.z = pos->z;
    result = angle;
    base = 0x10000 / n;
    step = base;
    for (i = 0; i < n; i++) {
        x = a.x;
        b.y = a.y;
        z = a.z;
        s = FX_SinCosTable_[(angle >> 4) * 2];
        c = FX_SinCosTable_[(angle >> 4) * 2 + 1];
        x += FX_Mul(radius, s);
        z += FX_Mul(radius, c);
        b.x = x;
        b.z = z;
        if (Hit_CastSegment(&a, &b, mask, 0, 0, -1) != -1 << 12) {
            if (flag != 0) {
                result = angle;
                break;
            }
        } else if (flag == 0) {
            result = angle;
            break;
        }
        if ((i & 1) == 0) {
            angle += step;
        } else {
            angle -= step;
        }
        step += base;
    }
    return result;
}
