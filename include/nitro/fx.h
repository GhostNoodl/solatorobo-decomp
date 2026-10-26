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
#define FX32_INT_SIZE       19
#define FX32_DEC_SIZE       12
#define FX32_INT_MASK       0x7ffff000
#define FX32_DEC_MASK       0x00000fff
#define FX32_SIGN_MASK      0x80000000
#define FX32_MAX            ((fx32)0x7fffffff)
#define FX32_MIN            ((fx32)0x80000000)
#define FX64_INT_SIZE       51
#define FX64_DEC_SIZE       12
#define FX64_INT_MASK       ((fx64)0x7ffffffffffff000)
#define FX64_DEC_MASK       ((fx64)0x0000000000000fff)
#define FX64_SIGN_MASK      ((fx64)0x8000000000000000)
#define FX64_MAX            ((fx64)0x7fffffffffffffff)
#define FX64_MIN            ((fx64)0x8000000000000000)
#define FX64C_INT_SIZE       31
#define FX64C_DEC_SIZE       32
#define FX64C_INT_MASK       ((fx64c)0x7fffffff00000000)
#define FX64C_DEC_MASK       ((fx64c)0x00000000ffffffff)
#define FX64C_SIGN_MASK      ((fx64c)0x8000000000000000)
#define FX64C_MAX            ((fx64c)0x7fffffffffffffff)
#define FX64C_MIN            ((fx64c)0x8000000000000000)
#define FX16_SHIFT          12
#define FX16_INT_SIZE       3
#define FX16_DEC_SIZE       12
#define FX16_INT_MASK       0x7000
#define FX16_DEC_MASK       0x0fff
#define FX16_SIGN_MASK      0x8000
#define FX16_MAX            ((fx16)0x7fff)
#define FX16_MIN            ((fx16)0x8000)
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


void FX_Init(void);
fx32 FX_Modf(fx32 x, fx32 *iPtr);
fx32 FX_MulFunc(fx32 v1, fx32 v2);
fx32 FX_Mul32x64cFunc(fx32 v32, fx64c v64c);

static inline s32 FX_Whole(fx32 v) {
    return (s32)(v >> FX32_SHIFT);
}

static inline fx32 FX_Floor(fx32 v) {
    return (fx32)(v & (FX32_INT_MASK | FX32_SIGN_MASK));
}

static inline fx32 FX_MulInline(fx32 v1, fx32 v2) {
    return (fx32)(((s64)(v1) * v2 + 0x800LL) >> FX32_SHIFT);
}
#define FX_Mul(v1, v2) FX_MulInline(v1, v2)

// fx_trig.h: idx is an angle index from 0 to 65535 (0 to 2*pi)
static inline fx16 FX_SinIdx(int idx) {
    return FX_SinCosTable_[((idx >> 4) << 1)];
}

static inline fx16 FX_CosIdx(int idx) {
    return FX_SinCosTable_[((idx >> 4) << 1) + 1];
}

// fx_vec.h
static inline void VEC_Set(VecFx32 *a, fx32 x, fx32 y, fx32 z) {
    a->x = x;
    a->y = y;
    a->z = z;
}

static inline void VEC_Fx16Set(VecFx16 *a, fx16 x, fx16 y, fx16 z) {
    a->x = x;
    a->y = y;
    a->z = z;
}

static inline fx32 FX_Mul32x64cInline(fx32 v32, fx64c v64c) {
    fx64c tmp = v64c * v32 + 0x80000000LL;
    return (fx32)(tmp >> FX64C_SHIFT);
}
#define FX_Mul32x64c(v32, v64c) FX_Mul32x64cInline(v32, v64c)

// The divider registers are written through non-volatile pointers here, so both
// writes can merge into one stm (dsi/1.3p1 keeps volatile stores separate).
static inline void FX_InvAsyncImm(fx32 denom) {
    *(u64 *)0x04000290 = (u64)FX32_ONE << 32;
    *(u64 *)0x04000298 = (u32)denom;
}

static inline void FX_DivAsyncImm(fx32 numer, fx32 denom) {
    *(u64 *)0x04000290 = (u64)numer << 32;
    *(u64 *)0x04000298 = (u32)denom;
}

static inline fx64c FX_GetInvResultFx64c(void) {
    return FX_GetDivResultFx64c();
}

static inline fx32 FX_GetInvResult(void) {
    return FX_GetDivResult();
}

void MI_Copy36B(const void *pSrc, void *pDest);
void MI_Copy48B(const void *pSrc, void *pDest);

typedef union MtxFx22 {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

typedef union MtxFx33 {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

typedef union MtxFx43 {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;

typedef union MtxFx44 {
    struct {
        fx32 _00, _01, _02, _03;
        fx32 _10, _11, _12, _13;
        fx32 _20, _21, _22, _23;
        fx32 _30, _31, _32, _33;
    };
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;

void MTX_Identity22_(MtxFx22 *pDst);
void MTX_Rot22_(MtxFx22 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_ScaleApply22(const MtxFx22 *pSrc, MtxFx22 *pDst, fx32 x, fx32 y);
void MTX_Concat22(const MtxFx22 *a, const MtxFx22 *b, MtxFx22 *ab);

void MTX_Identity33_(MtxFx33 *pDst);
void MTX_Copy33To43_(const MtxFx33 *pSrc, MtxFx43 *pDst);
void MTX_Scale33_(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_ScaleApply33(const MtxFx33 *pSrc, MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_RotX33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotY33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotZ33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotAxis33(MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst);

void MTX_Identity43_(MtxFx43 *pDst);
void MTX_Copy43To44_(const MtxFx43 *pSrc, MtxFx44 *pDst);
void MTX_TransApply43(const MtxFx43 *pSrc, MtxFx43 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_Scale43_(MtxFx43 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_ScaleApply43(const MtxFx43 *pSrc, MtxFx43 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_RotX43_(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotY43_(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotZ43_(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal);
int MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst);
void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab);
void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);

void MTX_Identity44_(MtxFx44 *pDst);
void MTX_Copy44To43_(const MtxFx44 *pSrc, MtxFx43 *pDst);
void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
void MTX_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);

#include "nitro/fx_const.h"

// SDK inline wrappers
static inline void MTX_Identity22(MtxFx22 *pDst) { MTX_Identity22_(pDst); }
static inline void MTX_Rot22(MtxFx22 *pDst, fx32 sinVal, fx32 cosVal) { MTX_Rot22_(pDst, sinVal, cosVal); }
static inline void MTX_Identity33(MtxFx33 *pDst) { MTX_Identity33_(pDst); }
static inline void MTX_Copy33(const MtxFx33 *pSrc, MtxFx33 *pDst) { MI_Copy36B(pSrc, pDst); }
static inline void MTX_Copy33To43(const MtxFx33 *pSrc, MtxFx43 *pDst) { MTX_Copy33To43_(pSrc, pDst); }
static inline void MTX_Scale33(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z) { MTX_Scale33_(pDst, x, y, z); }
static inline void MTX_RotX33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotX33_(pDst, sinVal, cosVal); }
static inline void MTX_RotY33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotY33_(pDst, sinVal, cosVal); }
static inline void MTX_RotZ33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotZ33_(pDst, sinVal, cosVal); }
static inline void MTX_Identity43(MtxFx43 *pDst) { MTX_Identity43_(pDst); }
static inline void MTX_Copy43(const MtxFx43 *pSrc, MtxFx43 *pDst) { MI_Copy48B(pSrc, pDst); }
static inline void MTX_Copy43To44(const MtxFx43 *pSrc, MtxFx44 *pDst) { MTX_Copy43To44_(pSrc, pDst); }
static inline void MTX_Scale43(MtxFx43 *pDst, fx32 x, fx32 y, fx32 z) { MTX_Scale43_(pDst, x, y, z); }
static inline void MTX_RotX43(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotX43_(pDst, sinVal, cosVal); }
static inline void MTX_RotY43(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotY43_(pDst, sinVal, cosVal); }
static inline void MTX_RotZ43(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotZ43_(pDst, sinVal, cosVal); }
static inline void MTX_Identity44(MtxFx44 *pDst) { MTX_Identity44_(pDst); }
static inline void MTX_Copy44To43(const MtxFx44 *pSrc, MtxFx43 *pDst) { MTX_Copy44To43_(pSrc, pDst); }

static inline void MTX_Frustum(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, MtxFx44 *mtx) { MTX_FrustumW(t, b, l, r, n, f, FX32_ONE, mtx); }
static inline void MTX_Perspective(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, MtxFx44 *mtx) { MTX_PerspectiveW(fovySin, fovyCos, aspect, n, f, FX32_ONE, mtx); }
static inline void MTX_Ortho(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, MtxFx44 *mtx) { MTX_OrthoW(t, b, l, r, n, f, FX32_ONE, mtx); }

#ifdef __cplusplus
}
#endif

#endif
