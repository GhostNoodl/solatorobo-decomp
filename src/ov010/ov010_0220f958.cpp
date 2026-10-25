#include <nitro/fx.h>

// This TU's .rodata from its base up to the copied vector, and its .data up to the end of the 0x14
// record (the TU's string pool follows). The copied vector and its source are weak: the stub loads
// each through its own pool word. All objects are the TU's size-sorted group (order found with
// solve2.py); the four dynamic initialisers must be defined in the stub's order (rot, vector,
// pointer, record).

struct Ov010Rot { u16 x, y, z; };

extern "C" {

extern const s32 data_ov010_0220f024;
extern const char *const data_ov010_0220f028;
extern const char *const data_ov010_0220f02c;
extern const char *const data_ov010_0220f030;
extern const char *const data_ov010_0220f034;
extern const char *const data_ov010_0220f038;
extern const char *const data_ov010_0220f03c;
extern const char *const data_ov010_0220f040;
extern const char *const data_ov010_0220f044;
extern const char *const data_ov010_0220f048;
extern const char *const data_ov010_0220f04c;
extern const char *const data_ov010_0220f050;
extern const char *const data_ov010_0220f054;
extern const char *const data_ov010_0220f058;
extern const Ov010Rot data_ov010_0220f05c;
extern const Ov010Rot data_ov010_0220f062;
extern const Ov010Rot data_ov010_0220f068;
extern const Ov010Rot data_ov010_0220f06e;
extern const Ov010Rot data_ov010_0220f074;
extern const Ov010Rot data_ov010_0220f07a;
extern const Ov010Rot data_ov010_0220f080;
extern const Ov010Rot data_ov010_0220f086;
extern const Ov010Rot data_ov010_0220f08c;
extern const Ov010Rot data_ov010_0220f092;
extern const u8 data_ov010_0220f098[8];
extern const u16 data_ov010_0220f0a0[4];
extern const VecFx32 data_ov010_0220f0a8;
extern const char *const data_ov010_0220fefc;
extern char data_ov010_0220ff00[];
extern char data_ov010_0220ff06[];
extern char data_ov010_0220ff0c[];
extern char data_ov010_0220ff12[];
extern char data_ov010_0220ff18[];
extern char data_ov010_0220ff1e[];
extern char data_ov010_0220ff24[];
extern char data_ov010_0220ff2a[];
extern char data_ov010_0220ff30[];
extern char data_ov010_0220ff36[];
extern const Ov010Rot data_ov010_0220ff3c;
extern char data_ov010_0220ff42[];
extern const VecFx32 data_ov010_0220ff48;
extern char data_ov010_0220ff54[];
extern char data_ov010_0220ff60[];
extern const fx32 data_ov010_0220ff70[5];

static inline fx32 K(fx32 v) { return v; }

const Ov010Rot data_ov010_0220f062 = {0x0, 0x7fff, 0x0};
char data_ov010_0220ff24[] = "nut02";
const u16 data_ov010_0220f0a0[4] = {0x1800, 0x1800, 0x1800, 0x1733};
char data_ov010_0220ff60[] = "ef/effect3dzai";
const char *const data_ov010_0220f058 = data_ov010_0220ff00;
const Ov010Rot data_ov010_0220f05c = {0, 0, 0};
const Ov010Rot data_ov010_0220f07a = {0x0, 0x7fff, 0x0};
const Ov010Rot data_ov010_0220ff3c = data_ov010_0220f05c;
const Ov010Rot data_ov010_0220f092 = {0x0, 0xff, 0x0};
char data_ov010_0220ff54[] = "ef3di1zai00";
const Ov010Rot data_ov010_0220f086 = {0x10ce, 0x6c1c, 0x0};
char data_ov010_0220ff36[] = "dmg13";
const Ov010Rot data_ov010_0220f08c = {0xd73, 0x801c, 0x0};
__declspec(weak) const VecFx32 data_ov010_0220f0a8 = {0, 0, 0};
const u8 data_ov010_0220f098[8] = {0, 1, 2, 2, 2, 2, 2, 0};
char data_ov010_0220ff06[] = "att00";
const char *const data_ov010_0220f040 = data_ov010_0220ff12;
char data_ov010_0220ff1e[] = "nut01";
const Ov010Rot data_ov010_0220f074 = {0x0, 0x0, 0x0};
__declspec(weak) const VecFx32 data_ov010_0220ff48 = data_ov010_0220f0a8;
char data_ov010_0220ff12[] = "att10";
const char *const data_ov010_0220f02c = data_ov010_0220ff06;
const char *const data_ov010_0220f034 = data_ov010_0220ff42;
const char *const data_ov010_0220fefc = data_ov010_0220f058;
const char *const data_ov010_0220f050 = data_ov010_0220ff1e;
const char *const data_ov010_0220f038 = data_ov010_0220ff36;
const fx32 data_ov010_0220ff70[5] = {-0x3302, -0x82b0, 0x33d7, -0x1d37, K(-0xdb33)};
const char *const data_ov010_0220f028 = data_ov010_0220ff30;
char data_ov010_0220ff42[] = "att02";
const char *const data_ov010_0220f03c = data_ov010_0220ff18;
const char *const data_ov010_0220f04c = data_ov010_0220ff54;
char data_ov010_0220ff0c[] = "att01";
const s32 data_ov010_0220f024 = 0xff00;
char data_ov010_0220ff18[] = "gun00";
const char *const data_ov010_0220f030 = data_ov010_0220ff0c;
char data_ov010_0220ff2a[] = "nut03";
char data_ov010_0220ff30[] = "dwn00";
char data_ov010_0220ff00[] = "run00";
const char *const data_ov010_0220f044 = data_ov010_0220ff2a;
const Ov010Rot data_ov010_0220f068 = {0x10e8, 0xd87e, 0x0};
const Ov010Rot data_ov010_0220f080 = {0x0, 0x7fff, 0x0};
const char *const data_ov010_0220f048 = data_ov010_0220ff24;
const char *const data_ov010_0220f054 = data_ov010_0220ff60;
const Ov010Rot data_ov010_0220f06e = {0xde8, 0xff7e, 0x0};

}
