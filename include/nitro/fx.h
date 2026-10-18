#ifndef NITRO_FX_H
#define NITRO_FX_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef s32 fx32;
typedef s16 fx16;
typedef s64 fx64;
typedef s64 fx64c;

#define FX32_SHIFT 12
#define FX32_ONE   (1 << FX32_SHIFT)
#define FX64C_SHIFT 32

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct VecFx16 {
    fx16 x;
    fx16 y;
    fx16 z;
} VecFx16;

#define REG_DIVCNT      (*(vu16 *)0x04000280)
#define REG_DIV_NUMER   (*(vu64 *)0x04000290)
#define REG_DIV_NUMER_L (*(vu32 *)0x04000290)
#define REG_DIV_NUMER_H (*(vu32 *)0x04000294)
#define REG_DIV_DENOM   (*(vu64 *)0x04000298)
#define REG_DIV_DENOM_L (*(vu32 *)0x04000298)
#define REG_DIV_DENOM_H (*(vu32 *)0x0400029c)
#define REG_DIV_RESULT  (*(vu64 *)0x040002a0)
#define REG_DIV_RESULT_L (*(vu32 *)0x040002a0)
#define REG_DIVREM_RESULT_L (*(vu32 *)0x040002a8)
#define REG_SQRTCNT     (*(vu16 *)0x040002b0)
#define REG_SQRT_RESULT (*(vu32 *)0x040002b4)
#define REG_SQRT_PARAM  (*(vu64 *)0x040002b8)
#define REG_SQRT_PARAM_L (*(vu32 *)0x040002b8)
#define REG_SQRT_PARAM_H (*(vu32 *)0x040002bc)

#define REG_DIVCNT_BUSY_MASK 0x8000
#define REG_SQRTCNT_BUSY_MASK 0x8000

fx32 FX_Div(fx32 numer, fx32 denom);
fx32 FX_Inv(fx32 denom);
fx32 FX_Sqrt(fx32 x);
fx64c FX_GetDivResultFx64c(void);
fx32 FX_GetDivResult(void);
void FX_InvAsync(fx32 denom);
fx32 FX_GetSqrtResult(void);
void FX_DivAsync(fx32 numer, fx32 denom);

#define FX64_SHIFT 12

void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b);
void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
fx32 VEC_Mag(const VecFx32 *v);
void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
void VEC_Fx16Normalize(const VecFx16 *pSrc, VecFx16 *pDst);
void VEC_MultAdd(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
void VEC_MultSubtract(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2);

u16 FX_Atan(fx32 x);
u16 FX_Atan2(fx32 y, fx32 x);
u16 FX_AsinIdx(fx32 x);
u16 FX_AcosIdx(fx32 x);

extern const fx16 FX_SinCosTable_[];
extern const fx16 FX_AtanTable_[];

#ifdef __cplusplus
}
#endif

#endif
