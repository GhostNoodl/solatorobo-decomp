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
