#include "nitro/fx.h"

fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2) {
    fx64 t2;
    fx32 tmp;
    tmp = v1->x - v2->x;
    t2 = (fx64)tmp * tmp;
    tmp = v1->y - v2->y;
    t2 += (fx64)tmp * tmp;
    tmp = v1->z - v2->z;
    t2 += (fx64)tmp * tmp;
    REG_SQRTCNT = 1;
    REG_SQRT_PARAM = (u64)(t2 * 4);
    while (REG_SQRTCNT & REG_SQRTCNT_BUSY_MASK) {
    }
    return ((fx32)REG_SQRT_RESULT + 1) >> 1;
}
