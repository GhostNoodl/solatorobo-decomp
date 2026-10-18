#include "ov003/Vec.h"

extern "C" {

s32 func_ov003_021d9a80(const Ov003Vec *a, const Ov003Vec *b) {
    s32 dx = b->x - a->x;
    s32 dy = b->y - a->y;
    s32 dz = b->z - a->z;
    return Ov003_FxMul(dx, dx) + Ov003_FxMul(dy, dy) + Ov003_FxMul(dz, dz);
}

void func_ov003_021d9aec(Ov003Vec *out, const Ov003Vec *in, s32 max) {
    s32 len = func_02012d18(in);
    if (len != 0 && len > max) {
        s32 s = func_02012ab8(max, len);
        out->x = Ov003_FxMul(in->x, s);
        out->y = Ov003_FxMul(in->y, s);
        out->z = Ov003_FxMul(in->z, s);
    } else {
        *out = *in;
    }
}

void func_ov003_021d9b8c(Ov003Vec *out, const Ov003Vec *in, s32 max, s32 sub) {
    s32 len = func_02012d18(in);
    if (len != 0 && len > max) {
        s32 t = len - sub;
        s32 s;
        if (t < max) {
            t = max;
        }
        s = func_02012ab8(t, len);
        out->x = Ov003_FxMul(in->x, s);
        out->y = Ov003_FxMul(in->y, s);
        out->z = Ov003_FxMul(in->z, s);
    } else {
        *out = *in;
    }
}

u16 func_ov003_021d9c38(const Ov003Vec *v) {
    return func_0201319c(v->x, v->z);
}

u16 func_ov003_021d9c50(const Ov003Vec *a, const Ov003Vec *b) {
    return func_0201319c(a->x - b->x, a->z - b->z);
}

u16 func_ov003_021d9c74(const Ov003Vec *v) {
    return Ov003_Pitch(v->y);
}

}
