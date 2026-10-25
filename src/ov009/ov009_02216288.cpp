#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, among this TU's colour
// bytes and offsets, which other functions read.
typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ov009Ver;

extern const Ov009Ver data_ov009_02216004[2];
extern const VecFx32 data_ov009_02216010;
extern const VecFx32 data_ov009_0221601c;
extern const VecFx32 data_ov009_02216028;
static const VecFx16 data_ov009_0221600a = {0, 0, 0};
const Ov009Ver data_ov009_02216004[2] = {{0x11, 1, 0}, {0x11, 1, 1}};
const VecFx32 data_ov009_0221601c = {0x1800, -FX32_ONE, 0x3000};
const VecFx32 data_ov009_02216028 = {0, 0, 0x1800};
static const VecFx32 data_ov009_02216034 = {0, 0, 0};
const VecFx32 data_ov009_02216010 = {-0x6800, 0xc800, 0xb0cd};
static const VecFx16 data_ov009_02217994 = data_ov009_0221600a;
static const VecFx32 data_ov009_0221799c = data_ov009_02216034;
