#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, next to this TU's effect
// names and the pointers to them. Other functions read the first pointer, an offset, the zero
// vector and the rotation copy.
extern const char *const data_ov010_0220ef68;
extern const VecFx32 data_ov010_0220ef80;
extern const VecFx32 data_ov010_0220ef8c;
extern const VecFx16 data_ov010_0220fd70;
extern char data_ov010_0220fd76[];
extern char data_ov010_0220fd82[];
extern char data_ov010_0220fd9c[];
extern char data_ov010_0220fdab[];
static const char *const data_ov010_0220ef74 = data_ov010_0220fdab;
static const char *const data_ov010_0220ef70 = data_ov010_0220fd82;
static const char *const data_ov010_0220ef6c = data_ov010_0220fd76;
const char *const data_ov010_0220ef68 = data_ov010_0220fd9c;
static const VecFx16 data_ov010_0220ef78 = {0, 0, 0};
const VecFx32 data_ov010_0220ef80 = {0, FX32_ONE, 0};
const VecFx32 data_ov010_0220ef8c = {0, 0, 0};
const VecFx16 data_ov010_0220fd70 = data_ov010_0220ef78;
char data_ov010_0220fd76[] = "ef3di1cas10";
char data_ov010_0220fd82[] = "ef3di1cas11";
static const VecFx32 data_ov010_0220fd90 = data_ov010_0220ef8c;
