#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, two angle tables and six vectors. Other functions read the
// pointers, the tables and the named vectors; the unnamed ones are read through offsets.
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Ov003Blk12;

extern const char *const data_ov003_021f6a80;
extern const s16 data_ov003_021f6a96[4];
extern const s16 data_ov003_021f6a9e[5];
extern const Ov003Blk12 data_ov003_021f6aa8;
extern const Ov003Blk12 data_ov003_021f6ab4;
extern const Ov003Blk12 data_ov003_021f6ac0;
extern const VecFx32 data_ov003_021f6acc;
extern const VecFx32 data_ov003_021f6ad8;
extern char data_ov003_021f90e0[];
extern char data_ov003_021f90e6[];
extern char data_ov003_021f90ec[];
extern char data_ov003_021f90f8[];
const s16 data_ov003_021f6a9e[5] = {0x2d, 0x5b, 0xb6, 0x16c, 0x2d8};
static const char *const data_ov003_021f6a88 = data_ov003_021f90e0;
static const char *const data_ov003_021f6a8c = data_ov003_021f90ec;
const VecFx32 data_ov003_021f6ad8 = {0, 0, 0};
const char *const data_ov003_021f6a80 = data_ov003_021f90f8;
static const char *const data_ov003_021f6a84 = data_ov003_021f90e6;
const s16 data_ov003_021f6a96[4] = {0x5b, 0xb6, 0x16c, 0x2d8};
const Ov003Blk12 data_ov003_021f6ab4 = {0xe66, 0xe66, 0xe66};
char data_ov003_021f90f8[] = "act00";
const VecFx32 data_ov003_021f6acc = {0, FX32_ONE, 0};
char data_ov003_021f90e6[] = "run00";
char data_ov003_021f90ec[] = "att00";
const Ov003Blk12 data_ov003_021f6aa8 = {0x2000, 0x1000, 0x2000};
const Ov003Blk12 data_ov003_021f6ac0 = {0x8cd, 0x8cd, 0x8cd};
char data_ov003_021f90e0[] = "nut00";
static const VecFx32 data_ov003_021f6ae4 = {0, 0, 0};
static const VecFx16 data_ov003_021f6a90 = {0, 0, 0};
static const VecFx16 data_ov003_021f90f2 = data_ov003_021f6a90;
static const VecFx32 data_ov003_021f9100 = data_ov003_021f6ae4;
