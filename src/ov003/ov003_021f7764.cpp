#include <nitro/fx.h>
#include "Main/Math/Rot16.h"

// This TU's .rodata from its base to the last vector the static initialiser copies, and its .data
// up to the copies (the string table after them stays in the gap). All objects are the TU's
// size-sorted group (definition order found with solve2.py). The two copied vectors and their
// sources are weak: the stub loads each through its own pool word, not from the section base.
// The ten name strings are ROM data: their initializers are written into build/ from the
// user's ROM at build time (config/usa/romdata_inc.txt, tools/extract_data.py).


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

char data_ov003_021f79dc[] =
#include "romdata/ov003/021f79dc.inc"
;
__declspec(weak) const VecFx32 data_ov003_021f4394 = {0, 0x1000, 0};
char data_ov003_021f79e2[] =
#include "romdata/ov003/021f79e2.inc"
;
char data_ov003_021f79d0[] =
#include "romdata/ov003/021f79d0.inc"
;
char data_ov003_021f79d6[] =
#include "romdata/ov003/021f79d6.inc"
;
static const Rot16 data_ov003_021f4374 = {0, 0, 0};
static const Rot16 data_ov003_021f7a0c = data_ov003_021f4374;
const VecFx32 data_ov003_021f437c = {0xb, 4, 0xa};
__declspec(weak) const VecFx32 data_ov003_021f4388 = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov003_021f7a20 = data_ov003_021f4388;
char data_ov003_021f7a06[] =
#include "romdata/ov003/021f7a06.inc"
;
static const VecFx32 data_ov003_021f7a14 = {K(0x1000), K(0), K(0)};
char data_ov003_021f79e8[] =
#include "romdata/ov003/021f79e8.inc"
;
char data_ov003_021f7a00[] =
#include "romdata/ov003/021f7a00.inc"
;
char data_ov003_021f79f4[] =
#include "romdata/ov003/021f79f4.inc"
;
char data_ov003_021f79ee[] =
#include "romdata/ov003/021f79ee.inc"
;
__declspec(weak) const VecFx32 data_ov003_021f7a2c = data_ov003_021f4394;
char data_ov003_021f79fa[] =
#include "romdata/ov003/021f79fa.inc"
;

}
