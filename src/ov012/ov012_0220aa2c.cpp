#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, around this TU's offsets
// and scale. Two of the offsets are read by other functions.
extern const VecFx32 data_ov012_0220a810;
extern const VecFx32 data_ov012_0220a81c;
static const VecFx16 data_ov012_0220a808 = {0, 0, 0};
static const VecFx32 data_ov012_0220a828 = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov012_0220a81c = {0, 0, 9 * FX32_ONE};
static const VecFx32 data_ov012_0220a834 = {0, 0, 0};
const VecFx32 data_ov012_0220a810 = {0, 0, 2 * FX32_ONE};
static const VecFx16 data_ov012_0220b088 = data_ov012_0220a808;
static const VecFx32 data_ov012_0220b090 = data_ov012_0220a834;
