#include <nitro/fx.h>

// This TU's .rodata from its base to the last vector the static initialiser copies, and its .data
// up to the second copy. The copied vectors and their sources are weak: the stub loads each through
// its own pool word, not from the section base. Everything follows the empty asm function, so it
// keeps definition (address) order.
struct Ov014Rot { u16 x, y, z; };
struct Ov014Res { const char *name; s32 n; };

extern "C" {

extern const char *const data_ov014_02216500[4];
extern const s16 data_ov014_02216510[3];
extern const Ov014Rot data_ov014_02216516;
extern const s32 data_ov014_0221651c[2];
extern const s32 data_ov014_02216524[2];
extern const s32 data_ov014_0221652c[2];
extern const s32 data_ov014_02216534[2];
extern const s32 data_ov014_0221653c[2];
extern const s32 data_ov014_02216544[2];
extern const s32 data_ov014_0221654c[2];
extern const s32 data_ov014_02216554[2];
extern const s32 data_ov014_0221655c[2];
extern const VecFx32 data_ov014_02216564;
extern const VecFx32 data_ov014_02216570;
extern const VecFx32 data_ov014_0221657c;
extern const s32 data_ov014_02216588[6];
extern const s32 data_ov014_022165a0[6];
extern const VecFx32 data_ov014_022165b8;
extern const s32 data_ov014_022165c4[6];
extern const VecFx32 data_ov014_022165dc;
extern const VecFx32 data_ov014_022165e8;
extern const s32 data_ov014_022165f4[1];
extern const s32 data_ov014_022165f8[2];
extern const VecFx32 data_ov014_02216600;
extern const s32 data_ov014_0221660c[6];
extern const VecFx32 data_ov014_02216624;
extern const VecFx32 data_ov014_02216630;
extern char data_ov014_02217354[];
extern char data_ov014_02217360[];
extern char data_ov014_02217366[];
extern char data_ov014_0221736c[];
extern char data_ov014_02217372[];
extern char data_ov014_0221737e[];
extern char data_ov014_02217398[];
extern char data_ov014_022173a7[];
extern char data_ov014_022173b9[];
extern char data_ov014_022173c8[];
extern char data_ov014_022173ce[];
extern char data_ov014_022173d9[];
extern Ov014Res data_ov014_022173e0;
extern const VecFx32 data_ov014_0221738c;
extern const VecFx32 data_ov014_022173e8;

static asm void Ov014_Dummy(void) {}

const char *const data_ov014_02216500[4] = {data_ov014_02217354, data_ov014_02217360, data_ov014_0221736c, data_ov014_02217366};
const s16 data_ov014_02216510[3] = {0x0, 0x5554, -0x5558};
const Ov014Rot data_ov014_02216516 = {0, 0, 0};
const s32 data_ov014_0221651c[2] = {0x2, 0x1f40000};
const s32 data_ov014_02216524[2] = {0xb, 0x1e0000};
const s32 data_ov014_0221652c[2] = {0xa, 0x0};
const s32 data_ov014_02216534[2] = {0x780000, 0x3};
const s32 data_ov014_0221653c[2] = {0x960001, 0x3};
const s32 data_ov014_02216544[2] = {0xa0002, 0x20004};
const s32 data_ov014_0221654c[2] = {0x18001800, 0x18001800};
const s32 data_ov014_02216554[2] = {0x18001800, 0x18001800};
const s32 data_ov014_0221655c[2] = {0x96000c, 0x1e0000};
__declspec(weak) const VecFx32 data_ov014_02216564 = {0x0, 0x0, 0x1000};
const VecFx32 data_ov014_02216570 = {0x0, -0x1000, 0x0};
const VecFx32 data_ov014_0221657c = {0x0, 0x2000, 0x0};
const s32 data_ov014_02216588[6] = {0x0, 0x4759a, 0x0, 0x0, -0x5000, 0x4000};
const s32 data_ov014_022165a0[6] = {0x0, 0x0, 0x1800, 0x0, 0x1000, 0x4000};
const VecFx32 data_ov014_022165b8 = {0x0, 0x0, 0x1800};
const s32 data_ov014_022165c4[6] = {0x0, 0x0, 0x1800, 0x0, 0x1800, 0x1000};
const VecFx32 data_ov014_022165dc = {0x0, 0x4759a, 0x0};
const VecFx32 data_ov014_022165e8 = {0x0, 0x4719a, 0xf000};
const s32 data_ov014_022165f4[1] = {0x0};
const s32 data_ov014_022165f8[2] = {0x1000, 0x0};
const VecFx32 data_ov014_02216600 = {0x0, 0x0, 0x9000};
const s32 data_ov014_0221660c[6] = {0x0, -0x1000, 0x0, 0x0, 0x0, -0x1800};
const VecFx32 data_ov014_02216624 = {0x0, 0x0, 0x1800};
__declspec(weak) const VecFx32 data_ov014_02216630 = {0x0, 0x0, 0x0};
char data_ov014_02217354[6] = "run00";
static const Ov014Rot data_ov014_0221735a = data_ov014_02216516;
char data_ov014_02217360[] = "att00";
char data_ov014_02217366[] = "nut00";
char data_ov014_0221736c[] = "att01";
char data_ov014_02217372[] = "ef3di1lcr11";
char data_ov014_0221737e[] = "ef3di1lcr10";
__declspec(weak) const VecFx32 data_ov014_0221738c = data_ov014_02216630;
char data_ov014_02217398[] = "ef/effect3dlcr";
char data_ov014_022173a7[] = "ef3di1lcr12.cceff";
char data_ov014_022173b9[] = "ef/effect3dlcr";
char data_ov014_022173c8[] = "nut01";
char data_ov014_022173ce[] = "blt/b1sha1";
char data_ov014_022173d9[] = "b1sha1";
Ov014Res data_ov014_022173e0 = {data_ov014_02217398, 0x37};
__declspec(weak) const VecFx32 data_ov014_022173e8 = data_ov014_02216564;

}
