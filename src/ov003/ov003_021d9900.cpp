#include "ov003/Vec.h"

extern "C" {

void func_ov003_021d9900(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotX33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33((VecFx32 *)in, &m, (VecFx32 *)out);
}

void func_ov003_021d9980(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotY33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33((VecFx32 *)in, &m, (VecFx32 *)out);
}

void func_ov003_021d9a00(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotZ33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33((VecFx32 *)in, &m, (VecFx32 *)out);
}

s32 Ov003Vec_DistSq(const Ov003Vec *a, const Ov003Vec *b) {
    s32 dx = b->x - a->x;
    s32 dy = b->y - a->y;
    s32 dz = b->z - a->z;
    return FX_Mul(dx, dx) + FX_Mul(dy, dy) + FX_Mul(dz, dz);
}

void func_ov003_021d9aec(Ov003Vec *out, const Ov003Vec *in, s32 max) {
    s32 len = VEC_Mag((VecFx32 *)in);
    if (len != 0 && len > max) {
        s32 s = FX_Div(max, len);
        out->x = FX_Mul(in->x, s);
        out->y = FX_Mul(in->y, s);
        out->z = FX_Mul(in->z, s);
    } else {
        *out = *in;
    }
}

void func_ov003_021d9b8c(Ov003Vec *out, const Ov003Vec *in, s32 max, s32 sub) {
    s32 len = VEC_Mag((VecFx32 *)in);
    if (len != 0 && len > max) {
        s32 t = len - sub;
        s32 s;
        if (t < max) {
            t = max;
        }
        s = FX_Div(t, len);
        out->x = FX_Mul(in->x, s);
        out->y = FX_Mul(in->y, s);
        out->z = FX_Mul(in->z, s);
    } else {
        *out = *in;
    }
}

u16 Ov003Vec_Yaw(const Ov003Vec *v) {
    return FX_Atan2(v->x, v->z);
}

u16 func_ov003_021d9c50(const Ov003Vec *a, const Ov003Vec *b) {
    return FX_Atan2(a->x - b->x, a->z - b->z);
}

u16 Ov003Vec_Pitch(const Ov003Vec *v) {
    return Ov003_Pitch(v->y);
}

void Ov003Vec_RotY(Ov003Vec *out, const Ov003Vec *in, s32 angle) {
    Ov003Mtx33 m;
    MTX_RotY33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33((VecFx32 *)in, &m, (VecFx32 *)out);
}

void func_ov003_021d9d28(Ov003Vec *out, const Ov003Vec *in, s32 angle, const Ov003Vec *center) {
    Ov003Vec d;
    Ov003Mtx33 m;
    d.x = in->x - center->x;
    d.y = in->y - center->y;
    d.z = in->z - center->z;
    MTX_RotY33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33((VecFx32 *)&d, &m, (VecFx32 *)out);
    VEC_Add((VecFx32 *)out, (VecFx32 *)center, (VecFx32 *)out);
}

}
