#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, a 6-byte table and offsets. Other functions read all but the
// zero objects.
extern const char *const data_ov009_02215ee4;
extern const u8 data_ov009_02215ef0[6];
extern const VecFx32 data_ov009_02215efc;
extern const VecFx32 data_ov009_02215f08;
extern const VecFx32 data_ov009_02215f14;
extern char data_ov009_0221727e[];
extern char data_ov009_02217284[];
extern char data_ov009_0221728a[];
static const VecFx16 data_ov009_02215ef6 = {0, 0, 0};
static const VecFx16 data_ov009_02217278 = data_ov009_02215ef6;
static const char *const data_ov009_02215ee8 = data_ov009_02217284;
const char *const data_ov009_02215ee4 = data_ov009_0221727e;
char data_ov009_0221727e[] = "nut00";
char data_ov009_0221728a[] = "att00";
const VecFx32 data_ov009_02215f14 = {0, 0x1800, -0xa000};
char data_ov009_02217284[] = "run00";
static const char *const data_ov009_02215eec = data_ov009_0221728a;
const VecFx32 data_ov009_02215f08 = {0, 0, 0x3000};
static const VecFx32 data_ov009_02215f20 = {0, 0, 0};
const VecFx32 data_ov009_02215efc = {0, 0x4000, -0x8000};
static const VecFx32 data_ov009_02217290 = data_ov009_02215f20;
const u8 data_ov009_02215ef0[6] = {0x0a, 0x1a, 0x05, 0x0d, 0, 0};
