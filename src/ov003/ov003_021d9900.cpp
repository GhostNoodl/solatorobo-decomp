#include "ov003/Vec.h"

extern "C" {

void func_ov003_021d9900(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    func_0201146c(&m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(in, &m, out);
}

void func_ov003_021d9980(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    func_02011488(&m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(in, &m, out);
}

void func_ov003_021d9a00(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    func_020114a4(&m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(in, &m, out);
}

s32 func_ov003_021d9a80(const Ov003Vec *a, const Ov003Vec *b) {
    s32 dx = b->x - a->x;
    s32 dy = b->y - a->y;
    s32 dz = b->z - a->z;
    return Ov003_FxMul(dx, dx) + Ov003_FxMul(dy, dy) + Ov003_FxMul(dz, dz);
}

void func_ov003_021d9aec(Ov003Vec *out, const Ov003Vec *in, s32 max) {
    s32 len = VEC_Mag(in);
    if (len != 0 && len > max) {
        s32 s = FX_Div(max, len);
        out->x = Ov003_FxMul(in->x, s);
        out->y = Ov003_FxMul(in->y, s);
        out->z = Ov003_FxMul(in->z, s);
    } else {
        *out = *in;
    }
}

void func_ov003_021d9b8c(Ov003Vec *out, const Ov003Vec *in, s32 max, s32 sub) {
    s32 len = VEC_Mag(in);
    if (len != 0 && len > max) {
        s32 t = len - sub;
        s32 s;
        if (t < max) {
            t = max;
        }
        s = FX_Div(t, len);
        out->x = Ov003_FxMul(in->x, s);
        out->y = Ov003_FxMul(in->y, s);
        out->z = Ov003_FxMul(in->z, s);
    } else {
        *out = *in;
    }
}

u16 func_ov003_021d9c38(const Ov003Vec *v) {
    return FX_Atan2(v->x, v->z);
}

u16 func_ov003_021d9c50(const Ov003Vec *a, const Ov003Vec *b) {
    return FX_Atan2(a->x - b->x, a->z - b->z);
}

u16 func_ov003_021d9c74(const Ov003Vec *v) {
    return Ov003_Pitch(v->y);
}

void func_ov003_021d9cd0(Ov003Vec *out, const Ov003Vec *in, s32 angle) {
    Ov003Mtx33 m;
    func_02011488(&m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(in, &m, out);
}

void func_ov003_021d9d28(Ov003Vec *out, const Ov003Vec *in, s32 angle, const Ov003Vec *center) {
    Ov003Vec d;
    Ov003Mtx33 m;
    d.x = in->x - center->x;
    d.y = in->y - center->y;
    d.z = in->z - center->z;
    func_02011488(&m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(&d, &m, out);
    VEC_Add(out, center, out);
}

}
