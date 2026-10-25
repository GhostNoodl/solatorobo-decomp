#include <nitro/fx.h>

// Squared hit radii read by the hit check in ov006_021e6ca4.cpp: the outer one, and a quarter of it (half the radius).
struct HitRadiusSq {
    fx32 half;
    fx32 full;

    HitRadiusSq(fx32 sq) {
        full = sq;
        half = sq >> 2;
    }
};

extern const HitRadiusSq data_ov006_021ec484;
const HitRadiusSq data_ov006_021ec484(160000 * FX32_ONE);
