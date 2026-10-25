#include <nitro/fx.h>

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last of the five records the TU's record table points to. The .data objects before the empty asm
// function are the TU's size-sorted group: their definition order (found with the heapsort model)
// gives both the ROM layout and the stub's init order. The rest keeps definition order.
struct Ov010Rot { u16 x, y, z; };
struct Ov010Seg { VecFx32 pos; u16 v[8]; };
struct Ov010Rec { u16 v[8]; const char *name; Ov010Rot rot; VecFx32 a; VecFx32 b; };
typedef void (*Ov010Fn)(void);

extern "C" {

void func_ov010_021fa740(void);
void func_ov010_021fa6a0(void);


extern const s32 data_ov010_0220ebc0;
extern const char *const data_ov010_0220ebc4;
extern const char *const data_ov010_0220ebc8;
extern const char *const data_ov010_0220ebcc;
extern const char *const data_ov010_0220ebd0;
extern const char *const data_ov010_0220ebd4;
extern const char *const data_ov010_0220ebd8;
extern const char *const data_ov010_0220ebdc;
extern const char *const data_ov010_0220ebe0;
extern const Ov010Rot data_ov010_0220ebe4;
extern const Ov010Rot data_ov010_0220ebea;
extern const Ov010Rot data_ov010_0220ebf0;
extern const Ov010Rot data_ov010_0220ebf6;
extern const Ov010Rot data_ov010_0220ebfc;
extern const s16 data_ov010_0220ec02[4];
extern Ov010Fn const data_ov010_0220ec0c[2];
extern const VecFx32 data_ov010_0220ec14;
extern const VecFx32 data_ov010_0220ec20;
extern const VecFx32 data_ov010_0220ec2c;
extern const VecFx32 data_ov010_0220ec38;
extern const VecFx32 data_ov010_0220ec44;
extern const VecFx32 data_ov010_0220ec50;
extern const VecFx32 data_ov010_0220ec5c;
extern const VecFx32 data_ov010_0220ec68;
extern const VecFx32 data_ov010_0220ec74;
extern const VecFx32 data_ov010_0220ec80;
extern const VecFx32 data_ov010_0220ec8c;
extern const VecFx32 data_ov010_0220ec98;
extern const VecFx32 data_ov010_0220eca4;
extern const VecFx32 data_ov010_0220ecb0;
extern const VecFx32 data_ov010_0220ecbc;
extern const VecFx32 data_ov010_0220ecc8;
extern const VecFx32 data_ov010_0220ecd4;
extern const VecFx32 data_ov010_0220ece0;
extern const VecFx32 data_ov010_0220ecec;
extern const VecFx32 data_ov010_0220ecf8;
extern const VecFx32 data_ov010_0220ed04;
extern char data_ov010_0220fa2c[];
extern char data_ov010_0220fa32[];
extern char data_ov010_0220fa38[];
extern const Ov010Rot data_ov010_0220fa3e;
extern char data_ov010_0220fa44[];
extern char data_ov010_0220fa4a[];
extern char data_ov010_0220fa50[];
extern char data_ov010_0220fa56[];
extern char data_ov010_0220fa5c[];
extern const VecFx32 data_ov010_0220fa64;
extern const VecFx32 data_ov010_0220fa70;
extern const VecFx32 data_ov010_0220fa7c;
extern const VecFx32 data_ov010_0220fa88;
extern const Ov010Seg data_ov010_0220fa94;
extern const Ov010Seg data_ov010_0220fab0;
extern const Ov010Rec data_ov010_0220facc;
extern const Ov010Rec data_ov010_0220fb00;
extern const Ov010Rec data_ov010_0220fb34;
extern const Ov010Rec data_ov010_0220fb68;
extern const Ov010Rec data_ov010_0220fb9c;

// The stub stores some vector members as immediates while the member next to them stays static:
// the original computed them with an expression MWCC evaluates in __sinit and folds there. An
// inline identity reproduces that.
static inline fx32 K(fx32 v) { return v; }
const Ov010Rot data_ov010_0220fa3e = data_ov010_0220ebe4;
char data_ov010_0220fa2c[] = "nut00";
char data_ov010_0220fa44[] = "nut01";
char data_ov010_0220fa4a[] = "nut02";
const VecFx32 data_ov010_0220fa88 = data_ov010_0220ec20;
char data_ov010_0220fa5c[] = "nut05";
char data_ov010_0220fa56[] = "nut04";
char data_ov010_0220fa50[] = "nut03";
const VecFx32 data_ov010_0220fa64 = {K(0x1000), K(0), K(0)};
const VecFx32 data_ov010_0220fa70 = data_ov010_0220ec2c;
char data_ov010_0220fa32[] = "run00";
char data_ov010_0220fa38[] = "gun00";
const VecFx32 data_ov010_0220fa7c = {K(0xf619), 0x16000, K(-0x67aa)};
const Ov010Seg data_ov010_0220fa94 = {data_ov010_0220ed04, {0x300, 0x20, 0x1e, 0x10, 0x8, 0xf80, 0x60, 0x10}};
const Ov010Seg data_ov010_0220fab0 = {data_ov010_0220ed04, {0x180, 0x8, 0x1e, 0xa, 0x4, 0xf60, 0x40, 0xa}};

static asm void ov010_0220f5dc_order() {
}

const s32 data_ov010_0220ebc0 = 0xff00;
const char *const data_ov010_0220ebc4 = data_ov010_0220fa32;
const char *const data_ov010_0220ebc8 = data_ov010_0220fa38;
const char *const data_ov010_0220ebcc = data_ov010_0220fa4a;
const char *const data_ov010_0220ebd0 = data_ov010_0220fa56;
const char *const data_ov010_0220ebd4 = data_ov010_0220fa5c;
const char *const data_ov010_0220ebd8 = data_ov010_0220fa50;
const char *const data_ov010_0220ebdc = data_ov010_0220fa44;
const char *const data_ov010_0220ebe0 = data_ov010_0220fa2c;
const Ov010Rot data_ov010_0220ebe4 = {0x0, 0x0, 0x0};
const Ov010Rot data_ov010_0220ebea = {0xfe00, 0x0, 0x0};
const Ov010Rot data_ov010_0220ebf0 = {0x0, 0xbfff, 0x0};
const Ov010Rot data_ov010_0220ebf6 = {0xfc0d, 0x53f4, 0x0};
const Ov010Rot data_ov010_0220ebfc = {0xfb19, 0x8000, 0x0};
const s16 data_ov010_0220ec02[4] = {0x1800, 0x1800, 0x1800, 0x1800};
Ov010Fn const data_ov010_0220ec0c[2] = {func_ov010_021fa740, func_ov010_021fa6a0};
const VecFx32 data_ov010_0220ec14 = {0x0, -0x1000, 0x0};
const VecFx32 data_ov010_0220ec20 = {0x0, 0x0, 0x0};
const VecFx32 data_ov010_0220ec2c = {0x0, 0x1000, 0x0};
const VecFx32 data_ov010_0220ec38 = {0x0, 0x0, 0x1000};
const VecFx32 data_ov010_0220ec44 = {0x0, -0x1000, 0x0};
const VecFx32 data_ov010_0220ec50 = {0x0, 0x61b2, 0x24d5};
const VecFx32 data_ov010_0220ec5c = {0x0, 0x74e9, 0x3e77};
const VecFx32 data_ov010_0220ec68 = {0x0, 0x5580, 0x0};
const VecFx32 data_ov010_0220ec74 = {-0x59ec, 0x5d48, -0x268f};
const VecFx32 data_ov010_0220ec80 = {-0x6571, 0x6d71, -0x34a4};
const VecFx32 data_ov010_0220ec8c = {0xf619, 0x4a1d, -0x67aa};
const VecFx32 data_ov010_0220ec98 = {0xfafa, 0x2996, -0x42bc};
const VecFx32 data_ov010_0220eca4 = {0xdc83, 0x64d9, -0xf629};
const VecFx32 data_ov010_0220ecb0 = {-0x15a19, 0x372b, -0xdd0a};
const VecFx32 data_ov010_0220ecbc = {0x9600, 0x17d9e, 0x0};
const VecFx32 data_ov010_0220ecc8 = {0x0, 0x1000, 0x0};
const VecFx32 data_ov010_0220ecd4 = {-0x15cf, 0x4550, -0x861d};
const VecFx32 data_ov010_0220ece0 = {0x3a619, 0x1cd9e, 0x0};
const VecFx32 data_ov010_0220ecec = {0x4e639, 0x268b, 0x1148};
const VecFx32 data_ov010_0220ecf8 = {0xcf1b, 0x1796, -0xa46f};
const VecFx32 data_ov010_0220ed04 = {-0x1000, 0x0, 0x0};

const Ov010Rec data_ov010_0220facc = {{0x0, 0x0, 0x0, 0x10, 0x400, 0x3000, 0xf20, 0x8}, data_ov010_0220ebe0, data_ov010_0220fa3e, data_ov010_0220fa88, data_ov010_0220ec8c};
const Ov010Rec data_ov010_0220fb00 = {{0x0, 0x0, 0x0, 0x40, 0x2000, 0x0, 0x1000, 0x0}, data_ov010_0220ebd8, data_ov010_0220fa3e, data_ov010_0220fa88, data_ov010_0220ecec};
const Ov010Rec data_ov010_0220fb34 = {{0x0, 0x0, 0x0, 0x20, 0x2000, 0x0, 0x1000, 0x0}, data_ov010_0220ebcc, data_ov010_0220fa3e, data_ov010_0220fa88, {0x19c00 - K(0xf619), -0x16000, K(-0xdd0a)}};
const Ov010Rec data_ov010_0220fb68 = {{0x3, 0x1, 0x1000, 0x0, 0x1000, 0x7000, 0xe00, 0x20}, data_ov010_0220ebc4, data_ov010_0220ebf0, data_ov010_0220ecec, data_ov010_0220ec8c};
const Ov010Rec data_ov010_0220fb9c = {{0x3, 0x1, 0x1000, 0x0, 0x1000, 0x7000, 0xe00, 0x20}, data_ov010_0220ebcc, data_ov010_0220ebf0, data_ov010_0220ece0, data_ov010_0220ec8c};

}
