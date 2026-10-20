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


BOOL func_01ffc318(VecFx32 *p, const VecFx32 *trans, VecFx32 *min, VecFx32 *max, u16 *rot) {
    MtxFx43 m;
    VecFx32 v;
    MtxFx43 tmp;
    BOOL init;
    u16 rz;
    u16 ry;
    u16 rx;

    ry = rot[1];
    rz = rot[2];
    rx = rot[0];
    init = FALSE;
    MTX_Identity43(&m);
    if (ry != 0) {
        MTX_RotY43(&m, HitSinIdx(ry), HitCosIdx(ry));
        init = TRUE;
    }
    if (rx != 0) {
        if (init) {
            MTX_RotX43(&tmp, HitSinIdx(rx), HitCosIdx(rx));
            MTX_Concat43(&tmp, &m, &m);
        } else {
            MTX_RotX43(&m, HitSinIdx(rx), HitCosIdx(rx));
            init = TRUE;
        }
    }
    if (rz != 0) {
        if (init) {
            MTX_RotZ43(&tmp, HitSinIdx(rz), HitCosIdx(rz));
            MTX_Concat43(&tmp, &m, &m);
        } else {
            MTX_RotZ43(&m, HitSinIdx(rz), HitCosIdx(rz));
        }
    }
    m._30 = trans->x;
    m._31 = trans->y;
    m._32 = trans->z;
    MTX_Inverse43(&m, &m);
    MTX_MultVec43(p, &m, &v);
    return HitInBox(&v, min, max);
}

}
