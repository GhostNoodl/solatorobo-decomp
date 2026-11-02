#include "Main/Math/Interp.h"

extern "C" {

s32 Interp_SinLerp(s32 t, s32 from, s32 to) {
    return from + Interp_FxMul(to - from, Interp_EaseSin(t));
}

void Interp_SinLerpVec(InterpVec *out, s32 t, const InterpVec *from, const InterpVec *to) {
    InterpVec d;
    s32 s = Interp_EaseSin(t);
    Interp_VecSub(to, from, &d);
    VEC_MultAdd(s, &d, from, out);
}

s32 Interp_QuadLerp(s32 t, s32 from, s32 to) {
    return from + Interp_FxMul(to - from, Interp_FxMul(t, t));
}

BOOL func_02049244(InterpVec *out, s32 speed, const InterpVec *from, const InterpVec *to, s32 minDist) {
    InterpVec d;
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
