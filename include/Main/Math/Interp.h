#ifndef MAIN_MATH_INTERP_H
#define MAIN_MATH_INTERP_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct InterpVec {
    s32 x;
    s32 y;
    s32 z;
} InterpVec;

extern s16 FX_SinCosTable_[];

extern s32 func_02012d18(const InterpVec *v);
extern void func_02012fb8(s32 scale, const InterpVec *dir, const InterpVec *base, InterpVec *out);

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

static inline void Interp_VecSub(const InterpVec *a, const InterpVec *b, InterpVec *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

#ifdef __cplusplus
}
#endif

#endif
