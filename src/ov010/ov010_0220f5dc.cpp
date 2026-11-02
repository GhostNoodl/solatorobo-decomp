#include "ov010/ov010.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nitro/std.h"
#include "nitro/mi.h"

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
struct Ov010ShakeParam { VecFx32 dir; s16 lim; s16 acc; u16 dur; s16 k5e; s16 k60; s16 k62; s16 k64; s16 k66; };
struct Ov010Rec { u16 v[8]; const char *name; Ov010Rot rot; VecFx32 a; VecFx32 b; };
typedef void (*Ov010Fn)(void);

struct Ov010Shake {
    void *vtbl; // data_ov010_0220fc34
    u8 active;
    u8 unk_05;
    s16 decay;
    VecFx32 a;
    VecFx32 b;
    VecFx32 vel;
    VecFx32 pos;
    u16 state;
    u16 timer;
    u8 unk_3c[0x10];
    VecFx32 dir;
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

// State 3 of the state machine (vtable data_ov010_0220fc6c, 0x18).
class Ov010State3 : public VObj {
public:
    u8 unk_04;
    s32 unk_08;
    VecFx32 unk_0c;
};

struct Ov010Toggle {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

extern "C" {

VecFx32 func_ov010_021fa740(const char *name);
VecFx32 func_ov010_021fa6a0(const char *name);

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
const VecFx32 data_ov010_0220fa88 = data_ov010_0220ec20;
char data_ov010_0220fa5c[] = "nut05";
char data_ov010_0220fa56[] = "nut04";
char data_ov010_0220fa50[] = "nut03";
const VecFx32 data_ov010_0220fa64 = {K(0x1000), K(0), K(0)};
const VecFx32 data_ov010_0220fa70 = data_ov010_0220ec2c;
char data_ov010_0220fa32[] = "run00";
char data_ov010_0220fa38[] = "gun00";
const VecFx32 data_ov010_0220fa7c = {K(0xf619), 0x16000, K(-0x67aa)};
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

extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *o);
extern s32 VEC_Mag(const VecFx32 *v);
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void *data_02097e4c;
extern char data_ov010_0220fc13[];
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov000_0218a358(void *a, const void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);
extern EffectObj *func_ov010_02203ee0(s32 a, const VecFx32 *pos);


// ---- merged from ov010_021fa6a0.cpp
namespace m_021fa6a0 {
extern "C" {


VecFx32 func_ov010_021fa6a0(const char *name) {
    VecFx32 v = data_ov010_0220fa88;
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

VecFx32 func_ov010_021fa740(const char *name) {
    VecFx32 v = data_ov010_0220fa88;
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

VecFx32 func_ov010_021fa7e0(Actor *obj) {
    return Ov010_AttachOffset(obj);
}

}
}  // namespace m_021fa6a0

// ---- merged from ov010_021fa860.cpp
struct Ov010MovePath;

namespace m_021fa860 {
extern "C" {

extern u8 data_ov010_0220fccc[];
extern char data_ov010_0220fbd0[];
extern char data_ov010_0220fbdd[];
extern char data_ov010_0220fbec[];
extern char data_ov010_0220fbf7[];
extern char data_ov010_0220fc02[];
extern void *data_02097e4c;

extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov010Vt_0220fe1c_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f7cf4_Ctor(void *p);
extern void func_ov010_021fedd4(Obj021fa860 *self);
extern void SndMgr_StopSeqArc(void *a, s32 b);
extern void func_ov010_021fee70(Obj021fa860 *self);
extern void *Ov003Group_Dtor(void *p);
extern void *Ov003Vt_021f7cf4_Dtor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void *Ov010Vt_0220fe1c_Dtor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void SndMgr_LoadHeapState(void *a, s32 b, s32 c);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL SndMgr_IsLoadDone(void *a);

void *Ov010ActVt_0220fccc_Ctor(Obj021fa860 *self) {
    func_ov003_021d0c1c(self);
    *(void * *)self = data_ov010_0220fccc;
    self->fade.b0 = 0;
    Ov003Vt_021f7d10_Ctor(&self->ticker);
    Ov010Vt_0220fe1c_Ctor(&self->tasks);
    Ov003Vt_021f79a8_Ctor(&self->flagObj);
    func_ov003_021d8f24(&self->seq);
    Ov003Vt_021f7cf4_Ctor(&self->sm);
    func_ov003_021cf418(&self->group);
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
    SndMgr_StopSeqArc(data_02097e4c, self->seqHandle);
    func_ov010_021fee70(self);
    Ov003Group_Dtor(&self->group);
    Ov003Vt_021f7cf4_Dtor(&self->sm);
    func_ov003_021d8f34(&self->seq);
    Ov003Vt_021f79a8_Dtor(&self->flagObj);
    Ov010Vt_0220fe1c_Dtor(&self->tasks);
    Ov003Vt_021f7d10_Dtor(&self->ticker);
    if (self->fade.b0) {
        EffectMgr_Kill(data_0214a420, self->fade.key);
        self->fade.b0 = 0;
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
        SndMgr_LoadHeapState(data_02097e4c, 1, 1);
        func_02049678(data_02097e4c, 4, 0xb, -1);
        r = FALSE;
    } else if (SndMgr_IsLoadDone(data_02097e4c) == 0) {
        r = FALSE;
    }
    return r;
}

extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void func_ov010_0220166c(void *p);

BOOL Ov010ActVt_0220fccc_Draw(Obj021fa860 *self) {
    BOOL r;
    u8 m1[0x24];
    u8 m2[0x24];
    VecFx32 v;
    func_ov003_021cf4ec(&self->group);
    MTX_RotZ33_(m1, OV010_SIN(self->rot_z), OV010_COS(self->rot_z));
    MTX_RotX33_(m2, OV010_SIN(self->rot_x), OV010_COS(self->rot_x));
    MTX_Concat33(m1, m2, m1);
    MTX_RotY33_(m2, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
    MTX_Concat33(m1, m2, m1);
    func_ov003_021d883c(&self->ticker, &v, &self->pos, self->unk_f2);
    self->unk_93_0 = 1;
    MI_Copy36B(m1, &self->model->rot);
    self->model->trans = v;
    r = func_ov003_021d16cc(self);
    func_ov010_0220166c(self->beams);
    return r;
}

}
}  // namespace m_021fa860

// ---- merged from ov010_021fac1c.cpp
namespace m_021fac1c {
// Hit message handler (message 9 = damage)

extern "C" {

extern const VecFx32 data_ov010_0220ed10;
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);

typedef VecFx32 (*Ov010PosFn)(void *a);

static inline VecFx32 Ov010e_AttachPos(Obj021fa860 *self) {
    VecFx32 r;
    VecFx32 v = data_ov010_0220ec20;
    ActorSub44 *p;
    if (self != NULL && (p = self->unk_44) != NULL) {
        u16 ry;
        v.x = p->unk_0c.x;
        v.y = p->unk_0c.y;
        v.z = p->unk_0c.z;
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
    if (self->unk_ea_13 && self->hp[5] == 0) {
        r = FALSE;
    }
    return r;
}

static inline BOOL Ov010e_Ignore(Obj021fa860 *self) {
    BOOL r = TRUE;
    if (!Ov010e_Invul(self) && self->fsm->current != 0x20) {
        r = FALSE;
    }
    return r;
}

static inline Actor *Ov010e_FindActor(u16 id) {
    Actor *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return a;
}

static inline EffectObj *Ov010e_Eff(Ov010Fade *p) {
    EffectObj *e = NULL;
    if (p != NULL) {
        e = func_020657b0(data_0214a420, p->b0 ? p->key : 0);
    }
    return e;
}

static inline void Ov010e_Spawn(Obj021fa860 *self) {
    if (self->fade.b0 && self->fade.state == 0) {
        Actor *a = Ov010e_FindActor(self->fade.id);
        if (a != NULL) {
            EffectObj *e;
            VecFx32 w;
            VecFx32 u = ((Ov010PosFn)self->fade.getPos)(a);
            w.x = a->pos.x;
            w.y = a->pos.y;
            w.z = a->pos.z;
            VEC_Add(&w, &u, &w);
            e = func_02065f88(self->fade.fxId, &w);
            e->paused = 1;
            self->fade.key = e->id;
            self->fade.unk_01 = 0x1f;
            self->fade.state = 1;
            self->fade.timer = 0;
        }
    }
}

BOOL func_ov010_021fac1c(Obj021fa860 *self, ActorMsg *msg) {
    if (msg->type == 9) {
        if (!Ov010e_Ignore(self)) {
            u16 *c;
            self->hp[2] = msg->id;
            self->hp[5] = 5;
            c = self->unk_f8;
            c[0] = 0;
            c[1]++;
            func_ov003_021cedf4(8);
            c = self->unk_f8;
            if (c[1] >= 0x14) {
                c[0] = 0;
                c[1] = 0;
                func_ov003_021d97fc(&self->seq, 1);
                c = self->unk_f8;
                c[0] = 0;
                c[1] = 0;
                if (self->fade.b0 && self->fade.state == 1) {
                    self->fade.state = 2;
                    self->fade.timer = 0;
                }
                func_ov000_02198360(self->fsm, 0x14, 0);
            } else {
                if (c[1] == 0xf) {
                    Ov010e_Spawn(self);
                    Ov010e_Eff(&self->fade)->SetScaleAll(0x1800);
                    VecFx32 p = Ov010e_AttachPos(self);
                    VecFx32 off = data_ov010_0220ed10;
                    VecFx32 rr;
                    func_ov003_021d9980(&rr, self->rot_y, &off);
                    VEC_Add(&p, &rr, &p);
                    func_02065f88(0x44c, &p)->SetScaleAll(0x2000);
                    self->unk_f2 = 0x800;
                    func_ov003_021d85c8(&self->ticker, 10, 0, 0, 0);
                    {
                        FieldState *g = data_ov000_021ccd54;
                        g->cam.base.flags |= 0x1c;
                        g->cam.base.shakeTime = 10;
                        g->cam.base.shakeLen = 10;
                        g->cam.base.shakeCur = 10;
                    }
                } else {
                    self->unk_f2 = 0x500;
                    func_ov003_021d85c8(&self->ticker, 7, 0, 0, 0);
                }
                {
                    u16 *hp = self->hp;
                    u16 d = msg->hit.dmg;
                    if (d >= hp[0]) {
                        hp[0] = 0;
                    } else {
                        hp[0] -= d;
                    }
                    if (hp[0] == 0) {
                        func_ov000_02198360(self->fsm, 0x15, 0);
                    }
                }
                func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
                func_ov000_02191418(self->model, 5, 0);
            }
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

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
extern const VecFx32 data_ov010_0220ed1c;
extern VecFx32 func_ov010_021fa7e0(Actor *a);
extern BOOL Ov003TickerSet_Init(void *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 v);
extern BOOL Ov010TaskList_Init(void *p);
extern void func_0203f2b8(void *p);
extern BOOL Ov003StateMachine_Init(void *p);
extern void *func_ov010_02200d94(void *p);
extern BOOL func_ov010_02200dcc(void *p, u16 a, u16 b, u8 c, u16 d);
extern void *History_Init(void *p);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern BOOL Ov003Group_Init(void *p);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0218b700(void *u, s32 a, s32 b);
extern BOOL func_020621c4(void);
extern s32 func_02049afc(void *mgr, s32 v);
extern void func_0204a058(void *mgr, u32 slot, s32 volume, s32 frames);

struct Ov010StBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
};

static inline VObj *Ov010e_NewVt(u32 size, void *vt) {
    VObj *o = (VObj *)Heap_Alloc(size);
    if (o != NULL) {
        *(void **)o = vt;
    }
    return o;
}

static inline Ov010State3 *Ov010e_NewC(void) {
    Ov010State3 *o = (Ov010State3 *)Heap_Alloc(sizeof(Ov010State3));
    if (o != NULL) {
        *(void **)o = data_ov010_0220fc6c;
        o->unk_04 = 0;
        o->unk_08 = 0;
        OV010_BLKCPY(&o->unk_0c, &data_ov010_0220fa88);
    }
    return o;
}

static inline Ov010Wobble *Ov010e_NewD(void) {
    Ov010Wobble *o = (Ov010Wobble *)Heap_Alloc(sizeof(Ov010Wobble));
    if (o != NULL) {
        o->vtbl = data_ov010_0220fc50;
        o->b0 = 0;
        o->b1 = 0;
        o->b2 = 0;
        o->b3 = 0;
        o->unk_06 = 0;
        o->unk_08 = 0;
    }
    return o;
}

static inline Ov010Shake *Ov010e_NewE(void) {
    Ov010Shake *o = (Ov010Shake *)Heap_Alloc(sizeof(Ov010Shake));
    if (o != NULL) {
        o->vtbl = data_ov010_0220fc34;
        o->active = 0;
        o->decay = 0;
        VecFx32 t = data_ov010_0220ec20;
        OV010_BLKCPY(&o->a, &t);
        OV010_BLKCPY(&o->b, &t);
        OV010_BLKCPY(&o->vel, &t);
        OV010_BLKCPY(&o->pos, &t);
        History_Init(&o->state);
        func_ov003_021da48c(&o->state, 0);
    }
    return o;
}

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

void Ov010ActVt_0220fccc_Start(Obj021fa860 *self) {
    void *saved;
    void *o;
    u16 k;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    self->unk_f0.b2 = 1;
    self->fade.b0 = 1;
    self->fade.b1 = 0;
    self->fade.fxId = 0x322;
    self->fade.getPos = (void (*)(VecFx32 *, Actor *))func_ov010_021fa7e0; // returns the VecFx32 through out
    self->fade.unk_01 = 0x1f;
    self->fade.id = self->id;
    self->fade.timer = 0;
    self->fade.state = 0;
    self->fade.key = 0;
    Ov003TickerSet_Init(&self->ticker);
    func_ov003_021cf330(&self->flagObj, data_ov010_0220fc0f, data_ov003_021f4340);
    Ov010TaskList_Init(&self->tasks);
    func_ov003_021d8f4c(&self->seq);
    func_ov003_021d95e8(&self->seq, data_ov010_0220ee6c, 0x2a);
    {
        ActorSub44 *p = self->unk_44;
        p->unk_0c.x = 0;
        p->unk_0c.y = 0x61b2;
        p->unk_0c.z = 0x24d5;
    }
    self->model->boxTest = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->hit != NULL) {
        void *q = self->hit;
        if (q != NULL) {
            func_0203f2b8(q);
            Heap_Free(q);
        }
        self->hit = NULL;
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
    Ov003StateMachine_Init(&self->sm);
    func_ov003_021d8a30(&self->sm, 1, self->unk_110);
    func_ov003_021d8a30(&self->sm, 2, self->unk_114);
    func_ov003_021d8a30(&self->sm, 3, self->unk_118);
    o = Heap_Alloc(0x40);
    if (o != NULL) {
        o = func_ov010_02200d94(o);
    }
    self->beams = (Ov010BeamSet *)o;
    func_ov010_02200dcc(self->beams, self->id, 0x78, 0x30, 2);
    self->unk_108 = Ov010e_NewD();
    {
        Ov010Shake *sh = Ov010e_NewE();
        self->unk_104 = sh;
        Ov010e_StartE(sh);
    }
    o = Heap_Alloc(0x20);
    if (o != NULL) {
        o = Ov003Vt_021f7cd8_Ctor(o);
    }
    self->unk_10c = (Ov010Timer *)o;
    func_ov003_021d8c10(o);
    Ov003Group_Init(&self->group);
    k = data_ov003_021f435c;
    func_ov003_021cf52c(&self->group, self->unk_104, k, k);
    func_ov003_021cf52c(&self->group, self->unk_108, k, k);
    func_ov003_021cf52c(&self->group, self->unk_10c, k, k);
    func_ov003_021cf52c(&self->group, &self->ticker, k, k);
    func_ov003_021cf52c(&self->group, &self->tasks, k, k);
    func_ov003_021cf52c(&self->group, &self->flagObj, k, k);
    func_ov003_021cf52c(&self->group, &self->sm, k, k);
    {
        u8 *u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
        if (u != NULL) {
            func_ov000_0218b700(u, 0x3000, 0);
        }
    }
    self->unk_c4 = 0;
    self->unk_93_4 = 1;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220ec02);
    }
    switch (self->unk_18) {
    case 0:
        self->unk_f0.b2 = 0;
        self->seqHandle = func_02049afc(data_02097e4c, 0x4e);
        func_0204a058(data_02097e4c, self->seqHandle, 0x78, 0);
        func_0204a058(data_02097e4c, self->seqHandle, 0x28, 0x258);
        break;
    case 1:
        func_ov000_02198360(self->fsm, 0x2c, 0);
        func_ov003_021d97fc(&self->seq, 1);
        self->unk_f0.b2 = 0;
        break;
    case 2: {
        VecFx32 v = data_ov010_0220ed1c;
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


void func_ov010_021fb5a4(Obj021fa860 *self) {
    func_ov003_021da40c(self->fsm);
    func_ov000_0218d7e8(self, self->fsm->current);
}

extern const Ov010StEnt data_ov010_0220ed50[];
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void Ov003StateMachine_SendMessage(void *p, Ov010Cmd *c);
extern void func_ov010_021ffa6c(void *p);
extern void func_ov010_02201064(void *p);

static inline Ov010Rot Ov010_MkRotZ(Ov010Wobble *q) {
    Ov010Rot r = {0, 0, 0};
    r.z = q->unk_08;
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
    self->model->alpha = a;
    if (self->fade.b0 && self->fade.state != 0) {
        self->fade.unk_01 = a;
    }
    if (self->unk_d0 != NULL && self->unk_ea_3) {
        s32 i;
        for (i = 0; i < 2; i++) {
            Model0218fe1c *p = self->unk_d0->models[i];
            if (p != NULL) {
                p->alpha = a;
            }
        }
    }
}

void func_ov010_021fb5c8(Ov010Cls *self) {
    u32 i;
    u8 key;
    Ov010Wobble *q;
    key = self->fsm->current;
    for (i = 0; i < 11; i++) {
        if (key == data_ov010_0220ed50[i].key && *(s32 *)&data_ov010_0220ed50[i].fn != 0) {
            (self->*data_ov010_0220ed50[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        self->mode = func_ov003_021cf408();
    }
    {
        VecFx32 t;
        VecFx32 o;
        func_ov003_021d9a00(&t, self->rot_z, &data_ov010_0220ec50);
        self->unk_44->unk_0c = t;
        OV010_BLKCPY(&o, &self->unk_104->vel);
        VEC_Add(&self->pos, &o, &self->pos);
    }
    q = self->unk_108;
    if (!q->b1) {
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
                    if (self->fade.b0 && self->fade.state == 1) {
                        self->fade.state = 2;
                        self->fade.timer = 0;
                    }
                }
            } else {
                if (f[0] > 0x5a) {
                    f[0] = 0;
                    f[1] = 0;
                    if (self->fade.b0 && self->fade.state == 1) {
                        self->fade.state = 2;
                        self->fade.timer = 0;
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
        Ov003StateMachine_SendMessage(&self->sm, &cmd);
    } else {
        Ov010Cmd cmd;
        func_ov003_021d88ec(&cmd);
        cmd.a = 1;
        cmd.b = 1;
        Ov003StateMachine_SendMessage(&self->sm, &cmd);
    }
    func_ov003_021cf4ac(&self->group);
    func_ov010_021ffa6c(&self->fade);
    func_ov010_02201064(self->beams);
    self->unk_f8[0]++;
}

}
}  // namespace m_021fb5a4

// ---- merged from ov010_021fb95c.cpp
namespace m_021fb95c {
extern "C" {

extern u8 data_ov010_0220edd4[];
extern BOOL Ov003Sequence_HasEntries(void *p, void *a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);

void Ov010ActVt_0220fccc_Update(Obj021fa860 *self) {
    BOOL a;
    BOOL b;
    if (!func_ov003_021da03c(self)) {
        return;
    }
    a = func_ov003_021d98a0(&self->seq) ? FALSE : TRUE;
    b = Ov003Sequence_HasEntries(&self->seq, data_ov010_0220edd4) ? FALSE : TRUE;
    func_ov003_021d8fc0(&self->seq);
    if (a && b) {
        u16 *hp = self->hp;
        if (((hp[0] << 12) / hp[1]) <= 0x333) {
            func_ov003_021d95e8(&self->seq, data_ov010_0220edd4, 0x19);
            func_ov003_021d97fc(&self->seq, 1);
            func_ov000_02198360(self->fsm, 0x14, 1);
            return;
        }
    }
    if (func_ov003_021d9878(&self->seq)) {
        Ov010B2 r = func_ov003_021d9644(&self->seq);
        self->step = r;
        func_ov000_02198360(self->fsm, r.a, 1);
    }
}

void func_ov010_021fba6c(void) {
}

static inline void Ov010Cam_Start(Ov010Shake *cam) {
    if (cam->active == 0) {
        cam->active = 1;
        OV010_BLKCPY(&cam->dir, &data_ov010_0220fa94.dir);
        cam->lim = data_ov010_0220fa94.lim;
        cam->acc = data_ov010_0220fa94.acc;
        cam->dur = data_ov010_0220fa94.dur;
        cam->k5e = data_ov010_0220fa94.k5e;
        cam->k60 = data_ov010_0220fa94.k60;
        cam->k62 = data_ov010_0220fa94.k62;
        cam->k64 = data_ov010_0220fa94.k64;
        cam->k66 = data_ov010_0220fa94.k66;
        func_ov003_021da48c(&cam->state, 0);
    }
}

void func_ov010_021fba70(Obj021fa860 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    Ov010Cam_Start(self->unk_104);
    func_ov000_02190cb0(self->model, data_ov010_0220ebe0, 0xcd, 0);
    func_ov000_021915a0(self->model);
    self->fsm->st++;
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
    VecFx32 pos;
    VecFx32 target;
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
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL Ov003Vec_Equal(VecFx32 *a, void *b);
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

void func_ov010_021fbb40(Obj021fa860 *self) {
    Ov010MoveParam *p = NULL;
    u32 i;
    for (i = 0; i < 5; i++) {
        if (self->step.b == data_ov010_0220ed28[i].key) {
            p = data_ov010_0220ed28[i].param;
        }
    }
    switch (self->fsm->st) {
    case 0: {
        Ov010Shake *cam;
        func_ov000_02190cb0(self->model, p->anim, 0xcd, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = p->speed;
        if (p->b0) {
            self->pos.x = p->pos.x;
            self->pos.y = p->pos.y;
            self->pos.z = p->pos.z;
        }
        if (p->b1) {
            self->rot_x = p->rot[0];
            self->rot_y = p->rot[1];
            self->rot_z = p->rot[2];
        }
        self->model->visible = 1;
        cam = self->unk_104;
        cam->active = 0;
        cam->decay = 0xf00;
        Ov010_Cmd(&self->sm, 4, p->unk_02);
        self->fsm->st = 10;
        if (self->unk_f0.b1) {
            self->unk_f0.b1 = 0;
            func_02049a48(data_02097e4c, 0xb00, -1, -1, -1);
        }
        break;
    }
    case 10: {
        s32 v;
        if (VEC_Distance(&p->target, &self->pos) <= p->near) {
            v = Ov010_FxMul(self->speed, p->decel);
        } else {
            self->speed += p->accel;
            v = Ov010_Clamp(self->speed, p->max);
        }
        self->speed = v;
        func_ov003_021d9dbc(&self->pos, &p->target, &self->pos, self->speed, 0);
        if (Ov003Vec_Equal(&p->target, &self->pos) || self->speed < p->min) {
            self->fsm->st = 100;
        }
        break;
    }
    case 100:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
    {
        Ov010Wobble *o = self->unk_108;
        o->b2 = 1;
        o->unk_06 = 0;
    }
    self->hp[5] = 5;
}
}
}  // namespace m_021fbb40

struct Ov010MovePath {
    const char *anim0;
    const char *anim1;
    VecFx32 a;
    VecFx32 b;
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
extern u16 Ov003Vec_Pitch(VecFx32 *a);
extern BOOL Ov003Vec_Equal(VecFx32 *a, VecFx32 *b);
extern void func_ov010_02201b48(Ov010TaskList *p);
extern void *func_ov010_02201ad4(void *p, void *fn, u32 time);
extern void *Ov010Vt_0220fe08_New(void);
extern void func_ov010_02201eac(void *t, u16 a, u16 id, const VecFx32 *v0, const VecFx32 *v1);
extern void func_ov010_02201bf4(Ov010TaskList *p);
extern BOOL func_ov010_02201c5c(Ov010TaskList *p);
extern BOOL func_ov010_02201c34(Ov010TaskList *p);

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

static inline Ov010MovePath *Ov010e_NewPath(const char *n0, const char *n1, const VecFx32 *a, const VecFx32 *b) {
    Ov010MovePath *o = (Ov010MovePath *)Heap_Alloc(0x20);
    if (o != NULL) {
        o->anim0 = n0;
        o->anim1 = n1;
        OV010_BLKCPY(&o->a, a);
        OV010_BLKCPY(&o->b, b);
    }
    return o;
}

struct Ov010Fns2 { Ov010Fn f[2]; };
static inline Ov010MovePath *Ov010e_MkPath(u8 sel) {
    VecFx32 v0;
    VecFx32 v1;
    Ov010MovePath *o = NULL;
    switch (sel) {
    case 0:
        func_ov003_021d9900(&v0, 0x1000, (VecFx32 *)&data_ov010_0220ec38);
        func_ov003_021d9980(&v0, 0x4000, &v0);
        o = Ov010e_NewPath(data_ov010_0220ebd4, data_ov010_0220ebd0, &data_ov010_0220eca4, &v0);
        break;
    case 1:
        func_ov003_021d9900(&v1, 0x400, (VecFx32 *)&data_ov010_0220ec38);
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
    VecFx32 d10;
    VecFx32 q;
    VecFx32 d11;
    VecFx32 r;
    VecFx32 dv;
    switch (self->fsm->st) {
    case 0: {
        Ov010MovePath *o;
        if ((void *)self->unk_fc != NULL) {
            Heap_Free(self->unk_fc);
        }
        o = Ov010e_MkPath(self->step.b);
        self->unk_fc = o;
        if (o == NULL) {
            self->fsm->st = 100;
            return;
        }
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0xf00;
        }
        Ov010e_Cmd(&self->sm, 4, 1);
        self->fsm->st = 10;
        break;
    }
    case 10: {
        Ov010MovePath *p;
        EffectObj *e;
        u16 a;
        func_ov000_02190cb0(self->model, self->unk_fc->anim0, data_ov010_0220fa24, 0);
        p = self->unk_fc;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        d10.x = p->a.x - self->pos.x;
        d10.y = p->a.y - self->pos.y;
        d10.z = p->a.z - self->pos.z;
        VEC_Normalize(&d10, &d10);
        q.x = self->pos.x;
        q.y = self->pos.y + 0x6000;
        q.z = self->pos.z;
        e = func_02065f88(0x192, &q);
        a = Ov003Vec_Pitch(&d10);
        e->SetRotXYZ(a, Ov003Vec_Yaw(&d10), 0);
        e->SetScaleAll(0x3000);
        self->fsm->st = 11;
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        break;
    }
    case 11: {
        Ov010MovePath *p = self->unk_fc;
        d11.x = p->a.x - self->pos.x;
        d11.y = p->a.y - self->pos.y;
        d11.z = p->a.z - self->pos.z;
        self->speed = Ov010e_Clamp(self->speed + 0x60, 0x1000);
        if (VEC_Mag(&d11) < 0x3000) {
            self->speed = Ov010_FxMul(self->speed, 0xf40);
            func_ov000_02190cb0(self->model, self->unk_fc->anim1, data_ov010_0220fa24, 0);
        }
        func_ov003_021d9dbc(&self->pos, &self->unk_fc->a, &self->pos, self->speed, 0);
        if (Ov003Vec_Equal(&self->pos, &self->unk_fc->a) || self->speed < 0x10) {
            self->fsm->st = 0x14;
        }
        break;
    }
    case 0x14: {
        Robo021ca458 *pl = func_ov000_0219bf90();
        u32 i;
        u16 id;
        if (pl == NULL) {
            self->fsm->st = 100;
            return;
        }
        func_ov010_02201b48(&self->tasks);
        Ov010Fns2 fns = *(const Ov010Fns2 *)data_ov010_0220ec0c;
        id = pl->id;
        for (i = 0; i < 2; i++) {
            void *t = func_ov010_02201ad4(&self->tasks, (void *)Ov010Vt_0220fe08_New, i * 15);
            *(Ov010Blk12 *)&r = ((Ov010OfsFn)fns.f[i])(self->unk_fc->anim1);
            func_ov010_02201eac(t, id, self->id, &self->unk_fc->b, &r);
        }
        func_ov010_02201bf4(&self->tasks);
        Ov010e_StartE(self->unk_104);
        self->fsm->st = 0x15;
        break;
    }
    case 0x15:
        if (func_ov010_02201c5c(&self->tasks)) {
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
        if (func_ov010_02201c34(&self->tasks)) {
            func_ov010_02201b48(&self->tasks);
            self->fsm->st = 0x1e;
        }
        break;
    case 0x1e:
        self->fsm->timer++;
        if (data_ov010_0220fa28 == self->fsm->timer) {
            func_ov000_02190cb0(self->model, data_ov010_0220ebe0, data_ov010_0220fa20, 0);
        }
        if (self->fsm->timer > 0x78) {
            self->fsm->timer = 0;
            self->fsm->st = 100;
        }
        break;
    case 100:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
}

// A non-const view of the attach offset: loads from it must stay after earlier stores

extern void *data_02097e4c;
extern BOOL func_ov000_02198360(ActorSub40 *a, u8 b, BOOL c);
extern void *Ov010Vt_0220fdf4_New(void);
extern void func_ov010_02202074(void *t, u16 a, u16 id, const VecFx32 *v0, const VecFx32 *v1);
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern s32 VEC_Mag(const VecFx32 *v);

extern void func_ov000_021915a0(Model0218fe1c *a);
extern BOOL func_ov000_02191120(Model0218fe1c *p);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void func_ov010_022016a0(Ov010BeamSet *p, const VecFx32 *a, const VecFx32 *b, u16 c);
extern void func_ov010_02201830(Ov010BeamSet *p, const VecFx32 *a);
extern void func_ov010_02201898(Ov010BeamSet *p, const VecFx32 *a);
extern void Ov010BeamSet_Stop(Ov010BeamSet *p);
extern BOOL Ov010BeamSet_IsDone(Ov010BeamSet *p);

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
    VecFx32 up = data_ov010_0220ec14;
    const char *anim = data_ov010_0220ebd0;
    const VecFx32 *tgt = &data_ov010_0220ecd4;
    const VecFx32 *grav = &data_ov010_0220ec2c;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 rot;
        VecFx32 ofs;
        Robo021ca458 *pl;
        s32 i = 0;
        func_ov000_02190cb0(self->model, data_ov010_0220ebcc, 0x1000, i);
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = i;
            cam->decay = i;
        }
        Ov010e_Cmd(&self->sm, 4, 1);
        self->speed = i;
        self->velY = i;
        self->friction = i;
        self->gravity = i;
        self->unk_120.x = data_ov010_0220ec20.x;
        self->unk_120.y = data_ov010_0220ec20.y;
        self->unk_120.z = data_ov010_0220ec20.z;
        self->pos.x = 0x9600;
        self->pos.y = 0x17d9e;
        self->pos.z = i;
        func_ov010_02201b48(&self->tasks);
        pl = func_ov000_0219bf90();
        if (pl == NULL) {
            func_ov000_02198360(self->fsm, 100, i);
            break;
        }
        for (; i < 3; i++) {
            void *t;
            func_ov003_021d9900(&rot, i * 0xb00 + 0xf800, (VecFx32 *)&data_ov010_0220ec38);
            ofs.x = -0x1333;
            ofs.y = 0x8000;
            ofs.z = 0x2666;
            t = func_ov010_02201ad4(&self->tasks, (void *)Ov010Vt_0220fdf4_New, i * 15 + 0x50);
            func_ov010_02202074(t, pl->id, self->id, &rot, &ofs);
        }
        self->fsm->st = 10;
        break;
    }
    case 10: {
        VecFx32 d;
        VecFx32 n;
        self->unk_120.x = data_ov010_0220ec20.x;
        self->unk_120.y = data_ov010_0220ec20.y;
        self->unk_120.z = data_ov010_0220ec20.z;
        d.x = tgt->x - self->pos.x;
        d.y = tgt->y - self->pos.y;
        d.z = tgt->z - self->pos.z;
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0xa00, &n, &self->unk_120, &self->unk_120);
        if (VEC_Mag(&d) <= 0xa00) {
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 0x1e: {
        FieldState *g;
        func_ov010_02203ee0(0x12e, &self->pos)->SetScaleAll(0x3000);
        g = data_ov000_021ccd54;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 10;
        g->cam.base.shakeLen = 0x1e;
        g->cam.base.shakeCur = 0x1e;
        func_ov000_02190cb0(self->model, data_ov010_0220ebe0, 0x80, 0);
        self->fsm->st = 0x1f;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        break;
    }
    case 0x1f:
        VEC_MultAdd(0x18, &data_ov010_0220ed04, &self->unk_120, &self->unk_120);
        VEC_MultAdd(0x50, grav, &self->unk_120, &self->unk_120);
        func_ov003_021d9b8c(&self->unk_120, &self->unk_120, 0x400, 0x80);
        self->fsm->timer++;
        if (self->fsm->timer > 0x28) {
            self->fsm->timer = 0;
            self->fsm->st = 0x28;
        }
        break;
    case 0x28:
        self->unk_120.x = Ov010_FxMul(self->unk_120.x, 0xf50);
        self->unk_120.y = Ov010_FxMul(self->unk_120.y, 0xf50);
        self->unk_120.z = Ov010_FxMul(self->unk_120.z, 0xf50);
        VEC_MultAdd(4, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        func_ov003_021d9b8c(&self->unk_120, &self->unk_120, 0x400, 0x20);
        self->fsm->timer++;
        if (self->fsm->timer > 0x1e) {
            self->fsm->timer = 0;
            self->fsm->st = 0x32;
        }
        break;
    case 0x32:
        func_ov000_02190cb0(self->model, anim, 0x90, 0);
        func_ov010_02201bf4(&self->tasks);
        self->fsm->st = 0x33;
        func_02049a48(data_02097e4c, 0xb03, -1, -1, -1);
        break;
    case 0x33:
        VEC_MultAdd(0xc, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        VEC_MultAdd(9, &up, &self->unk_120, &self->unk_120);
        VEC_MultAdd(4, &data_ov010_0220ec38, &self->unk_120, &self->unk_120);
        func_ov003_021d9aec(&self->unk_120, &self->unk_120, 0x2000);
        self->fsm->timer++;
        if ((s32)self->fsm->timer > 0xf0 && func_ov010_02201c34(&self->tasks)) {
            self->model->visible = 0;
            self->fsm->timer = 0;
            self->fsm->st = 100;
        }
        break;
    case 100:
        func_ov000_02190cb0(self->model, data_ov010_0220ebe0, 0x1000, 0);
        func_ov010_02201b48(&self->tasks);
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
    VEC_Add(&self->pos, &self->unk_120, &self->pos);
    {
        Ov010Wobble *c = self->unk_108;
        c->b2 = 1;
        c->unk_06 = 0;
    }
}

static inline Actor *Ov010e_FindActor(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
}
static inline void Ov010e_Pull(Obj021fa860 *self, s32 rate) {
    Actor *a = Ov010e_FindActor(self->target);
    if (a != NULL) {
        VecFx32 d;
        s32 x = a->pos.x;
        s32 y = a->pos.y;
        s32 z = a->pos.z;
        d.x = x - self->unk_12c.x;
        d.y = y - self->unk_12c.y;
        d.z = z - self->unk_12c.z;
        VEC_MultAdd(rate, &d, &self->unk_12c, &self->unk_12c);
    }
}

void func_ov010_021fca40(Obj021fa860 *self) {
    BOOL follow = TRUE;
    s32 rate = 0;
    switch (self->fsm->st) {
    case 0: {
        Robo021ca458 *pl;
        rate = 0x100;
        pl = func_ov000_0219bf90();
        if (pl == NULL) {
            self->fsm->st = 100;
        } else {
            self->unk_12c.x = pl->pos.x;
            self->unk_12c.y = pl->pos.y;
            self->unk_12c.z = pl->pos.z;
            self->target = pl->id;
            self->fsm->st = 10;
        }
        func_ov000_02190cb0(self->model, data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(self->model);
        break;
    }
    case 10:
    case 11:
        self->fsm->timer++;
        rate = 0x100;
        if (func_ov000_02191120(self->model)) {
            if (self->fsm->timer > 0x3c) {
                self->fsm->timer = 0;
                self->fsm->st = 0x28;
            }
        }
        break;
    case 0x28: {
        EffectObj *e;
        rate = 0x100;
        Ov010e_Cmd(&self->sm, 3, -0x2800);
        e = func_ov003_021da788(0x196, self, &data_ov010_0220ec5c);
        if (e != NULL) {
            e->SetScaleAll(0x1a00);
        }
        self->fsm->st = 0x29;
        func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        func_02049a48(data_02097e4c, 0xb02, -1, -1, -1);
        break;
    }
    case 0x29:
        self->fsm->timer++;
        rate = 0x100;
        if (self->fsm->timer > 0x46) {
            self->fsm->timer = 0;
            self->fsm->st = 0x32;
        }
        break;
    case 0x32: {
        VecFx32 v;
        rate = 0x100;
        func_ov003_021d9980(&v, self->rot_y, (VecFx32 *)&data_ov010_0220ec5c);
        VEC_Add(&v, &self->pos, &v);
        func_ov010_022016a0(self->beams, &self->unk_12c, &v, 0x2bc);
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0xf00;
        }
        Ov010e_Cmd(&self->sm, 3, 0x3000);
        self->fsm->st = 0x33;
        break;
    }
    case 0x33: {
        VecFx32 v;
        follow = FALSE;
        rate = 0x100;
        func_ov003_021d9980(&v, self->rot_y, (VecFx32 *)&data_ov010_0220ec5c);
        VEC_Add(&v, &self->pos, &v);
        func_ov010_02201830(self->beams, &v);
        func_ov010_02201898(self->beams, &self->unk_12c);
        self->fsm->timer++;
        if (self->fsm->timer > 0x3c) {
            Actor *a = Ov010e_FindActor(self->target);
            if (a != NULL) {
                VecFx32 p;
                p.x = a->pos.x;
                p.y = a->pos.y;
                p.z = a->pos.z;
                if (VEC_Distance(&p, &self->unk_84) > 0x10000) {
                    Ov010BeamSet_Stop(self->beams);
                }
            }
        }
        if (Ov010BeamSet_IsDone(self->beams)) {
            self->fsm->st = 0x3c;
        }
        break;
    }
    case 0x3c:
        Ov010e_Cmd(&self->sm, 3, 0);
        self->fsm->st = 0x3d;
        break;
    case 0x3d:
        self->fsm->timer++;
        if (self->fsm->timer > 0x1e) {
            self->fsm->timer = 0;
            self->fsm->st = 0x46;
        }
        break;
    case 0x46:
        func_ov000_02190cb0(self->model, data_ov010_0220ebe0, 0xcd, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x47;
        break;
    case 0x47:
        if (func_ov000_02191120(self->model)) {
            Ov010e_Cmd(&self->sm, 2, 1);
            self->fsm->st = 100;
        }
        break;
    case 100:
        func_ov003_021d969c(&self->seq, 1);
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
        Ov010Wobble *c = self->unk_108;
        c->b2 = 1;
        c->unk_06 = 0;
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
extern u32 Rand_UpTo(u32 max);
extern void func_ov010_0220172c(Ov010BeamSet *p);
extern void func_ov000_02191418(Model0218fe1c *a, u16 b, BOOL c);
extern BOOL Ov003Sequence_HasEntries(void *p, void *tbl);
extern u16 func_01ffc128(u16 a, u16 b, s32 c, u32 d, u16 e);
extern char data_ov010_0220fc19[];
extern char data_ov010_0220fc1f[];
extern u8 data_ov010_0220edd4[];

typedef Ov010Blk12 (*Ov010PosFn)(void *a);

static inline u16 Ov010e_AngTo(Obj021fa860 *self, Actor *a) {
    if (a == NULL || a == self) {
        return self->rot_y;
    }
    return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
}

static inline void Ov010e_Spawn(Obj021fa860 *self) {
    if (self->fade.b0 && self->fade.state == 0) {
        Actor *a = Ov010e_FindActor(self->fade.id);
        if (a != NULL) {
            EffectObj *e;
            VecFx32 w;
            VecFx32 u;
            *(Ov010Blk12 *)&u = ((Ov010PosFn)self->fade.getPos)(a);
            w.x = a->pos.x;
            w.y = a->pos.y;
            w.z = a->pos.z;
            VEC_Add(&w, &u, &w);
            e = func_02065f88(self->fade.fxId, &w);
            e->paused = 1;
            self->fade.key = e->id;
            self->fade.unk_01 = 0x1f;
            self->fade.timer = 0;
            self->fade.state = 1;
        }
    }
}

void func_ov010_021fcf70(Obj021fa860 *self) {
    u16 st;
    s32 i;
    self->unk_f0.b1 = 0;
    st = self->fsm->st;
    switch (st) {
    case 0:
    case 1:
        if (st == 0) {
            if (self->hp != NULL && func_ov000_02199f60(self->hp) != NULL) {
                self->moveYaw = Ov010e_AngTo(self, (Actor *)func_ov000_02199f60(self->hp));
            } else {
                self->moveYaw = self->rot_y;
            }
            self->moveYaw += (u16)(Rand_PlusMinus(0x2000) + 0x7fff);
            self->unk_120.x = data_ov010_0220ec20.x;
            self->unk_120.y = data_ov010_0220ec20.y;
            self->unk_120.z = data_ov010_0220ec20.z;
            func_ov000_02191418(self->model, 3, 0);
            Ov010e_Cmd(&self->sm, 2, 1);
            func_ov010_0220172c(self->beams);
            func_ov010_02201b48(&self->tasks);
            self->fsm->st = 1;
        }
        func_ov003_021d6868(self, 0x739f);
        if (self->fade.b0) {
            self->fade.b1 = 1;
        }
        if (self->fsm->timer > 3) {
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        } else {
            self->fsm->timer = ActorSub40_Timer(self->fsm) + 1;
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
            func_ov003_021d85c8(&self->ticker, 0x14, 0, 0, 0);
            {
                FieldState *g = data_ov000_021ccd54;
                g->cam.base.flags |= 0x1c;
                g->cam.base.shakeTime = 0xf;
                g->cam.base.shakeLen = 0xf;
                g->cam.base.shakeCur = 0xf;
            }
            func_ov003_021d68e0(self, 0x5adf, 0x739f, 10);
            func_ov003_021d9980(&self->unk_120, self->moveYaw, (VecFx32 *)&data_ov010_0220ec38);
            self->unk_120.x = Ov010_FxMul(self->unk_120.x, 0x800);
            self->unk_120.y = Ov010_FxMul(self->unk_120.y, 0x800);
            self->unk_120.z = Ov010_FxMul(self->unk_120.z, 0x800);
            if (self->fade.b0 && self->fade.state == 1) {
                self->fade.state = 2;
                self->fade.timer = 0;
            }
            func_ov000_02190cb0(self->model, data_ov010_0220fc19, 0x800, 1);
            self->unk_b4 = 0;
            self->unk_b6 = 0;
            self->fsm->st = 0x15;
            func_02049a48(data_02097e4c, 0xb04, -1, -1, -1);
            func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        }
        for (i = 0; i < 3; i++) {
            s32 k = i * 5;
            if (k == self->fsm->timer) {
                func_ov003_021da108(self, 0x6000, 0x6b, 0x1000, 0x3000);
            }
        }
        self->unk_120.x = Ov010_FxMul(self->unk_120.x, 0xec0);
        self->unk_120.y = Ov010_FxMul(self->unk_120.y, 0xec0);
        self->unk_120.z = Ov010_FxMul(self->unk_120.z, 0xec0);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        self->fsm->timer++;
        if (self->fsm->timer > 0x19) {
            func_ov000_02190cb0(self->model, data_ov010_0220fc1f, 0x89, 0);
            func_ov000_021915a0(self->model);
            self->fsm->timer = 0;
            self->fsm->st = 0x32;
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
                if (!Ov003Sequence_HasEntries(&self->seq, data_ov010_0220edd4)) {
                    func_ov003_021d95e8(&self->seq, data_ov010_0220edd4, 0x19);
                    func_ov003_021d97fc(&self->seq, 1);
                }
            }
            self->fsm->st = 100;
        }
        self->rot_x = func_01ffc128(0, self->rot_x, 0x148, 1, 0x8000);
        self->rot_y = func_01ffc128(0xbfff, self->rot_y, 0x148, 1, 0x8000);
        self->rot_z = func_01ffc128(0, self->rot_z, 0x148, 1, 0x8000);
        break;
    case 100:
        func_ov000_02198360(self->fsm, 0x2b, 0);
        break;
    }
    self->unk_108->b1 = 1;
    {
        Ov010Shake *cam = self->unk_104;
        cam->active = 0;
        cam->decay = 0;
    }
    self->hp[5] = 5;
}

extern BOOL Ov003StateMachine_IsState(void *p, s32 a);
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern void func_0203cb78(s32 a, s32 b, s32 c);
extern EffectObj *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *s, s32 a, s32 b, s32 c, u8 d);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void SndMgr_StopSeqArc(void *a, s32 b);
extern char data_ov010_0220fc25[];

static inline s32 Ov010f_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline VecFx32 Ov010f_AttachPos(Obj021fa860 *self) {
    VecFx32 r;
    VecFx32 v = data_ov010_0220ec20;
    ActorSub44 *p;
    if (self != NULL && (p = self->unk_44) != NULL) {
        u16 ry;
        v.x = p->unk_0c.x;
        v.y = p->unk_0c.y;
        v.z = p->unk_0c.z;
        ry = self->rot_y;
        func_ov003_021d9900(&v, self->rot_x, &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&r, &v);
    VEC_Add(&r, &self->pos, &r);
    return r;
}

void func_ov010_021fd694(Obj021fa860 *self) {
    switch (self->fsm->st) {
    case 0:
        if (Ov003StateMachine_IsState(&self->sm, 1)) {
            Ov010e_Cmd(&self->sm, 2, 1);
        } else {
            func_ov003_021d8a7c(&self->sm, 3);
        }
        if (self->fade.b0 && self->fade.state == 1) {
            self->fade.state = 2;
            self->fade.timer = 0;
        }
        func_ov010_0220172c(self->beams);
        func_ov003_021d97fc(&self->seq, 1);
        self->hp[0] = 0;
        {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        self->unk_120.x = data_ov010_0220ec20.x;
        self->unk_120.y = data_ov010_0220ec20.y;
        self->unk_120.z = data_ov010_0220ec20.z;
        {
            Ov010Wobble *c = self->unk_108;
            c->b2 = 1;
            c->unk_06 = 0;
        }
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0xf00;
        }
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4829, 0x15);
        self->fsm->st = 10;
        break;
    case 10:
        func_ov000_02191418(self->model, 5, 1);
        func_ov000_02190cb0(self->model, data_ov010_0220fc19, 0x266, 1);
        func_ov000_021915a0(self->model);
        func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
        self->fsm->st = 11;
    case 11:
        if (self->fsm->timer < 5) {
            self->fsm->timer = ActorSub40_Timer(self->fsm) + 1;
            break;
        }
        func_0203cb78(0x1e000, 1, 0);
        self->fsm->timer = 0;
        self->fsm->st = 0x14;
        break;
    case 0x14:
        if (self->fsm->timer % 20 == 0) {
            VecFx32 pos = Ov010f_AttachPos(self);
            VecFx32 sc;
            sc.x = self->radius;
            sc.y = self->height;
            sc.z = self->radius;
            func_ov000_0219b71c(&pos, &sc, 0x733, 0xccd, 3, 0x32);
            func_ov000_0218996c(0x14, 8);
            func_02049f44(data_02097e4c, 0x35, &pos, 0);
        }
        if (self->unk_f4 == 0) {
            VecFx32 o = {0, 0, 0};
            o.y = 0x61b2;
            self->unk_f4 = func_ov003_021da7e8(0x390, self, &o)->id;
        }
        VEC_MultAdd(0x10, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        VEC_MultAdd(10, &data_ov010_0220ec44, &self->unk_120, &self->unk_120);
        func_ov003_021d9aec(&self->unk_120, &self->unk_120, 0x180);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        self->rot_y = func_01ffc128(Ov003Vec_Yaw(&data_ov010_0220ed04), self->rot_y, 0x80, 1, 0x8000);
        if (self->fsm->timer > 0x28) {
            self->unk_93_4 = 0;
        }
        if (self->fsm->timer % 25 == 0) {
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        if (self->fsm->timer >= 0x78) {
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        } else {
            self->fsm->timer = ActorSub40_Timer(self->fsm) + 1;
        }
        break;
    case 0x1e: {
        EffectObj *e;
        EffectMgr_Kill(data_0214a420, self->unk_f4);
        self->unk_f4 = 0;
        VecFx32 pos2 = Ov010f_AttachPos(self);
        func_02065f88(4, &pos2)->SetScaleAll(0x3000);
        e = func_02065f88(0x131, &pos2);
        e->SetScaleAll(0x2800);
        e->SetRotXYZ(0, Ov003Vec_Yaw(&data_ov010_0220fa64), 0);
        func_02065f88(0x68, &pos2)->SetScaleAll(0x4800);
        func_02049a48(data_02097e4c, 0xb05, -1, -1, -1);
        func_02049f44(data_02097e4c, 0x19, &pos2, 0);
        VEC_MultAdd(0x800, &data_ov010_0220fa64, &self->unk_120, &self->unk_120);
        func_ov000_02190cb0(self->model, data_ov010_0220fc25, 0x800, 1);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x1f;
    }
    case 0x1f:
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        func_ov003_021d9b8c(&self->unk_120, &self->unk_120, 0x200, 0x30);
        self->fsm->timer++;
        if (self->fsm->timer >= 0x3c) {
            self->unk_120.x = Ov010f_FxMul64(self->unk_120.x, 0x600);
            self->unk_120.y = Ov010f_FxMul64(self->unk_120.y, 0x600);
            self->unk_120.z = Ov010f_FxMul64(self->unk_120.z, 0x600);
            self->fsm->timer = 0;
            self->fsm->st = 0x28;
        }
        break;
    case 0x28: {
        VecFx32 d;
        VecFx32 n;
        d.x = 0xcf1b - self->pos.x;
        d.y = 0x1796 - self->pos.y;
        d.z = -0xa46f - self->pos.z;
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0x20, &n, &self->unk_120, &self->unk_120);
        func_ov003_021d9aec(&self->unk_120, &self->unk_120, 0x800);
        VEC_Add(&self->pos, &self->unk_120, &self->pos);
        if (VEC_Mag(&d) <= 0x2800) {
            self->fsm->st = 0x32;
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
            self->fsm->st = 0x3c;
            func_ov003_021d8a7c(&self->sm, 1);
            {
                Ov010Shake *o = self->unk_104;
                if (o->active == 0) {
                    o->active = 1;
                    OV010_BLKCPY(&o->dir, &data_ov010_0220fa94.dir);
                    o->lim = data_ov010_0220fa94.lim;
                    o->acc = data_ov010_0220fa94.acc;
                    o->dur = data_ov010_0220fa94.dur;
                    o->k5e = data_ov010_0220fa94.k5e;
                    o->k60 = data_ov010_0220fa94.k60;
                    o->k62 = data_ov010_0220fa94.k62;
                    o->k64 = data_ov010_0220fa94.k64;
                    o->k66 = data_ov010_0220fa94.k66;
                    func_ov003_021da48c(&o->state, 0);
                }
            }
        }
        break;
    case 0x3c:
        self->fsm->timer++;
        if (self->fsm->timer >= 0x14) {
            self->fsm->timer = 0;
            self->fsm->st = 100;
        }
        break;
    case 100:
        SndMgr_StopSeqArc(data_02097e4c, self->seqHandle);
        Ov010e_Cmd(&self->sm, 1, 1);
        func_ov003_021d6a3c(self, self->unk_f0.b2, 1, 1);
        func_ov000_02198360(self->fsm, 0x2c, 0);
        break;
    }
}

extern void Ov003Vec_MultAdd(void *out, VecFx32 *dir, void *in, s32 speed, s32 e);

static inline void Ov010_SetAnim(Obj021fa860 *self, void *model, const void *anim, s32 n) {
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    func_ov000_02190cb0(model, anim, n, 0);
}

void func_ov010_021fe084(Obj021fa860 *self) {
    VecFx32 pos;
    VecFx32 d;
    Ov010Cmd cmd;
    u16 st = self->fsm->st;
    switch (st) {
    case 0: {
        Ov010Shake *cam = self->unk_104;
        cam->active = 0;
        cam->decay = 0xf00;
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        Ov003StateMachine_SendMessage(&self->sm, &cmd);
        Ov010_SetAnim(self, self->model, data_ov010_0220ebdc, 0x266);
        self->fsm->st = 10;
        break;
    }
    case 10:
    case 11: {
        s32 v;
        if (st == 10) {
            EffectObj *e;
            pos.x = self->pos.x;
            pos.y = self->pos.y + 0x6000;
            pos.z = self->pos.z;
            e = func_02065f88(0x192, &pos);
            e->SetRotXYZ(0xbfff, 0, 0);
            e->SetScaleAll(0x3000);
            self->fsm->st = 11;
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        }
        v = self->speed + 0xa0;
        self->speed = v;
        if (v > 0x3000) {
            v = 0x3000;
        } else if (v < 0) {
            v = 0;
        }
        self->speed = v;
        func_ov003_021d9900(&d, 0x9fff, (VecFx32 *)&data_ov010_0220ec38);
        func_ov003_021d9980(&d, self->rot_y, &d);
        Ov003Vec_MultAdd(&self->pos, &d, &self->pos, self->speed, 0);
        self->fsm->timer++;
        if (self->fsm->timer > 60) {
            self->fsm->timer = 0;
            self->fsm->st = 100;
        }
        break;
    }
    case 100:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
    {
        Ov010Wobble *o = self->unk_108;
        o->b2 = 1;
        o->unk_06 = 0;
    }
    self->hp[5] = 5;
}

extern ActorGroup *ActorMgr_GetGroup(void *mgr, s32 key);
extern Actor *ActorMgr_FindKind(void *a, u16 b, s32 c);
static inline void Ov010h_AttachWorld(Obj021fa860 *obj, VecFx32 *out) {
    VecFx32 a;
    VecFx32 v = data_ov010_0220ec20;
    ActorSub44 *p;
    if (obj != NULL && (p = obj->unk_44) != NULL) {
        u16 ry;
        v.x = p->unk_0c.x;
        v.y = p->unk_0c.y;
        v.z = p->unk_0c.z;
        ry = obj->rot_y;
        func_ov003_021d9900(&v, obj->rot_x, &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&a, &v);
    VEC_Add(&a, &obj->pos, &a);
    OV010_BLKCPY(out, &a);
}
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);

struct Ov010G190 {
    u8 lo : 2;
    u8 mid : 3;
    u8 hi : 3;
};

static inline s32 Ov010h_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010h_Cmd(Obj021fa860 *self) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = 4;
    cmd.b = 1;
    Ov003StateMachine_SendMessage(&self->sm, &cmd);
}

void func_ov010_021fe2a4(Obj021fa860 *self) {
    const VecFx32 *goal = &data_ov010_0220ecb0;
    BOOL flag = FALSE;
    s32 i;
    switch ((s32)self->fsm->st) {
    case 0: {
        Actor *a;
        {
            u16 id = ActorMgr_GetGroup(data_ov000_021ccd68, 0x1000)->key;
            a = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_FindKind(data_ov000_021ccd68, id, 0x1000);
        }
        if (a == NULL) {
            self->fsm->st = 100;
            break;
        }
        self->target = a->id;
        {
            Ov010Shake *cam = self->unk_104;
            cam->active = 0;
            cam->decay = 0;
        }
        Ov010h_Cmd(self);
        func_ov000_02190cb0(self->model, data_ov010_0220ebc4, 0x1000, 0);
        self->pos.z = 0x1148;
        self->rot_y = 0xbfff;
        self->rot_x = 0;
        self->pos.x = 0x4e639;
        self->rot_z = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->pos.y = 0x268b;
        self->speed = 0x3000;
        self->fsm->st = 10;
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        break;
    }
    case 10: {
        FieldState *g = data_ov000_021ccd54;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0x1e;
        g->cam.base.shakeLen = 10;
        g->cam.base.shakeCur = 10;
        self->fsm->st = 0xb;
        break;
    }
    case 0xb:
        self->fsm->timer++;
        if (self->fsm->timer > 0x3c) {
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        }
        break;
    case 0x14: {
        func_ov003_021d6868(self, 0x2bde);
        for (i = 0; i < 3; i++) {
            if (self->fsm->timer == (u16)((i + 1) * 10)) {
                EffectObj *e;
                {
                    VecFx32 q;
                    Ov010h_AttachWorld(self, &q);
                    e = func_ov010_02203ee0(0x68, &q);
                }
                e->SetScaleAll(0x2800);
                e->SetRotXYZ(0x4000, self->rot_y, 0);
            }
        }
        self->fsm->timer++;
        func_ov003_021d9dbc(&self->pos, goal, &self->pos, self->speed, 0);
        if (VEC_Distance(goal, &self->pos) < 0x18000) {
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 0x1e:
    case 0x1f:
        flag = TRUE;
        if (self->fsm->st == 0x1e) {
            Ov010Shake *cam;
            func_ov000_02190cb0(self->model, data_ov010_0220ebc8, 0x100, 0);
            func_0204a028(data_02097e4c, 0xf, &self->pos, -5);
            func_ov003_021d8a7c(&self->sm, 3);
            cam = self->unk_104;
            if (cam->active == 0) {
                cam->active = 1;
                OV010_BLKCPY(&cam->dir, &data_ov010_0220fab0.dir);
                cam->lim = data_ov010_0220fab0.lim;
                cam->acc = data_ov010_0220fab0.acc;
                cam->dur = data_ov010_0220fab0.dur;
                cam->k5e = data_ov010_0220fab0.k5e;
                cam->k60 = data_ov010_0220fab0.k60;
                cam->k62 = data_ov010_0220fab0.k62;
                cam->k64 = data_ov010_0220fab0.k64;
                cam->k66 = data_ov010_0220fab0.k66;
                func_ov003_021da48c(&cam->state, 0);
            }
            func_ov003_021d68e0(self, 0x2bde, 0x6739, 0x50);
            self->fsm->st = 0x1f;
        }
        {
            u16 id = self->target;
            Actor *t = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
            Actor_TurnToActor(self, t, 0x180);
        }
        self->speed = Ov010h_Mul64(self->speed, 0xe00);
        func_ov003_021d9dbc(&self->pos, goal, &self->pos, self->speed, 0);
        if (self->model->anim_state == 1) {
            EffectObj *e;
            {
                VecFx32 q;
                Ov010h_AttachWorld(self, &q);
                e = func_ov010_02203ee0(0x12f, &q);
            }
            e->SetScaleAll(0x3000);
            e->SetRotXYZ(0xbfff, self->rot_y, 0);
            func_02049f44(data_02097e4c, 0x52, &self->pos, 0);
        }
        self->fsm->timer++;
        if (self->fsm->timer > 0x78) {
            self->fsm->timer = 0;
            self->fsm->st = 100;
        }
        break;
    case 100:
        flag = TRUE;
        self->rot_y = func_01ffc128(self->target, self->rot_y, 0x180, 1, 0x8000);
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
    {
        Ov010Wobble *o = self->unk_108;
        o->b2 = 1;
        o->unk_06 = 0;
    }
    if (flag && func_ov000_02191120(self->model)) {
        func_ov000_02190cb0(self->model, data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(self->model);
    }
    if (self->fsm->st < 0x1e) {
        self->hp[5] = 5;
    }
}

extern void func_ov010_021fbb40(Obj021fa860 *self);

static inline void Ov010Cam_Start(Ov010Shake *cam) {
    if (cam->active == 0) {
        cam->active = 1;
        OV010_BLKCPY(&cam->dir, &data_ov010_0220fa94.dir);
        cam->lim = data_ov010_0220fa94.lim;
        cam->acc = data_ov010_0220fa94.acc;
        cam->dur = data_ov010_0220fa94.dur;
        cam->k5e = data_ov010_0220fa94.k5e;
        cam->k60 = data_ov010_0220fa94.k60;
        cam->k62 = data_ov010_0220fa94.k62;
        cam->k64 = data_ov010_0220fa94.k64;
        cam->k66 = data_ov010_0220fa94.k66;
        func_ov003_021da48c(&cam->state, 0);
    }
}

void func_ov010_021fe928(Obj021fa860 *self) {
    u16 st = self->fsm->st;
    if (st == 0) {
        Ov010Wobble *o;
        self->step.a = 2;
        self->step.b = 3;
        func_ov003_021d8a7c(&self->sm, 1);
        o = self->unk_108;
        o->b2 = 0;
        o->b3 = 0;
        o->unk_06 = 0;
        o->unk_08 = 0;
        o->unk_0a = 0;
    } else if (st == 100) {
        func_ov003_021d97fc(&self->seq, 0);
        func_ov003_021d9740(&self->seq, 0xff);
    }
    func_ov010_021fbb40(self);
}

void func_ov010_021fe9b4(void) {
}

void func_ov010_021fe9b8(Obj021fa860 *self) {
    self->hp[5] = 5;
}

void func_ov010_021fe9c8(Obj021fa860 *self) {
    VecFx32 v;
    VecFx32 off;
    Ov010Cmd cmd;
    ActorSub40 *st;
    if (self->fsm->st == 0) {
        Ov010Cam_Start(self->unk_104);
        func_ov000_02190cb0(self->model, data_ov010_0220fc25, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->hp[0] = 0;
        {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        func_ov003_021d88ec(&cmd);
        cmd.a = 2;
        cmd.b = 1;
        Ov003StateMachine_SendMessage(&self->sm, &cmd);
        self->fsm->st++;
    }
    self->fsm->timer++;
    st = self->fsm;
    if (st->timer % 60 == 0) {
        EffectObj *p;
        ActorSub44 *q;
        st->timer = 0;
        v.x = self->pos.x + Rand_PlusMinus(self->radius);
        v.y = self->pos.y + Rand_PlusMinus(self->radius);
        v.z = self->pos.z + Rand_PlusMinus(self->radius);
        q = self->unk_44;
        off.x = q->unk_0c.x;
        off.y = q->unk_0c.y;
        off.z = q->unk_0c.z;
        VEC_Add(&v, &off, &v);
        p = func_02065f88(0x325, &v);
        p->SetRotXYZ(0, 0x4000, 0);
        p->SetScaleXYZ(0x2800, 0x2800, 0x2800);
    }
}

void func_ov010_021febfc(Obj021fa860 *self) {
    Ov010Cmd cmd;
    ActorSub40 *st = self->fsm;
    if (*(const u16 *)st != 0) {
        return;
    }
    st->st++;
    switch (self->step.b) {
    case 0:
        func_ov003_021d8a7c(&self->sm, 3);
        break;
    case 1:
        func_ov003_021d8a7c(&self->sm, 2);
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        Ov003StateMachine_SendMessage(&self->sm, &cmd);
        break;
    case 2:
        func_ov003_021d8a7c(&self->sm, 1);
        break;
    }
}

void func_ov010_021fecb0(Obj021fa860 *self) {
    u16 *c = self->unk_f8;
    c[0] = 0;
    c[1] = 0;
    if (self->fade.b0) {
        if (self->fade.state == 1) {
            self->fade.state = 2;
            self->fade.timer = 0;
        }
    }
}

static inline Actor *Ov010List_Next(Actor *head, Actor *n) {
    if (n != NULL) {
        return n->next;
    }
    return head;
}

void func_ov010_021fecec(Obj021fa860 *self) {
    ActorGroup *list = ActorMgr_GetGroup(data_ov000_021ccd68, 0x4829);
    BOOL found = FALSE;
    Robo021ca458 *pl = func_ov000_0219bf90();
    Actor *head = list->head;
    Actor *n;
    for (n = head; n != NULL; n = Ov010List_Next(head, n)) {
        if (n->kind == 0x4829 && pl->unk_b1c != n->id) {
            found = TRUE;
            break;
        }
    }
    if (found) {
        func_ov003_021d969c(&self->seq, 1);
    } else {
        func_ov003_021d969c(&self->seq, 0);
    }
}

void func_ov010_021fed88(Obj021fa860 *self) {
    u8 k = self->step.b;
    if (k == 0) {
        self->model->visible = 1;
    } else if (k == 1) {
        self->model->visible = 0;
    }
}

void func_ov010_021fedc4(Obj021fa860 *self) {
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
    self->beams = 0;
    self->unk_104 = 0;
    self->unk_108 = 0;
    self->unk_10c = 0;
    self->unk_110 = 0;
    self->unk_114 = 0;
    self->unk_118 = 0;
    self->seqHandle = -1;
    self->unk_120 = data_ov010_0220ec20;
    self->unk_12c = self->unk_120;
    self->step.a = 0;
    self->step.b = 0xff;
}

extern void *func_ov010_02200db8(void *p);
extern void Ov003Group_Release(void *p);
extern void func_ov010_021fedd4(Obj021fa860 *self);

}

// Deletes the object a field points to (vfunc_04) and clears the field.
template <class T> static inline void Ov010_FreeV(T **pp) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*pp != NULL) {
        VObj *p = (VObj *)*pp;
        if (p != NULL) {
            p->vfunc_04();
        }
        *pp = NULL;
    }
    data_02097dd0->cur = saved;
}

extern "C" {

void func_ov010_021fee70(Obj021fa860 *self) {
    void *saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    EffectMgr_Kill(data_0214a420, self->unk_f4);
    self->unk_f4 = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if ((void *)self->unk_f8 != NULL) {
        Heap_Free(self->unk_f8);
        self->unk_f8 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(&self->unk_110);
    Ov010_FreeV(&self->unk_114);
    Ov010_FreeV(&self->unk_118);
    if ((void *)self->unk_fc != NULL) {
        Heap_Free(self->unk_fc);
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->beams != NULL) {
        void *p = self->beams;
        if (p != NULL) {
            func_ov010_02200db8(p);
            Heap_Free(p);
        }
        self->beams = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(&self->unk_104);
    Ov010_FreeV(&self->unk_108);
    Ov010_FreeV(&self->unk_10c);
    if (self->fade.b0) {
        EffectMgr_Kill(data_0214a420, self->fade.key);
        self->fade.b0 = 0;
    }
    self->ticker.vfunc_08();
    ((VObj *)(&self->tasks))->vfunc_08();
    self->flagObj.vfunc_08();
    func_ov003_021d8fa8(&self->seq);
    self->sm.vfunc_08();
    Ov003Group_Release(&self->group);
    func_ov010_021fedd4(self);
}

// The deleting destructors (slot 0x04) of the 8-byte objects with vtables data_ov010_0220fcac and
// data_ov010_0220fc8c, of Ov010State3, Ov010Shake and Ov010Wobble.
void *func_ov010_021ff0fc(VObj *self) {
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff110(VObj *self) {
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff124(Ov010State3 *self) {
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff138(Ov010Shake *self) {
    Heap_Free(self);
    return self;
}

void *func_ov010_021ff14c(Ov010Wobble *self) {
    Heap_Free(self);
    return self;
}

static inline void Ov010_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
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

static inline VecFx32 Ov010_TargetPos(void) {
    Actor *o = Ov010_FindObj(ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000)->key, 0x5c06);
    VecFx32 p = data_ov010_0220fa88;
    if (o != NULL) {
        p = o->pos;
        p.y = 0x7000;
    }
    return p;
}

BOOL func_ov010_021ff160(Ov010State3 *self) {
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = Ov010_TargetPos();
    return TRUE;
}

static inline BOOL Ov010_PlBusy(Robo021ca458 *pl) {
    return pl->unk_b24_0 ? TRUE : FALSE;
}

void func_ov010_021ff21c(Ov010State3 *self) {
    Robo021ca458 *pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (Ov010_PlBusy(pl)) {
        return;
    }
    VecFx32 pp;
    Ov010_VecCopy(&pp, &pl->pos);
    if (self->unk_04 == 0) {
        self->unk_0c = Ov010_TargetPos();
    }
    VecFx32 d;
    Ov010_VecSub(&self->unk_0c, &pp, &d);
    Ov010Rot r = data_ov010_0220ebea;
    r.y = Ov003Vec_Yaw(&d);
    s32 dist = VEC_Distance(&pp, &self->unk_0c);
    func_ov000_0218a358(&data_ov000_021ccd54->cam, &self->unk_0c, &r, self->unk_08 + dist + 0x10000, 0, 0x1000, 0x1000, 1);
}

void func_ov010_021ff3d0(Ov010State3 *self, s32 *msg) {
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

static inline s32 Ov010s_Dot(const VecFx32 *a, const VecFx32 *b) {
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
            func_ov003_021d9900(&self->b, 0xe39, (VecFx32 *)&data_ov010_0220ec38);
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
            VecFx32 u;
            VecFx32 t;
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
            VecFx32 w;
            s32 e;
            w.x = Ov010s_Mul64(self->pos.x, -0x1000);
            w.y = Ov010s_Mul64(self->pos.y, -0x1000);
            w.z = Ov010s_Mul64(self->pos.z, -0x1000);
            VEC_Normalize(&w, &w);
            VEC_MultAdd(self->k66, &w, &self->vel, &self->vel);
            func_ov003_021d9aec(&self->vel, &self->vel, 0x300);
            {
            VecFx32 up;
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

extern s32 FX_Div(s32 a, s32 b);

static inline u8 Ov010_Clamp31(u8 v) {
    return v > 0x1f ? 0x1f : v;
}

void func_ov010_021ffa6c(Ov010Fade *self) {
    Actor *tgt;
    s32 flag;
    EffectObj *obj;
    s32 x;
    s32 v;

    if (!self->b0) {
        return;
    }
    if (self->state != 0) {
        obj = func_020657b0(data_0214a420, self->key);
        u16 id = self->id;
        tgt = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
        if (obj == NULL || tgt == NULL) {
            self->state = 2;
            self->timer = 0;
        } else if (self->b1) {
            obj->paused = 1;
        } else {
            VecFx32 c;
            VecFx32 b;
            VecFx32 a;
            x = 0x1f;
            flag = 0;
            obj->paused = 0;
            switch (self->state) {
            case 1:
                if (self->timer == 0) {
                    obj->paused = 0;
                    obj->loopCount = -1;
                    flag = 1;
                }
                break;
            case 2:
                obj->paused = 1;
                obj->SetScaleAll(obj->scale.x + (s32)(((s64)(0x2800 - obj->scale.x) * 0x280 + 0x800) >> 12));
                x = 0x1f - self->timer * 2;
                if (self->timer > 0x1e) {
                    obj->state = 4;
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
            obj->alpha = FX_Div(Ov010_Clamp31(v) << 12, 0x1f000);
            self->getPos(&a, tgt);
            *(Ov010Blk12 *)&b = *(Ov010Blk12 *)&a;
            c.x = tgt->pos.x;
            c.y = tgt->pos.y;
            c.z = tgt->pos.z;
            obj->SetPos(&c);
            obj->AddPos(&b);
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
    FieldState *g = data_ov000_021ccd54;
    g->cam.unk_dc.x = 0;
    g->cam.unk_dc.y = 0x5580;
    g->cam.unk_dc.z = 0;
    g->cam.unk_da_0 = 1;
    g = data_ov000_021ccd54;
    g->cam.unk_f4 = 0x5c00;
    g->cam.unk_da_2 = 2;
}

void func_ov010_021ffd0c(Ov010Toggle *o) {
    if (o->b0) {
        VecFx32 v = data_ov010_0220ec80;
        Ov010Rot r = data_ov010_0220ebfc;
        func_ov000_0218a358(&data_ov000_021ccd54->cam, &v, &r, 0x17385, 0, 0x1000, 0x1000, 1);
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
        VecFx32 v = data_ov010_0220ec74;
        Ov010Rot r = data_ov010_0220ebf6;
        func_ov000_0218a358(&data_ov000_021ccd54->cam, &v, &r, 0xf000, 0, 0x1000, 0x1000, 1);
    } else if (o->b1) {
        Ov010_SetSky();
    }
}

}
