#include "Main/Math/MathItcm.h"

// Small collision and angle helpers placed in ITCM

extern "C" {

u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep) {
    u16 diff = (u16)(target - cur);
    BOOL neg;
    u32 step;

    if (diff == 0) {
        return target;
    }
    neg = FALSE;
    if (diff > 0x8000) {
        diff = (u16)-diff;
        neg = TRUE;
    }
    step = (u32)(diff * rate << 4) >> 16;
    if (step < minStep) {
        step = minStep;
    } else if (step > maxStep) {
        step = maxStep;
    }
    if (neg) {
        return (u16)(cur - step);
    }
    return (u16)(cur + step);
}

BOOL func_01ffc198(VecFx32 *a, VecFx32 *b, fx32 r) {
    VecFx32 d;
    BOOL ret = FALSE;

    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    if (HitInCube(&d, r)) {
        if (HitMagSq(&d) <= FX_Mul(r, r)) {
            ret = TRUE;
        }
    }
    return ret;
}

BOOL func_01ffc23c(VecFx32 *p, VecFx32 *min, VecFx32 *max) {
    return HitInBox(p, min, max);
}

BOOL func_01ffc2a4(VecFx32 *a, VecFx32 *b, VecFx32 *min, VecFx32 *max) {
    VecFx32 d;

    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    return HitInBox(&d, min, max);
}

}
