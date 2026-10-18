#include "ov000/VObj.h"
#include "ov000/Vec.h"

extern "C" {

s32 func_02040528(s32 max);
s32 func_02040498(s32 max);
void *NNS_G3dGlbGetInvV(void);
void MTX_MultVec33(const VecFx32 *v, const void *m, VecFx32 *out);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
VObj *func_02065f88(s32 kind, VecFx32 *pos);

VObj *func_ov000_0219b71c(VecFx32 *base, VecFx32 *range, s32 min, s32 max, s32 kind, u8 chance) {
    VecFx32 v;
    s32 scale;
    BOOL big;
    VObj *obj;
    s32 z = range->z;
    s32 y = func_02040528(range->y);
    v.x = func_02040528(range->x);
    v.y = y;
    v.z = z;
    MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, base, &v);
    scale = min + func_02040498(max - min);
    big = FALSE;
    if (kind == -1 || chance == 0) {
        big = TRUE;
    }
    if (chance < 100 && chance < func_02040498(100)) {
        big = TRUE;
    }
    if (big) {
        kind = 4;
        scale += scale >> 2;
    }
    obj = func_02065f88(kind, &v);
    obj->vfunc_14(scale, scale, scale);
    return obj;
}

}
