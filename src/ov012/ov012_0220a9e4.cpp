#include <nitro/fx.h>

// This TU's .rodata from its base to the vector the static initialiser copies, and its .data up to
// the copy. The copied vector and its source are weak: the stub loads each through its own pool
// word, not from the section base. The objects before the empty asm function are the TU's
// size-sorted group (order found with solve2.py); the rest keep definition order.
struct Ov012Rot { u16 x, y, z; };

extern "C" {

extern const char *const data_ov012_0220a57c;
extern const char *const data_ov012_0220a580;
extern const char *const data_ov012_0220a584;
extern const Ov012Rot data_ov012_0220a588;
extern const s16 data_ov012_0220a58e[6];
extern const s16 data_ov012_0220a59a[4];
extern const s16 data_ov012_0220a5a2[5];
extern const VecFx32 data_ov012_0220a5ac[3];
extern const VecFx32 data_ov012_0220a5d0;
extern const Ov012Rot data_ov012_0220afa0;
extern char data_ov012_0220afa6[];
extern char data_ov012_0220afac[];
extern char data_ov012_0220afb2[];
extern const VecFx32 data_ov012_0220afb8;

const Ov012Rot data_ov012_0220a588 = {0, 0, 0};
char data_ov012_0220afa6[] = "nut00";
char data_ov012_0220afac[] = "att00";
const Ov012Rot data_ov012_0220afa0 = data_ov012_0220a588;
const char *const data_ov012_0220a580 = data_ov012_0220afb2;
const char *const data_ov012_0220a584 = data_ov012_0220afac;
const char *const data_ov012_0220a57c = data_ov012_0220afa6;
const s16 data_ov012_0220a58e[6] = {700, 600, 500, 0x5fff, 0, 0};
char data_ov012_0220afb2[] = "run00";

static asm void Ov012_Dummy(void) {}

const s16 data_ov012_0220a59a[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a5a2[5] = {0, 0x4cd, 0, 0, -1};
const VecFx32 data_ov012_0220a5ac[3] = {{-0x34cd, 0x2000, 0x2333}, {-0xccd, 0, 0x2000}, {0, 0x1800, -0x1800}};
__declspec(weak) const VecFx32 data_ov012_0220a5d0 = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov012_0220afb8 = data_ov012_0220a5d0;

}
