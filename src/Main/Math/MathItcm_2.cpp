#include "Main/Math/MathItcm.h"

// Small collision and angle helpers placed in ITCM

extern "C" {

BOOL func_01ffc4ec(VecFx32 *p, fx32 r, fx32 h) {
    BOOL ret = FALSE;

    if (HitInCylinder(p, r, h)) {
        if (HitMagSqXZ(p) <= FX_Mul(r, r)) {
            ret = TRUE;
        }
    }
    return ret;
}

BOOL func_01ffc584(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h) {
    VecFx32 d;
    BOOL ret = FALSE;

    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    if (HitInCylinder(&d, r, h)) {
        if (HitMagSqXZ(&d) <= FX_Mul(r, r)) {
            ret = TRUE;
        }
    }
    return ret;
}


// h is a const parameter: the read through the const lvalue is not copy-propagated to its
// use, so h is loaded from the stack where the cylinder test starts, as in the target.
BOOL func_01ffc624(VecFx32 *p, const VecFx32 *trans, u16 *rot, fx32 r, const fx32 h) {
    MtxFx43 m;
    VecFx32 v;
    MtxFx43 tmp;
    BOOL init;
    u16 rz;
    u16 ry;
    u16 rx;
    BOOL ret;

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
    ret = FALSE;
    if (HitInCylinder(&v, r, h)) {
        if (HitMagSqXZ(&v) <= FX_Mul(r, r)) {
            ret = TRUE;
        }
    }
    return ret;
}

}
