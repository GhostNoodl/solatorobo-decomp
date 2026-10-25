#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, among this TU's constants.
// Other functions read them through the first one and two of the vectors by name.
extern const u16 data_ov013_0220b290;
extern const VecFx32 data_ov013_0220b2a8;
extern const VecFx32 data_ov013_0220b2b4;
const u16 data_ov013_0220b290 = 1;
static const VecFx16 data_ov013_0220b292 = {0x4000, 0, 0};
static const fx16 data_ov013_0220b29e[5] = {-0x1556, -0xaac, 0, 0xaab, 0x1555};
const VecFx32 data_ov013_0220b2a8 = {0, -0xccd, 0};
static const VecFx16 data_ov013_0220b298 = {0, 0, 0};
static const VecFx32 data_ov013_0220b2c0 = {0, 0, 0};
const VecFx32 data_ov013_0220b2b4 = {-FX32_ONE / 2, 0, 0};
static const VecFx16 data_ov013_0220ba44 = data_ov013_0220b298;
static const VecFx32 data_ov013_0220ba4c = data_ov013_0220b2c0;
