#ifndef OV003_VEC_H
#define OV003_VEC_H

#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
    Ov003Vec() {}
};

struct Ov003Rot {
    s16 x;
    s16 y;
    s16 z;
};

struct Ov003Mtx33 {
    s32 m[9];
};

#define OV003_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline s32 Ov003_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

extern "C" {
extern const s16 FX_SinCosTable_[];
extern void MTX_RotX33_(Ov003Mtx33 *m, s32 sin, s32 cos);
extern void MTX_RotY33_(Ov003Mtx33 *m, s32 sin, s32 cos);
extern void MTX_RotZ33_(Ov003Mtx33 *m, s32 sin, s32 cos);
extern void MTX_MultVec33(const Ov003Vec *v, const Ov003Mtx33 *m, Ov003Vec *out);
extern s32 FX_Div(s32 a, s32 b);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern s32 VEC_Mag(const Ov003Vec *v);
extern void VEC_Normalize(const Ov003Vec *src, Ov003Vec *dst);
extern void VEC_MultAdd(s32 scale, const Ov003Vec *dir, const Ov003Vec *base, Ov003Vec *out);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern u16 FX_Atan2(s32 x, s32 z);
extern u16 FX_AcosIdx(s32 v);
extern s16 func_02040528(s32 max);
}

static inline u16 Ov003_Pitch(s32 y) {
    u16 r = 0;
    u16 a = FX_AcosIdx(Ov003_FxMul(y, 0x1000));
    if (a < 0x4000) {
        r = a + 0xbfff;
    } else if (a > 0x4000) {
        r = a - 0x4000;
    }
    return r;
}

#endif
