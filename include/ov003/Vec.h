#ifndef OV003_VEC_H
#define OV003_VEC_H

#include "types.h"
#include "nitro/fx.h"

// Not VecFx32: the empty user constructor is load-bearing. Copies such as `Ov003Vec p = t->pos;` then go
// through the copy constructor, which MWCC schedules differently than a plain struct copy
// (func_ov003_021da520, func_ov003_021ce630, func_ov003_021da854). Pass it to the SDK as (VecFx32 *).
struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
    Ov003Vec() {}
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
