#include <nitro/fx.h>

// This TU's .rodata from its base to the last vector the static initialiser copies, and its .data
// up to the copies (the string table after them stays in the gap). All objects are the TU's
// size-sorted group (definition order found with solve2.py). The two copied vectors and their
// sources are weak: the stub loads each through its own pool word, not from the section base.

struct Ov003Rot { u16 x, y, z; };

extern "C" {

extern const VecFx32 data_ov003_021f437c;
extern const VecFx32 data_ov003_021f4388;
extern const VecFx32 data_ov003_021f4394;
extern char data_ov003_021f79d0[];
extern char data_ov003_021f79d6[];
extern char data_ov003_021f79dc[];
extern char data_ov003_021f79e2[];
extern char data_ov003_021f79e8[];
extern char data_ov003_021f79ee[];
extern char data_ov003_021f79f4[];
extern char data_ov003_021f79fa[];
extern char data_ov003_021f7a00[];
extern char data_ov003_021f7a06[];
extern const VecFx32 data_ov003_021f7a20;
extern const VecFx32 data_ov003_021f7a2c;

static inline fx32 K(fx32 v) { return v; }

char data_ov003_021f79dc[] = "gun10";
__declspec(weak) const VecFx32 data_ov003_021f4394 = {0, 0x1000, 0};
char data_ov003_021f79e2[] = "att00";
char data_ov003_021f79d0[] = "gun01";
char data_ov003_021f79d6[] = "att11";
static const Ov003Rot data_ov003_021f4374 = {0, 0, 0};
static const Ov003Rot data_ov003_021f7a0c = data_ov003_021f4374;
const VecFx32 data_ov003_021f437c = {0xb, 4, 0xa};
__declspec(weak) const VecFx32 data_ov003_021f4388 = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov003_021f7a20 = data_ov003_021f4388;
char data_ov003_021f7a06[] = "gun00";
static const VecFx32 data_ov003_021f7a14 = {K(0x1000), K(0), K(0)};
char data_ov003_021f79e8[] = "gun11";
char data_ov003_021f7a00[] = "att21";
char data_ov003_021f79f4[] = "att20";
char data_ov003_021f79ee[] = "att10";
__declspec(weak) const VecFx32 data_ov003_021f7a2c = data_ov003_021f4394;
char data_ov003_021f79fa[] = "att01";

}
