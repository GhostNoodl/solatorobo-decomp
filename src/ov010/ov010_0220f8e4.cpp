#include <nitro/fx.h>

// This TU's .rodata (all of it) and its .data up to the copies the static initialiser makes. The
// copied vectors and their sources are weak: the stub loads each through its own pool word, not
// from the section base. All objects are the TU's size-sorted group (order found with solve2.py).
struct Ov010Rot { u16 x, y, z; };
struct Ov010Handler { s32 key; void (*fn)(void); s32 adj; };

extern "C" {

void func_ov010_02202838(void);
void func_ov010_022028ec(void);

extern const Ov010Rot data_ov010_0220efc8;
extern const VecFx32 data_ov010_0220efd0;
extern const VecFx32 data_ov010_0220efdc;
extern const VecFx32 data_ov010_0220efe8;
extern const VecFx32 data_ov010_0220eff4;
extern const VecFx32 data_ov010_0220f000;
extern const Ov010Handler data_ov010_0220f00c[2];
extern const Ov010Rot data_ov010_0220fe30;
extern const VecFx32 data_ov010_0220fe38;
extern const VecFx32 data_ov010_0220fe44;
extern const VecFx32 data_ov010_0220fe50;

static inline fx32 K(fx32 v) { return v; }

__declspec(weak) const VecFx32 data_ov010_0220f000 = {0, 0, 0};
const Ov010Handler data_ov010_0220f00c[2] = {{0, func_ov010_02202838, 0}, {1, func_ov010_022028ec, 0}};
const Ov010Rot data_ov010_0220efc8 = {0, 0, 0};
const Ov010Rot data_ov010_0220fe30 = data_ov010_0220efc8;
const VecFx32 data_ov010_0220efdc = {-0x1000, 0, 0};
const VecFx32 data_ov010_0220efd0 = {0, 0, 0x1000};
__declspec(weak) const VecFx32 data_ov010_0220fe50 = data_ov010_0220f000;
__declspec(weak) const VecFx32 data_ov010_0220efe8 = {0, 0x1000, 0};
const VecFx32 data_ov010_0220fe38 = {K(0x1000), K(0), K(0)};
__declspec(weak) const VecFx32 data_ov010_0220fe44 = data_ov010_0220efe8;
const VecFx32 data_ov010_0220eff4 = {0, 0x1be, -0x125e};

}
