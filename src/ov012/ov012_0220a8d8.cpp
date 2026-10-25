#include <nitro/fx.h>

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last effect record. Everything follows the empty asm function, so both sections keep definition
// order. The three handler tables are vtables (two zero words, then 41 handlers); the TU's
// functions point objects at the handler part.
struct Ov012Rot { u16 x, y, z; };
struct Ov012EffPart { const char *name; s16 v[8]; };
struct Ov012Rec {
    const char *effect;
    s32 id;
    VecFx32 pos;
    s32 unk_14;
    Ov012EffPart part[2];
    const char *file;
    s32 scale;
};
typedef void (*Ov012Fn)(void);

extern "C" {

void func_ov003_021d16cc(void);
void func_ov012_021ffb90(void);
void func_0205e958(void);
void func_ov012_021ffb9c(void);
void func_ov000_0218cfc8(void);
void func_ov000_0218d17c(void);
void func_ov000_0218d190(void);
void func_ov012_02201cb8(void);
void func_ov012_021ffaa8(void);
void func_ov012_021ffb18(void);
void func_ov012_021ffba8(void);
void func_ov012_021ffd34(void);
void func_ov012_02201cb4(void);
void func_ov012_02201cb0(void);
void func_ov003_021d2e28(void);
void func_ov003_021d3008(void);
void func_ov003_021d1b88(void);
void func_ov012_02201c90(void);
void func_ov012_02201c70(void);
void func_ov012_021ffcd0(void);
void func_ov012_02200200(void);
void func_ov003_021d3600(void);
void func_ov003_021d36fc(void);
void func_ov003_021d3a88(void);
void func_ov012_02200cd4(void);
void func_ov012_02200398(void);
void func_ov012_022007a0(void);
void func_ov012_02201d04(void);
void func_ov003_021d4b68(void);
void func_ov012_02201ce4(void);
void func_ov012_02201cd0(void);
void func_ov003_021d4fd8(void);
void func_ov003_021d5348(void);
void func_ov012_022015a0(void);
void func_ov012_022016a4(void);
void func_ov003_021d64f0(void);
void func_ov012_02201ccc(void);
void func_ov012_02201cc8(void);
void func_ov012_02201cc4(void);
void func_ov012_02201cc0(void);
void func_ov012_02201cbc(void);
void func_ov003_021d0fc0(void);
void func_ov000_0218cf5c(void);
void func_ov012_02201d68(void);
void func_ov012_02201d4c(void);
void func_ov012_021fee58(void);
void func_ov012_021fefc8(void);
void func_ov012_021fef64(void);
void func_ov003_021d3524(void);
void func_ov003_021d3d28(void);
void func_ov003_021d452c(void);
void func_ov012_02201d28(void);
void func_ov012_021ff20c(void);
void func_ov003_021d5900(void);
void func_ov012_021ff674(void);
void func_ov012_021fa91c(void);
void func_ov012_021fa80c(void);
void func_ov012_021fa8b8(void);
void func_ov012_021fa724(void);
void func_ov012_021fa794(void);
void func_ov012_021fa9e8(void);
void func_ov012_021fab7c(void);
void func_ov012_021fa978(void);
void func_ov012_021fbe64(void);
void func_ov012_021fbec8(void);
void func_ov012_021fc688(void);
void func_ov012_021fcf1c(void);
void func_ov012_021fcf48(void);
void func_ov012_021fd148(void);
void func_ov012_021fd1b0(void);
void func_ov012_021fba44(void);
void func_ov012_021fbb80(void);
void func_ov012_021fbce0(void);

static asm void ov012_0220a8d8_order() {
}

extern const char *const data_ov012_0220a3c4[2];
extern const Ov012Rot data_ov012_0220a3cc;
extern const Ov012Rot data_ov012_0220a3d2;
extern const Ov012Rot data_ov012_0220a3d8;
extern const Ov012Rot data_ov012_0220a3de;
extern const Ov012Rot data_ov012_0220a3e4;
extern const Ov012Rot data_ov012_0220a3ea;
extern const s16 data_ov012_0220a3f0[4];
extern const s16 data_ov012_0220a3f8[4];
extern const s16 data_ov012_0220a400[4];
extern const VecFx32 data_ov012_0220a408;
extern const VecFx32 data_ov012_0220a414;
extern const VecFx32 data_ov012_0220a420;
extern const VecFx32 data_ov012_0220a42c;
extern const VecFx32 data_ov012_0220a438;
extern const VecFx32 data_ov012_0220a444;
extern const VecFx32 data_ov012_0220a450;
extern const VecFx32 data_ov012_0220a45c;
extern const VecFx32 data_ov012_0220a468;
extern const VecFx32 data_ov012_0220a474;
extern const Ov012Rot data_ov012_0220aaa0;
extern char data_ov012_0220aaa6[];
extern char data_ov012_0220aaac[];
extern char data_ov012_0220aab2[];
extern char data_ov012_0220aabe[];
extern const VecFx32 data_ov012_0220aacc;
extern char data_ov012_0220aad8[];
extern char data_ov012_0220aae7[];
extern char data_ov012_0220aaf9[];
extern char data_ov012_0220ab08[];
extern char data_ov012_0220ab10[];
extern char data_ov012_0220ab1b[];
extern char data_ov012_0220ab21[];
extern char data_ov012_0220ab27[];
extern char data_ov012_0220ab2d[];
extern char data_ov012_0220ab33[];
extern u32 data_ov012_0220ab3c[2];
extern Ov012Fn data_ov012_0220ab44[41];
extern u32 data_ov012_0220abe8[2];
extern Ov012Fn data_ov012_0220abf0[41];
extern u32 data_ov012_0220ac94[2];
extern Ov012Fn data_ov012_0220ac9c[41];
extern const Ov012Rec data_ov012_0220ad40[6];

const char *const data_ov012_0220a3c4[2] = {data_ov012_0220aaa6, data_ov012_0220aaac};
const Ov012Rot data_ov012_0220a3cc = {0x3fff, 0, 0};
const Ov012Rot data_ov012_0220a3d2 = {0xbff4, 0, 0};
const Ov012Rot data_ov012_0220a3d8 = {0xbfff, 0, 0};
const Ov012Rot data_ov012_0220a3de = {0x3fff, 0, 0};
const Ov012Rot data_ov012_0220a3e4 = {0, 0, 0};
const Ov012Rot data_ov012_0220a3ea = {0x3fff, 0, 0};
const s16 data_ov012_0220a3f0[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a3f8[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a400[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const VecFx32 data_ov012_0220a408 = {0, 0x3000, 0};
const VecFx32 data_ov012_0220a414 = {0, 0x4000, -0x4000};
const VecFx32 data_ov012_0220a420 = {0, 0x1333, 0x1800};
const VecFx32 data_ov012_0220a42c = {0x7000, 0, -0xa000};
const VecFx32 data_ov012_0220a438 = {0x3800, 0, 0x3000};
const VecFx32 data_ov012_0220a444 = {0x3000, 0, 0};
const VecFx32 data_ov012_0220a450 = {0x1000, 0x1000, 0x1333};
const VecFx32 data_ov012_0220a45c = {0x2800, 0, 0x3800};
const VecFx32 data_ov012_0220a468 = {0, 0x1333, 0x4000};
const VecFx32 data_ov012_0220a474 = {0, 0, 0};

const Ov012Rot data_ov012_0220aaa0 = data_ov012_0220a3e4;
char data_ov012_0220aaa6[] = "run00";
char data_ov012_0220aaac[] = "nut00";
char data_ov012_0220aab2[] = "ef3di1ope11";
char data_ov012_0220aabe[] = "ef3di1ope10";
const VecFx32 data_ov012_0220aacc = data_ov012_0220a474;
char data_ov012_0220aad8[] = "ef/effect3dope";
char data_ov012_0220aae7[] = "ef3di1ope12.cceff";
char data_ov012_0220aaf9[] = "ef/effect3dope";
char data_ov012_0220ab08[] = "g1lft01";
char data_ov012_0220ab10[] = "gm/g1lft01";
char data_ov012_0220ab1b[] = "att00";
char data_ov012_0220ab21[] = "nut00";
char data_ov012_0220ab27[] = "gun00";
char data_ov012_0220ab2d[] = "att10";
char data_ov012_0220ab33[] = "att20";
#pragma explicit_zero_data on
u32 data_ov012_0220ab3c[2] = {0, 0};
Ov012Fn data_ov012_0220ab44[41] = {
    func_ov003_021d16cc,
    func_ov012_021ffb90,
    func_0205e958,
    func_ov012_021ffb9c,
    func_ov000_0218cfc8,
    func_ov000_0218d17c,
    func_ov000_0218d190,
    func_ov012_02201cb8,
    func_ov012_021ffaa8,
    func_ov012_021ffb18,
    func_ov012_021ffba8,
    func_ov012_021ffd34,
    func_ov012_02201cb4,
    func_ov012_02201cb0,
    func_ov003_021d2e28,
    func_ov003_021d3008,
    func_ov003_021d1b88,
    func_ov012_02201c90,
    func_ov012_02201c70,
    func_ov012_021ffcd0,
    func_ov012_02200200,
    func_ov003_021d3600,
    func_ov003_021d36fc,
    func_ov003_021d3a88,
    func_ov012_02200cd4,
    func_ov012_02200398,
    func_ov012_022007a0,
    func_ov012_02201d04,
    func_ov003_021d4b68,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    func_ov003_021d4fd8,
    func_ov003_021d5348,
    func_ov012_022015a0,
    func_ov012_022016a4,
    func_ov003_021d64f0,
    func_ov012_02201ccc,
    func_ov012_02201cc8,
    func_ov012_02201cc4,
    func_ov012_02201cc0,
    func_ov012_02201cbc,
};
u32 data_ov012_0220abe8[2] = {0, 0};
Ov012Fn data_ov012_0220abf0[41] = {
    func_ov003_021d16cc,
    func_ov003_021d0fc0,
    func_0205e958,
    func_ov000_0218cf5c,
    func_ov000_0218cfc8,
    func_ov000_0218d17c,
    func_ov000_0218d190,
    func_ov012_02201cb8,
    func_ov012_02201d68,
    func_ov012_02201d4c,
    func_ov012_021fee58,
    func_ov012_021fefc8,
    func_ov012_02201cb4,
    func_ov012_02201cb0,
    func_ov003_021d2e28,
    func_ov003_021d3008,
    func_ov003_021d1b88,
    func_ov012_02201c90,
    func_ov012_02201c70,
    func_ov012_021fef64,
    func_ov003_021d3524,
    func_ov003_021d3600,
    func_ov003_021d36fc,
    func_ov003_021d3a88,
    func_ov003_021d3d28,
    func_ov003_021d452c,
    func_ov012_02201d28,
    func_ov012_02201d04,
    func_ov012_021ff20c,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    func_ov003_021d4fd8,
    func_ov003_021d5348,
    func_ov003_021d5900,
    func_ov012_021ff674,
    func_ov003_021d64f0,
    func_ov012_02201ccc,
    func_ov012_02201cc8,
    func_ov012_02201cc4,
    func_ov012_02201cc0,
    func_ov012_02201cbc,
};
u32 data_ov012_0220ac94[2] = {0, 0};
Ov012Fn data_ov012_0220ac9c[41] = {
    func_ov012_021fa91c,
    func_ov012_021fa80c,
    func_0205e958,
    func_ov012_021fa8b8,
    func_ov000_0218cfc8,
    func_ov000_0218d17c,
    func_ov000_0218d190,
    func_ov012_02201cb8,
    func_ov012_021fa724,
    func_ov012_021fa794,
    func_ov012_021fa9e8,
    func_ov012_021fab7c,
    func_ov012_02201cb4,
    func_ov012_02201cb0,
    func_ov003_021d2e28,
    func_ov003_021d3008,
    func_ov003_021d1b88,
    func_ov012_02201c90,
    func_ov012_02201c70,
    func_ov012_021fa978,
    func_ov012_021fbe64,
    func_ov003_021d3600,
    func_ov003_021d36fc,
    func_ov003_021d3a88,
    func_ov003_021d3d28,
    func_ov012_021fbec8,
    func_ov012_021fc688,
    func_ov012_021fcf1c,
    func_ov012_021fcf48,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    func_ov012_021fd148,
    func_ov003_021d5348,
    func_ov003_021d5900,
    func_ov012_021fd1b0,
    func_ov012_021fba44,
    func_ov012_021fbb80,
    func_ov012_021fbce0,
    func_ov012_02201cc4,
    func_ov012_02201cc0,
    func_ov012_02201cbc,
};

const Ov012Rec data_ov012_0220ad40[6] = {
    {data_ov012_0220aad8, 0x46, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x180, 0x100, 0x33, 0x1a, 0x1a, 0xd}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x100, 0x14d, 0x1a, 0x21, 0xd, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x19, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x180, 0x100, 0x33, 0x1a, 0x1a, 0xd}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x100, 0x14d, 0x1a, 0x21, 0xd, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x12c, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1d, 0x300, 0x300, 0x4d, 0x4d, 0x26, 0x26}}, {data_ov012_0220aabe, {-0x1, 0x19, 0x180, 0x14d, 0x26, 0x21, 0x12, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x14a, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1d, 0x400, 0x400, 0x80, 0x66, 0x40, 0x33}}, {data_ov012_0220aabe, {-0x1, 0x1b, 0x200, 0x14d, 0x33, 0x21, 0x1a, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x1c2, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x280, 0x180, 0x4d, 0x33, 0x26, 0x1a}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x180, 0x14d, 0x26, 0x21, 0x12, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x3e8, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x366, 0x100, 0x66, 0x1a, 0x33, 0xd}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x233, 0x140, 0x33, 0x21, 0x1a, 0x0}}}, data_ov012_0220aae7, 0x1000}
};
}
