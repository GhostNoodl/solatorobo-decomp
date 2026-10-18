#include "nitro/fx.h"
#pragma thumb off

inline fx32 mul64 (fx64 x, fx32 y)
{
    return (fx32)((x * y) >> FX32_SHIFT);
}

asm void MTX_Identity33_ (register MtxFx33 *pDst)
{
    mov r2, #4096
    str r2, [r0, #32]
    mov r3, #0
    stmia r0 !, {r2, r3}
    mov r1, #0
    stmia r0 !, {r1, r3}
    stmia r0 !, {r2, r3}
    stmia r0 !, {r1, r3}
    bx lr
}

asm void MTX_Copy33To43_ (const register MtxFx33 *pSrc, register MtxFx43 *pDst)
{
    ldmia r0 !, {r2 - r3, r12}
    stmia r1 !, {r2 - r3, r12}
    ldmia r0 !, {r2 - r3, r12}
    stmia r1 !, {r2 - r3, r12}
    ldmia r0 !, {r2 - r3, r12}
    stmia r1 !, {r2 - r3, r12}
    mov r2, #0
    str r2, [r1, #0]
    str r2, [r1, #4]
    str r2, [r1, #8]
    bx lr
}

#pragma thumb on

asm void MTX_Scale33_ (register MtxFx33 *pDst, register fx32 x, register fx32 y, register fx32 z)
{
    stmia r0 !, {r1}
    mov r1, #0
    str r3, [r0, #28]
    mov r3, #0
    stmia r0 !, {r1, r3}
    stmia r0 !, {r1, r2, r3}
    mov r2, #0
    stmia r0 !, {r1, r3}
    bx lr
}

#pragma thumb off

void MTX_ScaleApply33 (const MtxFx33 *pSrc, MtxFx33 *pDst, fx32 x, fx32 y, fx32 z)
{
    fx64 v;

    v = (fx64)x;
    pDst->_00 = mul64(v, pSrc->_00);
    pDst->_01 = mul64(v, pSrc->_01);
    pDst->_02 = mul64(v, pSrc->_02);

    v = (fx64)y;
    pDst->_10 = mul64(v, pSrc->_10);
    pDst->_11 = mul64(v, pSrc->_11);
    pDst->_12 = mul64(v, pSrc->_12);

    v = (fx64)z;
    pDst->_20 = mul64(v, pSrc->_20);
    pDst->_21 = mul64(v, pSrc->_21);
    pDst->_22 = mul64(v, pSrc->_22);
}

#pragma thumb on

asm void MTX_RotX33_ (register MtxFx33 *pDst, register fx32 sinVal, register fx32 cosVal)
{
    mov r3, #1
    lsl r3, r3, #12
    str r3, [r0, #0]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r3, [r0, #12]
    str r2, [r0, #16]
    str r1, [r0, #20]
    str r3, [r0, #24]
    neg r1, r1
    str r1, [r0, #28]
    str r2, [r0, #32]
    bx lr
}

#pragma thumb off
#pragma thumb on

asm void MTX_RotY33_ (register MtxFx33 *pDst, register fx32 sinVal, register fx32 cosVal)
{
    str r2, [r0, #0]
    str r2, [r0, #32]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #12]
    str r3, [r0, #20]
    str r3, [r0, #28]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #12
    str r1, [r0, #24]
    str r2, [r0, #8]
    str r3, [r0, #16]
    bx lr
}

#pragma thumb off
#pragma thumb on

asm void MTX_RotZ33_ (register MtxFx33 *pDst, register fx32 sinVal, register fx32 cosVal)
{
    stmia r0 !, {r2}
    mov r3, #0
    stmia r0 !, {r1, r3}
    neg r1, r1
    stmia r0 !, {r1, r2}
    mov r1, #1
    lsl r1, r1, #12
    str r3, [r0, #0]
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r1, [r0, #12]
    bx lr
}

#pragma thumb off

void MTX_RotAxis33 (MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal)
{
    fx64 t, ss, cc, xx, yy, zz;
    fx32 t01;
    fx32 s2;

    t = (fx64)(FX32_ONE - (fx32)cosVal);
    ss = (fx64)sinVal;
    cc = (fx64)cosVal;
    xx = (fx64)vec->x;
    yy = (fx64)vec->y;
    zz = (fx64)vec->z;

    t01 = (fx32)((xx * xx * t) >> (FX64_SHIFT + FX64_SHIFT));
    pDst->_00 = t01 + cosVal;

    t01 = (fx32)((yy * yy * t) >> (FX64_SHIFT + FX64_SHIFT));
    pDst->_11 = t01 + cosVal;

    t01 = (fx32)((zz * zz * t) >> (FX64_SHIFT + FX64_SHIFT));
    pDst->_22 = t01 + cosVal;

    t01 = (fx32)((t * xx * yy) >> (FX64_SHIFT + FX64_SHIFT));
    s2 = (fx32)((ss * zz) >> FX64_SHIFT);
    pDst->_01 = t01 + s2;
    pDst->_10 = t01 - s2;

    t01 = (fx32)((t * xx * zz) >> (FX64_SHIFT + FX64_SHIFT));
    s2 = (fx32)((ss * yy) >> FX64_SHIFT);
    pDst->_02 = t01 - s2;
    pDst->_20 = t01 + s2;

    t01 = (fx32)((t * yy * zz) >> (FX64_SHIFT + FX64_SHIFT));
    s2 = (fx32)((ss * xx) >> FX64_SHIFT);
    pDst->_12 = t01 + s2;
    pDst->_21 = t01 - s2;
}

void MTX_Concat33 (const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab)
{
    MtxFx33 tmp;
    MtxFx33 *p;

    register fx32 x, y, z;
    register fx32 xx, yy, zz;

    if (ab == b) {
        p = &tmp;
    } else {
        p = ab;
    }

    x = a->_00;
    y = a->_01;
    z = a->_02;

    p->_00 = (fx32)(((fx64)x * b->_00 + (fx64)y * b->_10 + (fx64)z * b->_20) >> FX32_SHIFT);
    p->_01 = (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT);

    xx = b->_02;
    yy = b->_12;
    zz = b->_22;

    p->_02 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);

    x = a->_10;
    y = a->_11;
    z = a->_12;

    p->_12 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);
    p->_11 = (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT);

    xx = b->_00;
    yy = b->_10;
    zz = b->_20;

    p->_10 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);

    x = a->_20;
    y = a->_21;
    z = a->_22;

    p->_20 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);
    p->_21 = (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT);
    p->_22 = (fx32)(((fx64)x * b->_02 + (fx64)y * b->_12 + (fx64)z * b->_22) >> FX32_SHIFT);

    if (p == &tmp) {
        *ab = tmp;
    }
}

void MTX_MultVec33 (const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst)
{
    register fx32 x, y, z;

    x = vec->x;
    y = vec->y;
    z = vec->z;

    dst->x = (fx32)(((fx64)x * m->_00 + (fx64)y * m->_10 + (fx64)z * m->_20) >> FX32_SHIFT);
    dst->y = (fx32)(((fx64)x * m->_01 + (fx64)y * m->_11 + (fx64)z * m->_21) >> FX32_SHIFT);
    dst->z = (fx32)(((fx64)x * m->_02 + (fx64)y * m->_12 + (fx64)z * m->_22) >> FX32_SHIFT);
}

#pragma thumb reset
