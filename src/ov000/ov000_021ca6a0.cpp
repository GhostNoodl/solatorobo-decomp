#include <nitro/fx.h>

// The photo block at 0x021cb9dc is not one struct: it is five objects (name pointer, rotation,
// "photo01", a pair of name pointers, "photo00"), so the whole TU prefix is one size-sorted group
// and the copied vector can be initialised before the rotation while still sitting last. The copied
// vector and its source are weak (each has its own pool word). Definition order found with solve2.py.

struct Ov000Rot { u16 x, y, z; };

extern "C" {
extern const fx32 data_ov000_021cb9d8;
extern const char *const data_ov000_021cb9dc;
extern const Ov000Rot data_ov000_021cb9e0;
extern char data_ov000_021cb9e6[8];
extern const char *const data_ov000_021cb9f0[2];
extern char data_ov000_021cb9f8[8];
extern const VecFx32 data_ov000_021cba00;
extern const fx32 data_ov000_021c9bf4;
extern const char *const data_ov000_021c9bf8;
extern const char *const data_ov000_021c9bfc;
extern const Ov000Rot data_ov000_021c9c00;
extern const s32 data_ov000_021c9c08[2];
extern const VecFx32 data_ov000_021c9c10;
extern const VecFx32 data_ov000_021c9c1c;

const fx32 data_ov000_021cb9d8 = FX_Div(256 * FX32_ONE, 15 * FX32_ONE);
const Ov000Rot data_ov000_021c9c00 = {0, 0, 0};
const s32 data_ov000_021c9c08[2] = {3, 4};
__declspec(weak) const VecFx32 data_ov000_021c9c1c = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov000_021cba00 = data_ov000_021c9c1c;
const char *const data_ov000_021c9bfc = data_ov000_021cb9e6;
const char *const data_ov000_021c9bf8 = data_ov000_021cb9f8;
const Ov000Rot data_ov000_021cb9e0 = data_ov000_021c9c00;
const VecFx32 data_ov000_021c9c10 = {0x60000, 0x60000, FX32_ONE};
const fx32 data_ov000_021c9bf4 = FX32_ONE;
char data_ov000_021cb9f8[8] = "photo00";
const char *const data_ov000_021cb9dc = data_ov000_021c9bfc;
char data_ov000_021cb9e6[8] = "photo01";
const char *const data_ov000_021cb9f0[2] = {data_ov000_021c9bf8, data_ov000_021c9bfc};
}
