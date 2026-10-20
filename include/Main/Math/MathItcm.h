#ifndef MAIN_MATH_MATHITCM_H
#define MAIN_MATH_MATHITCM_H

#include "types.h"
#include "nitro/fx.h"

// Small collision helpers inlined into the ITCM hit tests

static inline BOOL HitInCube(const VecFx32 *d, fx32 r) {
    BOOL ret = TRUE;

    if (d->x < -r || d->x > r || d->y < -r || d->y > r || d->z < -r || d->z > r) {
        ret = FALSE;
    }
    return ret;
}

static inline fx32 HitSinIdx(u16 idx) {
    return FX_SinCosTable_[(idx >> 4) * 2];
}

static inline fx32 HitCosIdx(u16 idx) {
    return FX_SinCosTable_[(idx >> 4) * 2 + 1];
}

static inline BOOL HitInBox(const VecFx32 *p, const VecFx32 *min, const VecFx32 *max) {
    BOOL ret = TRUE;

    if (p->x < min->x || p->x > max->x || p->y < min->y || p->y > max->y || p->z < min->z || p->z > max->z) {
        ret = FALSE;
    }
    return ret;
}

static inline BOOL HitInCylinder(const VecFx32 *d, fx32 r, fx32 h) {
    BOOL ret = TRUE;
    fx32 nr = -r;
    fx32 hh = h;

    if (d->x < nr || d->x > r || d->y < 0 || d->y > hh || d->z < nr || d->z > r) {
        ret = FALSE;
    }
    return ret;
}

static inline fx32 HitMagSqXZ(const VecFx32 *d) {
    return (fx32)(((s64)d->x * d->x + (s64)d->z * d->z + 0x800) >> 12);
}

static inline fx32 HitMagSq(const VecFx32 *d) {
    return (fx32)(((s64)d->x * d->x + (s64)d->y * d->y + (s64)d->z * d->z + 0x800) >> 12);
}

#endif
