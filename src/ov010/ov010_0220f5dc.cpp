#include "ov010/ov010.h"
#include "ov000/ObjLayouts.h"
#include "nitro/std.h"

typedef s32 fx32;

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last of the five records the TU's record table points to. The .data objects before the empty asm
// function are the TU's size-sorted group: their definition order (found with the heapsort model)
// gives both the ROM layout and the stub's init order. The rest keeps definition order.
// The functions below (0x021fa6a0..0x021fff80, the start of the overlay) are part of this TU: they
// read the constants and the .data above through the section base plus an offset, which only a
// TU-local object gives. The six files before 021fbda0 were merged in round dtB, each in its own
// namespace so their local types and inlines keep their names; they read the TU's objects by name
// (data_ov010_0220fa94.lim.., data_ov010_0220ebd0/ebd4/ebe0) instead of views of 0x0220fa2c/0x0220ebc0.
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
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern u16 Ov003Vec_Yaw(const Ov010Vec *v);
extern void func_ov003_021d9dbc(void *out, const Ov010Vec *a, const void *b, s32 dist, s32 yoff);
extern Ov010V *func_ov010_02203ee0(s32 a, const void *v);


// ---- merged from ov010_021fa6a0.cpp
namespace m_021fa6a0 {
extern "C" {


Ov010Vec func_ov010_021fa6a0(const char *name) {
    Ov010Vec v = data_ov010_0220fa88;
    if (STD_CompareString(name, data_ov010_0220ebd0) == 0) {
        v.x = 0x333;
        v.y = 0x84ee;
        v.z = 0x266f;
    } else if (STD_CompareString(name, data_ov010_0220ebd4) == 0) {
        v.x = -0x2008;
        v.y = 0x6819;
        v.z = 0x266f;
    }
    return v;
}

Ov010Vec func_ov010_021fa740(const char *name) {
    Ov010Vec v = data_ov010_0220fa88;
    if (STD_CompareString(name, data_ov010_0220ebd0) == 0) {
        v.x = 0x2008;
        v.y = 0x6819;
        v.z = 0x266f;
    } else if (STD_CompareString(name, data_ov010_0220ebd4) == 0) {
        v.x = -0x333;
        v.y = 0x84ee;
        v.z = 0x266f;
    }
    return v;
}

Ov010Vec func_ov010_021fa7e0(void *obj) {
    return Ov010_AttachOffset(obj);
}

}
}  // namespace m_021fa6a0

// ---- merged from ov010_021fa860.cpp
struct Ov010Path;

struct Obj021fa860 : public Ov010Obj {
    u8 unk_ac[0x8];
    u16 unk_b4;
    u16 unk_b6;
    u8 unk_b8[0xc];
    s32 unk_c4;
    u8 unk_c8[0x8];
    void *unk_d0;
    u8 unk_d4[0x16];
    Ov010Flags unk_ea;
    u8 unk_ec[0x4];
    Ov010Flags8 unk_f0;
    u8 unk_f1[0x1];
    s16 unk_f2;
    s32 unk_f4;
    u16 *unk_f8;
    Ov010Path *unk_fc;
    void *unk_100;
    Ov010Shake *unk_104;
    u8 *unk_108;
    void *unk_10c;
    void *unk_110;
    void *unk_114;
    void *unk_118;
    s32 unk_11c;
    Ov010Vec unk_120;
    Ov010Vec unk_12c;
    Ov010Flags8 unk_138;
    u8 unk_139;
    u16 unk_13a;
    u16 unk_13c;
    u8 unk_13e[0x2];
    s32 unk_140;
    s32 unk_144;
    s32 unk_148;
    void *unk_14c;
    u8 unk_150[0x6c];
    u8 unk_1bc;
    u8 unk_1bd;
};

namespace m_021fa860 {
extern "C" {

extern u8 data_ov010_0220fccc[];
extern char data_ov010_0220fbd0[];
extern char data_ov010_0220fbdd[];
extern char data_ov010_0220fbec[];
extern char data_ov010_0220fbf7[];
extern char data_ov010_0220fc02[];
extern void *data_02097e4c;
extern void *data_0214a420;

extern void func_ov003_021d0c1c(void *self);
extern void *func_ov003_021d0edc(void *self);
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *func_ov010_02201914(void *p);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void func_ov003_021d8f24(void *p);
extern void *Ov003Vt_021f7cf4_Ctor(void *p);
extern void func_ov003_021cf418(void *p);
extern void func_ov003_021cf340(const char *p);
extern void func_ov003_021cf3fc(s32 a);
extern void func_ov003_021cf39c(s32 a, const char *b);
extern void func_ov010_021fedd4(Obj021fa860 *self);
extern void SndMgr_StopSeqArc(void *a, s32 b);
extern void func_ov010_021fee70(Obj021fa860 *self);
extern void *func_ov003_021cf428(void *p);
extern void *Ov003Vt_021f7cf4_Dtor(void *p);
extern void func_ov003_021d8f34(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void *func_ov010_02201944(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void func_02065804(void *a, s32 b);
extern BOOL func_ov000_0218cf5c(void *self);
extern void func_02049564(void *a, s32 b, s32 c);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL SndMgr_IsLoadDone(void *a);

void *Ov010ActVt_0220fccc_Ctor(Obj021fa860 *self) {
    func_ov003_021d0c1c(self);
    *(void * *)self = data_ov010_0220fccc;
    self->unk_138.b0 = 0;
    Ov003Vt_021f7d10_Ctor((u8 *)self + 0x150);
    func_ov010_02201914((u8 *)self + 0x17c);
    Ov003Vt_021f79a8_Ctor((u8 *)self + 0x19c);
    func_ov003_021d8f24((u8 *)self + 0x1ac);
    Ov003Vt_021f7cf4_Ctor((u8 *)self + 0x1c0);
    func_ov003_021cf418((u8 *)self + 0x1d0);
    func_ov003_021cf340(data_ov010_0220fbd0);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(0, data_ov010_0220fbdd);
    func_ov003_021cf39c(1, data_ov010_0220fbec);
    func_ov003_021cf39c(2, data_ov010_0220fbf7);
    func_ov003_021cf39c(3, data_ov010_0220fc02);
    func_ov010_021fedd4(self);
    return self;
}

static inline void Ov010_021fa91c_Body(Obj021fa860 *self) {
    *(void * *)self = data_ov010_0220fccc;
    func_ov003_021cf3fc(0);
    SndMgr_StopSeqArc(data_02097e4c, self->unk_11c);
    func_ov010_021fee70(self);
    func_ov003_021cf428((u8 *)self + 0x1d0);
    Ov003Vt_021f7cf4_Dtor((u8 *)self + 0x1c0);
    func_ov003_021d8f34((u8 *)self + 0x1ac);
    Ov003Vt_021f79a8_Dtor((u8 *)self + 0x19c);
    func_ov010_02201944((u8 *)self + 0x17c);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x150);
    if (self->unk_138.b0) {
        func_02065804(data_0214a420, self->unk_148);
        self->unk_138.b0 = 0;
    }
    func_ov003_021d0edc(self);
}

void *Ov010ActVt_0220fccc_Dtor(Obj021fa860 *self) {
    Ov010_021fa91c_Body(self);
    return self;
}

void *Ov010ActVt_0220fccc_DtorDelete(Obj021fa860 *self) {
    Ov010_021fa91c_Body(self);
    Heap_Free(self);
    return self;
}

BOOL Ov010ActVt_0220fccc_IsReady(Obj021fa860 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (!self->unk_f0.b0) {
        self->unk_f0.b0 = 1;
        func_02049564(data_02097e4c, 1, 1);
        func_02049678(data_02097e4c, 4, 0xb, -1);
        r = FALSE;
    } else if (SndMgr_IsLoadDone(data_02097e4c) == 0) {
        r = FALSE;
    }
    return r;
}

extern void func_ov003_021cf4ec(void *p);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void func_ov003_021d883c(void *a, Ov010Vec *b, void *c, s32 d);
extern void MI_Copy36B(void *m, void *b);
extern u16 func_ov003_021d16cc(void *self);
extern void func_ov010_0220166c(void *p);

BOOL Ov010ActVt_0220fccc_Draw(Obj021fa860 *self) {
    BOOL r;
    u8 m1[0x24];
    u8 m2[0x24];
    Ov010Vec v;
    func_ov003_021cf4ec((u8 *)self + 0x1d0);
    MTX_RotZ33_(m1, OV010_SIN(self->rot_z), OV010_COS(self->rot_z));
    MTX_RotX33_(m2, OV010_SIN(self->rot_x), OV010_COS(self->rot_x));
    MTX_Concat33(m1, m2, m1);
    MTX_RotY33_(m2, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
    MTX_Concat33(m1, m2, m1);
    func_ov003_021d883c((u8 *)self + 0x150, &v, &self->pos, self->unk_f2);
    self->unk_93.b0 = 1;
    MI_Copy36B(m1, (u8 *)self->unk_38 + 0x84);
    FLD(Ov010Vec, self->unk_38, 0x78) = v;
    r = func_ov003_021d16cc(self);
    func_ov010_0220166c(self->unk_100);
    return r;
}

}
}  // namespace m_021fa860

// ---- merged from ov010_021fac1c.cpp
namespace m_021fac1c {
// Hit message handler (message 9 = damage)
struct Ov010Msg {
    u8 pad[5];
    u8 type;
    u16 a;
    u16 dmg;
};

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern const Ov010Vec data_ov010_0220ed10;
extern BOOL func_ov003_021d1c00(void *self, Ov010Msg *msg);
extern void func_ov003_021cedf4(s32 a);
extern void func_ov003_021d97fc(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern Ov010V *func_020657b0(void *a, s32 b);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);

typedef Ov010Vec (*Ov010PosFn)(void *a);

static inline Ov010Vec Ov010e_AttachPos(Obj021fa860 *self) {
    Ov010Vec r;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (self != NULL && (p = self->unk_44) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = self->rot_y;
        func_ov003_021d9900(&v, self->rot_x, &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&r, &v);
    VEC_Add(&r, &self->pos, &r);
    return r;
}

static inline BOOL Ov010e_Invul(Obj021fa860 *self) {
    BOOL r = TRUE;
    if (self->unk_ea.b13 && self->hp[5] == 0) {
        r = FALSE;
    }
    return r;
}

static inline BOOL Ov010e_Ignore(Obj021fa860 *self) {
    BOOL r = TRUE;
    if (!Ov010e_Invul(self) && self->unk_40->current != 0x20) {
        r = FALSE;
    }
    return r;
}

static inline void *Ov010e_FindActor(u16 id) {
    Actor *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return a;
}

static inline Ov010V *Ov010e_Eff(u8 *p) {
    Ov010V *e = NULL;
    if (p != NULL) {
        e = func_020657b0(data_0214a420, FLD(Ov010Flags8, p, 0).b0 ? FLD(s32, p, 0x10) : 0);
    }
    return e;
}

static inline void Ov010e_Spawn(Obj021fa860 *self) {
    if (self->unk_138.b0 && self->unk_140 == 0) {
        void *a = Ov010e_FindActor(self->unk_13a);
        if (a != NULL) {
            Ov010V *e;
            Ov010Vec w;
            Ov010Vec u = ((Ov010PosFn)self->unk_14c)(a);
            w.x = FLD(s32, a, 0x70);
            w.y = FLD(s32, a, 0x74);
            w.z = FLD(s32, a, 0x78);
            VEC_Add(&w, &u, &w);
            e = func_02065f88(self->unk_144, &w);
            FLD(u8, e, 0xd0) = 1;
            self->unk_148 = FLD(s32, e, 0x24);
            self->unk_139 = 0x1f;
            self->unk_140 = 1;
            self->unk_13c = 0;
        }
    }
}

BOOL func_ov010_021fac1c(Obj021fa860 *self, Ov010Msg *msg) {
    if (msg->type == 9) {
        if (!Ov010e_Ignore(self)) {
            u16 *c;
            self->hp[2] = msg->a;
            self->hp[5] = 5;
            c = self->unk_f8;
            c[0] = 0;
            c[1]++;
            func_ov003_021cedf4(8);
            c = self->unk_f8;
            if (c[1] >= 0x14) {
                c[0] = 0;
                c[1] = 0;
                func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
                c = self->unk_f8;
                c[0] = 0;
                c[1] = 0;
                if (self->unk_138.b0 && self->unk_140 == 1) {
                    self->unk_140 = 2;
                    self->unk_13c = 0;
                }
                func_ov000_02198360(((u8 *)self->unk_40), 0x14, 0);
            } else {
                if (c[1] == 0xf) {
                    Ov010e_Spawn(self);
                    Ov010e_Eff((u8 *)self + 0x138)->v0c(0x1800);
                    Ov010Vec p = Ov010e_AttachPos(self);
                    Ov010Vec off = data_ov010_0220ed10;
                    Ov010Vec rr;
                    func_ov003_021d9980(&rr, self->rot_y, &off);
                    VEC_Add(&p, &rr, &p);
                    func_02065f88(0x44c, &p)->v0c(0x2000);
                    self->unk_f2 = 0x800;
                    func_ov003_021d85c8((u8 *)self + 0x150, 10, 0, 0, 0);
                    {
                        u8 *g = data_ov000_021ccd54;
                        g[0x190] |= 0x1c;
                        g[0x18d] = 10;
                        g[0x18e] = 10;
                        g[0x18f] = 10;
                    }
                } else {
                    self->unk_f2 = 0x500;
                    func_ov003_021d85c8((u8 *)self + 0x150, 7, 0, 0, 0);
                }
                {
                    u16 *hp = self->hp;
                    u16 d = msg->dmg;
                    if (d >= hp[0]) {
                        hp[0] = 0;
                    } else {
                        hp[0] -= d;
                    }
                    if (hp[0] == 0) {
                        func_ov000_02198360(((u8 *)self->unk_40), 0x15, 0);
                    }
                }
                func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
                func_ov000_02191418(self->unk_38, 5, 0);
            }
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern Ov010Heap *data_02097dd0;
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 data_ov003_021f4340;
extern u16 data_ov003_021f435c;
extern char data_ov010_0220fc0f[];
extern u8 data_ov010_0220ee6c[];
extern u8 data_ov010_0220fcac[];
extern u8 data_ov010_0220fc8c[];
extern u8 data_ov010_0220fc6c[];
extern u8 data_ov010_0220fc50[];
extern u8 data_ov010_0220fc34[];
extern const Ov010Vec data_ov010_0220ed1c;
extern void func_ov003_021d112c(void *self);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern Ov010Vec func_ov010_021fa7e0(void *a);
extern BOOL func_ov003_021d8198(void *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 v);
extern BOOL func_ov010_022019ac(void *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern void func_ov003_021d95e8(void *p, void *tbl, u16 n);
extern void func_0203f2b8(void *p);
extern BOOL Ov003StateMachine_Init(void *p);
extern void func_ov003_021d8a30(void *p, u8 id, void *st);
extern void *func_ov010_02200d94(void *p);
extern BOOL func_ov010_02200dcc(void *p, u16 a, u16 b, u8 c, u16 d);
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern BOOL func_ov003_021d8c10(void *p);
extern BOOL Ov003Group_Init(void *p);
extern void *func_ov003_021cf52c(void *g, void *obj, u16 a, u16 b);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0218b700(void *u, s32 a, s32 b);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(void *self, const void *a);
extern s32 func_02049afc(void *mgr, s32 v);
extern void func_0204a058(void *mgr, u32 slot, s32 volume, s32 frames);

struct Ov010StBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
};

static inline void *Ov010e_NewVt(u32 size, void *vt) {
    void *o = Heap_Alloc(size);
    if (o != NULL) {
        FLD(void *, o, 0) = vt;
    }
    return o;
}

static inline void *Ov010e_NewC(void) {
    void *o = Heap_Alloc(0x18);
    if (o != NULL) {
        FLD(void *, o, 0) = data_ov010_0220fc6c;
        FLD(u8, o, 4) = 0;
        FLD(s32, o, 8) = 0;
        OV010_BLKCPY((u8 *)o + 0xc, &data_ov010_0220fa88);
    }
    return o;
}

static inline void *Ov010e_NewD(void) {
    void *o = Heap_Alloc(0xc);
    if (o != NULL) {
        FLD(void *, o, 0) = data_ov010_0220fc50;
        FLD(Ov010StBits, o, 4).b0 = 0;
        FLD(Ov010StBits, o, 4).b1 = 0;
        FLD(Ov010StBits, o, 4).b2 = 0;
        FLD(Ov010StBits, o, 4).b3 = 0;
        FLD(u16, o, 6) = 0;
        FLD(u16, o, 8) = 0;
    }
    return o;
}

static inline void *Ov010e_NewE(void) {
    void *o = Heap_Alloc(0x68);
    if (o != NULL) {
        FLD(void *, o, 0) = data_ov010_0220fc34;
        FLD(u8, o, 4) = 0;
        FLD(u16, o, 6) = 0;
        Ov010Vec t = data_ov010_0220ec20;
        FLD(Ov010Blk12, o, 8) = *(Ov010Blk12 *)&t;
        FLD(Ov010Blk12, o, 0x14) = *(Ov010Blk12 *)&t;
        FLD(Ov010Blk12, o, 0x20) = *(Ov010Blk12 *)&t;
        FLD(Ov010Blk12, o, 0x2c) = *(Ov010Blk12 *)&t;
        func_ov000_02198328((u8 *)o + 0x38);
        func_ov003_021da48c((u8 *)o + 0x38, 0);
    }
    return o;
}

static inline void Ov010e_StartE(u8 *o) {
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

void Ov010ActVt_0220fccc_Start(Obj021fa860 *self) {
    u32 saved;
    void *o;
    u16 k;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    self->unk_f0.b2 = 1;
    self->unk_138.b0 = 1;
    self->unk_138.b1 = 0;
    self->unk_144 = 0x322;
    self->unk_14c = (void *)func_ov010_021fa7e0;
    self->unk_139 = 0x1f;
    self->unk_13a = self->id;
    self->unk_13c = 0;
    self->unk_140 = 0;
    self->unk_148 = 0;
    func_ov003_021d8198((u8 *)self + 0x150);
    func_ov003_021cf330((u8 *)self + 0x19c, data_ov010_0220fc0f, data_ov003_021f4340);
    func_ov010_022019ac((u8 *)self + 0x17c);
    func_ov003_021d8f4c((u8 *)self + 0x1ac);
    func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220ee6c, 0x2a);
    {
        u8 *p = (u8 *)self->unk_44;
        FLD(s32, p, 0xc) = 0;
        FLD(s32, p, 0x10) = 0x61b2;
        FLD(s32, p, 0x14) = 0x24d5;
    }
    FLD(Ov010Flags, self->unk_38, 0xc2).b4 = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        void *q = self->unk_48;
        if (q != NULL) {
            func_0203f2b8(q);
            Heap_Free(q);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    {
        u16 *c = (u16 *)Heap_Alloc(4);
        self->unk_f8 = c;
        c[0] = 0;
        c[1] = 0;
    }
    self->unk_110 = Ov010e_NewVt(8, data_ov010_0220fcac);
    self->unk_114 = Ov010e_NewVt(8, data_ov010_0220fc8c);
    self->unk_118 = Ov010e_NewC();
    Ov003StateMachine_Init((u8 *)self + 0x1c0);
    func_ov003_021d8a30((u8 *)self + 0x1c0, 1, self->unk_110);
    func_ov003_021d8a30((u8 *)self + 0x1c0, 2, self->unk_114);
    func_ov003_021d8a30((u8 *)self + 0x1c0, 3, self->unk_118);
    o = Heap_Alloc(0x40);
    if (o != NULL) {
        o = func_ov010_02200d94(o);
    }
    self->unk_100 = o;
    func_ov010_02200dcc(self->unk_100, self->id, 0x78, 0x30, 2);
    self->unk_108 = (u8 *)(Ov010e_NewD());
    o = Ov010e_NewE();
    self->unk_104 = (Ov010Shake *)(o);
    Ov010e_StartE((u8 *)o);
    o = Heap_Alloc(0x20);
    if (o != NULL) {
        o = Ov003Vt_021f7cd8_Ctor(o);
    }
    self->unk_10c = o;
    func_ov003_021d8c10(o);
    Ov003Group_Init((u8 *)self + 0x1d0);
    k = data_ov003_021f435c;
    func_ov003_021cf52c((u8 *)self + 0x1d0, self->unk_104, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, self->unk_108, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, self->unk_10c, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x150, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x17c, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x19c, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x1c0, k, k);
    {
        u8 *u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
        if (u != NULL) {
            func_ov000_0218b700(u, 0x3000, 0);
        }
    }
    self->unk_c4 = 0;
    self->unk_93.b4 = 1;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220ec02);
    }
    switch (self->unk_18[0]) {
    case 0:
        self->unk_f0.b2 = 0;
        self->unk_11c = func_02049afc(data_02097e4c, 0x4e);
        func_0204a058(data_02097e4c, self->unk_11c, 0x78, 0);
        func_0204a058(data_02097e4c, self->unk_11c, 0x28, 0x258);
        break;
    case 1:
        func_ov000_02198360(((u8 *)self->unk_40), 0x2c, 0);
        func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
        self->unk_f0.b2 = 0;
        break;
    case 2: {
        Ov010Vec v = data_ov010_0220ed1c;
        self->pos.x = v.x;
        self->pos.y = v.y;
        self->pos.z = v.z;
        self->rot_x = 0;
        self->rot_y = 0xbfff;
        self->rot_z = 0;
        self->unk_f0.b2 = 1;
        break;
    }
    }
}

}
}  // namespace m_021fac1c

// ---- merged from ov010_021fb5a4.cpp
namespace m_021fb5a4 {
// The state-handler class: complete, so that the dispatcher reads its fields by name.
class Ov010Cls : public Obj021fa860 {
};
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};

struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

struct Ov010Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov010Ea {
    u16 lo : 3;
    u16 n : 3;
    u16 rest : 10;
};

struct Ov010B24 {
    u32 lo : 12;
    u32 n : 2;
    u32 rest : 18;
};

struct Ov010Bit0 {
    u8 b0 : 1;
    u8 rest : 7;
};

extern "C" {

extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(void *self, u8 a);

void func_ov010_021fb5a4(Obj021fa860 *self) {
    func_ov003_021da40c(((u8 *)self->unk_40));
    func_ov000_0218d7e8(self, self->unk_40->current);
}

extern const Ov010StEnt data_ov010_0220ed50[];
extern void func_ov003_021d3008(void *self);
extern int func_ov003_021cf408(void);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void func_ov003_021d9a00(Ov010Vec *out, s32 angle, const Ov010Vec *in);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void Ov003StateMachine_SendMessage(void *p, Ov010Cmd *c);
extern void func_ov003_021cf4ac(void *p);
extern void func_ov010_021ffa6c(void *p);
extern void func_ov010_02201064(void *p);

static inline Ov010Rot Ov010_MkRotZ(void *q) {
    Ov010Rot r = {0, 0, 0};
    r.z = FLD(u16, q, 8);
    return r;
}

static inline BOOL Ov010_PlFlag(void) {
    Robo021ca458 *pl = func_ov000_0219bf90();
    BOOL on = FALSE;
    if (pl != NULL) {
        on = pl->unk_b24_12 != 0;
    }
    return on;
}

static inline void Ov010_SetAlpha(Ov010Cls *self, u8 a) {
    FLD(u8, self->unk_38, 0xbe) = a;
    if (self->unk_138.b0 && self->unk_140 != 0) {
        self->unk_139 = a;
    }
    if (self->unk_d0 != NULL && FLD(Ov010Ea, self, 0xea).n) {
        s32 i;
        for (i = 0; i < 2; i++) {
            void *p = ((void **)self->unk_d0)[0x68 / 4 + i];
            if (p != NULL) {
                FLD(u8, p, 0xbe) = a;
            }
        }
    }
}

void func_ov010_021fb5c8(Ov010Cls *self) {
    u32 i;
    u8 key;
    void *q;
    key = self->unk_40->current;
    for (i = 0; i < 11; i++) {
        if (key == data_ov010_0220ed50[i].key && *(s32 *)&data_ov010_0220ed50[i].fn != 0) {
            (self->*data_ov010_0220ed50[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        self->unk_15 = func_ov003_021cf408();
    }
    {
        Ov010Vec t;
        Ov010Vec o;
        func_ov003_021d9a00(&t, self->rot_z, &data_ov010_0220ec50);
        FLD(Ov010Vec, self->unk_44, 0xc) = t;
        OV010_BLKCPY(&o, ((u8 *)self->unk_104) + 0x20);
        VEC_Add(&self->pos, &o, &self->pos);
    }
    q = ((void *)self->unk_108);
    if (!FLD(Ov010Flags8, q, 4).b1) {
        Ov010Rot a = Ov010_MkRotZ(q);
        self->rot_x = a.x;
        Ov010Rot b = Ov010_MkRotZ(q);
        self->rot_z = b.z;
    }
    if (self->pos.x > 0x1c000) {
        s32 v = 0x1f - ((self->pos.x - 0x1c000) >> 12);
        if (v > 0x1f) {
            v = 0x1f;
        } else if (v < 0) {
            v = 0;
        }
        u8 a = v;
        Ov010_SetAlpha(self, a);
    } else {
        Ov010_SetAlpha(self, 0x1f);
    }
    {
        u16 *c = self->hp;
        if ((c[0] << 12) / c[1] <= 0x333) {
            u16 *f = self->unk_f8;
            f[0] = 0;
            f[1] = 0;
        } else {
            u16 *f = self->unk_f8;
            if (f[1] >= 0xf) {
                if (f[0] > 0x96) {
                    f[0] = 0;
                    f[1] = 0;
                    if (self->unk_138.b0 && self->unk_140 == 1) {
                        self->unk_140 = 2;
                        self->unk_13c = 0;
                    }
                }
            } else {
                if (f[0] > 0x5a) {
                    f[0] = 0;
                    f[1] = 0;
                    if (self->unk_138.b0 && self->unk_140 == 1) {
                        self->unk_140 = 2;
                        self->unk_13c = 0;
                    }
                }
            }
        }
    }
    if (Ov010_PlFlag()) {
        Ov010Cmd cmd;
        func_ov003_021d88ec(&cmd);
        cmd.a = 1;
        cmd.b = 0;
        Ov003StateMachine_SendMessage((u8 *)self + 0x1c0, &cmd);
    } else {
        Ov010Cmd cmd;
        func_ov003_021d88ec(&cmd);
        cmd.a = 1;
        cmd.b = 1;
        Ov003StateMachine_SendMessage((u8 *)self + 0x1c0, &cmd);
    }
    func_ov003_021cf4ac((u8 *)self + 0x1d0);
    func_ov010_021ffa6c(&self->unk_138);
    func_ov010_02201064(self->unk_100);
    self->unk_f8[0]++;
}

}
}  // namespace m_021fb5a4

// ---- merged from ov010_021fb95c.cpp
namespace m_021fb95c {
extern "C" {

extern u8 data_ov010_0220edd4[];
extern BOOL func_ov003_021da03c(void *self);
extern BOOL func_ov003_021d98a0(void *p);
extern BOOL func_ov003_021d984c(void *p, void *a);
extern void func_ov003_021d8fc0(void *p);
extern void func_ov003_021d95e8(void *p, void *a, s32 b);
extern void func_ov003_021d97fc(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d9878(void *p);
struct Ov010B2 {
    u8 a;
    u8 b;
};
extern Ov010B2 func_ov003_021d9644(void *p);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);

void Ov010ActVt_0220fccc_Update(Obj021fa860 *self) {
    BOOL a;
    BOOL b;
    if (!func_ov003_021da03c(self)) {
        return;
    }
    a = func_ov003_021d98a0((u8 *)self + 0x1ac) ? FALSE : TRUE;
    b = func_ov003_021d984c((u8 *)self + 0x1ac, data_ov010_0220edd4) ? FALSE : TRUE;
    func_ov003_021d8fc0((u8 *)self + 0x1ac);
    if (a && b) {
        u16 *hp = self->hp;
        if (((hp[0] << 12) / hp[1]) <= 0x333) {
            func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220edd4, 0x19);
            func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
            func_ov000_02198360(((u8 *)self->unk_40), 0x14, 1);
            return;
        }
    }
    if (func_ov003_021d9878((u8 *)self + 0x1ac)) {
        Ov010B2 r = func_ov003_021d9644((u8 *)self + 0x1ac);
        FLD(Ov010B2, self, 0x1bc) = r;
        func_ov000_02198360(((u8 *)self->unk_40), r.a, 1);
    }
}

void func_ov010_021fba6c(void) {
}

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

void func_ov010_021fba70(Obj021fa860 *self) {
    if (self->unk_40->st != 0) {
        return;
    }
    Ov010Cam_Start((u8 *)self->unk_104);
    func_ov000_02190cb0(self->unk_38, data_ov010_0220ebe0, 0xcd, 0);
    func_ov000_021915a0(self->unk_38);
    self->unk_40->st++;
}

}
}  // namespace m_021fb95c

// ---- merged from ov010_021fbb40.cpp
namespace m_021fbb40 {
struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

struct Ov010Obj108 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_05;
    u16 unk_06;
};

struct Ov010MoveParam {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s16 speed;
    s16 accel;
    s16 max;
    s16 near;
    s16 decel;
    s16 min;
    void *anim;
    u16 rot[3];
    u8 unk_1a[2];
    Ov010Vec pos;
    Ov010Vec target;
};

struct Ov010MoveEntry {
    u8 key;
    Ov010MoveParam *param;
};

extern "C" {
extern Ov010MoveEntry data_ov010_0220ed28[];
extern void *data_02097e4c;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void Ov003StateMachine_SendMessage(void *p, Ov010Cmd *c);
extern void func_ov003_021d969c(void *p, s32 a);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(void *out, Ov010Vec *dir, void *in, s32 speed, s32 e);
extern BOOL Ov003Vec_Equal(Ov010Vec *a, void *b);
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

static inline void Ov010_Cmd(void *dst, s32 a, s32 b) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = a;
    cmd.b = b;
    Ov003StateMachine_SendMessage(dst, &cmd);
}

static inline s32 Ov010_Clamp(s32 v, s32 max) {
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

void func_ov010_021fbb40(void *self) {
    Ov010MoveParam *p = NULL;
    u32 i;
    for (i = 0; i < 5; i++) {
        if (FLD(u8, self, 0x1bd) == data_ov010_0220ed28[i].key) {
            p = data_ov010_0220ed28[i].param;
        }
    }
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u8 *cam;
        func_ov000_02190cb0(FLD(void *, self, 0x38), p->anim, 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x9c) = p->speed;
        if (p->b0) {
            FLD(s32, self, 0x70) = p->pos.x;
            FLD(s32, self, 0x74) = p->pos.y;
            FLD(s32, self, 0x78) = p->pos.z;
        }
        if (p->b1) {
            FLD(u16, self, 0x7c) = p->rot[0];
            FLD(u16, self, 0x7e) = p->rot[1];
            FLD(u16, self, 0x80) = p->rot[2];
        }
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
        cam = FLD(u8 *, self, 0x104);
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0xf00;
        Ov010_Cmd((u8 *)self + 0x1c0, 4, p->unk_02);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        if (FLD(Ov010Flags8, self, 0xf0).b1) {
            FLD(Ov010Flags8, self, 0xf0).b1 = 0;
            func_02049a48(data_02097e4c, 0xb00, -1, -1, -1);
        }
        break;
    }
    case 10: {
        s32 v;
        if (VEC_Distance(&p->target, (Ov010Vec *)((u8 *)self + 0x70)) <= p->near) {
            v = Ov010_FxMul(FLD(s32, self, 0x9c), p->decel);
        } else {
            FLD(s32, self, 0x9c) += p->accel;
            v = Ov010_Clamp(FLD(s32, self, 0x9c), p->max);
        }
        FLD(s32, self, 0x9c) = v;
        func_ov003_021d9dbc((u8 *)self + 0x70, &p->target, (u8 *)self + 0x70, FLD(s32, self, 0x9c), 0);
        if (Ov003Vec_Equal(&p->target, (u8 *)self + 0x70) || FLD(s32, self, 0x9c) < p->min) {
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
}
}  // namespace m_021fbb40

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
extern void Ov003StateMachine_SendMessage(void *p, Ov010Cmd *c);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern u16 Ov003Vec_Pitch(Ov010Vec *a);
extern BOOL Ov003Vec_Equal(void *a, const Ov010Vec *b);
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
    Ov010Path *o = (Ov010Path *)Heap_Alloc(0x20);
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
    Ov003StateMachine_SendMessage(dst, &cmd);
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
void func_ov010_021fbda0(Obj021fa860 *self) {
    Ov010Vec d10;
    Ov010Vec q;
    Ov010Vec d11;
    Ov010Vec r;
    Ov010Vec dv;
    switch (self->unk_40->st) {
    case 0: {
        Ov010Path *o;
        if ((void *)self->unk_fc != NULL) {
            Heap_Free(self->unk_fc);
        }
        o = Ov010e_MkPath(self->unk_1bd);
        self->unk_fc = o;
        if (o == NULL) {
            self->unk_40->st = 100;
            return;
        }
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0xf00;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 4, 1);
        self->unk_40->st = 10;
        break;
    }
    case 10: {
        Ov010Path *p;
        Ov010V *e;
        u16 a;
        func_ov000_02190cb0(self->unk_38, self->unk_fc->anim0, data_ov010_0220fa24, 0);
        p = self->unk_fc;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        d10.x = p->a.x - self->pos.x;
        d10.y = p->a.y - self->pos.y;
        d10.z = p->a.z - self->pos.z;
        VEC_Normalize(&d10, &d10);
        q.x = self->pos.x;
        q.y = self->pos.y + 0x6000;
        q.z = self->pos.z;
        e = func_02065f88(0x192, &q);
        a = Ov003Vec_Pitch(&d10);
        e->v34(a, Ov003Vec_Yaw(&d10), 0);
        e->v0c(0x3000);
        self->unk_40->st = 11;
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        break;
    }
    case 11: {
        Ov010Path *p = self->unk_fc;
        d11.x = p->a.x - self->pos.x;
        d11.y = p->a.y - self->pos.y;
        d11.z = p->a.z - self->pos.z;
        self->unk_9c = Ov010e_Clamp(self->unk_9c + 0x60, 0x1000);
        if (VEC_Mag(&d11) < 0x3000) {
            self->unk_9c = Ov010_FxMul(self->unk_9c, 0xf40);
            func_ov000_02190cb0(self->unk_38, self->unk_fc->anim1, data_ov010_0220fa24, 0);
        }
        func_ov003_021d9dbc(&self->pos, &self->unk_fc->a, &self->pos, self->unk_9c, 0);
        if (Ov003Vec_Equal(&self->pos, &self->unk_fc->a) || self->unk_9c < 0x10) {
            self->unk_40->st = 0x14;
        }
        break;
    }
    case 0x14: {
        Robo021ca458 *pl = func_ov000_0219bf90();
        u32 i;
        u16 id;
        if (pl == NULL) {
            self->unk_40->st = 100;
            return;
        }
        func_ov010_02201b48((u8 *)self + 0x17c);
        Ov010Fns2 fns = *(const Ov010Fns2 *)data_ov010_0220ec0c;
        id = pl->id;
        for (i = 0; i < 2; i++) {
            void *t = func_ov010_02201ad4((u8 *)self + 0x17c, (void *)func_ov010_02201c9c, i * 15);
            *(Ov010Blk12 *)&r = ((Ov010OfsFn)fns.f[i])(self->unk_fc->anim1);
            func_ov010_02201eac(t, id, self->id, &self->unk_fc->b, &r);
        }
        func_ov010_02201bf4((u8 *)self + 0x17c);
        Ov010e_StartE(self->unk_104);
        self->unk_40->st = 0x15;
        break;
    }
    case 0x15:
        if (func_ov010_02201c5c((u8 *)self + 0x17c)) {
            Ov010Shake *c;
            dv.x = Ov010_FxMul(data_ov010_0220fa64.x, 0x1000);
            dv.y = Ov010_FxMul(data_ov010_0220fa64.y, 0x1000);
            dv.z = Ov010_FxMul(data_ov010_0220fa64.z, 0x1000);
            c = self->unk_104;
            if (c->active) {
                VEC_Add(&c->vel, &dv, &c->vel);
                VEC_Add(&c->pos, &dv, &c->pos);
            }
            func_ov003_021d68e0(self, 0x63fc, 0x5ad4, 10);
            if (self->unk_f0.b1) {
                self->unk_f0.b1 = 0;
                func_02049a48(data_02097e4c, 0xb01, -1, -1, -1);
            }
        }
        if (func_ov010_02201c34((u8 *)self + 0x17c)) {
            func_ov010_02201b48((u8 *)self + 0x17c);
            self->unk_40->st = 0x1e;
        }
        break;
    case 0x1e:
        self->unk_40->timer++;
        if (data_ov010_0220fa28 == self->unk_40->timer) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220ebe0, data_ov010_0220fa20, 0);
        }
        if (self->unk_40->timer > 0x78) {
            self->unk_40->timer = 0;
            self->unk_40->st = 100;
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
extern void Actor_TurnToPos(void *self, void *t, s32 a);

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

void func_ov010_021fc4ac(Obj021fa860 *self) {
    Ov010Vec up = data_ov010_0220ec14;
    const char *anim = data_ov010_0220ebd0;
    const Ov010Vec *tgt = &data_ov010_0220ecd4;
    const Ov010Vec *grav = &data_ov010_0220ec2c;
    switch (self->unk_40->st) {
    case 0: {
        Ov010Vec rot;
        Ov010Vec ofs;
        Robo021ca458 *pl;
        s32 i = 0;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220ebcc, 0x1000, i);
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = i;
            cam->decay = i;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 4, 1);
        self->unk_9c = i;
        self->unk_a0 = i;
        self->unk_a4 = i;
        self->unk_a8 = i;
        self->unk_120.x = data_ov010_0220ec20.x;
        self->unk_120.y = data_ov010_0220ec20.y;
        self->unk_120.z = data_ov010_0220ec20.z;
        self->pos.x = 0x9600;
        self->pos.y = 0x17d9e;
        self->pos.z = i;
        func_ov010_02201b48((u8 *)self + 0x17c);
        pl = func_ov000_0219bf90();
        if (pl == NULL) {
            func_ov000_02198360(((u8 *)self->unk_40), 100, i);
            break;
        }
        for (; i < 3; i++) {
            void *t;
            func_ov003_021d9900(&rot, i * 0xb00 + 0xf800, (Ov010Vec *)&data_ov010_0220ec38);
            ofs.x = -0x1333;
            ofs.y = 0x8000;
            ofs.z = 0x2666;
            t = func_ov010_02201ad4((u8 *)self + 0x17c, (void *)func_ov010_02201f18, i * 15 + 0x50);
            func_ov010_02202074(t, pl->id, self->id, &rot, &ofs);
        }
        self->unk_40->st = 10;
        break;
    }
    case 10: {
        Ov010Vec d;
        Ov010Vec n;
        self->unk_120.x = data_ov010_0220ec20.x;
        self->unk_120.y = data_ov010_0220ec20.y;
        self->unk_120.z = data_ov010_0220ec20.z;
        d.x = tgt->x - self->pos.x;
        d.y = tgt->y - self->pos.y;
        d.z = tgt->z - self->pos.z;
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0xa00, &n, &self->unk_120, &self->unk_120);
        if (VEC_Mag(&d) <= 0xa00) {
            self->unk_40->st = 0x1e;
        }
        break;
    }
    case 0x1e: {
        u8 *g;
        func_ov010_02203ee0(0x12e, &self->pos)->v0c(0x3000);
        g = (u8 *)data_ov000_021ccd54;
        g[0x190] |= 0x1c;
        g[0x18d] = 10;
        g[0x18e] = 0x1e;
        g[0x18f] = 0x1e;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220ebe0, 0x80, 0);
        self->unk_40->st = 0x1f;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        break;
    }
    case 0x1f:
        VEC_MultAdd(0x18, &data_ov010_0220ed04, &self->unk_120, &self->unk_120);
        VEC_MultAdd(0x50, grav, &self->unk_120, &self->unk_120);
        func_ov003_021d9b8c(&self->unk_120, &self->unk_120, 0x400, 0x80);
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x28) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x28;
        }
        break;
    case 0x28:
        self->unk_120.x = Ov010_FxMul(self->unk_120.x, 0xf50);
        self->unk_120.y = Ov010_FxMul(self->unk_120.y, 0xf50);
        self->unk_120.z = Ov010_FxMul(self->unk_120.z, 0xf50);
        VEC_MultAdd(4, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        func_ov003_021d9b8c(&self->unk_120, &self->unk_120, 0x400, 0x20);
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x1e) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x32;
        }
        break;
    case 0x32:
        func_ov000_02190cb0(self->unk_38, anim, 0x90, 0);
        func_ov010_02201bf4((u8 *)self + 0x17c);
        self->unk_40->st = 0x33;
        func_02049a48(data_02097e4c, 0xb03, -1, -1, -1);
        break;
    case 0x33:
        VEC_MultAdd(0xc, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        VEC_MultAdd(9, &up, &self->unk_120, &self->unk_120);
        VEC_MultAdd(4, &data_ov010_0220ec38, &self->unk_120, &self->unk_120);
        func_ov003_021d9aec(&self->unk_120, &self->unk_120, 0x2000);
        self->unk_40->timer++;
        if ((s32)self->unk_40->timer > 0xf0 && func_ov010_02201c34((u8 *)self + 0x17c)) {
            FLD(Ov010Bits16, self->unk_38, 0xc2).b0 = 0;
            self->unk_40->timer = 0;
            self->unk_40->st = 100;
        }
        break;
    case 100:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220ebe0, 0x1000, 0);
        func_ov010_02201b48((u8 *)self + 0x17c);
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    VEC_Add(&self->pos, &self->unk_120, &self->pos);
    {
        u8 *c = self->unk_108;
        FLD(Ov010StBits, c, 4).b2 = 1;
        FLD(u16, c, 6) = 0;
    }
}

static inline void *Ov010e_FindActor(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
}
static inline void Ov010e_Pull(Obj021fa860 *self, s32 rate) {
    void *a = Ov010e_FindActor(self->target);
    if (a != NULL) {
        Ov010Vec d;
        s32 x = FLD(s32, a, 0x70);
        s32 y = FLD(s32, a, 0x74);
        s32 z = FLD(s32, a, 0x78);
        d.x = x - self->unk_12c.x;
        d.y = y - self->unk_12c.y;
        d.z = z - self->unk_12c.z;
        VEC_MultAdd(rate, &d, &self->unk_12c, &self->unk_12c);
    }
}

void func_ov010_021fca40(Obj021fa860 *self) {
    BOOL follow = TRUE;
    s32 rate = 0;
    switch (self->unk_40->st) {
    case 0: {
        Robo021ca458 *pl;
        rate = 0x100;
        pl = func_ov000_0219bf90();
        if (pl == NULL) {
            self->unk_40->st = 100;
        } else {
            self->unk_12c.x = pl->pos.x;
            self->unk_12c.y = pl->pos.y;
            self->unk_12c.z = pl->pos.z;
            self->target = pl->id;
            self->unk_40->st = 10;
        }
        func_ov000_02190cb0(self->unk_38, data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(self->unk_38);
        break;
    }
    case 10:
    case 11:
        self->unk_40->timer++;
        rate = 0x100;
        if (func_ov000_02191120(self->unk_38)) {
            if (self->unk_40->timer > 0x3c) {
                self->unk_40->timer = 0;
                self->unk_40->st = 0x28;
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
        self->unk_40->st = 0x29;
        func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        func_02049a48(data_02097e4c, 0xb02, -1, -1, -1);
        break;
    }
    case 0x29:
        self->unk_40->timer++;
        rate = 0x100;
        if (self->unk_40->timer > 0x46) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x32;
        }
        break;
    case 0x32: {
        Ov010Vec v;
        rate = 0x100;
        func_ov003_021d9980(&v, self->rot_y, (Ov010Vec *)&data_ov010_0220ec5c);
        VEC_Add(&v, &self->pos, &v);
        func_ov010_022016a0(self->unk_100, &self->unk_12c, &v, 0x2bc);
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0xf00;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, 0x3000);
        self->unk_40->st = 0x33;
        break;
    }
    case 0x33: {
        Ov010Vec v;
        follow = FALSE;
        rate = 0x100;
        func_ov003_021d9980(&v, self->rot_y, (Ov010Vec *)&data_ov010_0220ec5c);
        VEC_Add(&v, &self->pos, &v);
        func_ov010_02201830(self->unk_100, &v);
        func_ov010_02201898(self->unk_100, &self->unk_12c);
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x3c) {
            void *a = Ov010e_FindActor(self->target);
            if (a != NULL) {
                Ov010Vec p;
                p.x = FLD(s32, a, 0x70);
                p.y = FLD(s32, a, 0x74);
                p.z = FLD(s32, a, 0x78);
                if (VEC_Distance(&p, &self->unk_84) > 0x10000) {
                    func_ov010_02201700(self->unk_100);
                }
            }
        }
        if (func_ov010_0220180c(self->unk_100)) {
            self->unk_40->st = 0x3c;
        }
        break;
    }
    case 0x3c:
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, 0);
        self->unk_40->st = 0x3d;
        break;
    case 0x3d:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x1e) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x46;
        }
        break;
    case 0x46:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220ebe0, 0xcd, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->st = 0x47;
        break;
    case 0x47:
        if (func_ov000_02191120(self->unk_38)) {
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
            self->unk_40->st = 100;
        }
        break;
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    Ov010e_Pull(self, rate);
    if (follow) {
        self->unk_84.x = self->unk_12c.x;
        self->unk_84.y = self->unk_12c.y;
        self->unk_84.z = self->unk_12c.z;
    }
    Actor_TurnToPos(self, &self->unk_84, 0x180);
    {
        u8 *c = self->unk_108;
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
extern s32 Rand_PlusMinus(s32 n);
extern s32 Rand_UpTo(s32 max);
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

static inline u16 Ov010e_AngTo(Obj021fa860 *self, u8 *a) {
    if (a == NULL || a == (void *)self) {
        return self->rot_y;
    }
    return FX_Atan2(FLD(s32, a, 0x70) - self->pos.x, FLD(s32, a, 0x78) - self->pos.z);
}

static inline void Ov010e_Spawn(Obj021fa860 *self) {
    if (self->unk_138.b0 && self->unk_140 == 0) {
        void *a = Ov010e_FindActor(self->unk_13a);
        if (a != NULL) {
            Ov010V *e;
            Ov010Vec w;
            Ov010Vec u;
            *(Ov010Blk12 *)&u = ((Ov010PosFn)self->unk_14c)(a);
            w.x = FLD(s32, a, 0x70);
            w.y = FLD(s32, a, 0x74);
            w.z = FLD(s32, a, 0x78);
            VEC_Add(&w, &u, &w);
            e = func_02065f88(self->unk_144, &w);
            FLD(u8, e, 0xd0) = 1;
            self->unk_148 = FLD(s32, e, 0x24);
            self->unk_139 = 0x1f;
            self->unk_13c = 0;
            self->unk_140 = 1;
        }
    }
}

void func_ov010_021fcf70(Obj021fa860 *self) {
    u16 st;
    s32 i;
    self->unk_f0.b1 = 0;
    st = self->unk_40->st;
    switch (st) {
    case 0:
    case 1:
        if (st == 0) {
            if ((void *)self->hp != NULL && func_ov000_02199f60(self->hp) != NULL) {
                self->unk_98 = Ov010e_AngTo(self, (u8 *)func_ov000_02199f60(self->hp));
            } else {
                self->unk_98 = self->rot_y;
            }
            self->unk_98 += (u16)(Rand_PlusMinus(0x2000) + 0x7fff);
            self->unk_120.x = data_ov010_0220ec20.x;
            self->unk_120.y = data_ov010_0220ec20.y;
            self->unk_120.z = data_ov010_0220ec20.z;
            func_ov000_02191418(self->unk_38, 3, 0);
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
            func_ov010_0220172c(self->unk_100);
            func_ov010_02201b48((u8 *)self + 0x17c);
            self->unk_40->st = 1;
        }
        func_ov003_021d6868(self, 0x739f);
        if (self->unk_138.b0) {
            self->unk_138.b1 = 1;
        }
        if (self->unk_40->timer > 3) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x14;
        } else {
            self->unk_40->timer = FLD(const u16, ((u8 *)self->unk_40), 2) + 1;
        }
        break;
    case 0x14:
    case 0x15:
        if (st == 0x14) {
            u16 rx = (Rand_UpTo(0x2000) - 0x2000) >> 1;
            u16 ry = (Rand_UpTo(0x2000) - 0x2000) >> 1;
            u16 rz = (Rand_UpTo(0x2000) - 0x2000) >> 1;
            self->rot_x += rx;
            self->rot_y += ry;
            self->rot_z += rz;
            {
                u16 *hp = self->hp;
                u16 d = Ov010_FxMul(hp[1] << 12, 0x19a) >> 12;
                if (d >= hp[0]) {
                    hp[0] = 0;
                } else {
                    hp[0] -= d;
                }
            }
            self->unk_f2 = 0x1000;
            func_ov003_021d85c8((u8 *)self + 0x150, 0x14, 0, 0, 0);
            {
                u8 *g = (u8 *)data_ov000_021ccd54;
                g[0x190] |= 0x1c;
                g[0x18d] = 0xf;
                g[0x18e] = 0xf;
                g[0x18f] = 0xf;
            }
            func_ov003_021d68e0(self, 0x5adf, 0x739f, 10);
            func_ov003_021d9980(&self->unk_120, self->unk_98, (Ov010Vec *)&data_ov010_0220ec38);
            self->unk_120.x = Ov010_FxMul(self->unk_120.x, 0x800);
            self->unk_120.y = Ov010_FxMul(self->unk_120.y, 0x800);
            self->unk_120.z = Ov010_FxMul(self->unk_120.z, 0x800);
            if (self->unk_138.b0 && self->unk_140 == 1) {
                self->unk_140 = 2;
                self->unk_13c = 0;
            }
            func_ov000_02190cb0(self->unk_38, data_ov010_0220fc19, 0x800, 1);
            self->unk_b4 = 0;
            self->unk_b6 = 0;
            self->unk_40->st = 0x15;
            func_02049a48(data_02097e4c, 0xb04, -1, -1, -1);
            func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        }
        for (i = 0; i < 3; i++) {
            s32 k = i * 5;
            if (k == self->unk_40->timer) {
                func_ov003_021da108(self, 0x6000, 0x6b, 0x1000, 0x3000);
            }
        }
        self->unk_120.x = Ov010_FxMul(self->unk_120.x, 0xec0);
        self->unk_120.y = Ov010_FxMul(self->unk_120.y, 0xec0);
        self->unk_120.z = Ov010_FxMul(self->unk_120.z, 0xec0);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x19) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220fc1f, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->timer = 0;
            self->unk_40->st = 0x32;
        }
        break;
    case 0x32:
        VEC_MultAdd(0x20, &data_ov010_0220ec44, &self->unk_120, &self->unk_120);
        VEC_MultAdd(0x30, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        if (self->pos.y <= -0x16000) {
            u16 *hp = self->hp;
            if ((hp[0] << 12) / hp[1] <= 0x333) {
                Ov010e_Spawn(self);
                if (!func_ov003_021d984c((u8 *)self + 0x1ac, data_ov010_0220edd4)) {
                    func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220edd4, 0x19);
                    func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
                }
            }
            self->unk_40->st = 100;
        }
        self->rot_x = func_01ffc128(0, self->rot_x, 0x148, 1, 0x8000);
        self->rot_y = func_01ffc128(0xbfff, self->rot_y, 0x148, 1, 0x8000);
        self->rot_z = func_01ffc128(0, self->rot_z, 0x148, 1, 0x8000);
        break;
    case 100:
        func_ov000_02198360(((u8 *)self->unk_40), 0x2b, 0);
        break;
    }
    FLD(Ov010Flags8b, self->unk_108, 4).b1 = 1;
    {
        Ov010Shake *cam = self->unk_104;
        cam->active = 0;
        cam->decay = 0;
    }
    self->hp[5] = 5;
}

extern BOOL func_ov003_021d8b34(void *p, s32 a);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_0203cb78(s32 a, s32 b, s32 c);
extern void *func_ov000_0219b71c(Ov010Vec *pos, Ov010Vec *s, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02065804(void *a, s32 b);
extern void SndMgr_StopSeqArc(void *a, s32 b);
extern void func_ov003_021d6a3c(void *self, s32 a, s32 b, s32 c);
extern Ov010V *func_ov003_021da7e8(s32 id, void *src, const Ov010Vec *ofs);
extern char data_ov010_0220fc25[];
extern void *data_0214a420;

static inline s32 Ov010f_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline Ov010Vec Ov010f_AttachPos(Obj021fa860 *self) {
    Ov010Vec r;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (self != NULL && (p = self->unk_44) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = self->rot_y;
        func_ov003_021d9900(&v, self->rot_x, &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&r, &v);
    VEC_Add(&r, &self->pos, &r);
    return r;
}

void func_ov010_021fd694(Obj021fa860 *self) {
    switch (self->unk_40->st) {
    case 0:
        if (func_ov003_021d8b34((u8 *)self + 0x1c0, 1)) {
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
        } else {
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
        }
        if (self->unk_138.b0 && self->unk_140 == 1) {
            self->unk_140 = 2;
            self->unk_13c = 0;
        }
        func_ov010_0220172c(self->unk_100);
        func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
        FLD(u16, self->hp, 0) = 0;
        {
            u8 *s44 = (u8 *)self->unk_44;
            FLD(Ov010Flags, s44, 0x22).b0 = 0;
            FLD(Ov010Flags, s44, 0x22).b1 = 0;
        }
        FLD(u16, self->unk_4c, 0x1c) = 0xffff;
        self->unk_120.x = data_ov010_0220ec20.x;
        self->unk_120.y = data_ov010_0220ec20.y;
        self->unk_120.z = data_ov010_0220ec20.z;
        {
            u8 *c = self->unk_108;
            FLD(Ov010Flags8b, c, 4).b2 = 1;
            FLD(u16, c, 6) = 0;
        }
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0xf00;
        }
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4829, 0x15);
        self->unk_40->st = 10;
        break;
    case 10:
        func_ov000_02191418(self->unk_38, 5, 1);
        func_ov000_02190cb0(self->unk_38, data_ov010_0220fc19, 0x266, 1);
        func_ov000_021915a0(self->unk_38);
        func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
        self->unk_40->st = 11;
    case 11:
        if (self->unk_40->timer < 5) {
            self->unk_40->timer = FLD(const u16, ((u8 *)self->unk_40), 2) + 1;
            break;
        }
        func_0203cb78(0x1e000, 1, 0);
        self->unk_40->timer = 0;
        self->unk_40->st = 0x14;
        break;
    case 0x14:
        if (self->unk_40->timer % 20 == 0) {
            Ov010Vec pos = Ov010f_AttachPos(self);
            Ov010Vec sc;
            sc.x = self->unk_64;
            sc.y = self->unk_68;
            sc.z = self->unk_64;
            func_ov000_0219b71c(&pos, &sc, 0x733, 0xccd, 3, 0x32);
            func_ov000_0218996c(0x14, 8);
            func_02049f44(data_02097e4c, 0x35, &pos, 0);
        }
        if (self->unk_f4 == 0) {
            Ov010Vec o = {0, 0, 0};
            o.y = 0x61b2;
            self->unk_f4 = FLD(s32, func_ov003_021da7e8(0x390, self, &o), 0x24);
        }
        VEC_MultAdd(0x10, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        VEC_MultAdd(10, &data_ov010_0220ec44, &self->unk_120, &self->unk_120);
        func_ov003_021d9aec(&self->unk_120, &self->unk_120, 0x180);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        self->rot_y = func_01ffc128(Ov003Vec_Yaw(&data_ov010_0220ed04), self->rot_y, 0x80, 1, 0x8000);
        if (self->unk_40->timer > 0x28) {
            self->unk_93.b4 = 0;
        }
        if (self->unk_40->timer % 25 == 0) {
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        if (self->unk_40->timer >= 0x78) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x1e;
        } else {
            self->unk_40->timer = FLD(const u16, ((u8 *)self->unk_40), 2) + 1;
        }
        break;
    case 0x1e: {
        Ov010V *e;
        func_02065804(data_0214a420, self->unk_f4);
        self->unk_f4 = 0;
        Ov010Vec pos2 = Ov010f_AttachPos(self);
        func_02065f88(4, &pos2)->v0c(0x3000);
        e = func_02065f88(0x131, &pos2);
        e->v0c(0x2800);
        e->v34(0, Ov003Vec_Yaw(&data_ov010_0220fa64), 0);
        func_02065f88(0x68, &pos2)->v0c(0x4800);
        func_02049a48(data_02097e4c, 0xb05, -1, -1, -1);
        func_02049f44(data_02097e4c, 0x19, &pos2, 0);
        VEC_MultAdd(0x800, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        func_ov000_02190cb0(self->unk_38, data_ov010_0220fc25, 0x800, 1);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->st = 0x1f;
    }
    case 0x1f:
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        func_ov003_021d9b8c(&self->unk_120, &self->unk_120, 0x200, 0x30);
        self->unk_40->timer++;
        if (self->unk_40->timer >= 0x3c) {
            self->unk_120.x = Ov010f_FxMul64(self->unk_120.x, 0x600);
            self->unk_120.y = Ov010f_FxMul64(self->unk_120.y, 0x600);
            self->unk_120.z = Ov010f_FxMul64(self->unk_120.z, 0x600);
            self->unk_40->timer = 0;
            self->unk_40->st = 0x28;
        }
        break;
    case 0x28: {
        Ov010Vec d;
        Ov010Vec n;
        d.x = 0xcf1b - self->pos.x;
        d.y = 0x1796 - self->pos.y;
        d.z = -0xa46f - self->pos.z;
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0x20, &n, &self->unk_120, &self->unk_120);
        func_ov003_021d9aec(&self->unk_120, &self->unk_120, 0x800);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        if (VEC_Mag(&d) <= 0x2800) {
            self->unk_40->st = 0x32;
        }
        break;
    }
    case 0x32:
        self->unk_120.x = Ov010f_FxMul64(self->unk_120.x, 0xf00);
        self->unk_120.y = Ov010f_FxMul64(self->unk_120.y, 0xf00);
        self->unk_120.z = Ov010f_FxMul64(self->unk_120.z, 0xf00);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        if (VEC_Mag(&self->unk_120) <= 0x100) {
            self->unk_120.x = data_ov010_0220ec20.x;
            self->unk_120.y = data_ov010_0220ec20.y;
            self->unk_120.z = data_ov010_0220ec20.z;
            self->unk_40->st = 0x3c;
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
            {
                u8 *o = (u8 *)self->unk_104;
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
        self->unk_40->timer++;
        if (self->unk_40->timer >= 0x14) {
            self->unk_40->timer = 0;
            self->unk_40->st = 100;
        }
        break;
    case 100:
        SndMgr_StopSeqArc(data_02097e4c, self->unk_11c);
        Ov010e_Cmd((u8 *)self + 0x1c0, 1, 1);
        func_ov003_021d6a3c(self, self->unk_f0.b2, 1, 1);
        func_ov000_02198360(((u8 *)self->unk_40), 0x2c, 0);
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

struct Obj021fe084 {
    u8 unk_00[0x38];
    void *unk_38;
    u8 unk_3c[0x4];
    ActorSub40 *unk_40;
    u8 *unk_44;
    u8 unk_48[0x4];
    u8 *unk_4c;
    u8 *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[0x8];
    Ov010Vec unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92[0xa];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x44];
    Ov010Flags8 unk_f0;
    u8 unk_f1[0x7];
    u16 *unk_f8;
    u8 unk_fc[0x8];
    u8 *unk_104;
    Ov010Obj108 *unk_108;
    u8 unk_10c[0x2c];
    Ov010Flags8 unk_138;
    u8 unk_139[0x3];
    u16 unk_13c;
    u8 unk_13e[0x2];
    s32 unk_140;
    u8 unk_144[0x78];
    u8 unk_1bc;
    u8 unk_1bd;
};

static inline void Ov010_SetAnim(Obj021fe084 *self, void *model, const void *anim, s32 n) {
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    func_ov000_02190cb0(model, anim, n, 0);
}

void func_ov010_021fe084(Obj021fe084 *self) {
    Ov010Vec pos;
    Ov010Vec d;
    Ov010Cmd cmd;
    u16 st = self->unk_40->st;
    switch (st) {
    case 0: {
        u8 *cam = self->unk_104;
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0xf00;
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        Ov003StateMachine_SendMessage((u8 *)self + 0x1c0, &cmd);
        Ov010_SetAnim(self, self->unk_38, data_ov010_0220ebdc, 0x266);
        self->unk_40->st = 10;
        break;
    }
    case 10:
    case 11: {
        s32 v;
        if (st == 10) {
            Ov010V *e;
            pos.x = self->unk_70.x;
            pos.y = self->unk_70.y + 0x6000;
            pos.z = self->unk_70.z;
            e = func_02065f88(0x192, &pos);
            e->v34(0xbfff, 0, 0);
            e->v0c(0x3000);
            self->unk_40->st = 11;
            func_02049f44(data_02097e4c, 0x29, &self->unk_70, 0);
        }
        v = self->unk_9c + 0xa0;
        self->unk_9c = v;
        if (v > 0x3000) {
            v = 0x3000;
        } else if (v < 0) {
            v = 0;
        }
        self->unk_9c = v;
        func_ov003_021d9900(&d, 0x9fff, (Ov010Vec *)&data_ov010_0220ec38);
        func_ov003_021d9980(&d, self->unk_7e, &d);
        func_ov003_021d9e90(&self->unk_70, &d, &self->unk_70, self->unk_9c, 0);
        self->unk_40->timer++;
        if (self->unk_40->timer > 60) {
            self->unk_40->timer = 0;
            self->unk_40->st = 100;
        }
        break;
    }
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    {
        Ov010Obj108 *o = self->unk_108;
        o->b2 = 1;
        o->unk_06 = 0;
    }
    FLD(u16, self->unk_50, 0xa) = 5;
}

extern void *ActorMgr_GetGroup(void *a, s32 b);
extern Actor *ActorMgr_FindKind(void *a, u16 b, s32 c);
static inline void Ov010h_AttachWorld(Obj021fe084 *obj, Ov010Vec *out) {
    Ov010Vec a;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (obj != NULL && (p = ((void *)obj->unk_44)) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = obj->unk_7e;
        func_ov003_021d9900(&v, obj->unk_7c, &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&a, &v);
    VEC_Add(&a, &obj->unk_70, &a);
    OV010_BLKCPY(out, &a);
}
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern void Actor_TurnToActor(void *self, void *target, s32 a);

struct Ov010G190 {
    u8 lo : 2;
    u8 mid : 3;
    u8 hi : 3;
};

static inline s32 Ov010h_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010h_Cmd(Obj021fe084 *self) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = 4;
    cmd.b = 1;
    Ov003StateMachine_SendMessage((u8 *)self + 0x1c0, &cmd);
}

void func_ov010_021fe2a4(Obj021fe084 *self) {
    const Ov010Vec *goal = &data_ov010_0220ecb0;
    BOOL flag = FALSE;
    s32 i;
    switch ((s32)self->unk_40->st) {
    case 0: {
        void *a;
        {
            u16 id = FLD(u16, ActorMgr_GetGroup(data_ov000_021ccd68, 0x1000), 8);
            a = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_FindKind(data_ov000_021ccd68, id, 0x1000);
        }
        if (a == NULL) {
            self->unk_40->st = 100;
            break;
        }
        self->unk_90 = FLD(u16, a, 0xc);
        {
            u8 *cam = self->unk_104;
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0;
        }
        Ov010h_Cmd(self);
        func_ov000_02190cb0(self->unk_38, data_ov010_0220ebc4, 0x1000, 0);
        self->unk_70.z = 0x1148;
        self->unk_7e = 0xbfff;
        self->unk_7c = 0;
        self->unk_70.x = 0x4e639;
        self->unk_80 = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_70.y = 0x268b;
        self->unk_9c = 0x3000;
        self->unk_40->st = 10;
        func_02049f44(data_02097e4c, 0x32, &self->unk_70, 0);
        break;
    }
    case 10: {
        u8 *g = (u8 *)data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0x1e;
        FLD(u8, g, 0x18e) = 10;
        FLD(u8, g, 0x18f) = 10;
        self->unk_40->st = 0xb;
        break;
    }
    case 0xb:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x3c) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x14;
        }
        break;
    case 0x14: {
        func_ov003_021d6868(self, 0x2bde);
        for (i = 0; i < 3; i++) {
            if (self->unk_40->timer == (u16)((i + 1) * 10)) {
                Ov010V *e;
                {
                    Ov010Vec q;
                    Ov010h_AttachWorld(self, &q);
                    e = func_ov010_02203ee0(0x68, &q);
                }
                e->v0c(0x2800);
                e->v34(0x4000, self->unk_7e, 0);
            }
        }
        self->unk_40->timer++;
        func_ov003_021d9dbc(&self->unk_70, goal, &self->unk_70, self->unk_9c, 0);
        if (VEC_Distance(goal, &self->unk_70) < 0x18000) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x1e;
        }
        break;
    }
    case 0x1e:
    case 0x1f:
        flag = TRUE;
        if (self->unk_40->st == 0x1e) {
            u8 *cam;
            func_ov000_02190cb0(self->unk_38, data_ov010_0220ebc8, 0x100, 0);
            func_0204a028(data_02097e4c, 0xf, &self->unk_70, -5);
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
            cam = self->unk_104;
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
            self->unk_40->st = 0x1f;
        }
        {
            u16 id = self->unk_90;
            void *t = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
            Actor_TurnToActor(self, t, 0x180);
        }
        self->unk_9c = Ov010h_Mul64(self->unk_9c, 0xe00);
        func_ov003_021d9dbc(&self->unk_70, goal, &self->unk_70, self->unk_9c, 0);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov010V *e;
            {
                Ov010Vec q;
                Ov010h_AttachWorld(self, &q);
                e = func_ov010_02203ee0(0x12f, &q);
            }
            e->v0c(0x3000);
            e->v34(0xbfff, self->unk_7e, 0);
            func_02049f44(data_02097e4c, 0x52, &self->unk_70, 0);
        }
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x78) {
            self->unk_40->timer = 0;
            self->unk_40->st = 100;
        }
        break;
    case 100:
        flag = TRUE;
        self->unk_7e = func_01ffc128(self->unk_90, self->unk_7e, 0x180, 1, 0x8000);
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    {
        Ov010Obj108 *o = self->unk_108;
        o->b2 = 1;
        o->unk_06 = 0;
    }
    if (flag && func_ov000_02191120(self->unk_38)) {
        func_ov000_02190cb0(self->unk_38, data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(self->unk_38);
    }
    if (self->unk_40->st < 0x1e) {
        FLD(u16, self->unk_50, 0xa) = 5;
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

void func_ov010_021fe928(Obj021fe084 *self) {
    u16 st = self->unk_40->st;
    if (st == 0) {
        Ov010Obj108 *o;
        self->unk_1bc = 2;
        self->unk_1bd = 3;
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
        o = self->unk_108;
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

void func_ov010_021fe9b8(Obj021fe084 *self) {
    FLD(u16, self->unk_50, 0xa) = 5;
}

void func_ov010_021fe9c8(Obj021fe084 *self) {
    Ov010Vec v;
    Ov010Vec off;
    Ov010Cmd cmd;
    ActorSub40 *st;
    if (self->unk_40->st == 0) {
        Ov010Cam_Start(self->unk_104);
        func_ov000_02190cb0(self->unk_38, data_ov010_0220fc25, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u16, self->unk_50, 0) = 0;
        {
            u8 *q = self->unk_44;
            FLD(Ov010Flags, q, 0x22).b0 = 0;
            FLD(Ov010Flags, q, 0x22).b1 = 0;
        }
        FLD(u16, self->unk_4c, 0x1c) = 0xffff;
        func_ov003_021d88ec(&cmd);
        cmd.a = 2;
        cmd.b = 1;
        Ov003StateMachine_SendMessage((u8 *)self + 0x1c0, &cmd);
        self->unk_40->st++;
    }
    self->unk_40->timer++;
    st = self->unk_40;
    if (st->timer % 60 == 0) {
        Ov010V *p;
        u8 *q;
        st->timer = 0;
        v.x = self->unk_70.x + Rand_PlusMinus(self->unk_64);
        v.y = self->unk_70.y + Rand_PlusMinus(self->unk_64);
        v.z = self->unk_70.z + Rand_PlusMinus(self->unk_64);
        q = self->unk_44;
        off.x = FLD(s32, q, 0xc);
        off.y = FLD(s32, q, 0x10);
        off.z = FLD(s32, q, 0x14);
        VEC_Add(&v, &off, &v);
        p = func_02065f88(0x325, &v);
        p->v34(0, 0x4000, 0);
        p->v14(0x2800, 0x2800, 0x2800);
    }
}

void func_ov010_021febfc(Obj021fe084 *self) {
    Ov010Cmd cmd;
    ActorSub40 *st = self->unk_40;
    if (*(const u16 *)st != 0) {
        return;
    }
    st->st++;
    switch (self->unk_1bd) {
    case 0:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
        break;
    case 1:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 2);
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        Ov003StateMachine_SendMessage((u8 *)self + 0x1c0, &cmd);
        break;
    case 2:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
        break;
    }
}

void func_ov010_021fecb0(Obj021fe084 *self) {
    u16 *c = self->unk_f8;
    c[0] = 0;
    c[1] = 0;
    if (self->unk_138.b0) {
        if (self->unk_140 == 1) {
            self->unk_140 = 2;
            self->unk_13c = 0;
        }
    }
}

static inline Ov010Node *Ov010List_Next(Ov010Node *head, Ov010Node *n) {
    if (n != NULL) {
        return n->next;
    }
    return head;
}

void func_ov010_021fecec(Obj021fe084 *self) {
    void *list = ActorMgr_GetGroup(data_ov000_021ccd68, 0x4829);
    BOOL found = FALSE;
    Robo021ca458 *pl = func_ov000_0219bf90();
    Ov010Node *head = FLD(Ov010Node *, list, 0xc);
    Ov010Node *n;
    for (n = head; n != NULL; n = Ov010List_Next(head, n)) {
        if (n->unk_0e == 0x4829 && pl->unk_b1c != n->unk_0c) {
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

void func_ov010_021fed88(Obj021fe084 *self) {
    u8 k = self->unk_1bd;
    if (k == 0) {
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
    } else if (k == 1) {
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 0;
    }
}

void func_ov010_021fedc4(Obj021fe084 *self) {
    self->unk_f0.b1 = 1;
}

void func_ov010_021fedd4(Obj021fa860 *self) {
    self->unk_f0.b0 = 0;
    self->unk_f0.b1 = 0;
    self->unk_f0.b2 = 0;
    self->unk_f0.b3 = 0;
    self->unk_f2 = 0;
    self->unk_f4 = 0;
    self->unk_f8 = 0;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_108 = 0;
    self->unk_10c = 0;
    self->unk_110 = 0;
    self->unk_114 = 0;
    self->unk_118 = 0;
    self->unk_11c = -1;
    self->unk_120 = data_ov010_0220ec20;
    self->unk_12c = self->unk_120;
    self->unk_1bc = 0;
    self->unk_1bd = 0xff;
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
extern void func_ov010_021fedd4(Obj021fa860 *self);

static inline void Ov010_FreeV(Obj021fa860 *self, u32 off) {
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

void func_ov010_021fee70(Obj021fa860 *self) {
    u32 saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    func_02065804(data_0214a420, self->unk_f4);
    self->unk_f4 = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if ((void *)self->unk_f8 != NULL) {
        Heap_Free(self->unk_f8);
        self->unk_f8 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(self, 0x110);
    Ov010_FreeV(self, 0x114);
    Ov010_FreeV(self, 0x118);
    if ((void *)self->unk_fc != NULL) {
        Heap_Free(self->unk_fc);
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_100 != NULL) {
        void *p = self->unk_100;
        if (p != NULL) {
            func_ov010_02200db8(p);
            Heap_Free(p);
        }
        self->unk_100 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(self, 0x104);
    Ov010_FreeV(self, 0x108);
    Ov010_FreeV(self, 0x10c);
    if (self->unk_138.b0) {
        func_02065804(data_0214a420, self->unk_148);
        self->unk_138.b0 = 0;
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
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff110(void *self) {
    Heap_Free(self);
    return self;
}

struct Obj021ff124 {
    u8 unk_00[0x4];
    u8 unk_04;
    u8 unk_05[0x3];
    s32 unk_08;
    Ov010Vec unk_0c;
};

void *func_ov010_021ff124(Obj021ff124 *self) {
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff138(void *self) {
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff14c(void *self) {
    Heap_Free(self);
    return self;
}

static inline void Ov010_VecSub(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline Actor *Ov010_FindObj(u16 id, s32 kind) {
    if (data_ov000_021ccd68 != NULL) {
        return ActorMgr_FindKind(data_ov000_021ccd68, id, kind);
    }
    return NULL;
}

static inline Ov010Vec Ov010_TargetPos(void) {
    Actor *o = Ov010_FindObj(FLD(u16, ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000), 8), 0x5c06);
    Ov010Vec p = data_ov010_0220fa88;
    if (o != NULL) {
        p = FLD(Ov010Vec, o, 0x70);
        p.y = 0x7000;
    }
    return p;
}

BOOL func_ov010_021ff160(Obj021ff124 *self) {
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = Ov010_TargetPos();
    return TRUE;
}

static inline BOOL Ov010_PlBusy(u8 *pl) {
    return FLD(Ov010Flags32, pl, 0xb24).b0 ? TRUE : FALSE;
}

void func_ov010_021ff21c(Obj021ff124 *self) {
    u8 *pl = (u8 *)func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (Ov010_PlBusy(pl)) {
        return;
    }
    Ov010Vec pp;
    Ov010_VecCopy(&pp, &FLD(Ov010Vec, pl, 0x70));
    if (self->unk_04 == 0) {
        self->unk_0c = Ov010_TargetPos();
    }
    Ov010Vec d;
    Ov010_VecSub(&self->unk_0c, &pp, &d);
    Ov010Rot r = data_ov010_0220ebea;
    r.y = Ov003Vec_Yaw(&d);
    s32 dist = VEC_Distance(&pp, &self->unk_0c);
    func_ov000_0218a358((u8 *)data_ov000_021ccd54 + 0xf4, &self->unk_0c, &r, self->unk_08 + dist + 0x10000, 0, 0x1000, 0x1000, 1);
}

void func_ov010_021ff3d0(Obj021ff124 *self, s32 *msg) {
    switch (msg[0]) {
    case 2:
        self->unk_04 = (msg[1] == 1) ? TRUE : FALSE;
        break;
    case 3:
        self->unk_08 = msg[1];
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
            u16 r = Ov003Vec_Yaw(&self->dir);
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
        tgt = data_ov000_021ccd68 == NULL ? NULL : (u8 *)ActorMgr_GetActor(data_ov000_021ccd68, id);
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
