#include "Main/Math/MathItcm.h"

// Small collision and angle helpers placed in ITCM

extern "C" {

void func_01ffc9fc(VecFx32 *dst, VecFx32 *src, u16 angle) {
    fx32 x = 0;
    fx32 z = 0;
    fx32 s = FX_SinCosTable_[(angle >> 4) * 2];
    fx32 c = FX_SinCosTable_[(angle >> 4) * 2 + 1];

    if (src->x != 0) {
        x += FX_Mul(c, src->x);
        z += FX_Mul(-s, src->x);
    }
    if (src->z != 0) {
        x += FX_Mul(s, src->z);
        z += FX_Mul(c, src->z);
    }
    {
        VecFx32 tmp;
        tmp.x = x;
        tmp.y = src->y;
        tmp.z = z;
        *dst = tmp;
    }
}

}
