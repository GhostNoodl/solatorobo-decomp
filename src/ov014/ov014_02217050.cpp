#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, with this TU's offset
// between them. Other functions read all three constants.
extern const VecFx16 data_ov014_022169c0;
extern const VecFx32 data_ov014_022169c8;
extern const VecFx32 data_ov014_022169d4;
const VecFx16 data_ov014_022169c0 = {0, 0, 0};
const VecFx32 data_ov014_022169c8 = {0, 0x333, 0};
static const VecFx16 data_ov014_0221762c = data_ov014_022169c0;
const VecFx32 data_ov014_022169d4 = {0, 0, 0};
static const VecFx32 data_ov014_02217634 = data_ov014_022169d4;
