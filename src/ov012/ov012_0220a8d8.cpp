#include "ov012/ov012.h"

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last effect record. Everything follows the empty asm function, so both sections keep definition
// order. The three handler tables are vtables (two zero words, then 41 handlers); the TU's
// functions point objects at the handler part. The functions at the end, func_ov012_021fc688 to
// func_ov012_021fdfa0, are part of this TU: they read the constants through the .rodata base plus an offset.
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
void func_ov012_02201c90(void);
void func_ov012_02201c70(void);
void func_ov012_021ffcd0(void);
void func_ov012_02200200(void);
void func_ov003_021d36fc(void);
void func_ov012_02200cd4(void);
void func_ov012_02200398(void);
void func_ov012_022007a0(void);
void func_ov012_02201d04(void);
void func_ov012_02201ce4(void);
void func_ov012_02201cd0(void);
void func_ov012_022015a0(void);
void func_ov012_022016a4(void);
void func_ov003_021d64f0(void);
void func_ov012_02201ccc(void);
void func_ov012_02201cc8(void);
void func_ov012_02201cc4(void);
void func_ov012_02201cc0(void);
void func_ov012_02201cbc(void);
void func_ov012_02201d68(void);
void func_ov012_02201d4c(void);
void func_ov012_021fee58(void);
void func_ov012_021fefc8(void);
void func_ov012_021fef64(void);
void func_ov012_02201d28(void);
void func_ov012_021ff20c(void);
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
void func_ov012_021fbec8(Ov012Actor *self);
void func_ov012_021fc688(Ov012Actor *self);
void func_ov012_021fcf1c(Ov012Actor *self);
void func_ov012_021fcf48(Ov012Actor *self);
void func_ov012_021fd148(Ov012Actor *self);
void func_ov012_021fd1b0(Ov012Actor *self);
void func_ov012_021fba44(void);
void func_ov012_021fbb80(void);
void func_ov012_021fbce0(void);

static asm void ov012_0220a8d8_order() {
}

extern const u8 *const data_ov012_0220a3c4[2];
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
extern u8 data_ov012_0220aaf9[];
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

const u8 *const data_ov012_0220a3c4[2] = {(const u8 *)data_ov012_0220aaa6, (const u8 *)data_ov012_0220aaac};
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
u8 data_ov012_0220aaf9[] = "ef/effect3dope";
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
    (Ov012Fn)func_ov003_021d1b88,
    func_ov012_02201c90,
    func_ov012_02201c70,
    func_ov012_021ffcd0,
    func_ov012_02200200,
    (Ov012Fn)func_ov003_021d3600,
    func_ov003_021d36fc,
    (Ov012Fn)func_ov003_021d3a88,
    func_ov012_02200cd4,
    func_ov012_02200398,
    func_ov012_022007a0,
    func_ov012_02201d04,
    (Ov012Fn)func_ov003_021d4b68,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    (Ov012Fn)func_ov003_021d4fd8,
    (Ov012Fn)func_ov003_021d5348,
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
    (Ov012Fn)func_ov003_021d16cc,
    (Ov012Fn)func_ov003_021d0fc0,
    func_0205e958,
    (Ov012Fn)func_ov000_0218cf5c,
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
    (Ov012Fn)func_ov003_021d1b88,
    func_ov012_02201c90,
    func_ov012_02201c70,
    func_ov012_021fef64,
    (Ov012Fn)func_ov003_021d3524,
    (Ov012Fn)func_ov003_021d3600,
    func_ov003_021d36fc,
    (Ov012Fn)func_ov003_021d3a88,
    (Ov012Fn)func_ov003_021d3d28,
    (Ov012Fn)func_ov003_021d452c,
    func_ov012_02201d28,
    func_ov012_02201d04,
    func_ov012_021ff20c,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    (Ov012Fn)func_ov003_021d4fd8,
    (Ov012Fn)func_ov003_021d5348,
    (Ov012Fn)func_ov003_021d5900,
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
    (Ov012Fn)func_ov003_021d1b88,
    func_ov012_02201c90,
    func_ov012_02201c70,
    func_ov012_021fa978,
    func_ov012_021fbe64,
    (Ov012Fn)func_ov003_021d3600,
    func_ov003_021d36fc,
    (Ov012Fn)func_ov003_021d3a88,
    (Ov012Fn)func_ov003_021d3d28,
    (Ov012Fn)func_ov012_021fbec8,
    (Ov012Fn)func_ov012_021fc688,
    (Ov012Fn)func_ov012_021fcf1c,
    (Ov012Fn)func_ov012_021fcf48,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    (Ov012Fn)func_ov012_021fd148,
    (Ov012Fn)func_ov003_021d5348,
    (Ov012Fn)func_ov003_021d5900,
    (Ov012Fn)func_ov012_021fd1b0,
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

void func_ov012_021fe8b4(Ov012Actor *self, const Ov012Vec *p, u8 n);

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
        FLD(Ov012Flags8, o, 0x16).b0 = 1;
        o->unk_90 = self->unk_90;
        FLD(u16, self, 0xde) = o->id;
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
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x52, 0);
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
        func_ov000_0218d988(self, pl, 0xf6);
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
    s32 kz;
    Ov012Vec d2;
    Ov012Sub40 *s;
    d2.x = FLD(s32, self, 0xf4) - self->pos.x;
    d2.y = FLD(s32, self, 0xf8) - self->pos.y;
    d2.z = FLD(s32, self, 0xfc) - self->pos.z;
    VEC_MultAdd(0x66, &d2, &self->pos, &self->pos);
    func_ov000_0218d918(self, &FLD(Ov012Vec, self, 0x100), 0x400);
    s = self->unk_40;
    s->timer++;
    if (s->timer <= 100) {
        return;
    }
    if (FLD(u32, self, 0x10c) & 0x400000) {
        FLD(u32, self, 0x10c) ^= 0x400000;
    }
    kz = 0;
    if ((u32)self & 3) {
        kz = 0;
    }
    FLD(u8, self, 0x110) = kz;
    if (FLD(u32, self, 0x10c) & 0x100000) {
        FLD(u32, self, 0x10c) ^= 0x100000;
    }
    FLD(u8, self, 0x137) = kz;
    if (FLD(u32, self, 0x10c) & 0x200000) {
        FLD(u32, self, 0x10c) ^= 0x200000;
    }
    FLD(u32, self, 0x10c) |= 1;
    func_ov000_02198360(self->unk_40, 1, kz);
}

void func_ov012_021fbec8(Ov012Actor *self) {
    Ov012Actor *pl;
    s32 idx;
    Ov012Ad40 *ent;
    s32 lim;
    u16 t;
    s32 px;
    pl = func_ov000_0218d240(self);
    px = pl->pos.x;
    if (FLD(u32, self, 0x10c) & 0x100000) {
        idx = 0;
    } else if (FLD(u32, self, 0x10c) & 0x200000) {
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
        if (FLD(s16, self, 0xf0) == 0) {
            FLD(u8, self, 0x138) = 2;
        } else {
            u16 *hp = self->unk_50;
            u16 pct = hp[0] * 100 / hp[1];
            if (pct <= 0x19) {
                FLD(u8, self, 0x138) = 2;
            } else {
                FLD(u8, self, 0x138) = 1;
            }
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if ((FLD(u32, self, 0x10c) & 0x400000) && (FLD(u32, self, 0x10c) & 0x200000)) {
            FLD(u32, self, 0x10c) |= 0x8000000;
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
        y = FLD(s32, self, 0xf8) + 0x14cd;
        z = FLD(s32, self, 0x78);
        d0.x = x - self->pos.x;
        d0.y = y - self->pos.y;
        d0.z = z - self->pos.z;
        VEC_MultAdd(0x52, &d0, &self->pos, &self->pos);
        switch (FLD(s16, self, 0xf0)) {
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
            func_ov000_0218d988(self, func_ov000_0218d240(self), 0x400);
            t0 = self->unk_b8;
            func_ov000_0218ddd4(self, &t0, 0);
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
            FLD(s32, self, 0x13c) = FLD(s32, o, 0x24);
            FLD(u32, self, 0x10c) |= 2;
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        }
        if (FLD(u32, self, 0x10c) & 2) {
            Ov012V *e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x13c));
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

void func_ov012_021fc688(Ov012Actor *self) {
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
    pl = func_ov000_0218d240(self);
    pp = pl->pos;
    if (FLD(u32, self, 0x10c) & 0x400000) {
        tbl = (Ov012Ad40 *)&data_ov012_0220ad40[4];
        kind = 0x4835;
    } else {
        tbl = (Ov012Ad40 *)&data_ov012_0220ad40[2];
        kind = 0x4834;
    }
    s = self->unk_40;
    switch (s->state) {
    case 0:
        FLD(u32, self, 0x10c) |= 0x800000;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x400, 0);
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if (FLD(u32, self, 0x10c) & 0x400000) {
            FLD(u32, self, 0x10c) |= 0x10000000;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov012V *e;
        s->timer++;
        t = s->timer;
        if (t <= 0x5a) {
            func_ov000_0218d988(self, pl, 0x7b);
        }
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = FLD(s32, self, 0xf8) + 0x14cd;
            s32 z = FLD(s32, self, 0x78);
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
            FLD(s32, self, 0x13c) = FLD(s32, o, 0x24);
            FLD(u32, self, 0x10c) |= 2;
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        }
        if (FLD(u32, self, 0x10c) & 2) {
            e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x13c));
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
            FLD(u32, self, 0x10c) ^= 2;
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
                o->unk_1c = FLD(s16, self, 0x170);
                o->v04();
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                FLD(u16, self, 0xde) = o->id;
            }
            FLD(s32, self, 0x13c) = Ov012_Fx2(self, 0x68, &data_ov012_0220a3de, &v5, &data_ov012_0220a468, 0x1333);
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
            dd.x = pp.x - FLD(s32, self, 0xf4);
            dd.y = pp.y - FLD(s32, self, 0xf8);
            dd.z = pp.z - FLD(s32, self, 0xfc);
            func_01ffc9fc(&dd, &dd, 0xffff - self->rot[1]);
            FLD(s32, self, 0x124) = 0x7000;
            FLD(s32, self, 0x128) = 0;
            FLD(s32, self, 0x12c) = -0xa000;
            if (dd.x <= 0) {
                FLD(s32, self, 0x124) = Ov012_FxMul64d(FLD(s32, self, 0x124), -0x1000);
            }
        } else if (s->timer >= 0x28) {
            if (FLD(u32, self, 0x10c) & 0x10000000) {
                FLD(s32, self, 0x130) = 0x25;
            } else {
                FLD(s32, self, 0x130) = 0x29;
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 11: {
        Ov012Actor *o;
        s->timer++;
        t = s->timer;
        o = Ov012_FindActor(FLD(u16, self, 0xde));
        if (t < tbl->unk_04) {
            if (FLD(u32, self, 0x10c) & 0x800000) {
                func_ov000_0218d918(self, &FLD(Ov012Vec, self, 0x124), FLD(s32, self, 0x130));
                if (self->rot[1] <= 0xe87a && self->rot[1] >= 0x1776) {
                    FLD(u32, self, 0x10c) ^= 0x800000;
                    if (FLD(u32, self, 0x10c) & 0x10000000) {
                        FLD(u32, self, 0x10c) |= 0x20000000;
                    }
                }
            } else if (!(FLD(u32, self, 0x10c) & 0x20000000)) {
                switch (FLD(s16, self, 0xf0)) {
                case 0:
                    if (o != NULL) {
                        o->unk_1a = 1;
                    }
                    self->unk_40->timer = 0;
                    self->unk_40->state++;
                    break;
                case 1:
                    FLD(s32, self, 0x124) = Ov012_FxMul64d(FLD(s32, self, 0x124), -0x1000);
                    if (!(FLD(u32, self, 0x10c) & 0x10000000)) {
                        FLD(s32, self, 0x130) = 0x21;
                    }
                    func_ov000_0218d918(self, &FLD(Ov012Vec, self, 0x124), FLD(s32, self, 0x130));
                    FLD(u32, self, 0x10c) |= 0x800000;
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
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x52, 0);
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
        d2.x = FLD(s32, self, 0xf4) - self->pos.x;
        d2.y = FLD(s32, self, 0xf8) - self->pos.y;
        d2.z = FLD(s32, self, 0xfc) - self->pos.z;
        VEC_MultAdd(0x66, &d2, &self->pos, &self->pos);
        func_ov000_0218d918(self, &FLD(Ov012Vec, self, 0x100), 0xcd);
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 100) {
            return;
        }
        if (FLD(u32, self, 0x10c) & 0x400000) {
            FLD(u32, self, 0x10c) ^= 0x400000;
        }
        if (FLD(u32, self, 0x10c) & 8) {
            FLD(u32, self, 0x10c) ^= 8;
        }
        if (FLD(u32, self, 0x10c) & 0x800000) {
            FLD(u32, self, 0x10c) ^= 0x800000;
        }
        FLD(u8, self, 0x110) = 0;
        FLD(u32, self, 0x10c) |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}

extern "C" {
void func_ov012_021fd708(Ov012Actor *self);
void func_ov012_021fdfa0(Ov012Actor *self);
void func_ov012_021fcf1c(Ov012Actor *self) {
    switch (FLD(s16, self, 0xf0)) {
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
void func_ov012_021fcf48(Ov012Actor *self) {
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
                FLD(u16, o, 0x18) = i;
                o->unk_90 = self->unk_90;
                o->v04();
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                func_ov000_0219bebc(o, FLD(s16, self, 0x170));
                if (FLD(void *, o, 0x4c) != NULL) {
                    FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
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
        FLD(u8, self, 0x110) = 0;
        FLD(u32, self, 0x10c) |= 1;
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
extern void func_ov000_0219b71c(Ov012Vec *pos, Ov012Vec *v, s32 a, s32 b, s32 c, s32 d);
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
    u8 *g = (u8 *)data_ov000_021ccd54;
    FLD(Ov012Flags8, g, 0x190).b2 = 1;
    FLD(Ov012Flags8, g, 0x190).b3 = 1;
    FLD(Ov012Flags8, g, 0x190).b4 = 1;
    g[0x18d] = a;
    g[0x18e] = b;
    g[0x18f] = c;
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

void func_ov012_021fd1b0(Ov012Actor *self) {
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
        o = Ov012_FindActor(FLD(u16, self, 0xde));
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
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += 0x5000;
        FLD(s32, self, 0x13c) = FLD(s32, func_02065f88(0x390, &p), 0x24);
        func_02065f88(5, &p)->v0c(0x5800);
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            FLD(s32, self, 0x114) = 0x3000;
            break;
        case 1:
            FLD(s32, self, 0x114) = -0x4000;
            break;
        }
        self->unk_1a = 0x28;
        Ov012_SetTgt(self);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x4000);
            e->v24(0, FLD(s32, self, 0x6c), 0);
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
            func_02065804(data_0214a420, FLD(s32, self, 0x13c));
        }
        if (t >= 0x8c) {
            {
                s32 y = self->pos.y;
                s32 z = self->pos.z;
                s32 x = self->pos.x;
                d.x = x - FLD(s32, self, 0x70);
                d.y = (y - 0x11000) - FLD(s32, self, 0x74);
                d.z = z - FLD(s32, self, 0x78);
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
            q.y += FLD(s32, self, 0x68) >> 1;
            s.x = self->unk_64;
            s.y = FLD(s32, self, 0x68) >> 2;
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
        Ov012Actor *pl = func_ov000_0219bf90();
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
                FLD(s32, self, 0x114) -= 0xb8;
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
        FLD(Ov012Vec, cam, 0xe8) = FLD(Ov012Vec, self, 0x100);
        FLD(Ov012CamDa, cam, 0xda).b1 = 1;
        FLD(s32, cam, 0xf4) = FLD(s32, self, 0x114);
        FLD(Ov012CamDa, cam, 0xda).b2 = 2;
        FLD(u16, cam, 0xf8) = r + 0x5b0;
        FLD(Ov012CamDa, cam, 0xda).b4 = 1;
    }
}
}

extern "C" {
void func_ov012_021fd708(Ov012Actor *self) {
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
    pl = func_ov000_0218d240(self);
    tbl = (u8 *)&data_ov012_0220ad40[3];
    pp = pl->pos;
    s = self->unk_40;
    switch (s->state) {
    case 0:
        FLD(u8, self, 0x135) = 0;
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
            func_ov000_0218d988(self, pl, 0x7b);
        }
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = FLD(s32, self, 0xf8) + 0x14cd;
            s32 z = FLD(s32, self, 0x78);
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
            FLD(s32, self, 0x13c) = FLD(s32, o, 0x24);
            o = func_02065f88(0x68, &self->pos);
            func_01ffc9fc(&v2, (Ov012Vec *)&data_ov012_0220a420, r1.y);
            o->v0c(0x4000);
            o->v20(&v2);
            o->v30(&r1);
            FLD(s32, o, 0xc8) = 0;
            FLD(s32, self, 0x144) = FLD(s32, o, 0x24);
            FLD(u32, self, 0x10c) |= 2;
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        }
        if (FLD(u32, self, 0x10c) & 2) {
            e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x13c));
            if (e != NULL) {
                func_01ffc9fc(&v3, (Ov012Vec *)&data_ov012_0220a420, self->rot[1]);
                VEC_Add(&v3, &self->pos, &v3);
                e->v18(&v3);
                e->v30(self->rot);
            }
        }
        e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x144));
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
            FLD(s32, self, 0x13c) = 0;
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
            FLD(u32, self, 0x10c) ^= 2;
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
                o->unk_1c = FLD(s16, self, 0x170);
                o->v04();
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                FLD(u16, self, 0xde) = o->id;
            }
            FLD(s32, self, 0x13c) = Ov012_Fx2(self, 0x68, &data_ov012_0220a3cc, &v5, &data_ov012_0220a468, 0x800);
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
        } else if (s->timer >= 0x28) {
            dd.x = pp.x - FLD(s32, self, 0xf4);
            dd.y = pp.y - FLD(s32, self, 0xf8);
            dd.z = pp.z - FLD(s32, self, 0xfc);
            func_01ffc9fc(&dd, &dd, 0xffff - self->rot[1]);
            FLD(s32, self, 0x124) = 0x7000;
            FLD(s32, self, 0x128) = 0;
            FLD(s32, self, 0x12c) = -0xa000;
            if (dd.x <= 0) {
                FLD(u8, self, 0x134) = 0;
                FLD(s32, self, 0x124) = Ov012_FxMul(FLD(s32, self, 0x124), -0x1000);
            } else {
                FLD(u8, self, 0x134) = 1;
            }
            FLD(s32, self, 0x130) = 0xc;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x13c));
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
            o = Ov012_FindActor(FLD(u16, self, 0xde));
            if (o != NULL) {
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
            }
            if (t % 40 == 1) {
                func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
            }
        } else if (t > lim + 0x1e) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x52, 0);
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
        d12.x = FLD(s32, self, 0xf4) - self->pos.x;
        d12.y = FLD(s32, self, 0xf8) - self->pos.y;
        d12.z = FLD(s32, self, 0xfc) - self->pos.z;
        VEC_MultAdd(0x66, &d12, &self->pos, &self->pos);
        func_ov000_0218d918(self, (u8 *)self + 0x100, 0xcd);
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


void func_ov012_021fdfa0(Ov012Actor *self) {
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
    pl = func_ov000_0218d240(self);
    s = self->unk_40;
    px = pl->pos.x;
    tbl = (u8 *)&data_ov012_0220ad40[5];
    switch (s->state) {
    case 0:
        self->unk_9c = 0x19a;
        if (px >= 0) {
            FLD(u8, self, 0x16e) = 0;
        } else {
            FLD(u8, self, 0x16e) = 1;
        }
        FLD(u8, self, 0x135) = 0;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x400, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        tg = FLD(Ov012Vec, self, 0xf4);
        {
            s32 off = 0x5000;
            if (FLD(u8, self, 0x16e) == 1) off -= 0xa000;
            tg.x += off;
        }
        tg.y = self->pos.y;
        Ov012_VecSub(&d, &tg, &self->pos);
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = FLD(s32, self, 0xf8) + 0x14cd;
            s32 z = FLD(s32, self, 0x78);
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
                FLD(s32, self, 0x13c) = FLD(s32, o, 0x24);
                FLD(u32, self, 0x10c) |= 2;
                func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
                if (t == 0x32) {
                    FLD(u32, self, 0x10c) |= 0x10000000;
                }
            }
            if (FLD(u32, self, 0x10c) & 2) {
                e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0x13c));
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
            FLD(u32, self, 0x10c) ^= 2;
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
                o->unk_1c = FLD(s16, self, 0x170);
                o->v04();
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                FLD(u16, self, 0xde) = o->id;
            }
            FLD(s32, self, 0x13c) = Ov012_Fx2(self, 0x68, &data_ov012_0220a3ea, &v5, &data_ov012_0220a468, 0x1800);
            func_02049f44(data_02097e4c, 0x502, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 11:
        s->timer++;
        t = s->timer;
        if (t == 0x14) {
            FLD(u32, self, 0x10c) ^= 0x40000000;
        }
        if (t >= 0x14) {
            Ov012Actor *o;
            tg = self->pos;
            {
                s32 off = 0x3800;
                if (FLD(u8, self, 0x16e) == 0) off -= 0x7000;
                tg.x = FLD(s32, self, 0xf4) + off;
            }
            FLD(Ov012Vec, self, 0xb8) = tg;
            func_ov000_0218ddd4(self, &tg, 0);
            o = Ov012_FindActor(FLD(u16, self, 0xde));
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
            }
        }
        if (t > 0x14 && VEC_Distance(&self->pos, &FLD(Ov012Vec, self, 0xb8)) <= 0) {
            FLD(u8, self, 0x134) = 1;
            FLD(s32, self, 0x130) = 0xc;
            FLD(s32, self, 0x124) = 0x7000;
            FLD(s32, self, 0x128) = 0;
            FLD(s32, self, 0x12c) = -0xa000;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 12: {
        Ov012Actor *r = (Ov012Actor *)Ov012_FindRes(0x4000, 0x4837);
        if (FLD(u32, self, 0x10c) & 0x10000000) {
            u16 pct = self->unk_50[0] * 100 / self->unk_50[1];
            if (pct <= 0x32) {
                tg.x = 0x3800;
                tg.y = 0;
                tg.z = 0x3000;
                if (FLD(u8, self, 0x16e) == 0) {
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
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x52, 0);
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
        if (!(FLD(u32, self, 0x10c) & 0x10000000)) {
            d14.x = FLD(s32, self, 0xf4) - self->pos.x;
            d14.y = FLD(s32, self, 0xf8) - self->pos.y;
            d14.z = FLD(s32, self, 0xfc) - self->pos.z;
            VEC_MultAdd(0x66, &d14, &self->pos, &self->pos);
            func_ov000_0218d918(self, (u8 *)self + 0x100, 0x400);
            s = self->unk_40;
            s->timer++;
            if (s->timer > 0x64) {
                Ov012_Finish(self);
            }
        } else if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x89, 0);
            func_ov000_021915a0(self->unk_38);
        }
        break;
    }
}

}
