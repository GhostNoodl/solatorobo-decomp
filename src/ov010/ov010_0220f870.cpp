#include <nitro/fx.h>

// This TU's .rodata (all of it) and its .data up to the copies the static initialiser makes. The
// copied vectors and their sources are weak: the stub loads each through its own pool word, not
// from the section base.
struct Ov010Rot { u16 x, y, z; };

extern "C" {

extern const s32 data_ov010_0220ef98;
extern const VecFx32 data_ov010_0220efa4;
extern const VecFx32 data_ov010_0220efb0;
extern const VecFx32 data_ov010_0220efbc;
extern const VecFx32 data_ov010_0220fdc8;
extern const VecFx32 data_ov010_0220fde0;

static inline fx32 K(fx32 v) { return v; }

const s32 data_ov010_0220ef98 = 0x9000;
static const Ov010Rot data_ov010_0220ef9c = {0, 0, 0};
const VecFx32 data_ov010_0220efb0 = {-0x1000, 0, 0};
__declspec(weak) const VecFx32 data_ov010_0220efa4 = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov010_0220efbc = {0, 0x1000, 0};
static const Ov010Rot data_ov010_0220fdc0 = data_ov010_0220ef9c;
__declspec(weak) const VecFx32 data_ov010_0220fdc8 = data_ov010_0220efa4;
static const VecFx32 data_ov010_0220fdd4 = {K(0x1000), K(0), K(0)};
__declspec(weak) const VecFx32 data_ov010_0220fde0 = data_ov010_0220efbc;

}
