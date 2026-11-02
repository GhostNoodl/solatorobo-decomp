#include "Main/Math/Interp.h"

extern "C" {

s32 Interp_SinLerp(s32 t, s32 from, s32 to) {
    return from + Interp_FxMul(to - from, Interp_EaseSin(t));
}

void Interp_SinLerpVec(VecFx32 *out, s32 t, const VecFx32 *from, const VecFx32 *to) {
    VecFx32 d;
    s32 s = Interp_EaseSin(t);
    Interp_VecSub(to, from, &d);
    VEC_MultAdd(s, &d, from, out);
}

s32 Interp_QuadLerp(s32 t, s32 from, s32 to) {
    return from + Interp_FxMul(to - from, Interp_FxMul(t, t));
}

BOOL Interp_MoveTo(VecFx32 *out, s32 speed, const VecFx32 *from, const VecFx32 *to, s32 minDist) {
    VecFx32 d;
    BOOL done = FALSE;
    Interp_VecSub(to, from, &d);
    if (VEC_Mag(&d) > minDist) {
        VEC_MultAdd(speed, &d, from, out);
    } else {
        *out = *from;
        done = TRUE;
    }
    return done;
}

}
