#include "ov010/ov010.h"

typedef s32 fx32;

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last of the five records the TU's record table points to. The .data objects before the empty asm
// function are the TU's size-sorted group: their definition order (found with the heapsort model)
// gives both the ROM layout and the stub's init order. The rest keeps definition order.
// The functions below (0x021fbda0..0x021fff80) are part of this TU: they read the constants and
// the .data above through the section base plus an offset, which only a TU-local object gives.
// 021fbda0 needs that for its shake parameters and the 0x0220fa64 vector (round dtA): with an
// extern view its case 0x15 loads all of 0x0220fa64 before the stores; with the named objects it
// loads z after them, as the ROM does.
struct Ov010Rot { u16 x, y, z; };
// The shake parameters Ov010Shake copies from 0x4c on.
struct Ov010ShakeParam { Ov010Vec dir; s16 lim; s16 acc; u16 dur; s16 k5e; s16 k60; s16 k62; s16 k64; s16 k66; };
struct Ov010Rec { u16 v[8]; const char *name; Ov010Rot rot; Ov010Vec a; Ov010Vec b; };
typedef void (*Ov010Fn)(void);

struct Ov010Shake {
    u8 unk_00[4];
    u8 active;
    u8 unk_05;
    s16 decay;
    Ov010Vec a;
    Ov010Vec b;
    Ov010Vec vel;
    Ov010Vec pos;
    u16 state;
    u16 timer;
    u8 unk_3c[0x10];
    Ov010Vec dir;
    s16 lim;
    s16 acc;
    u16 dur;
    s16 k5e;
    s16 k60;
    s16 k62;
    s16 k64;
    s16 k66;
};

struct Ov010Wobble {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
};

struct Ov010G54 {
    u8 unk_000[0x1ce];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 4;
    u8 unk_1cf;
    s32 unk_1d0;
    s32 unk_1d4;
    s32 unk_1d8;
    u8 unk_1dc[0xc];
    s32 unk_1e8;
};

struct Ov010Fade {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 id;
    u16 timer;
    u16 unk_06;
    s32 state;
    s32 unk_0c;
    s32 key;
    void (*getPos)(Ov010Vec *out, u8 *obj);
};

struct Ov010Toggle {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

extern "C" {

Ov010Vec func_ov010_021fa740(const char *name);
Ov010Vec func_ov010_021fa6a0(const char *name);

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
extern const Ov010Vec data_ov010_0220ec14;
extern const Ov010Vec data_ov010_0220ec20;
extern const Ov010Vec data_ov010_0220ec2c;
extern const Ov010Vec data_ov010_0220ec38;
extern const Ov010Vec data_ov010_0220ec44;
extern const Ov010Vec data_ov010_0220ec50;
extern const Ov010Vec data_ov010_0220ec5c;
extern const Ov010Vec data_ov010_0220ec68;
extern const Ov010Vec data_ov010_0220ec74;
extern const Ov010Vec data_ov010_0220ec80;
extern const Ov010Vec data_ov010_0220ec8c;
extern const Ov010Vec data_ov010_0220ec98;
extern const Ov010Vec data_ov010_0220eca4;
extern const Ov010Vec data_ov010_0220ecb0;
extern const Ov010Vec data_ov010_0220ecbc;
extern const Ov010Vec data_ov010_0220ecc8;
extern const Ov010Vec data_ov010_0220ecd4;
extern const Ov010Vec data_ov010_0220ece0;
extern const Ov010Vec data_ov010_0220ecec;
extern const Ov010Vec data_ov010_0220ecf8;
extern const Ov010Vec data_ov010_0220ed04;
extern char data_ov010_0220fa2c[];
extern char data_ov010_0220fa32[];
extern char data_ov010_0220fa38[];
extern const Ov010Rot data_ov010_0220fa3e;
extern char data_ov010_0220fa44[];
extern char data_ov010_0220fa4a[];
extern char data_ov010_0220fa50[];
extern char data_ov010_0220fa56[];
extern char data_ov010_0220fa5c[];
extern const Ov010Vec data_ov010_0220fa64;
extern const Ov010Vec data_ov010_0220fa70;
extern const Ov010Vec data_ov010_0220fa7c;
extern const Ov010Vec data_ov010_0220fa88;
extern const Ov010ShakeParam data_ov010_0220fa94;
extern const Ov010ShakeParam data_ov010_0220fab0;
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
const Ov010Vec data_ov010_0220fa88 = data_ov010_0220ec20;
char data_ov010_0220fa5c[] = "nut05";
char data_ov010_0220fa56[] = "nut04";
char data_ov010_0220fa50[] = "nut03";
const Ov010Vec data_ov010_0220fa64 = {K(0x1000), K(0), K(0)};
const Ov010Vec data_ov010_0220fa70 = data_ov010_0220ec2c;
char data_ov010_0220fa32[] = "run00";
char data_ov010_0220fa38[] = "gun00";
const Ov010Vec data_ov010_0220fa7c = {K(0xf619), 0x16000, K(-0x67aa)};
const Ov010ShakeParam data_ov010_0220fa94 = {data_ov010_0220ed04, 0x300, 0x20, 0x1e, 0x10, 0x8, 0xf80, 0x60, 0x10};
const Ov010ShakeParam data_ov010_0220fab0 = {data_ov010_0220ed04, 0x180, 0x8, 0x1e, 0xa, 0x4, 0xf60, 0x40, 0xa};

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
Ov010Fn const data_ov010_0220ec0c[2] = {(Ov010Fn)func_ov010_021fa740, (Ov010Fn)func_ov010_021fa6a0};
const Ov010Vec data_ov010_0220ec14 = {0x0, -0x1000, 0x0};
const Ov010Vec data_ov010_0220ec20 = {0x0, 0x0, 0x0};
const Ov010Vec data_ov010_0220ec2c = {0x0, 0x1000, 0x0};
const Ov010Vec data_ov010_0220ec38 = {0x0, 0x0, 0x1000};
const Ov010Vec data_ov010_0220ec44 = {0x0, -0x1000, 0x0};
const Ov010Vec data_ov010_0220ec50 = {0x0, 0x61b2, 0x24d5};
const Ov010Vec data_ov010_0220ec5c = {0x0, 0x74e9, 0x3e77};
const Ov010Vec data_ov010_0220ec68 = {0x0, 0x5580, 0x0};
const Ov010Vec data_ov010_0220ec74 = {-0x59ec, 0x5d48, -0x268f};
const Ov010Vec data_ov010_0220ec80 = {-0x6571, 0x6d71, -0x34a4};
const Ov010Vec data_ov010_0220ec8c = {0xf619, 0x4a1d, -0x67aa};
const Ov010Vec data_ov010_0220ec98 = {0xfafa, 0x2996, -0x42bc};
const Ov010Vec data_ov010_0220eca4 = {0xdc83, 0x64d9, -0xf629};
const Ov010Vec data_ov010_0220ecb0 = {-0x15a19, 0x372b, -0xdd0a};
const Ov010Vec data_ov010_0220ecbc = {0x9600, 0x17d9e, 0x0};
const Ov010Vec data_ov010_0220ecc8 = {0x0, 0x1000, 0x0};
const Ov010Vec data_ov010_0220ecd4 = {-0x15cf, 0x4550, -0x861d};
const Ov010Vec data_ov010_0220ece0 = {0x3a619, 0x1cd9e, 0x0};
const Ov010Vec data_ov010_0220ecec = {0x4e639, 0x268b, 0x1148};
const Ov010Vec data_ov010_0220ecf8 = {0xcf1b, 0x1796, -0xa46f};
const Ov010Vec data_ov010_0220ed04 = {-0x1000, 0x0, 0x0};

const Ov010Rec data_ov010_0220facc = {{0x0, 0x0, 0x0, 0x10, 0x400, 0x3000, 0xf20, 0x8}, data_ov010_0220ebe0, data_ov010_0220fa3e, data_ov010_0220fa88, data_ov010_0220ec8c};
const Ov010Rec data_ov010_0220fb00 = {{0x0, 0x0, 0x0, 0x40, 0x2000, 0x0, 0x1000, 0x0}, data_ov010_0220ebd8, data_ov010_0220fa3e, data_ov010_0220fa88, data_ov010_0220ecec};
const Ov010Rec data_ov010_0220fb34 = {{0x0, 0x0, 0x0, 0x20, 0x2000, 0x0, 0x1000, 0x0}, data_ov010_0220ebcc, data_ov010_0220fa3e, data_ov010_0220fa88, {0x19c00 - K(0xf619), -0x16000, K(-0xdd0a)}};
const Ov010Rec data_ov010_0220fb68 = {{0x3, 0x1, 0x1000, 0x0, 0x1000, 0x7000, 0xe00, 0x20}, data_ov010_0220ebc4, data_ov010_0220ebf0, data_ov010_0220ecec, data_ov010_0220ec8c};
const Ov010Rec data_ov010_0220fb9c = {{0x3, 0x1, 0x1000, 0x0, 0x1000, 0x7000, 0xe00, 0x20}, data_ov010_0220ebcc, data_ov010_0220ebf0, data_ov010_0220ece0, data_ov010_0220ec8c};

extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern Ov010G54 *data_ov000_021ccd54;
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *o);
extern s32 VEC_Mag(const Ov010Vec *v);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void *data_02097e4c;
extern char data_ov010_0220fc13[];
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov000_0218a358(void *a, const void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern u8 *func_ov000_0219bf90(void);
extern u16 func_ov003_021d9c38(const Ov010Vec *v);
extern void func_ov003_021d9dbc(void *out, const Ov010Vec *a, const void *b, s32 dist, s32 yoff);
extern Ov010V *func_ov010_02203ee0(s32 a, const void *v);

struct Ov010Path {
    const char *anim0;
    const char *anim1;
    Ov010Vec a;
    Ov010Vec b;
};

struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

// The attach-point getters (021fa740, 021fa6a0) as 021fbda0 calls them: the vector comes back as one 12-byte block.
typedef Ov010Blk12 (*Ov010OfsFn)(const char *name);

extern const s16 data_ov010_0220fa24;
extern s16 data_ov010_0220fa20;
extern u16 data_ov010_0220fa28;
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern u16 func_ov003_021d9c74(Ov010Vec *a);
extern BOOL func_ov003_021d98bc(void *a, const Ov010Vec *b);
extern void func_ov010_02201b48(void *p);
extern void *func_ov010_02201ad4(void *p, void *fn, u32 time);
extern void func_ov010_02201c9c(void);
extern void func_ov010_02201eac(void *t, u16 a, u16 id, const Ov010Vec *v0, const Ov010Vec *v1);
extern void func_ov010_02201bf4(void *p);
extern BOOL func_ov010_02201c5c(void *p);
extern BOOL func_ov010_02201c34(void *p);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);

static inline void Ov010e_StartE(Ov010Shake *s) {
    if (s->active == 0) {
        s->active = 1;
        OV010_BLKCPY(&s->dir, &data_ov010_0220fa94.dir);
        s->lim = data_ov010_0220fa94.lim;
        s->acc = data_ov010_0220fa94.acc;
        s->dur = data_ov010_0220fa94.dur;
        s->k5e = data_ov010_0220fa94.k5e;
        s->k60 = data_ov010_0220fa94.k60;
        s->k62 = data_ov010_0220fa94.k62;
        s->k64 = data_ov010_0220fa94.k64;
        s->k66 = data_ov010_0220fa94.k66;
        func_ov003_021da48c(&s->state, 0);
    }
}

static inline Ov010Path *Ov010e_NewPath(const char *n0, const char *n1, const Ov010Vec *a, const Ov010Vec *b) {
    Ov010Path *o = (Ov010Path *)func_0203dd9c(0x20);
    if (o != NULL) {
        o->anim0 = n0;
        o->anim1 = n1;
        OV010_BLKCPY(&o->a, a);
        OV010_BLKCPY(&o->b, b);
    }
    return o;
}

struct Ov010Fns2 { Ov010Fn f[2]; };
static inline Ov010Path *Ov010e_MkPath(u8 sel) {
    Ov010Vec v0;
    Ov010Vec v1;
    Ov010Path *o = NULL;
    switch (sel) {
    case 0:
        func_ov003_021d9900(&v0, 0x1000, (Ov010Vec *)&data_ov010_0220ec38);
        func_ov003_021d9980(&v0, 0x4000, &v0);
        o = Ov010e_NewPath(data_ov010_0220ebd4, data_ov010_0220ebd0, &data_ov010_0220eca4, &v0);
        break;
    case 1:
        func_ov003_021d9900(&v1, 0x400, (Ov010Vec *)&data_ov010_0220ec38);
        func_ov003_021d9980(&v1, 0xdfff, &v1);
        o = Ov010e_NewPath(data_ov010_0220ebd0, data_ov010_0220ebd4, &data_ov010_0220ec98, &v1);
        break;
    }
    return o;
}

static inline void Ov010e_Cmd(void *dst, s32 a, s32 b) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = a;
    cmd.b = b;
    func_ov003_021d8b60(dst, &cmd);
}

static inline s32 Ov010e_Clamp(s32 v, s32 max) {
    s32 r;
    if (v > max) {
        r = max;
    } else {
        if (v < 0) {
            v = 0;
        }
        r = v;
    }
    return r;
}
void func_ov010_021fbda0(void *self) {
    Ov010Vec d10;
    Ov010Vec q;
    Ov010Vec d11;
    Ov010Vec r;
    Ov010Vec dv;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        Ov010Path *o;
        if (FLD(void *, self, 0xfc) != NULL) {
            func_0203de1c(FLD(void *, self, 0xfc));
        }
        o = Ov010e_MkPath(FLD(u8, self, 0x1bd));
        FLD(Ov010Path *, self, 0xfc) = o;
        if (o == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
            return;
        }
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0xf00;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 4, 1);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        break;
    }
    case 10: {
        Ov010Path *p;
        Ov010V *e;
        u16 a;
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(Ov010Path *, self, 0xfc)->anim0, data_ov010_0220fa24, 0);
        p = FLD(Ov010Path *, self, 0xfc);
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        d10.x = p->a.x - FLD(s32, self, 0x70);
        d10.y = p->a.y - FLD(s32, self, 0x74);
        d10.z = p->a.z - FLD(s32, self, 0x78);
        VEC_Normalize(&d10, &d10);
        q.x = FLD(s32, self, 0x70);
        q.y = FLD(s32, self, 0x74) + 0x6000;
        q.z = FLD(s32, self, 0x78);
        e = func_02065f88(0x192, &q);
        a = func_ov003_021d9c74(&d10);
        e->v34(a, func_ov003_021d9c38(&d10), 0);
        e->v0c(0x3000);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 11;
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        break;
    }
    case 11: {
        Ov010Path *p = FLD(Ov010Path *, self, 0xfc);
        d11.x = p->a.x - FLD(s32, self, 0x70);
        d11.y = p->a.y - FLD(s32, self, 0x74);
        d11.z = p->a.z - FLD(s32, self, 0x78);
        FLD(s32, self, 0x9c) = Ov010e_Clamp(FLD(s32, self, 0x9c) + 0x60, 0x1000);
        if (VEC_Mag(&d11) < 0x3000) {
            FLD(s32, self, 0x9c) = Ov010_FxMul(FLD(s32, self, 0x9c), 0xf40);
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(Ov010Path *, self, 0xfc)->anim1, data_ov010_0220fa24, 0);
        }
        func_ov003_021d9dbc((u8 *)self + 0x70, &FLD(Ov010Path *, self, 0xfc)->a, (u8 *)self + 0x70, FLD(s32, self, 0x9c), 0);
        if (func_ov003_021d98bc((u8 *)self + 0x70, &FLD(Ov010Path *, self, 0xfc)->a) || FLD(s32, self, 0x9c) < 0x10) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        }
        break;
    }
    case 0x14: {
        u8 *pl = (u8 *)func_ov000_0219bf90();
        u32 i;
        u16 id;
        if (pl == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
            return;
        }
        func_ov010_02201b48((u8 *)self + 0x17c);
        Ov010Fns2 fns = *(const Ov010Fns2 *)data_ov010_0220ec0c;
        id = FLD(u16, pl, 0xc);
        for (i = 0; i < 2; i++) {
            void *t = func_ov010_02201ad4((u8 *)self + 0x17c, (void *)func_ov010_02201c9c, i * 15);
            *(Ov010Blk12 *)&r = ((Ov010OfsFn)fns.f[i])(FLD(Ov010Path *, self, 0xfc)->anim1);
            func_ov010_02201eac(t, id, FLD(u16, self, 0xc), &FLD(Ov010Path *, self, 0xfc)->b, &r);
        }
        func_ov010_02201bf4((u8 *)self + 0x17c);
        Ov010e_StartE(FLD(Ov010Shake *, self, 0x104));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x15;
        break;
    }
    case 0x15:
        if (func_ov010_02201c5c((u8 *)self + 0x17c)) {
            u8 *c;
            dv.x = Ov010_FxMul(data_ov010_0220fa64.x, 0x1000);
            dv.y = Ov010_FxMul(data_ov010_0220fa64.y, 0x1000);
            dv.z = Ov010_FxMul(data_ov010_0220fa64.z, 0x1000);
            c = FLD(u8 *, self, 0x104);
            if (FLD(u8, c, 4)) {
                VEC_Add((Ov010Vec *)(c + 0x20), &dv, (Ov010Vec *)(c + 0x20));
                VEC_Add((Ov010Vec *)(c + 0x2c), &dv, (Ov010Vec *)(c + 0x2c));
            }
            func_ov003_021d68e0(self, 0x63fc, 0x5ad4, 10);
            if (FLD(Ov010Flags8, self, 0xf0).b1) {
                FLD(Ov010Flags8, self, 0xf0).b1 = 0;
                func_02049a48(data_02097e4c, 0xb01, -1, -1, -1);
            }
        }
        if (func_ov010_02201c34((u8 *)self + 0x17c)) {
            func_ov010_02201b48((u8 *)self + 0x17c);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        }
        break;
    case 0x1e:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (data_ov010_0220fa28 == FLD(u16, FLD(u8 *, self, 0x40), 2)) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebe0, data_ov010_0220fa20, 0);
        }
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x78) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
}

// A non-const view of the attach offset: loads from it must stay after earlier stores

extern void *data_02097e4c;
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov010_02201f18(void);
extern void func_ov010_02202074(void *t, u16 a, u16 id, const Ov010Vec *v0, const Ov010Vec *v1);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern s32 VEC_Mag(const Ov010Vec *v);
extern void func_ov003_021d9b8c(Ov010Vec *out, const Ov010Vec *in, s32 max, s32 sub);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);

extern void *data_ov000_021ccd68;
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern Ov010V *func_ov003_021da788(s32 id, void *self, const Ov010Vec *ofs);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov010_022016a0(void *p, Ov010Vec *a, Ov010Vec *b, s32 c);
extern void func_ov010_02201830(void *p, Ov010Vec *a);
extern void func_ov010_02201898(void *p, Ov010Vec *a);
extern void func_ov010_02201700(void *p);
extern BOOL func_ov010_0220180c(void *p);
extern void func_ov000_0218d918(void *self, void *t, s32 a);

struct Ov010Bits16 {
    u16 b0 : 1;
    u16 rest : 15;
};

struct Ov010StBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
};

void func_ov010_021fc4ac(void *self) {
    Ov010Vec up = data_ov010_0220ec14;
    const char *anim = data_ov010_0220ebd0;
    const Ov010Vec *tgt = &data_ov010_0220ecd4;
    const Ov010Vec *grav = &data_ov010_0220ec2c;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec rot;
        Ov010Vec ofs;
        u8 *pl;
        s32 i = 0;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebcc, 0x1000, i);
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = i;
            FLD(u16, cam, 6) = i;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 4, 1);
        FLD(s32, self, 0x9c) = i;
        FLD(s32, self, 0xa0) = i;
        FLD(s32, self, 0xa4) = i;
        FLD(s32, self, 0xa8) = i;
        FLD(s32, self, 0x120) = data_ov010_0220ec20.x;
        FLD(s32, self, 0x124) = data_ov010_0220ec20.y;
        FLD(s32, self, 0x128) = data_ov010_0220ec20.z;
        FLD(s32, self, 0x70) = 0x9600;
        FLD(s32, self, 0x74) = 0x17d9e;
        FLD(s32, self, 0x78) = i;
        func_ov010_02201b48((u8 *)self + 0x17c);
        pl = (u8 *)func_ov000_0219bf90();
        if (pl == NULL) {
            func_ov000_02198360(FLD(void *, self, 0x40), 100, i);
            break;
        }
        for (; i < 3; i++) {
            void *t;
            func_ov003_021d9900(&rot, i * 0xb00 + 0xf800, (Ov010Vec *)&data_ov010_0220ec38);
            ofs.x = -0x1333;
            ofs.y = 0x8000;
            ofs.z = 0x2666;
            t = func_ov010_02201ad4((u8 *)self + 0x17c, (void *)func_ov010_02201f18, i * 15 + 0x50);
            func_ov010_02202074(t, FLD(u16, pl, 0xc), FLD(u16, self, 0xc), &rot, &ofs);
        }
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        break;
    }
    case 10: {
        Ov010Vec d;
        Ov010Vec n;
        FLD(s32, self, 0x120) = data_ov010_0220ec20.x;
        FLD(s32, self, 0x124) = data_ov010_0220ec20.y;
        FLD(s32, self, 0x128) = data_ov010_0220ec20.z;
        d.x = tgt->x - FLD(s32, self, 0x70);
        d.y = tgt->y - FLD(s32, self, 0x74);
        d.z = tgt->z - FLD(s32, self, 0x78);
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0xa00, &n, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        if (VEC_Mag(&d) <= 0xa00) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        }
        break;
    }
    case 0x1e: {
        u8 *g;
        func_ov010_02203ee0(0x12e, (u8 *)self + 0x70)->v0c(0x3000);
        g = (u8 *)data_ov000_021ccd54;
        g[0x190] |= 0x1c;
        g[0x18d] = 10;
        g[0x18e] = 0x1e;
        g[0x18f] = 0x1e;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebe0, 0x80, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1f;
        func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
        break;
    }
    case 0x1f:
        VEC_MultAdd(0x18, &data_ov010_0220ed04, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(0x50, grav, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9b8c(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x400, 0x80);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x28) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x28;
        }
        break;
    case 0x28:
        FLD(s32, self, 0x120) = Ov010_FxMul(FLD(s32, self, 0x120), 0xf50);
        FLD(s32, self, 0x124) = Ov010_FxMul(FLD(s32, self, 0x124), 0xf50);
        FLD(s32, self, 0x128) = Ov010_FxMul(FLD(s32, self, 0x128), 0xf50);
        VEC_MultAdd(4, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9b8c(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x400, 0x20);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x1e) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    case 0x32:
        func_ov000_02190cb0(FLD(void *, self, 0x38), anim, 0x90, 0);
        func_ov010_02201bf4((u8 *)self + 0x17c);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x33;
        func_02049a48(data_02097e4c, 0xb03, -1, -1, -1);
        break;
    case 0x33:
        VEC_MultAdd(0xc, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(9, &up, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(4, &data_ov010_0220ec38, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9aec(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x2000);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if ((s32)FLD(u16, FLD(u8 *, self, 0x40), 2) > 0xf0 && func_ov010_02201c34((u8 *)self + 0x17c)) {
            FLD(Ov010Bits16, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebe0, 0x1000, 0);
        func_ov010_02201b48((u8 *)self + 0x17c);
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
    {
        u8 *c = FLD(u8 *, self, 0x108);
        FLD(Ov010StBits, c, 4).b2 = 1;
        FLD(u16, c, 6) = 0;
    }
}

static inline void *Ov010e_FindActor(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
}
static inline void Ov010e_Pull(void *self, s32 rate) {
    void *a = Ov010e_FindActor(FLD(u16, self, 0x90));
    if (a != NULL) {
        Ov010Vec d;
        s32 x = FLD(s32, a, 0x70);
        s32 y = FLD(s32, a, 0x74);
        s32 z = FLD(s32, a, 0x78);
        d.x = x - FLD(s32, self, 0x12c);
        d.y = y - FLD(s32, self, 0x130);
        d.z = z - FLD(s32, self, 0x134);
        VEC_MultAdd(rate, &d, &FLD(Ov010Vec, self, 0x12c), &FLD(Ov010Vec, self, 0x12c));
    }
}

void func_ov010_021fca40(void *self) {
    BOOL follow = TRUE;
    s32 rate = 0;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u8 *pl;
        rate = 0x100;
        pl = (u8 *)func_ov000_0219bf90();
        if (pl == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        } else {
            FLD(s32, self, 0x12c) = FLD(s32, pl, 0x70);
            FLD(s32, self, 0x130) = FLD(s32, pl, 0x74);
            FLD(s32, self, 0x134) = FLD(s32, pl, 0x78);
            FLD(u16, self, 0x90) = FLD(u16, pl, 0xc);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        }
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        break;
    }
    case 10:
    case 11:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        rate = 0x100;
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x3c) {
                FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
                FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x28;
            }
        }
        break;
    case 0x28: {
        Ov010V *e;
        rate = 0x100;
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, -0x2800);
        e = func_ov003_021da788(0x196, self, &data_ov010_0220ec5c);
        if (e != NULL) {
            e->v0c(0x1a00);
        }
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x29;
        func_02049f44(data_02097e4c, 0x5b, (u8 *)self + 0x70, 0);
        func_02049a48(data_02097e4c, 0xb02, -1, -1, -1);
        break;
    }
    case 0x29:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        rate = 0x100;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x46) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    case 0x32: {
        Ov010Vec v;
        rate = 0x100;
        func_ov003_021d9980(&v, FLD(u16, self, 0x7e), (Ov010Vec *)&data_ov010_0220ec5c);
        VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
        func_ov010_022016a0(FLD(void *, self, 0x100), &FLD(Ov010Vec, self, 0x12c), &v, 0x2bc);
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0xf00;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, 0x3000);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x33;
        break;
    }
    case 0x33: {
        Ov010Vec v;
        follow = FALSE;
        rate = 0x100;
        func_ov003_021d9980(&v, FLD(u16, self, 0x7e), (Ov010Vec *)&data_ov010_0220ec5c);
        VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
        func_ov010_02201830(FLD(void *, self, 0x100), &v);
        func_ov010_02201898(FLD(void *, self, 0x100), &FLD(Ov010Vec, self, 0x12c));
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x3c) {
            void *a = Ov010e_FindActor(FLD(u16, self, 0x90));
            if (a != NULL) {
                Ov010Vec p;
                p.x = FLD(s32, a, 0x70);
                p.y = FLD(s32, a, 0x74);
                p.z = FLD(s32, a, 0x78);
                if (VEC_Distance(&p, &FLD(Ov010Vec, self, 0x84)) > 0x10000) {
                    func_ov010_02201700(FLD(void *, self, 0x100));
                }
            }
        }
        if (func_ov010_0220180c(FLD(void *, self, 0x100))) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x3c;
        }
        break;
    }
    case 0x3c:
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x3d;
        break;
    case 0x3d:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x1e) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x46;
        }
        break;
    case 0x46:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebe0, 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x47;
        break;
    case 0x47:
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    Ov010e_Pull(self, rate);
    if (follow) {
        FLD(s32, self, 0x84) = FLD(s32, self, 0x12c);
        FLD(s32, self, 0x88) = FLD(s32, self, 0x130);
        FLD(s32, self, 0x8c) = FLD(s32, self, 0x134);
    }
    func_ov000_0218d918(self, (u8 *)self + 0x84, 0x180);
    {
        u8 *c = FLD(u8 *, self, 0x108);
        FLD(Ov010StBits, c, 4).b2 = 1;
        FLD(u16, c, 6) = 0;
    }
}

struct Ov010Flags8b {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern void *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 x, s32 z);
extern s32 func_02040528(s32 n);
extern s32 func_02040498(s32 max);
extern void func_ov003_021d6868(void *self, s32 a);
extern void func_ov010_0220172c(void *p);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021da108(void *t, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern void func_ov003_021d97fc(void *p, s32 a);
extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
extern char data_ov010_0220fc19[];
extern char data_ov010_0220fc1f[];
extern u8 data_ov010_0220edd4[];

typedef Ov010Blk12 (*Ov010PosFn)(void *a);

static inline u16 Ov010e_AngTo(void *self, u8 *a) {
    if (a == NULL || a == self) {
        return FLD(u16, self, 0x7e);
    }
    return FX_Atan2(FLD(s32, a, 0x70) - FLD(s32, self, 0x70), FLD(s32, a, 0x78) - FLD(s32, self, 0x78));
}

static inline void Ov010e_Spawn(void *self) {
    if (FLD(Ov010Flags8b, self, 0x138).b0 && FLD(s32, self, 0x140) == 0) {
        void *a = Ov010e_FindActor(FLD(u16, self, 0x13a));
        if (a != NULL) {
            Ov010V *e;
            Ov010Vec w;
            Ov010Vec u;
            *(Ov010Blk12 *)&u = ((Ov010PosFn)FLD(void *, self, 0x14c))(a);
            w.x = FLD(s32, a, 0x70);
            w.y = FLD(s32, a, 0x74);
            w.z = FLD(s32, a, 0x78);
            VEC_Add(&w, &u, &w);
            e = func_02065f88(FLD(s32, self, 0x144), &w);
            FLD(u8, e, 0xd0) = 1;
            FLD(s32, self, 0x148) = FLD(s32, e, 0x24);
            FLD(u8, self, 0x139) = 0x1f;
            FLD(u16, self, 0x13c) = 0;
            FLD(s32, self, 0x140) = 1;
        }
    }
}

void func_ov010_021fcf70(void *self) {
    u16 st;
    s32 i;
    FLD(Ov010Flags8b, self, 0xf0).b1 = 0;
    st = FLD(u16, FLD(u8 *, self, 0x40), 0);
    switch (st) {
    case 0:
    case 1:
        if (st == 0) {
            if (FLD(void *, self, 0x50) != NULL && func_ov000_02199f60(FLD(void *, self, 0x50)) != NULL) {
                FLD(u16, self, 0x98) = Ov010e_AngTo(self, (u8 *)func_ov000_02199f60(FLD(void *, self, 0x50)));
            } else {
                FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
            }
            FLD(u16, self, 0x98) += (u16)(func_02040528(0x2000) + 0x7fff);
            FLD(s32, self, 0x120) = data_ov010_0220ec20.x;
            FLD(s32, self, 0x124) = data_ov010_0220ec20.y;
            FLD(s32, self, 0x128) = data_ov010_0220ec20.z;
            func_ov000_02191418(FLD(void *, self, 0x38), 3, 0);
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
            func_ov010_0220172c(FLD(void *, self, 0x100));
            func_ov010_02201b48((u8 *)self + 0x17c);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        }
        func_ov003_021d6868(self, 0x739f);
        if (FLD(Ov010Flags8b, self, 0x138).b0) {
            FLD(Ov010Flags8b, self, 0x138).b1 = 1;
        }
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 3) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        } else {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = FLD(const u16, FLD(u8 *, self, 0x40), 2) + 1;
        }
        break;
    case 0x14:
    case 0x15:
        if (st == 0x14) {
            u16 rx = (func_02040498(0x2000) - 0x2000) >> 1;
            u16 ry = (func_02040498(0x2000) - 0x2000) >> 1;
            u16 rz = (func_02040498(0x2000) - 0x2000) >> 1;
            FLD(u16, self, 0x7c) += rx;
            FLD(u16, self, 0x7e) += ry;
            FLD(u16, self, 0x80) += rz;
            {
                u16 *hp = FLD(u16 *, self, 0x50);
                u16 d = Ov010_FxMul(hp[1] << 12, 0x19a) >> 12;
                if (d >= hp[0]) {
                    hp[0] = 0;
                } else {
                    hp[0] -= d;
                }
            }
            FLD(s16, self, 0xf2) = 0x1000;
            func_ov003_021d85c8((u8 *)self + 0x150, 0x14, 0, 0, 0);
            {
                u8 *g = (u8 *)data_ov000_021ccd54;
                g[0x190] |= 0x1c;
                g[0x18d] = 0xf;
                g[0x18e] = 0xf;
                g[0x18f] = 0xf;
            }
            func_ov003_021d68e0(self, 0x5adf, 0x739f, 10);
            func_ov003_021d9980(&FLD(Ov010Vec, self, 0x120), FLD(u16, self, 0x98), (Ov010Vec *)&data_ov010_0220ec38);
            FLD(s32, self, 0x120) = Ov010_FxMul(FLD(s32, self, 0x120), 0x800);
            FLD(s32, self, 0x124) = Ov010_FxMul(FLD(s32, self, 0x124), 0x800);
            FLD(s32, self, 0x128) = Ov010_FxMul(FLD(s32, self, 0x128), 0x800);
            if (FLD(Ov010Flags8b, self, 0x138).b0 && FLD(s32, self, 0x140) == 1) {
                FLD(s32, self, 0x140) = 2;
                FLD(u16, self, 0x13c) = 0;
            }
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc19, 0x800, 1);
            FLD(u16, self, 0xb4) = 0;
            FLD(u16, self, 0xb6) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x15;
            func_02049a48(data_02097e4c, 0xb04, -1, -1, -1);
            func_02049f44(data_02097e4c, 0x1a, (u8 *)self + 0x70, 0);
        }
        for (i = 0; i < 3; i++) {
            s32 k = i * 5;
            if (k == FLD(u16, FLD(u8 *, self, 0x40), 2)) {
                func_ov003_021da108(self, 0x6000, 0x6b, 0x1000, 0x3000);
            }
        }
        FLD(s32, self, 0x120) = Ov010_FxMul(FLD(s32, self, 0x120), 0xec0);
        FLD(s32, self, 0x124) = Ov010_FxMul(FLD(s32, self, 0x124), 0xec0);
        FLD(s32, self, 0x128) = Ov010_FxMul(FLD(s32, self, 0x128), 0xec0);
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x19) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc1f, 0x89, 0);
            func_ov000_021915a0(FLD(void *, self, 0x38));
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    case 0x32:
        VEC_MultAdd(0x20, &data_ov010_0220ec44, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(0x30, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        if (FLD(s32, self, 0x74) <= -0x16000) {
            u16 *hp = FLD(u16 *, self, 0x50);
            if ((hp[0] << 12) / hp[1] <= 0x333) {
                Ov010e_Spawn(self);
                if (!func_ov003_021d984c((u8 *)self + 0x1ac, data_ov010_0220edd4)) {
                    func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220edd4, 0x19);
                    func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
                }
            }
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        FLD(u16, self, 0x7c) = func_01ffc128(0, FLD(u16, self, 0x7c), 0x148, 1, 0x8000);
        FLD(u16, self, 0x7e) = func_01ffc128(0xbfff, FLD(u16, self, 0x7e), 0x148, 1, 0x8000);
        FLD(u16, self, 0x80) = func_01ffc128(0, FLD(u16, self, 0x80), 0x148, 1, 0x8000);
        break;
    case 100:
        func_ov000_02198360(FLD(void *, self, 0x40), 0x2b, 0);
        break;
    }
    FLD(Ov010Flags8b, FLD(u8 *, self, 0x108), 4).b1 = 1;
    {
        u8 *cam = FLD(u8 *, self, 0x104);
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0;
    }
    FLD(u16 *, self, 0x50)[5] = 5;
}

extern BOOL func_ov003_021d8b34(void *p, s32 a);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_0203cb78(s32 a, s32 b, s32 c);
extern void *func_ov000_0219b71c(Ov010Vec *pos, Ov010Vec *s, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02065804(void *a, s32 b);
extern void func_02049bb4(void *a, s32 b);
extern void func_ov003_021d6a3c(void *self, s32 a, s32 b, s32 c);
extern Ov010V *func_ov003_021da7e8(s32 id, void *src, const Ov010Vec *ofs);
extern char data_ov010_0220fc25[];
extern void *data_0214a420;

static inline s32 Ov010f_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline Ov010Vec Ov010f_AttachPos(void *self) {
    Ov010Vec r;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (self != NULL && (p = FLD(void *, self, 0x44)) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = FLD(u16, self, 0x7e);
        func_ov003_021d9900(&v, FLD(u16, self, 0x7c), &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&r, &v);
    VEC_Add(&r, &FLD(Ov010Vec, self, 0x70), &r);
    return r;
}

void func_ov010_021fd694(void *self) {
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        if (func_ov003_021d8b34((u8 *)self + 0x1c0, 1)) {
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
        } else {
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
        }
        if (FLD(Ov010Flags8b, self, 0x138).b0 && FLD(s32, self, 0x140) == 1) {
            FLD(s32, self, 0x140) = 2;
            FLD(u16, self, 0x13c) = 0;
        }
        func_ov010_0220172c(FLD(void *, self, 0x100));
        func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
        FLD(u16, FLD(u8 *, self, 0x50), 0) = 0;
        {
            u8 *s44 = FLD(u8 *, self, 0x44);
            FLD(Ov010Flags, s44, 0x22).b0 = 0;
            FLD(Ov010Flags, s44, 0x22).b1 = 0;
        }
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        FLD(s32, self, 0x120) = data_ov010_0220ec20.x;
        FLD(s32, self, 0x124) = data_ov010_0220ec20.y;
        FLD(s32, self, 0x128) = data_ov010_0220ec20.z;
        {
            u8 *c = FLD(u8 *, self, 0x108);
            FLD(Ov010Flags8b, c, 4).b2 = 1;
            FLD(u16, c, 6) = 0;
        }
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0xf00;
        }
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4829, 0x15);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        break;
    case 10:
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc19, 0x266, 1);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 11;
    case 11:
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) < 5) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = FLD(const u16, FLD(u8 *, self, 0x40), 2) + 1;
            break;
        }
        func_0203cb78(0x1e000, 1, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        break;
    case 0x14:
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) % 20 == 0) {
            Ov010Vec pos = Ov010f_AttachPos(self);
            Ov010Vec sc;
            sc.x = FLD(s32, self, 0x64);
            sc.y = FLD(s32, self, 0x68);
            sc.z = FLD(s32, self, 0x64);
            func_ov000_0219b71c(&pos, &sc, 0x733, 0xccd, 3, 0x32);
            func_ov000_0218996c(0x14, 8);
            func_02049f44(data_02097e4c, 0x35, &pos, 0);
        }
        if (FLD(s32, self, 0xf4) == 0) {
            Ov010Vec o = {0, 0, 0};
            o.y = 0x61b2;
            FLD(s32, self, 0xf4) = FLD(s32, func_ov003_021da7e8(0x390, self, &o), 0x24);
        }
        VEC_MultAdd(0x10, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(10, &data_ov010_0220ec44, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9aec(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x180);
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, self, 0x7e) = func_01ffc128(func_ov003_021d9c38(&data_ov010_0220ed04), FLD(u16, self, 0x7e), 0x80, 1, 0x8000);
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x28) {
            FLD(Ov010Flags8b, self, 0x93).b4 = 0;
        }
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) % 25 == 0) {
            func_02049f44(data_02097e4c, 0x44, (u8 *)self + 0x70, 0);
        }
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) >= 0x78) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        } else {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = FLD(const u16, FLD(u8 *, self, 0x40), 2) + 1;
        }
        break;
    case 0x1e: {
        Ov010V *e;
        func_02065804(data_0214a420, FLD(s32, self, 0xf4));
        FLD(s32, self, 0xf4) = 0;
        Ov010Vec pos2 = Ov010f_AttachPos(self);
        func_02065f88(4, &pos2)->v0c(0x3000);
        e = func_02065f88(0x131, &pos2);
        e->v0c(0x2800);
        e->v34(0, func_ov003_021d9c38(&data_ov010_0220fa64), 0);
        func_02065f88(0x68, &pos2)->v0c(0x4800);
        func_02049a48(data_02097e4c, 0xb05, -1, -1, -1);
        func_02049f44(data_02097e4c, 0x19, &pos2, 0);
        VEC_MultAdd(0x800, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc25, 0x800, 1);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1f;
    }
    case 0x1f:
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        func_ov003_021d9b8c(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x200, 0x30);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) >= 0x3c) {
            FLD(s32, self, 0x120) = Ov010f_FxMul64(FLD(s32, self, 0x120), 0x600);
            FLD(s32, self, 0x124) = Ov010f_FxMul64(FLD(s32, self, 0x124), 0x600);
            FLD(s32, self, 0x128) = Ov010f_FxMul64(FLD(s32, self, 0x128), 0x600);
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x28;
        }
        break;
    case 0x28: {
        Ov010Vec d;
        Ov010Vec n;
        d.x = 0xcf1b - FLD(s32, self, 0x70);
        d.y = 0x1796 - FLD(s32, self, 0x74);
        d.z = -0xa46f - FLD(s32, self, 0x78);
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0x20, &n, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9aec(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x800);
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        if (VEC_Mag(&d) <= 0x2800) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    }
    case 0x32:
        FLD(s32, self, 0x120) = Ov010f_FxMul64(FLD(s32, self, 0x120), 0xf00);
        FLD(s32, self, 0x124) = Ov010f_FxMul64(FLD(s32, self, 0x124), 0xf00);
        FLD(s32, self, 0x128) = Ov010f_FxMul64(FLD(s32, self, 0x128), 0xf00);
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        if (VEC_Mag(&FLD(Ov010Vec, self, 0x120)) <= 0x100) {
            FLD(s32, self, 0x120) = data_ov010_0220ec20.x;
            FLD(s32, self, 0x124) = data_ov010_0220ec20.y;
            FLD(s32, self, 0x128) = data_ov010_0220ec20.z;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x3c;
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
            {
                u8 *o = FLD(u8 *, self, 0x104);
                if (FLD(u8, o, 4) == 0) {
                    FLD(u8, o, 4) = 1;
                    OV010_BLKCPY(o + 0x4c, &data_ov010_0220fa94.dir);
                    FLD(s16, o, 0x58) = data_ov010_0220fa94.lim;
                    FLD(s16, o, 0x5a) = data_ov010_0220fa94.acc;
                    FLD(u16, o, 0x5c) = data_ov010_0220fa94.dur;
                    FLD(s16, o, 0x5e) = data_ov010_0220fa94.k5e;
                    FLD(s16, o, 0x60) = data_ov010_0220fa94.k60;
                    FLD(s16, o, 0x62) = data_ov010_0220fa94.k62;
                    FLD(s16, o, 0x64) = data_ov010_0220fa94.k64;
                    FLD(s16, o, 0x66) = data_ov010_0220fa94.k66;
                    func_ov003_021da48c(o + 0x38, 0);
                }
            }
        }
        break;
    case 0x3c:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) >= 0x14) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        func_02049bb4(data_02097e4c, FLD(s32, self, 0x11c));
        Ov010e_Cmd((u8 *)self + 0x1c0, 1, 1);
        func_ov003_021d6a3c(self, FLD(Ov010Flags8b, self, 0xf0).b2, 1, 1);
        func_ov000_02198360(FLD(void *, self, 0x40), 0x2c, 0);
        break;
    }
}

struct Ov010Obj108 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
};

extern void func_ov003_021d9e90(void *out, Ov010Vec *dir, void *in, s32 speed, s32 e);

static inline void Ov010_SetAnim(void *self, void *model, const void *anim, s32 n) {
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
    func_ov000_02190cb0(model, anim, n, 0);
}

void func_ov010_021fe084(void *self) {
    Ov010Vec pos;
    Ov010Vec d;
    Ov010Cmd cmd;
    u16 st = FLD(u16, FLD(u8 *, self, 0x40), 0);
    switch (st) {
    case 0: {
        u8 *cam = FLD(u8 *, self, 0x104);
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0xf00;
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
        Ov010_SetAnim(self, FLD(void *, self, 0x38), data_ov010_0220ebdc, 0x266);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        break;
    }
    case 10:
    case 11: {
        s32 v;
        if (st == 10) {
            Ov010V *e;
            pos.x = FLD(s32, self, 0x70);
            pos.y = FLD(s32, self, 0x74) + 0x6000;
            pos.z = FLD(s32, self, 0x78);
            e = func_02065f88(0x192, &pos);
            e->v34(0xbfff, 0, 0);
            e->v0c(0x3000);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 11;
            func_02049f44(data_02097e4c, 0x29, (u8 *)self + 0x70, 0);
        }
        v = FLD(s32, self, 0x9c) + 0xa0;
        FLD(s32, self, 0x9c) = v;
        if (v > 0x3000) {
            v = 0x3000;
        } else if (v < 0) {
            v = 0;
        }
        FLD(s32, self, 0x9c) = v;
        func_ov003_021d9900(&d, 0x9fff, (Ov010Vec *)&data_ov010_0220ec38);
        func_ov003_021d9980(&d, FLD(u16, self, 0x7e), &d);
        func_ov003_021d9e90((u8 *)self + 0x70, &d, (u8 *)self + 0x70, FLD(s32, self, 0x9c), 0);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 60) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    }
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    {
        Ov010Obj108 *o = FLD(Ov010Obj108 *, self, 0x108);
        o->b2 = 1;
        o->unk_06 = 0;
    }
    FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 5;
}

extern void *func_ov000_0218e4cc(void *a, s32 b);
extern void *func_ov000_0218e6d0(void *a, u16 b, s32 c);
static inline void Ov010h_AttachWorld(void *obj, Ov010Vec *out) {
    Ov010Vec a;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (obj != NULL && (p = FLD(void *, obj, 0x44)) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = FLD(u16, obj, 0x7e);
        func_ov003_021d9900(&v, FLD(u16, obj, 0x7c), &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&a, &v);
    VEC_Add(&a, &FLD(Ov010Vec, obj, 0x70), &a);
    OV010_BLKCPY(out, &a);
}
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern void func_ov000_0218d988(void *self, void *target, s32 a);

struct Ov010G190 {
    u8 lo : 2;
    u8 mid : 3;
    u8 hi : 3;
};

static inline s32 Ov010h_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010h_Cmd(void *self) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = 4;
    cmd.b = 1;
    func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
}

void func_ov010_021fe2a4(void *self) {
    const Ov010Vec *goal = &data_ov010_0220ecb0;
    BOOL flag = FALSE;
    s32 i;
    switch ((s32)FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        void *a;
        {
            u16 id = FLD(u16, func_ov000_0218e4cc(data_ov000_021ccd68, 0x1000), 8);
            a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e6d0(data_ov000_021ccd68, id, 0x1000);
        }
        if (a == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
            break;
        }
        FLD(u16, self, 0x90) = FLD(u16, a, 0xc);
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0;
        }
        Ov010h_Cmd(self);
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebc4, 0x1000, 0);
        FLD(s32, self, 0x78) = 0x1148;
        FLD(u16, self, 0x7e) = 0xbfff;
        FLD(u16, self, 0x7c) = 0;
        FLD(s32, self, 0x70) = 0x4e639;
        FLD(u16, self, 0x80) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x74) = 0x268b;
        FLD(s32, self, 0x9c) = 0x3000;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        func_02049f44(data_02097e4c, 0x32, (u8 *)self + 0x70, 0);
        break;
    }
    case 10: {
        u8 *g = (u8 *)data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0x1e;
        FLD(u8, g, 0x18e) = 10;
        FLD(u8, g, 0x18f) = 10;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0xb;
        break;
    }
    case 0xb:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x3c) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        }
        break;
    case 0x14: {
        func_ov003_021d6868(self, 0x2bde);
        for (i = 0; i < 3; i++) {
            if (FLD(u16, FLD(u8 *, self, 0x40), 2) == (u16)((i + 1) * 10)) {
                Ov010V *e;
                {
                    Ov010Vec q;
                    Ov010h_AttachWorld(self, &q);
                    e = func_ov010_02203ee0(0x68, &q);
                }
                e->v0c(0x2800);
                e->v34(0x4000, FLD(u16, self, 0x7e), 0);
            }
        }
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), goal, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), 0);
        if (VEC_Distance(goal, &FLD(Ov010Vec, self, 0x70)) < 0x18000) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        }
        break;
    }
    case 0x1e:
    case 0x1f:
        flag = TRUE;
        if (FLD(u16, FLD(u8 *, self, 0x40), 0) == 0x1e) {
            u8 *cam;
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebc8, 0x100, 0);
            func_0204a028(data_02097e4c, 0xf, &FLD(Ov010Vec, self, 0x70), -5);
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
            cam = FLD(u8 *, self, 0x104);
            if (FLD(u8, cam, 4) == 0) {
                FLD(u8, cam, 4) = 1;
                OV010_BLKCPY(cam + 0x4c, &data_ov010_0220fab0.dir);
                FLD(s16, cam, 0x58) = data_ov010_0220fab0.lim;
                FLD(s16, cam, 0x5a) = data_ov010_0220fab0.acc;
                FLD(u16, cam, 0x5c) = data_ov010_0220fab0.dur;
                FLD(s16, cam, 0x5e) = data_ov010_0220fab0.k5e;
                FLD(s16, cam, 0x60) = data_ov010_0220fab0.k60;
                FLD(s16, cam, 0x62) = data_ov010_0220fab0.k62;
                FLD(s16, cam, 0x64) = data_ov010_0220fab0.k64;
                FLD(s16, cam, 0x66) = data_ov010_0220fab0.k66;
                func_ov003_021da48c(cam + 0x38, 0);
            }
            func_ov003_021d68e0(self, 0x2bde, 0x6739, 0x50);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1f;
        }
        {
            u16 id = FLD(u16, self, 0x90);
            void *t = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
            func_ov000_0218d988(self, t, 0x180);
        }
        FLD(s32, self, 0x9c) = Ov010h_Mul64(FLD(s32, self, 0x9c), 0xe00);
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), goal, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), 0);
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            Ov010V *e;
            {
                Ov010Vec q;
                Ov010h_AttachWorld(self, &q);
                e = func_ov010_02203ee0(0x12f, &q);
            }
            e->v0c(0x3000);
            e->v34(0xbfff, FLD(u16, self, 0x7e), 0);
            func_02049f44(data_02097e4c, 0x52, (u8 *)self + 0x70, 0);
        }
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x78) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        flag = TRUE;
        FLD(u16, self, 0x7e) = func_01ffc128(FLD(u16, self, 0x90), FLD(u16, self, 0x7e), 0x180, 1, 0x8000);
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    {
        Ov010Obj108 *o = FLD(Ov010Obj108 *, self, 0x108);
        o->b2 = 1;
        o->unk_06 = 0;
    }
    if (flag && func_ov000_02191120(FLD(void *, self, 0x38))) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
    if (FLD(u16, FLD(u8 *, self, 0x40), 0) < 0x1e) {
        FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 5;
    }
}

struct Ov010Node {
    u8 unk_00[0x8];
    Ov010Node *next;
    u16 unk_0c;
    u16 unk_0e;
};

extern void func_ov003_021d9740(void *p, s32 a);
extern void func_ov010_021fbb40(void *self);

static inline void Ov010Cam_Start(u8 *cam) {
    if (FLD(u8, cam, 0x4) == 0) {
        FLD(u8, cam, 0x4) = 1;
        OV010_BLKCPY(cam + 0x4c, &data_ov010_0220fa94.dir);
        FLD(s16, cam, 0x58) = data_ov010_0220fa94.lim;
        FLD(s16, cam, 0x5a) = data_ov010_0220fa94.acc;
        FLD(u16, cam, 0x5c) = data_ov010_0220fa94.dur;
        FLD(s16, cam, 0x5e) = data_ov010_0220fa94.k5e;
        FLD(s16, cam, 0x60) = data_ov010_0220fa94.k60;
        FLD(s16, cam, 0x62) = data_ov010_0220fa94.k62;
        FLD(s16, cam, 0x64) = data_ov010_0220fa94.k64;
        FLD(s16, cam, 0x66) = data_ov010_0220fa94.k66;
        func_ov003_021da48c(cam + 0x38, 0);
    }
}

void func_ov010_021fe928(void *self) {
    u16 st = FLD(u16, FLD(u8 *, self, 0x40), 0);
    if (st == 0) {
        Ov010Obj108 *o;
        FLD(u8, self, 0x1bc) = 2;
        FLD(u8, self, 0x1bd) = 3;
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
        o = FLD(Ov010Obj108 *, self, 0x108);
        o->b2 = 0;
        o->b3 = 0;
        o->unk_06 = 0;
        o->unk_08 = 0;
        o->unk_0a = 0;
    } else if (st == 100) {
        func_ov003_021d97fc((u8 *)self + 0x1ac, 0);
        func_ov003_021d9740((u8 *)self + 0x1ac, 0xff);
    }
    func_ov010_021fbb40(self);
}

void func_ov010_021fe9b4(void) {
}

void func_ov010_021fe9b8(void *self) {
    FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 5;
}

void func_ov010_021fe9c8(void *self) {
    Ov010Vec v;
    Ov010Vec off;
    Ov010Cmd cmd;
    u16 *st;
    if (FLD(u16, FLD(u8 *, self, 0x40), 0) == 0) {
        Ov010Cam_Start(FLD(u8 *, self, 0x104));
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc25, 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, FLD(u8 *, self, 0x50), 0) = 0;
        {
            u8 *q = FLD(u8 *, self, 0x44);
            FLD(Ov010Flags, q, 0x22).b0 = 0;
            FLD(Ov010Flags, q, 0x22).b1 = 0;
        }
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        func_ov003_021d88ec(&cmd);
        cmd.a = 2;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
        FLD(u16, FLD(u8 *, self, 0x40), 0)++;
    }
    FLD(u16, FLD(u8 *, self, 0x40), 2)++;
    st = FLD(u16 *, self, 0x40);
    if (st[1] % 60 == 0) {
        Ov010V *p;
        u8 *q;
        st[1] = 0;
        v.x = FLD(s32, self, 0x70) + func_02040528(FLD(s32, self, 0x64));
        v.y = FLD(s32, self, 0x74) + func_02040528(FLD(s32, self, 0x64));
        v.z = FLD(s32, self, 0x78) + func_02040528(FLD(s32, self, 0x64));
        q = FLD(u8 *, self, 0x44);
        off.x = FLD(s32, q, 0xc);
        off.y = FLD(s32, q, 0x10);
        off.z = FLD(s32, q, 0x14);
        VEC_Add(&v, &off, &v);
        p = func_02065f88(0x325, &v);
        p->v34(0, 0x4000, 0);
        p->v14(0x2800, 0x2800, 0x2800);
    }
}

void func_ov010_021febfc(void *self) {
    Ov010Cmd cmd;
    u16 *st = FLD(u16 *, self, 0x40);
    if (*(const u16 *)st != 0) {
        return;
    }
    st[0]++;
    switch (FLD(u8, self, 0x1bd)) {
    case 0:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
        break;
    case 1:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 2);
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
        break;
    case 2:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
        break;
    }
}

void func_ov010_021fecb0(void *self) {
    u16 *c = FLD(u16 *, self, 0xf8);
    c[0] = 0;
    c[1] = 0;
    if (FLD(Ov010Flags8, self, 0x138).b0) {
        if (FLD(s32, self, 0x140) == 1) {
            FLD(s32, self, 0x140) = 2;
            FLD(u16, self, 0x13c) = 0;
        }
    }
}

static inline Ov010Node *Ov010List_Next(Ov010Node *head, Ov010Node *n) {
    if (n != NULL) {
        return n->next;
    }
    return head;
}

void func_ov010_021fecec(void *self) {
    void *list = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4829);
    BOOL found = FALSE;
    u8 *pl = func_ov000_0219bf90();
    Ov010Node *head = FLD(Ov010Node *, list, 0xc);
    Ov010Node *n;
    for (n = head; n != NULL; n = Ov010List_Next(head, n)) {
        if (n->unk_0e == 0x4829 && FLD(u16, pl, 0xb1c) != n->unk_0c) {
            found = TRUE;
            break;
        }
    }
    if (found) {
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
    } else {
        func_ov003_021d969c((u8 *)self + 0x1ac, 0);
    }
}

void func_ov010_021fed88(void *self) {
    u8 k = FLD(u8, self, 0x1bd);
    if (k == 0) {
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
    } else if (k == 1) {
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
    }
}

void func_ov010_021fedc4(void *self) {
    FLD(Ov010Flags8, self, 0xf0).b1 = 1;
}

void func_ov010_021fedd4(void *self) {
    FLD(Ov010Flags8, self, 0xf0).b0 = 0;
    FLD(Ov010Flags8, self, 0xf0).b1 = 0;
    FLD(Ov010Flags8, self, 0xf0).b2 = 0;
    FLD(Ov010Flags8, self, 0xf0).b3 = 0;
    FLD(u16, self, 0xf2) = 0;
    FLD(s32, self, 0xf4) = 0;
    FLD(s32, self, 0xf8) = 0;
    FLD(s32, self, 0xfc) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x104) = 0;
    FLD(s32, self, 0x108) = 0;
    FLD(s32, self, 0x10c) = 0;
    FLD(s32, self, 0x110) = 0;
    FLD(s32, self, 0x114) = 0;
    FLD(s32, self, 0x118) = 0;
    FLD(s32, self, 0x11c) = -1;
    FLD(Ov010Vec, self, 0x120) = data_ov010_0220ec20;
    FLD(Ov010Vec, self, 0x12c) = FLD(Ov010Vec, self, 0x120);
    FLD(u8, self, 0x1bc) = 0;
    FLD(u8, self, 0x1bd) = 0xff;
}

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern Ov010Heap *data_02097dd0;
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void *func_ov010_02200db8(void *p);
extern void func_ov003_021d8fa8(void *p);
extern void func_ov003_021cf480(void *p);
extern void func_ov010_021fedd4(void *self);

static inline void Ov010_FreeV(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        Ov010V *p = FLD(Ov010V *, self, off);
        if (p != NULL) {
            p->v04();
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_ov010_021fee70(void *self) {
    u32 saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    func_02065804(data_0214a420, FLD(s32, self, 0xf4));
    FLD(s32, self, 0xf4) = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xf8) != NULL) {
        func_0203de1c(FLD(void *, self, 0xf8));
        FLD(void *, self, 0xf8) = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(self, 0x110);
    Ov010_FreeV(self, 0x114);
    Ov010_FreeV(self, 0x118);
    if (FLD(void *, self, 0xfc) != NULL) {
        func_0203de1c(FLD(void *, self, 0xfc));
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x100) != NULL) {
        void *p = FLD(void *, self, 0x100);
        if (p != NULL) {
            func_ov010_02200db8(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0x100) = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(self, 0x104);
    Ov010_FreeV(self, 0x108);
    Ov010_FreeV(self, 0x10c);
    if (FLD(Ov010Flags8, self, 0x138).b0) {
        func_02065804(data_0214a420, FLD(s32, self, 0x148));
        FLD(Ov010Flags8, self, 0x138).b0 = 0;
    }
    ((Ov010V *)((u8 *)self + 0x150))->v08();
    ((Ov010V *)((u8 *)self + 0x17c))->v08();
    ((Ov010V *)((u8 *)self + 0x19c))->v08();
    func_ov003_021d8fa8((u8 *)self + 0x1ac);
    ((Ov010V *)((u8 *)self + 0x1c0))->v08();
    func_ov003_021cf480((u8 *)self + 0x1d0);
    func_ov010_021fedd4(self);
}

void *func_ov010_021ff0fc(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff110(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff124(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff138(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff14c(void *self) {
    func_0203de1c(self);
    return self;
}

static inline void Ov010_VecSub(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline void *Ov010_FindObj(u16 id, s32 kind) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e6d0(data_ov000_021ccd68, id, kind);
    }
    return NULL;
}

static inline Ov010Vec Ov010_TargetPos(void) {
    void *o = Ov010_FindObj(FLD(u16, func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 8), 0x5c06);
    Ov010Vec p = data_ov010_0220fa88;
    if (o != NULL) {
        p = FLD(Ov010Vec, o, 0x70);
        p.y = 0x7000;
    }
    return p;
}

BOOL func_ov010_021ff160(void *self) {
    FLD(u8, self, 4) = 0;
    FLD(s32, self, 8) = 0;
    FLD(Ov010Vec, self, 0xc) = Ov010_TargetPos();
    return TRUE;
}

static inline BOOL Ov010_PlBusy(u8 *pl) {
    return FLD(Ov010Flags32, pl, 0xb24).b0 ? TRUE : FALSE;
}

void func_ov010_021ff21c(void *self) {
    u8 *pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (Ov010_PlBusy(pl)) {
        return;
    }
    Ov010Vec pp;
    Ov010_VecCopy(&pp, &FLD(Ov010Vec, pl, 0x70));
    if (FLD(u8, self, 4) == 0) {
        FLD(Ov010Vec, self, 0xc) = Ov010_TargetPos();
    }
    Ov010Vec d;
    Ov010_VecSub(&FLD(Ov010Vec, self, 0xc), &pp, &d);
    Ov010Rot r = data_ov010_0220ebea;
    r.y = func_ov003_021d9c38(&d);
    s32 dist = VEC_Distance(&pp, &FLD(Ov010Vec, self, 0xc));
    func_ov000_0218a358((u8 *)data_ov000_021ccd54 + 0xf4, &FLD(Ov010Vec, self, 0xc), &r, FLD(s32, self, 8) + dist + 0x10000, 0, 0x1000, 0x1000, 1);
}

void func_ov010_021ff3d0(void *self, s32 *msg) {
    switch (msg[0]) {
    case 2:
        FLD(u8, self, 4) = (msg[1] == 1) ? TRUE : FALSE;
        break;
    case 3:
        FLD(s32, self, 8) = msg[1];
        break;
    }
}

static inline s32 Ov010s_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov010s_Dot(const Ov010Vec *a, const Ov010Vec *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

void func_ov010_021ff404(Ov010Shake *self) {
    if (self->active) {
        switch (self->state) {
        case 0: {
            u16 r = func_ov003_021d9c38(&self->dir);
            self->a.x = Ov010s_Mul64(self->dir.x, -0x1000);
            self->a.y = Ov010s_Mul64(self->dir.y, -0x1000);
            self->a.z = Ov010s_Mul64(self->dir.z, -0x1000);
            func_ov003_021d9900(&self->b, 0xe39, (Ov010Vec *)&data_ov010_0220ec38);
            func_ov003_021d9980(&self->b, r, &self->b);
            self->pos = self->vel = data_ov010_0220ec20;
            self->state = 10;
            break;
        }
        case 10:
            VEC_MultAdd(self->acc, &self->dir, &self->vel, &self->vel);
            self->timer++;
            if (self->timer > self->dur) {
                self->timer = 0;
                self->state = 0x14;
            }
            break;
        case 0x14: {
            Ov010Vec u;
            Ov010Vec t;
            s32 k;
            self->vel.y = Ov010s_Mul64(self->vel.y, 0xf00);
            *(Ov010Blk12 *)&t = *(Ov010Blk12 *)&data_ov010_0220ecc8;
            k = self->k5e;
            u.x = Ov010_FxMul(self->a.x, k);
            u.y = Ov010_FxMul(self->a.y, k);
            u.z = Ov010_FxMul(self->a.z, k);
            k = self->k60;
            t.x = Ov010_FxMul(t.x, k);
            t.y = Ov010_FxMul(t.y, k);
            t.z = Ov010_FxMul(t.z, k);
            if (Ov010s_Dot(&self->pos, &self->dir) < 0) {
                k = self->k62;
                self->vel.x = Ov010_FxMul(self->vel.x, k);
                self->vel.y = Ov010_FxMul(self->vel.y, k);
                self->vel.z = Ov010_FxMul(self->vel.z, k);
                if (VEC_Mag(&self->vel) < self->k64) {
                    self->state = 0x1e;
                }
            } else {
                VEC_Add(&self->vel, &u, &self->vel);
                VEC_Add(&self->vel, &t, &self->vel);
            }
            break;
        }
        case 0x1e: {
            Ov010Vec w;
            s32 e;
            w.x = Ov010s_Mul64(self->pos.x, -0x1000);
            w.y = Ov010s_Mul64(self->pos.y, -0x1000);
            w.z = Ov010s_Mul64(self->pos.z, -0x1000);
            VEC_Normalize(&w, &w);
            VEC_MultAdd(self->k66, &w, &self->vel, &self->vel);
            func_ov003_021d9aec(&self->vel, &self->vel, 0x300);
            {
            Ov010Vec up;
            up.x = 0; up.y = 0x1000; up.z = 0;
            e = Ov010s_Dot(&self->pos, &up);
            }
            if (Ov010s_Dot(&self->pos, &self->dir) >= 0 && e <= 0) {
                self->state = 0x14;
            }
            break;
        }
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        func_ov003_021d9aec(&self->vel, &self->vel, self->lim);
    } else {
        s32 k = self->decay;
        self->vel.x = Ov010_FxMul(self->vel.x, k);
        self->vel.y = Ov010_FxMul(self->vel.y, k);
        self->vel.z = Ov010_FxMul(self->vel.z, k);
        if (VEC_Mag(&self->vel) < 0x20) {
            self->vel = data_ov010_0220ec20;
        }
    }
}

void func_ov010_021ff924(Ov010Wobble *o) {
    if (!o->b1) {
        if (o->b2) {
            o->unk_08 = func_01ffc128(o->unk_06, o->unk_08, 0x148, 1, 0x8000);
            o->b2 = 0;
            o->b3 = 1;
            o->unk_06 = 0;
        } else if (o->b3) {
            o->unk_08 = func_01ffc128(0, o->unk_08, 0x148, 1, 0x8000);
            if (o->unk_08 < 0x200 || o->unk_08 >= 0xfdff) {
                o->b3 = 0;
                o->unk_0a = 0;
            }
        } else {
            o->unk_0a += 0x80;
            o->unk_08 = func_01ffc128((u16)((s32)(((s64)OV010_SIN(o->unk_0a) * 0xc00000 + 0x800) >> 12) >> 12), o->unk_08, 0x100, 1, 0x8000);
        }
    }
    o->b1 = o->b0;
}

extern Ov010V *func_020657b0(void *a, s32 b);
extern s32 FX_Div(s32 a, s32 b);

static inline u8 Ov010_Clamp31(u8 v) {
    return v > 0x1f ? 0x1f : v;
}

void func_ov010_021ffa6c(Ov010Fade *self) {
    u8 *tgt;
    s32 flag;
    Ov010V *obj;
    s32 x;
    s32 v;

    if (!self->b0) {
        return;
    }
    if (self->state != 0) {
        obj = func_020657b0(data_0214a420, self->key);
        u16 id = self->id;
        tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        if (obj == NULL || tgt == NULL) {
            self->state = 2;
            self->timer = 0;
        } else if (self->b1) {
            FLD(u8, obj, 0xd0) = 1;
        } else {
            Ov010Vec c;
            Ov010Vec b;
            Ov010Vec a;
            x = 0x1f;
            flag = 0;
            FLD(u8, obj, 0xd0) = 0;
            switch (self->state) {
            case 1:
                if (self->timer == 0) {
                    FLD(u8, obj, 0xd0) = 0;
                    FLD(s32, obj, 0xc8) = -1;
                    flag = 1;
                }
                break;
            case 2:
                FLD(u8, obj, 0xd0) = 1;
                obj->v0c(FLD(s32, obj, 0x40) + (s32)(((s64)(0x2800 - FLD(s32, obj, 0x40)) * 0x280 + 0x800) >> 12));
                x = 0x1f - self->timer * 2;
                if (self->timer > 0x1e) {
                    FLD(s32, obj, 0x1c) = 4;
                    self->state = 0;
                    self->timer = 0;
                }
                break;
            }
            v = x - (0x1f - self->unk_01);
            if (v > 0x1f) {
                v = 0x1f;
            } else if (v < 1) {
                v = 1;
            }
            FLD(s32, obj, 0x7c) = FX_Div(Ov010_Clamp31(v) << 12, 0x1f000);
            self->getPos(&a, tgt);
            *(Ov010Blk12 *)&b = *(Ov010Blk12 *)&a;
            c.x = FLD(s32, tgt, 0x70);
            c.y = FLD(s32, tgt, 0x74);
            c.z = FLD(s32, tgt, 0x78);
            obj->v18(&c);
            obj->v20(&b);
            if (flag) {
                func_02049f44(data_02097e4c, 0x7a, &c, 0);
            }
            self->timer++;
        }
    }
    self->b1 = 0;
}

void func_ov010_021ffc98(void) {
}

void func_ov010_021ffc9c(void) {
}

void func_ov010_021ffca0(void) {
}

void func_ov010_021ffca4(Ov010Toggle *o, s32 *msg) {
    switch (msg[0]) {
    case 1:
        o->b0 = msg[1] == 0;
        break;
    case 4:
        o->b1 = msg[1] == 1;
        break;
    }
}

static inline void Ov010_SetSky(void) {
    Ov010G54 *g = data_ov000_021ccd54;
    g->unk_1d0 = 0;
    g->unk_1d4 = 0x5580;
    g->unk_1d8 = 0;
    g->b0 = 1;
    g = data_ov000_021ccd54;
    g->unk_1e8 = 0x5c00;
    g->b2 = 2;
}

void func_ov010_021ffd0c(Ov010Toggle *o) {
    if (o->b0) {
        Ov010Vec v = data_ov010_0220ec80;
        Ov010Rot r = data_ov010_0220ebfc;
        func_ov000_0218a358((u8 *)data_ov000_021ccd54 + 0xf4, &v, &r, 0x17385, 0, 0x1000, 0x1000, 1);
    } else if (o->b1) {
        Ov010_SetSky();
    }
}

BOOL func_ov010_021ffe04(Ov010Toggle *o) {
    o->b0 = 1;
    o->b1 = 0;
    return TRUE;
}

void func_ov010_021ffe24(Ov010Toggle *o, s32 *msg) {
    switch (msg[0]) {
    case 1:
        o->b0 = msg[1] == 0;
        break;
    case 4:
        o->b1 = msg[1] == 1;
        break;
    }
}

void func_ov010_021ffe8c(Ov010Toggle *o) {
    if (o->b0) {
        Ov010Vec v = data_ov010_0220ec74;
        Ov010Rot r = data_ov010_0220ebf6;
        func_ov000_0218a358((u8 *)data_ov000_021ccd54 + 0xf4, &v, &r, 0xf000, 0, 0x1000, 0x1000, 1);
    } else if (o->b1) {
        Ov010_SetSky();
    }
}

}
