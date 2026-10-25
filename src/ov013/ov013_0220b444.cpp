#include <nitro/fx.h>

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// spot block. The objects before the empty asm function are the TU's size-sorted group (definition
// order found with solve2.py); the vectors after it keep definition order. The spot block is one
// object: its far[] entries are initialised before the separate near-spot array.
struct Ov013Rot { u16 x, y, z; };
struct Ov013Spot { VecFx32 pos; u16 rot; };
struct Ov013SpotBlock { char name[16]; void (*fn[6])(void); Ov013Spot far[4]; };

extern "C" {

void func_ov013_02204450(void);
void func_ov013_021fed50(void);
void func_ov013_02204448(void);
void func_ov013_02204444(void);
void func_ov013_0220428c(void);
void func_ov013_022043f8(void);

extern const s32 data_ov013_0220aedc;
extern const s32 data_ov013_0220aef8;
extern const s32 data_ov013_0220af0c;
extern const Ov013Rot data_ov013_0220af18;
extern const s16 data_ov013_0220af1e[4];
extern const VecFx32 data_ov013_0220af28;
extern const VecFx32 data_ov013_0220af34;
extern const VecFx32 data_ov013_0220af40[2];
extern const VecFx32 data_ov013_0220af58[3];
extern char data_ov013_0220b89c[];
extern char data_ov013_0220b8a2[];
extern char data_ov013_0220b8a8[];
extern char data_ov013_0220b8ae[];
extern char data_ov013_0220b8b4[];
extern char data_ov013_0220b8ba[];
extern char data_ov013_0220b8c0[];
extern char data_ov013_0220b8c6[];
extern const Ov013Rot data_ov013_0220b8cc;
extern char data_ov013_0220b8d2[];
extern const VecFx32 data_ov013_0220b8d8;
extern char data_ov013_0220b8e4[];
extern char data_ov013_0220b8f0[];
extern const Ov013SpotBlock data_ov013_0220b930;
extern const Ov013Spot data_ov013_0220b900[3];
extern const VecFx32 data_ov013_0220af7c;
extern const VecFx32 data_ov013_0220af88;
extern const VecFx32 data_ov013_0220af94;
extern const VecFx32 data_ov013_0220afa0;
extern const VecFx32 data_ov013_0220afac;
extern const VecFx32 data_ov013_0220afb8;
extern const VecFx32 data_ov013_0220afc4;
extern const char *const data_ov013_0220aee0;
extern const char *const data_ov013_0220aee4;
extern const char *const data_ov013_0220aee8;
extern const char *const data_ov013_0220aeec;
extern const char *const data_ov013_0220aef0;
extern const char *const data_ov013_0220aef4;
extern const char *const data_ov013_0220aefc;
extern const char *const data_ov013_0220af00;
extern const char *const data_ov013_0220af04;
extern const char *const data_ov013_0220af08;
extern const char *const data_ov013_0220af10;
extern const char *const data_ov013_0220af14;

const char *const data_ov013_0220af14 = data_ov013_0220b8ba;
const Ov013Rot data_ov013_0220b8cc = data_ov013_0220af18;
const Ov013Rot data_ov013_0220af18 = {0, 0, 0};
const VecFx32 data_ov013_0220af58[3] = {{0, 0, -0x7000}, {-0x1464a, 0x2000, -0xad64}, {0xa89c, 0xc642, 0xc4cd}};
const VecFx32 data_ov013_0220b8d8 = data_ov013_0220af28;
const VecFx32 data_ov013_0220af40[2] = {{0, 0x2000, -0x2666}, {-0x14d1, 0x4cd, 0}};
const char *const data_ov013_0220aefc = data_ov013_0220b8c0;
char data_ov013_0220b8f0[] = "ef/effect3dhsn";
const char *const data_ov013_0220aee0 = data_ov013_0220b89c;
const Ov013SpotBlock data_ov013_0220b930 = {"SHR2", {func_ov013_02204450, func_ov013_021fed50, func_ov013_02204448, func_ov013_02204444, func_ov013_0220428c, func_ov013_022043f8}, {{data_ov013_0220afa0, 0xde4e}, {data_ov013_0220afac, 0x1b00}, {data_ov013_0220afb8, 0xaa65}, {data_ov013_0220afc4, 0x6b00}}};
const char *const data_ov013_0220aef4 = data_ov013_0220b8ae;
char data_ov013_0220b8b4[] = "att01";
const char *const data_ov013_0220aee8 = data_ov013_0220b8e4;
const s32 data_ov013_0220aedc = 0xff00;
const Ov013Spot data_ov013_0220b900[3] = {{data_ov013_0220af94, 0}, {data_ov013_0220afa0, 0xde4e}, {data_ov013_0220afac, 0x1b00}};
const VecFx32 data_ov013_0220af34 = {0, 0, -0x3000};
const s32 data_ov013_0220af0c = 0x2000;
const char *const data_ov013_0220af10 = data_ov013_0220b8a2;
const char *const data_ov013_0220aef0 = data_ov013_0220b8d2;
char data_ov013_0220b8c0[] = "att10";
const char *const data_ov013_0220af04 = data_ov013_0220b8a8;
char data_ov013_0220b89c[] = "nut00";
char data_ov013_0220b8d2[] = "nut01";
char data_ov013_0220b8a8[] = "run00";
const char *const data_ov013_0220aee4 = data_ov013_0220b8f0;
const VecFx32 data_ov013_0220af28 = {0, 0, 0};
char data_ov013_0220b8ba[] = "att02";
const s32 data_ov013_0220aef8 = 8;
char data_ov013_0220b8e4[] = "ef3di1hsn00";
const char *const data_ov013_0220af00 = data_ov013_0220b8c6;
const s16 data_ov013_0220af1e[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const char *const data_ov013_0220af08 = data_ov013_0220b8b4;
char data_ov013_0220b8c6[] = "dmg00";
char data_ov013_0220b8ae[] = "att00";
const char *const data_ov013_0220aeec = data_ov013_0220b89c;
char data_ov013_0220b8a2[] = "nut10";

static asm void ov013_0220b444_order() {
}

const VecFx32 data_ov013_0220af7c = {0x6000, 0x6000, 0x6000};
const VecFx32 data_ov013_0220af88 = {0x9000, 0x6000, 0x9000};
const VecFx32 data_ov013_0220af94 = {-0x212b, 0x2000, -0xb3a2};
const VecFx32 data_ov013_0220afa0 = {0xf189, 0x2000, -0x9c21};
const VecFx32 data_ov013_0220afac = {-0xd66a, 0x2000, -0x9323};
const VecFx32 data_ov013_0220afb8 = {0x56bc, 0x2000, 0xa9ec};
const VecFx32 data_ov013_0220afc4 = {-0xa8c9, 0x2000, 0xa91f};

}
