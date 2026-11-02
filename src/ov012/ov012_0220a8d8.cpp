#include "ov012/ov012.h"

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last effect record. Everything follows the empty asm function, so both sections keep definition
// order. The three handler tables are vtables (two zero words, then 41 handlers); the TU's
// functions point objects at the handler part. The functions at the end, func_ov012_021fc688 to
// func_ov012_021fdfa0, are part of this TU: they read the constants through the .rodata base plus an offset.
// Round dtC also folded in the files of 0x021fa6a0..0x021fab7c and 0x021fe8b4..0x02200200 (each in
// its own namespace): they point objects at the handler tables and pass the angle tables, which they
// now reach by the TU's own names instead of u8[] externs. Round dtD folded in 0x02200200..0x02201c70
// (two files). The two motion names at the start of .rodata are separate pointers
// (data_ov012_0220a3c4/a3c8), not one const char *const [2]: as an array, func_ov012_02200200
// hoists the name loads above the stores before them (13 lines).
struct Ov012Rot { u16 x, y, z; };
struct Ov012EffPart { const char *name; s16 v[8]; };
struct Ov012Rec {
    const char *effect;
    s32 id;
    Ov012Vec pos;
    s32 unk_14;
    Ov012EffPart part[2];
    const char *file;
    s32 scale;
};
typedef void (*Ov012Fn)(void);

extern "C" {

void Ov012Act_021ffa68_Init(void *self);
void func_0205e958(void *light);
BOOL Ov012Act_021ffa68_IsReady(void *self);
void func_ov000_0218cfc8(void *self);
BOOL func_ov000_0218d17c(void *self);
void func_ov000_0218d190(void *self);
void func_ov012_02201cb8(void);
void *Ov012Act_021ffa68_Dtor(void *self);
void *Ov012Act_021ffa68_DtorDelete(void *self);
void Ov012Act_021ffa68_Start(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_Update(Ov012Act_021ffa68 *self);
void func_ov012_02201cb4(void);
void func_ov012_02201cb0(void);
void func_ov003_021d2e28(void *self);
void func_ov003_021d3008(void *self);
void func_ov012_02201c90(void *self);
void func_ov012_02201c70(void *self);
void func_ov012_021ffcd0(Ov012Act_021ffa68 *self, void *msg);
void func_ov012_02200200(Ov012Act_021ffa68 *self);
void func_ov003_021d36fc(void *self);
void func_ov012_02200cd4(Ov012Act_021ffa68 *self);
void func_ov012_02200398(Ov012Act_021ffa68 *self);
void func_ov012_022007a0(Ov012Act_021ffa68 *self);
void func_ov012_02201d04(void *self);
void func_ov012_02201ce4(void *self);
void func_ov012_02201cd0(void *self);
void func_ov012_022015a0(Ov012Act_021ffa68 *self);
void func_ov012_022016a4(void *self);
void func_ov003_021d64f0(void *self);
void func_ov012_02201ccc(void);
void func_ov012_02201cc8(void);
void func_ov012_02201cc4(void);
void func_ov012_02201cc0(void);
void func_ov012_02201cbc(void);
void *Ov012Act_021fee1c_Dtor(void *self);
void *Ov012Act_021fee1c_DtorDelete(void *self);
void Ov012Act_021fee1c_Start(Ov012Act_021fee1c *self);
void Ov012Act_021fee1c_Update(Ov012Act_021fee1c *self);
void func_ov012_021fef64(Ov012Act_021fee1c *self, void *msg);
void func_ov012_02201d28(void *self);
void func_ov012_021ff20c(Ov012Act_021fee1c *self);
void func_ov012_021ff674(Ov012Act_021fee1c *self);
BOOL Ov012Lift_Draw(Ov012Lift *self);
void Ov012Lift_Init(Ov012Lift *self);
BOOL Ov012Lift_IsReady(Ov012Lift *self);
void *Ov012Lift_Dtor(void *self);
void *Ov012Lift_DtorDelete(void *self);
void Ov012Lift_Start(Ov012Lift *self);
void Ov012Lift_Update(Ov012Lift *self);
void func_ov012_021fa978(Ov012Lift *self, void *msg);
void func_ov012_021fbe64(Ov012Actor *self);
void func_ov012_021fbec8(Ov012Lift *self);
void func_ov012_021fc688(Ov012Lift *self);
void func_ov012_021fcf1c(Ov012Lift *self);
void func_ov012_021fcf48(Ov012Lift *self);
void func_ov012_021fd148(Ov012Actor *self);
void func_ov012_021fd1b0(Ov012Lift *self);
void func_ov012_021fba44(Ov012Lift *self);
void func_ov012_021fbb80(Ov012Lift *self);
void func_ov012_021fbce0(Ov012Lift *self);

static asm void ov012_0220a8d8_order() {
}

extern const Ov012Rot data_ov012_0220a3cc;
extern const Ov012Rot data_ov012_0220a3d2;
extern const Ov012Rot data_ov012_0220a3d8;
extern const Ov012Rot data_ov012_0220a3de;
extern const Ov012Rot data_ov012_0220a3e4;
extern const Ov012Rot data_ov012_0220a3ea;
extern const s16 data_ov012_0220a3f0[4];
extern const s16 data_ov012_0220a3f8[4];
extern const s16 data_ov012_0220a400[4];
extern const Ov012Vec data_ov012_0220a408;
extern const Ov012Vec data_ov012_0220a414;
extern const Ov012Vec data_ov012_0220a420;
extern const Ov012Vec data_ov012_0220a42c;
extern const Ov012Vec data_ov012_0220a438;
extern const Ov012Vec data_ov012_0220a444;
extern const Ov012Vec data_ov012_0220a450;
extern const Ov012Vec data_ov012_0220a45c;
extern const Ov012Vec data_ov012_0220a468;
extern const Ov012Vec data_ov012_0220a474;
extern const Ov012Rot data_ov012_0220aaa0;
extern char data_ov012_0220aaa6[];
extern char data_ov012_0220aaac[];
extern char data_ov012_0220aab2[];
extern char data_ov012_0220aabe[];
extern const Ov012Vec data_ov012_0220aacc;
extern char data_ov012_0220aad8[];
extern char data_ov012_0220aae7[];
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

const char *const data_ov012_0220a3c4 = data_ov012_0220aaa6;
const char *const data_ov012_0220a3c8 = data_ov012_0220aaac;
const Ov012Rot data_ov012_0220a3cc = {0x3fff, 0, 0};
const Ov012Rot data_ov012_0220a3d2 = {0xbff4, 0, 0};
const Ov012Rot data_ov012_0220a3d8 = {0xbfff, 0, 0};
const Ov012Rot data_ov012_0220a3de = {0x3fff, 0, 0};
const Ov012Rot data_ov012_0220a3e4 = {0, 0, 0};
const Ov012Rot data_ov012_0220a3ea = {0x3fff, 0, 0};
const s16 data_ov012_0220a3f0[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a3f8[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a400[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const Ov012Vec data_ov012_0220a408 = {0, 0x3000, 0};
const Ov012Vec data_ov012_0220a414 = {0, 0x4000, -0x4000};
const Ov012Vec data_ov012_0220a420 = {0, 0x1333, 0x1800};
const Ov012Vec data_ov012_0220a42c = {0x7000, 0, -0xa000};
const Ov012Vec data_ov012_0220a438 = {0x3800, 0, 0x3000};
const Ov012Vec data_ov012_0220a444 = {0x3000, 0, 0};
const Ov012Vec data_ov012_0220a450 = {0x1000, 0x1000, 0x1333};
const Ov012Vec data_ov012_0220a45c = {0x2800, 0, 0x3800};
const Ov012Vec data_ov012_0220a468 = {0, 0x1333, 0x4000};
const Ov012Vec data_ov012_0220a474 = {0, 0, 0};

const Ov012Rot data_ov012_0220aaa0 = data_ov012_0220a3e4;
char data_ov012_0220aaa6[] = "run00";
char data_ov012_0220aaac[] = "nut00";
char data_ov012_0220aab2[] = "ef3di1ope11";
char data_ov012_0220aabe[] = "ef3di1ope10";
const Ov012Vec data_ov012_0220aacc = data_ov012_0220a474;
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
    (Ov012Fn)func_ov003_021d16cc,
    (Ov012Fn)Ov012Act_021ffa68_Init,
    (Ov012Fn)func_0205e958,
    (Ov012Fn)Ov012Act_021ffa68_IsReady,
    (Ov012Fn)func_ov000_0218cfc8,
    (Ov012Fn)func_ov000_0218d17c,
    (Ov012Fn)func_ov000_0218d190,
    (Ov012Fn)func_ov012_02201cb8,
    (Ov012Fn)Ov012Act_021ffa68_Dtor,
    (Ov012Fn)Ov012Act_021ffa68_DtorDelete,
    (Ov012Fn)Ov012Act_021ffa68_Start,
    (Ov012Fn)Ov012Act_021ffa68_Update,
    (Ov012Fn)func_ov012_02201cb4,
    (Ov012Fn)func_ov012_02201cb0,
    (Ov012Fn)func_ov003_021d2e28,
    (Ov012Fn)func_ov003_021d3008,
    (Ov012Fn)func_ov003_021d1b88,
    (Ov012Fn)func_ov012_02201c90,
    (Ov012Fn)func_ov012_02201c70,
    (Ov012Fn)func_ov012_021ffcd0,
    (Ov012Fn)func_ov012_02200200,
    (Ov012Fn)func_ov003_021d3600,
    (Ov012Fn)func_ov003_021d36fc,
    (Ov012Fn)func_ov003_021d3a88,
    (Ov012Fn)func_ov012_02200cd4,
    (Ov012Fn)func_ov012_02200398,
    (Ov012Fn)func_ov012_022007a0,
    (Ov012Fn)func_ov012_02201d04,
    (Ov012Fn)func_ov003_021d4b68,
    (Ov012Fn)func_ov012_02201ce4,
    (Ov012Fn)func_ov012_02201cd0,
    (Ov012Fn)func_ov003_021d4fd8,
    (Ov012Fn)func_ov003_021d5348,
    (Ov012Fn)func_ov012_022015a0,
    (Ov012Fn)func_ov012_022016a4,
    (Ov012Fn)func_ov003_021d64f0,
    (Ov012Fn)func_ov012_02201ccc,
    (Ov012Fn)func_ov012_02201cc8,
    (Ov012Fn)func_ov012_02201cc4,
    (Ov012Fn)func_ov012_02201cc0,
    (Ov012Fn)func_ov012_02201cbc,
};
u32 data_ov012_0220abe8[2] = {0, 0};
Ov012Fn data_ov012_0220abf0[41] = {
    (Ov012Fn)func_ov003_021d16cc,
    (Ov012Fn)func_ov003_021d0fc0,
    (Ov012Fn)func_0205e958,
    (Ov012Fn)func_ov000_0218cf5c,
    (Ov012Fn)func_ov000_0218cfc8,
    (Ov012Fn)func_ov000_0218d17c,
    (Ov012Fn)func_ov000_0218d190,
    (Ov012Fn)func_ov012_02201cb8,
    (Ov012Fn)Ov012Act_021fee1c_Dtor,
    (Ov012Fn)Ov012Act_021fee1c_DtorDelete,
    (Ov012Fn)Ov012Act_021fee1c_Start,
    (Ov012Fn)Ov012Act_021fee1c_Update,
    (Ov012Fn)func_ov012_02201cb4,
    (Ov012Fn)func_ov012_02201cb0,
    (Ov012Fn)func_ov003_021d2e28,
    (Ov012Fn)func_ov003_021d3008,
    (Ov012Fn)func_ov003_021d1b88,
    (Ov012Fn)func_ov012_02201c90,
    (Ov012Fn)func_ov012_02201c70,
    (Ov012Fn)func_ov012_021fef64,
    (Ov012Fn)func_ov003_021d3524,
    (Ov012Fn)func_ov003_021d3600,
    (Ov012Fn)func_ov003_021d36fc,
    (Ov012Fn)func_ov003_021d3a88,
    (Ov012Fn)func_ov003_021d3d28,
    (Ov012Fn)func_ov003_021d452c,
    (Ov012Fn)func_ov012_02201d28,
    (Ov012Fn)func_ov012_02201d04,
    (Ov012Fn)func_ov012_021ff20c,
    (Ov012Fn)func_ov012_02201ce4,
    (Ov012Fn)func_ov012_02201cd0,
    (Ov012Fn)func_ov003_021d4fd8,
    (Ov012Fn)func_ov003_021d5348,
    (Ov012Fn)func_ov003_021d5900,
    (Ov012Fn)func_ov012_021ff674,
    (Ov012Fn)func_ov003_021d64f0,
    (Ov012Fn)func_ov012_02201ccc,
    (Ov012Fn)func_ov012_02201cc8,
    (Ov012Fn)func_ov012_02201cc4,
    (Ov012Fn)func_ov012_02201cc0,
    (Ov012Fn)func_ov012_02201cbc,
};
u32 data_ov012_0220ac94[2] = {0, 0};
Ov012Fn data_ov012_0220ac9c[41] = {
    (Ov012Fn)Ov012Lift_Draw,
    (Ov012Fn)Ov012Lift_Init,
    (Ov012Fn)func_0205e958,
    (Ov012Fn)Ov012Lift_IsReady,
    (Ov012Fn)func_ov000_0218cfc8,
    (Ov012Fn)func_ov000_0218d17c,
    (Ov012Fn)func_ov000_0218d190,
    (Ov012Fn)func_ov012_02201cb8,
    (Ov012Fn)Ov012Lift_Dtor,
    (Ov012Fn)Ov012Lift_DtorDelete,
    (Ov012Fn)Ov012Lift_Start,
    (Ov012Fn)Ov012Lift_Update,
    (Ov012Fn)func_ov012_02201cb4,
    (Ov012Fn)func_ov012_02201cb0,
    (Ov012Fn)func_ov003_021d2e28,
    (Ov012Fn)func_ov003_021d3008,
    (Ov012Fn)func_ov003_021d1b88,
    (Ov012Fn)func_ov012_02201c90,
    (Ov012Fn)func_ov012_02201c70,
    (Ov012Fn)func_ov012_021fa978,
    (Ov012Fn)func_ov012_021fbe64,
    (Ov012Fn)func_ov003_021d3600,
    (Ov012Fn)func_ov003_021d36fc,
    (Ov012Fn)func_ov003_021d3a88,
    (Ov012Fn)func_ov003_021d3d28,
    (Ov012Fn)func_ov012_021fbec8,
    (Ov012Fn)func_ov012_021fc688,
    (Ov012Fn)func_ov012_021fcf1c,
    (Ov012Fn)func_ov012_021fcf48,
    (Ov012Fn)func_ov012_02201ce4,
    (Ov012Fn)func_ov012_02201cd0,
    (Ov012Fn)func_ov012_021fd148,
    (Ov012Fn)func_ov003_021d5348,
    (Ov012Fn)func_ov003_021d5900,
    (Ov012Fn)func_ov012_021fd1b0,
    (Ov012Fn)func_ov012_021fba44,
    (Ov012Fn)func_ov012_021fbb80,
    (Ov012Fn)func_ov012_021fbce0,
    (Ov012Fn)func_ov012_02201cc4,
    (Ov012Fn)func_ov012_02201cc0,
    (Ov012Fn)func_ov012_02201cbc,
};

const Ov012Rec data_ov012_0220ad40[6] = {
    {data_ov012_0220aad8, 0x46, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x180, 0x100, 0x33, 0x1a, 0x1a, 0xd}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x100, 0x14d, 0x1a, 0x21, 0xd, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x19, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x180, 0x100, 0x33, 0x1a, 0x1a, 0xd}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x100, 0x14d, 0x1a, 0x21, 0xd, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x12c, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1d, 0x300, 0x300, 0x4d, 0x4d, 0x26, 0x26}}, {data_ov012_0220aabe, {-0x1, 0x19, 0x180, 0x14d, 0x26, 0x21, 0x12, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x14a, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1d, 0x400, 0x400, 0x80, 0x66, 0x40, 0x33}}, {data_ov012_0220aabe, {-0x1, 0x1b, 0x200, 0x14d, 0x33, 0x21, 0x1a, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x1c2, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x280, 0x180, 0x4d, 0x33, 0x26, 0x1a}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x180, 0x14d, 0x26, 0x21, 0x12, 0x0}}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x3e8, data_ov012_0220a468, 0x1a, {{data_ov012_0220aab2, {-0x1, 0x1e, 0x366, 0x100, 0x66, 0x1a, 0x33, 0xd}}, {data_ov012_0220aabe, {-0x1, 0x1d, 0x233, 0x140, 0x33, 0x21, 0x1a, 0x0}}}, data_ov012_0220aae7, 0x1000}
};


// ---- merged from ov012_021fa6a0.cpp
namespace m_021fa6a0 {
extern "C" {

#pragma force_active on
Ov012Lift *Ov012Lift_Ctor(Ov012Lift *self) {
    u8 i;
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220ac9c;
    func_ov000_0218e9c4((u8 *)self + 0x174);
    func_ov000_0218fe1c((u8 *)self + 0x2ac);
    self->unk_10c = 0x40;
    self->unk_110 = 0;
    self->unk_136 = 0;
    self->unk_137 = 0;
    self->unk_112 = 0;
    for (i = 0; i < 3; i++) {
        ((s32 *)((u8 *)self + 0x13c))[i] = -1;
    }
    self->unk_3af = 0;
    self->unk_3ae = 0;
    self->unk_170 = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
void *Ov012Lift_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ac9c;
    Ov012_StopSnd();
    func_ov000_0218fee4((u8 *)self + 0x2ac);
    func_ov000_0218ea20((u8 *)self + 0x174);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
void *Ov012Lift_DtorDelete(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ac9c;
    Ov012_StopSnd();
    func_ov000_0218fee4((u8 *)self + 0x2ac);
    func_ov000_0218ea20((u8 *)self + 0x174);
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}
}
}  // namespace m_021fa6a0

// ---- merged from ov012_021fa80c.cpp
namespace m_021fa80c {
extern "C" {


void Ov012Lift_Init(Ov012Lift *self) {
    func_ov003_021d0fc0(self);
    self->unk_f0 = self->unk_18;
    func_02049564(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 5);
    func_020359d0(data_ov012_0220aaf9, 7, 0);
    if (self->unk_f0 == 1) {
        func_ov000_02187a20(data_ov000_021ccd54, 6);
        {
            const char *b = data_ov012_0220ab08;
            Ov012Names *n = &self->unk_174;
            if (b) {
                STD_CopyString(n->unk_10, data_ov012_0220ab10);
                STD_CopyString(n->unk_30, b);
                n->unk_03_1 = 1;
            }
            n->unk_00 = 0;
        }
    }
}

}
}  // namespace m_021fa80c

// ---- merged from ov012_021fa8b8.cpp
namespace m_021fa8b8 {
extern "C" {
BOOL Ov012Lift_IsReady(Ov012Lift *self) {
    BOOL r = func_ov000_0218cf5c(self);
    r = (r & func_02035b90(data_ov012_0220aaf9, 7)) ? TRUE : FALSE;
    if (self->unk_f0 == 1 && ((s16)self->unk_174.unk_00) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x174)) ? TRUE : FALSE;
    }
    return r;
}
}

struct Ov012_021fa91c {
    u8 unk_00[0x324];
    Ov012Vec cur;
    u8 unk_330[0x64];
    Ov012Vec arr[2];
};
extern "C" {
BOOL Ov012Lift_Draw(Ov012Lift *self) {
    if (self->unk_f0 == 1) {
        u8 i;
        for (i = 0; i < 2; i++) {
            ((Ov012_021fa91c *)self)->cur = ((Ov012_021fa91c *)self)->arr[i];
            func_ov000_021903b4((u8 *)self + 0x2ac);
        }
    }
    return func_ov003_021d16cc(self);
}
}

extern "C" {
void func_ov012_021fa978(Ov012Lift *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_112 = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        self->unk_16c = FLD(u16, msg, 6);
        self->unk_3af = FLD(s32, msg, 8);
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}
}

struct Ov012_021fa9e8 {
    u8 unk_00[0x394];
    Ov012Vec arr[2];
    u8 unk_3ac[2];
};
extern "C" {
extern const u8 data_ov012_0220a498[];
extern const u8 data_ov012_0220a480[];
extern const Ov012Vec data_ov012_0220a4bc[];

void Ov012Lift_Start(Ov012Lift *self) {
    Ov012Actor *o;
    Ov012Sub48 *m;
    func_ov003_021d112c(self);
    o = (Ov012Actor *)Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (o != NULL) {
        FLD(Ov012Flags8, o, 0xa2).b0 = 0;
    }
    VEC_Add(&self->pos, (VecFx32 *)data_ov012_0220a498, &self->pos);
    VEC_Add(&self->pos, (VecFx32 *)data_ov012_0220a480, (VecFx32 *)((u8 *)self + 0x100));
    self->unk_f4 = self->pos;
    self->pos.y -= 0x11000;
    m = self->unk_48;
    m->unk_5c = 0;
    m->unk_60 = 0x3000;
    m->unk_64 = 0;
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    if (self->unk_f0 == 1) {
        u8 i;
        for (i = 0; i < 2; i++) {
            ((Ov012_021fa9e8 *)self)->arr[i] = data_ov012_0220a4bc[i];
            ((Ov012_021fa9e8 *)self)->unk_3ac[i] = 0;
        }
        func_ov000_0218ffdc((u8 *)self + 0x2ac, (u8 *)self + 0x174, 0, 0);
        self->unk_354 = 0x1000;
        self->unk_358 = 0x1000;
        self->unk_35c = 0x1333;
        self->unk_36e.b0 = 1;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a3f8);
        self->unk_170 = 0x1800;
    }
}
}
}  // namespace m_021fa8b8
// ---- merged from 021fab7c
namespace m_021fab7c {




extern "C" {

extern void func_ov012_021fb060(Ov012Lift *self);
extern void func_ov012_021fb300(Ov012Lift *self);
extern void func_ov012_021fb818(Ov012Lift *self);
static inline Ov012Actor *Ov012_FindActorT(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : (Ov012Actor *)ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov012_VSubP(const Ov012Vec *a, const Ov012Vec *b, Ov012Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline u16 Ov012_Pct(u16 *p) {
    return p[0] * 100 / p[1];
}


void Ov012Lift_Update(Ov012Lift *self) {
    Ov012Vec w;
    Ov012Vec v;
    Ov012Actor *pl;
    u8 k;
    u16 s;
    u16 hp;
    u16 pct;
    Ov012Actor *a;
    Ov012V *o;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = (Ov012Actor *)func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    self->unk_93_4 = 1;
    k = self->unk_40->unk_13;
    switch (self->unk_f0) {
    case 0:
        func_ov012_021fb060(self);
        break;
    case 1:
        func_ov012_021fb300(self);
        if (Ov012_GameIdle()) {
            func_ov012_021fb818(self);
        }
        break;
    }
    if (!Ov012_GameIdle()) {
        return;
    }
    if (self->unk_30 & 0x200) {
        if (Rand_UpTo(1)) {
            func_02049f44((SndMgr *)data_02097e4c, 0x503, &self->pos, 0);
        } else {
            func_02049f44((SndMgr *)data_02097e4c, 0x504, &self->pos, 0);
        }
        if (*self->unk_50 == 0) {
            self->unk_40->flags = 0;
            self->unk_40->flags |= 0x200000;
        } else if (self->unk_f0 == 1) {
            s = self->unk_40->state;
            if (k == 0x11) {
                if (s == 0xc) {
                    u16 id = self->target_id;
                    a = Ov012_FindActorT(id);
                    if (a != NULL) {
                        a->unk_1a = 1;
                        self->unk_40->timer = 0;
                        self->unk_40->state = 0xd;
                    }
                }
                if (s >= 0xc) {
                    func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x1000, 0);
                }
            } else if (k == 0x10 && (self->unk_10c & 0x20000000)) {
                if (s == 0xb) {
                    u16 id = self->target_id;
                    a = Ov012_FindActorT(id);
                    if (a != NULL) {
                        a->unk_1a = 1;
                        self->unk_40->timer = 0;
                        self->unk_40->state = 0xc;
                    }
                }
                if (s >= 0xb) {
                    func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x1000, 0);
                }
            }
        }
    }
    hp = self->unk_50[0];
    pct = hp * 100 / self->unk_50[1];
    if ((s32)pct > 0x2d) {
        return;
    }
    if (hp == 0) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 == 0) {
        s32 n;
        s32 z;
        v = self->pos;
        v.y += self->unk_68 >> 1;
        z = self->unk_64;
        Ov012_VecSet(&w, Rand_PlusMinus(z), Rand_PlusMinus(self->unk_68 >> 2), z);
        MTX_MultVec33(&w, (MtxFx33 *)NNS_G3dGlbGetInvV(), &w);
        VEC_Add(&w, &v, &w);
        n = Rand_UpTo(0x4cd);
        {
            Ov012Rot r = data_ov012_0220a3d2;
            o = func_02065f88(0x325, &w);
            o->v0c(n + 0x800);
            o->v30(&r);
        }
        self->unk_140 = FLD(s32, o, 0x24);
        self->unk_154 = w.x - self->pos.x;
        self->unk_158 = w.y - self->pos.y;
        self->unk_15c = w.z - self->pos.z;
        self->unk_b6 = 0xfa - (0xc8 - pct * 4);
    }
    if (self->unk_140 == -1) {
        return;
    }
    o = (Ov012V *)func_020657b0(data_0214a420, (void *)self->unk_140);
    if (o == NULL) {
        return;
    }
    VEC_Add((VecFx32 *)((u8 *)self + 0x154), &self->pos, &w);
    { s32 ox = FLD(s32, o, 0x58); s32 oy = FLD(s32, o, 0x5c); s32 oz = FLD(s32, o, 0x60); w.x -= ox; w.y -= oy; w.z -= oz; }
    o->v20(&w);
}


}
}  // namespace m_021fab7c
// ---- merged from 021fb060
namespace m_021fb060 {

extern "C" {
void func_ov012_021fb060(Ov012Lift *self) {
    void *o;
    s32 r;
    if (!Ov012_GameIdle()) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    o = Ov012_FindRes(0x4000, 0x480f);
    if (self->unk_10c == 0) {
        r = Rand_UpTo(9);
        if (((r >= 0 && r < 3) || func_ov000_021983b0(self->unk_40, 0x12, 2, 1) ||
             func_ov000_021983b0(self->unk_40, 0xe, 4, 1) || o != NULL) &&
            self->unk_136 < 2) {
            u16 *hp = self->unk_50;
            s32 pct = (u16)(hp[0] * 100 / hp[1]);
            self->target_id = 0;
            if (pct > 0x4b) {
                self->unk_10c |= 0x100000;
                self->unk_40->flags |= 0x8000;
            } else if (pct > 0x32) {
                self->unk_10c |= 0x200000;
                self->unk_40->flags |= 0x8000;
            } else if (pct > 0x19) {
                self->unk_10c |= 8;
                self->unk_40->flags |= 0x10000;
            } else {
                self->unk_10c |= 0x10;
                self->unk_40->flags |= 0x20000;
            }
            self->unk_136++;
        } else if ((r >= 3 && r < 10) || self->unk_136 >= 2) {
            if (o == NULL) {
                self->unk_40->flags |= 0x4000;
                self->unk_10c |= 0x20;
            }
            self->unk_136 = 0;
        }
    } else if (self->unk_10c & 1) {
        if (o == NULL) {
            self->unk_110++;
            self->unk_40->timer = 0;
            if (self->unk_10c & 0x20) {
                self->unk_10c ^= 0x20;
            }
            if (self->unk_10c & 1) {
                self->unk_10c ^= 1;
            }
        } else if (func_ov003_021d9edc(0x480f) <= 1) {
            if (self->unk_110++ >= 0x64) {
                if (self->unk_10c & 0x20) {
                    self->unk_10c ^= 0x20;
                }
                if (self->unk_10c & 1) {
                    self->unk_10c ^= 1;
                }
            }
        }
    }
}

void func_ov012_021feacc(Ov012Actor *self, s32 a);
void func_ov012_021fec58(Ov012Actor *self, s32 a);

static inline void Ov012_LiftTick(Ov012Lift *self) {
    if (self->unk_3af & 1) {
        func_ov012_021feacc(self, 0);
    }
    if (self->unk_3af & 2) {
        func_ov012_021feacc(self, 1);
    }
    if (self->unk_3af & 4) {
        func_ov012_021fec58(self, 0);
    }
    if (self->unk_3af & 8) {
        func_ov012_021fec58(self, 1);
    }
}

void func_ov012_021fb300(Ov012Lift *self) {
    u8 c;
    u8 d;
    s32 id;
    Ov012Actor *a = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c14);
    Ov012Actor *b = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c13);
    switch (self->unk_b4) {
    case 0:
        self->unk_b6++;
        if (self->unk_b6 > 10) {
            self->unk_3ae = 0;
            self->unk_3af = 0xc;
            self->unk_b6 = 0;
            self->unk_b4++;
        }
        break;
    case 1:
        Ov012_LiftTick(self);
        if (a != NULL) {
            a->pos = self->arr[0];
        }
        if (b != NULL) {
            b->pos = self->arr[1];
        }
        if (self->unk_3af == 0) {
            c = 1;
            func_ov000_0219bd20(0x5c13, self->kind, 6, 1, 1, &c);
            func_ov000_0219bd20(0x5c14, self->kind, 6, 1, 1, &c);
            self->unk_10c ^= 0x2000000;
            self->unk_36e.b0 = 0;
            self->unk_b4 = 10;
        }
        break;
    case 10:
        if ((self->unk_10c & 0x8000000) || (self->unk_10c & 0x10000000)) {
            c = 2;
            if (self->unk_10c & 0x8000000) {
                id = 0x5c13;
            } else if (self->unk_10c & 0x10000000) {
                id = 0x5c14;
            }
            func_ov000_0219bd20(id, self->kind, 6, 1, 1, &c);
            if (!(self->unk_10c & 0x10)) {
                self->unk_16e = Rand_UpTo(1);
            }
            d = self->unk_16e;
            func_ov000_0219bd20(id, self->kind, 0xe, 1, 1, &d);
            self->unk_10c |= 0x4000000;
            self->unk_3ae = 0;
            self->unk_36e.b0 = true;
            self->unk_b4++;
        }
        break;
    case 11: {
        BOOL go;
        Ov012_LiftTick(self);
        switch (self->unk_16c) {
        case 0x5c13:
            if (b != NULL) {
                b->pos = self->arr[self->unk_16e];
            }
            break;
        case 0x5c14:
            if (a != NULL) {
                Ov012_VecSet(&FLD(Ov012Vec, a, 0x70), a->pos.x, self->arr[self->unk_16e].y, a->pos.z);
            }
            break;
        }
        if (self->unk_3af == 0) {
            go = FALSE;
            self->unk_3ae = 0;
            if (self->unk_10c & 0x4000000) {
                if (self->unk_10c & 0x20000000) {
                    c = 4;
                    self->unk_b4++;
                    go = TRUE;
                } else if (self->unk_10c & 0x40000000) {
                    c = 8;
                    self->unk_b4++;
                    go = TRUE;
                }
            } else {
                go = TRUE;
                c = 1;
                self->unk_36e.b0 = 0;
                self->unk_b4 = 10;
            }
            if (go) {
                func_ov000_0219bd20(self->unk_16c, self->kind, 6, 1, 1, &c);
            }
        }
        break;
    }
    case 12:
        if (self->unk_3af != 0) {
            if (self->unk_10c & 0x4000000) {
                self->unk_10c ^= 0x4000000;
            }
            if (self->unk_10c & 0x20000000) {
                self->unk_10c ^= 0x20000000;
            }
            if (self->unk_10c & 0x40000000) {
                self->unk_10c ^= 0x40000000;
            }
            if (self->unk_10c & 0x8000000) {
                self->unk_10c ^= 0x8000000;
            } else if (self->unk_10c & 0x10000000) {
                self->unk_10c ^= 0x10000000;
            }
            self->unk_b4 = 11;
        }
        break;
    }
    if (!(self->unk_30 & 0x200)) {
        return;
    }
    if (self->unk_50[0] != 0) {
        return;
    }
    c = 0x10;
    func_ov000_0219bd20(0x5c13, self->kind, 6, 1, 1, &c);
    func_ov000_0219bd20(0x5c14, self->kind, 6, 1, 1, &c);
}
}
}  // namespace m_021fb060
// ---- merged from 021fb818
namespace m_021fb818 {

extern "C" {
void func_ov012_021fb818(Ov012Lift *self) {
    u16 *hp = self->unk_50;
    s32 pct;
    u8 k = self->unk_40->unk_13;
    pct = (u16)(hp[0] * 100 / hp[1]);
    if (k == 1) {
        if (self->unk_10c == 0 && self->unk_3af == 0) {
            s32 r = Rand_UpTo(9);
            if ((r >= 4 || func_ov000_021983b0(self->unk_40, 0xf, 4, 1)) && self->unk_136 < 2) {
                s32 r2 = Rand_UpTo(9);
                if (pct >= 0x2d) {
                    if (r2 >= 2) {
                        self->unk_10c |= 0x10;
                    } else {
                        self->unk_10c |= 8;
                    }
                } else if (pct < 0x2d) {
                    if (r2 >= 2) {
                        self->unk_10c |= 8;
                    } else {
                        self->unk_10c |= 0x10;
                    }
                }
                if (self->unk_10c & 8) {
                    self->unk_10c |= 0x400000;
                    self->unk_40->flags |= 0x10000;
                } else if (self->unk_10c & 0x10) {
                    self->unk_40->flags |= 0x20000;
                }
                self->unk_136++;
            } else if (r < 4 || self->unk_136 >= 2) {
                self->unk_136 = 0;
                self->unk_10c |= 0x28400000;
                if (pct > 0x32) {
                    self->unk_10c |= 0x100000;
                    self->unk_40->flags |= 0x8000;
                } else {
                    self->unk_10c |= 0x200000;
                    self->unk_40->flags |= 0x8000;
                }
            }
        } else if (self->unk_10c & 1) {
            if (self->unk_110++ >= 0x14) {
                self->unk_10c ^= 1;
                self->unk_110 = 0;
            }
        }
    }
    if ((self->unk_30 & 0x40) && ((u16)self->unk_112) == 1) {
        Ov012Actor *o = Ov012_FindActor(self->target_id);
        if (o != NULL) {
            o->unk_1a = 1;
            self->unk_40->timer = 0;
            switch (k) {
            case 0x10:
                self->unk_40->state = 0xc;
                break;
            case 0x11:
                self->unk_40->state = 0xd;
                break;
            }
        }
    }
}
}

extern "C" {
void func_ov012_021fba44(Ov012Lift *self) {
    Ov012Sub40 *s;
    Ov012Vec d;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        func_02049f44(data_02097e4c, 0x50, &self->unk_f4, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        s = self->unk_40;
        s->timer++;
        if (s->timer >= 0xa0) {
            if (self->unk_10c & 0x40) {
                self->unk_10c ^= 0x40;
            }
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            if (self->unk_f0 == 0) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
    d.x = self->unk_f4.x - self->pos.x;
    d.y = self->unk_f4.y - self->pos.y;
    d.z = self->unk_f4.z - self->pos.z;
    VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
}
}

extern "C" {
void func_ov012_021feacc(Ov012Actor *self, s32 a);
void func_ov012_021fec58(Ov012Actor *self, s32 a);
void func_ov012_021fbb80(Ov012Lift *self) {
    Ov012Actor *o;
    Ov012Sub40 *s;
    if (self->unk_f0 != 1) {
        return;
    }
    o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c13);
    if (o == NULL) {
        return;
    }
    s = self->unk_40;
    switch (s->state) {
    case 0:
        self->unk_3ae = 0;
        self->unk_3af = 2;
        s->state++;
    case 1:
        if (self->unk_3af & 1) {
            func_ov012_021feacc(self, 0);
        }
        if (self->unk_3af & 2) {
            func_ov012_021feacc(self, 1);
        }
        if (self->unk_3af & 4) {
            func_ov012_021fec58(self, 0);
        }
        if (self->unk_3af & 8) {
            func_ov012_021fec58(self, 1);
        }
        o->pos = self->arr[1];
        if (self->unk_3af == 0) {
            self->unk_40->state++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer < 0x50) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        break;
    }
}
}

extern "C" {
void func_ov012_021feacc(Ov012Actor *self, s32 a);
void func_ov012_021fec58(Ov012Actor *self, s32 a);
void func_ov012_021fbce0(Ov012Lift *self) {
    Ov012Actor *o;
    Ov012Sub40 *s;
    if (self->unk_f0 != 1) {
        return;
    }
    o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c14);
    if (o == NULL) {
        return;
    }
    s = self->unk_40;
    switch (s->state) {
    case 0:
        self->unk_3ae = 0;
        self->unk_3af = 1;
        s->timer = 0;
        self->unk_40->state++;
    case 1:
        if (self->unk_3af & 1) {
            func_ov012_021feacc(self, 0);
        }
        if (self->unk_3af & 2) {
            func_ov012_021feacc(self, 1);
        }
        if (self->unk_3af & 4) {
            func_ov012_021fec58(self, 0);
        }
        if (self->unk_3af & 8) {
            func_ov012_021fec58(self, 1);
        }
        o->pos = self->arr[0];
        if (self->unk_3af == 0) {
            self->unk_40->state++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer < 0x50) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->unk_40->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        self->unk_10c = 0x2000000;
        break;
    }
}
}

extern "C" {
void func_ov012_021fbe64(Ov012Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x89, 0);
    func_ov000_021915a0(self->unk_38);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    self->unk_40->state++;
}
}
}  // namespace m_021fb818

void func_ov012_021fe8b4(Ov012Lift *self, const Ov012Vec *p, u8 n);

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov012_Fx2(Ov012Actor *self, s32 id, const Ov012Rot *base, Ov012Vec *v, const Ov012Vec *off, s32 scale) {
    Ov012V *o;
    Ov012Rot r = *base;
    r.y = self->rot[1];
    o = func_02065f88(id, &self->pos);
    func_01ffc9fc(v, (Ov012Vec *)off, r.y);
    o->v0c(scale);
    o->v20(v);
    o->v30(&r);
    FLD(s32, o, 0xc8) = 0;
    return FLD(s32, o, 0x24);
}

static inline void Ov012_Finish(Ov012Actor *self) {
    if (FLD(u32, self, 0x10c) & 0x10) {
        FLD(u32, self, 0x10c) ^= 0x10;
    }
    if (FLD(u32, self, 0x10c) & 0x1000000) {
        FLD(u32, self, 0x10c) ^= 0x1000000;
    }
    FLD(u8, self, 0x110) = 0;
    FLD(u32, self, 0x10c) |= 1;
    func_ov000_02198360(self->unk_40, 1, 0);
}
struct Ov012Ad40 {
    u8 unk_00[4];
    u16 unk_04;
    u8 unk_06[0x42];
};
static inline void Bec8_S10(Ov012Actor *self, Ov012Ad40 *ent) {
    Ov012SpawnDesc desc;
    Ov012Actor *o;
    FLD(u32, self, 0x10c) ^= 2;
    func_ov000_0218996c(10, 0xf);
    Ov012Spawn_Init(&desc, 0xffff);
    Ov012Spawn_Set(&desc, 0x4833);
    o = func_ov000_02192b24(&desc);
    if (o != NULL) {
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->rot[0] = self->rot[0];
        o->rot[1] = self->rot[1];
        o->rot[2] = self->rot[2];
        FLD(Ov012Ad40 *, o, 0x60) = ent;
        o->unk_1c = FLD(s16, self, 0x170);
        o->v04();
        o->unk_16.b0 = 1;
        o->unk_90 = self->unk_90;
        self->target_id = o->id;
    }
    self->unk_40->timer = 0;
    self->unk_40->state++;
}

static inline void Bec8_S11(Ov012Actor *self, Ov012Ad40 *ent) {
    Ov012Sub40 *s = self->unk_40;
    s->timer++;
    if (s->timer <= ent->unk_04 + 0x28) {
        return;
    }
    self->unk_40->timer = 0;
    if ((FLD(u32, self, 0x10c) & 0x100000) || FLD(u8, self, 0x137) >= FLD(u8, self, 0x138)) {
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x52, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0x500, &self->pos, 0);
        func_02049f44(data_02097e4c, 0xf, &self->pos, 0);
        self->unk_40->state = 0x1e;
    } else if (FLD(u32, self, 0x10c) & 0x200000) {
        FLD(u8, self, 0x137)++;
        self->unk_40->state = 0x14;
    }
}

static inline void Bec8_S14(Ov012Actor *self, Ov012Actor *pl) {
    Ov012Vec v4;
    Ov012Vec v3;
    u16 t;
    Ov012Sub40 *s = self->unk_40;
    s->timer++;
    t = s->timer;
    if (t <= 0x32) {
        Actor_TurnToActor(self, pl, 0xf6);
    }
    if (t == 0x1e) {
        Ov012V *o = func_02065f88(0x5e0, &self->pos);
        func_01ffc9fc(&v3, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
        o->v0c(0x1800);
        o->v20(&v3);
        o->v30(self->rot);
        FLD(s32, o, 0xc8) = 0;
        FLD(s32, self, 0x13c) = FLD(s32, o, 0x24);
        FLD(u32, self, 0x10c) |= 2;
        func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
    }
    if (FLD(u32, self, 0x10c) & 2) {
        Ov012V *e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x13c));
        if (e != NULL) {
            func_01ffc9fc(&v4, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
            VEC_Add(&v4, &self->pos, &v4);
            e->v18(&v4);
            e->v30(self->rot);
        }
    }
    if (t >= 0x50) {
        self->unk_40->state = 10;
    }
}

static inline void Bec8_S1e(Ov012Actor *self) {
    Ov012Vec d2;
    Ov012Sub40 *s;
    d2.x = FLD(s32, self, 0xf4) - self->pos.x;
    d2.y = FLD(s32, self, 0xf8) - self->pos.y;
    d2.z = FLD(s32, self, 0xfc) - self->pos.z;
    VEC_MultAdd(0x66, &d2, &self->pos, &self->pos);
    Actor_TurnToPos(self, &FLD(Ov012Vec, self, 0x100), 0x400);
    s = self->unk_40;
    s->timer++;
    if (s->timer <= 100) {
        return;
    }
    if (FLD(u32, self, 0x10c) & 0x400000) {
        FLD(u32, self, 0x10c) ^= 0x400000;
    }
    if (FLD(u32, self, 0x10c) & 0x100000) {
        FLD(u32, self, 0x10c) ^= 0x100000;
    }
    if (FLD(u32, self, 0x10c) & 0x200000) {
        FLD(u32, self, 0x10c) ^= 0x200000;
    }
    FLD(u8, self, 0x110) = 0;
    FLD(u8, self, 0x137) = 0;
    FLD(u32, self, 0x10c) |= 1;
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov012_021fbec8(Ov012Lift *self) {
    Ov012Actor *pl;
    s32 idx;
    Ov012Ad40 *ent;
    s32 lim;
    u16 t;
    s32 px;
    pl = Actor_GetTarget(self);
    px = pl->pos.x;
    if (self->unk_10c & 0x100000) {
        idx = 0;
    } else if (self->unk_10c & 0x200000) {
        idx = 1;
    }
    ent = (Ov012Ad40 *)&data_ov012_0220ad40[idx];
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x111, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00;
        if (self->unk_f0 == 0) {
            self->unk_138 = 2;
        } else {
            u16 *hp = self->unk_50;
            u16 pct = hp[0] * 100 / hp[1];
            if (pct <= 0x19) {
                self->unk_138 = 2;
            } else {
                self->unk_138 = 1;
            }
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if ((self->unk_10c & 0x400000) && (self->unk_10c & 0x200000)) {
            self->unk_10c |= 0x8000000;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov012Vec d0;
        Ov012Vec t0;
        Ov012Vec d1;
        Ov012Vec v1;
        Ov012Vec v2;
        s32 x;
        s32 y;
        s32 z;
        Ov012Sub40 *s;
        s = self->unk_40;
        s->timer++;
        t = s->timer;
        x = FLD(s32, self, 0x70);
        y = self->unk_f4.y + 0x14cd;
        z = self->pos.z;
        d0.x = x - self->pos.x;
        d0.y = y - self->pos.y;
        d0.z = z - self->pos.z;
        VEC_MultAdd(0x52, &d0, &self->pos, &self->pos);
        switch (self->unk_f0) {
        case 0:
            lim = 0x5a;
            break;
        case 1:
            lim = 0x46;
            break;
        }
        if (t <= lim) {
            self->unk_b8.x = px;
            self->unk_b8.y = self->pos.y;
            self->unk_b8.z = self->pos.z;
            Actor_TurnToActor(self, Actor_GetTarget(self), 0x400);
            t0 = self->unk_b8;
            Actor_MoveToPos(self, &t0, 0);
        } else {
            d1.x = x - self->pos.x;
            d1.y = y - self->pos.y;
            d1.z = z - self->pos.z;
            VEC_MultAdd(0x52, &d1, &self->pos, &self->pos);
        }
        if (t == 0x46) {
            Ov012V *o;
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
            o = func_02065f88(0x5e0, &self->pos);
            func_01ffc9fc(&v1, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
            o->v0c(0x1800);
            o->v20(&v1);
            o->v30(self->rot);
            FLD(s32, o, 0xc8) = 0;
            self->unk_13c = FLD(s32, o, 0x24);
            self->unk_10c |= 2;
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        }
        if (self->unk_10c & 2) {
            Ov012V *e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_13c));
            if (e != NULL) {
                func_01ffc9fc(&v2, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
                VEC_Add(&v2, &self->pos, &v2);
                e->v18(&v2);
                e->v30(self->rot);
            }
        }
        if (t >= 0x78) {
            self->unk_40->state = 10;
        }
        break;
    }
    case 10:
        Bec8_S10(self, ent);
        break;
    case 11:
        Bec8_S11(self, ent);
        break;
    case 0x14:
        Bec8_S14(self, pl);
        break;
    case 0x1e:
        Bec8_S1e(self);
        break;
    }
}

void func_ov012_021fc688(Ov012Lift *self) {
    Ov012Vec dd;
    Ov012Vec arr_[2];

    Ov012Vec v2;
    Ov012SpawnDesc desc;
    Ov012Vec v5;
    Ov012Vec d2;
    Ov012Actor *pl;
    Ov012Ad40 *tbl;
    u16 kind;
    Ov012Vec pp;
    Ov012Sub40 *s;
    u16 t;
    pl = Actor_GetTarget(self);
    pp = pl->pos;
    if (self->unk_10c & 0x400000) {
        tbl = (Ov012Ad40 *)&data_ov012_0220ad40[4];
        kind = 0x4835;
    } else {
        tbl = (Ov012Ad40 *)&data_ov012_0220ad40[2];
        kind = 0x4834;
    }
    s = self->unk_40;
    switch (s->state) {
    case 0:
        self->unk_10c |= 0x800000;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x400, 0);
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if (self->unk_10c & 0x400000) {
            self->unk_10c |= 0x10000000;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov012V *e;
        s->timer++;
        t = s->timer;
        if (t <= 0x5a) {
            Actor_TurnToActor(self, pl, 0x7b);
        }
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = self->unk_f4.y + 0x14cd;
            s32 z = self->pos.z;
            arr_[1].x = x - self->pos.x;
            arr_[1].y = y - self->pos.y;
            arr_[1].z = z - self->pos.z;
        }
        VEC_MultAdd(0x52, &arr_[1], &self->pos, &self->pos);
        if (t == 0x28 || t == 0x5a) {
            Ov012V *o = func_02065f88(0x5e0, &self->pos);
            func_01ffc9fc(&arr_[0], (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
            o->v0c(0x1800);
            o->v20(&arr_[0]);
            o->v30(self->rot);
            FLD(s32, o, 0xc8) = 0;
            self->unk_13c = FLD(s32, o, 0x24);
            self->unk_10c |= 2;
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        }
        if (self->unk_10c & 2) {
            e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_13c));
            if (e != NULL) {
                func_01ffc9fc(&v2, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
                VEC_Add(&v2, &self->pos, &v2);
                e->v18(&v2);
                e->v30(self->rot);
            }
        }
        if (t >= 0x8c) {
            self->unk_40->timer = 0;
            self->unk_40->state = 10;
        }
        break;
    }
    case 10:
        s->timer++;
        if (s->timer == 1) {
            Ov012Actor *o;
            self->unk_10c ^= 2;
            func_ov000_0218996c(10, 0x14);
            Ov012Spawn_Init(&desc, 0xffff);
            Ov012Spawn_Set(&desc, kind);
            o = func_ov000_02192b24(&desc);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
                FLD(Ov012Ad40 *, o, 0x60) = tbl;
                o->unk_1c = self->unk_170;
                o->v04();
                o->unk_16.b0 = 1;
                o->unk_90 = self->unk_90;
                self->target_id = o->id;
            }
            self->unk_13c = Ov012_Fx2(self, 0x68, &data_ov012_0220a3de, &v5, &data_ov012_0220a468, 0x1333);
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
            dd.x = pp.x - self->unk_f4.x;
            dd.y = pp.y - self->unk_f4.y;
            dd.z = pp.z - self->unk_f4.z;
            func_01ffc9fc(&dd, &dd, 0xffff - self->rot[1]);
            self->unk_124.x = 0x7000;
            self->unk_124.y = 0;
            self->unk_124.z = -0xa000;
            if (dd.x <= 0) {
                self->unk_124.x = Ov012_FxMul64d(self->unk_124.x, -0x1000);
            }
        } else if (s->timer >= 0x28) {
            if (self->unk_10c & 0x10000000) {
                self->unk_130 = 0x25;
            } else {
                self->unk_130 = 0x29;
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 11: {
        Ov012Actor *o;
        s->timer++;
        t = s->timer;
        o = Ov012_FindActor(self->target_id);
        if (t < tbl->unk_04) {
            if (self->unk_10c & 0x800000) {
                Actor_TurnToPos(self, &self->unk_124, self->unk_130);
                if (self->rot[1] <= 0xe87a && self->rot[1] >= 0x1776) {
                    self->unk_10c ^= 0x800000;
                    if (self->unk_10c & 0x10000000) {
                        self->unk_10c |= 0x20000000;
                    }
                }
            } else if (!(self->unk_10c & 0x20000000)) {
                switch (self->unk_f0) {
                case 0:
                    if (o != NULL) {
                        o->unk_1a = 1;
                    }
                    self->unk_40->timer = 0;
                    self->unk_40->state++;
                    break;
                case 1:
                    self->unk_124.x = Ov012_FxMul64d(self->unk_124.x, -0x1000);
                    if (!(self->unk_10c & 0x10000000)) {
                        self->unk_130 = 0x21;
                    }
                    Actor_TurnToPos(self, &self->unk_124, self->unk_130);
                    self->unk_10c |= 0x800000;
                    break;
                }
            }
            if (o != NULL) {
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
            }
            if (t % 40 == 1) {
                func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
            }
        } else if (t == tbl->unk_04) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 12:
        s->timer++;
        if (s->timer <= 0x1e) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x52, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        func_02049f44(data_02097e4c, 0x500, &self->pos, 0);
        func_02049f44(data_02097e4c, 0xf, &self->pos, 0);
        self->unk_40->state = 0x1e;
        break;
    case 0x1e:
        d2.x = self->unk_f4.x - self->pos.x;
        d2.y = self->unk_f4.y - self->pos.y;
        d2.z = self->unk_f4.z - self->pos.z;
        VEC_MultAdd(0x66, &d2, &self->pos, &self->pos);
        Actor_TurnToPos(self, &self->unk_100, 0xcd);
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 100) {
            return;
        }
        if (self->unk_10c & 0x400000) {
            self->unk_10c ^= 0x400000;
        }
        if (self->unk_10c & 8) {
            self->unk_10c ^= 8;
        }
        if (self->unk_10c & 0x800000) {
            self->unk_10c ^= 0x800000;
        }
        self->unk_110 = 0;
        self->unk_10c |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}

extern "C" {
void func_ov012_021fd708(Ov012Lift *self);
void func_ov012_021fdfa0(Ov012Lift *self);
void func_ov012_021fcf1c(Ov012Lift *self) {
    switch (self->unk_f0) {
    case 0:
        func_ov012_021fd708(self);
        break;
    case 1:
        func_ov012_021fdfa0(self);
        break;
    }
}
}

extern "C" {
extern char data_ov012_0220ab21[];
extern const Ov012Vec data_ov012_0220a414;
void func_ov012_021fcf48(Ov012Lift *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab21, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0xe, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1: {
        u8 i;
        for (i = 0; i < 4; i++) {
            Ov012SpawnDesc d;
            Ov012Actor *o;
            Ov012Spawn_Init(&d, 0xffff);
            Ov012Spawn_Set(&d, 0x480f);
            o = func_ov000_02192b24(&d);
            if (o != NULL) {
                Ov012Vec t;
                VEC_Add(&self->pos, &data_ov012_0220a414, &t);
                o->pos = t;
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
                o->unk_18 = i;
                o->unk_90 = self->unk_90;
                o->v04();
                o->unk_16.b0 = 1;
                func_ov000_0219bebc(o, self->unk_170);
                if (o->unk_4c != NULL) {
                    o->unk_4c->target = self->id;
                }
            }
        }
        func_02049f44(data_02097e4c, 0x501, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 2:
        s->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        self->unk_110 = 0;
        self->unk_10c |= 1;
        break;
    }
}
}

extern "C" {
void func_ov012_021fd148(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        s->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 5) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}
}

extern "C" {
extern void func_02065804(void *a, s32 b);
extern void func_ov000_02184508(void *g);
extern void func_ov000_02184548(void *g);
extern void *func_ov000_0219b71c(Ov012Vec *pos, Ov012Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d6a3c(Ov012Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov012Actor *self, u8 a);

struct Ov012Bits32 {
    u32 b0 : 1;
    u32 b1 : 31;
};

struct Ov012CamDa {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 3;
};

static inline void Ov012_Flash(u8 a, u8 b, u8 c) {
    FieldState *g = data_ov000_021ccd54;
    g->cam.base.shakeX = 1;
    g->cam.base.shakeY = 1;
    g->cam.base.shakeZ = 1;
    g->cam.base.shakeTime = a;
    g->cam.base.shakeLen = b;
    g->cam.base.shakeCur = c;
}

static inline void Ov012_SetTgt(Ov012Actor *self) {
    s32 y = FLD(s32, self, 0xf8);
    s32 z = FLD(s32, self, 0xfc);
    FLD(s32, self, 0x108) = z;
    FLD(s32, self, 0x100) = self->pos.x;
    FLD(s32, self, 0x104) = y + 0x4800;
}
static inline BOOL Ov012_PlBusy(Ov012Actor *pl) {
    return FLD(Ov012Bits32, pl, 0xb24).b0 ? TRUE : FALSE;
}

void func_ov012_021fd1b0(Ov012Lift *self) {
    Ov012Vec p;
    Ov012Vec q;
    Ov012Vec s;
    Ov012Vec d;
    Ov012Sub40 *w = self->unk_40;
    u16 st = w->state;
    switch (st) {
    case 0: {
        Ov012Actor *o;
        Ov012Sub48 *m48;
        Ov012Sub44 *n;
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480f, 0x15);
        o = Ov012_FindActor(self->target_id);
        if (o != NULL) {
            o->unk_1a = 1;
        }
        self->unk_50[0] = 0;
        m48 = self->unk_48;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_4c->target = 0xffff;
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += 0x5000;
        self->unk_13c = FLD(s32, func_02065f88(0x390, &p), 0x24);
        func_02065f88(5, &p)->v0c(0x5800);
        switch (self->unk_f0) {
        case 0:
            self->unk_114 = 0x3000;
            break;
        case 1:
            self->unk_114 = -0x4000;
            break;
        }
        self->unk_1a = 0x28;
        Ov012_SetTgt(self);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x4000);
            e->v24(0, self->unk_6c, 0);
        }
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_ov000_0218996c(0x19, 0x64);
        self->unk_40->state++;
    }
    case 1: {
        u16 t;
        {
            Ov012Sub40 *q = self->unk_40;
            q->timer++;
            t = q->timer;
        }
        if (t >= 0x96) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        if (t == 10) {
            func_ov000_02184508(data_ov000_021ccd54);
        }
        if (t == 0x1e || t == 0x3c || t == 0x5a || t == 0x78) {
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        break;
    }
    case 2: {
        u16 t;
        w->timer++;
        t = w->timer;
        if (t == 0x32) {
            func_02065804(data_0214a420, self->unk_13c);
        }
        if (t >= 0x8c) {
            {
                s32 y = self->pos.y;
                s32 z = self->pos.z;
                s32 x = self->pos.x;
                d.x = x - FLD(s32, self, 0x70);
                d.y = (y - 0x11000) - self->pos.y;
                d.z = z - self->pos.z;
            }
            VEC_MultAdd(0xe, &d, &self->pos, &self->pos);
            if (t >= 0x12c) {
                Ov012_Flash(10, 0x3c, 0x3c);
                func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
                self->unk_40->timer = 0;
                self->unk_40->state++;
                break;
            }
            if (t % 8 == 0) {
                self->rot[2] += 0xb6;
            }
        }
        if (t % 20 == 0) {
            q.x = self->pos.x;
            q.y = self->pos.y;
            q.z = self->pos.z;
            q.y += self->unk_68 >> 1;
            s.x = self->unk_64;
            s.y = self->unk_68 >> 2;
            s.z = self->unk_64;
            func_ov000_0219b71c(&q, &s, 0x99a, 0x1000, 2, 0x32);
            Ov012_Flash(0x14, 10, 10);
            func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        }
        break;
    }
    case 3:
        w->timer++;
        if (w->timer > 0x3c) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            func_ov000_02184548(data_ov000_021ccd54);
        } else {
            func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        }
        break;
    }
    if (st < 1) {
        return;
    }
    {
        Ov012Actor *pl = (Ov012Actor *)func_ov000_0219bf90();
        u8 *cam;
        s16 r;
        if (pl == NULL) {
            return;
        }
        if (Ov012_PlBusy(pl)) {
            return;
        }
        cam = (u8 *)data_ov000_021ccd54 + 0xf4;
        r = self->unk_1c;
        if (st == 1) {
            s16 c = self->unk_1a - 1;
            if (c <= 0) {
                self->unk_114 -= 0xb8;
                if (r < 0xb60) {
                    r = r + 0x16;
                    if (r >= 0xb60) {
                        r = 0xb60;
                    }
                    self->unk_1c = r;
                }
            } else {
                self->unk_1a = c;
            }
        } else {
            Ov012_SetTgt(self);
        }
        FLD(Ov012Vec, cam, 0xe8) = self->unk_100;
        FLD(Ov012CamDa, cam, 0xda).b1 = 1;
        FLD(s32, cam, 0xf4) = self->unk_114;
        FLD(Ov012CamDa, cam, 0xda).b2 = 2;
        FLD(u16, cam, 0xf8) = r + 0x5b0;
        FLD(Ov012CamDa, cam, 0xda).b4 = 1;
    }
}
}

extern "C" {
void func_ov012_021fd708(Ov012Lift *self) {
    Ov012Vec pp;
    Ov012Vec v4;
    Ov012Vec dd;
    Ov012Vec d1;
    Ov012Vec v1;
    Ov012Vec v2;
    Ov012Vec v3;
    Ov012SpawnDesc desc;
    Ov012Vec v5;
    Ov012Vec d12;
    Ov012Rot r1;
    Ov012Rot r2;
    Ov012Actor *pl;
    u8 *tbl;
    Ov012Sub40 *s;
    u16 t;
    pl = Actor_GetTarget(self);
    tbl = (u8 *)&data_ov012_0220ad40[3];
    pp = pl->pos;
    s = self->unk_40;
    switch (s->state) {
    case 0:
        self->unk_135 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x400, 0);
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 1: {
        Ov012V *e;
        s->timer++;
        t = s->timer;
        if (t <= 0xa0) {
            Actor_TurnToActor(self, pl, 0x7b);
        }
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = self->unk_f4.y + 0x14cd;
            s32 z = self->pos.z;
            d1.x = x - self->pos.x;
            d1.y = y - self->pos.y;
            d1.z = z - self->pos.z;
        }
        VEC_MultAdd(0x52, &d1, &self->pos, &self->pos);
        r1 = data_ov012_0220a3d8;
        r1.y = self->rot[1];
        r1.z = self->rot[2];
        if (t == 0x28 || t == 0x5a || t == 0x8c) {
            Ov012V *o = func_02065f88(0x5e0, &self->pos);
            func_01ffc9fc(&v1, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
            o->v0c(0x1800);
            o->v20(&v1);
            o->v30(self->rot);
            FLD(s32, o, 0xc8) = 0;
            self->unk_13c = FLD(s32, o, 0x24);
            o = func_02065f88(0x68, &self->pos);
            func_01ffc9fc(&v2, (Ov012Vec *)&data_ov012_0220a420, r1.y);
            o->v0c(0x4000);
            o->v20(&v2);
            o->v30(&r1);
            FLD(s32, o, 0xc8) = 0;
            self->unk_144 = FLD(s32, o, 0x24);
            self->unk_10c |= 2;
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        }
        if (self->unk_10c & 2) {
            e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_13c));
            if (e != NULL) {
                func_01ffc9fc(&v3, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
                VEC_Add(&v3, &self->pos, &v3);
                e->v18(&v3);
                e->v30(self->rot);
            }
        }
        e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_144));
        if (e != NULL) {
            func_01ffc9fc(&v4, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
            VEC_Add(&v4, &self->pos, &v4);
            e->v18(&v4);
            e->v30(&r1);
            if (FLD(s32, e, 0x40) > 0) {
                s32 a = FLD(s32, e, 0x40) - 0x333;
                if (a <= 0) {
                    FLD(s32, e, 0x1c) = 4;
                } else {
                    e->v0c(a);
                }
            }
        }
        if (t >= 0xbe) {
            self->unk_13c = 0;
            self->unk_40->timer = 0;
            self->unk_40->state = 10;
        }
        break;
    }
    case 10: {
        Ov012V *e;
        s->timer++;
        if (s->timer == 1) {
            Ov012Actor *o;
            Ov012V *f;
            self->unk_10c ^= 2;
            func_ov000_0218996c(0xf, 0x28);
            Ov012Spawn_Init(&desc, 0xffff);
            Ov012Spawn_Set(&desc, 0x4836);
            o = func_ov000_02192b24(&desc);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
                FLD(u8 *, o, 0x60) = tbl;
                o->unk_1c = self->unk_170;
                o->v04();
                o->unk_16.b0 = 1;
                o->unk_90 = self->unk_90;
                self->target_id = o->id;
            }
            self->unk_13c = Ov012_Fx2(self, 0x68, &data_ov012_0220a3cc, &v5, &data_ov012_0220a468, 0x800);
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
        } else if (s->timer >= 0x28) {
            dd.x = pp.x - self->unk_f4.x;
            dd.y = pp.y - self->unk_f4.y;
            dd.z = pp.z - self->unk_f4.z;
            func_01ffc9fc(&dd, &dd, 0xffff - self->rot[1]);
            self->unk_124.x = 0x7000;
            self->unk_124.y = 0;
            self->unk_124.z = -0xa000;
            if (dd.x <= 0) {
                self->unk_134 = 0;
                self->unk_124.x = FX_Mul(self->unk_124.x, -0x1000);
            } else {
                self->unk_134 = 1;
            }
            self->unk_130 = 0xc;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_13c));
        if (e != NULL) {
            e->v0c(FLD(s32, e, 0x40) + 0x19a);
        }
        break;
    }
    case 11: {
        u16 lim;
        s->timer++;
        lim = FLD(u16, tbl, 4);
        t = s->timer;
        if (t <= lim) {
            Ov012Actor *o;
            func_ov012_021fe8b4(self, &pp, 0x1e);
            o = Ov012_FindActor(self->target_id);
            if (o != NULL) {
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
            }
            if (t % 40 == 1) {
                func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
            }
        } else if (t > lim + 0x1e) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x52, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->timer = 0;
            func_02049f44(data_02097e4c, 0x500, &self->pos, 0);
            func_02049f44(data_02097e4c, 0xf, &self->pos, 0);
            self->unk_40->state++;
        }
        break;
    }
    case 12:
        d12.x = self->unk_f4.x - self->pos.x;
        d12.y = self->unk_f4.y - self->pos.y;
        d12.z = self->unk_f4.z - self->pos.z;
        VEC_MultAdd(0x66, &d12, &self->pos, &self->pos);
        Actor_TurnToPos(self, (u8 *)self + 0x100, 0xcd);
        s = self->unk_40;
        s->timer++;
        if (s->timer > 0x64) {
            Ov012_Finish(self);
        }
        break;
    }
}
static inline void Ov012_VecSub(Ov012Vec *o, const Ov012Vec *a, const Ov012Vec *b) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}


void func_ov012_021fdfa0(Ov012Lift *self) {
    Ov012Vec tg;
    Ov012Vec d;
    u16 lim;
    Ov012Vec d2;
    Ov012Vec v1;
    Ov012Vec v3;
    Ov012SpawnDesc desc;
    Ov012Vec v5;
    Ov012Vec d14;
    Ov012Actor *pl;
    u8 *tbl;
    Ov012Sub40 *s;
    u16 t;
    s32 px;
    pl = Actor_GetTarget(self);
    s = self->unk_40;
    px = pl->pos.x;
    tbl = (u8 *)&data_ov012_0220ad40[5];
    switch (s->state) {
    case 0:
        self->unk_9c = 0x19a;
        if (px >= 0) {
            self->unk_16e = 0;
        } else {
            self->unk_16e = 1;
        }
        self->unk_135 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x400, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        tg = self->unk_f4;
        {
            s32 off = 0x5000;
            if (self->unk_16e == 1) off -= 0xa000;
            tg.x += off;
        }
        tg.y = self->pos.y;
        Ov012_VecSub(&d, &tg, &self->pos);
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = self->unk_f4.y + 0x14cd;
            s32 z = self->pos.z;
            d2.x = x - self->pos.x;
            d2.y = y - self->pos.y;
            d2.z = z - self->pos.z;
        }
        VEC_MultAdd(0x52, &d2, &self->pos, &self->pos);
        if (func_ov000_02191120(self->unk_38)) {
            Ov012V *e;
            s = self->unk_40;
            s->timer++;
            t = s->timer;
            if (t == 1 || t == 0x32 || t == 0x64) {
                Ov012V *o = func_02065f88(0x5e0, &self->pos);
                func_01ffc9fc(&v1, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
                o->v0c(0x1800);
                o->v20(&v1);
                o->v30(self->rot);
                FLD(s32, o, 0xc8) = 0;
                self->unk_13c = FLD(s32, o, 0x24);
                self->unk_10c |= 2;
                func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
                if (t == 0x32) {
                    self->unk_10c |= 0x10000000;
                }
            }
            if (self->unk_10c & 2) {
                e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_13c));
                if (e != NULL) {
                    func_01ffc9fc(&v3, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
                    VEC_Add(&v3, &self->pos, &v3);
                    e->v18(&v3);
                    e->v30(self->rot);
                }
            }
            if (t >= 0x96) {
                self->unk_40->timer = 0;
                self->unk_40->state = 10;
            }
        }
        break;
    case 10:
        s->timer++;
        if (s->timer == 1) {
            Ov012Actor *o;
            self->unk_10c ^= 2;
            func_ov000_0218996c(10, 0xf);
            Ov012Spawn_Init(&desc, 0xffff);
            Ov012Spawn_Set(&desc, 0x4837);
            o = func_ov000_02192b24(&desc);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
                FLD(u8 *, o, 0x60) = tbl;
                o->unk_1c = self->unk_170;
                o->v04();
                o->unk_16.b0 = 1;
                o->unk_90 = self->unk_90;
                self->target_id = o->id;
            }
            self->unk_13c = Ov012_Fx2(self, 0x68, &data_ov012_0220a3ea, &v5, &data_ov012_0220a468, 0x1800);
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 11:
        s->timer++;
        t = s->timer;
        if (t == 0x14) {
            self->unk_10c ^= 0x40000000;
        }
        if (t >= 0x14) {
            Ov012Actor *o;
            tg = self->pos;
            {
                s32 off = 0x3800;
                if (self->unk_16e == 0) off -= 0x7000;
                tg.x = self->unk_f4.x + off;
            }
            self->unk_b8 = tg;
            Actor_MoveToPos(self, &tg, 0);
            o = Ov012_FindActor(self->target_id);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
            }
        }
        if (t > 0x14 && VEC_Distance(&self->pos, &self->unk_b8) <= 0) {
            self->unk_134 = 1;
            self->unk_130 = 0xc;
            self->unk_124.x = 0x7000;
            self->unk_124.y = 0;
            self->unk_124.z = -0xa000;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 12: {
        Ov012Actor *r = (Ov012Actor *)Ov012_FindRes(0x4000, 0x4837);
        if (self->unk_10c & 0x10000000) {
            u16 pct = self->unk_50[0] * 100 / self->unk_50[1];
            if (pct <= 0x32) {
                tg.x = 0x3800;
                tg.y = 0;
                tg.z = 0x3000;
                if (self->unk_16e == 0) {
                    tg.x = Ov012_FxMul64d(tg.x, -0x1000);
                }
                func_ov012_021fe8b4(self, &tg, 0x1e);
                if (r != NULL) {
                    r->rot[0] = self->rot[0];
                    r->rot[1] = self->rot[1];
                    r->rot[2] = self->rot[2];
                }
            }
            {
                lim = FLD(u16, tbl, 4);
                s = self->unk_40;
                s->timer++;
                t = s->timer;
                if (t <= lim - 0x28 && t % 40 == 1) {
                    func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
                }
            }
        } else {
            if (r != NULL) {
                r->unk_1a = 1;
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 13:
        s->timer++;
        if (s->timer == 0x46) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x52, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->timer = 0;
            func_02049f44(data_02097e4c, 0x500, &self->pos, 0);
            func_02049f44(data_02097e4c, 0xf, &self->pos, 0);
            self->unk_40->state++;
        }
        break;
    case 14:
        if (!(self->unk_10c & 0x10000000)) {
            d14.x = self->unk_f4.x - self->pos.x;
            d14.y = self->unk_f4.y - self->pos.y;
            d14.z = self->unk_f4.z - self->pos.z;
            VEC_MultAdd(0x66, &d14, &self->pos, &self->pos);
            Actor_TurnToPos(self, (u8 *)self + 0x100, 0x400);
            s = self->unk_40;
            s->timer++;
            if (s->timer > 0x64) {
                Ov012_Finish(self);
            }
        } else if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
        }
        break;
    }
}

}

// ---- merged from ov012_021feacc.cpp
namespace m_021feacc {
extern "C" {

extern u8 data_ov012_0220a4a4[];
extern u8 data_ov012_0220a4a8[];
extern u8 data_ov012_0220a4ac[];
extern u8 data_ov012_0220a4bc[];
extern u8 data_ov012_0220a4c0[];
extern u8 data_ov012_0220a4c4[];


static inline s32 Ov012_FxMulFe8b4(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov012_021fe8b4(Ov012Lift *self, const Ov012Vec *p, u8 n) {
    Ov012Vec d;
    d.x = p->x - self->pos.x;
    d.y = p->y - self->pos.y;
    d.z = p->z - self->pos.z;
    func_01ffc9fc(&d, &d, 0xffff - self->rot[1]);
    Actor_TurnToPos(self, (u8 *)self + 0x124, self->unk_130);
    switch (self->unk_134) {
    case 0:
        if (d.x > 0 && !(self->unk_10c & 0x1000000)) {
            if (self->unk_135 == 0) {
                self->unk_135 = n;
            }
            if (--self->unk_135 == 0) {
                self->unk_10c |= 0x1000000;
            }
        }
        if ((self->rot[1] < 0xe87a && self->rot[1] > 0xbff4) || (self->unk_10c & 0x1000000)) {
            self->unk_124.x = Ov012_FxMulFe8b4(self->unk_124.x, -0x1000);
            self->unk_134 = 1;
            self->unk_135 = 0;
            if (self->unk_10c & 0x1000000) {
                self->unk_10c ^= 0x1000000;
            }
        }
        break;
    case 1:
        if (d.x < 0 && !(self->unk_10c & 0x1000000)) {
            if (self->unk_135 == 0) {
                self->unk_135 = n;
            }
            if (--self->unk_135 == 0) {
                self->unk_10c |= 0x1000000;
            }
        }
        if ((self->rot[1] > 0x1776 && self->rot[1] < 0x4000) || (self->unk_10c & 0x1000000)) {
            self->unk_124.x = Ov012_FxMulFe8b4(self->unk_124.x, -0x1000);
            self->unk_134 = 0;
            self->unk_135 = 0;
            if (self->unk_10c & 0x1000000) {
                self->unk_10c ^= 0x1000000;
            }
        }
        break;
    }
}

struct Ov012Feacc {
    u8 pad[0x394];
    Ov012Vec v[2];
};

void func_ov012_021feacc(u8 *self, s32 i) {
    switch (FLD(u8, self, 0x3ae)) {
    case 0:
        func_02049f44((SndMgr *)data_02097e4c, 0x46, &((Ov012Feacc *)self)->v[i], 0);
        FLD(u8, self, 0x3af) |= 0x10;
        FLD(u8, self, 0x3ae)++;
    case 1: {
        Ov012Vec d;
        s32 tx, ty, tz;
        tx = FLD(s32, data_ov012_0220a4a4, i * 12);
        d.x = tx - ((Ov012Vec *)(self + 0x394))[i].x;
        ty = FLD(s32, data_ov012_0220a4a8, i * 12);
        d.y = ty - ((Ov012Feacc *)self)->v[i].y;
        tz = FLD(s32, data_ov012_0220a4ac, i * 12);
        d.z = tz - ((Ov012Feacc *)self)->v[i].z;
        VEC_MultAdd(0x171, &d, &((Ov012Feacc *)self)->v[i], &((Ov012Feacc *)self)->v[i]);
        if (VEC_Distance(&((Ov012Feacc *)self)->v[i], (Ov012Vec *)(data_ov012_0220a4a4 + i * 12)) >= 0x4cd) {
            return;
        }
        ((Ov012Vec *)(self + 0x394))[i].x = tx;
        ((Ov012Feacc *)self)->v[i].y = ty;
        ((Ov012Feacc *)self)->v[i].z = tz;
        func_ov000_0218996c(7, 0xf);
        if (FLD(u8, self, 0x3af) & 0x10) {
            func_02049f44((SndMgr *)data_02097e4c, 0x47, &((Ov012Feacc *)self)->v[i], 0);
            FLD(u8, self, 0x3af) ^= 0x10;
        }
        switch (i) {
        case 0:
            if (FLD(u8, self, 0x3af) & 1) {
                FLD(u8, self, 0x3af) ^= 1;
            }
            break;
        case 1:
            if (FLD(u8, self, 0x3af) & 2) {
                FLD(u8, self, 0x3af) ^= 2;
            }
            break;
        }
        break;
    }
    }
}

void func_ov012_021fec58(u8 *self, s32 i) {
    switch (FLD(u8, self, 0x3ae)) {
    case 0:
        func_02049f44((SndMgr *)data_02097e4c, 0x18, &((Ov012Feacc *)self)->v[i], 0);
        FLD(u8, self, 0x3af) |= 0x10;
        FLD(u8, self, 0x3ae)++;
        break;
    case 1:
        if (FLD(u8, self + 0x3ac, i)++ <= 0x14) {
            return;
        }
        if (FLD(u8, self, 0x3af) & 0x10) {
            func_02049f44((SndMgr *)data_02097e4c, 0x46, &((Ov012Feacc *)self)->v[i], 0);
            FLD(u8, self, 0x3af) ^= 0x10;
        }
        FLD(u8, self + 0x3ac, i) = 0;
        FLD(u8, self, 0x3ae)++;
        break;
    case 2: {
        Ov012Vec d;
        s32 tx, ty, tz;
        tx = FLD(s32, data_ov012_0220a4bc, i * 12);
        d.x = tx - ((Ov012Vec *)(self + 0x394))[i].x;
        ty = FLD(s32, data_ov012_0220a4c0, i * 12);
        d.y = ty - ((Ov012Feacc *)self)->v[i].y;
        tz = FLD(s32, data_ov012_0220a4c4, i * 12);
        d.z = tz - ((Ov012Feacc *)self)->v[i].z;
        VEC_MultAdd(0xa4, &d, &((Ov012Feacc *)self)->v[i], &((Ov012Feacc *)self)->v[i]);
        if (VEC_Distance(&((Ov012Feacc *)self)->v[i], (Ov012Vec *)(data_ov012_0220a4bc + i * 12)) >= 0x2000) {
            return;
        }
        ((Ov012Vec *)(self + 0x394))[i].x = tx;
        ((Ov012Feacc *)self)->v[i].y = ty;
        ((Ov012Feacc *)self)->v[i].z = tz;
        switch (i) {
        case 0:
            if (FLD(u8, self, 0x3af) & 4) {
                FLD(u8, self, 0x3af) ^= 4;
            }
            break;
        case 1:
            if (FLD(u8, self, 0x3af) & 8) {
                FLD(u8, self, 0x3af) ^= 8;
            }
            break;
        }
        break;
    }
    }
}

}
}  // namespace m_021feacc

// ---- merged from ov012_021fee1c.cpp
namespace m_021fee1c {
extern "C" {
#pragma force_active on
Ov012Act_021fee1c *Ov012Act_021fee1c_Ctor(Ov012Act_021fee1c *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220abf0;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_102 = 0;
    self->unk_104 = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
void Ov012Act_021fee1c_Start(Ov012Act_021fee1c *self) {
    Ov012Sub48 *m;
    Ov012Sub44 *n;
    func_ov003_021d112c(self);
    Ov012_ClearOwnerFlag(self);
    Ov012_VecSet(&self->unk_f0, -0x9000, 0x3000, 0);
    Ov012_VecSet(&self->pos, -0x9000, -0xa000, 0);
    self->rot[1] = 0x4000;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a400);
        self->unk_104 = 0x1800;
    }
}
}

extern "C" {
void func_ov012_021fef64(Ov012Act_021fee1c *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_100 = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        self->unk_102 = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a4a4[];
extern const Ov012Vec data_ov012_0220a4bc[];
void Ov012Act_021fee1c_Update(Ov012Act_021fee1c *self) {
    Ov012Actor *pl;
    Ov012Vec v;
    s32 a;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = (Ov012Actor *)func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    v.x = pl->pos.x;
    v.y = pl->pos.y;
    v.z = pl->pos.z;
    VEC_Distance(&self->pos, &v);
    if (!(self->unk_30 & 0x40)) {
        return;
    }
    switch (((u16)self->unk_100)) {
    case 1:
        self->unk_38->unk_c2_0 = 0;
        self->unk_fc |= 0x100000;
        break;
    case 2:
        if (self->unk_fc & 0x100000) {
            self->unk_fc ^= 0x100000;
        }
        self->unk_38->unk_c2_0 = 1;
        self->unk_f0 = data_ov012_0220a4a4[self->unk_102];
        self->pos = data_ov012_0220a4bc[self->unk_102];
        switch (self->unk_102) {
        case 0:
            a = 1;
            self->rot[1] = 0xbff4;
            break;
        case 1:
            a = 2;
            self->rot[1] = 0x4000;
            break;
        }
        func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &a);
        break;
    case 4:
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->flags |= 0x4000;
        break;
    case 0x10:
        self->unk_40->flags = 0;
        self->unk_40->flags |= 0x200000;
        break;
    }
    self->unk_100 = 0;
}
}
}  // namespace m_021fee1c

// ---- merged from ov012_021ff674.cpp
namespace m_021ff674 {
extern "C" {
extern const Ov012Vec data_ov012_0220a4d4[];
extern const Ov012Vec data_ov012_0220a4bc[];
void func_ov012_021ff8b4(Ov012Act_021fee1c *self, s32 idx);

void func_ov012_021ff20c(Ov012Act_021fee1c *self) {
    s32 off;
    Actor_GetTarget(self);
    off = 0;
    switch (self->unk_102) {
    case 0:
        off = -0x1000;
        break;
    case 1:
        off = 0x1000;
        break;
    }
    switch (self->unk_40->state) {
    case 0: {
        u8 *t;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x1000, 0);
        self->unk_9c = self->unk_b0->unk_00;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        {
            s32 x = self->pos.x + off;
            s32 y = self->pos.y;
            s32 z = self->pos.z;
            Ov012_VecSet(&self->unk_b8, x, y, z);
        }
        t = (u8 *)Ov012_FindRes(0x5000, 0x5c02);
        if (t == NULL) {
            goto st1;
        }
        {
            u16 pct = FLD(u16, FLD(u8 *, t, 0x50), 0) * 100 / FLD(u16, FLD(u8 *, t, 0x50), 2);
            u16 n;
            if (pct <= 20) {
                self->unk_103 = 10;
                n = 5;
            } else {
                self->unk_103 = 0x28;
                n = 3;
            }
            self->unk_4c->unk_1e = n;
        }
        self->unk_40->state++;
    }
    case 1:
    st1: {
        Ov012Vec v;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab27, 0x400, 0);
        func_ov000_02191418(self->unk_38, self->unk_103, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    }
    case 2: {
        Ov012Vec d;
        Ov012Sub40 *s;
        s32 k = self->unk_4c->unk_1e - 1;
        d.x = data_ov012_0220a4d4[k].x;
        d.y = data_ov012_0220a4d4[k].y;
        d.z = data_ov012_0220a4d4[k].z;
        if (self->unk_f0.x >= 0) {
            d.x = FX_Mul(d.x, -0x1000);
        }
        Actor_TurnToPos(self, &d, 0x19a);
        s = self->unk_40;
        s->timer++;
        if (s->timer < self->unk_103) {
            return;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    }
    case 3:
        func_ov012_021ff8b4(self, self->unk_4c->unk_1e);
        self->unk_40->state++;
        return;
    case 4: {
        u16 n;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        n = self->unk_4c->unk_1e - 1;
        self->unk_4c->unk_1e = n;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x400, 0);
        if (n != 0) {
            self->unk_40->state = 1;
            return;
        }
        {
            s32 x = self->pos.x - off;
            s32 y = self->pos.y;
            s32 z = self->pos.z;
            Ov012_VecSet(&self->unk_b8, x, y, z);
        }
        self->unk_40->state = 10;
        return;
    }
    case 10: {
        Ov012Vec v;
        s32 a;
        Ov012Sub40 *s;
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 20) {
            return;
        }
        Actor_TurnToPos(self, (void *)&data_ov012_0220a4bc[self->unk_102], 0x19a);
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
            return;
        }
        switch (self->unk_102) {
        case 0:
            a = 4;
            break;
        case 1:
            a = 8;
            break;
        }
        func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &a);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a4bc[];
void func_ov012_021ff674(Ov012Act_021fee1c *self) {
    s32 off = 0;
    Ov012Sub40 *s;
    u8 side = self->unk_102;
    switch (side) {
    case 0:
        off = -0x1000;
        break;
    case 1:
        off = 0x1000;
        break;
    }
    s = self->unk_40;
    switch (Ov012Sub40_State(s)) {
    case 0:
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480b, 0x15);
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x400, 0);
        self->unk_b8.y = self->pos.y;
        self->unk_b8.z = self->pos.z;
        self->unk_b8.x = self->pos.x - off;
        self->unk_40->state++;
        break;
    case 1:
        if (!(self->unk_fc & 0x100000)) {
            Ov012Vec v;
            s32 a;
            Actor_TurnToPos(self, (void *)&data_ov012_0220a4bc[side], 0x19a);
            if (!func_ov000_02191120(self->unk_38)) {
                return;
            }
            v.x = self->unk_b8.x;
            v.y = self->unk_b8.y;
            v.z = self->unk_b8.z;
            Actor_MoveToPos(self, &v, 0);
            if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
                return;
            }
            switch (self->unk_102) {
            case 0:
                a = 4;
                break;
            case 1:
                a = 8;
                break;
            }
            func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &a);
            self->unk_40->state++;
        } else {
            s->state++;
        }
        break;
    case 2:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        break;
    case 3:
        if (self->unk_fc & 0x100000) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
            self->v08();
        }
        break;
    }
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a4d4[];
void func_ov012_021ff8b4(Ov012Act_021fee1c *self, s32 idx) {
    Ov012SpawnDesc d;
    Ov012Vec v;
    Ov012Vec dir;
    u16 r[3];
    Ov012Actor *o;
    Ov012Spawn_Init(&d, 0x480b);
    v.x = 0x99a;
    v.y = 0x1000;
    v.z = 0x2000;
    func_01ffc9fc(&v, &v, self->rot[1]);
    VEC_Add(&self->pos, &v, &v);
    dir = data_ov012_0220a4d4[idx - 1];
    if (self->unk_f0.x >= 0) {
        dir.x = -dir.x;
    }
    dir.x = dir.x - v.x;
    dir.y = dir.y - v.y;
    dir.z = dir.z - v.z;
    VEC_Normalize(&dir, &dir);
    r[0] = 0;
    r[1] = 0;
    r[2] = 0;
    r[0] = FX_AsinIdx(-dir.y);
    r[1] = FX_Atan2(dir.x, dir.z);
    o = Group_SpawnActor(data_ov000_021ccd64, &d, &v, r, 0xffff);
    if (o == NULL) {
        return;
    }
    o->unk_18 = 6;
    func_ov000_0219bebc(o, self->unk_104);
    o->unk_16.b0 = 1;
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
}
}

extern "C" {
#pragma force_active on
Ov012Act_021ffa68 *Ov012Act_021ffa68_Ctor(Ov012Act_021ffa68 *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220ab44;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_106 = 0;
    self->unk_107 = 0;
    self->unk_fc = 0;
    self->unk_108 = 0;
    return self;
}
#pragma force_active reset
}

extern "C" {
void *Ov012Act_021ffa68_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ab44;
    Ov012_FreeFx(self, 0x108);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
void *Ov012Act_021ffa68_DtorDelete(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ab44;
    Ov012_FreeFx(self, 0x108);
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
void Ov012Act_021ffa68_Init(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
}
}

extern "C" {
BOOL Ov012Act_021ffa68_IsReady(Ov012Actor *self) {
    return func_ov000_0218cf5c(self);
}
}

extern "C" {
void Ov012Act_021ffa68_Start(Ov012Act_021ffa68 *self) {
    Ov012Sub48 *m;
    Ov012Sub44 *n;
    func_ov003_021d112c(self);
    FLD(s32 *, self, 0x108) = Ov012_NewFx();
    Ov012_ClearOwnerFlag(self);
    self->unk_ea_6 = 1;
    Ov012_VecSet(&self->unk_f0, 0x9000, 0x3000, 0);
    Ov012_VecSet(&self->pos, 0x9000, -0xa000, 0);
    self->rot[1] = 0xbff4;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a3f0);
    }
}
}

extern "C" {
void func_ov012_021ffcd0(Ov012Act_021ffa68 *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_104 = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        self->unk_106 = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}
}


extern "C" {
extern const Ov012Vec data_ov012_0220a4a4[];
void Ov012Act_021ffa68_Update(Ov012Act_021ffa68 *self) {
    Ov012Vec v;
    Ov012Vec w;
    s32 n;
    s32 n2;
    u8 b;
    Ov012Actor *pl;
    u8 kind;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = (Ov012Actor *)func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    v = pl->pos;
    VEC_Distance(&self->pos, &v);
    kind = self->unk_40->unk_13;
    {
        u16 *hp = self->unk_50;
        u16 mx = self->unk_b0->unk_08;
        if (hp[0] < mx) {
            hp[0] = mx;
        }
    }
    if (self->unk_30 & 0x40) {
        switch (((u16)self->unk_104)) {
        case 1: {
            Ov012Sub44 *q;
            Ov012Sub48 *m;
            self->unk_38->unk_c2_0 = 0;
            q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_100 |= 0x200000;
            break;
        }
        case 2: {
            if (self->unk_100 & 0x200000) {
                self->unk_100 ^= 0x200000;
            }
            self->unk_38->unk_c2_0 = 1;
            self->unk_f0 = data_ov012_0220a4a4[self->unk_106];
            self->pos = data_ov012_0220a4bc[self->unk_106];
            n = 3;
            switch (self->unk_106) {
            case 0:
                self->rot[1] = 0xbff4;
                break;
            case 1:
                self->rot[1] = 0x4000;
                break;
            }
            func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &n);
            break;
        }
        case 4:
            self->unk_38->unk_c2_0 = 1;
            self->unk_100 |= 4;
            self->unk_40->flags |= 0x8000;
            break;
        case 8:
            self->unk_38->unk_c2_0 = 1;
            self->unk_100 |= 8;
            self->unk_40->flags |= 0x10000;
            break;
        case 0x10:
            self->unk_100 |= 0x1000;
            break;
        }
        self->unk_104 = 0;
    }
    if (self->pos.y <= -0x14000) {
        Ov012Sub44 *q;
        self->unk_38->unk_c2_0 = 0;
        q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_4c->target = 0xffff;
        n2 = 0xc;
        func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &n2);
        self->unk_100 = 1;
        self->unk_40->flags |= 2;
    }
    switch (kind) {
    case 0x14:
        self->unk_100 = 0x800;
        break;
    case 11: {
        Ov012Actor *o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c02);
        if (o != NULL) {
            w = o->pos;
            VEC_Distance(&self->pos, &w);
            self->unk_100 |= 0x100;
            if (self->unk_100 & 0x200) {
                self->unk_100 ^= 0x200;
            }
            if (self->unk_100 & 0x800) {
                self->unk_100 ^= 0x800;
            }
            self->unk_48->unk_30 = 0;
        }
        break;
    }
    case 10:
        self->unk_100 |= 0x200;
        b = 1;
        func_ov000_0219bd20(0x5c02, self->kind, 6, 1, 1, &b);
        break;
    }
    if ((self->unk_100 & 0x200000) && (self->unk_100 & 0x1000)) {
        self->unk_40->flags = 0;
        self->unk_40->flags |= 0x200000;
    }
    func_ov003_021dacfc(((void *)self->unk_108));
}
}
}  // namespace m_021ff674

// ---- merged from ov012_02200200.cpp
namespace m_02200200 {
extern "C" {
BOOL func_ov012_02201910(Ov012Act_021ffa68 *self, void *p, s32 a);
void func_ov012_02200200(Ov012Act_021ffa68 *self) {
    u32 f = self->unk_100;
    if ((f & 0x200) || (f & 0x800) || (f & 0x400000)) {
        switch (self->unk_40->state) {
        case 0: {
            Ov012Sub48 *m;
            s32 x = 0x3000;
            if (self->unk_106 == 1) {
                x = -0x3000;
            }
            Ov012_VecSet(&self->unk_b8, x, self->pos.y, 0);
            self->unk_107 = 0;
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x111, 0);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            self->unk_48->unk_30 = 0;
            self->unk_40->state++;
            break;
        }
        case 1:
            if (func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
                if (self->unk_100 & 0x200) {
                    self->unk_100 ^= 0x200;
                }
                if (self->unk_100 & 0x800) {
                    self->unk_100 ^= 0x800;
                }
                if (self->unk_100 & 0x400000) {
                    self->unk_100 ^= 0x400000;
                }
                self->unk_40->state = 0;
            }
            break;
        }
    } else if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
}
}

extern "C" {
BOOL func_ov012_022016d8(Ov012Act_021ffa68 *self, s32 a);

void func_ov012_02200398(Ov012Act_021ffa68 *self) {
    Ov012Actor *pl = Actor_GetTarget(self);
    Ov012Vec t;
    Ov012Vec v;
    s32 py = pl->pos.y;
    s32 pz = pl->pos.z;
    t = self->unk_f0;
    t.x = FX_Mul(t.x, -0x1000);
    self->unk_ea_0 = 3;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub48 *m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link((HitSphere *)m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        v.y = py;
        v.z = pz;
        v.x = 0;
        self->unk_b8 = v;
        func_02049f44(data_02097e4c, 0x601, &self->pos, 0);
        self->unk_107 = 0;
        self->unk_40->state++;
    }
    case 1:
        if (!func_ov012_022016d8(self, self->unk_b0->unk_00 * 2)) {
            return;
        }
        {
            Ov012Sub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        self->unk_40->state++;
        return;
    case 2:
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0 && !func_01ffc198(&pl->pos, &self->pos, pl->unk_64 + 0x2000)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab2d, 0x111, 0);
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
        }
        func_02049f44(data_02097e4c, 0x600, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    case 3: {
        Ov012Sub40 *s;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        s = self->unk_40;
        s->timer++;
        if (s->timer == 1) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            return;
        }
        if (s->timer == 0x1e) {
            Ov012V *e = func_02065f88(0x12f, &self->pos);
            e->v24(0, 0x800, 0);
            e->v14(0x800, 0x800, 0x800);
            return;
        }
        if (s->timer < 0x50) {
            return;
        }
        self->unk_100 = 1;
        v.x = 0x3000;
        v.y = 0;
        v.z = 0;
        if (self->unk_106 == 0) {
            v.x = -v.x;
        }
        v.y = self->pos.y;
        self->unk_b8 = v;
        self->unk_107 = 0;
        {
            Ov012Sub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        self->unk_94_1 = 1;
        self->unk_40->state++;
        return;
    }
    case 4:
        if (!func_ov012_02201910(self, &t, self->unk_b0->unk_00 * 2)) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}

extern "C" {

void func_ov012_022007a0(Ov012Act_021ffa68 *self) {
    Ov012Vec v;
    Ov012Vec w;
    Actor_GetTarget(self);
    self->unk_ea_0 = 3;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub48 *m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link((HitSphere *)m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        v.x = 0x2800;
        v.y = 0;
        v.z = 0x3800;
        if (self->unk_106 == 1) {
            v.x = FX_Mul(v.x, -0x1000);
        }
        if ((u8)Rand_UpTo(1)) {
            v.z = FX_Mul(v.z, -0x1000);
        }
        self->unk_b8 = v;
        self->unk_107 = 0;
        self->unk_40->state++;
    }
    case 1:
        if (!func_ov012_022016d8(self, self->unk_b0->unk_00)) {
            return;
        }
        {
            Ov012Sub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
        }
        self->unk_40->state++;
        return;
    case 2:
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        w = v;
        w.z = FX_Mul(w.z, -0x1000);
        Actor_TurnToPos(self, &w, 0x19a);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab33, 0x111, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    case 3: {
        u16 t;
        Ov012Sub40 *s = self->unk_40;
        s->timer++;
        t = s->timer;
        if (t > 0x69) {
            self->unk_94_1 = 1;
            if (t != 0x6e) {
                return;
            }
            {
                Ov012Sub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
            return;
        }
        if (t == 0x14) {
            Ov012V *e = func_02065f88(0x391, &self->pos);
            e->v24(0, 0x1000, 0);
            func_ov003_021da9ac(((void *)self->unk_108), 0, e);
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        if (t == 0x64) {
            Ov012V *e = func_02065f88(0x69, &self->pos);
            e->v24(0, 0x1000, 0);
            e->v0c(0xb33);
            func_02049f44(data_02097e4c, 0x601, &self->pos, 0);
        }
        w = self->unk_b8;
        w.z = FX_Mul(w.z, -0x1000);
        Actor_TurnToPos(self, &w, 0x19a);
        return;
    }
    case 4:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_100 = 1;
            v.x = 0x3000;
            v.y = 0;
            v.z = 0;
            if (self->unk_106 == 1) {
                v.x = -v.x;
            }
            v.y = self->pos.y;
            self->unk_b8 = v;
            self->unk_107 = 0;
            {
                Ov012Sub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            {
                Ov012Sub48 *m = self->unk_48;
                m->unk_9a_0 = 0;
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
            self->unk_40->state++;
        }
        self->unk_94_1 = 1;
        return;
    case 5:
        if (!func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00)) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}

extern "C" {
extern u16 func_ov000_02199e94(void *p);
extern u8 func_ov000_02199f08(void *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, void *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);
extern void *func_020658cc(void *a, s32 b);

struct Ov012HitArg {
    u16 a;
    u8 kind;
    u16 b;
};

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov012_Flash(s32 b) {
    FieldState *g = data_ov000_021ccd54;
    u8 c = (b << 1) + 0x14 + b;
    g->cam.base.shakeX = 1;
    g->cam.base.shakeY = 1;
    g->cam.base.shakeZ = 1;
    g->cam.base.shakeTime = b * 2 + 6;
    g->cam.base.shakeLen = c;
    g->cam.base.shakeCur = c;
}

/* The hit result is an enum: the optimizer does not constant-propagate enum-typed
   locals, so `j = hit - 1` stays a subtraction from the register (round lfA). */
typedef enum { OV012_HIT_NONE = 0, OV012_HIT_YES = 1 } Ov012Hit;

void func_ov012_02200cd4(Ov012Act_021ffa68 *self) {
    Ov012Vec t;
    Ov012Vec hv;
    Ov012Actor *pl;
    s32 k;
    Ov012Sub40 *s;

    pl = (Ov012Actor *)func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    k = pl->unk_40 != NULL ? pl->unk_40->unk_13 : 0;
    if (k == 0x11 || (self->unk_100 & 0x400000)) {
        s = self->unk_40;
        switch (s->state) {
        case 0:
            self->unk_48->unk_30 = 0;
            self->unk_100 |= 0x400000;
            break;
        case 1:
            s->timer = 0;
            break;
        }
        func_ov003_021d3d28(self);
        return;
    }
    if ((self->unk_100 & 0x200) || (self->unk_100 & 0x800)) {
        s = self->unk_40;
        switch (s->state) {
        case 0: {
            Ov012Sub44 *q = self->unk_44;
            Ov012Sub48 *m;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            self->unk_48->unk_30 = 0x40000000;
            m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link((HitSphere *)m);
            if (self->unk_a8 == 0) {
                self->unk_a8 = 0x52;
            }
            self->unk_40->state++;
            break;
        }
        case 1:
            s->timer = 0;
            break;
        }
        func_ov003_021d3d28(self);
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub48 *m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link((HitSphere *)m);
        self->unk_48->unk_30 = 0;
        self->unk_40->state++;
    }
    case 1: {
        Ov012Hit hit;
        u16 x;
        s32 j;
        Ov012Actor *g;
        Ov012Sub48 *m;
        Ov012Sub48 *gm;
        void *p;
        BOOL re;
        if (self->unk_100 & 0x100) {
            Ov012Actor *o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c02);
            if (o != NULL) {
                s32 d;
                u16 a;
                s32 dx = o->pos.x; dx = self->pos.x - dx;
                s64 sq = (s64)dx * dx;
                s32 dz = o->pos.z; dz = self->pos.z - dz;
                s32 oy = o->pos.y;
                sq += (s64)dz * dz;
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                d = Ov012_Sqrt2(sq);
                a = FX_Atan2(d, oy + 0x3000 - self->pos.y);
                self->unk_9c = Ov012_FxMul64d(OV012_SIN(a), 0x666);
                self->unk_a0 = Ov012_FxMul64d(OV012_COS(a), 0x666);
                self->unk_100 ^= 0x100;
            }
        }
        g = NULL;
        if (self->unk_4c != NULL) {
            g = (Ov012Actor *)Target_Get(self->unk_4c);
        }
        if (g != NULL && self->unk_4c->unk_01 == 1) {
            m = self->unk_48;
            if ((m->unk_50 & 0x60000000) || m->unk_58 != 0) {
                Ov012HitArg arg;
                u8 kind;
                hit = OV012_HIT_NONE;
                x = func_ov000_02199e94(self->unk_4c);
                j = hit - 1;
                if (!(self->unk_48->unk_50 & 0x20000000)) {
                    Ov012V *e = func_02065f88(0x65, &self->pos);
                    e->v34(0x1800, (u16)(self->rot[1] + 0x8000), hit);
                    {
                        Ov012_Flash(self->unk_4c->unk_1a);
                    }
                    func_02049f44(data_02097e4c, 0x1a, &self->pos, hit);
                    self->unk_40->state = 10;
                }
                if (self->unk_4c->unk_03 == 1) {
                    s32 lim = self->unk_64 + 0xccd;
                    if (lim < 0x199a) {
                        lim = 0x199a;
                    }
                    hv.y = self->unk_68 >> 1;
                    hv.x = 0;
                    hv.z = 0;
                    hit = (Ov012Hit)func_ov000_0219aae8(self, g, x, self->unk_4c->unk_0a, 0x20, &hv, NULL, lim, 0, j, 0x1000);
                }
                kind = 0x40;
                if (self->unk_4c->unk_19) {
                    kind = func_ov000_02199f08(self->unk_4c);
                    self->unk_100 |= 0x100000;
                }
                arg.a = 0;
                arg.kind = kind;
                arg.b = 0xffff;
                if (hit && kind == 0x41) {
                    g = self;
                }
                if (g != NULL) {
                    Actor_SendMsg((Actor *)self, g->id, 9, 0, 6, &arg);
                }
                self->unk_4c->target = 0xffff;
            }
        }
        gm = NULL;
        Actor_Move((Actor *)self, 0);
        m = self->unk_48;
        if (m == NULL) {
            return;
        }
        re = FALSE;
        p = self->unk_4c;
        if (p != NULL && FLD(u16, p, 0x1c) != 0xffff && FLD(u8, p, 1) == 1) {
            Ov012Actor *g2;
            s32 v = self->unk_64 + 0x4cd;
            if (v < 0xccd) {
                v = 0xccd;
            }
            m->unk_44 = v;
            g2 = (Ov012Actor *)Target_Get(self->unk_4c);
            if (g2 != NULL && (gm = g2->unk_48) != NULL && gm->unk_9a_3) {
                gm->unk_9a_3 = 0;
                func_0203f364(gm);
                re = TRUE;
            }
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (re) {
            gm->unk_9a_3 = 1;
            HitSphere_Link((HitSphere *)gm);
        }
        break;
    }
    case 10: {
        Ov012Sub44 *q;
        Ov012Sub48 *m;
        void *e;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x111, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00 * 2;
        self->unk_a0 = 0x333;
        self->unk_a8 = 0x52;
        self->unk_b8.x = 0;
        self->unk_b8.y = 0;
        self->unk_b8.z = 0xa000;
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        self->unk_4c->target = 0xffff;
        e = func_020658cc(data_0214a420, 0x321);
        if (e != NULL) {
            FLD(s32, e, 0x1c) = 4;
        }
        self->unk_40->state++;
        break;
    }
    case 11: {
        Ov012Sub48 *m;
        Ov012V *o;
        if (self->unk_38->unk_c4 == 2) {
            func_ov000_02191418(self->unk_38, 0x1e, 0);
        }
        t = self->unk_b8;
        Actor_MoveToPos(self, &t, 0);
        Actor_TurnToPos(self, &t, 0x400);
        self->unk_48->unk_9a_5 = 1;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        o = func_02065f88(0x12f, &self->pos);
        o->v0c(0x800);
        func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
        t.x = 0x3000;
        t.y = 0;
        t.z = 0;
        if (self->unk_106 == 1) {
            t.x = -t.x;
        }
        t.y = self->pos.y;
        self->unk_b8 = t;
        self->unk_107 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x111, 0);
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        m = self->unk_48;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
        self->unk_40->state++;
        break;
    }
    case 12:
        if (!func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
            return;
        }
        if (self->unk_100 & 0x100000) {
            self->unk_100 ^= 0x100000;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}
}  // namespace m_02200200

// ---- merged from ov012_022015a0.cpp
namespace m_022015a0 {
extern "C" {
void func_ov012_022015a0(Ov012Act_021ffa68 *self) {
    Ov012Sub48 *m;
    void *o;
    self->unk_48->unk_30 = 0x40000000;
    FLD(u16, self->unk_48, 0x9a) |= 0x12;
    func_ov003_021daa6c(((void *)self->unk_108), 0);
    self->unk_40->timer = 0;
    func_ov003_021d5900(self);
    if (!(self->unk_100 & 0x100000)) {
        return;
    }
    if (self->unk_40->state != 1) {
        return;
    }
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    if (self->unk_100 & 0x100000) {
        self->unk_100 ^= 0x100000;
    }
    self->unk_9c = 0x266;
    self->unk_a0 = 0x333;
    o = Ov012_FindRes(0x5000, 0x5c02);
    if (o == NULL) {
        return;
    }
    if (*FLD(u16 *, o, 0x50) != 0) {
        return;
    }
    func_ov000_02198360(self->unk_40, 4, 0);
    self->unk_40->state = 10;
}
}

extern "C" {
void func_ov012_022016a4(Ov012Actor *self) {
    func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
    self->v08();
}
}

extern "C" {
BOOL func_ov012_022016d8(Ov012Act_021ffa68 *self, s32 spd) {
    Ov012Vec v;
    switch (self->unk_107) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x111, 0);
        self->unk_9c = self->unk_b0->unk_00 * 2;
        self->unk_a0 = 0x266;
        self->unk_a4 = 0;
        self->unk_a8 = 0x52;
        self->unk_107++;
    case 1:
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_TurnToPos(self, &v, 0x333);
        if (self->unk_38->unk_c4 == 1) {
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            self->unk_107++;
        }
        break;
    case 2:
        if (self->unk_38->unk_c4 == 2) {
            func_ov000_02191418(self->unk_38, 0x1e, 0);
        }
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_MoveToPos(self, &v, 0);
        self->unk_48->unk_9a_5 = 1;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x20000000) {
            func_ov000_0218996c(3, 5);
            func_02065f88(0x12f, &self->pos)->v0c(0x800);
            func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x111, 0);
            self->unk_9c = spd;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_107++;
        }
        break;
    case 3:
        self->unk_48->unk_9a_5 = 0;
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        v.y = self->pos.y;
        self->unk_b8 = v;
        return TRUE;
    }
    return FALSE;
}
}

extern "C" {
BOOL func_ov012_02201910(Ov012Act_021ffa68 *self, const Ov012Vec *target, s32 spd) {
    Ov012Vec v;
    s32 n;
    self->unk_94_1 = 1;
    switch (self->unk_107) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4, 0x111, 0);
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = spd;
        self->unk_107++;
    case 1:
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_TurnToPos(self, &v, 0x333);
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x111, 0);
        self->unk_9c = self->unk_b0->unk_00 * 2;
        self->unk_a0 = 0x59a;
        self->unk_a8 = 0x52;
        self->unk_b8 = *target;
        self->unk_107++;
        break;
    case 2:
        Actor_TurnToPos(self, (void *)target, 0x333);
        if (self->unk_38->unk_c4 == 1) {
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            self->unk_107++;
        }
        break;
    case 3:
        if (self->unk_38->unk_c4 == 2) {
            func_ov000_02191418(self->unk_38, 0x1e, 0);
        }
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_TurnToPos(self, &v, 0x333);
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
            break;
        }
        self->pos = *target;
        func_02065f88(0x12f, &self->pos)->v0c(0x800);
        func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c8, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->unk_40->timer = 0;
        self->unk_107++;
        break;
    case 4: {
        void *o;
        Ov012Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer <= 10) {
            break;
        }
        n = 0xc;
        func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &n);
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        o = Ov012_FindRes(0x5000, 0x5c02);
        if (o != NULL) {
            if (*FLD(u16 *, o, 0x50) == 0) {
                self->unk_38->unk_be = 0;
            }
        }
        return TRUE;
    }
    }
    return FALSE;
}
}
}  // namespace m_022015a0
