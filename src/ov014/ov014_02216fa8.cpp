#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, next to this TU's name,
// scale and offsets. The pointer to the name and two offsets are read by other functions.
extern const char *const data_ov014_022164a0;
extern const VecFx32 data_ov014_022164b8;
extern const VecFx32 data_ov014_022164c4;
extern char data_ov014_022171be[];
const char *const data_ov014_022164a0 = data_ov014_022171be;
static const VecFx16 data_ov014_022164a4 = {0, 0, 0};
const VecFx32 data_ov014_022164b8 = {0, FX32_ONE, 0};
static const VecFx32 data_ov014_022164ac = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov014_022164c4 = {2 * FX32_ONE, 0, 0};
static const VecFx32 data_ov014_022164d0 = {0, 0, 0};
static const VecFx16 data_ov014_022171b8 = data_ov014_022164a4;
char data_ov014_022171be[] = "nut00";
static const VecFx32 data_ov014_022171c4 = data_ov014_022164d0;
