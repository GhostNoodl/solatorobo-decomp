#include "ov010/ov010.h"

typedef s32 fx32;
typedef Ov010Vec VecFx32;

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
struct Ov010Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
};

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
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
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

static inline BOOL Ov010_HasFlag(Ov010Sub40 *s, u64 m) {
    BOOL r = FALSE;
    if (s->flags & m) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov010_0220441c(u8 *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 1:
            func_ov003_021d85c8(self + 0x1b0, 3, 0, 0, 0);
            break;
        case 0: {
            u16 *hp = FLD(u16 *, self, 0x50);
            if (!Ov010_IsInvul(hp)) {
                s32 n;
                u8 st;
                u8 *g;
                hp[2] = FLD(u16, msg, 6);
                n = func_ov003_021d6548(self, msg + 0xa);
                hp = FLD(u16 *, self, 0x50);
                st = FLD(u8, hp, 9);
                if (hp[0] <= FLD(u16, self, 0xf4)) {
                    n = 0x15;
                    hp[0] = FLD(u16, self, 0xf4);
                }
                if (n != 0) {
                    FLD(u8, self, 0x170) = n;
                    FLD(u8, self, 0x171) = Ov010_HitKind(msg[9]);
                    FLD(Ov010Sub40 *, self, 0x40)->flags |= 1ull << n;
                    func_ov003_021d982c(self + 0x160, 1);
                }
                if (st != 1) {
                    func_ov000_02191418(FLD(void *, self, 0x38), 5, 0);
                }
                g = data_ov000_021ccd54;
                FLD(Ov010G190, g, 0x190).b2 = 1;
                FLD(Ov010G190, g, 0x190).b3 = 1;
                FLD(Ov010G190, g, 0x190).b4 = 1;
                FLD(u8, g, 0x18d) = 0x14;
                FLD(u8, g, 0x18e) = 0x1e;
                FLD(u8, g, 0x18f) = 0x1e;
                func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
                func_02049f44(data_02097e4c, 0x1b, self + 0x70, 0);
            }
            break;
        }
        }
        FLD(u32, self, 0x30) |= 1 << msg[5];
        msg[5] = 0;
        r = TRUE;
    } else if (msg[5] == 9) {
        u8 *o;
        u16 *p;
        r = func_ov003_021d1c00(self, msg);
        {
            u16 id = FLD(u16, msg, 0xc);
            o = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (o != NULL && FLD(u16, o, 0xe) == 0x4817) {
            u16 *hp = FLD(u16 *, self, 0x50);
            if (hp[0] <= FLD(u16, self, 0xf4)) {
                hp[0] = FLD(u16, self, 0xf4) + 1;
                FLD(Ov010Sub40 *, self, 0x40)->flags = 0;
            }
        }
        FLD(u16 *, self, 0x124)[0] = FLD(u16, o, 0x7e);
        FLD(u16 *, self, 0x124)[1] = 0xa00;
        FLD(u16 *, self, 0x124)[2] = 0x600;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x12c), self + 0x70, 0);
        if (!Ov010_HasFlag(FLD(Ov010Sub40 *, self, 0x40), 0x200000)) {
            FLD(Ov010Sub40 *, self, 0x40)->flags = 0;
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
extern void *func_ov010_022092c8(void *p);
extern void *func_ov010_022095a8(void *p);
extern void *func_ov010_02209860(void *p);
extern void *func_ov010_0220a078(void *p);
extern void *func_ov010_0220a2a8(void *p);
extern void *func_ov003_021d8910(void *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern BOOL func_ov010_0220d7f8(void *p);
extern BOOL func_ov003_021d8198(void *p);
extern BOOL func_ov003_021d8c10(void *p);
extern BOOL func_ov003_021d8980(void *p);
extern void func_ov003_021d8a30(void *p, u8 id, void *st);
extern void *func_ov000_0219bf90(void);
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

void func_ov010_022046ac(Ov010V *self) {
    void *o;
    u16 *p;
    u32 i;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    FLD(u8, self, 0xf3) = 1;
    o = func_0203dd9c(0x30);
    if (o != NULL) {
        o = func_ov010_022092c8(o);
    }
    FLD(void *, self, 0x104) = o;
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = func_ov010_022095a8(o);
    }
    FLD(void *, self, 0x108) = o;
    o = func_0203dd9c(0x34);
    if (o != NULL) {
        o = func_ov010_02209860(o);
    }
    FLD(void *, self, 0x10c) = o;
    o = func_0203dd9c(0xc);
    if (o != NULL) {
        o = func_ov010_0220a078(o);
    }
    FLD(void *, self, 0x110) = o;
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = func_ov010_0220a2a8(o);
    }
    FLD(void *, self, 0x114) = o;
    o = func_0203dd9c(0x10);
    if (o != NULL) {
        o = func_ov003_021d8910(o);
    }
    FLD(void *, self, 0x118) = o;
    FLD(Ov010CamPreset *, self, 0x11c) = Ov010Cam_New();
    FLD(Ov010CamPreset *, self, 0x120) = Ov010Cam_New();
    p = (u16 *)func_0203dd9c(6);
    FLD(u16 *, self, 0x124) = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    func_ov003_021d8f4c((u8 *)self + 0x160);
    func_ov010_0220d7f8((u8 *)self + 0x174);
    func_ov003_021d8198((u8 *)self + 0x1b0);
    func_ov003_021d8c10((u8 *)self + 0x1dc);
    switch (FLD(u16, self, 0xe)) {
    case 0x5c04:
        FLD(void *, self, 0xf8) = data_ov010_0220f160;
        FLD(s32, self, 0x15c) = 0;
        FLD(const fx32 *, self, 0xfc) = data_ov010_0220ff70;
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x11c), 0x1266, -0xcd1f, -0x5ee1, 0x10e8, 0xd87e, 0x10571);
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x120), 0xcd, -0xd19a, -0x3800, 0xde8, 0xff7e, 0x14571);
        break;
    case 0x5c05:
        FLD(void *, self, 0xf8) = data_ov010_0220f174;
        FLD(s32, self, 0x15c) = 1;
        FLD(void *, self, 0x100) = data_ov010_0220f150;
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x11c), -0x20f6, 0x13d7, 0x3c7b, 0x10ce, 0x6c1c, 0x1711f);
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x120), -0xa66, 0x1a14, 0x2214, 0xd73, 0x801c, 0x144f6);
        break;
    }
    self->va4();
    for (i = 0; i < 9; i++) {
        FLD(s32, (u8 *)self + i * 4, 0x12c) = -1;
    }
    self->vac((u8 *)self + 0x12c, 9);
    func_ov003_021d8980(FLD(void *, self, 0x118));
    func_ov003_021d8a30(FLD(void *, self, 0x118), 0, FLD(void *, self, 0x120));
    func_ov003_021d8a30(FLD(void *, self, 0x118), 1, FLD(void *, self, 0x11c));
    FLD(Ov010Bits16, FLD(void *, self, 0x38), 0xc2).b0 = 0;
    FLD(u16, self, 0x90) = FLD(u16, func_ov000_0219bf90(), 0xc);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220f0a0);
    }
    func_ov003_021cf400(1);
    FLD(u8, self, 0x15) = 2;
}

}
}  // namespace m_022046ac

// ---- merged from ov010_02204aac.cpp
namespace m_02204aac {
class Ov010Cls;
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

void func_ov010_02204aac(void *self) {
    func_ov003_021da40c(FLD(void *, self, 0x40));
    func_ov000_0218d7e8(self, FLD(u8, FLD(u8 *, self, 0x40), 0x13));
}

void func_ov010_02204ad0(void) {
}

void func_ov010_02204ad4(void *self) {
    BOOL go = FALSE;
    FLD(Ov010Flags8, self, 0x93).b4 = 0;
    if (func_ov003_021da03c(self) || FLD(u8, self, 0xf2) != 0) {
        go = TRUE;
    }
    FLD(u8, self, 0xf2) = 0;
    if (!go) {
        return;
    }
    FLD(s32, self, 0xc4) = 0;
    FLD(Ov010Flags8, self, 0x93).b4 = 1;
    func_ov003_021d8fc0((u8 *)self + 0x160);
    if (func_ov003_021d9878((u8 *)self + 0x160)) {
        Ov010B2 r = func_ov003_021d9644((u8 *)self + 0x160);
        FLD(Ov010B2, self, 0x170) = r;
        func_ov000_02198360(FLD(void *, self, 0x40), r.a, 1);
    }
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern void func_ov003_021d3008(void *self);
extern int func_ov003_021cf408(void);
extern u8 *func_ov000_0219bf90(void);
extern void VEC_MultAdd(s32 a, const Ov010Vec *b, const Ov010Vec *c, Ov010Vec *out);
extern void func_ov010_0220d858(void *p);


void func_ov010_02204b74(Ov010Cls *self) {
    u32 i;
    u8 *pl;
    s16 *p;
    u8 key;
    key = FLD(u8, FLD(u8 *, self, 0x40), 0x13);
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        FLD(u8, self, 0x15) = func_ov003_021cf408();
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov010_VecCopy(&FLD(Ov010Vec, pl, 0xb90), &FLD(Ov010Vec, self, 0x70));
        FLD(s32, pl, 0xb9c) = 0x800;
    }
    p = FLD(s16 *, self, 0x124);
    if (p != NULL) {
        Ov010Vec v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x70));
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    func_ov010_0220d858((u8 *)self + 0x174);
    ((Ov010V *)((u8 *)self + 0x1b0))->v0c();
    ((Ov010V *)((u8 *)self + 0x1dc))->v0c();
    if (FLD(Ov010V *, self, 0x118) != NULL) {
        FLD(Ov010V *, self, 0x118)->v0c();
    }
}

}
}  // namespace m_02204aac

// ---- merged from ov010_02204cdc.cpp
namespace m_02204cdc {
extern "C" {

extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);

void func_ov010_02204cdc(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0x266, 0);
    func_ov000_021915a0(FLD(void *, self, 0x38));
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
    FLD(u16, FLD(void *, self, 0x40), 0)++;
}

struct Ov010Mtx33 {
    s32 m[3][3];
};

extern void *data_02097e4c;
extern BOOL func_ov010_0220d77c(void *p);
extern void func_ov010_0220d918(void *p, void (*fn)(void));
extern s32 func_ov010_0220d9a4(void *p);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern void *func_ov000_0219bf90(void);
extern void func_ov010_02209578(void *t, s32 a, s32 b, s32 c, u16 d, u16 e);
extern void func_ov010_02204030(Ov010Vec *out, void *c, const Ov010Vec *target, s32 n, u16 ang);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
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

static inline Ov010Vec Ov010d_Pt(void *self) {
    Ov010Vec p;
    func_ov010_02204030(&p, FLD(void *, self, 0xf8), &FLD(Ov010Vec, self, 0x70), 4, 0);
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

void func_ov010_02204d44(void *self) {
    BOOL flag = FALSE;
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0:
        func_ov010_0220d918((u8 *)self + 0x174, (void (*)(void))func_ov010_0220d77c);
        if (func_ov010_0220d9a4((u8 *)self + 0x174) >= 5) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x32;
            break;
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 10;
    case 10: {
        void *pl;
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f040, 0x800, 1);
        pl = func_ov000_0219bf90();
        func_ov010_02209578(FLD(void *, self, 0x104), FLD(s32, self, 0x15c), FLD(s32, self, 0xfc), FLD(s32, self, 0x100), FLD(u16, self, 0xc), FLD(u16, pl, 0xc));
        func_ov010_0220d9c0((u8 *)self + 0x174, FLD(void *, self, 0x104));
        FLD(u16, FLD(void *, self, 0x40), 0) = 11;
    }
    case 11:
        flag = TRUE;
        FLD(u16, FLD(void *, self, 0x40), 2)++;
        if (FLD(u16, FLD(void *, self, 0x40), 2) > 0x1e) {
            FLD(u16, FLD(void *, self, 0x40), 2) = 0;
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x14;
        }
        break;
    case 0x14: {
        flag = TRUE;
        {
        Ov010Vec q = Ov010d_Pt(self);
        Ov010Vec d;
        Ov010Vec v;
        u16 r;
        u8 *c;
        s32 y;
        Ov010V *e;
        c = FLD(u8 *, self, 0xf8);
        d.x = q.x - FLD(s32, c, 0);
        d.y = q.y - FLD(s32, c, 4);
        d.z = q.z - FLD(s32, c, 8);
        r = func_ov003_021d9c38(&d);
        if (!(func_02040420() & 1)) {
            r += 0x3fff;
        } else {
            r += 0xc000;
        }
        c = FLD(u8 *, self, 0xf8);
        y = FLD(s32, c, 4);
        Ov010d_SetRot(&v, FLD(s32, c, 0x10), r);
        VEC_Add(&v, (Ov010Vec *)c, &v);
        v.y = y;
        v.y += func_02040528(0x1000);
        FLD(Ov010Vec, self, 0xb8) = v;
        FLD(s32, self, 0x150) = v.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = v.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = v.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &v);
        e->v0c(0x2000);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x15;
        if (FLD(u8, self, 0xf1) != 0) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x138), &FLD(Ov010Vec, self, 0x70), 0);
        }
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        }
        break;
    }
    case 0x15:
        flag = TRUE;
        if (func_ov010_0220da4c((u8 *)self + 0x174)) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x1e;
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        break;
    case 0x1e:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        FLD(Ov010Flags8, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x111).b3 = 0;
        func_ov000_021911c8(FLD(void *, self, 0x38), 0x2000);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x1f;
        break;
    case 0x1f:
        if (FLD(s16, FLD(void *, self, 0x38), 0xc4) == 1) {
            func_ov010_0220984c(FLD(void *, self, 0x108), FLD(u16, self, 0xc));
            func_ov010_0220d9c0((u8 *)self + 0x174, FLD(void *, self, 0x108));
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x28;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x13c), &FLD(Ov010Vec, self, 0x70), 0);
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        break;
    case 0x28:
        if (func_ov010_0220da4c((u8 *)self + 0x174) && func_ov000_02191120(FLD(void *, self, 0x38))) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0x266, 1);
            func_ov000_021915a0(FLD(void *, self, 0x38));
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x32;
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        break;
    case 0x32:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
    if (flag && FLD(s16, FLD(void *, self, 0x38), 0xc4) == 2) {
        FLD(Ov010Flags8, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x111).b3 = 1;
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
extern void *func_ov000_0219bf90(void);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220a040(void *self, u16 a, s32 b, s32 c, s32 d, u16 e, u16 f);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d8afc(void *p);
extern void func_ov003_021d969c(void *p, s32 a);

void func_ov010_0220522c(u8 *self) {
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x10;
        break;
    case 0x10:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f040, 0x266, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x11;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x134), self + 0x70, 0);
    case 0x11:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x32) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x20;
        }
        break;
    case 0x20: {
        u8 *pl = (u8 *)func_ov000_0219bf90();
        func_ov010_0220a040(FLD(void *, self, 0x10c), FLD(u8, self, 0x171), FLD(s32, self, 0x15c), FLD(s32, self, 0xfc),
                            FLD(s32, self, 0x100), FLD(u16, self, 0xc), FLD(u16, pl, 0xc));
        func_ov010_0220d9c0(self + 0x174, FLD(void *, self, 0x10c));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x21;
        break;
    }
    case 0x21:
        if (func_ov010_0220da4c(self + 0x174) && func_ov000_02191120(FLD(void *, self, 0x38))) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x30;
        }
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            func_ov003_021d8a7c(FLD(void *, self, 0x118), 1);
        }
        break;
    case 0x30:
        func_ov010_0220d9c0(self + 0x174, FLD(void *, self, 0x110));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x31;
        break;
    case 0x31:
        if (func_ov010_0220da4c(self + 0x174)) {
            func_ov003_021d8afc(FLD(void *, self, 0x118));
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x40;
        }
        break;
    case 0x40:
        func_ov003_021d969c(self + 0x160, 1);
        break;
    }
    if (func_ov000_02191120(FLD(void *, self, 0x38))) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0x800, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
}

}
}  // namespace m_0220522c

// ---- merged from ov010_02205444.cpp
namespace m_02205444 {
struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010St40 {
    u16 state;
    u16 timer;
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
extern void *func_ov000_0219bf90(void);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
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

static inline Ov010Vec Ov010_Center(u8 *self) {
    Ov010Vec v;
    v.x = FLD(s32, self, 0x70);
    v.y = FLD(s32, self, 0x74) + FLD(s32, self, 0x68) / 2;
    v.z = FLD(s32, self, 0x78);
    return v;
}

static inline void Ov010_ClearSpeed(u8 *self) {
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_02205444(u8 *self) {
    Ov010St40 *st = FLD(Ov010St40 *, self, 0x40);
    FLD(u8, self, 0xf2) = 1;
    switch (st->state) {
    case 0: {
        u8 k;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f02c, 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        func_ov003_021d8a7c(FLD(void *, self, 0x118), 0);
        k = FLD(u8, self, 0x171);
        switch (k) {
        case 1:
            FLD(Ov010St40 *, self, 0x40)->state = 10;
            break;
        case 2:
            FLD(Ov010St40 *, self, 0x40)->state = 0x14;
            break;
        }
        func_02049f44(data_02097e4c, 0x36, self + 0x70, 0);
        break;
    }
    case 10: {
        Ov010Vec v;
        Ov010Vec d;
        Ov010Vec *t = FLD(Ov010Vec *, self, 0xf8);
        u16 ang;
        s32 y;
        d.x = FLD(s32, self, 0x70) - t->x;
        d.y = FLD(s32, self, 0x74) - t->y;
        d.z = FLD(s32, self, 0x78) - t->z;
        ang = func_ov003_021d9c38(&d);
        t = FLD(Ov010Vec *, self, 0xf8);
        y = t->y;
        Ov010f_SetRot(&v, FLD(s32, t, 0x10), ang);
        VEC_Add(&v, t, &v);
        v.y = y;
        FLD(s32, self, 0xb8) = v.x;
        FLD(s32, self, 0xbc) = v.y;
        FLD(s32, self, 0xc0) = v.z;
        FLD(s32, self, 0x150) = v.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = v.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = v.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        {
            Ov010_ClearSpeed(self);
            Ov010Vec c = Ov010_Center(self);
            func_02065f88(0x5e2, &c)->v0c(0x3000);
        }
        FLD(Ov010St40 *, self, 0x40)->state = 0xb;
        break;
    }
    case 0xb:
        func_ov010_02207828(self);
        if (FLD(Ov010St40 *, self, 0x40)->timer % 30 == 0) {
            func_02065f88(0x66, &FLD(Ov010Vec, self, 0x70))->v0c(0x2800);
        }
        FLD(Ov010St40 *, self, 0x40)->timer++;
        st = FLD(Ov010St40 *, self, 0x40);
        if (st->timer > 0x3c) {
            st->timer = 0;
            FLD(Ov010St40 *, self, 0x40)->state = 0x1e;
        }
        func_ov000_0218d988(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x14:
        st->timer++;
        st = FLD(Ov010St40 *, self, 0x40);
        if (st->timer > 0xf) {
            st->timer = 0;
            FLD(Ov010St40 *, self, 0x40)->state = 0x1e;
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
        func_ov003_021d9980(&c2, FLD(u16, self, 0x7e), &b);
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        o2 = func_02066774(data_ov010_0220f054, data_ov010_0220f04c, 0, self + 0x70);
        FLD(u8, o2, 0x28) = 0;
        o2->v34(0, FLD(u16, self, 0x98), 0);
        o2->v10(&a);
        o2->v20(&c2);
        FLD(Ov010St40 *, self, 0x40)->state = 0x1f;
        func_02049f44(data_02097e4c, 0x44, self + 0x70, 0);
        break;
    }
    case 0x1f:
        st->timer++;
        st = FLD(Ov010St40 *, self, 0x40);
        if (st->timer > 0x19) {
            st->timer = 0;
            FLD(Ov010St40 *, self, 0x40)->state = 0x28;
        }
        break;
    case 0x28: {
        u8 *g;
        Ov010V *e;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f030, 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        Ov010_ClearSpeed(self);
        g = data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 0x28;
        FLD(u8, g, 0x18f) = 0x28;
        FLD(Ov010St40 *, self, 0x40)->state = 0x29;
        Ov010Vec o = {0, 0, 0};
        o.y = FLD(s32, self, 0x68) / 2;
        e = func_ov003_021da788(0x4b0, self, &o);
        e->v34(0, FLD(u16, self, 0x7e), 0);
        e->v0c(0x1800);
        if (FLD(u8, self, 0xf1) != 0) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x148), self + 0x70, 0);
        }
        func_02049f44(data_02097e4c, 0x32, self + 0x70, 0);
        break;
    }
    case 0x29: {
        Ov010Vec *t = FLD(Ov010Vec *, self, 0xf8);
        Ov010Vec f;
        s32 dx = t->x - FLD(s32, self, 0x70);
        s32 dy = t->y;
        s32 dz = t->z;
        dy -= FLD(s32, self, 0x74);
        dz -= FLD(s32, self, 0x78);
        s32 sv;
        func_ov003_021d9980(&f, FLD(u16, self, 0x98), (Ov010Vec *)&data_ov010_0220f0b4);
        if ((s32)(((s64)f.x * dx + (s64)f.y * dy + (s64)f.z * dz + 0x800) >> 12) < 0) {
            if (VEC_Distance(FLD(Ov010Vec *, self, 0xf8), &FLD(Ov010Vec, self, 0x70)) >=
                FLD(s32, FLD(u8 *, self, 0xf8), 0x10) + 0x3000) {
                FLD(Ov010St40 *, self, 0x40)->timer = 0;
                FLD(Ov010St40 *, self, 0x40)->state = 0x32;
            }
        }
        func_ov000_0219aae8(self, self, 0x8c, 0x30, 2, 0, 0, 0x800, 0x3000, 0x64, 0x1000);
        FLD(s32, self, 0x9c) += 0x266;
        sv = FLD(s32, self, 0x9c);
        FLD(s32, self, 0x9c) = sv > 0x1000 ? 0x1000 : (sv < 0 ? 0 : sv);
        func_ov000_0218dbe0(self, 0x1000);
        FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 1;
        break;
    }
    case 0x32:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f034, 0x266, 0);
        func_ov000_02191618(FLD(void *, self, 0x38));
        FLD(s32, self, 0xa4) = 0x400;
        FLD(Ov010St40 *, self, 0x40)->state = 0x33;
        break;
    case 0x33:
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            Ov010_ClearSpeed(self);
            FLD(Ov010St40 *, self, 0x40)->state = 0x3c;
        }
        func_ov000_0218dbe0(self, 0x1000);
        break;
    case 0x3c:
        FLD(u16, self, 0x7e) += 0x7fff;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(Ov010St40 *, self, 0x40)->state = 0x46;
        break;
    case 0x46:
        func_ov003_021d969c(self + 0x160, 1);
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
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
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

void func_ov010_02205c30(u8 *self) {
    u8 *tgt;
    s32 r = FLD(s16, FLD(u8 *, self, 0xb0), 2) * 2;
    {
        u16 id = FLD(u16, self, 0x90);
        tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f03c, 0x800, 0);
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        return;
    case 1:
        func_ov000_0218d988(self, tgt, r);
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 2;
        }
        return;
    case 2: {
        u8 *res;
        u8 *ent;
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) != 3) {
            return;
        }
        res = func_02070558(FLD(u16, self, 0xe));
        ent = res != NULL ? res + 0x3a : NULL;
        if (ent == NULL || FLD(u16, ent, 0) == 0xffff) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
        } else {
            Ov010Vec v;
            u8 *m = FLD(u8 *, self, 0x38);
            u8 *o;
            v.x = FLD(s16, m, 0xc6) << 4;
            v.y = FLD(s16, m, 0xc8) << 4;
            v.z = FLD(s16, m, 0xca) << 4;
            func_01ffc9fc(&v, &v, FLD(u16, self, 0x7e));
            VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
            o = func_ov003_021d69f0(self, 0x4818, &v, self + 0x7c, tgt);
            if (o != NULL) {
                FLD(s16, o, 0x18) = FLD(s8, ent, 2);
                func_ov010_0220de4c(o, FLD(u8, self, 0x171));
            }
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 3;
            func_02065f88(0x12c, &v)->v0c(0x2000);
            func_02049f44(data_02097e4c, 0x65, self + 0x70, 0);
            func_02049f44(data_02097e4c, 0x82, self + 0x70, 0);
        }
        if (FLD(u8, self, 0xf1) != 0) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x140), self + 0x70, 0);
        }
    }
    case 3: {
        u8 *a;
        u16 id = FLD(u16, self, 0xde);
        a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        if (a == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
            return;
        }
        func_ov000_0218d46c(a, FLD(u16, self, 0xc), 0xb);
        FLD(u16, self, 0xde) = 0xffff;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
        return;
    }
    case 4:
        if (!func_ov000_02191120(FLD(void *, self, 0x38))) {
            return;
        }
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(Ov010Bits3, self, 0xea).lo = FLD(Ov010Rank, FLD(u8 *, self, 0xb0), 0xa).rank;
        FLD(Ov010Flags8, self, 0xec).b0 = 1;
        func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
        func_ov003_021d969c(self + 0x160, 1);
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
extern void func_ov003_021d8afc(void *p);
extern void func_ov010_0220da14(void *p);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov000_0218d918(void *self, void *t, s32 a);

static inline BOOL Ov010f_Arrived(const Ov010Vec *a, const Ov010Vec *b) {
    return func_ov003_021d9a80(a, b) == 0 ? TRUE : FALSE;
}

void func_ov010_02205f40(u8 *self) {
    func_ov003_021d982c(self + 0x160, 1);
    FLD(u8, self, 0xf1) = 0;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u16 ang;
        void *t;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f038, 0x1000, 1);
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        func_ov000_02191618(FLD(void *, self, 0x38));
        FLD(u8, self, 0x92) = 0;
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, self, 0xb4) = 0;
        FLD(u16, self, 0xb6) = 0;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        if (FLD(void *, self, 0x50) != NULL) {
            t = func_ov000_02199f60(FLD(void *, self, 0x50));
            if (t == NULL || t == self) {
                ang = FLD(u16, self, 0x7e);
            } else {
                ang = FX_Atan2(FLD(s32, t, 0x70) - FLD(s32, self, 0x70), FLD(s32, t, 0x78) - FLD(s32, self, 0x78));
            }
        } else {
            ang = FLD(u16, self, 0x7e);
        }
        FLD(u16, self, 0x96) = ang;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x96) + 0x8000 + func_02040528(0x2000);
        func_ov003_021d8afc(FLD(void *, self, 0x118));
        func_ov010_0220da14(self + 0x174);
        func_ov003_021d969c(self + 0x160, 0);
        switch (FLD(u8, self, 0x171)) {
        case 1:
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x10;
            break;
        case 2:
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x20;
            break;
        }
        break;
    }
    case 0x10:
        FLD(s32, self, 0x9c) = 0x1000;
        FLD(s32, self, 0xa4) = 0x400;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x11;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x130), self + 0x70, 0);
    case 0x11: {
        Ov010Vec v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, FLD(u16, self, 0x98), &v);
        func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &v, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        if (FLD(s32, self, 0x9c) < 0x40) {
            FLD(s32, self, 0x9c) = 0;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
        }
        if (!func_ov000_02191120(FLD(void *, self, 0x38))) {
            return;
        }
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x50;
        }
        break;
    }
    case 0x20:
        FLD(Ov010Vec, self, 0xb8) = FLD(Ov010Vec, self, 0x70);
        FLD(s32, self, 0x9c) = 0x500;
        FLD(s32, self, 0xa0) = 0x200;
        FLD(s32, self, 0xa8) = 0x18;
        FLD(s32, self, 0xa4) = 0xf00;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x21;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x130), self + 0x70, 0);
    case 0x21:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) >= 0x14) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x30;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x30:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fefc, 0x266, 1);
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        func_ov000_02191618(FLD(void *, self, 0x38));
        FLD(s32, self, 0xa8) -= 2;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x31;
        break;
    case 0x31:
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x40;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            FLD(s32, self, 0x9c) = 0x666;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x40: {
        Ov010Vec t;
        t.x = FLD(s32, self, 0xb8);
        t.y = FLD(s32, self, 0xbc);
        t.z = FLD(s32, self, 0xc0);
        if (func_ov003_021d9a80(&t, &FLD(Ov010Vec, self, 0x70)) < 0x9000) {
            FLD(s32, self, 0xa4) = 0x1000;
        }
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), &t, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        FLD(u16, self, 0x98) = FX_Atan2(t.x - FLD(s32, self, 0x70), t.z - FLD(s32, self, 0x78));
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (Ov010f_Arrived(&t, &FLD(Ov010Vec, self, 0x70))) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x50;
        }
        break;
    }
    case 0x50:
        ((Ov010V *)self)->va4();
        func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
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

struct Ov010Sub40 {
    u16 state;
    u16 timer;
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
extern BOOL func_ov003_021d8efc(void *a);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov003_021d6a3c(void *self, s32 a, s32 b, s32 c);

static inline s32 Ov010g_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

// The screen argument of func_0203cb78 (its callers pass 0, 1 or -1).
// As an enum local it is not propagated, so its `mov #0` is listed before
// the jump's loads, as in the ROM (round o4B).
typedef enum { OV010_FADE_SCREEN_MAIN = 0, OV010_FADE_SCREEN_SUB = 1 } Ov010FadeScreen;

static inline void Ov010_Jump640c(u8 *self) {
    FLD(u16, self, 0x98) = FLD(u16, self, 0x98) + (u16)(FLD(u16, self, 0x7e) + 0x7fff);
    FLD(s32, self, 0x9c) = 0x280;
    FLD(s32, self, 0xa0) = 0x180;
    FLD(s32, self, 0xa8) = 0xb;
    FLD(s32, self, 0xa4) = 0xf00;
}

void func_ov010_0220640c(u8 *self) {
    switch (FLD(Ov010Sub40 *, self, 0x40)->state) {
    case 0: {
        Ov010Sub48 *m48;
        Ov010Sub44 *n;
        Ov010V *o;
        Ov010FadeScreen scr;
        func_ov003_021d97fc(self + 0x160, 1);
        m48 = FLD(Ov010Sub48 *, self, 0x48);
        m48->b9a_0 = 0;
        m48->b9a_3 = 0;
        func_0203f364(m48);
        n = FLD(Ov010Sub44 *, self, 0x44);
        n->b22_0 = 0;
        n->b22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        func_ov003_021d8afc(FLD(void *, self, 0x118));
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f038, 0x800, 1);
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        scr = OV010_FADE_SCREEN_MAIN;
        Ov010_Jump640c(self);
        func_0203cb78(0x1e000, 1, scr);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4817, 0x15);
        o = func_02065f88(0x69, &FLD(Ov010Vec, self, 0x70));
        if (o != NULL) {
            o->v0c(0x5000);
        }
        func_02049f44(data_02097e4c, FLD(s32, self, 0x130), self + 0x70, 0);
        FLD(Ov010Sub40 *, self, 0x40)->state = 1;
        return;
    }
    case 1:
        FLD(Ov010Sub40 *, self, 0x40)->timer++;
        if (FLD(Ov010Sub40 *, self, 0x40)->timer == 0x1e) {
            func_ov003_021d8eac(self + 0x1dc, self, 0x1000, 0);
            FLD(s32, self, 0xa8) >>= 1;
            FLD(s32, self, 0xa0) -= FLD(s32, self, 0xa0) >> 2;
        }
        if (FLD(Ov010Sub40 *, self, 0x40)->timer >= 0x5a) {
            FLD(s32, self, 0xa8) = 0;
            FLD(s32, self, 0xa0) = Ov010g_Mul(FLD(s32, self, 0xa0), 0xf80);
        }
        if (FLD(Ov010Sub40 *, self, 0x40)->timer >= 0x5a && func_ov003_021d8efc(self + 0x1dc)) {
            Ov010V *o = func_02065f88(0x69, &FLD(Ov010Vec, self, 0x70));
            if (o != NULL) {
                o->v0c(0x5000);
            }
            FLD(Ov010Sub40 *, self, 0x40)->timer = 0;
            FLD(Ov010Sub40 *, self, 0x40)->state = 2;
        }
        func_ov000_0218dbe0(self, 0);
        return;
    case 2:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f028, 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x112) = 0x800;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0xa0) = Ov010g_Mul(FLD(s32, self, 0xa0), 0xf80);
        FLD(Ov010Sub40 *, self, 0x40)->timer++;
        if (FLD(Ov010Sub40 *, self, 0x40)->timer > 0x78) {
            FLD(Ov010Sub40 *, self, 0x40)->timer = 0;
            FLD(Ov010Sub40 *, self, 0x40)->state = 3;
        }
        func_ov000_0218dbe0(self, 0);
        return;
    case 3:
        data_ov000_021ccd54->b0 = 1;
        func_ov003_021d6a3c(self, FLD(u8, self, 0xf3), 1, 1);
        FLD(Ov010Sub40 *, self, 0x40)->state = 4;
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
extern void func_ov010_02206784(void *self);
extern void func_ov010_02206974(void *self);

void func_ov010_02206758(void *self) {
    switch (FLD(u8, self, 0x171)) {
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

void func_ov010_02206784(void *self) {
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec p;
        Ov010V *e;
        u16 d;
        func_ov010_02204030(&p, FLD(void *, self, 0xf8), &FLD(Ov010Vec, self, 0x70), 4, 0);
        Ov010_VecCopy(&FLD(Ov010Vec, self, 0xb8), &p);
        FLD(s32, self, 0x150) = p.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = p.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = p.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &p);
        e->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        d = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f048, 0x800, 0);
            return;
        }
        if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f044, 0x800, 0);
        }
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
        }
        break;
    case 0x100:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0xcd, 0);
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
extern u16 func_ov003_021d9c38(Ov010Vec *v);
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

static inline void Ov010f_ClearVel(void *self) {
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_02206974(void *self) {
    Ov010Vec a;
    Ov010Vec b;
    Ov010Vec c;
    if (data_ov000_021ccd54 + 0xf4 == NULL) {
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
    } else {
        u8 *t = FLD(u8 *, self, 0xf8);
        s32 cross;
        u16 ang;
        a.x = FLD(s32, self, 0x70) - FLD(s32, t, 0);
        a.y = FLD(s32, self, 0x74) - FLD(s32, t, 4);
        a.z = FLD(s32, self, 0x78) - FLD(s32, t, 8);
        VEC_Normalize(&a, &a);
        b = FLD(Ov010Vec, data_ov000_021ccd54, 0xf8);
        t = FLD(u8 *, self, 0xf8);
        b.x = FLD(s32, t, 0) - b.x;
        b.y = FLD(s32, t, 4) - b.y;
        b.z = FLD(s32, t, 8) - b.z;
        VEC_Normalize(&b, &b);
        cross = (s32)(((s64)b.z * a.x - (s64)b.x * a.z + 0x800) >> 12);
        {
            s32 dist = VEC_Distance(&FLD(Ov010Vec, self, 0x70), FLD(Ov010Vec *, self, 0xf8));
            if (cross > 0) {
                ang = 0xffff - func_ov010_02208e90(dist, *FLD(s16 *, self, 0xb0));
            } else {
                ang = func_ov010_02208e90(dist, *FLD(s16 *, self, 0xb0));
            }
        }
        func_ov003_021d9d28(&c, &FLD(Ov010Vec, self, 0x70), ang, FLD(void *, self, 0xf8));
    }
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec d;
        Ov010Vec v;
        u8 *t = FLD(u8 *, self, 0xf8);
        u16 r;
        s32 y;
        d.x = FLD(s32, self, 0x70) - FLD(s32, t, 0);
        d.y = FLD(s32, self, 0x74) - FLD(s32, t, 4);
        d.z = FLD(s32, self, 0x78) - FLD(s32, t, 8);
        r = func_ov003_021d9c38(&d);
        t = FLD(u8 *, self, 0xf8);
        y = FLD(s32, t, 4);
        Ov010f_SetRot(&v, FLD(s32, t, 0x10), r);
        VEC_Add(&v, (Ov010Vec *)t, &v);
        v.y = y;
        FLD(Ov010Vec, self, 0xb8) = v;
        FLD(s32, self, 0x150) = v.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = v.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = v.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        Ov010f_ClearVel(self);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x30;
        }
        break;
    case 0x30: {
        Ov010V *e;
        u16 d;
        Ov010f_ClearVel(self);
        FLD(s32, self, 0x9c) = Ov010f_FxMul(*FLD(s16 *, self, 0xb0), 0x1800);
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &c);
        e->v0c(0x2000);
        d = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f048, 0x800, 0);
        } else if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f044, 0x800, 0);
        }
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x31;
        FLD(u16, FLD(void *, self, 0x40), 2) = 0;
        break;
    }
    case 0x31: {
        u16 *m = FLD(u16 *, self, 0x40);
        s32 dot = (s32)(((s64)a.x * b.x + (s64)a.y * b.y + (s64)a.z * b.z + 0x800) >> 12);
        if (dot > 0xc00 || (m[1]++, m[1] > 0x12c)) {
            FLD(s32, self, 0x150) = c.x - FLD(s32, self, 0x70);
            FLD(s32, self, 0x154) = c.y - FLD(s32, self, 0x74);
            FLD(s32, self, 0x158) = c.z - FLD(s32, self, 0x78);
            VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
            FLD(s32, self, 0x9c) = 0x300;
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0xcd, 0);
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x40;
        } else {
            FLD(Ov010Vec, self, 0x70) = c;
            func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
            func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
            break;
        }
    }
    case 0x40:
        if (FLD(s32, self, 0x9c) < 0x38) {
            Ov010f_ClearVel(self);
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
        }
        FLD(s32, self, 0xa4) = 0xe80;
        func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
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
extern void func_ov003_021d8afc(void *p);
extern void func_ov003_021d969c(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);

static inline Ov010Vec Ov010_Center(void *self) {
    Ov010Vec p;
    p.x = FLD(s32, self, 0x70);
    p.y = FLD(s32, self, 0x74) + FLD(s32, self, 0x68) / 2;
    p.z = FLD(s32, self, 0x78);
    return p;
}

void func_ov010_02206f54(void *self) {
    FLD(u8, self, 0xf2) = 1;
    FLD(u8, self, 0xf1) = 1;
}

void func_ov010_02206f64(void *self) {
    FLD(u8, self, 0xf2) = 1;
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    func_ov003_021d8a7c(FLD(void *, self, 0x118), 0);
    func_ov003_021d969c((u8 *)self + 0x160, 1);
    FLD(u16, FLD(void *, self, 0x40), 0)++;
    func_02049f44(data_02097e4c, FLD(s32, self, 0x144), (u8 *)self + 0x70, 0);
}

// Reads the state word through a const view (a const getter is not merged with the later
// plain read of the same field, so the increment reloads it as in the target).
static inline u16 Ov010_GetState(const u16 *state) {
    return *state;
}

void func_ov010_02206fd0(void *self) {
    u16 *m = FLD(u16 *, self, 0x40);
    FLD(u8, self, 0xf2) = 1;
    if (Ov010_GetState(m) != 0) {
        return;
    }
    m[0]++;
    func_ov003_021d8afc(FLD(void *, self, 0x118));
}

void func_ov010_02207004(void *self) {
    FLD(u8, self, 0xf2) = 1;
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        func_ov010_0220d9c0((u8 *)self + 0x174, FLD(void *, self, 0x114));
        FLD(u16, FLD(void *, self, 0x40), 0)++;
        return;
    }
    if (func_ov010_0220da4c((u8 *)self + 0x174)) {
        func_ov003_021d969c((u8 *)self + 0x160, 1);
    }
}

void func_ov010_02207064(void *self) {
    u16 *m = FLD(u16 *, self, 0x40);
    switch (m[0]) {
    case 0: {
        s32 sc = Ov010_FxMul(FLD(s32, self, 0x64), 0x1800);
        Ov010Vec q = Ov010_Center(self);
        Ov010V *fx = func_02065f88(0x196, &q);
        fx->v0c(sc);
        FLD(s32, fx, 0x3c) = 0x1000;
        func_02049f44(data_02097e4c, 0x44, (u8 *)self + 0x70, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        break;
    }
    case 1:
        m[1]++;
        if (FLD(u16, FLD(void *, self, 0x40), 2) > 0x32) {
            FLD(u16, FLD(void *, self, 0x40), 2) = 0;
            FLD(u16, FLD(void *, self, 0x40), 0) = 2;
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

void func_ov010_022071a0(void *self) {
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0:
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x10;
        break;
    case 0x30:
        break;
    case 0x10:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x11;
        break;
    case 0x11:
        if (!func_ov010_0220794c(self)) {
            break;
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x20;
    case 0x20: {
        Ov010Vec v;
        u8 *c = FLD(u8 *, self, 0xf8);
        u16 ang = FX_Atan2(FLD(s32, c, 0) - FLD(s32, self, 0x70), FLD(s32, c, 8) - FLD(s32, self, 0x78)) + 0x7fff;
        u16 d = func_ov010_02208e90(FLD(s32, FLD(u8 *, self, 0xf8), 0x10), 0x3000);
        s32 y;
        Ov010V *e;
        u16 diff;
        if (func_0204045c() % 2 == 0) {
            ang += d;
        } else {
            ang -= d;
        }
        c = FLD(u8 *, self, 0xf8);
        y = FLD(s32, c, 4);
        Ov010e_SetRot(&v, FLD(s32, c, 0x10), ang);
        VEC_Add(&v, (Ov010Vec *)c, &v);
        v.y = y;
        FLD(Ov010Vec, self, 0xb8) = v;
        FLD(u16, self, 0x98) = FX_Atan2(v.x - FLD(s32, self, 0x70), v.z - FLD(s32, self, 0x78));
        FLD(s32, self, 0x9c) = 0x2800;
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        func_ov000_0218dbe0(self, 0);
        FLD(s32, self, 0x9c) = 0x400;
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &v);
        e->v0c(0x2000);
        diff = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (diff >= 0x1400 && diff <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f048, 0x800, 0);
        } else if (diff >= 0x9400 && diff <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f044, 0x800, 0);
        }
        func_02049f44(data_02097e4c, FLD(s32, self, 0x14c), (u8 *)self + 0x70, 0);
        func_02049f44(data_02097e4c, 0x29, (u8 *)self + 0x70, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x21;
        break;
    }
    case 0x21:
        if (VEC_Distance(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xb8)) < 0x3000) {
            FLD(s32, self, 0xa4) = 0xf00;
        }
        if (FLD(s32, self, 0x9c) < 0x100) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f050, 0xcd, 0);
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) < 4) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x30;
        }
        break;
    }
}

}
}  // namespace m_02206f54
