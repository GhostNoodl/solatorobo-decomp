#include "Main/Math/MathItcm.h"

// Small collision and angle helpers placed in ITCM

typedef struct HitSegment {
    VecFx32 from;  // 0x00
    VecFx32 to;    // 0x0c
    u16 angle;     // 0x18
} HitSegment;

typedef struct HitVolume {
    u8 unk_00[0x44];
    VecFx32 min;   // 0x44
    VecFx32 max;   // 0x50
    u8 unk_5c[0x18];
    fx32 range;    // 0x74
    u8 unk_78[0x2a];
    u8 unk_a2_0 : 1;
    u8 useRange : 1;
    u8 unk_a2_2 : 1;
    u8 useAngle : 1;
} HitVolume;

extern "C" {

BOOL func_01ffc2a4(VecFx32 *a, VecFx32 *b, VecFx32 *min, VecFx32 *max);

BOOL func_01ffc828(VecFx32 *aMin, VecFx32 *aMax, VecFx32 *bMin, VecFx32 *bMax) {
    if (aMin->x > bMax->x || aMax->x < bMin->x || aMin->y > bMax->y || aMax->y < bMin->y || aMin->z > bMax->z ||
        aMax->z < bMin->z) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_01ffc89c(HitVolume *vol, HitSegment *seg) {
    fx32 dx;
    fx32 dz;
    fx64 t;
    fx32 dist;
    u16 diff;
    fx32 scale;

    if (!func_01ffc2a4(&seg->from, &seg->to, &vol->min, &vol->max)) {
        return FALSE;
    }
    if (!vol->useRange) {
        return TRUE;
    }
    dx = seg->to.x - seg->from.x;
    t = (fx64)dx * dx;
    dz = seg->to.z - seg->from.z;
    t += (fx64)dz * dz;
    REG_SQRTCNT = 1;
    REG_SQRT_PARAM = (u64)(t * 4);
    while (REG_SQRTCNT & REG_SQRTCNT_BUSY_MASK) {
    }
    dist = ((fx32)REG_SQRT_RESULT + 1) >> 1;
    if (vol->range < dist) {
        return FALSE;
    }
    if (!vol->useAngle) {
        return TRUE;
    }
    diff = (u16)(FX_Atan2(seg->from.x - seg->to.x, seg->from.z - seg->to.z) - seg->angle);
    if (diff > 0x8000) {
        diff = (u16)-diff;
    }
    scale = 0x119a - (diff >> 3);
    if (scale > 0x1000) {
        scale = 0x1000;
    } else if (scale < 0x43d) {
        scale = 0x43d;
    }
    if (scale == 0x1000) {
        return TRUE;
    }
    return dist <= FX_Mul(vol->range, scale);
}

}
