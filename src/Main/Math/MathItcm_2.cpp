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

}
