#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, after this TU's count and
// name pointers and among its offsets and sizes, which other functions read.
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Ov010Blk12;

extern const s32 data_ov010_0220f534;
extern const VecFx32 data_ov010_0220f54c;
extern const Ov010Blk12 data_ov010_0220f558;
extern const Ov010Blk12 data_ov010_0220f564;
extern const Ov010Blk12 data_ov010_0220f570;
extern const VecFx32 data_ov010_0220f57c;
extern const Ov010Blk12 data_ov010_0220f588;
extern const VecFx32 data_ov010_0220f594;
extern char data_ov010_02210204[];
extern char data_ov010_02210210[];
extern char data_ov010_02210228[];
char data_ov010_02210210[] = "ef3di1zai03";
static const char *const data_ov010_0220f538 = data_ov010_02210228;
static const char *const data_ov010_0220f53c = data_ov010_02210210;
const VecFx32 data_ov010_0220f57c = {0x2800, 0x2800, 0x2800};
const Ov010Blk12 data_ov010_0220f558 = {0, 0x4000, -0x3000};
const s32 data_ov010_0220f534 = 4;
static const char *const data_ov010_0220f540 = data_ov010_02210204;
const Ov010Blk12 data_ov010_0220f570 = {FX32_ONE, FX32_ONE, FX32_ONE};
const Ov010Blk12 data_ov010_0220f588 = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov010_0220f54c = {0, 0, FX32_ONE};
const Ov010Blk12 data_ov010_0220f564 = {0, 0x4000, -0x3000};
static const VecFx16 data_ov010_0220f544 = {0, 0, 0};
char data_ov010_02210204[] = "nut00";
static const VecFx16 data_ov010_0221020a = data_ov010_0220f544;
const VecFx32 data_ov010_0220f594 = {0, 0, 0};
static const VecFx32 data_ov010_0221021c = data_ov010_0220f594;
