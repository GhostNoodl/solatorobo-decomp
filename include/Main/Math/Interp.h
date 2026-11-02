#ifndef MAIN_MATH_INTERP_H
#define MAIN_MATH_INTERP_H

#include "types.h"
#include "nitro/fx.h"

#ifdef __cplusplus
extern "C" {
#endif


static inline s32 Interp_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline s32 Interp_SinIdx(s32 idx) {
    return FX_SinCosTable_[idx * 2];
}

// Maps t in [0, 1] onto a quarter sine wave (ease-out).
static inline s32 Interp_EaseSin(s32 t) {
    return Interp_SinIdx(Interp_FxMul(t, 0x3fff000) >> 16);
}

static inline void Interp_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

#ifdef __cplusplus
}
#endif

#endif
