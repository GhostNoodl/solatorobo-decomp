#include "nitro/fx.h"

void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab) {
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}

fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b) {
    return (fx32)(((fx64)a->x * b->x + (fx64)a->y * b->y + (fx64)a->z * b->z + (1 << (FX64_SHIFT - 1))) >>
                  FX64_SHIFT);
}

fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b) {
    fx32 tmp1, tmp2;
    tmp1 = (a->x * b->x) + (a->y * b->y);
    tmp2 = (a->z * b->z) + (1 << (FX64_SHIFT - 1));
    return (fx32)(((fx64)tmp1 + tmp2) >> FX64_SHIFT);
}

void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb) {
    fx32 x, y, z;
    x = (fx32)(((fx64)a->y * b->z - (fx64)a->z * b->y + (1 << (FX64_SHIFT - 1))) >> FX64_SHIFT);
    y = (fx32)(((fx64)a->z * b->x - (fx64)a->x * b->z + (1 << (FX64_SHIFT - 1))) >> FX64_SHIFT);
    z = (fx32)(((fx64)a->x * b->y - (fx64)a->y * b->x + (1 << (FX64_SHIFT - 1))) >> FX64_SHIFT);
    axb->x = x;
    axb->y = y;
    axb->z = z;
}

fx32 VEC_Mag(const VecFx32 *v) {
    fx64 t2;
    t2 = (fx64)v->x * v->x;
    t2 += (fx64)v->y * v->y;
    t2 += (fx64)v->z * v->z;
    REG_SQRTCNT = 1;
    REG_SQRT_PARAM = (u64)(t2 * 4);
    while (REG_SQRTCNT & REG_SQRTCNT_BUSY_MASK) {
    }
    return ((fx32)REG_SQRT_RESULT + 1) >> 1;
}

static inline void CP_SetDiv64_64(u64 numer, u64 denom) {
    REG_DIVCNT = 2;
    *(u64 *)0x04000290 = numer;
    *(u64 *)0x04000298 = denom;
}

static inline void CP_SetSqrt64(u64 param) {
    REG_SQRTCNT = 1;
    *(u64 *)0x040002b8 = param;
}

static inline u32 CP_GetSqrtResult32(void) {
    while (REG_SQRTCNT & REG_SQRTCNT_BUSY_MASK) {
    }
    return REG_SQRT_RESULT;
}

static inline s64 CP_GetDivResult64(void) {
    while (REG_DIVCNT & REG_DIVCNT_BUSY_MASK) {
    }
    return *(s64 *)0x040002a0;
}

void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst) {
    fx64 t;
    s32 sqrt;
    t = (fx64)pSrc->x * pSrc->x;
    t += (fx64)pSrc->y * pSrc->y;
    t += (fx64)pSrc->z * pSrc->z;
    CP_SetDiv64_64(1LL << 56, (u64)t);
    CP_SetSqrt64((u64)(t << 2));
    sqrt = (s32)CP_GetSqrtResult32();
    t = CP_GetDivResult64();
    t = t * sqrt;
    pDst->x = (fx32)((t * pSrc->x + (1LL << 44)) >> 45);
    pDst->y = (fx32)((t * pSrc->y + (1LL << 44)) >> 45);
    pDst->z = (fx32)((t * pSrc->z + (1LL << 44)) >> 45);
}

void VEC_Fx16Normalize(const VecFx16 *pSrc, VecFx16 *pDst) {
    fx64 t;
    s32 sqrt;
    t = pSrc->x * pSrc->x;
    t += pSrc->y * pSrc->y;
    t += pSrc->z * pSrc->z;
    CP_SetDiv64_64(1LL << 56, (u64)t);
    CP_SetSqrt64((u64)(t << 2));
    sqrt = (s32)CP_GetSqrtResult32();
    t = CP_GetDivResult64();
    t = t * sqrt;
    pDst->x = (fx16)((t * pSrc->x + (1LL << 44)) >> 45);
    pDst->y = (fx16)((t * pSrc->y + (1LL << 44)) >> 45);
    pDst->z = (fx16)((t * pSrc->z + (1LL << 44)) >> 45);
}

void VEC_MultAdd(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest) {
    pDest->x = v2->x + (fx32)(((fx64)a * v1->x) >> 12);
    pDest->y = v2->y + (fx32)(((fx64)a * v1->y) >> 12);
    pDest->z = v2->z + (fx32)(((fx64)a * v1->z) >> 12);
}

void VEC_MultSubtract(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest) {
    pDest->x = -v2->x + (fx32)(((fx64)a * v1->x) >> 12);
    pDest->y = -v2->y + (fx32)(((fx64)a * v1->y) >> 12);
    pDest->z = -v2->z + (fx32)(((fx64)a * v1->z) >> 12);
}
