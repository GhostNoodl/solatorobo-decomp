#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup. Other functions of this TU
// read the vector and its copy, so those two keep their names.
extern const VecFx16 data_ov003_021f4980;
extern const VecFx32 data_ov003_021f4988;
extern const VecFx32 data_ov003_021f7cc4;
const VecFx16 data_ov003_021f4980 = {0, 0, 0};
const VecFx32 data_ov003_021f4988 = {0, 0, 0};
static const VecFx16 data_ov003_021f7cbc = data_ov003_021f4980;
const VecFx32 data_ov003_021f7cc4 = data_ov003_021f4988;
