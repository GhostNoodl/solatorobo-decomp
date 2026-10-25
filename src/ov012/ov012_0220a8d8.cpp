#include "ov012/ov012.h"

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last effect record. Everything follows the empty asm function, so both sections keep definition
// order. The three handler tables are vtables (two zero words, then 41 handlers); the TU's
// functions point objects at the handler part. func_ov012_021fdfa0 at the end is part of this TU:
// it copies data_ov012_0220a3ea through the .rodata base plus an offset.
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
    func_ov012_021fbec8,
    func_ov012_021fc688,
    func_ov012_021fcf1c,
    func_ov012_021fcf48,
    func_ov012_02201ce4,
    func_ov012_02201cd0,
    func_ov012_021fd148,
    (Ov012Fn)func_ov003_021d5348,
    (Ov012Fn)func_ov003_021d5900,
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
