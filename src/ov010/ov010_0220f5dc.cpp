#include "ov010/ov010.h"

typedef s32 fx32;

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last of the five records the TU's record table points to. The .data objects before the empty asm
// function are the TU's size-sorted group: their definition order (found with the heapsort model)
// gives both the ROM layout and the stub's init order. The rest keeps definition order.
// The functions at the end (0x021ff21c..0x021fff80) are part of this TU: they read the rotations
// above through the .rodata base plus an offset, which only a TU-local object gives.
struct Ov010Rot { u16 x, y, z; };
struct Ov010Seg { Ov010Vec pos; u16 v[8]; };
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
const Ov010Vec data_ov010_0220fa88 = data_ov010_0220ec20;
char data_ov010_0220fa5c[] = "nut05";
char data_ov010_0220fa56[] = "nut04";
char data_ov010_0220fa50[] = "nut03";
const Ov010Vec data_ov010_0220fa64 = {K(0x1000), K(0), K(0)};
const Ov010Vec data_ov010_0220fa70 = data_ov010_0220ec2c;
char data_ov010_0220fa32[] = "run00";
char data_ov010_0220fa38[] = "gun00";
const Ov010Vec data_ov010_0220fa7c = {K(0xf619), 0x16000, K(-0x67aa)};
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

extern void *data_ov000_021ccd68;
extern Ov010G54 *data_ov000_021ccd54;
s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
void *func_ov000_0218e4cc(void *a, s32 b);
void *func_ov000_0218e6d0(void *a, u16 b, s32 c);
u8 *func_ov000_0219bf90(void);
u16 func_ov003_021d9c38(Ov010Vec *v);
void func_ov000_0218a358(void *a, const void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);

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

extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *o);
extern s32 VEC_Mag(const Ov010Vec *v);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);

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

extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);

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

extern void *data_0214a420;
extern void *data_02097e4c;
extern Ov010V *func_020657b0(void *a, s32 b);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
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
