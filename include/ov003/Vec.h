#ifndef OV003_VEC_H
#define OV003_VEC_H

#include "types.h"
#include "nitro/fx.h"

// A VecFx32 with a user-declared (empty) default constructor and a member-wise copy constructor.
// Both are load-bearing: copies such as `Ov003Vec p = t->pos;` are built field by field, which MWCC
// schedules differently from the 12-byte block copy of a plain VecFx32 (func_ov003_021da520,
// func_ov003_021ce630, func_ov003_021da854). Being derived from VecFx32, it passes to the SDK without a cast.
struct Ov003Vec : public VecFx32 {
    Ov003Vec() {}
    Ov003Vec(const Ov003Vec &o) {
        x = o.x;
        y = o.y;
        z = o.z;
    }
    explicit Ov003Vec(const VecFx32 &o) {
        x = o.x;
        y = o.y;
        z = o.z;
    }
};
typedef VecFx16 Ov003Rot;
typedef MtxFx33 Ov003Mtx33;

#define OV003_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

extern "C" s32 Rand_PlusMinus(s32 max);

static inline u16 Ov003_Pitch(s32 y) {
    u16 r = 0;
    u16 a = FX_AcosIdx(FX_Mul(y, 0x1000));
    if (a < 0x4000) {
        r = a + 0xbfff;
    } else if (a > 0x4000) {
        r = a - 0x4000;
    }
    return r;
}

#endif
