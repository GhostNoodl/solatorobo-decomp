#include "ov010/ov010.h"

typedef s32 fx32;

// This TU's .rodata (all of it) and its .data up to the copies the static initialiser makes. The
// copied vectors and their sources are weak: the stub loads each through its own pool word, not
// from the section base. All objects are the TU's size-sorted group (order found with solve2.py).
// func_ov010_02203f08 at the end is part of this TU: it scales data_ov010_0220fe38, which it reads
// through the .data base plus an offset. So are the seven files before it (0x022020c8..0x02203f08,
// merged in round dtB, each in its own namespace). 022020c8's functions read data_ov010_0220f000
// through the .rodata base (it was an FLD view at data_ov010_0220efc8 + 0x38), so f000 is not
// weak: only the copies and their other sources are. The stub still matches with it non-weak.
struct Ov010Rot { u16 x, y, z; };
struct Ov010Handler { s32 key; void (*fn)(void); s32 adj; };

extern "C" {

void func_ov010_02202838(void);
void func_ov010_022028ec(void);

extern const Ov010Rot data_ov010_0220efc8;
extern const Ov010Vec data_ov010_0220efd0;
extern const Ov010Vec data_ov010_0220efdc;
extern const Ov010Vec data_ov010_0220efe8;
extern const Ov010Vec data_ov010_0220eff4;
extern const Ov010Vec data_ov010_0220f000;
extern const Ov010Handler data_ov010_0220f00c[2];
extern const Ov010Rot data_ov010_0220fe30;
extern const Ov010Vec data_ov010_0220fe38;
extern const Ov010Vec data_ov010_0220fe44;
extern const Ov010Vec data_ov010_0220fe50;

static inline fx32 K(fx32 v) { return v; }

const Ov010Vec data_ov010_0220f000 = {0, 0, 0};
const Ov010Handler data_ov010_0220f00c[2] = {{0, func_ov010_02202838, 0}, {1, func_ov010_022028ec, 0}};
const Ov010Rot data_ov010_0220efc8 = {0, 0, 0};
const Ov010Rot data_ov010_0220fe30 = data_ov010_0220efc8;
const Ov010Vec data_ov010_0220efdc = {-0x1000, 0, 0};
const Ov010Vec data_ov010_0220efd0 = {0, 0, 0x1000};
__declspec(weak) const Ov010Vec data_ov010_0220fe50 = data_ov010_0220f000;
__declspec(weak) const Ov010Vec data_ov010_0220efe8 = {0, 0x1000, 0};
const Ov010Vec data_ov010_0220fe38 = {K(0x1000), K(0), K(0)};
__declspec(weak) const Ov010Vec data_ov010_0220fe44 = data_ov010_0220efe8;
const Ov010Vec data_ov010_0220eff4 = {0, 0x1be, -0x125e};

}

// ---- merged from ov010_022020c8.cpp
struct Obj022020c8 {
    void *unk_00;
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0x2a];
    void *unk_38;
    u8 unk_3c[0x4];
    u16 *unk_40;
    void *unk_44;
    void *unk_48;
    void *unk_4c;
    u8 unk_50[0x14];
    s32 unk_64;
    u8 unk_68[0x8];
    Ov010Vec unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92[0x1];
    Ov010Flags8 unk_93;
    u8 unk_94[0x8];
    s32 unk_9c;
    Ov010Vec unk_a0;
    u8 unk_ac[0x4];
    void *unk_b0;
    u8 unk_b4[0x1a];
    Ov010Flags8 unk_ce;
    u8 unk_cf[0x9];
    void *unk_d8;
    u8 unk_dc[0x4];
    Ov010Vec unk_e0;
    Ov010Vec unk_ec;
    Ov010Vec unk_f8;
};

namespace m_022020c8 {
struct Ov010Heap022 {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010Snd {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
};

struct Ov010Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

static inline void Ov010Snd_Init(Ov010Snd *s, u16 id) {
    s->b0 = 1;
    s->b1 = 0;
    s->b2 = 0;
    s->b3 = 0;
    s->unk_02 = id;
    s->unk_04 = 0;
    s->unk_06 = 0;
    s->unk_08 = 0;
    s->unk_0c = 0;
    s->unk_10 = 0;
    s->unk_14 = 0;
    s->unk_18 = 0x1be;
    s->unk_1c = -0x125e;
}

class Ov010Cls;
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010FnEnt {
    s32 key;
    Ov010Fn fn;
};

struct Ov010FnTbl2 {
    s32 w[6];
};

extern "C" {

extern u8 *data_ov000_021ccd54;

extern u8 data_ov010_0220fe5c[];
extern const u8 data_ov003_021f4340;
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_0203f364(void *p);
extern int func_ov003_021cf330(void *p, void *d, s32 c);

extern u8 data_ov010_0220fe6c[];
extern Ov010Heap022 *data_02097dd0;
extern void *data_0214a420;

extern void *func_ov000_02194074(void *self);
extern void *func_ov000_0219429c(void *self);
extern void *func_ov003_021cf2bc(void *p);
extern void *func_ov003_021cf2d8(void *p);
extern void func_02065860(void *a, s32 b);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void MI_Copy36B(void *m, void *b);
extern BOOL func_ov000_0218cea4(void *self);

static inline void Ov010_022020c8_Init(void *self) {
    FLD(Ov010Flags8, self, 0xce).b0 = 0;
    FLD(Ov010Flags8, self, 0xce).b1 = 0;
    FLD(Ov010Flags8, self, 0xce).b2 = 0;
    FLD(u16, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = -1;
    FLD(void *, self, 0xd8) = NULL;
    FLD(void *, self, 0xdc) = NULL;
    FLD(Ov010Vec, self, 0xf8) = FLD(Ov010Vec, self, 0xec) = FLD(Ov010Vec, self, 0xe0) = data_ov010_0220f000;
}

void *func_ov010_022020c8(Obj022020c8 *self) {
    func_ov000_02194074(self);
    self->unk_00 = data_ov010_0220fe6c;
    func_ov003_021cf2bc((u8 *)self + 0x104);
    Ov010_022020c8_Init(self);
    return self;
}

// Kept on FLD (round svA): the class struct is defined above this namespace, so 0xd8 can only be a
// `void *` there, and the cast read `(Ov010Snd *)self->unk_d8` swaps r4/r5 in both callers.
static inline void Ov010_022020c8_Dtor(void *self) {
    u32 saved;
    FLD(void *, self, 0) = data_ov010_0220fe6c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(Ov010Snd *, self, 0xd8) != NULL) {
        Ov010Snd *s = FLD(Ov010Snd *, self, 0xd8);
        if (s != NULL) {
            if (s->b0) {
                s->b0 = 0;
                func_02065860(data_0214a420, s->unk_0c);
                func_02065860(data_0214a420, s->unk_10);
                s->unk_0c = 0;
                s->unk_10 = 0;
            }
            func_0203de1c(s);
        }
        FLD(Ov010Snd *, self, 0xd8) = NULL;
    }
    data_02097dd0->cur = saved;
    ((Ov010V *)((u8 *)self + 0x104))->v08();
    Ov010_022020c8_Init(self);
    func_ov003_021cf2d8((u8 *)self + 0x104);
    func_ov000_0219429c(self);
}

void *func_ov010_0220215c(void *self) {
    Ov010_022020c8_Dtor(self);
    return self;
}

void *func_ov010_0220228c(void *self) {
    Ov010_022020c8_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov010_022023c4(Obj022020c8 *self) {
    u8 m1[0x24];
    u8 m2[0x24];
    self->unk_93.b0 = 1;
    MTX_RotZ33_(m1, OV010_SIN(self->unk_80), OV010_COS(self->unk_80));
    MTX_RotX33_(m2, OV010_SIN(self->unk_7c), OV010_COS(self->unk_7c));
    MTX_Concat33(m1, m2, m1);
    MTX_RotY33_(m2, OV010_SIN(self->unk_7e), OV010_COS(self->unk_7e));
    MTX_Concat33(m1, m2, m1);
    MI_Copy36B(m1, (u8 *)self->unk_38 + 0x84);
    FLD(Ov010Vec, self->unk_38, 0x78) = self->unk_70;
    func_ov000_0218cea4(self);
}

struct Ov010Shot22 {
    u8 unk_00[0x70];
    Ov010Vec pos;
    Ov010Rot3 rot;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92[0x3c];
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_cf;
    u16 unk_d0;
    s32 unk_d4;
    void *unk_d8;
    void *unk_dc;
    Ov010Vec unk_e0;
    Ov010Vec unk_ec;
};

void func_ov010_022024c4(Ov010Shot22 *self, u16 a, const Ov010Vec *pos, const Ov010Vec *v, const Ov010Rot3 *rot) {
    if (self->b0) {
        return;
    }
    self->unk_90 = a;
    self->unk_d4 = 0;
    self->b0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    self->rot = *rot;
    self->unk_d0 = 0;
    self->unk_e0 = data_ov010_0220f000;
}

void func_ov010_02202560(Ov010Shot22 *self, u16 a, const Ov010Vec *pos, const Ov010Vec *v, const Ov010Rot3 *rot) {
    if (self->b0) {
        return;
    }
    self->unk_90 = a;
    self->unk_d4 = 1;
    self->b0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    self->rot = *rot;
    self->unk_d0 = 0;
    self->unk_e0 = data_ov010_0220f000;
}

struct Obj02202600 {
    u8 unk_00[0xdc];
    void *unk_dc;
};

void func_ov010_02202600(Obj02202600 *self, void *fn) {
    self->unk_dc = fn;
}

void func_ov010_02202608(Obj022020c8 *self) {
    void *m;
    Ov010Snd *s;
    u8 c;
    func_ov000_02194758(self);
    FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 0;
    func_ov000_02198360(self->unk_40, 0x20, 0);
    m = self->unk_48;
    FLD(Ov010Flags, m, 0x9a).b1 = 0;
    FLD(Ov010Flags, m, 0x9a).b4 = 0;
    FLD(Ov010Flags, self->unk_48, 0x9a).b7 = 1;
    m = self->unk_48;
    FLD(Ov010Flags, m, 0x9a).b0 = 0;
    FLD(Ov010Flags, m, 0x9a).b3 = 0;
    func_0203f364(m);
    c = data_ov003_021f4340;
    FLD(Ov010Flags, self->unk_48, 0x9a).b6 = 0;
    FLD(s32, self->unk_48, 0x30) = 0;
    FLD(s32, self->unk_44, 0x1c) = self->unk_64 * 2;
    func_ov003_021cf330((u8 *)self + 0x104, data_ov010_0220fe5c, c);
    s = (Ov010Snd *)func_0203dd9c(sizeof(Ov010Snd));
    if (s != NULL) {
        s->b0 = 0;
    }
    self->unk_d8 = s;
    Ov010Snd_Init(s, self->unk_0c);
}

static inline BOOL Ov010_GBusy(u8 *g) {
    return FLD(s32, g, 0x90) != FLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL Ov010_GIdle(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (Ov010_GBusy(g)) {
            return FALSE;
        }
        if (FLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov010_02202750(Ov010Cls *self) {
    Ov010FnEnt tbl[2];
    s32 key;
    u32 i;
    if (!Ov010_GIdle()) {
        return;
    }
    *(Ov010FnTbl2 *)tbl = *(const Ov010FnTbl2 *)data_ov010_0220f00c;
    key = FLD(s32, self, 0xd4);
    for (i = 0; i < 2; i++) {
        if (key == ((const Ov010FnEnt *)tbl)[i].key && *(s32 *)&tbl[i].fn != 0) {
            (self->*tbl[i].fn)();
            break;
        }
    }
}


}
}  // namespace m_022020c8

// ---- merged from ov010_02202838.cpp
namespace m_02202838 {
extern "C" {
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

struct Obj02202838 {
    u8 unk_00[0x40];
    void *unk_40;
    u8 unk_44[0x8a];
    Ov010Flags8 unk_ce;
    u8 unk_cf[0x1];
    u16 unk_d0;
};

void func_ov010_02202838(Obj02202838 *self) {
    void *m = self->unk_40;
    switch (FLD(u8, m, 0x13)) {
    case 0x20:
        if (self->unk_ce.b0) {
            func_ov000_02198360(m, 0x21, 1);
        }
        break;
    case 0x21:
        self->unk_d0++;
        if (self->unk_d0 > 0x3c) {
            self->unk_d0 = 0;
            func_ov000_02198360(m, 0x22, 1);
        }
        break;
    case 0x22:
        self->unk_d0++;
        if (self->unk_d0 > 0x3c) {
            self->unk_d0 = 0;
            func_ov000_02198360(m, 0x23, 1);
        }
        break;
    }
}

void func_ov010_022028ec(Obj02202838 *self) {
    void *m = self->unk_40;
    switch (FLD(u8, m, 0x13)) {
    case 0x20:
        if (self->unk_ce.b0) {
            func_ov000_02198360(m, 0x21, 1);
        }
        break;
    case 0x21:
        self->unk_d0++;
        if (self->unk_d0 > 0x28) {
            self->unk_d0 = 0;
            func_ov000_02198360(m, 0x22, 1);
        }
        break;
    case 0x22:
        self->unk_d0++;
        if (self->unk_d0 > 0x64) {
            self->unk_d0 = 0;
            func_ov000_02198360(m, 0x23, 1);
        }
        break;
    }
}

void func_ov010_022029a0(Obj022020c8 *self) {
}
}
}  // namespace m_02202838

// ---- merged from ov010_02202c9c.cpp
namespace m_02202c9c {
struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
};

extern "C" {
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void func_ov010_02203bf8(Ov010FxSet *p);

extern void *data_02097e4c;
extern void func_0203f364(void *p);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);
extern void func_ov010_02203f08(void *fx);

class Ov010Fx2 {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    s32 timer;
    s32 scale;
};
extern Ov010Fx2 *func_02065f88(s32 a, void *b);

static inline Ov010Fx2 *Ov010_SpawnRing(s32 a, void *b) {
    Ov010Fx2 *fx = func_02065f88(a, b);
    if (fx != NULL) {
        fx->timer = 0;
        fx->scale = 0;
    }
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02203f08;
    return fx;
}

void func_ov010_022029a4(Obj022020c8 *self) {
    s32 a = 0;
    s32 b = a;
    s32 c = a;
    s32 d = a;
    switch (self->unk_40[0]) {
    case 0: {
        void *m;
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
        self->unk_9c = a;
        self->unk_a0.x = a;
        self->unk_a0.y = a;
        self->unk_a0.z = a;
        Ov010_SpawnRing(0x12c, (u8 *)self + 0x70)->v0c(0x2000);
        self->unk_40[0] = 1;
        FLD(Ov010Flags, self->unk_44, 0x22).b1 = 0;
        m = self->unk_48;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = self->unk_38;
        FLD(u16, m, 0xb6) = 0x53ff;
        FLD(u16, m, 0xb8) = 0x53ff;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        FLD(u8, self->unk_38, 0xbe) = 0x14;
        func_02049f44(data_02097e4c, 0x2b, &self->unk_70, 0);
        break;
    }
    case 1: {
        void *m;
        b = 0x10;
        d = 0x400;
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x41) {
            self->unk_40[1] = 0;
            self->unk_40[0] = 2;
        }
        FLD(Ov010Flags, self->unk_44, 0x22).b1 = 0;
        m = self->unk_48;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = self->unk_38;
        FLD(u16, m, 0xb6) = 0x53ff;
        FLD(u16, m, 0xb8) = 0x53ff;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        break;
    }
    case 2:
        b = 2;
        c = 2;
        d = 0x400;
        self->unk_e0.x = Ov010_FxMul(self->unk_e0.x, 0xfa0);
        self->unk_e0.y = Ov010_FxMul(self->unk_e0.y, 0xfa0);
        self->unk_e0.z = Ov010_FxMul(self->unk_e0.z, 0xfa0);
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x3c) {
            Ov010FxSet *s;
            FLD(u8, self->unk_38, 0xbe) = 0x1f;
            s = (Ov010FxSet *)self->unk_d8;
            if (s->b0) {
                s->b1 = 1;
                s->unk_06 = 0x1000;
            }
            self->unk_40[1] = 0;
            self->unk_40[0] = 3;
        }
        break;
    case 3:
        a = 4;
        c = 0x10;
        d = 0x2000;
        break;
    }
    VEC_MultAdd(a, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
    VEC_MultAdd(b, &self->unk_ec, &self->unk_e0, &self->unk_e0);
    VEC_MultAdd(c, &data_ov010_0220fe38, &self->unk_e0, &self->unk_e0);
    func_ov003_021d9aec(&self->unk_e0, &self->unk_e0, d);
    VEC_Add(&self->unk_70, &self->unk_e0, &self->unk_70);
    if ((Ov010FxSet *)self->unk_d8 != NULL) {
        func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
    }
}

void func_ov010_02202c9c(Obj022020c8 *self) {
    if (FLD(u16, self->unk_40, 0) == 0) {
        Ov010FxSet *s;
        FLD(u8, self->unk_38, 0xbe) = 0x1f;
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x1000;
        }
        FLD(u16, self->unk_40, 0)++;
    }
    {
        self->unk_e0.x = Ov010_FxMul(self->unk_e0.x, 0xf80);
        self->unk_e0.y = Ov010_FxMul(self->unk_e0.y, 0xf80);
        self->unk_e0.z = Ov010_FxMul(self->unk_e0.z, 0xf80);
    }
    VEC_MultAdd(4, &data_ov010_0220fe38, &self->unk_e0, &self->unk_e0);
    VEC_Add(&self->unk_70, &self->unk_e0, &self->unk_70);
    if ((Ov010FxSet *)self->unk_d8 != NULL) {
        func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
    }
}
}
}  // namespace m_02202c9c

// ---- merged from ov010_02202d9c.cpp
namespace m_02202d9c {
struct Ov010Trail {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_01[5];
    u16 unk_06;
    u16 unk_08;
    u8 unk_0a[6];
    void *unk_10;
};

typedef BOOL (*Ov010HitFn)(u16 id, Ov010Vec *a, Ov010Vec *b);

extern "C" {
extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_02065860(void *a, void *b);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *src, Ov010Vec *dst);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);
extern void func_ov003_021d9b8c(Ov010Vec *out, const Ov010Vec *in, s32 max, s32 sub);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern u16 func_ov003_021d9c74(Ov010Vec *v);
extern u16 func_ov003_021d9c38(const Ov010Vec *v);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL func_01ffc198(const Ov010Vec *a, const Ov010Vec *b, s32 r);
extern void func_ov010_02203bf8(Ov010Trail *p);

static inline s32 Ov010t_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov010_02202d9c(Obj022020c8 *self) {
    void *p40 = self->unk_40;
    BOOL dir;
    BOOL done = FALSE;
    void *tgt;
    u8 chk;
    if ((FLD(u64, p40, 4) & 0x200) != 0) {
        func_ov000_02198360(p40, 9, done);
        return;
    }
    dir = done;
    tgt = NULL;
    chk = done;
    switch (FLD(u16, p40, 0)) {
    case 0: {
        void *m = self->unk_38;
        Ov010Trail *s;
        FLD(u16, m, 0xb6) = 0x7fff;
        FLD(u16, m, 0xb8) = 0x7fff;
        FLD(u16, m, 0xba) = 0x10;
        FLD(u16, m, 0xbc) = 0xf;
        FLD(u8, self->unk_38, 0xbe) = 0x1f;
        s = (Ov010Trail *)self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        s = (Ov010Trail *)self->unk_d8;
        if (s->b0) {
            if (s->b2) {
                func_02065860(data_0214a420, s->unk_10);
                s->unk_10 = NULL;
            }
            s->b2 = 1;
            s->unk_08 = 0x2000;
            s->b3 = 0;
        }
        self->unk_40[0] = 1;
        func_02049f44(data_02097e4c, 0x50, &self->unk_70, 0);
        break;
    }
    case 1:
        VEC_MultAdd(6, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
        func_ov003_021d9b8c(&self->unk_e0, &self->unk_e0, 0x180, 0x180);
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x46) {
            self->unk_40[1] = 0;
            self->unk_40[0] = 10;
            func_0204a028(data_02097e4c, 0x32, &self->unk_70, 8);
        }
        break;
    case 10:
        VEC_MultAdd(0x18, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
        VEC_MultAdd(6, &data_ov010_0220fe44, &self->unk_e0, &self->unk_e0);
        func_ov003_021d9aec(&self->unk_e0, &self->unk_e0, 0x700);
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x1d) {
            self->unk_40[1] = 0;
            self->unk_40[0] = 0x14;
        }
        break;
    case 0x15:
    case 0x14: {
        Ov010Vec d;
        Ov010HitFn fn;
        dir = TRUE;
        chk = TRUE;
        {
            u16 id = self->unk_90;
            tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        {
            u16 *st = self->unk_40;
            if (st[0] == 0x14) {
                self->unk_9c = 0;
                self->unk_f8 = FLD(Ov010Vec, tgt, 0x70);
                self->unk_f8.y += FLD(s32, FLD(void *, tgt, 0x44), 0x10);
                st[0] = 0x15;
            }
        }
        d.x = self->unk_f8.x - self->unk_70.x;
        d.y = self->unk_f8.y - self->unk_70.y;
        d.z = self->unk_f8.z - self->unk_70.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(self->unk_9c, &d, &self->unk_e0, &self->unk_e0);
        VEC_MultAdd(4, &data_ov010_0220fe44, &self->unk_e0, &self->unk_e0);
        self->unk_9c += 4;
        {
            s32 v = self->unk_9c;
            if (v > 0x400) {
                v = 0x400;
            } else if (v < 0) {
                v = 0;
            }
            self->unk_9c = v;
        }
        func_ov003_021d9aec(&self->unk_e0, &self->unk_e0, 0x700);
        fn = FLD(Ov010HitFn, self, 0xdc);
        if (fn != NULL) {
            if (fn(FLD(u16, tgt, 0xc), &self->unk_f8, &self->unk_70)) {
                self->unk_40[0] = 0x1e;
            }
        }
        if (VEC_Distance(&self->unk_70, &self->unk_f8) < 0x1000) {
            self->unk_40[0] = 0x28;
        }
        break;
    }
    case 0x1e: {
        Ov010Vec d;
        dir = TRUE;
        chk = TRUE;
        {
            u16 id = self->unk_90;
            if (data_ov000_021ccd68 != NULL) {
                tgt = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
        }
        self->unk_e0.x = Ov010t_FxMul64(self->unk_e0.x, 0xe80);
        self->unk_e0.y = Ov010t_FxMul64(self->unk_e0.y, 0xe80);
        self->unk_e0.z = Ov010t_FxMul64(self->unk_e0.z, 0xe80);
        d.x = self->unk_f8.x - self->unk_70.x;
        d.y = self->unk_f8.y - self->unk_70.y;
        d.z = self->unk_f8.z - self->unk_70.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x40, &d, &self->unk_e0, &self->unk_e0);
        if (VEC_Distance(&self->unk_70, &self->unk_f8) < 0x1000) {
            self->unk_40[0] = 0x28;
        }
        break;
    }
    case 100:
        // Final state: nothing to do, but the empty case sets the switch's compare tree.
        break;
    case 0x28: {
        s32 t;
        u16 col;
        void *m;
        {
            u16 id = self->unk_90;
            if (data_ov000_021ccd68 != NULL) {
                tgt = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
        }
        t = 0x19 - self->unk_40[1];
        if (t > 0x19) {
            t = 0x19;
        } else if (t < 1) {
            t = 1;
        }
        col = (t << 5) | 0x1f | (t << 10);
        m = self->unk_38;
        FLD(u16, m, 0xb6) = col;
        FLD(u16, m, 0xb8) = col;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        dir = TRUE;
        chk = TRUE;
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x1e) {
            self->unk_40[1] = 0;
            self->unk_40[0] = 100;
            done = TRUE;
        }
        break;
    }
    }
    if (dir) {
        Ov010Vec n;
        VEC_Normalize(&self->unk_e0, &n);
        self->unk_7c = func_ov003_021d9c74(&n);
        self->unk_7e = func_ov003_021d9c38(&n);
    }
    if (chk && tgt != NULL) {
        BOOL hit;
        BOOL r;
        FLD(u16, self->unk_48, 0x9a) |= 0x10;
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        hit = FALSE;
        if (FLD(u32, self->unk_48, 0x50) & 0x20000000) {
            hit = TRUE;
        }
        r = func_01ffc198(&FLD(Ov010Vec, tgt, 0x70), &self->unk_70, self->unk_64 + FLD(s32, tgt, 0x64));
        if (hit || r) {
            done = TRUE;
        }
    }
    if (done) {
        FLD(u8, self, 0xce) |= 2;
        func_ov000_02198360(self->unk_40, 0x15, 1);
    }
    VEC_Add(&self->unk_70, &self->unk_e0, &self->unk_70);
    if ((Ov010Trail *)self->unk_d8 != NULL) {
        func_ov010_02203bf8((Ov010Trail *)self->unk_d8);
    }
}
}
}  // namespace m_02202d9c

// ---- merged from ov010_022033d0.cpp
namespace m_022033d0 {
struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
    u8 unk_08[4];
    s32 fx0;
    s32 fx1;
};

struct Ov010Sub44 {
    u8 unk_00[0x22];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
};

struct Ov010Sub48 {
    u8 unk_00[0x9a];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 rest : 11;
};

extern "C" {
extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern void func_02065804(void *a, s32 b);
extern void func_ov010_02203bf8(Ov010FxSet *p);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern u16 func_ov003_021d9c38(const Ov010Vec *v);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(Ov010Sub48 *p);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

static inline void *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov010_TeamBit(u16 id) {
    void *a = Ov010_FindActor(id);
    if (a == NULL) {
        return 0;
    }
    return (u16)(1 << (FLD(u16, a, 0xe) >> 12));
}

void func_ov010_022033d0(Obj022020c8 *self) {
    u16 *st = self->unk_40;
    if (((const u16 *)st)[0] == 0) {
        Ov010V *e;
        Ov010FxSet *s;
        st[0]++;
        if (self->unk_ce.b1) {
            func_ov000_0219aae8(self, self, FLD(u16, self->unk_4c, 8), FLD(u16, self->unk_4c, 0xa), Ov010_TeamBit(self->unk_90), NULL, NULL, 0x2000, 0, 100, 0x1000);
            func_ov000_0218996c(0xf, 5);
        }
        e = func_02065f88(0x131, &self->unk_70);
        e->v34(0, func_ov003_021d9c38(&data_ov010_0220fe38), 0);
        e->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x1a, &self->unk_70, 0);
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 0;
            func_02065804(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b2 = 0;
            func_02065804(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
        if ((Ov010Sub44 *)self->unk_44 != NULL) {
            Ov010Sub44 *n = (Ov010Sub44 *)self->unk_44;
            n->b0 = 0;
            n->b1 = 0;
        }
        if ((Ov010Sub48 *)self->unk_48 != NULL) {
            Ov010Sub48 *m;
            func_ov000_02198c8c((Ov010Sub48 *)self->unk_48, 0xffff);
            m = (Ov010Sub48 *)self->unk_48;
            m->b0 = 0;
            m->b3 = 0;
            func_0203f364(m);
            m = (Ov010Sub48 *)self->unk_48;
            m->b1 = 0;
            m->b4 = 0;
        }
    } else {
        st[1]++;
        if (st[1] > 5) {
            func_ov000_02197dec(self, 0xf, 0x63);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov010V *)self)->v08();
        } else if (self->unk_38 != NULL) {
            FLD(u8, self->unk_38, 0xbe) = 31 - self->unk_40[1] * 4;
        }
    }
    func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
}
}
}  // namespace m_022033d0

// ---- merged from ov010_0220366c.cpp
namespace m_0220366c {
struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
    u8 unk_08[4];
    s32 fx0;
    s32 fx1;
};

struct Ov010Sub48b {
    u8 unk_00[0x44];
    s32 unk_44;
    u8 unk_48[0x10];
    s32 unk_58;
    u8 unk_5c[0x3e];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 rest : 12;
};

struct Ov010Owner {
    u8 unk_00;
    u8 kind;
    u8 unk_02[0x1a];
    u16 id;
};

struct Ov010B0 {
    u16 unk_00;
    u16 mode : 3;
    u16 rest : 13;
};

extern "C" {
extern void *data_0214a420;
extern void func_02065804(void *a, s32 b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02196060(void *self);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov010_02203bf8(Ov010FxSet *p);

void func_ov010_0220366c(Obj022020c8 *self) {
    if (self->unk_40[0] == 0) {
        Ov010FxSet *s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 0;
            func_02065804(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b2 = 0;
            func_02065804(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
    }
    func_ov000_02195d88(self);
}

void func_ov010_022036fc(Obj022020c8 *self) {
    BOOL first = FALSE;
    if (self->unk_40[0] == 0) {
        first = TRUE;
    }
    func_ov000_02196060(self);
    if (first) {
        Ov010FxSet *s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        Ov010_VecSet(&self->unk_a0, 0, 0, 0);
        self->unk_ce.b2 = 1;
        self->unk_9c = 0x4c0;
        self->unk_90 = FLD(u16, func_ov000_02199ba0(self->unk_4c), 0x90);
    }
    func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
}

extern void *data_ov000_021ccd68;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern u8 *func_ov000_0219bf90(void);
extern void func_ov000_02196c40(void *self);
extern Ov010Vec func_ov003_021da214(void *actor);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *o);
extern s32 func_ov000_0219a510(void *self, u16 mask, Ov010Vec *pos, s32 r, s32 a, void **list);
extern void func_ov003_021f0c60(void *self, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_0203f324(Ov010Sub48b *p);
extern void func_0203f364(Ov010Sub48b *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern u16 func_ov003_021d9c74(Ov010Vec *v);
extern u16 func_ov003_021d9c38(const Ov010Vec *v);

static inline void *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov010_02203788(Obj022020c8 *self) {
    u16 *st;
    void *actor;
    if (!self->unk_ce.b2) {
        FLD(u16, self->unk_4c, 0x1c) = FLD(u16, func_ov000_0219bf90(), 0xc);
        func_ov000_02196c40(self);
        return;
    }
    switch (self->unk_40[0]) {
    case 0:
        actor = Ov010_FindActor(self->unk_90);
        if (actor != NULL) {
            Ov010Vec c;
            Ov010Vec b = func_ov003_021da214(actor);
            c.x = FLD(s32, actor, 0x70);
            c.y = FLD(s32, actor, 0x74);
            c.z = FLD(s32, actor, 0x78);
            VEC_Add(&c, &b, &c);
            self->unk_ec.x = c.x - self->unk_70.x;
            self->unk_ec.y = c.y - self->unk_70.y;
            self->unk_ec.z = c.z - self->unk_70.z;
            VEC_Normalize(&self->unk_ec, &self->unk_ec);
        } else {
            func_ov003_021d9980(&self->unk_ec, self->unk_7e, &data_ov010_0220efd0);
        }
        self->unk_40[0] = 10;
        break;
    case 10: {
        void *list[32];
        actor = Ov010_FindActor(self->unk_90);
        if (actor != NULL) {
            Ov010Vec c;
            Ov010Vec b = func_ov003_021da214(actor);
            c.x = FLD(s32, actor, 0x70);
            c.y = FLD(s32, actor, 0x74);
            c.z = FLD(s32, actor, 0x78);
            VEC_Add(&c, &b, &c);
            self->unk_ec.x = c.x - self->unk_70.x;
            self->unk_ec.y = c.y - self->unk_70.y;
            self->unk_ec.z = c.z - self->unk_70.z;
            VEC_Normalize(&self->unk_ec, &self->unk_ec);
        }
        if (func_ov000_0219a510(self, 0x20, &self->unk_70, self->unk_64, 0, list) != 0 ||
            ((Ov010Sub48b *)self->unk_48)->unk_58 != 0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->unk_40, 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x3c) {
            self->unk_40[1] = 0;
            self->unk_40[0] = 0x14;
        }
        break;
    }
    case 0x14: {
        void *list[32];
        if (func_ov000_0219a510(self, 0x20, &self->unk_70, self->unk_64, 0, list) != 0 ||
            ((Ov010Sub48b *)self->unk_48)->unk_58 != 0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->unk_40, 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        self->unk_40[1]++;
        if (self->unk_40[1] > 0x3c) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
            return;
        }
        break;
    }
    }
    {
        s32 v = self->unk_9c + 0x14;
        self->unk_9c = v;
        if (v > 0xa00) {
            v = 0xa00;
        } else if (v < 0) {
            v = 0;
        }
        self->unk_9c = v;
    }
    func_ov003_021d9e90(&self->unk_70, &self->unk_ec, &self->unk_70, self->unk_9c, 0);
    if ((Ov010Sub48b *)self->unk_48 != NULL) {
        Ov010Sub48b *o;
        BOOL f;
        if (((Ov010B0 *)self->unk_b0)->mode == 2) {
            Ov010Sub48b *m = (Ov010Sub48b *)self->unk_48;
            m->b0 = 1;
            m->b3 = 1;
            func_0203f324(m);
        }
        o = NULL;
        f = FALSE;
        {
            Ov010Owner *ow = (Ov010Owner *)self->unk_4c;
            if (ow != NULL && ow->id != 0xffff && ow->kind == 1) {
                s32 r = self->unk_64 + 0x4cd;
                void *p;
                if (r < 0xccd) {
                    r = 0xccd;
                }
                ((Ov010Sub48b *)self->unk_48)->unk_44 = r;
                p = func_ov000_02199ba0(self->unk_4c);
                if (p != NULL && (o = FLD(Ov010Sub48b *, p, 0x48)) != NULL && o->b3) {
                    o->b3 = 0;
                    func_0203f364(o);
                    f = TRUE;
                }
            }
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (f) {
            o->b3 = 1;
            func_0203f324(o);
        }
    }
    self->unk_7c = func_ov003_021d9c74(&self->unk_ec);
    self->unk_7e = func_ov003_021d9c38(&self->unk_ec);
    func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
}
}
}  // namespace m_0220366c

// ---- merged from ov010_02203ee0.cpp
namespace m_02203ee0 {
class Ov010Fx {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    s32 timer;
    s32 scale;
};

extern "C" {

extern Ov010Fx *func_02065f88(s32 a, const void *b);
extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(void *p, s32 a);
void func_ov010_02203f08(Ov010Fx *fx);

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern Ov010V *func_020657b0(void *a, s32 b);
extern void func_02065860(void *a, s32 b);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);

struct Ov010Glow {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 rest : 4;
    u8 pad_01;
    u16 id;
    s16 cur;
    s16 tgt;
    s16 scale;
    u16 pad_0a;
    s32 keyA;
    s32 keyB;
    Ov010Vec off;
};

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

void func_ov010_02203bf8(Ov010Glow *self) {
    u8 *actor;
    Ov010V *o;
    u16 ry;
    u16 rx;
    Ov010Vec base;
    if (!self->b0) {
        return;
    }
    {
        u16 id = self->id;
        actor = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    if (actor == NULL) {
        self->id = 0xffff;
        func_02065860(data_0214a420, self->keyA);
        func_02065860(data_0214a420, self->keyB);
        self->keyA = 0;
        self->keyB = 0;
        return;
    }
    if (self->b1 && self->keyA == 0) {
        self->keyA = FLD(s32, func_02065f88(0x324, &data_ov010_0220fe50), 0x24);
    }
    if (self->b2 && self->keyB == 0) {
        Ov010Fx *fx = func_02065f88(self->b3 ? 0x25e : 0x25d, &data_ov010_0220fe50);
        fx->v14(self->scale, self->scale, self->scale);
        self->keyB = FLD(s32, fx, 0x24);
    }
    if (self->b1 && self->tgt != self->cur) {
        s32 d = self->tgt - self->cur;
        if ((d < 0 ? -d : d) <= 0x19a) {
            self->cur = self->tgt;
        } else if (self->tgt > self->cur) {
            self->cur += 0x19a;
        } else {
            self->cur -= 0x19a;
        }
    }
    if (self->cur < 0) {
        self->cur = 0;
    }
    base = FLD(Ov010Vec, actor, 0x70);
    ry = FLD(u16, actor, 0x7c);
    rx = FLD(u16, actor, 0x7e);
    if (self->keyA != 0) {
        o = func_020657b0(data_0214a420, self->keyA);
        if (o == NULL) {
            self->keyA = 0;
            self->b1 = 0;
        } else {
            Ov010Vec v;
            func_ov003_021d9900(&v, ry, &self->off);
            func_ov003_021d9980(&v, rx, &v);
            VEC_Add(&v, &base, &v);
            o->v18(&v);
            o->v14(self->cur, self->cur, self->cur);
        }
    }
    if (self->keyB == 0) {
        return;
    }
    o = func_020657b0(data_0214a420, self->keyB);
    if (o == NULL) {
        self->keyB = 0;
        self->b2 = 0;
        return;
    }
    {
        Ov010Vec v;
        func_ov003_021d9900(&v, ry, &self->off);
        func_ov003_021d9980(&v, rx, &v);
        VEC_Add(&v, &base, &v);
        o->v18(&v);
        o->v34((u16)(ry + 0x7fff), rx, 0);
    }
}

Ov010Fx *func_ov010_02203ee0(s32 a, void *b) {
    Ov010Fx *fx = func_02065f88(a, b);
    if (fx != NULL) {
        fx->timer = 0;
        fx->scale = 0;
    }
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02203f08;
    return fx;
}

}
}  // namespace m_02203ee0

class Ov010Fx {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    s32 timer;
    s32 scale;
};

extern "C" {

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov010_VecScale(Ov010Vec *out, const Ov010Vec *in, s32 sc) {
    out->x = Ov010_FxMul(in->x, sc);
    out->y = Ov010_FxMul(in->y, sc);
    out->z = Ov010_FxMul(in->z, sc);
}

void func_ov010_02203f08(Ov010Fx *fx) {
    Ov010Vec v;
    if (fx == NULL) {
        return;
    }
    if (fx->timer < 0x14) {
        fx->scale += 0x20;
        fx->scale = Ov010_Clamp(fx->scale, 0, 0x600);
    } else {
        fx->scale += 0x100;
        fx->scale = Ov010_Clamp(fx->scale, 0, 0x2000);
    }
    Ov010_VecScale(&v, &data_ov010_0220fe38, fx->scale);
    fx->v20(&v);
    fx->timer++;
}

}
