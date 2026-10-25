#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, next to this TU's name and
// offsets. The pointer to the name and the two offsets are read by other functions.
extern const char *const data_ov012_0220a510;
extern const VecFx32 data_ov012_0220a51c;
extern const VecFx32 data_ov012_0220a528;
extern char data_ov012_0220aef6[];
const char *const data_ov012_0220a510 = data_ov012_0220aef6;
static const VecFx16 data_ov012_0220a514 = {0, 0, 0};
const VecFx32 data_ov012_0220a51c = {0, 0, 4 * FX32_ONE};
const VecFx32 data_ov012_0220a528 = {0, -2 * FX32_ONE, 4 * FX32_ONE};
static const VecFx32 data_ov012_0220a534 = {0, 0, 0};
static const VecFx16 data_ov012_0220aef0 = data_ov012_0220a514;
char data_ov012_0220aef6[] = "nut00";
static const VecFx32 data_ov012_0220aefc = data_ov012_0220a534;
