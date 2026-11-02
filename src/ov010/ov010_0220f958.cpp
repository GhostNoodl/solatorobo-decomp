#include "ov010/ov010.h"
#include "ov000/ObjLayouts.h"

typedef s32 fx32;

// This TU's .rodata from its base up to the copied vector, and its .data up to the end of the 0x14
// record (the TU's string pool follows). The copied vector and its source are weak: the stub loads
// each through its own pool word. All objects are the TU's size-sorted group (order found with
// solve2.py); the four dynamic initialisers must be defined in the stub's order (rot, vector,
// pointer, record).
// The functions of 0x0220441c..0x02207520 (nine files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the name pointers and rotations through the .rodata
// base plus an offset, and now name them (data_ov010_0220f028..f058, f074) instead of
// data_ov010_0220f024[n] / FLD views. The files after 0x02207520 read the TU too, but 02207a44
// reads six u16 at base + 0xb4 (0x0220f0d8), past the .rodata defined here; with the TU's own
// f024 that view folds to one literal, so the merge stops before ov010_02207520.cpp.

struct Ov010Rot { u16 x, y, z; };

extern "C" {

extern const s32 data_ov010_0220f024;
extern const char *const data_ov010_0220f028;
extern const char *const data_ov010_0220f02c;
extern const char *const data_ov010_0220f030;
extern const char *const data_ov010_0220f034;
extern const char *const data_ov010_0220f038;
extern const char *const data_ov010_0220f03c;
extern const char *const data_ov010_0220f040;
extern const char *const data_ov010_0220f044;
extern const char *const data_ov010_0220f048;
extern const char *const data_ov010_0220f04c;
extern const char *const data_ov010_0220f050;
extern const char *const data_ov010_0220f054;
extern const char *const data_ov010_0220f058;
extern const Ov010Rot data_ov010_0220f05c;
extern const Ov010Rot data_ov010_0220f062;
extern const Ov010Rot data_ov010_0220f068;
extern const Ov010Rot data_ov010_0220f06e;
extern const Ov010Rot data_ov010_0220f074;
extern const Ov010Rot data_ov010_0220f07a;
extern const Ov010Rot data_ov010_0220f080;
extern const Ov010Rot data_ov010_0220f086;
extern const Ov010Rot data_ov010_0220f08c;
extern const Ov010Rot data_ov010_0220f092;
extern const u8 data_ov010_0220f098[8];
extern const u16 data_ov010_0220f0a0[4];
extern const VecFx32 data_ov010_0220f0a8;
extern const char *const data_ov010_0220fefc;
extern char data_ov010_0220ff00[];
extern char data_ov010_0220ff06[];
extern char data_ov010_0220ff0c[];
extern char data_ov010_0220ff12[];
extern char data_ov010_0220ff18[];
extern char data_ov010_0220ff1e[];
extern char data_ov010_0220ff24[];
extern char data_ov010_0220ff2a[];
extern char data_ov010_0220ff30[];
extern char data_ov010_0220ff36[];
extern const Ov010Rot data_ov010_0220ff3c;
extern char data_ov010_0220ff42[];
extern const VecFx32 data_ov010_0220ff48;
extern char data_ov010_0220ff54[];
extern char data_ov010_0220ff60[];
extern const fx32 data_ov010_0220ff70[5];

static inline fx32 K(fx32 v) { return v; }

const Ov010Rot data_ov010_0220f062 = {0x0, 0x7fff, 0x0};
char data_ov010_0220ff24[] = "nut02";
const u16 data_ov010_0220f0a0[4] = {0x1800, 0x1800, 0x1800, 0x1733};
char data_ov010_0220ff60[] = "ef/effect3dzai";
const char *const data_ov010_0220f058 = data_ov010_0220ff00;
const Ov010Rot data_ov010_0220f05c = {0, 0, 0};
const Ov010Rot data_ov010_0220f07a = {0x0, 0x7fff, 0x0};
const Ov010Rot data_ov010_0220ff3c = data_ov010_0220f05c;
const Ov010Rot data_ov010_0220f092 = {0x0, 0xff, 0x0};
char data_ov010_0220ff54[] = "ef3di1zai00";
const Ov010Rot data_ov010_0220f086 = {0x10ce, 0x6c1c, 0x0};
char data_ov010_0220ff36[] = "dmg13";
const Ov010Rot data_ov010_0220f08c = {0xd73, 0x801c, 0x0};
__declspec(weak) const VecFx32 data_ov010_0220f0a8 = {0, 0, 0};
const u8 data_ov010_0220f098[8] = {0, 1, 2, 2, 2, 2, 2, 0};
char data_ov010_0220ff06[] = "att00";
const char *const data_ov010_0220f040 = data_ov010_0220ff12;
char data_ov010_0220ff1e[] = "nut01";
const Ov010Rot data_ov010_0220f074 = {0x0, 0x0, 0x0};
__declspec(weak) const VecFx32 data_ov010_0220ff48 = data_ov010_0220f0a8;
char data_ov010_0220ff12[] = "att10";
const char *const data_ov010_0220f02c = data_ov010_0220ff06;
const char *const data_ov010_0220f034 = data_ov010_0220ff42;
const char *const data_ov010_0220fefc = data_ov010_0220f058;
const char *const data_ov010_0220f050 = data_ov010_0220ff1e;
const char *const data_ov010_0220f038 = data_ov010_0220ff36;
const fx32 data_ov010_0220ff70[5] = {-0x3302, -0x82b0, 0x33d7, -0x1d37, K(-0xdb33)};
const char *const data_ov010_0220f028 = data_ov010_0220ff30;
char data_ov010_0220ff42[] = "att02";
const char *const data_ov010_0220f03c = data_ov010_0220ff18;
const char *const data_ov010_0220f04c = data_ov010_0220ff54;
char data_ov010_0220ff0c[] = "att01";
const s32 data_ov010_0220f024 = 0xff00;
char data_ov010_0220ff18[] = "gun00";
const char *const data_ov010_0220f030 = data_ov010_0220ff0c;
char data_ov010_0220ff2a[] = "nut03";
char data_ov010_0220ff30[] = "dwn00";
char data_ov010_0220ff00[] = "run00";
const char *const data_ov010_0220f044 = data_ov010_0220ff2a;
const Ov010Rot data_ov010_0220f068 = {0x10e8, 0xd87e, 0x0};
const Ov010Rot data_ov010_0220f080 = {0x0, 0x7fff, 0x0};
const char *const data_ov010_0220f048 = data_ov010_0220ff24;
const char *const data_ov010_0220f054 = data_ov010_0220ff60;
const Ov010Rot data_ov010_0220f06e = {0xde8, 0xff7e, 0x0};

}

// ---- merged from ov010_0220441c.cpp
namespace m_0220441c {
struct Ov010G190 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

extern "C" {

extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern u8 func_ov003_021d6548(void *self, void *p);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d982c(void *p, u8 v);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(void *self, u8 *msg);
extern Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

static inline u8 Ov010_HitKind(s32 i) {
    if (i >= 0 && (u32)i < 7) {
        return data_ov010_0220f098[i];
    }
    return 2;
}

static inline BOOL Ov010_IsInvul(u16 *hp) {
    return hp[5] != 0;
}

static inline BOOL Ov010_HasFlag(ActorSub40 *s, u64 m) {
    BOOL r = FALSE;
    if (s->flags & m) {
        r = TRUE;
    }
    return r;
}

struct Obj0220441c : public Ov010Obj {
    u8 unk_ac[0x48];
    u16 unk_f4;
    u8 unk_f6[0x2e];
    u16 *unk_124;
    u8 unk_128[0x4];
    s32 unk_12c;
    u8 unk_130[0x40];
    u8 unk_170;
    u8 unk_171;
};

BOOL func_ov010_0220441c(Obj0220441c *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 1:
            func_ov003_021d85c8((u8 *)self + 0x1b0, 3, 0, 0, 0);
            break;
        case 0: {
            u16 *hp = self->hp;
            if (!Ov010_IsInvul(hp)) {
                s32 n;
                u8 st;
                u8 *g;
                hp[2] = FLD(u16, msg, 6);
                n = func_ov003_021d6548(self, msg + 0xa);
                hp = self->hp;
                st = FLD(u8, hp, 9);
                if (hp[0] <= self->unk_f4) {
                    n = 0x15;
                    hp[0] = self->unk_f4;
                }
                if (n != 0) {
                    self->unk_170 = n;
                    self->unk_171 = Ov010_HitKind(msg[9]);
                    self->unk_40->flags |= 1ull << n;
                    func_ov003_021d982c((u8 *)self + 0x160, 1);
                }
                if (st != 1) {
                    func_ov000_02191418(self->unk_38, 5, 0);
                }
                g = data_ov000_021ccd54;
                FLD(Ov010G190, g, 0x190).b2 = 1;
                FLD(Ov010G190, g, 0x190).b3 = 1;
                FLD(Ov010G190, g, 0x190).b4 = 1;
                FLD(u8, g, 0x18d) = 0x14;
                FLD(u8, g, 0x18e) = 0x1e;
                FLD(u8, g, 0x18f) = 0x1e;
                func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
                func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
            }
            break;
        }
        }
        self->msg_flags |= 1 << msg[5];
        msg[5] = 0;
        r = TRUE;
    } else if (msg[5] == 9) {
        u8 *o;
        u16 *p;
        r = func_ov003_021d1c00(self, msg);
        {
            u16 id = FLD(u16, msg, 0xc);
            o = data_ov000_021ccd68 == NULL ? NULL : (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (o != NULL && FLD(u16, o, 0xe) == 0x4817) {
            u16 *hp = self->hp;
            if (hp[0] <= self->unk_f4) {
                hp[0] = self->unk_f4 + 1;
                self->unk_40->flags = 0;
            }
        }
        self->unk_124[0] = FLD(u16, o, 0x7e);
        self->unk_124[1] = 0xa00;
        self->unk_124[2] = 0x600;
        func_02049f44(data_02097e4c, self->unk_12c, &self->pos, 0);
        if (!Ov010_HasFlag(self->unk_40, 0x200000)) {
            self->unk_40->flags = 0;
        }
    } else {
        r = func_ov003_021d1c00(self, msg);
    }
    return r;
}

}
}  // namespace m_0220441c

// ---- merged from ov010_022046ac.cpp
namespace m_022046ac {
struct Ov010CamBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

struct Ov010Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

struct Ov010CamPreset {
    void *vt;
    Ov010CamBits bits;
    u8 pad[3];
    s32 x;
    s32 y;
    s32 z;
    u16 a;
    u16 b;
    u16 c;
    u16 pad2;
    s32 w;
};

extern "C" {

extern u8 data_ov010_0220ffc4[];
extern u8 data_ov010_0220f160[];
extern u8 data_ov010_0220f174[];
extern u8 data_ov010_0220f150[];
extern void func_ov003_021d112c(void *self);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void *func_0203dd9c(u32 size);
extern void *Ov010Vt_02210280_Ctor(void *p);
extern void *Ov010Vt_022102c0_Ctor(void *p);
extern void *Ov010Vt_022102a0_Ctor(void *p);
extern void *Ov010Vt_02210260_Ctor(void *p);
extern void *Ov010Vt_02210240_Ctor(void *p);
extern void *Ov003Vt_021f7cf4_Ctor(void *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern BOOL func_ov010_0220d7f8(void *p);
extern BOOL func_ov003_021d8198(void *p);
extern BOOL func_ov003_021d8c10(void *p);
extern BOOL Ov003StateMachine_Init(void *p);
extern void func_ov003_021d8a30(void *p, u8 id, void *st);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(void *self, const void *a);

static inline Ov010CamPreset *Ov010Cam_New(void) {
    Ov010CamPreset *o = (Ov010CamPreset *)func_0203dd9c(0x20);
    if (o != NULL) {
        o->vt = data_ov010_0220ffc4;
        o->bits.b0 = 0;
        o->bits.b1 = 0;
    }
    return o;
}

static inline void Ov010Cam_Set(Ov010CamPreset *o, s32 x, s32 y, s32 z, u16 a, u16 b, s32 w) {
    if (!o->bits.b0) {
        o->bits.b1 = 1;
        o->x = x;
        o->y = y;
        o->z = z;
        o->a = a;
        o->b = b;
        o->c = 0;
        o->w = w;
    }
}

struct Obj022046ac : public Ov010Obj {
    u8 unk_ac[0x47];
    u8 unk_f3;
    u8 unk_f4[0x4];
    void *unk_f8;
    const fx32 *unk_fc;
    void *unk_100;
    void *unk_104;
    void *unk_108;
    void *unk_10c;
    void *unk_110;
    void *unk_114;
    void *unk_118;
    Ov010CamPreset *unk_11c;
    Ov010CamPreset *unk_120;
    u16 *unk_124;
    u8 unk_128[0x34];
    s32 unk_15c;
};

void Ov010ActVt_02210154_Start(Obj022046ac *self) {
    void *o;
    u16 *p;
    u32 i;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    self->unk_f3 = 1;
    o = func_0203dd9c(0x30);
    if (o != NULL) {
        o = Ov010Vt_02210280_Ctor(o);
    }
    self->unk_104 = o;
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = Ov010Vt_022102c0_Ctor(o);
    }
    self->unk_108 = o;
    o = func_0203dd9c(0x34);
    if (o != NULL) {
        o = Ov010Vt_022102a0_Ctor(o);
    }
    self->unk_10c = o;
    o = func_0203dd9c(0xc);
    if (o != NULL) {
        o = Ov010Vt_02210260_Ctor(o);
    }
    self->unk_110 = o;
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = Ov010Vt_02210240_Ctor(o);
    }
    self->unk_114 = o;
    o = func_0203dd9c(0x10);
    if (o != NULL) {
        o = Ov003Vt_021f7cf4_Ctor(o);
    }
    self->unk_118 = o;
    self->unk_11c = Ov010Cam_New();
    self->unk_120 = Ov010Cam_New();
    p = (u16 *)func_0203dd9c(6);
    self->unk_124 = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    func_ov003_021d8f4c((u8 *)self + 0x160);
    func_ov010_0220d7f8((u8 *)self + 0x174);
    func_ov003_021d8198((u8 *)self + 0x1b0);
    func_ov003_021d8c10((u8 *)self + 0x1dc);
    switch (self->kind) {
    case 0x5c04:
        self->unk_f8 = data_ov010_0220f160;
        self->unk_15c = 0;
        self->unk_fc = data_ov010_0220ff70;
        Ov010Cam_Set(self->unk_11c, 0x1266, -0xcd1f, -0x5ee1, 0x10e8, 0xd87e, 0x10571);
        Ov010Cam_Set(self->unk_120, 0xcd, -0xd19a, -0x3800, 0xde8, 0xff7e, 0x14571);
        break;
    case 0x5c05:
        self->unk_f8 = data_ov010_0220f174;
        self->unk_15c = 1;
        self->unk_100 = data_ov010_0220f150;
        Ov010Cam_Set(self->unk_11c, -0x20f6, 0x13d7, 0x3c7b, 0x10ce, 0x6c1c, 0x1711f);
        Ov010Cam_Set(self->unk_120, -0xa66, 0x1a14, 0x2214, 0xd73, 0x801c, 0x144f6);
        break;
    }
    self->va4();
    for (i = 0; i < 9; i++) {
        FLD(s32, (u8 *)self + i * 4, 0x12c) = -1;
    }
    self->vac((u8 *)self + 0x12c, 9);
    Ov003StateMachine_Init(self->unk_118);
    func_ov003_021d8a30(self->unk_118, 0, self->unk_120);
    func_ov003_021d8a30(self->unk_118, 1, self->unk_11c);
    FLD(Ov010Bits16, self->unk_38, 0xc2).b0 = 0;
    self->target = FLD(u16, func_ov000_0219bf90(), 0xc);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220f0a0);
    }
    func_ov003_021cf400(1);
    self->unk_15 = 2;
}

}
}  // namespace m_022046ac

// ---- merged from ov010_02204aac.cpp
struct Obj02204aac : public Ov010Obj {
    u8 unk_ac[0x4];
    s16 *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov010Vec unk_b8;
    s32 unk_c4;
    u8 unk_c8[0x16];
    u16 unk_de;
    u8 unk_e0[0xc];
    Ov010Flags8 unk_ec;
    u8 unk_ed[0x4];
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u8 unk_f4[0x4];
    Ov010Vec *unk_f8;
    s32 unk_fc;
    s32 unk_100;
    void *unk_104;
    void *unk_108;
    void *unk_10c;
    void *unk_110;
    u8 unk_114[0x4];
    void *unk_118;
    u8 unk_11c[0x8];
    s16 *unk_124;
    u8 unk_128[0x8];
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    s32 unk_13c;
    s32 unk_140;
    u8 unk_144[0x4];
    s32 unk_148;
    u8 unk_14c[0x4];
    Ov010Vec unk_150;
    s32 unk_15c;
    u8 unk_160[0x11];
    u8 unk_171;
};

namespace m_02204aac {
// The state-handler class: complete, so that the dispatcher reads its fields by name.
class Ov010Cls : public Obj02204aac {
};
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};

struct Ov010B2 {
    u8 a;
    u8 b;
};

extern "C" {

extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(void *self, u8 a);
extern BOOL func_ov003_021da03c(void *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov010B2 func_ov003_021d9644(void *p);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

void func_ov010_02204aac(Obj02204aac *self) {
    func_ov003_021da40c(self->unk_40);
    func_ov000_0218d7e8(self, self->unk_40->current);
}

void func_ov010_02204ad0(void) {
}

void func_ov010_02204ad4(Obj02204aac *self) {
    BOOL go = FALSE;
    self->unk_93.b4 = 0;
    if (func_ov003_021da03c(self) || self->unk_f2 != 0) {
        go = TRUE;
    }
    self->unk_f2 = 0;
    if (!go) {
        return;
    }
    self->unk_c4 = 0;
    self->unk_93.b4 = 1;
    func_ov003_021d8fc0((u8 *)self + 0x160);
    if (func_ov003_021d9878((u8 *)self + 0x160)) {
        Ov010B2 r = func_ov003_021d9644((u8 *)self + 0x160);
        FLD(Ov010B2, self, 0x170) = r;
        func_ov000_02198360(self->unk_40, r.a, 1);
    }
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern void func_ov003_021d3008(void *self);
extern int func_ov003_021cf408(void);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void VEC_MultAdd(s32 a, const Ov010Vec *b, const Ov010Vec *c, Ov010Vec *out);
extern void func_ov010_0220d858(void *p);


void func_ov010_02204b74(Ov010Cls *self) {
    u32 i;
    Robo021ca458 *pl;
    s16 *p;
    u8 key;
    key = self->unk_40->current;
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        self->unk_15 = func_ov003_021cf408();
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov010_VecCopy(&pl->unk_b90, &self->pos);
        pl->unk_b9c = 0x800;
    }
    p = self->unk_124;
    if (p != NULL) {
        Ov010Vec v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &self->pos, &self->pos);
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    func_ov010_0220d858((u8 *)self + 0x174);
    ((Ov010V *)((u8 *)self + 0x1b0))->v0c();
    ((Ov010V *)((u8 *)self + 0x1dc))->v0c();
    if (((Ov010V *)self->unk_118) != NULL) {
        ((Ov010V *)self->unk_118)->v0c();
    }
}

}
}  // namespace m_02204aac

// ---- merged from ov010_02204cdc.cpp
namespace m_02204cdc {
extern "C" {

extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);

void func_ov010_02204cdc(Obj02204aac *self) {
    if (self->unk_40->st != 0) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0x266, 0);
    func_ov000_021915a0(self->unk_38);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    self->unk_40->st++;
}

struct Ov010Mtx33 {
    s32 m[3][3];
};

extern void *data_02097e4c;
extern BOOL func_ov010_0220d77c(void *p);
extern void func_ov010_0220d918(void *p, void (*fn)(void));
extern s32 Ov010Coll_GetCount(void *p);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void func_ov010_02209578(void *t, s32 a, s32 b, s32 c, u16 d, u16 e);
extern void func_ov010_02204030(Ov010Vec *out, void *c, const Ov010Vec *target, s32 n, u16 ang);
extern u16 Ov003Vec_Yaw(Ov010Vec *v);
extern u32 func_02040420(void);
extern s32 func_02040528(s32 n);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33 *m, Ov010Vec *o);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void VEC_Normalize(Ov010Vec *a, Ov010Vec *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_021911c8(void *p, s32 a);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov010_0220984c(void *t, u16 a);

static inline Ov010Vec Ov010d_Pt(Obj02204aac *self) {
    Ov010Vec p;
    func_ov010_02204030(&p, self->unk_f8, &self->pos, 4, 0);
    return p;
}

static inline void Ov010d_Rot(Ov010Vec *v, u16 ang) {
    Ov010Mtx33 m;
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline s32 Ov010d_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010d_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33 m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010d_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

void func_ov010_02204d44(Obj02204aac *self) {
    BOOL flag = FALSE;
    switch (self->unk_40->st) {
    case 0:
        func_ov010_0220d918((u8 *)self + 0x174, (void (*)(void))func_ov010_0220d77c);
        if (Ov010Coll_GetCount((u8 *)self + 0x174) >= 5) {
            self->unk_40->st = 0x32;
            break;
        }
        self->unk_40->st = 10;
    case 10: {
        Robo021ca458 *pl;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f040, 0x800, 1);
        pl = func_ov000_0219bf90();
        func_ov010_02209578(self->unk_104, self->unk_15c, self->unk_fc, self->unk_100, self->id, pl->id);
        func_ov010_0220d9c0((u8 *)self + 0x174, self->unk_104);
        self->unk_40->st = 11;
    }
    case 11:
        flag = TRUE;
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x1e) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x14;
        }
        break;
    case 0x14: {
        flag = TRUE;
        {
        Ov010Vec q = Ov010d_Pt(self);
        Ov010Vec d;
        Ov010Vec v;
        u16 r;
        Ov010Vec *c;
        s32 y;
        Ov010V *e;
        c = self->unk_f8;
        d.x = q.x - c->x;
        d.y = q.y - c->y;
        d.z = q.z - c->z;
        r = Ov003Vec_Yaw(&d);
        if (!(func_02040420() & 1)) {
            r += 0x3fff;
        } else {
            r += 0xc000;
        }
        c = self->unk_f8;
        y = c->y;
        Ov010d_SetRot(&v, FLD(s32, c, 0x10), r);
        VEC_Add(&v, (Ov010Vec *)c, &v);
        v.y = y;
        v.y += func_02040528(0x1000);
        self->unk_b8 = v;
        self->unk_150.x = v.x - self->pos.x;
        self->unk_150.y = v.y - self->pos.y;
        self->unk_150.z = v.z - self->pos.z;
        VEC_Normalize(&self->unk_150, &self->unk_150);
        self->unk_98 = FX_Atan2(self->unk_150.x, self->unk_150.z);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        e = func_ov010_0220eaf0(self, &self->pos, &v);
        e->v0c(0x2000);
        self->unk_40->st = 0x15;
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            func_02049f44(data_02097e4c, self->unk_138, &self->pos, 0);
        }
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        }
        break;
    }
    case 0x15:
        flag = TRUE;
        if (func_ov010_0220da4c((u8 *)self + 0x174)) {
            self->unk_40->st = 0x1e;
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        break;
    case 0x1e:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        FLD(Ov010Flags8, func_ov000_02190a30(self->unk_38, 0), 0x111).b3 = 0;
        func_ov000_021911c8(self->unk_38, 0x2000);
        self->unk_40->st = 0x1f;
        break;
    case 0x1f:
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            func_ov010_0220984c(self->unk_108, self->id);
            func_ov010_0220d9c0((u8 *)self + 0x174, self->unk_108);
            self->unk_40->st = 0x28;
            func_02049f44(data_02097e4c, self->unk_13c, &self->pos, 0);
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        break;
    case 0x28:
        if (func_ov010_0220da4c((u8 *)self + 0x174) && func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0x266, 1);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->st = 0x32;
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        break;
    case 0x32:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
    if (flag && FLD(s16, self->unk_38, 0xc4) == 2) {
        FLD(Ov010Flags8, func_ov000_02190a30(self->unk_38, 0), 0x111).b3 = 1;
    }
}

}
}  // namespace m_02204cdc

// ---- merged from ov010_0220522c.cpp
namespace m_0220522c {
extern "C" {

extern void *data_02097e4c;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220a040(void *self, u16 a, s32 b, s32 c, s32 d, u16 e, u16 f);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void Ov003StateMachine_Leave(void *p);
extern void func_ov003_021d969c(void *p, s32 a);

void func_ov010_0220522c(Obj02204aac *self) {
    switch (self->unk_40->st) {
    case 0:
        self->unk_40->st = 0x10;
        break;
    case 0x10:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f040, 0x266, 0);
        self->unk_40->st = 0x11;
        func_02049f44(data_02097e4c, self->unk_134, &self->pos, 0);
    case 0x11:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x32) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x20;
        }
        break;
    case 0x20: {
        Robo021ca458 *pl = func_ov000_0219bf90();
        func_ov010_0220a040(self->unk_10c, self->unk_171, self->unk_15c, self->unk_fc,
                            self->unk_100, self->id, pl->id);
        func_ov010_0220d9c0((u8 *)self + 0x174, self->unk_10c);
        self->unk_40->st = 0x21;
        break;
    }
    case 0x21:
        if (func_ov010_0220da4c((u8 *)self + 0x174) && func_ov000_02191120(self->unk_38)) {
            self->unk_40->st = 0x30;
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov003_021d8a7c(self->unk_118, 1);
        }
        break;
    case 0x30:
        func_ov010_0220d9c0((u8 *)self + 0x174, self->unk_110);
        self->unk_40->st = 0x31;
        break;
    case 0x31:
        if (func_ov010_0220da4c((u8 *)self + 0x174)) {
            Ov003StateMachine_Leave(self->unk_118);
            self->unk_40->st = 0x40;
        }
        break;
    case 0x40:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
    if (func_ov000_02191120(self->unk_38)) {
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0x800, 0);
        func_ov000_021915a0(self->unk_38);
    }
}

}
}  // namespace m_0220522c

// ---- merged from ov010_02205444.cpp
struct Ov010_CenterSelf {
    u8 unk_00[0x68];
    s32 unk_68;
    u8 unk_6c[0x4];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
};

namespace m_02205444 {
struct Ov010Mtx33 {
    s32 m[9];
};

extern "C" {

extern void *data_02097e4c;
extern const Ov010Blk12 data_ov010_0220f0b4;
extern const Ov010Blk12 data_ov010_0220f0c0;
extern const Ov010Blk12 data_ov010_0220f0cc;
extern u8 *data_ov000_021ccd54;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov000_02191618(void *a);
extern BOOL func_ov000_02191120(void *p);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);
extern u16 Ov003Vec_Yaw(Ov010Vec *v);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(Ov010Vec *v, Ov010Mtx33 *m, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Normalize(const Ov010Vec *in, Ov010Vec *out);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d988(void *self, void *other, s32 a);
extern Ov010V *func_02066774(const char *a, const char *b, s32 c, void *d);
extern Ov010V *func_ov003_021da788(s32 id, void *self, Ov010Vec *ofs);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218dbe0(void *self, s32 a);

static inline s32 Ov010f_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010f_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33 m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010f_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline Ov010Vec Ov010_Center(Ov010_CenterSelf *self) {
    Ov010Vec v;
    v.x = self->unk_70;
    v.y = self->unk_74 + self->unk_68 / 2;
    v.z = self->unk_78;
    return v;
}

static inline void Ov010_ClearSpeed(Obj02204aac *self) {
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
}

void func_ov010_02205444(Obj02204aac *self) {
    ActorSub40 *st = self->unk_40;
    self->unk_f2 = 1;
    switch (st->st) {
    case 0: {
        u8 k;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f02c, 0x266, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov003_021d8a7c(self->unk_118, 0);
        k = self->unk_171;
        switch (k) {
        case 1:
            self->unk_40->st = 10;
            break;
        case 2:
            self->unk_40->st = 0x14;
            break;
        }
        func_02049f44(data_02097e4c, 0x36, &self->pos, 0);
        break;
    }
    case 10: {
        Ov010Vec v;
        Ov010Vec d;
        Ov010Vec *t = self->unk_f8;
        u16 ang;
        s32 y;
        d.x = self->pos.x - t->x;
        d.y = self->pos.y - t->y;
        d.z = self->pos.z - t->z;
        ang = Ov003Vec_Yaw(&d);
        t = self->unk_f8;
        y = t->y;
        Ov010f_SetRot(&v, FLD(s32, t, 0x10), ang);
        VEC_Add(&v, t, &v);
        v.y = y;
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        self->unk_150.x = v.x - self->pos.x;
        self->unk_150.y = v.y - self->pos.y;
        self->unk_150.z = v.z - self->pos.z;
        VEC_Normalize(&self->unk_150, &self->unk_150);
        self->unk_98 = FX_Atan2(self->unk_150.x, self->unk_150.z);
        {
            Ov010_ClearSpeed(self);
            Ov010Vec c = Ov010_Center((Ov010_CenterSelf *)self);
            func_02065f88(0x5e2, &c)->v0c(0x3000);
        }
        self->unk_40->st = 0xb;
        break;
    }
    case 0xb:
        func_ov010_02207828(self);
        if (self->unk_40->timer % 30 == 0) {
            func_02065f88(0x66, &self->pos)->v0c(0x2800);
        }
        self->unk_40->timer++;
        st = self->unk_40;
        if (st->timer > 0x3c) {
            st->timer = 0;
            self->unk_40->st = 0x1e;
        }
        func_ov000_0218d988(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x14:
        st->timer++;
        st = self->unk_40;
        if (st->timer > 0xf) {
            st->timer = 0;
            self->unk_40->st = 0x1e;
        }
        func_ov000_0218d988(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x1e: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010Vec c2;
        Ov010V *o2;
        *(Ov010Blk12 *)&a = data_ov010_0220f0c0;
        *(Ov010Blk12 *)&b = data_ov010_0220f0cc;
        func_ov003_021d9980(&c2, self->rot_y, &b);
        self->unk_98 = self->rot_y;
        o2 = func_02066774(data_ov010_0220f054, data_ov010_0220f04c, 0, &self->pos);
        FLD(u8, o2, 0x28) = 0;
        o2->v34(0, self->unk_98, 0);
        o2->v10(&a);
        o2->v20(&c2);
        self->unk_40->st = 0x1f;
        func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        break;
    }
    case 0x1f:
        st->timer++;
        st = self->unk_40;
        if (st->timer > 0x19) {
            st->timer = 0;
            self->unk_40->st = 0x28;
        }
        break;
    case 0x28: {
        u8 *g;
        Ov010V *e;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f030, 0x266, 0);
        func_ov000_021915a0(self->unk_38);
        Ov010_ClearSpeed(self);
        g = data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 0x28;
        FLD(u8, g, 0x18f) = 0x28;
        self->unk_40->st = 0x29;
        Ov010Vec o = {0, 0, 0};
        o.y = self->unk_68 / 2;
        e = func_ov003_021da788(0x4b0, self, &o);
        e->v34(0, self->rot_y, 0);
        e->v0c(0x1800);
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            func_02049f44(data_02097e4c, self->unk_148, &self->pos, 0);
        }
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        break;
    }
    case 0x29: {
        Ov010Vec *t = self->unk_f8;
        Ov010Vec f;
        s32 dx = t->x - self->pos.x;
        s32 dy = t->y;
        s32 dz = t->z;
        dy -= self->pos.y;
        dz -= self->pos.z;
        s32 sv;
        func_ov003_021d9980(&f, self->unk_98, (Ov010Vec *)&data_ov010_0220f0b4);
        if ((s32)(((s64)f.x * dx + (s64)f.y * dy + (s64)f.z * dz + 0x800) >> 12) < 0) {
            if (VEC_Distance(self->unk_f8, &self->pos) >=
                FLD(s32, self->unk_f8, 0x10) + 0x3000) {
                self->unk_40->timer = 0;
                self->unk_40->st = 0x32;
            }
        }
        func_ov000_0219aae8(self, self, 0x8c, 0x30, 2, 0, 0, 0x800, 0x3000, 0x64, 0x1000);
        self->unk_9c += 0x266;
        sv = self->unk_9c;
        self->unk_9c = sv > 0x1000 ? 0x1000 : (sv < 0 ? 0 : sv);
        func_ov000_0218dbe0(self, 0x1000);
        FLD(u16, ((void *)self->hp), 0xa) = 1;
        break;
    }
    case 0x32:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f034, 0x266, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_a4 = 0x400;
        self->unk_40->st = 0x33;
        break;
    case 0x33:
        if (func_ov000_02191120(self->unk_38)) {
            Ov010_ClearSpeed(self);
            self->unk_40->st = 0x3c;
        }
        func_ov000_0218dbe0(self, 0x1000);
        break;
    case 0x3c:
        self->rot_y += 0x7fff;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->st = 0x46;
        break;
    case 0x46:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

}
}  // namespace m_02205444

// ---- merged from ov010_02205c30.cpp
namespace m_02205c30 {
struct Ov010Bits3 {
    u16 lo : 3;
    u16 rest : 13;
};

struct Ov010Rank {
    u16 pad : 7;
    u16 rank : 3;
    u16 rest : 6;
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Actor *func_ov000_0218e640(void *mgr, u16 id);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov000_0218d988(void *self, void *target, s32 a);
extern void func_ov000_0218d46c(void *a, u16 b, s32 c);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021d969c(void *p, s32 a);
extern u8 *func_02070558(u16 id);
extern void func_01ffc9fc(Ov010Vec *src, Ov010Vec *dst, u16 angle);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern u8 *func_ov003_021d69f0(void *self, u16 kind, const Ov010Vec *pos, const void *rot, void *t);
extern void func_ov010_0220de4c(void *p, u8 a);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

void func_ov010_02205c30(Obj02204aac *self) {
    u8 *tgt;
    s32 r = FLD(s16, self->unk_b0, 2) * 2;
    {
        u16 id = self->target;
        tgt = data_ov000_021ccd68 == NULL ? NULL : (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    switch (self->unk_40->st) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f03c, 0x800, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->st = 1;
        return;
    case 1:
        func_ov000_0218d988(self, tgt, r);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_40->st = 2;
        }
        return;
    case 2: {
        u8 *res;
        u8 *ent;
        if (FLD(s16, self->unk_38, 0xc4) != 3) {
            return;
        }
        res = func_02070558(self->kind);
        ent = res != NULL ? res + 0x3a : NULL;
        if (ent == NULL || FLD(u16, ent, 0) == 0xffff) {
            self->unk_40->st = 4;
        } else {
            Ov010Vec v;
            u8 *m = (u8 *)self->unk_38;
            u8 *o;
            v.x = FLD(s16, m, 0xc6) << 4;
            v.y = FLD(s16, m, 0xc8) << 4;
            v.z = FLD(s16, m, 0xca) << 4;
            func_01ffc9fc(&v, &v, self->rot_y);
            VEC_Add(&v, &self->pos, &v);
            o = func_ov003_021d69f0(self, 0x4818, &v, (u8 *)self + 0x7c, tgt);
            if (o != NULL) {
                FLD(s16, o, 0x18) = FLD(s8, ent, 2);
                func_ov010_0220de4c(o, self->unk_171);
            }
            self->unk_40->st = 3;
            func_02065f88(0x12c, &v)->v0c(0x2000);
            func_02049f44(data_02097e4c, 0x65, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
        }
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            func_02049f44(data_02097e4c, self->unk_140, &self->pos, 0);
        }
    }
    case 3: {
        u8 *a;
        u16 id = self->unk_de;
        a = data_ov000_021ccd68 == NULL ? NULL : (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
        if (a == NULL) {
            self->unk_40->st = 4;
            return;
        }
        func_ov000_0218d46c(a, self->id, 0xb);
        self->unk_de = 0xffff;
        self->unk_40->st = 4;
        return;
    }
    case 4:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0xcd, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(Ov010Bits3, self, 0xea).lo = FLD(Ov010Rank, self->unk_b0, 0xa).rank;
        self->unk_ec.b0 = 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}


extern void *data_02097e4c;
extern Ov010Vec data_ov010_0220f0b4;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern BOOL func_ov000_02191120(void *p);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021d969c(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov003_021d982c(void *p, s32 a);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov000_02191618(void *a);
extern u8 *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 func_02040528(s32 max);
extern void Ov003StateMachine_Leave(void *p);
extern void func_ov010_0220da14(void *p);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern s32 Ov003Vec_DistSq(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov000_0218d918(void *self, void *t, s32 a);

static inline BOOL Ov010f_Arrived(const Ov010Vec *a, const Ov010Vec *b) {
    return Ov003Vec_DistSq(a, b) == 0 ? TRUE : FALSE;
}

void func_ov010_02205f40(Obj02204aac *self) {
    func_ov003_021d982c((u8 *)self + 0x160, 1);
    self->unk_f1 = 0;
    switch (self->unk_40->st) {
    case 0: {
        u16 ang;
        void *t;
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f038, 0x1000, 1);
        func_ov000_02191418(self->unk_38, 5, 1);
        func_ov000_02191618(self->unk_38);
        self->unk_92 = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        FLD(u16, self->unk_4c, 0x1c) = 0xffff;
        if (((void *)self->hp) != NULL) {
            t = func_ov000_02199f60(((void *)self->hp));
            if (t == NULL || t == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(FLD(s32, t, 0x70) - self->pos.x, FLD(s32, t, 0x78) - self->pos.z);
            }
        } else {
            ang = self->rot_y;
        }
        self->unk_96 = ang;
        self->unk_98 = self->unk_96 + 0x8000 + func_02040528(0x2000);
        Ov003StateMachine_Leave(self->unk_118);
        func_ov010_0220da14((u8 *)self + 0x174);
        func_ov003_021d969c((u8 *)self + 0x160, 0);
        switch (self->unk_171) {
        case 1:
            self->unk_40->st = 0x10;
            break;
        case 2:
            self->unk_40->st = 0x20;
            break;
        }
        break;
    }
    case 0x10:
        self->unk_9c = 0x1000;
        self->unk_a4 = 0x400;
        self->unk_40->st = 0x11;
        func_02049f44(data_02097e4c, self->unk_130, &self->pos, 0);
    case 0x11: {
        Ov010Vec v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, self->unk_98, &v);
        func_ov003_021d9e90(&self->pos, &v, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
        if (self->unk_9c < 0x40) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if (self->unk_9c == 0) {
            self->unk_40->st = 0x50;
        }
        break;
    }
    case 0x20:
        self->unk_b8 = self->pos;
        self->unk_9c = 0x500;
        self->unk_a0 = 0x200;
        self->unk_a8 = 0x18;
        self->unk_a4 = 0xf00;
        self->unk_40->st = 0x21;
        func_02049f44(data_02097e4c, self->unk_130, &self->pos, 0);
    case 0x21:
        self->unk_40->timer++;
        if (self->unk_40->timer >= 0x14) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x30;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x30:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220fefc, 0x266, 1);
        func_ov000_02191418(self->unk_38, 5, 1);
        func_ov000_02191618(self->unk_38);
        self->unk_a8 -= 2;
        self->unk_40->st = 0x31;
        break;
    case 0x31:
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_40->st = 0x40;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x666;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x40: {
        Ov010Vec t;
        t.x = self->unk_b8.x;
        t.y = self->unk_b8.y;
        t.z = self->unk_b8.z;
        if (Ov003Vec_DistSq(&t, &self->pos) < 0x9000) {
            self->unk_a4 = 0x1000;
        }
        func_ov003_021d9dbc(&self->pos, &t, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
        self->unk_98 = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        if (Ov010f_Arrived(&t, &self->pos)) {
            self->unk_40->st = 0x50;
        }
        break;
    }
    case 0x50:
        ((Ov010V *)self)->va4();
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}


struct Ov010Sub48 {
    u8 unk_00[0x9a];
    u16 b9a_0 : 1;
    u16 b9a_1 : 2;
    u16 b9a_3 : 1;
    u16 b9a_4 : 12;
};

struct Ov010Sub44 {
    u8 unk_00[0x22];
    u16 b22_0 : 1;
    u16 b22_1 : 1;
    u16 b22_2 : 14;
};

struct Ov010G54b {
    u8 unk_000[0x1cc];
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov010G54b *data_ov000_021ccd54;
extern void func_ov003_021d97fc(void *p, s32 a);
extern void func_0203f364(Ov010Sub48 *p);
extern void func_0203cb78(s32 a, s32 b, s32 c);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov003_021d8eac(void *a, void *b, s32 c, s32 d);
extern BOOL Ov003Timer_IsStopped(void *a);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov003_021d6a3c(void *self, s32 a, s32 b, s32 c);

static inline s32 Ov010g_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

// The screen argument of func_0203cb78 (its callers pass 0, 1 or -1).
// As an enum local it is not propagated, so its `mov #0` is listed before
// the jump's loads, as in the ROM (round o4B).
typedef enum { OV010_FADE_SCREEN_MAIN = 0, OV010_FADE_SCREEN_SUB = 1 } Ov010FadeScreen;

static inline void Ov010_Jump640c(Obj02204aac *self) {
    self->unk_98 = self->unk_98 + (u16)(self->rot_y + 0x7fff);
    self->unk_9c = 0x280;
    self->unk_a0 = 0x180;
    self->unk_a8 = 0xb;
    self->unk_a4 = 0xf00;
}

void func_ov010_0220640c(Obj02204aac *self) {
    switch (self->unk_40->st) {
    case 0: {
        Ov010Sub48 *m48;
        Ov010Sub44 *n;
        Ov010V *o;
        Ov010FadeScreen scr;
        func_ov003_021d97fc((u8 *)self + 0x160, 1);
        m48 = (Ov010Sub48 *)self->unk_48;
        m48->b9a_0 = 0;
        m48->b9a_3 = 0;
        func_0203f364(m48);
        n = (Ov010Sub44 *)self->unk_44;
        n->b22_0 = 0;
        n->b22_1 = 0;
        FLD(u16, self->unk_4c, 0x1c) = 0xffff;
        Ov003StateMachine_Leave(self->unk_118);
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f038, 0x800, 1);
        func_ov000_02191418(self->unk_38, 5, 1);
        scr = OV010_FADE_SCREEN_MAIN;
        Ov010_Jump640c(self);
        func_0203cb78(0x1e000, 1, scr);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4817, 0x15);
        o = func_02065f88(0x69, &self->pos);
        if (o != NULL) {
            o->v0c(0x5000);
        }
        func_02049f44(data_02097e4c, self->unk_130, &self->pos, 0);
        self->unk_40->st = 1;
        return;
    }
    case 1:
        self->unk_40->timer++;
        if (self->unk_40->timer == 0x1e) {
            func_ov003_021d8eac((u8 *)self + 0x1dc, self, 0x1000, 0);
            self->unk_a8 >>= 1;
            self->unk_a0 -= self->unk_a0 >> 2;
        }
        if (self->unk_40->timer >= 0x5a) {
            self->unk_a8 = 0;
            self->unk_a0 = Ov010g_Mul(self->unk_a0, 0xf80);
        }
        if (self->unk_40->timer >= 0x5a && Ov003Timer_IsStopped((u8 *)self + 0x1dc)) {
            Ov010V *o = func_02065f88(0x69, &self->pos);
            if (o != NULL) {
                o->v0c(0x5000);
            }
            self->unk_40->timer = 0;
            self->unk_40->st = 2;
        }
        func_ov000_0218dbe0(self, 0);
        return;
    case 2:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f028, 0x266, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u16, func_ov000_02190a30(self->unk_38, 0), 0x112) = 0x800;
        self->unk_a8 = 0;
        self->unk_a0 = Ov010g_Mul(self->unk_a0, 0xf80);
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x78) {
            self->unk_40->timer = 0;
            self->unk_40->st = 3;
        }
        func_ov000_0218dbe0(self, 0);
        return;
    case 3:
        data_ov000_021ccd54->b0 = 1;
        func_ov003_021d6a3c(self, self->unk_f3, 1, 1);
        self->unk_40->st = 4;
        return;
    case 4:
        return;
    }
}

}
}  // namespace m_02205c30

// ---- merged from ov010_02206758.cpp
namespace m_02206758 {
namespace Ov010T6974 {
}

extern "C" {
extern void func_ov010_02206784(Obj02204aac *self);
extern void func_ov010_02206974(Obj02204aac *self);

void func_ov010_02206758(Obj02204aac *self) {
    switch (self->unk_171) {
    case 1:
        func_ov010_02206784(self);
        break;
    case 2:
        func_ov010_02206974(self);
        break;
    }
}

extern void *data_02097e4c;
extern void func_ov010_02204030(Ov010Vec *out, void *c, const Ov010Vec *target, s32 n, u16 ang);
extern void VEC_Normalize(Ov010Vec *a, Ov010Vec *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);

void func_ov010_02206784(Obj02204aac *self) {
    switch (self->unk_40->st) {
    case 0: {
        Ov010Vec p;
        Ov010V *e;
        u16 d;
        func_ov010_02204030(&p, self->unk_f8, &self->pos, 4, 0);
        Ov010_VecCopy(&self->unk_b8, &p);
        self->unk_150.x = p.x - self->pos.x;
        self->unk_150.y = p.y - self->pos.y;
        self->unk_150.z = p.z - self->pos.z;
        VEC_Normalize(&self->unk_150, &self->unk_150);
        self->unk_98 = FX_Atan2(self->unk_150.x, self->unk_150.z);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        e = func_ov010_0220eaf0(self, &self->pos, &p);
        e->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->unk_40->st = 1;
        d = FLD(u16, e, 0x66) - self->rot_y;
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f048, 0x800, 0);
            return;
        }
        if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f044, 0x800, 0);
        }
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        if (self->unk_9c == 0) {
            self->unk_40->st = 0x100;
        }
        break;
    case 0x100:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0xcd, 0);
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

struct Ov010Mtx33f {
    s32 m[9];
};

extern u8 *data_ov000_021ccd54;
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void MTX_RotY33_(Ov010Mtx33f *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33f *m, Ov010Vec *o);
extern u16 func_ov010_02208e90(s32 a, s32 b);
extern void func_ov003_021d9d28(Ov010Vec *out, Ov010Vec *pos, u16 ang, void *c);
extern u16 Ov003Vec_Yaw(Ov010Vec *v);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);

static inline s32 Ov010f_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010f_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33f m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010f_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline void Ov010f_ClearVel(Obj02204aac *self) {
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
}

void func_ov010_02206974(Obj02204aac *self) {
    Ov010Vec a;
    Ov010Vec b;
    Ov010Vec c;
    if (data_ov000_021ccd54 + 0xf4 == NULL) {
        self->unk_40->st = 0x100;
    } else {
        Ov010Vec *t = self->unk_f8;
        s32 cross;
        u16 ang;
        a.x = self->pos.x - t->x;
        a.y = self->pos.y - t->y;
        a.z = self->pos.z - t->z;
        VEC_Normalize(&a, &a);
        b = FLD(Ov010Vec, data_ov000_021ccd54, 0xf8);
        t = self->unk_f8;
        b.x = t->x - b.x;
        b.y = t->y - b.y;
        b.z = t->z - b.z;
        VEC_Normalize(&b, &b);
        cross = (s32)(((s64)b.z * a.x - (s64)b.x * a.z + 0x800) >> 12);
        {
            s32 dist = VEC_Distance(&self->pos, self->unk_f8);
            if (cross > 0) {
                ang = 0xffff - func_ov010_02208e90(dist, *self->unk_b0);
            } else {
                ang = func_ov010_02208e90(dist, *self->unk_b0);
            }
        }
        func_ov003_021d9d28(&c, &self->pos, ang, self->unk_f8);
    }
    switch (self->unk_40->st) {
    case 0: {
        Ov010Vec d;
        Ov010Vec v;
        Ov010Vec *t = self->unk_f8;
        u16 r;
        s32 y;
        d.x = self->pos.x - t->x;
        d.y = self->pos.y - t->y;
        d.z = self->pos.z - t->z;
        r = Ov003Vec_Yaw(&d);
        t = self->unk_f8;
        y = t->y;
        Ov010f_SetRot(&v, FLD(s32, t, 0x10), r);
        VEC_Add(&v, (Ov010Vec *)t, &v);
        v.y = y;
        self->unk_b8 = v;
        self->unk_150.x = v.x - self->pos.x;
        self->unk_150.y = v.y - self->pos.y;
        self->unk_150.z = v.z - self->pos.z;
        VEC_Normalize(&self->unk_150, &self->unk_150);
        self->unk_98 = FX_Atan2(self->unk_150.x, self->unk_150.z);
        Ov010f_ClearVel(self);
        self->unk_40->st = 1;
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        if (self->unk_9c == 0) {
            self->unk_40->st = 0x30;
        }
        break;
    case 0x30: {
        Ov010V *e;
        u16 d;
        Ov010f_ClearVel(self);
        self->unk_9c = Ov010f_FxMul(*self->unk_b0, 0x1800);
        e = func_ov010_0220eaf0(self, &self->pos, &c);
        e->v0c(0x2000);
        d = FLD(u16, e, 0x66) - self->rot_y;
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f048, 0x800, 0);
        } else if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f044, 0x800, 0);
        }
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->unk_40->st = 0x31;
        self->unk_40->timer = 0;
        break;
    }
    case 0x31: {
        ActorSub40 *m = self->unk_40;
        s32 dot = (s32)(((s64)a.x * b.x + (s64)a.y * b.y + (s64)a.z * b.z + 0x800) >> 12);
        if (dot > 0xc00 || (m->timer++, m->timer > 0x12c)) {
            self->unk_150.x = c.x - self->pos.x;
            self->unk_150.y = c.y - self->pos.y;
            self->unk_150.z = c.z - self->pos.z;
            VEC_Normalize(&self->unk_150, &self->unk_150);
            self->unk_9c = 0x300;
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0xcd, 0);
            self->unk_40->st = 0x40;
        } else {
            self->pos = c;
            func_ov000_0218d918(self, self->unk_f8, 0x400);
            func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
            break;
        }
    }
    case 0x40:
        if (self->unk_9c < 0x38) {
            Ov010f_ClearVel(self);
            self->unk_40->st = 0x100;
        }
        self->unk_a4 = 0xe80;
        func_ov003_021d9e90(&self->pos, &self->unk_150, &self->pos, self->unk_9c, self->unk_a0);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
        break;
    case 0x100:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

}
}  // namespace m_02206758

// ---- merged from ov010_02206f54.cpp
namespace m_02206f54 {
extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void Ov003StateMachine_Leave(void *p);
extern void func_ov003_021d969c(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);

static inline Ov010Vec Ov010_Center(Ov010_CenterSelf *self) {
    Ov010Vec p;
    p.x = self->unk_70;
    p.y = self->unk_74 + self->unk_68 / 2;
    p.z = self->unk_78;
    return p;
}

struct Obj02206f54 {
    u8 unk_00[0x38];
    void *unk_38;
    u8 unk_3c[0x4];
    ActorSub40 *unk_40;
    u8 unk_44[0x20];
    s32 unk_64;
    u8 unk_68[0x8];
    Ov010Vec unk_70;
    u8 unk_7c[0x2];
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0xc];
    Ov010Vec unk_b8;
    u8 unk_c4[0x2d];
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3[0x5];
    u8 *unk_f8;
    u8 unk_fc[0x18];
    void *unk_114;
    void *unk_118;
    u8 unk_11c[0x28];
    s32 unk_144;
    u8 unk_148[0x4];
    s32 unk_14c;
};

void func_ov010_02206f54(Obj02206f54 *self) {
    self->unk_f2 = 1;
    self->unk_f1 = 1;
}

void func_ov010_02206f64(Obj02206f54 *self) {
    self->unk_f2 = 1;
    if (self->unk_40->st != 0) {
        return;
    }
    func_ov003_021d8a7c(self->unk_118, 0);
    func_ov003_021d969c((u8 *)self + 0x160, 1);
    self->unk_40->st++;
    func_02049f44(data_02097e4c, self->unk_144, &self->unk_70, 0);
}

// Reads the state word through a const view (a const getter is not merged with the later
// plain read of the same field, so the increment reloads it as in the target).
static inline u16 Ov010_GetState(const ActorSub40 *state) {
    return state->st;
}

void func_ov010_02206fd0(Obj02206f54 *self) {
    ActorSub40 *m = self->unk_40;
    self->unk_f2 = 1;
    if (Ov010_GetState(m) != 0) {
        return;
    }
    m->st++;
    Ov003StateMachine_Leave(self->unk_118);
}

void func_ov010_02207004(Obj02206f54 *self) {
    self->unk_f2 = 1;
    if (self->unk_40->st == 0) {
        func_ov010_0220d9c0((u8 *)self + 0x174, self->unk_114);
        self->unk_40->st++;
        return;
    }
    if (func_ov010_0220da4c((u8 *)self + 0x174)) {
        func_ov003_021d969c((u8 *)self + 0x160, 1);
    }
}

void func_ov010_02207064(Obj02206f54 *self) {
    ActorSub40 *m = self->unk_40;
    switch (m->st) {
    case 0: {
        s32 sc = Ov010_FxMul(self->unk_64, 0x1800);
        Ov010Vec q = Ov010_Center((Ov010_CenterSelf *)self);
        Ov010V *fx = func_02065f88(0x196, &q);
        fx->v0c(sc);
        FLD(s32, fx, 0x3c) = 0x1000;
        func_02049f44(data_02097e4c, 0x44, &self->unk_70, 0);
        self->unk_40->st = 1;
        break;
    }
    case 1:
        m->timer++;
        if (self->unk_40->timer > 0x32) {
            self->unk_40->timer = 0;
            self->unk_40->st = 2;
        }
        break;
    case 2:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}


struct Ov010Mtx33e {
    s32 m[9];
};

extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov010_0220794c(void *self);
extern u16 FX_Atan2(s32 y, s32 x);
extern u16 func_ov010_02208e90(s32 a, s32 b);
extern s32 func_0204045c(void);
extern void MTX_RotY33_(Ov010Mtx33e *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33e *m, Ov010Vec *o);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);

static inline s32 Ov010e_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010e_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33e m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010e_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

void func_ov010_022071a0(Obj02206f54 *self) {
    switch (self->unk_40->st) {
    case 0:
        self->unk_40->st = 0x10;
        break;
    case 0x30:
        break;
    case 0x10:
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0x266, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->st = 0x11;
        break;
    case 0x11:
        if (!func_ov010_0220794c(self)) {
            break;
        }
        self->unk_40->st = 0x20;
    case 0x20: {
        Ov010Vec v;
        u8 *c = self->unk_f8;
        u16 ang = FX_Atan2(FLD(s32, c, 0) - self->unk_70.x, FLD(s32, c, 8) - self->unk_70.z) + 0x7fff;
        u16 d = func_ov010_02208e90(FLD(s32, self->unk_f8, 0x10), 0x3000);
        s32 y;
        Ov010V *e;
        u16 diff;
        if (func_0204045c() % 2 == 0) {
            ang += d;
        } else {
            ang -= d;
        }
        c = self->unk_f8;
        y = FLD(s32, c, 4);
        Ov010e_SetRot(&v, FLD(s32, c, 0x10), ang);
        VEC_Add(&v, (Ov010Vec *)c, &v);
        v.y = y;
        self->unk_b8 = v;
        self->unk_98 = FX_Atan2(v.x - self->unk_70.x, v.z - self->unk_70.z);
        self->unk_9c = 0x2800;
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        func_ov000_0218dbe0(self, 0);
        self->unk_9c = 0x400;
        e = func_ov010_0220eaf0(self, &self->unk_70, &v);
        e->v0c(0x2000);
        diff = FLD(u16, e, 0x66) - self->unk_7e;
        if (diff >= 0x1400 && diff <= 0x6c00) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f048, 0x800, 0);
        } else if (diff >= 0x9400 && diff <= 0xec00) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f044, 0x800, 0);
        }
        func_02049f44(data_02097e4c, self->unk_14c, &self->unk_70, 0);
        func_02049f44(data_02097e4c, 0x29, &self->unk_70, 0);
        self->unk_40->st = 0x21;
        break;
    }
    case 0x21:
        if (VEC_Distance(&self->unk_70, &self->unk_b8) < 0x3000) {
            self->unk_a4 = 0xf00;
        }
        if (self->unk_9c < 0x100) {
            func_ov000_02190cb0(self->unk_38, data_ov010_0220f050, 0xcd, 0);
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_0218d918(self, self->unk_f8, 0x400);
        if (self->unk_9c < 4) {
            self->unk_40->st = 0x30;
        }
        break;
    }
}

}
}  // namespace m_02206f54
