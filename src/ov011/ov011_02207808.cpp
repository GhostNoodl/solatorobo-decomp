#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, and two scales of this TU
// that other functions read. MWCC emits this order as zero rotation, scales, zero vector.
extern const VecFx16 data_ov011_02207418;
extern const VecFx32 data_ov011_02207420;
extern const VecFx32 data_ov011_0220742c;
extern const VecFx32 data_ov011_02207438;
const VecFx32 data_ov011_02207420 = {FX32_ONE / 2, FX32_ONE / 2, FX32_ONE};
const VecFx32 data_ov011_0220742c = {0x14cd, 0x14cd, FX32_ONE};
const VecFx32 data_ov011_02207438 = {0, 0, 0};
const VecFx16 data_ov011_02207418 = {0, 0, 0};
static const VecFx16 data_ov011_02207994 = data_ov011_02207418;
static const VecFx32 data_ov011_0220799c = data_ov011_02207438;
