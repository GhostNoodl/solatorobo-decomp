#include "ov013/ov013.h"

typedef Ov013Vec VecFx32;

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// spot block. The objects before the empty asm function are the TU's size-sorted group (definition
// order found with solve2.py); the vectors after it keep definition order. The spot block is one
// object: its far[] entries are initialised before the separate near-spot array.
// Ov013Act_021fea8c_Start is part of this TU: it reads data_ov013_0220aee0 and data_ov013_0220af28
// through the .rodata base plus an offset. So do the functions of the nine files around it
// (0x021fea8c..0x02204454), merged in round dtB, each in its own namespace: they read the TU's
// name pointers and vectors by name instead of FLD views of data_ov013_0220aedc. The second read of af28's x is
// reloaded in the target, so it goes through a cast view of the vector (a second access path that
// MWCC does not merge with the first read).
struct Ov013Rot { u16 x, y, z; };
struct Ov013Spot { VecFx32 pos; u16 rot; };
typedef void (*Ov013Fn)(void);
struct Ov013SpotBlock { char name[16]; Ov013Fn fn[6]; Ov013Spot far[4]; };

extern "C" {

void func_ov013_02204450(void);
void *func_ov013_021fed50(void *self);
BOOL func_ov013_02204448(void);
void func_ov013_02204444(void);
void func_ov013_0220428c(void *self);
void func_ov013_022043f8(void *self, u32 *p);

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
const Ov013SpotBlock data_ov013_0220b930 = {"SHR2", {(Ov013Fn)func_ov013_02204450, (Ov013Fn)func_ov013_021fed50, (Ov013Fn)func_ov013_02204448, (Ov013Fn)func_ov013_02204444, (Ov013Fn)func_ov013_0220428c, (Ov013Fn)func_ov013_022043f8}, {{data_ov013_0220afa0, 0xde4e}, {data_ov013_0220afac, 0x1b00}, {data_ov013_0220afb8, 0xaa65}, {data_ov013_0220afc4, 0x6b00}}};
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


// ---- merged from ov013_021fea8c.cpp
namespace m_021fea8c {
struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01[3];
    Ov013Vec v;
};

extern "C" {

extern void *data_0214a420;
extern void *data_ov013_0220b9a0[];
extern void *func_ov003_021d8910(void *p);
extern void *func_ov003_021cf2bc(void *p);
extern void func_ov003_021d8f24(void *p);
extern void func_ov003_021d8f34(void *p);
extern void *func_ov003_021cf2d8(void *p);
extern void *func_ov003_021d8928(void *p);
extern void func_ov003_021d8fa8(void *p);
extern void func_02065804(void *a, s32 b);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void func_ov003_021cf3fc(s32 a);
void func_ov013_021fed64(Ov013Act_021fea8c *self);
void func_ov013_021febf8(Ov013Act_021fea8c *self);

Ov013Act_021fea8c *Ov013Act_021fea8c_Ctor(Ov013Act_021fea8c *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov013_0220b9a0;
    func_ov003_021d8910((u8 *)self + 0x12c);
    func_ov003_021cf2bc((u8 *)self + 0x13c);
    func_ov003_021d8f24((u8 *)self + 0x14c);
    func_ov013_021fed64(self);
    return self;
}

Ov013Act_021fea8c *Ov013Act_021fea8c_Dtor(Ov013Act_021fea8c *self) {
    FLD(void *, self, 0) = data_ov013_0220b9a0;
    func_ov013_021febf8(self);
    func_ov003_021d8f34((u8 *)self + 0x14c);
    func_ov003_021cf2d8((u8 *)self + 0x13c);
    func_ov003_021d8928((u8 *)self + 0x12c);
    func_ov003_021d0edc(self);
    return self;
}

Ov013Act_021fea8c *Ov013Act_021fea8c_DtorDelete(Ov013Act_021fea8c *self) {
    FLD(void *, self, 0) = data_ov013_0220b9a0;
    func_ov013_021febf8(self);
    func_ov003_021d8f34((u8 *)self + 0x14c);
    func_ov003_021cf2d8((u8 *)self + 0x13c);
    func_ov003_021d8928((u8 *)self + 0x12c);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

static inline void Ov013_AddVec(Ov013Vec *a, Ov013Vec b, Ov013Vec *out) {
    VEC_Add(a, &b, out);
}

static inline Ov013Vec Ov013_GetOff(Ov013Opt120 *o) {
    Ov013Vec off = data_ov013_0220af28;
    if (o->b0) {
        off.x = o->v.x;
        off.y = o->v.y;
        off.z = o->v.z;
    }
    return off;
}

BOOL Ov013Act_021fea8c_Draw(Ov013Act_021fea8c *self) {
    Ov013Vec saved = self->pos;
    BOOL r;
    Ov013_AddVec(&self->pos, Ov013_GetOff(((Ov013Opt120 *)self->unk_120)), &self->pos);
    r = func_ov003_021d16cc(self);
    self->pos.x = saved.x;
    self->pos.y = saved.y;
    self->pos.z = saved.z;
    return r;
}

static inline void Ov013_DelOpt(Ov013Opt120 *o) {
    if (o != NULL) {
        if (o->b0) {
            o->b0 = 0;
        }
        func_0203de1c(o);
    }
}

void func_ov013_021febf8(Ov013Act_021fea8c *self) {
    u32 saved;
    ((Ov013V *)((u8 *)self + 0x12c))->v08();
    ((Ov013V *)((u8 *)self + 0x13c))->v08();
    func_ov003_021d8fa8((u8 *)self + 0x14c);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (((Ov013Opt120 *)self->unk_120) != NULL) {
        Ov013_DelOpt(((Ov013Opt120 *)self->unk_120));
        FLD(Ov013Opt120 *, self, 0x120) = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (((Ov013Opt120 *)self->unk_124) != NULL) {
        Ov013_DelOpt(((Ov013Opt120 *)self->unk_124));
        FLD(Ov013Opt120 *, self, 0x124) = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (((Ov013V *)self->unk_128) != NULL) {
        Ov013V *v = ((Ov013V *)self->unk_128);
        if (v != NULL) {
            v->v04();
        }
        FLD(Ov013V *, self, 0x128) = NULL;
    }
    data_02097dd0->cur = saved;
    func_02065804(data_0214a420, self->unk_100);
    func_02065804(data_0214a420, self->unk_104);
    func_ov013_021fed64(self);
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    func_ov003_021cf3fc(0);
}

void *func_ov013_021fed50(void *self) {
    func_0203de1c(self);
    return self;
}

void func_ov013_021fed64(Ov013Act_021fea8c *self) {
    Ov013Flags8 *f = &self->unk_f0;
    f->b0 = 0;
    f->b1 = 0;
    f->b2 = 0;
    f->b3 = 0;
    f->b4 = 0;
    f->b5 = 0;
    self->unk_f2 = 0xffff;
    self->unk_f4 = 0xffff;
    self->unk_f6 = 0xffff;
    self->unk_f8 = 0;
    self->unk_fa = 0;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_108 = data_ov013_0220af28;
    self->unk_114 = self->unk_108;
    self->unk_120 = NULL;
    self->unk_124 = NULL;
    self->unk_128 = NULL;
    self->unk_15c = 0;
    self->unk_15d = 0xff;
}

}
}  // namespace m_021fea8c

extern "C" {
struct Ov013Area {
    void *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 id;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    Ov013Vec pos;
};

struct Ov013Opt120B {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 pad;
    u16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

struct Ov013Opt124 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 unk_02;
    s32 unk_04;
    Ov013Vec v;
    s32 unk_14;
    void *fn;
};

extern const u8 data_ov003_021f4340;
extern u8 data_ov013_0220b150[];
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_0203f324(Ov013Sub48 *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_ov003_021d8980(void *p);
extern void func_ov003_021d8a30(void *p, s32 a, void *b);
extern void func_ov013_02204428(void *dst, const void *src, void *owner);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov000_021bd228(void *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov013Actor *self, const void *p);

static inline void Ov013B_PartFlag(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline void Ov013Area_Set(Ov013Area *ar, u16 id) {
    ar->b0 = 1;
    ar->b1 = 1;
    ar->id = id;
    ar->unk_08 = -0x1464a;
    ar->unk_0c = 0x2000;
    ar->unk_10 = -0xad64;
    ar->unk_14 = 0xa89c;
    ar->unk_18 = 0xc642;
    ar->unk_1c = 0xc4cd;
}

void Ov013Act_021fea8c_Start(Ov013Act_021fea8c *self) {
    Ov013Sub48 *m48;
    Ov013Area *ar;
    Ov013Opt120B *o2;
    Ov013Opt124 *o3;
    const char *anim;
    void *m;
    s32 x;
    s32 y;
    s32 z;
    func_ov003_021d112c(self);
    self->unk_f0.b3 = 1;
    func_ov003_021cf330((u8 *)self + 0x13c, data_ov013_0220b930.name, data_ov003_021f4340);
    m48 = self->unk_48;
    m48->unk_9a_1 = 0;
    m48->unk_9a_4 = 0;
    m48 = self->unk_48;
    m48->unk_9a_0 = 1;
    m48->unk_9a_3 = 1;
    func_0203f324(m48);
    {
        Ov013Sub44 *n = self->unk_44;
        n->unk_1c = Ov013_FxMul(n->unk_1c, 0x1800);
    }
    func_ov003_021d8f4c((u8 *)self + 0x14c);
    func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b150, 0xf);
    self->unk_90 = func_ov000_0219bf90()->id;
    ar = (Ov013Area *)func_0203dd9c(0x2c);
    if (ar != NULL) {
        ar->vt = (void *)data_ov013_0220b930.fn;
        ar->b0 = 0;
    }
    FLD(Ov013Area *, self, 0x128) = ar;
    Ov013Area_Set(ar, self->id);
    ar->pos.x = x = data_ov013_0220af28.x;
    ar->pos.y = y = data_ov013_0220af28.y;
    ar->pos.z = z = data_ov013_0220af28.z;
    func_ov003_021d8980((u8 *)self + 0x12c);
    func_ov003_021d8a30((u8 *)self + 0x12c, 0, self->unk_128);
    o2 = (Ov013Opt120B *)func_0203dd9c(0x1c);
    if (o2 != NULL) {
        o2->b0 = 0;
    }
    FLD(Ov013Opt120B *, self, 0x120) = o2;
    o2->b0 = 1;
    o2->unk_02 = 0;
    {
        s32 x2 = ((const VecFx32 *)&data_ov013_0220af28)->x;
        o2->v.x = x2;
        o2->v.y = y;
        o2->v.z = z;
        o2->w.x = x2;
        o2->w.y = y;
        o2->w.z = z;
    }
    o3 = (Ov013Opt124 *)func_0203dd9c(0x1c);
    if (o3 != NULL) {
        o3->b0 = 0;
    }
    FLD(Ov013Opt124 *, self, 0x124) = o3;
    o3->b0 = 0;
    o3->b1 = 0;
    o3->unk_02 = 0x1000;
    o3->unk_04 = 0;
    o3->v.x = x;
    o3->v.y = y;
    o3->v.z = z;
    o3->unk_14 = 0;
    o3->fn = (void *)func_ov013_02204428;
    o3->b0 = 1;
    anim = data_ov013_0220aee0;
    func_ov000_02190cb0(self->unk_38, anim, 0x1000, 1);
    m = self->unk_38;
    if (FLD(void *, m, 0x14) != NULL) {
        void *o = FLD(void *, m, 0);
        func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 8), anim, 0x1000, 0);
    }
    FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
    m = self->unk_38;
    if (m != NULL) {
        Ov013B_PartFlag(m, 0);
        Ov013B_PartFlag(m, 1);
        Ov013B_PartFlag(m, 3);
        Ov013B_PartFlag(m, 4);
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_5c != NULL) {
            void *p = self->unk_5c;
            if (p != NULL) {
                func_ov000_021bd228(p);
                func_0203de1c(p);
            }
            self->unk_5c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov013_0220af1e);
    }
    self->pos.y -= 0x1000;
}

}


// ---- merged from ov013_021ff1ec.cpp
namespace m_021ff1ec {
struct Ov013Pair {
    u8 a;
    u8 b;
};

typedef void (Ov013Actor::*Ov013ActFn)();

struct Ov013StEnt {
    u8 key;
    Ov013ActFn fn;
};

struct Ov013Obj1c;
typedef void (*Ov013OffFn)(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);

struct Ov013Obj1c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    u32 unk_04;
    Ov013Vec v;
    Ov013Actor *unk_14;
    Ov013OffFn unk_18;
};

struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

extern "C" {

extern BOOL func_ov003_021da03c(Ov013Actor *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov013Pair func_ov003_021d9644(void *p);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern u8 func_ov003_021d6548(Ov013Actor *self, void *p);
extern void func_ov003_021d68e0(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);

void func_ov013_021ff1ec(void) {
}

void Ov013Act_021fea8c_Update(Ov013Act_021fea8c *self) {
    Ov013Pair p;
    if (!func_ov003_021da03c(self)) {
        return;
    }
    self->unk_93_4 = 1;
    self->unk_c4 = 0;
    self->unk_f0.b0 = 0;
    func_ov003_021d8fc0((u8 *)self + 0x14c);
    if (!func_ov003_021d9878((u8 *)self + 0x14c)) {
        return;
    }
    p = func_ov003_021d9644((u8 *)self + 0x14c);
    self->unk_15c = p.a;
    self->unk_15d = p.b;
    func_ov000_02198360(self->unk_40, p.a, 1);
}

void func_ov013_021ff288(Ov013Act_021fea8c *self) {
    func_ov003_021da40c(self->unk_40);
    func_ov000_0218d7e8(self, self->unk_40->unk_13);
}

static inline void Ov013_Ack(Ov013Act_021fea8c *self, Ov013Msg *msg) {
    self->unk_30 |= 1 << msg->type;
    msg->type = 0;
}

static inline BOOL Ov013_Ignore(Ov013Act_021fea8c *self, Ov013Msg *msg) {
    if (self->unk_f0.b0 && msg->type == 9) {
        Ov013_Ack(self, msg);
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Ov013_IsInvul(u16 *hp) {
    return hp[5] != 0;
}

static inline BOOL Ov013_IsBusy(u8 s) {
    BOOL r = FALSE;
    switch (s) {
    case 2:
    case 0xf:
    case 0x15:
    case 0x20:
    case 0x29:
    case 0x2a:
        r = TRUE;
        break;
    }
    return r;
}

static inline BOOL Ov013_CanFlinch(Ov013Act_021fea8c *self, Ov013Msg *msg) {
    BOOL r = FALSE;
    if (msg->type == 9) {
        if (!Ov013_IsBusy(self->unk_40->unk_13)) {
            r = TRUE;
        }
    }
    return r;
}

BOOL func_ov013_021ff2ac(Ov013Act_021fea8c *self, Ov013Msg *msg) {
    if (self->unk_f0.b0 && msg->type == 9) {
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    if (msg->type == 9) {
        if (!Ov013_IsInvul(self->unk_50) && self->unk_40->unk_13 != 0x20) {
            self->unk_50[2] = FLD(u16, msg, 6);
            func_ov003_021d6548(self, (u8 *)msg + 8);
            func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
            self->unk_50[5] = 5;
            func_ov000_02191418(self->unk_38, 5, 0);
            if (self->unk_50[0] == 0) {
                self->unk_40->flags |= 0x200000;
            } else if (Ov013_CanFlinch(self, msg)) {
                func_ov000_02198360(self->unk_40, 0x12, 1);
            }
        }
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

extern const Ov013StEnt data_ov013_0220b1ac[];
extern void *data_0214a420;
extern void func_ov003_021d3008(Ov013Actor *self);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern int func_ov003_021cf408(void);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_020657b0(void *a, s32 b);
extern void func_02065860(void *a, s32 b);
extern void func_ov003_021d6868(Ov013Actor *self, s32 a);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_0203f364(void *p);
extern void func_0203f324(void *p);

struct Ov013Blk12 {
    s32 w[3];
};

static inline void Ov013_MoveToward(Ov013Vec *v, const Ov013Vec *w, s32 k, Ov013Vec &d) {
    d.x = w->x - v->x;
    d.y = w->y - v->y;
    d.z = w->z - v->z;
    VEC_MultAdd(k, &d, v, v);
}


void func_ov013_021ff45c(Ov013Act_021fea8c *self) {
    Ov013Vec w;
    Ov013Vec d;
    Ov013Vec off;
    Ov013Vec pos;
    u32 i;
    u8 key = self->unk_40->unk_13;
    for (i = 0; i < 9; i++) {
        if (key == data_ov013_0220b1ac[i].key && *(s32 *)((u8 *)&data_ov013_0220b1ac[i] + 4) != 0) {
            (self->*data_ov013_0220b1ac[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (self->unk_f0.b4) {
        const char *anim;
        void *m;
        if (self->unk_f0.b3) {
            anim = data_ov013_0220aeec;
        } else {
            anim = data_ov013_0220aef0;
        }
        m = self->unk_38;
        if (FLD(void *, m, 0x1c) != NULL) {
            void *o = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x1c), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 0x10), anim, 0x1000, 0);
        }
    }
    self->unk_f0.b4 = 1;
    if (func_ov003_021cf408()) {
        self->unk_15 = func_ov003_021cf408();
    }
    {
        Ov013Opt120 *p = ((Ov013Opt120 *)self->unk_120);
        if (p->b0) {
            Ov013_MoveToward(&p->v, &p->w, p->unk_02, d);
            p->w = data_ov013_0220af28;
        }
    }
    {
        Ov013Obj1c *q = ((Ov013Obj1c *)self->unk_124);
        if (q->b0 && q->b1) {
            if (q->unk_04 % 10 == 0) {
                void *a = q->unk_14->unk_38;
                FLD(u16, a, 0xb6) = 0x7fff;
                FLD(u16, a, 0xb8) = 0x3eaf;
                FLD(u16, a, 0xba) = 6;
                FLD(u16, a, 0xbc) = 5;
            }
            if (q->unk_04 % 50 == 0) {
                Ov013_VecCopy(&pos, &q->unk_14->pos);
                q->unk_18(&off, &q->v, q->unk_14);
                VEC_Add(&pos, &off, &pos);
                func_02065f88(0x66, &pos)->v0c(q->unk_02);
            }
            q->unk_04++;
        }
    }
    ((Ov013V *)((u8 *)self + 0x12c))->v0c();
    if (!self->unk_f0.b1) {
        Ov013Obj1c *q = ((Ov013Obj1c *)self->unk_124);
        if (q->b0 && q->b1) {
            q->b1 = 0;
        }
    }
    self->unk_f0.b1 = 0;
    if (self->pos.y > -0xee1) {
        if (func_020657b0(data_0214a420, self->unk_104) == NULL && !self->unk_f0.b2) {
            Ov013Vec v;
            Ov013V *e;
            func_ov003_021d9980(&v, self->rot[1], &data_ov013_0220af34);
            VEC_Add(&v, &self->pos, &v);
            *(Ov013Blk12 *)&w = *(Ov013Blk12 *)&v;
            w.y = 0x1000;
            e = func_02065f88(0x2bd, &w);
            e->v0c(0x4000);
            self->unk_104 = FLD(s32, e, 0x24);
        }
    } else {
        func_02065860(data_0214a420, self->unk_104);
        self->unk_104 = 0;
        func_ov003_021d6868(self, 0x4698);
    }
    self->unk_f0.b2 = 0;
    if (self->unk_40->unk_13 != 0x15) {
        if (self->pos.y < -0xc000) {
            self->unk_38->unk_c2_0 = 0;
        } else {
            s32 a;
            self->unk_38->unk_c2_0 = 1;
            a = 0x1f;
            if (self->pos.y < -0x8000) {
                a = 0x1f >> (5 - ((self->pos.y + 0xd000) >> 12));
            }
            if (a > 0x1f) {
                a = 0x1f;
            } else if (a < 1) {
                a = 1;
            }
            self->unk_38->unk_be = a;
        }
    }
    if (self->unk_f0.b0) {
        Ov013Sub48 *m = self->unk_48;
        if (m != NULL) {
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
    } else {
        Ov013Sub48 *m = self->unk_48;
        if (m != NULL) {
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
        }
        self->unk_ea_0 = 0;
    }
}

}
}  // namespace m_021ff1ec

// ---- merged from ov013_021ff924.cpp
namespace m_021ff924 {
struct Ov013Pair {
    u8 a;
    u8 b;
};

extern "C" {

extern BOOL func_ov003_021da03c(Ov013Actor *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov013Pair func_ov003_021d9644(void *p);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern u8 func_ov003_021d6548(Ov013Actor *self, void *p);
extern void func_ov003_021d68e0(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);

extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov013_021fe948(Ov013Vec *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude);
extern BOOL func_ov013_022038a8(Ov013Act_021fea8c *self, Ov013Vec *pos, u16 rot);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0219bf90(void);
extern void func_ov013_02202dc8(Ov013Act_021fea8c *self, s32 a, s32 b, BOOL c, s32 d);

static inline void Ov013_PartFlag(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline u32 Ov013_Nearest(const Ov013Vec *p, const Ov013Spot *tbl, u32 n) {
    u32 best = 0;
    u32 i;
    for (i = 0; i < n; i++) {
        if (VEC_Distance(p, &tbl[best].pos) > VEC_Distance(p, &tbl[i].pos)) {
            best = i;
        }
    }
    return best;
}

static inline bool Ov013_IsMode1(Ov013Act_021fea8c *self) {
    return self->unk_15d == 1;
}

void func_ov013_021ff924(Ov013Act_021fea8c *self) {
    const char *anim;
    void *m;
    if (self->unk_40->state != 0) {
        return;
    }
    anim = data_ov013_0220aee0;
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    func_ov000_02190cb0(self->unk_38, anim, 0x266, 0);
    m = self->unk_38;
    if (FLD(void *, m, 0x14) != NULL) {
        void *o = FLD(void *, m, 0);
        func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 8), anim, 0x1000, 0);
    }
    FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
    m = self->unk_38;
    if (m != NULL) {
        Ov013_PartFlag(m, 0);
        Ov013_PartFlag(m, 1);
        Ov013_PartFlag(m, 3);
        Ov013_PartFlag(m, 4);
    }
    self->rot[0] = 0;
    self->rot[2] = 0;
    self->unk_40->state++;
}

void func_ov013_021ffab4(Ov013Act_021fea8c *self) {
    if (self->unk_40->state == 0) {
        Ov013Vec p;
        u32 best;
        Ov013Actor *pl = func_ov000_0219bf90();
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        switch (self->unk_15d) {
        case 1:
            best = Ov013_Nearest(&p, data_ov013_0220b900, 3);
            self->unk_114 = data_ov013_0220b900[best].pos;
            self->unk_fc = data_ov013_0220b900[best].rot;
            break;
        case 3:
            best = Ov013_Nearest(&p, data_ov013_0220b930.far, 4);
            self->unk_114 = data_ov013_0220b930.far[best].pos;
            self->unk_fc = data_ov013_0220b930.far[best].rot;
            break;
        case 2:
            func_ov013_021fe948(&self->unk_114, &self->unk_fc, data_ov013_0220b900, 3, (u8 *)self + 0x108);
            break;
        case 4:
            func_ov013_021fe948(&self->unk_114, &self->unk_fc, data_ov013_0220b930.far, 4, (u8 *)self + 0x108);
            break;
        }
    }
    if (func_ov013_022038a8(self, &self->unk_114, self->unk_fc)) {
        self->unk_108 = self->unk_114;
        self->unk_fa = self->unk_fc;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_0203f364(Ov013Sub48 *p);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern s32 FX_Div(s32 a, s32 b);
extern s32 func_02049130(s32 t, s32 a, s32 b);
extern BOOL func_ov003_021d98bc(Ov013Vec *a, Ov013Vec *b);
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021d9dbc(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(Ov013Actor *self, s32 a, s32 b, s32 c, s32 d);

void func_ov013_021ffc90(Ov013Act_021fea8c *self) {
    BOOL move = FALSE;
    s32 c = 0;
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        move = TRUE;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af04, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *o = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlag(m, 0);
            Ov013_PartFlag(m, 1);
            Ov013_PartFlag(m, 3);
            Ov013_PartFlag(m, 4);
        }
        {
            Ov013Vec v;
            Ov013_VecCopy(&v, &self->pos);
            v.y -= 0xf000;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x100;
            Ov013_VecCopy(&self->unk_b8, &v);
        }
        self->unk_40->state = 1;
        {
            Ov013Sub48 *s = self->unk_48;
            s->unk_9a_0 = 0;
            s->unk_9a_3 = 0;
            func_0203f364(s);
        }
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        break;
    }
    case 1: {
        s32 t;
        s32 sp;
        Ov013Vec v;
        self->unk_40->timer++;
        t = FX_Div(self->unk_40->timer << 12, 0x1e000);
        if (t > 0x1000) {
            c = 0x1000;
        } else if (t >= 0) {
            c = t;
        }
        self->rot[0] = func_02049130(c, 0, 0x4000);
        t = self->unk_9c + 0x30;
        sp = 0;
        if (t > 0x1000) {
            sp = 0x1000;
        } else if (t >= 0) {
            sp = t;
        }
        self->unk_9c = sp;
        v = self->unk_b8;
        if (func_ov003_021d98bc(&v, &self->pos)) {
            self->unk_40->state = 2;
        } else {
            move = TRUE;
        }
        break;
    }
    case 2:
        func_02065804(data_0214a420, self->unk_100);
        self->unk_100 = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        break;
    }
    if (move) {
        Ov013Vec v;
        Ov013_VecCopy(&v, &self->unk_b8);
        func_ov003_021d9dbc(&self->pos, &v, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
    }
}

}
}  // namespace m_021ff924

// ---- merged from ov013_021fffd0.cpp
namespace m_021fffd0 {
extern "C" {

extern void func_ov013_021fe948(Ov013Vec *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude);
extern BOOL func_ov013_02203ea4(Ov013Act_021fea8c *self, Ov013Vec *pos);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0219bf90(void);
extern void func_0203f324(Ov013Sub48 *p);

static inline u32 Ov013_Nearest(const Ov013Vec *p, const Ov013Spot *tbl, u32 n) {
    u32 best = 0;
    u32 i;
    for (i = 0; i < n; i++) {
        if (VEC_Distance(p, &tbl[best].pos) > VEC_Distance(p, &tbl[i].pos)) {
            best = i;
        }
    }
    return best;
}

void func_ov013_021fffd0(Ov013Act_021fea8c *self) {
    if (self->unk_40->state == 0) {
        Ov013Vec p;
        u32 best;
        Ov013Sub48 *m;
        Ov013Actor *pl = func_ov000_0219bf90();
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        switch (self->unk_15d) {
        case 1:
            best = Ov013_Nearest(&p, data_ov013_0220b900, 3);
            self->unk_114 = data_ov013_0220b900[best].pos;
            self->unk_fc = data_ov013_0220b900[best].rot;
            break;
        case 3:
            best = Ov013_Nearest(&p, data_ov013_0220b930.far, 4);
            self->unk_114 = data_ov013_0220b930.far[best].pos;
            self->unk_fc = data_ov013_0220b930.far[best].rot;
            break;
        case 2:
            func_ov013_021fe948(&self->unk_114, &self->unk_fc, data_ov013_0220b900, 3, (u8 *)self + 0x108);
            break;
        case 4:
            func_ov013_021fe948(&self->unk_114, &self->unk_fc, data_ov013_0220b930.far, 4, (u8 *)self + 0x108);
            break;
        }
    }
    if (func_ov013_02203ea4(self, &self->unk_114)) {
        self->unk_108 = self->unk_114;
        self->unk_fa = self->unk_fc;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
    }
}

extern void func_ov013_02202dc8(Ov013Act_021fea8c *self, u16 a, s32 b, BOOL c, u16 d);

void func_ov013_022001b8(Ov013Act_021fea8c *self) {
    BOOL m;
    if (self->unk_15d != 1) {
        m = FALSE;
        if ((u32)self & 3) {
            m = FALSE;
        }
    } else {
        m = TRUE;
    }
    func_ov013_02202dc8(self, 0xa00, 0x1000, m, 0);
}

}
}  // namespace m_021fffd0

// ---- merged from ov013_02200fe8.cpp
namespace m_02200fe8 {
extern "C" {
extern Ov013Game54 *data_ov000_021ccd54;
extern Ov013Actor *func_ov000_0219bf90(void);
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Ov013Actor *func_ov003_021da32c(s32 id);
extern void *func_0206fef8(u16 id);
extern Ov013V *func_02066774(const void *a, const void *b, s32 c, Ov013Vec *pos);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov013_02205bec(Ov013Actor *a, Ov013Vec *v, u16 id, u16 plid, u16 r, u16 rot);
extern u32 func_ov013_02205c64(Ov013Actor *self);
extern s32 func_ov003_021d9a80(const Ov013Vec *a, const Ov013Vec *b);
extern void func_ov000_0218dbe0(Ov013Obj *self, s32 a);
extern void func_ov003_021d88ec(u32 *p);
extern void func_ov003_021d8b60(void *sm, void *arg);
extern void func_ov003_021d969c(void *p, s32 a);

struct Ov013Opt120b {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

static inline void Ov013b_PathTarget(Ov013Act_021fea8c *self, const Ov013Vec &v) {
    Ov013Opt120b *p = ((Ov013Opt120b *)self->unk_120);
    if (p->b0) {
        p->w = v;
    }
}

static inline void Ov013b_PathSpeed(Ov013Act_021fea8c *self, s16 sp) {
    Ov013Opt120b *p = ((Ov013Opt120b *)self->unk_120);
    if (p->b0) {
        p->unk_02 = sp;
    }
}

static inline Ov013Vec Ov013b_FrontPos(Ov013Act_021fea8c *self, const Ov013Vec *off) {
    Ov013Vec v;
    func_ov003_021d9980(&v, self->rot[1], off);
    VEC_Add(&v, &self->pos, &v);
    return v;
}

static inline Ov013Vec Ov013b_Lift(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x900);
    return v;
}

static inline void Ov013b_Set84(Ov013Act_021fea8c *self, const Ov013Vec &v) {
    self->unk_84.x = v.x;
    self->unk_84.y = v.y;
    self->unk_84.z = v.z;
}

static inline void Ov013b_Place(Ov013Act_021fea8c *self, Ov013Actor *o, Ov013Actor *pl, s32 x, u16 dr) {
    u16 rot = self->rot[1];
    Ov013Vec v;
    u16 r;
    v.x = x;
    v.y = 0x4cd;
    v.z = 0;
    r = rot + dr;
    func_ov003_021d9980(&v, self->rot[1], &v);
    VEC_Add(&v, &self->pos, &v);
    func_ov013_02205bec(o, &v, self->id, pl->id, r, self->rot[1]);
}

static inline Ov013Actor *Ov013b_Find(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov013b_PartSet(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b3 = 1;
    }
}

static inline void Ov013b_PartClr(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b3 = 0;
    }
}

static inline void Ov013b_PartB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline void Ov013b_PartsSet(void *m) {
    if (m != NULL) {
        Ov013b_PartSet(m, 0);
        Ov013b_PartSet(m, 1);
        Ov013b_PartSet(m, 3);
        Ov013b_PartSet(m, 4);
    }
}

static inline void Ov013b_PartsClr(void *m) {
    if (m != NULL) {
        Ov013b_PartClr(m, 0);
        Ov013b_PartClr(m, 1);
        Ov013b_PartClr(m, 3);
        Ov013b_PartClr(m, 4);
    }
}

static inline void Ov013b_Fade(void) {
    Ov013Game54 *g = data_ov000_021ccd54;
    g->unk_190_2 = 1;
    g->unk_190_3 = 1;
    g->unk_190_4 = 1;
    g->unk_18d = 10;
    g->unk_18e = 0xf;
    g->unk_18f = 0xf;
}

static inline void Ov013b_Link(Ov013Act_021fea8c *self, u16 *out, s32 kind) {
    Ov013Actor *o = func_ov003_021da32c(kind);
    o->unk_16.b0 = 1;
    o->unk_90 = func_ov000_0219bf90()->id;
    o->unk_4c->target = self->id;
    o->rot[1] = self->rot[1];
    *out = o->id;
}

void func_ov013_022001e4(Ov013Act_021fea8c *self) {
    Ov013Actor *a = NULL;
    Ov013Actor *b = NULL;
    s32 zone = 0;
    BOOL move = FALSE;
    BOOL path = TRUE;
    self->unk_f0.b2 = 1;
    self->unk_f0.b4 = 0;
    switch (self->unk_40->state) {
    case 0: {
        void *info;
        s32 k;
        Ov013V *o;
        void *m;
        move = TRUE;
        self->unk_f0.b3 = 1;
        Ov013b_Link(self, &self->unk_f4, 0x4808);
        Ov013b_Link(self, &self->unk_f6, 0x4809);
        self->unk_a8 = 0x60;
        self->unk_a0 = 0x800;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        Ov013b_Set84(self, Ov013b_Lift(k));
        o = func_02066774(data_ov013_0220aee4, data_ov013_0220aee8, 0, &self->pos);
        FLD(u8, o, 0x28) = 0;
        o->v10(&data_ov013_0220af7c);
        self->rot[0] = 0;
        Ov013b_Fade();
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af08, 0x1000, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 0xa;
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        func_0204a028(data_02097e4c, 0x3c, &self->pos, -5);
        break;
    }
    case 0xa:
        move = TRUE;
        if (self->unk_a0 < 0) {
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e: {
        a = Ov013b_Find(self->unk_f4);
        b = Ov013b_Find(self->unk_f6);
        if (a == NULL || b == NULL) {
            self->unk_40->state = 0x50;
        } else if (a != NULL && b != NULL && a->unk_14 == 2 && b->unk_14 == 2) {
            self->unk_40->state = 0x28;
        }
        break;
    }
    case 0x28:
        Ov013b_PartsClr(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x29;
        func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
        break;
    case 0x29:
        if (self->unk_38->unk_c4 == 2) {
            Ov013Actor *pl;
            a = Ov013b_Find(self->unk_f4);
            b = Ov013b_Find(self->unk_f6);
            pl = func_ov000_0219bf90();
            if (a == NULL || b == NULL || pl == NULL) {
                self->unk_40->state = 0x50;
            } else {
                Ov013Vec v;
                u16 r;
                r = self->rot[1] + 0xbfff;
                v.x = -0x14d1;
                v.y = 0x4cd;
                v.z = 0;
                func_ov003_021d9980(&v, self->rot[1], &v);
                VEC_Add(&v, &self->pos, &v);
                func_ov013_02205bec(a, &v, self->id, pl->id, r, self->rot[1]);
                r = self->rot[1] + 0x4000;
                v.y = 0x4cd;
                v.x = 0x14d1;
                v.z = 0;
                func_ov003_021d9980(&v, self->rot[1], &v);
                VEC_Add(&v, &self->pos, &v);
                func_ov013_02205bec(b, &v, self->id, pl->id, r, self->rot[1]);
            }
            func_0204a028(data_02097e4c, 0x32, &self->pos, 10);
        }
        if (self->unk_38->unk_c4 == 3) {
            Ov013b_PartsSet(self->unk_38);
            self->unk_40->state = 0x32;
        }
        break;
    case 0x32: {
        a = Ov013b_Find(self->unk_f4);
        b = Ov013b_Find(self->unk_f6);
        if (a != NULL && func_ov013_02205c64(a)) {
            Ov013Vec p;
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            if (func_ov003_021d9a80(&self->pos, &p) < 0x9000) {
                a->v08();
                self->unk_f4 = 0xffff;
            }
        }
        if (b != NULL && func_ov013_02205c64(b)) {
            Ov013Vec p;
            p.x = b->pos.x;
            p.y = b->pos.y;
            p.z = b->pos.z;
            if (func_ov003_021d9a80(&self->pos, &p) < 0x9000) {
                b->v08();
                self->unk_f6 = 0xffff;
            }
        }
        if (a == NULL && b == NULL) {
            func_0204a028(data_02097e4c, 0x66, &self->pos, -5);
            self->unk_40->state = 0x3c;
        }
        break;
    }
    case 0x3c:
        move = TRUE;
        Ov013b_PartsClr(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0x4cd;
        self->unk_a4 = 0x1000;
        self->unk_a8 = 0x19a;
        self->unk_40->state = 0x3d;
        break;
    case 0x3d: {
        move = TRUE;
        if (self->pos.y > 0x2000) {
            zone = 0;
        } else if (self->pos.y <= 0x2000 && self->pos.y > 0) {
            zone = 1;
        } else {
            zone = 2;
        }
        if (zone == 1) {
            self->unk_40->state = 0x46;
        } else if (self->unk_38->unk_c4 == 4) {
            Ov013b_PartsSet(self->unk_38);
        }
        break;
    }
    case 0x46: {
        path = FALSE;
        Ov013b_PartsClr(self->unk_38);
        Ov013b_Fade();
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x47;
        {
            Ov013Vec t = Ov013b_FrontPos(self, &data_ov013_0220af34);
            Ov013V *o = func_02066774(data_ov013_0220aee4, data_ov013_0220aee8, 0, &t);
            FLD(u8, o, 0x28) = 0;
            o->v10(&data_ov013_0220af88);
        }
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        func_0204a028(data_02097e4c, 0x3d, &self->pos, -5);
        break;
    }
    case 0x47:
        path = FALSE;
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x14 && func_ov000_02191120(self->unk_38)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x50;
            break;
        }
        if (self->unk_40->timer > 10) {
            Ov013b_PathTarget(self, data_ov013_0220af28);
            Ov013b_PathSpeed(self, 0x180);
        } else {
            Ov013b_PathTarget(self, self->unk_84);
            Ov013b_PathSpeed(self, 0x140);
        }
        break;
    case 0x50: {
        void *m;
        const char *name;
        path = FALSE;
        self->unk_f0.b4 = 1;
        self->unk_f4 = 0xffff;
        self->unk_f6 = 0xffff;
        name = data_ov013_0220aee0;
        func_ov000_02190cb0(self->unk_38, name, 0x800, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), name, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013b_PartB2(m, 0);
            Ov013b_PartB2(m, 1);
            Ov013b_PartB2(m, 3);
            Ov013b_PartB2(m, 4);
        }
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
    if (move) {
        func_ov000_0218dbe0(self, 0);
    }
    if (path) {
        u32 cmd[4];
        func_ov003_021d88ec(cmd);
        cmd[0] = 0x2800;
        func_ov003_021d8b60((u8 *)self + 0x12c, cmd);
    }
}



extern void *data_02097e4c;
extern u8 data_ov013_0220b090[];
extern u8 data_ov013_0220b0cc[];
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov013_02203494(Ov013Act_021fea8c *self, BOOL a, BOOL b, s32 c, void *d);
extern void func_ov003_021d64f0(Ov013Actor *self);

static inline Ov013V *Ov013_SpawnFx(s32 id, const Ov013Vec &pos) {
    return func_02065f88(id, (Ov013Vec *)&pos);
}

static inline Ov013Vec Ov013_FrontPos(Ov013Act_021fea8c *self, const Ov013Vec *off) {
    Ov013Vec v;
    func_ov003_021d9980(&v, self->rot[1], off);
    VEC_Add(&v, &self->pos, &v);
    return v;
}

void func_ov013_02200fe8(Ov013Act_021fea8c *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02191418(self->unk_38, 0x28, 1);
    Ov013_SpawnFx(0x196, Ov013_FrontPos(self, &data_ov013_0220af34))->v0c(0x2000);
    func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
    func_02049f44(data_02097e4c, 0x36, &self->pos, 0);
    self->unk_40->state++;
}

void func_ov013_022010b8(Ov013Act_021fea8c *self) {
    s32 c = 0;
    BOOL a = TRUE;
    BOOL b = TRUE;
    void *d = NULL;
    switch (self->unk_15d) {
    case 1:
        d = data_ov013_0220b090;
        break;
    case 2:
        b = FALSE;
        d = data_ov013_0220b090;
        break;
    case 3:
        a = FALSE;
        d = data_ov013_0220b090;
        break;
    case 4:
        b = FALSE;
        c = 0xd00;
        d = data_ov013_0220b0cc;
        break;
    case 5:
        a = FALSE;
        c = 0xd00;
        d = data_ov013_0220b0cc;
        break;
    case 6:
        d = data_ov013_0220b0cc;
        c = 0xd00;
        break;
    }
    func_ov013_02203494(self, a, b, c, d);
}

void func_ov013_02201144(Ov013Act_021fea8c *self) {
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_18) {
    case 0:
        func_ov003_021d64f0(self);
        break;
    case 1: {
        Ov013Sub40 *s = self->unk_40;
        if (s->state == 0) {
            self->pos.x = -0x212b;
            self->pos.y = 0x2000;
            self->pos.z = -0xb3a2;
            self->rot[1] = 0;
            s->state++;
        } else {
            s->timer++;
            if (self->unk_40->timer > 0x1e) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
    }
}


struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

extern void *data_ov000_021ccd68;
extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b150[];
extern u8 data_ov013_0220b218[];
extern void func_ov003_021d969c(void *p, s32 a);
extern void func_ov003_021d97fc(void *p, s32 a);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern Ov013Actor *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 func_02040528(s32 max);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern s32 func_02049bdc(void *a, s32 b, s32 c);
extern BOOL func_ov000_0218fd84(void *a);
extern BOOL func_ov000_02191508(void *m);
extern void func_ov000_0218dbe0(Ov013Obj *self, s32 a);
extern Ov013V *func_02066774(const void *a, const void *b, s32 c, Ov013Vec *pos);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void *func_0206fef8(u16 id);
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);

static inline Ov013Vec Ov013_MakeVec(s32 x, s32 y, s32 z) {
    Ov013Vec v;
    Ov013_VecSet(&v, x, y, z);
    return v;
}

static inline Ov013Vec Ov013_Lift(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x600);
    return v;
}

static inline void Ov013_PathTarget(Ov013Act_021fea8c *self, const Ov013Vec &v) {
    Ov013Opt120 *p = ((Ov013Opt120 *)self->unk_120);
    if (p->b0) {
        p->w = v;
    }
}

static inline void Ov013_PathSpeed(Ov013Act_021fea8c *self, s16 sp) {
    Ov013Opt120 *p = ((Ov013Opt120 *)self->unk_120);
    if (p->b0) {
        p->unk_02 = sp;
    }
}

void func_ov013_022011ec(Ov013Act_021fea8c *self) {
    self->unk_48->unk_9a_4 = 1;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        u16 ang;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        func_ov003_021d97fc((u8 *)self + 0x14c, 1);
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af00, 0x800, 1);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        func_ov000_02191418(self->unk_38, 5, 1);
        if (((void *)self->unk_50) != NULL) {
            Ov013Actor *a = func_ov000_02199f60(((void *)self->unk_50));
            if (a != NULL && a != self) {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            } else {
                ang = self->rot[1];
            }
        } else {
            ang = self->rot[1];
        }
        self->unk_96 = ang;
        self->unk_98 = self->unk_96 + 0x8000 + func_02040528(0x2000);
        self->rot[1] = func_01ffc128(self->unk_96, self->rot[1], 0x8cd, 1, 0x8000);
        self->unk_9c = 0x27b;
        self->unk_a0 = 0x39a;
        self->unk_a4 = 0xcb8;
        self->unk_a8 = 0x52;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4808, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4809, 0x15);
        func_02049bdc(data_02097e4c, 0x41, 4);
        if (self->pos.y - 0x2000 > 0x2000) {
            self->unk_40->state = 0x14;
        } else {
            self->unk_40->state = 0xa;
        }
        break;
    }
    case 0xa:
        if (self->unk_48->unk_50 & 0x20000000) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            if (func_ov000_0218fd84(func_ov000_02190a30(self->unk_38, 0))) {
                self->unk_40->state = 0x64;
            }
            break;
        }
        if (!func_ov000_02191508(self->unk_38)) {
            func_ov000_0218dbe0(self, 0);
        }
        break;
    case 0x14:
        if (self->unk_48->unk_50 & 0x20000000) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state = 0x1e;
            break;
        }
        if (!func_ov000_02191508(self->unk_38)) {
            func_ov000_0218dbe0(self, 0);
        }
        break;
    case 0x1e: {
        Ov013Vec t = Ov013_FrontPos(self, &data_ov013_0220af34);
        Ov013V *o;
        void *info;
        s32 k;
        o = func_02066774(data_ov013_0220aee4, data_ov013_0220aee8, 0, &t);
        FLD(u8, o, 0x28) = 0;
        o->v10(&data_ov013_0220af88);
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        func_0204a028(data_02097e4c, 0x3d, &self->pos, -5);
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        {
            Ov013Vec w2 = Ov013_Lift(k);
            self->unk_84.x = w2.x;
            self->unk_84.y = w2.y;
            self->unk_84.z = w2.z;
        }
        self->unk_40->state = 0x1f;
    }
    case 0x1f:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0xf && func_ov000_02191120(self->unk_38)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x64;
            break;
        }
        if (self->unk_40->timer > 6) {
            Ov013_PathTarget(self, data_ov013_0220af28);
            Ov013_PathSpeed(self, 0x280);
        } else {
            Ov013_PathTarget(self, self->unk_84);
            Ov013_PathSpeed(self, 0x240);
        }
        break;
    case 0x64: {
        s32 r = (self->unk_50[0] << 12) / self->unk_50[1];
        if (r <= 0x666) {
            if (func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b218) || func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b150)) {
                func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b108, 0xc);
            } else if (func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b03a)) {
                func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b064, 7);
            }
        } else if (r <= 0xccd) {
            if (func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b150)) {
                func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b218, 0x14);
            }
        }
        func_ov003_021d97fc((u8 *)self + 0x14c, 0);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

extern void *data_0214a420;
extern void func_02065804(void *a, s32 b);
extern void func_02065860(void *a, s32 b);
extern void func_0203f364(Ov013Sub48 *p);
extern Ov013Vec func_ov003_021da214(Ov013Actor *self);
extern void *func_ov003_021da4a8(Ov013Vec *pos, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov013Actor *self, u8 a);

#define OV013_CLAMP(x, lo, hi) ((x) > (hi) ? (hi) : ((x) < (lo) ? (lo) : (x)))

void func_ov013_022017f8(Ov013Act_021fea8c *self) {
    self->unk_48->unk_9a_4 = 1;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        Ov013Sub48 *m48;
        Ov013Sub44 *n;
        u16 ang;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af00, 0x800, 1);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        func_ov000_02191418(self->unk_38, 5, 1);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x483e, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4808, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4809, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4807, 0x15);
        func_02065804(data_0214a420, self->unk_100);
        self->unk_50[0] = 0;
        m48 = self->unk_48;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_4c->target = 0xffff;
        self->unk_9c = 0x27b;
        self->unk_a0 = 0x39a;
        self->unk_a4 = 0xcb8;
        self->unk_a8 = 0x52;
        if (((void *)self->unk_50) != NULL) {
            Ov013Actor *a = func_ov000_02199f60(((void *)self->unk_50));
            if (a != NULL && a != self) {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            } else {
                ang = self->rot[1];
            }
        } else {
            ang = self->rot[1];
        }
        self->unk_96 = ang;
        self->unk_98 = self->unk_96 + 0x8000 + func_02040528(0x2000);
        self->unk_9c = 0x27b;
        self->unk_a0 = 0;
        self->unk_a4 = 0xcb8;
        self->unk_a8 = 0x52;
        self->unk_40->state = 0xa;
        break;
    }
    case 0xa:
        if (self->unk_48->unk_50 & 0x20000000) {
            Ov013Vec p = func_ov003_021da214(self);
            Ov013V *o = func_02065f88(0x390, &self->pos);
            if (o != NULL) {
                self->unk_100 = FLD(s32, o, 0x24);
                o->v20(&p);
                o->v0c(0x1800);
            }
            o = func_02065f88(0x69, &self->pos);
            if (o != NULL) {
                o->v20(&p);
                o->v0c(0x5000);
            }
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_ov000_0218996c(0xc, 0x28);
            self->unk_40->state = 0x14;
        }
    case 0x14: {
        Ov013Sub40 *q = self->unk_40;
        u16 t;
        q->timer++;
        t = q->timer;
        if (t >= 0x78) {
            if (t % 30 == 0) {
                Ov013Vec a = func_ov003_021da214(self);
                Ov013Vec b;
                VEC_Add(&self->pos, &a, &b);
                func_ov003_021da4a8(&b, self->unk_64, 0x38b);
                func_ov000_0218996c(8, 8);
                func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
            }
            if (t >= 0x12b) {
                func_ov000_0218996c(0x14, 0x78);
                self->unk_40->timer = 0;
                self->unk_40->state = 0x1e;
            }
        } else {
            if (t % 25 == 0) {
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
            if (t == 0x6e) {
                func_02065860(data_0214a420, self->unk_100);
                self->unk_100 = 0;
            }
        }
        break;
    }
    case 0x1e: {
        Ov013Vec p = func_ov003_021da214(self);
        Ov013V *o = func_02065f88(0x38b, &self->pos);
        if (o != NULL) {
            o->v20(&p);
            o->v0c(0x3000);
        }
        o = func_02065f88(0x69, &self->pos);
        if (o != NULL) {
            o->v20(&p);
            o->v0c(0x5000);
            FLD(s32, o, 0x3c) = 0xccd;
        }
        func_0204a028(data_02097e4c, 0x56, &self->pos, -8);
        func_0204a028(data_02097e4c, 0x41, &self->pos, 4);
        self->unk_40->state = 0x64;
        break;
    }
    case 0x64:
        self->unk_f0.b2 = 1;
        {
            Ov013Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer > 0x78) {
                func_ov003_021d6a3c(self, 1, 1, 1);
                break;
            }
        }
        {
            s32 a = 0x1f - (self->unk_40->timer >> 1);
            func_ov003_021d6954(self, OV013_CLAMP(a, 1, 0x1f));
        }
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    if (self->unk_48->unk_50 & 0x20000000) {
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    } else {
        func_ov000_0218dbe0(self, 0);
    }
}

struct Ov013Obj1c;
typedef void (*Ov013OffFn)(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);

struct Ov013Obj1c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    u32 unk_04;
    Ov013Vec v;
    Ov013Actor *unk_14;
    Ov013OffFn unk_18;
};

extern void func_ov013_02204428(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);
extern void func_ov013_02204408(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);
extern s32 func_ov003_021d9edc(u16 kind);
extern void func_ov003_021d96e0(void *p);
extern s32 func_ov013_021fe9f8(Ov013Actor **out, s32 max, u16 kind, Ov013Vec *pos, s32 dist);
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013V *func_020657b0(void *a, s32 b);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline Ov013Vec Ov013_Lift2(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x480);
    return v;
}

struct Ov013ObjHdr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};
static inline BOOL Ov013Obj_IsIdle2(const Ov013ObjHdr &h) {
    BOOL r = TRUE;
    if (h.b0 && h.b1) {
        r = FALSE;
    }
    return r;
}
static inline BOOL Ov013Obj_IsIdle(Ov013Obj1c *q) {
    return Ov013Obj_IsIdle2(*(Ov013ObjHdr *)q);
}

static inline void Ov013Obj_SetSpeed(Ov013Obj1c *q, s16 sp) {
    if (q->b0 && !Ov013Obj_IsIdle(q)) {
        q->unk_02 = sp;
    }
}
static inline void Ov013Obj_SetVec(Ov013Obj1c *q, s32 x, s32 y, s32 z) {
    if (q->b0 && !Ov013Obj_IsIdle(q)) {
        q->v.x = x;
        q->v.y = y;
        q->v.z = z;
    }
}
static inline void Ov013Obj_SetFn(Ov013Obj1c *q, Ov013OffFn fn) {
    if (q->b0 && !Ov013Obj_IsIdle(q)) {
        q->unk_18 = fn;
    }
}

static inline void Ov013Obj_Start(Ov013Obj1c *q, Ov013Actor *owner, s16 sp, const Ov013Vec *v, Ov013OffFn fn) {
    if (q->b0 && !q->b1) {
        q->b0 = 0;
        q->b1 = 0;
        q->unk_02 = sp;
        q->unk_04 = 0;
        q->v.x = v->x;
        q->v.y = v->y;
        q->v.z = v->z;
        q->unk_18 = fn;
        q->b0 = 1;
        q->b1 = 1;
        q->unk_14 = owner;
    }
}

static inline s32 Ov013_Mode(Ov013Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

static inline BOOL Ov013_IsMarked(Ov013Actor *a) {
    if (a == NULL) {
        return FALSE;
    }
    if (a->kind != 0x483e) {
        return FALSE;
    }
    if (Ov013_Mode(a) != 0xb) {
        return FALSE;
    }
    if (func_ov000_0219bf90() == NULL) {
        return FALSE;
    }
    u16 id = func_ov000_0219bf90()->id;
    if (id != a->unk_4c->target) {
        return FALSE;
    }
    return TRUE;
}

void func_ov013_02201de8(Ov013Act_021fea8c *self) {
    Ov013Actor *list[8];
    self->unk_f0.b2 = 1;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        Ov013Obj1c *q;
        Ov013V *o;
        void *info;
        s32 k;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af10, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        Ov013Obj_Start(((Ov013Obj1c *)self->unk_124), self, 0x1000, &data_ov013_0220af28, func_ov013_02204428);
        Ov013Obj_SetSpeed(((Ov013Obj1c *)self->unk_124), 0x3000);
        Ov013Obj_SetVec(((Ov013Obj1c *)self->unk_124), 0, 0, -0x3000);
        Ov013Obj_SetFn(((Ov013Obj1c *)self->unk_124), func_ov013_02204408);
        self->rot[0] = 0;
        self->rot[2] = 0;
        func_0204a028(data_02097e4c, 0x44, &self->pos, 3);
        o = func_02065f88(0x69, &self->pos);
        o->v0c(0x2000);
        func_02065804(data_0214a420, self->unk_100);
        self->unk_100 = FLD(s32, o, 0x24);
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        {
            Ov013Vec w2 = Ov013_Lift2(k);
            Ov013Sub48 *m48;
            self->unk_84.x = w2.x;
            self->unk_84.y = w2.y;
            self->unk_84.z = w2.z;
            m48 = self->unk_48;
            m48->unk_9a_0 = 0;
            m48->unk_9a_3 = 0;
            func_0203f364(m48);
        }
        self->unk_40->state = 1;
    }
    case 1: {
        s32 n;
        s32 i;
        BOOL found;
        Ov013V *p;
        if (!func_ov003_021d9edc(0x483e)) {
            func_ov003_021d96e0((u8 *)self + 0x14c);
            self->unk_40->state = 2;
            break;
        }
        n = func_ov013_021fe9f8(list, 8, 0x483e, &self->pos, Ov013_FxMul(self->unk_64, self->unk_38->unk_a8) / 2 + 0x5000);
        found = FALSE;
        for (i = 0; i < n; i++) {
            if (Ov013_IsMarked(list[i])) {
                found = TRUE;
                break;
            }
        }
        if (found) {
            func_ov003_021d97fc((u8 *)self + 0x14c, 1);
            func_ov003_021d96e0((u8 *)self + 0x14c);
            func_ov000_02198360(self->unk_40, 0x31, 1);
        }
        p = func_020657b0(data_0214a420, self->unk_100);
        if (p == NULL) {
            self->unk_100 = 0;
        } else {
            p->v34(FLD(u16, p, 0x64), (u16)(FLD(u16, p, 0x66) + 0x400), FLD(u16, p, 0x68));
        }
        break;
    }
    }
    self->unk_f0.b1 = 1;
    Ov013_PathSpeed(self, 0x100);
    Ov013_PathTarget(self, self->unk_84);
}

extern void func_ov000_0218d398(Ov013Actor *t, u16 id, s32 a, s32 b, s32 c, void *arg);

static inline Ov013Vec Ov013_Lift3(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x900);
    return v;
}

struct Ov013HitArg {
    u8 a;
};

static inline void Ov013_Hit(Ov013Actor *t, Ov013Actor *self) {
    Ov013HitArg arg;
    arg.a = 1;
    t->unk_90 = func_ov000_0219bf90()->id;
    func_ov000_0218d398(t, self->id, 0xe, 0, 1, &arg);
}

void func_ov013_02202394(Ov013Act_021fea8c *self) {
    self->unk_f0.b2 = 1;
    self->unk_f0.b0 = true;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        void *info;
        s32 k;
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        Ov013b_Set84(self, Ov013_Lift3(k));
        Ov013_PathSpeed(self, 0x19a);
        func_ov003_021d97fc((u8 *)self + 0x14c, 1);
        func_ov000_02190cb0(self->unk_38, data_ov013_0220aefc, 0x800, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *q = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, q, FLD(void *, FLD(void *, q, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 0xa;
        func_02049f44(data_02097e4c, 0x65, &self->pos, 0);
        break;
    }
    case 0xa:
        Ov013_PathTarget(self, self->unk_84);
        if (self->unk_38->unk_c4 == 2) {
            self->unk_40->state = 0x14;
        }
        break;
    case 0x14:
        Ov013_PathTarget(self, data_ov013_0220af28);
        if (func_ov000_0218fd84(func_ov000_02190a30(self->unk_38, 0))) {
            self->unk_40->state = 0x28;
        }
        break;
    case 0x28: {
        s32 r = (self->unk_50[0] << 12) / self->unk_50[1];
        if (r <= 0x666) {
            self->unk_f8 = 0xaf;
        } else {
            self->unk_f8 = 0x118;
        }
        func_ov000_02198360(self->unk_40, 0x32, 0);
        break;
    }
    }
    if (self->unk_38->unk_c4 == 3) {
        Ov013Vec t = Ov013_FrontPos(self, &data_ov013_0220af34);
        Ov013V *o = func_02066774(data_ov013_0220aee4, data_ov013_0220aee8, 0, &t);
        FLD(u8, o, 0x28) = 0;
        o->v10(&data_ov013_0220af88);
    }
    if (self->unk_38->unk_c4 != 1) {
        return;
    }
    {
    Ov013Actor *list[8];
    Ov013Vec p;
    s32 n;
    s32 i;
    BOOL hit;
    n = func_ov013_021fe9f8(list, 8, 0x483e, &self->pos, Ov013_FxMul(self->unk_64, self->unk_38->unk_a8) / 2 + 0x4000);
    hit = FALSE;
    for (i = 0; i < n; i++) {
        if (Ov013_Mode(list[i]) != 0x15) {
            Ov013HitArg arg;
            Ov013V *e;
            arg.a = 1;
            list[i]->unk_90 = func_ov000_0219bf90()->id;
            func_ov000_0218d398(list[i], self->id, 0xe, 0, 1, &arg);
            p = list[i]->pos;
            e = func_02065f88(0x6d, &p);
            e->v34(0x4000, (u16)(list[i]->rot[1] + 0x7fff), 0);
            e->v0c(0x4000);
            hit = TRUE;
        }
    }
    if (hit) {
        func_ov000_02191418(self->unk_38, 3, 1);
        func_0204a028(data_02097e4c, 0x2c, &self->pos, -3);
    }
    }
}

extern void func_0203f324(Ov013Sub48 *p);
extern const Ov013Vec data_ov013_0220afd0;
extern const Ov013Vec data_ov013_0220afdc;

static inline void Ov013c_Anim(Ov013Act_021fea8c *self, const char *nm, s32 sp, s32 loop) {
    void *m;
    func_ov000_02190cb0(self->unk_38, nm, sp, loop);
    m = self->unk_38;
    if (FLD(void *, m, 0x14) != NULL) {
        void *p = FLD(void *, m, 0);
        func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), nm, 0x1000, 0);
    }
}

static inline void Ov013c_Parts(Ov013Act_021fea8c *self) {
    void *m;
    FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
    m = self->unk_38;
    if (m != NULL) {
        Ov013_PartFlagB2(m, 0);
        Ov013_PartFlagB2(m, 1);
        Ov013_PartFlagB2(m, 3);
        Ov013_PartFlagB2(m, 4);
    }
}

void func_ov013_02202800(Ov013Act_021fea8c *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov013Sub48 *m48;
        Ov013c_Anim(self, data_ov013_0220aee0, 0x266, 1);
        Ov013c_Parts(self);
        self->unk_40->timer = 0;
        self->unk_40->state = 0xa;
        m48 = self->unk_48;
        m48->unk_9a_0 = true;
        m48->unk_9a_3 = 1;
        func_0203f324(m48);
    }
    case 0xa: {
        Ov013Sub40 *q = self->unk_40;
        if (q->timer >= self->unk_f8 - 0x3c) {
            q->state = 0x14;
        } else {
            self->unk_f0.b2 = 1;
            FLD(u16, func_ov000_02190a30(self->unk_38, 0), 0x112) = 0x800;
            FLD(u16, func_ov000_02190a30(self->unk_38, 2), 0x112) = 0x800;
            self->unk_40->timer++;
            break;
        }
    }
    case 0x14: {
        Ov013Vec a = data_ov013_0220afd0;
        Ov013Vec b = data_ov013_0220afdc;
        Ov013Vec v;
        Ov013V *o;
        func_ov003_021d9980(&v, self->rot[1], &b);
        VEC_Add(&v, &self->pos, &v);
        o = func_02065f88(0x25d, &v);
        o->v10(&a);
        o->v34(0, self->rot[1], 0);
        self->unk_40->state = 0x15;
    }
    case 0x15: {
        Ov013Sub40 *q = self->unk_40;
        if (q->timer >= self->unk_f8) {
            q->timer = 0;
            self->unk_40->state = 0x64;
        } else {
            FLD(u16, func_ov000_02190a30(self->unk_38, 0), 0x112) = 0x1000;
            FLD(u16, func_ov000_02190a30(self->unk_38, 2), 0x112) = 0x1000;
            self->unk_40->timer++;
            break;
        }
    }
    case 0x64:
        Ov013c_Anim(self, data_ov013_0220aee0, 0x266, 1);
        Ov013c_Parts(self);
        func_ov003_021d97fc((u8 *)self + 0x14c, 0);
        break;
    }
}
}
}  // namespace m_02200fe8

// ---- merged from ov013_02202c88.cpp
namespace m_02202c88 {
extern "C" {

extern void *data_ov000_021ccd68;
extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b218[];
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);

void func_ov013_02202c88(Ov013Act_021fea8c *self) {
    void *tbl = NULL;
    s32 n = 0;
    switch (self->unk_15d) {
    case 1:
        tbl = data_ov013_0220b03a;
        n = 7;
        break;
    case 2:
        tbl = data_ov013_0220b064;
        n = 7;
        break;
    }
    if (!func_ov003_021d984c((u8 *)self + 0x14c, tbl)) {
        func_ov003_021d95e8((u8 *)self + 0x14c, tbl, n);
    }
}

void func_ov013_02202cec(Ov013Act_021fea8c *self) {
    void *tbl = NULL;
    s32 n = 0;
    switch (self->unk_15d) {
    case 1:
        tbl = data_ov013_0220b218;
        n = 0x14;
        break;
    case 2:
        tbl = data_ov013_0220b108;
        n = 0xc;
        break;
    }
    if (!func_ov003_021d984c((u8 *)self + 0x14c, tbl)) {
        func_ov003_021d95e8((u8 *)self + 0x14c, tbl, n);
    }
}

void func_ov013_02202d50(Ov013Act_021fea8c *self) {
    BOOL f = FALSE;
    Ov013Actor *a;
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x483e);
    }
    if (a != NULL) {
        u8 k;
        if (a->unk_40 != NULL) {
            k = a->unk_40->unk_13;
        } else {
            k = 0;
        }
        if (k == 9) {
            f = TRUE;
        }
    }
    if (!f) {
        func_ov003_021d969c((u8 *)self + 0x14c, 0);
    } else {
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
    }
}


extern void *data_02097e4c;
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013Actor *func_ov003_021da32c(u16 kind);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov013_02204910(Ov013Actor *self, u16 a, u16 b, u16 c, u16 d);
extern void func_ov013_0220498c(Ov013Actor *self, s32 a);
extern void func_ov013_02204978(Ov013Actor *self, u16 a);
extern u32 func_ov013_02204968(Ov013Actor *self);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline void Ov013_PartFlagB3(void *m, s32 i, s32 v) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b3 = v;
    }
}

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_02202dc8(Ov013Act_021fea8c *self, u16 a, s32 b, BOOL c, u16 d) {
    self->unk_f0.b4 = 0;
    switch (self->unk_40->state) {
    case 0: {
        Ov013Actor *o;
        const char *anim;
        void *m;
        self->unk_90 = func_ov000_0219bf90()->id;
        o = func_ov003_021da32c(0x483e);
        o->unk_16.b0 = 1;
        self->unk_f2 = o->id;
        anim = data_ov013_0220aee0;
        func_ov000_02190cb0(self->unk_38, anim, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), anim, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->unk_40->state = 0x1e;
        break;
    }
    case 0x1e: {
        void *m;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220aef4, 0x1000, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 0x1f;
        break;
    }
    case 0x1f: {
        Ov013Actor *t;
        Ov013Actor *o;
        Ov013Vec v;
        void *m;
        t = Ov013_FindActor(self->unk_90);
        if (t != NULL) {
            func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        }
        if (self->unk_38->unk_c4 != 1) {
            break;
        }
        o = Ov013_FindActor(self->unk_f2);
        self->unk_f0.b3 = 0;
        func_ov003_021d9980(&v, self->rot[1], data_ov013_0220af40);
        VEC_Add(&v, &self->pos, &v);
        o->pos.x = v.x;
        o->pos.y = v.y;
        o->pos.z = v.z;
        func_ov013_02204910(o, self->id, self->unk_90, self->rot[1], a);
        func_ov013_0220498c(o, b);
        if (c) {
            func_ov013_02204978(o, d);
        }
        func_02065f88(0x57a, &self->pos)->v0c(0x2800);
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB3(m, 0, 1);
            Ov013_PartFlagB3(m, 1, 1);
            Ov013_PartFlagB3(m, 3, 1);
            Ov013_PartFlagB3(m, 4, 1);
        }
        func_0204a028(data_02097e4c, 0x2b, &self->pos, -5);
        self->unk_40->state = 0x28;
        break;
    }
    case 0x28: {
        Ov013Actor *o = Ov013_FindActor(self->unk_f2);
        Ov013Actor *t = Ov013_FindActor(self->unk_90);
        Ov013Vec v;
        if (o == NULL || t == NULL) {
            self->unk_f0.b5 = 1;
            self->unk_40->state = 0x3c;
            break;
        }
        if (o->unk_4c != NULL && t->id == o->unk_4c->target) {
            self->unk_f0.b5 = 0;
            self->unk_40->state = 0x3c;
            break;
        }
        if (!func_ov013_02204968(o)) {
            break;
        }
        self->unk_f0.b5 = 1;
        v.x = o->pos.x;
        v.y = o->pos.y;
        v.z = o->pos.z;
        if (VEC_Distance(&self->pos, &v) >= 0x3000) {
            break;
        }
        func_0204a028(data_02097e4c, 0x66, &self->pos, -5);
        self->unk_f0.b3 = 1;
        o->v08();
        self->unk_40->state = 0x3c;
        break;
    }
    case 0x3c: {
        void *m;
        func_ov003_021d969c((u8 *)self + 0x14c, self->unk_f0.b5);
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB3(m, 0, 0);
            Ov013_PartFlagB3(m, 1, 0);
            Ov013_PartFlagB3(m, 3, 0);
            Ov013_PartFlagB3(m, 4, 0);
        }
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        self->unk_f2 = 0xffff;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

extern s32 func_ov000_0218fd84(void *p);
extern void func_ov013_022065d8(Ov013Actor *o, u16 a);
extern void func_ov013_022065e0(Ov013Actor *o, s32 a);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);

struct Ov013Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov013_02203494(Ov013Act_021fea8c *self, BOOL a, BOOL b, u16 c, s32 d) {
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af14, 0x1000, 1);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 10;
        break;
    }
    case 10:
        func_ov000_0218d988(self, Ov013_FindActor(self->unk_90), 0x80);
        if ((u16)(s16)(self->unk_38->unk_c4 - 1) <= 1) {
            self->unk_40->state = 20;
        }
    case 20: {
        u16 rot = self->rot[1];
        BOOL fire = FALSE;
        if (b && self->unk_38->unk_c4 == 1) {
            rot = self->rot[1] + 0x1555;
            fire = TRUE;
        }
        if (a && self->unk_38->unk_c4 == 2) {
            rot = self->rot[1] + 0xeaaa;
            fire = TRUE;
        }
        if (fire) {
            Ov013Vec v;
            Ov013Vec w;
            Ov013Actor *o;
            void *m = self->unk_38;
            v.x = FLD(s16, m, 0xc6) << 4;
            v.y = FLD(s16, m, 0xc8) << 4;
            v.z = FLD(s16, m, 0xca) << 4;
            if (self != NULL) {
                func_ov003_021d9980(&v, self->rot[1], &v);
            }
            {
                Ov013Rot3 r = {0, 0, 0};
                r.y = rot;
                VEC_Add(&self->pos, &v, &w);
                o = func_ov003_021da32c(0x4807);
                o->pos.x = w.x;
                o->pos.y = w.y;
                o->pos.z = w.z;
                *(Ov013Rot3 *)o->rot = r;
            }
            o->unk_90 = self->unk_90;
            o->unk_4c->target = self->id;
            o->unk_60 = d;
            func_ov013_022065d8(o, c);
            func_ov013_022065e0(o, 1);
            o->unk_16.b0 = 1;
            func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
        }
        if (func_ov000_0218fd84(func_ov000_02190a30(self->unk_38, 0))) {
            self->unk_40->state = 100;
        }
        break;
    }
    case 100: {
        void *m;
        const char *anim;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        anim = data_ov013_0220aee0;
        func_ov000_02190cb0(self->unk_38, anim, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), anim, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        break;
    }
    }
}
}
}  // namespace m_02202c88

// ---- merged from ov013_022038a8.cpp
namespace m_022038a8 {
extern "C" {

extern const Ov013Vec data_ov013_0220afe8;
extern void *data_02097e4c;
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern BOOL func_ov003_021d98bc(Ov013Vec *a, Ov013Vec *b);
extern void func_ov003_021d9dbc(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d8afc(void *p);
extern u16 func_ov003_021d9c38(Ov013Vec *v);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline s32 Ov013_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov013_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline Ov013Vec Ov013_Around(const Ov013Vec *base, u16 r) {
    Ov013Vec v;
    Ov013Vec t = data_ov013_0220afe8;
    func_ov003_021d9980(&v, r, &t);
    VEC_Add(&v, base, &v);
    return v;
}

static inline void Ov013_VecSubYZ(Ov013Vec *o, const Ov013Vec *a, const Ov013Vec *b) {
    s32 y = a->y;
    s32 z = a->z;
    o->x = a->x - b->x;
    o->y = y - b->y;
    o->z = z - b->z;
}

BOOL func_ov013_022038a8(Ov013Act_021fea8c *self, const Ov013Vec *pos, u16 rot) {
    BOOL ret = FALSE;
    BOOL move = TRUE;
    BOOL turn = TRUE;
    s32 rate = 0x400;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        move = FALSE;
        turn = FALSE;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af04, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->rot[0] = 0;
        self->rot[2] = 0;
        self->unk_40->state = 10;
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        break;
    }
    case 10:
    case 11: {
        rate = 0x80;
        if (self->unk_40->state == 10) {
            Ov013Vec c = Ov013_Around(&self->unk_108, self->unk_fa);
            Ov013_VecCopy(&self->unk_b8, &c);
            self->unk_40->state = 11;
        }
        self->unk_9c += 0x40;
        self->unk_9c = Ov013_Clamp(self->unk_9c, 0, 0x2000);
        {
            Ov013Vec w;
            Ov013_VecCopy(&w, &self->unk_b8);
            if (func_ov003_021d98bc(&w, &self->pos)) {
                func_ov003_021d8afc((u8 *)self + 0x12c);
                self->unk_40->state = 20;
            }
        }
        break;
    }
    case 20:
    case 21: {
        rate = 0x300;
        if (self->unk_40->state == 20) {
            Ov013Vec c = Ov013_Around(pos, rot);
            Ov013_VecCopy(&self->unk_b8, &c);
            self->unk_f0.b3 = 1;
            self->unk_40->state = 21;
        }
        {
            Ov013Vec w;
            Ov013_VecCopy(&w, &self->unk_b8);
            if (VEC_Distance(&w, &self->pos) < 0x6000) {
                self->unk_9c = Ov013_FxMul64(self->unk_9c, 0xe00);
            } else {
                self->unk_9c += 0x100;
                self->unk_9c = Ov013_Clamp(self->unk_9c, 0, 0x4000);
            }
            if (func_ov003_021d98bc(&w, &self->pos) || self->unk_9c < 0x10) {
                self->unk_40->state = 30;
            }
        }
        break;
    }
    case 30:
    case 31: {
        Ov013Vec w;
        rate = 0x180;
        if (self->unk_40->state == 30) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_ov003_021d8a7c((u8 *)self + 0x12c, 0);
            Ov013_VecCopy(&self->unk_b8, pos);
            self->unk_40->state = 31;
        }
        Ov013_VecCopy(&w, &self->unk_b8);
        if (VEC_Distance(&w, &self->pos) < 0x7000) {
            self->unk_9c = Ov013_FxMul64(self->unk_9c, 0xf00);
            turn = FALSE;
        } else {
            self->unk_9c += 0xa0;
            self->unk_9c = Ov013_Clamp(self->unk_9c, 0, 0xa00);
        }
        if (func_ov003_021d98bc(&w, &self->pos) || self->unk_9c < 8) {
            self->unk_40->state = 40;
            turn = FALSE;
            func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        }
        break;
    }
    case 40:
        move = FALSE;
        turn = FALSE;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        ret = TRUE;
        break;
    }
    if (move) {
        Ov013Vec w;
        Ov013_VecCopy(&w, &self->unk_b8);
        func_ov003_021d9dbc(&self->pos, &w, &self->pos, self->unk_9c, 0);
    }
    if (turn) {
        Ov013Vec d;
        Ov013_VecSubYZ(&d, &self->unk_b8, &self->pos);
        self->rot[1] = func_01ffc128(func_ov003_021d9c38(&d), self->rot[1], rate, 1, 0x8000);
    }
    return ret;
}

}
}  // namespace m_022038a8

// ---- merged from ov013_02203ea4.cpp
namespace m_02203ea4 {
extern "C" {

extern void *data_02097e4c;
extern void *data_0214a420;
extern Ov013Actor *func_ov000_0219bf90(void);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_02065804(void *a, s32 b);
extern u16 FX_Atan2(s32 y, s32 x);
extern BOOL func_ov003_021d98bc(Ov013Vec *a, Ov013Vec *b);
extern void func_ov003_021d9dbc(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(Ov013Actor *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d8a7c(void *p, s32 a);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline s32 Ov013_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

BOOL func_ov013_02203ea4(Ov013Act_021fea8c *self, const Ov013Vec *dst) {
    BOOL ret = FALSE;
    BOOL move = FALSE;
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        Ov013V *o;
        Ov013Vec v;
        Ov013_VecCopy(&v, dst);
        Ov013_VecCopy(&self->unk_b8, &v);
        self->pos.x = v.x;
        self->pos.z = v.z;
        self->pos.y = v.y - 0xf000;
        move = TRUE;
        self->rot[0] = 0xbfff;
        o = func_02065f88(0x2bd, (Ov013Vec *)dst);
        o->v0c(0x3000);
        FLD(s32, o, 0xc8) = -1;
        self->unk_100 = FLD(s32, o, 0x24);
        self->unk_9c = 0x900;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov003_021d8a7c((u8 *)self + 0x12c, 0);
        func_ov000_02190cb0(self->unk_38, data_ov013_0220af04, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), data_ov013_0220aee0, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->unk_40->state = 10;
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        break;
    }
    case 10:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x4b) {
            self->unk_40->timer = 0;
            self->unk_40->state = 20;
        }
        break;
    case 20: {
        Ov013Actor *a = func_ov000_0219bf90();
        u16 r;
        if (a == NULL || a == self) {
            r = self->rot[1];
        } else {
            r = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        self->rot[1] = r;
        self->unk_40->state = 21;
        break;
    }
    case 21: {
        Ov013Vec w;
        Ov013_VecCopy(&w, &self->unk_b8);
        move = TRUE;
        if (func_ov003_021d98bc(&w, &self->pos) || self->unk_9c < 0x40) {
            self->unk_40->state = 100;
        } else if (VEC_Distance(&w, &self->pos) < 0x5000) {
            self->unk_9c = Ov013_FxMul64(self->unk_9c, 0xf00);
        }
        break;
    }
    case 100:
        func_02065804(data_0214a420, self->unk_100);
        self->unk_100 = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        ret = TRUE;
        break;
    }
    if (move) {
        Ov013Vec w;
        Ov013_VecCopy(&w, &self->unk_b8);
        func_ov003_021d9dbc(&self->pos, &w, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
    }
    return ret;
}
}
}  // namespace m_02203ea4

// ---- merged from ov013_022043f8.cpp
namespace m_022043f8 {
struct Ov013Cam {
    u8 unk_00[0x4];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 id;
    Ov013Vec min;
    Ov013Vec max;
    Ov013Vec off;
};


struct Ov013Pair32 {
    s32 a;
    s32 b;
};

extern "C" {

extern void *data_ov013_0220bbb8[];
extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void *func_ov000_02194074(void *self);
extern void *func_ov003_021cf2bc(void *p);
extern void *func_ov003_021cf2d8(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218e9c4(void *p);
extern void func_ov000_0219433c(void *self);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(void *p);

extern void *data_ov000_021ccd68;
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern u8 *func_ov000_0219bf90(void);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov013_RotY(Ov013Vec *out, const Ov013Vec *v, Ov013Actor *a) {
    if (a != NULL) {
        func_ov003_021d9980(out, a->rot[1], v);
    }
}


void func_ov013_0220428c(Ov013Cam *self) {
    Ov013Actor *t;
    u8 *pl;
    Ov013Vec p;
    Ov013Vec o;
    if (!self->b0) {
        return;
    }
    t = Ov013_FindActor(self->id);
    pl = func_ov000_0219bf90();
    if (t == NULL || pl == NULL) {
        return;
    }
    p = t->pos;
    Ov013_RotY(&o, data_ov013_0220af58, t);
    VEC_Add(&p, &o, &p);
    VEC_Add(&p, &self->off, &p);
    self->off = data_ov013_0220af28;
    if (self->b1) {
        p.x = p.x > self->max.x ? self->max.x : (p.x < self->min.x ? self->min.x : p.x);
        p.y = p.y > self->max.y ? self->max.y : (p.y < self->min.y ? self->min.y : p.y);
        p.z = p.z > self->max.z ? self->max.z : (p.z < self->min.z ? self->min.z : p.z);
    }
    FLD(Ov013Vec, pl, 0xb90) = p;
    FLD(s32, pl, 0xb9c) = 0x700;
}

void func_ov013_022043f8(void *self, u32 *p) {
    if (p != NULL) {
        FLD(u32, self, 0x24) = *p;
    }
}

void func_ov013_02204408(Ov013Vec *out, const Ov013Vec *v, Ov013Actor *a) {
    if (a != NULL) {
        func_ov003_021d9980(out, a->rot[1], v);
    }
}

void func_ov013_02204428(Ov013Vec *dst, const Ov013Vec *src, Ov013Actor *owner) {
    *dst = *src;
}

void func_ov013_02204444(void) {
}

BOOL func_ov013_02204448(void) {
    return TRUE;
}

void func_ov013_02204450(void) {
}

}
}  // namespace m_022043f8
