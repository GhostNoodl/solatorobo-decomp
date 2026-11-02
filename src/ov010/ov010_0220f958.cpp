#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
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

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(void *self, u8 *msg);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
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

BOOL func_ov010_0220441c(Ov010Obj02210154 *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 1:
            func_ov003_021d85c8(&self->ticker, 3, 0, 0, 0);
            break;
        case 0: {
            u16 *hp = self->hp;
            if (!Ov010_IsInvul(hp)) {
                s32 n;
                u8 st;
                FieldState *g;
                hp[2] = FLD(u16, msg, 6);
                n = func_ov003_021d6548(self, (ActorMsgHit *)(msg + 0xa));
                hp = self->hp;
                st = FLD(u8, hp, 9);
                if (hp[0] <= self->unk_f4) {
                    n = 0x15;
                    hp[0] = self->unk_f4;
                }
                if (n != 0) {
                    self->step.a = n;
                    self->step.b = Ov010_HitKind(msg[9]);
                    self->fsm->flags |= 1ull << n;
                    func_ov003_021d982c(&self->seq, 1);
                }
                if (st != 1) {
                    func_ov000_02191418(self->model, 5, 0);
                }
                g = data_ov000_021ccd54;
                g->cam.base.shakeX = 1;
                g->cam.base.shakeY = 1;
                g->cam.base.shakeZ = 1;
                g->cam.base.shakeTime = 0x14;
                g->cam.base.shakeLen = 0x1e;
                g->cam.base.shakeCur = 0x1e;
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
            o = data_ov000_021ccd68 == NULL ? NULL : (u8 *)ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        if (o != NULL && FLD(u16, o, 0xe) == 0x4817) {
            u16 *hp = self->hp;
            if (hp[0] <= self->unk_f4) {
                hp[0] = self->unk_f4 + 1;
                self->fsm->flags = 0;
            }
        }
        self->unk_124[0] = FLD(u16, o, 0x7e);
        self->unk_124[1] = 0xa00;
        self->unk_124[2] = 0x600;
        func_02049f44(data_02097e4c, self->sfx[0], &self->pos, 0);
        if (!Ov010_HasFlag(self->fsm, 0x200000)) {
            self->fsm->flags = 0;
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
struct Ov010Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

extern "C" {

extern u8 data_ov010_0220ffc4[];
extern Ov010Arena data_ov010_0220f160;
extern Ov010Arena data_ov010_0220f174;
extern const VecFx32 data_ov010_0220f150;
extern void *Heap_Alloc(u32 size);
extern void *Ov010Vt_02210280_Ctor(void *p);
extern void *Ov010Vt_022102c0_Ctor(void *p);
extern void *Ov010Vt_022102a0_Ctor(void *p);
extern void *Ov010Vt_02210260_Ctor(void *p);
extern void *Ov010Vt_02210240_Ctor(void *p);
extern void *Ov003Vt_021f7cf4_Ctor(void *p);
extern BOOL Ov003TickerSet_Init(void *p);
extern BOOL Ov003StateMachine_Init(void *p);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);

static inline Ov010CamPreset *Ov010Cam_New(void) {
    Ov010CamPreset *o = (Ov010CamPreset *)Heap_Alloc(0x20);
    if (o != NULL) {
        *(void **)o = data_ov010_0220ffc4;
        o->b0 = 0;
        o->b1 = 0;
    }
    return o;
}

static inline void Ov010Cam_Set(Ov010CamPreset *o, s32 x, s32 y, s32 z, u16 a, u16 b, s32 w) {
    if (!o->b0) {
        o->b1 = 1;
        o->x = x;
        o->y = y;
        o->z = z;
        o->a = a;
        o->b = b;
        o->c = 0;
        o->w = w;
    }
}

void Ov010ActVt_02210154_Start(Ov010Obj02210154 *self) {
    void *o;
    s16 *p;
    u32 i;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    self->unk_f3 = 1;
    o = Heap_Alloc(0x30);
    if (o != NULL) {
        o = Ov010Vt_02210280_Ctor(o);
    }
    self->unk_104 = (VObj *)o;
    o = Heap_Alloc(0x20);
    if (o != NULL) {
        o = Ov010Vt_022102c0_Ctor(o);
    }
    self->unk_108 = (VObj *)o;
    o = Heap_Alloc(0x34);
    if (o != NULL) {
        o = Ov010Vt_022102a0_Ctor(o);
    }
    self->unk_10c = (VObj *)o;
    o = Heap_Alloc(0xc);
    if (o != NULL) {
        o = Ov010Vt_02210260_Ctor(o);
    }
    self->unk_110 = (VObj *)o;
    o = Heap_Alloc(0x20);
    if (o != NULL) {
        o = Ov010Vt_02210240_Ctor(o);
    }
    self->unk_114 = (VObj *)o;
    o = Heap_Alloc(0x10);
    if (o != NULL) {
        o = Ov003Vt_021f7cf4_Ctor(o);
    }
    self->unk_118 = (VObj *)o;
    self->unk_11c = Ov010Cam_New();
    self->unk_120 = Ov010Cam_New();
    p = (s16 *)Heap_Alloc(6);
    self->unk_124 = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    func_ov003_021d8f4c(&self->seq);
    Ov010Coll_Init(&self->coll);
    Ov003TickerSet_Init(&self->ticker);
    func_ov003_021d8c10(&self->timer);
    switch (self->kind) {
    case 0x5c04:
        self->arena = &data_ov010_0220f160;
        self->unk_15c = 0;
        self->unk_fc = data_ov010_0220ff70;
        Ov010Cam_Set(self->unk_11c, 0x1266, -0xcd1f, -0x5ee1, 0x10e8, 0xd87e, 0x10571);
        Ov010Cam_Set(self->unk_120, 0xcd, -0xd19a, -0x3800, 0xde8, 0xff7e, 0x14571);
        break;
    case 0x5c05:
        self->arena = &data_ov010_0220f174;
        self->unk_15c = 1;
        self->unk_100 = &data_ov010_0220f150;
        Ov010Cam_Set(self->unk_11c, -0x20f6, 0x13d7, 0x3c7b, 0x10ce, 0x6c1c, 0x1711f);
        Ov010Cam_Set(self->unk_120, -0xa66, 0x1a14, 0x2214, 0xd73, 0x801c, 0x144f6);
        break;
    }
    self->vfunc_a4();
    for (i = 0; i < 9; i++) {
        self->sfx[i] = -1;
    }
    self->vfunc_ac(self->sfx, 9);
    Ov003StateMachine_Init(self->unk_118);
    func_ov003_021d8a30(self->unk_118, 0, self->unk_120);
    func_ov003_021d8a30(self->unk_118, 1, self->unk_11c);
    self->model->visible = 0;
    self->target = FLD(u16, func_ov000_0219bf90(), 0xc);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220f0a0);
    }
    func_ov003_021cf400(1);
    self->mode = 2;
}

}
}  // namespace m_022046ac

// ---- merged from ov010_02204aac.cpp
namespace m_02204aac {
// The state-handler class: complete, so that the dispatcher reads its fields by name.
class Ov010Cls : public Ov010Obj02210154 {
};
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};

extern "C" {

extern void func_ov000_0218d7e8(void *self, u8 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

void func_ov010_02204aac(Ov010Obj02210154 *self) {
    func_ov003_021da40c(self->fsm);
    func_ov000_0218d7e8(self, self->fsm->current);
}

void func_ov010_02204ad0(void) {
}

void func_ov010_02204ad4(Ov010Obj02210154 *self) {
    BOOL go = FALSE;
    self->unk_93_4 = 0;
    if (func_ov003_021da03c(self) || self->unk_f2 != 0) {
        go = TRUE;
    }
    self->unk_f2 = 0;
    if (!go) {
        return;
    }
    self->unk_c4 = 0;
    self->unk_93_4 = 1;
    func_ov003_021d8fc0(&self->seq);
    if (func_ov003_021d9878(&self->seq)) {
        Ov010B2 r = func_ov003_021d9644(&self->seq);
        self->step = r;
        func_ov000_02198360(self->fsm, r.a, 1);
    }
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void VEC_MultAdd(s32 a, const VecFx32 *b, const VecFx32 *c, VecFx32 *out);


void func_ov010_02204b74(Ov010Cls *self) {
    u32 i;
    Robo021ca458 *pl;
    s16 *p;
    u8 key;
    key = self->fsm->current;
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        self->mode = func_ov003_021cf408();
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov010_VecCopy(&pl->unk_b90, &self->pos);
        pl->unk_b9c = 0x800;
    }
    p = self->unk_124;
    if (p != NULL) {
        VecFx32 v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &self->pos, &self->pos);
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    func_ov010_0220d858(&self->coll);
    self->ticker.vfunc_0c();
    self->timer.vfunc_0c();
    if (((VObj *)self->unk_118) != NULL) {
        ((VObj *)self->unk_118)->vfunc_0c();
    }
}

}
}  // namespace m_02204aac

// ---- merged from ov010_02204cdc.cpp
namespace m_02204cdc {
extern "C" {

extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);

void func_ov010_02204cdc(Ov010Obj02210154 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    func_ov000_02190cb0(self->model, data_ov010_0220f050, 0x266, 0);
    func_ov000_021915a0(self->model);
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    self->fsm->st++;
}

struct Ov010Mtx33 {
    s32 m[3][3];
};

extern void *data_02097e4c;
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void func_ov010_02209578(VObj *t, s32 a, const s32 *rect, const VecFx32 *circ, u16 d, u16 e);
extern void func_ov010_02204030(VecFx32 *out, void *c, const VecFx32 *target, s32 n, u16 ang);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern u32 Rand_Get(void);
extern s32 Rand_PlusMinus(s32 n);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33 *m, VecFx32 *o);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void VEC_Normalize(VecFx32 *a, VecFx32 *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_ov010_02207828(void *self);
extern void Actor_TurnToPos(void *self, void *t, s32 a);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_021911c8(void *p, s32 a);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov010_0220984c(void *t, u16 a);

static inline VecFx32 Ov010d_Pt(Ov010Obj02210154 *self) {
    VecFx32 p;
    func_ov010_02204030(&p, self->arena, &self->pos, 4, 0);
    return p;
}

static inline void Ov010d_Rot(VecFx32 *v, u16 ang) {
    Ov010Mtx33 m;
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline s32 Ov010d_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010d_PolarVec(VecFx32 *v, s32 r, u16 ang) {
    Ov010Mtx33 m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010d_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

void func_ov010_02204d44(Ov010Obj02210154 *self) {
    BOOL flag = FALSE;
    switch (self->fsm->st) {
    case 0:
        func_ov010_0220d918(&self->coll, func_ov010_0220d77c);
        if (Ov010Coll_GetCount(&self->coll) >= 5) {
            self->fsm->st = 0x32;
            break;
        }
        self->fsm->st = 10;
    case 10: {
        Robo021ca458 *pl;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_ov000_02190cb0(self->model, data_ov010_0220f040, 0x800, 1);
        pl = func_ov000_0219bf90();
        func_ov010_02209578(self->unk_104, self->unk_15c, self->unk_fc, self->unk_100, self->id, pl->id);
        Ov010Coll_SetHandler(&self->coll, self->unk_104);
        self->fsm->st = 11;
    }
    case 11:
        flag = TRUE;
        self->fsm->timer++;
        if (self->fsm->timer > 0x1e) {
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        }
        break;
    case 0x14: {
        flag = TRUE;
        {
        VecFx32 q = Ov010d_Pt(self);
        VecFx32 d;
        VecFx32 v;
        u16 r;
        Ov010Arena *c;
        s32 y;
        VObj *e;
        c = self->arena;
        d.x = q.x - c->center.x;
        d.y = q.y - c->center.y;
        d.z = q.z - c->center.z;
        r = Ov003Vec_Yaw(&d);
        if (!(Rand_Get() & 1)) {
            r += 0x3fff;
        } else {
            r += 0xc000;
        }
        c = self->arena;
        y = c->center.y;
        Ov010d_PolarVec(&v, c->radius, r);
        VEC_Add(&v, &c->center, &v);
        v.y = y;
        v.y += Rand_PlusMinus(0x1000);
        self->unk_b8 = v;
        self->moveDir.x = v.x - self->pos.x;
        self->moveDir.y = v.y - self->pos.y;
        self->moveDir.z = v.z - self->pos.z;
        VEC_Normalize(&self->moveDir, &self->moveDir);
        self->moveYaw = FX_Atan2(self->moveDir.x, self->moveDir.z);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        e = func_ov010_0220eaf0(self, &self->pos, &v);
        e->vfunc_0c(0x2000);
        self->fsm->st = 0x15;
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            func_02049f44(data_02097e4c, self->sfx[3], &self->pos, 0);
        }
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        }
        break;
    }
    case 0x15:
        flag = TRUE;
        if (Ov010Coll_IsFree(&self->coll)) {
            self->fsm->st = 0x1e;
        }
        func_ov010_02207828(self);
        Actor_TurnToPos(self, self->arena, 0x400);
        break;
    case 0x1e:
        func_ov010_02207828(self);
        Actor_TurnToPos(self, self->arena, 0x400);
        FLD(Ov010Flags8, func_ov000_02190a30(self->model, 0), 0x111).b3 = 0;
        func_ov000_021911c8(self->model, 0x2000);
        self->fsm->st = 0x1f;
        break;
    case 0x1f:
        if (self->model->anim_state == 1) {
            func_ov010_0220984c(self->unk_108, self->id);
            Ov010Coll_SetHandler(&self->coll, self->unk_108);
            self->fsm->st = 0x28;
            func_02049f44(data_02097e4c, self->sfx[4], &self->pos, 0);
        }
        func_ov010_02207828(self);
        Actor_TurnToPos(self, self->arena, 0x400);
        break;
    case 0x28:
        if (Ov010Coll_IsFree(&self->coll) && func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov010_0220f050, 0x266, 1);
            func_ov000_021915a0(self->model);
            self->fsm->st = 0x32;
        }
        func_ov010_02207828(self);
        Actor_TurnToPos(self, self->arena, 0x400);
        break;
    case 0x32:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
    if (flag && self->model->anim_state == 2) {
        FLD(Ov010Flags8, func_ov000_02190a30(self->model, 0), 0x111).b3 = 1;
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
extern void func_ov010_0220a040(VObj *self, u16 a, s32 b, const s32 *rect, const VecFx32 *circ, u16 e, u16 f);
extern void Ov003StateMachine_Leave(void *p);

void func_ov010_0220522c(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->st = 0x10;
        break;
    case 0x10:
        func_ov000_02190cb0(self->model, data_ov010_0220f040, 0x266, 0);
        self->fsm->st = 0x11;
        func_02049f44(data_02097e4c, self->sfx[2], &self->pos, 0);
    case 0x11:
        self->fsm->timer++;
        if (self->fsm->timer > 0x32) {
            self->fsm->timer = 0;
            self->fsm->st = 0x20;
        }
        break;
    case 0x20: {
        Robo021ca458 *pl = func_ov000_0219bf90();
        func_ov010_0220a040(self->unk_10c, self->step.b, self->unk_15c, self->unk_fc,
                            self->unk_100, self->id, pl->id);
        Ov010Coll_SetHandler(&self->coll, self->unk_10c);
        self->fsm->st = 0x21;
        break;
    }
    case 0x21:
        if (Ov010Coll_IsFree(&self->coll) && func_ov000_02191120(self->model)) {
            self->fsm->st = 0x30;
        }
        if (func_ov000_02191120(self->model)) {
            func_ov003_021d8a7c(self->unk_118, 1);
        }
        break;
    case 0x30:
        Ov010Coll_SetHandler(&self->coll, self->unk_110);
        self->fsm->st = 0x31;
        break;
    case 0x31:
        if (Ov010Coll_IsFree(&self->coll)) {
            Ov003StateMachine_Leave(self->unk_118);
            self->fsm->st = 0x40;
        }
        break;
    case 0x40:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
    if (func_ov000_02191120(self->model)) {
        func_ov000_02190cb0(self->model, data_ov010_0220f050, 0x800, 0);
        func_ov000_021915a0(self->model);
    }
}

}
}  // namespace m_0220522c

// ---- merged from ov010_02205444.cpp
namespace m_02205444 {
struct Ov010Mtx33 {
    s32 m[9];
};

extern "C" {

extern void *data_02097e4c;
extern const Ov010Blk12 data_ov010_0220f0b4;
extern const Ov010Blk12 data_ov010_0220f0c0;
extern const Ov010Blk12 data_ov010_0220f0cc;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov000_02191618(void *a);
extern BOOL func_ov000_02191120(void *p);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(VecFx32 *v, Ov010Mtx33 *m, VecFx32 *out);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Normalize(const VecFx32 *in, VecFx32 *out);
extern u16 FX_Atan2(s32 y, s32 x);
extern VObj *func_02065f88(s32 id, VecFx32 *pos);
extern void func_ov010_02207828(void *self);
extern void Actor_TurnToActor(void *self, void *other, s32 a);
extern VObj *Effect3D_Create(const char *a, const char *b, s32 c, void *d);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void Actor_Move(void *self, s32 a);

static inline s32 Ov010f_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010f_PolarVec(VecFx32 *v, s32 r, u16 ang) {
    Ov010Mtx33 m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010f_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline VecFx32 Ov010_Center(Actor *self) {
    VecFx32 v;
    v.x = self->pos.x;
    v.y = self->pos.y + self->height / 2;
    v.z = self->pos.z;
    return v;
}

static inline void Ov010_ClearSpeed(Ov010Obj02210154 *self) {
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
}

void func_ov010_02205444(Ov010Obj02210154 *self) {
    ActorSub40 *st = self->fsm;
    self->unk_f2 = 1;
    switch (st->st) {
    case 0: {
        u8 k;
        func_ov000_02190cb0(self->model, data_ov010_0220f02c, 0x266, 0);
        func_ov000_021915a0(self->model);
        func_ov003_021d8a7c(self->unk_118, 0);
        k = self->step.b;
        switch (k) {
        case 1:
            self->fsm->st = 10;
            break;
        case 2:
            self->fsm->st = 0x14;
            break;
        }
        func_02049f44(data_02097e4c, 0x36, &self->pos, 0);
        break;
    }
    case 10: {
        VecFx32 v;
        VecFx32 d;
        Ov010Arena *t = self->arena;
        u16 ang;
        s32 y;
        d.x = self->pos.x - t->center.x;
        d.y = self->pos.y - t->center.y;
        d.z = self->pos.z - t->center.z;
        ang = Ov003Vec_Yaw(&d);
        t = self->arena;
        y = t->center.y;
        Ov010f_PolarVec(&v, t->radius, ang);
        VEC_Add(&v, &t->center, &v);
        v.y = y;
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        self->moveDir.x = v.x - self->pos.x;
        self->moveDir.y = v.y - self->pos.y;
        self->moveDir.z = v.z - self->pos.z;
        VEC_Normalize(&self->moveDir, &self->moveDir);
        self->moveYaw = FX_Atan2(self->moveDir.x, self->moveDir.z);
        {
            Ov010_ClearSpeed(self);
            VecFx32 c = Ov010_Center(self);
            func_02065f88(0x5e2, &c)->vfunc_0c(0x3000);
        }
        self->fsm->st = 0xb;
        break;
    }
    case 0xb:
        func_ov010_02207828(self);
        if (self->fsm->timer % 30 == 0) {
            func_02065f88(0x66, &self->pos)->vfunc_0c(0x2800);
        }
        self->fsm->timer++;
        st = self->fsm;
        if (st->timer > 0x3c) {
            st->timer = 0;
            self->fsm->st = 0x1e;
        }
        Actor_TurnToActor(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x14:
        st->timer++;
        st = self->fsm;
        if (st->timer > 0xf) {
            st->timer = 0;
            self->fsm->st = 0x1e;
        }
        Actor_TurnToActor(self, func_ov000_0219bf90(), 0x800);
        break;
    case 0x1e: {
        VecFx32 a;
        VecFx32 b;
        VecFx32 c2;
        VObj *o2;
        *(Ov010Blk12 *)&a = data_ov010_0220f0c0;
        *(Ov010Blk12 *)&b = data_ov010_0220f0cc;
        func_ov003_021d9980(&c2, self->rot_y, &b);
        self->moveYaw = self->rot_y;
        o2 = Effect3D_Create(data_ov010_0220f054, data_ov010_0220f04c, 0, &self->pos);
        FLD(u8, o2, 0x28) = 0;
        o2->vfunc_34(0, self->moveYaw, 0);
        o2->vfunc_10(&a);
        o2->vfunc_20(&c2);
        self->fsm->st = 0x1f;
        func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        break;
    }
    case 0x1f:
        st->timer++;
        st = self->fsm;
        if (st->timer > 0x19) {
            st->timer = 0;
            self->fsm->st = 0x28;
        }
        break;
    case 0x28: {
        FieldState *g;
        VObj *e;
        func_ov000_02190cb0(self->model, data_ov010_0220f030, 0x266, 0);
        func_ov000_021915a0(self->model);
        Ov010_ClearSpeed(self);
        g = data_ov000_021ccd54;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0xf;
        g->cam.base.shakeLen = 0x28;
        g->cam.base.shakeCur = 0x28;
        self->fsm->st = 0x29;
        VecFx32 o = {0, 0, 0};
        o.y = self->height / 2;
        e = func_ov003_021da788(0x4b0, self, &o);
        e->vfunc_34(0, self->rot_y, 0);
        e->vfunc_0c(0x1800);
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            func_02049f44(data_02097e4c, self->sfx[7], &self->pos, 0);
        }
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        break;
    }
    case 0x29: {
        Ov010Arena *t = self->arena;
        VecFx32 f;
        s32 dx = t->center.x - self->pos.x;
        s32 dy = t->center.y;
        s32 dz = t->center.z;
        dy -= self->pos.y;
        dz -= self->pos.z;
        s32 sv;
        func_ov003_021d9980(&f, self->moveYaw, (VecFx32 *)&data_ov010_0220f0b4);
        if ((s32)(((s64)f.x * dx + (s64)f.y * dy + (s64)f.z * dz + 0x800) >> 12) < 0) {
            if (VEC_Distance(&self->arena->center, &self->pos) >=
                self->arena->radius + 0x3000) {
                self->fsm->timer = 0;
                self->fsm->st = 0x32;
            }
        }
        func_ov000_0219aae8(self, self, 0x8c, 0x30, 2, 0, 0, 0x800, 0x3000, 0x64, 0x1000);
        self->speed += 0x266;
        sv = self->speed;
        self->speed = sv > 0x1000 ? 0x1000 : (sv < 0 ? 0 : sv);
        Actor_Move(self, 0x1000);
        self->hp[5] = 1;
        break;
    }
    case 0x32:
        func_ov000_02190cb0(self->model, data_ov010_0220f034, 0x266, 0);
        func_ov000_02191618(self->model);
        self->friction = 0x400;
        self->fsm->st = 0x33;
        break;
    case 0x33:
        if (func_ov000_02191120(self->model)) {
            Ov010_ClearSpeed(self);
            self->fsm->st = 0x3c;
        }
        Actor_Move(self, 0x1000);
        break;
    case 0x3c:
        self->rot_y += 0x7fff;
        func_ov000_02190cb0(self->model, data_ov010_0220f050, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x46;
        break;
    case 0x46:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
}

}
}  // namespace m_02205444

// ---- merged from ov010_02205c30.cpp
namespace m_02205c30 {
extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void Actor_TurnToActor(void *self, void *target, s32 a);
extern void func_ov000_0218d46c(void *a, u16 b, s32 c);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern u8 *func_02070558(u16 id);
extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void func_ov010_0220de4c(void *p, u8 a);
extern VObj *func_02065f88(s32 a, VecFx32 *b);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

void func_ov010_02205c30(Ov010Obj02210154 *self) {
    Actor *tgt;
    s32 r = self->unk_b0->unk_02 * 2;
    {
        u16 id = self->target;
        tgt = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov010_0220f03c, 0x800, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 1;
        return;
    case 1:
        Actor_TurnToActor(self, tgt, r);
        if (self->model->anim_state == 1) {
            self->fsm->st = 2;
        }
        return;
    case 2: {
        u8 *res;
        u8 *ent;
        if (self->model->anim_state != 3) {
            return;
        }
        res = func_02070558(self->kind);
        ent = res != NULL ? res + 0x3a : NULL;
        if (ent == NULL || FLD(u16, ent, 0) == 0xffff) {
            self->fsm->st = 4;
        } else {
            VecFx32 v;
            Model0218fe1c *m = self->model;
            Actor *o;
            v.x = ((s16)m->unk_c6) << 4;
            v.y = ((s16)m->unk_c8) << 4;
            v.z = ((s16)m->unk_ca) << 4;
            func_01ffc9fc(&v, &v, self->rot_y);
            VEC_Add(&v, &self->pos, &v);
            o = func_ov003_021d69f0(self, 0x4818, &v, &self->rot_x, tgt);
            if (o != NULL) {
                o->unk_18 = FLD(s8, ent, 2);
                func_ov010_0220de4c(o, self->step.b);
            }
            self->fsm->st = 3;
            func_02065f88(0x12c, &v)->vfunc_0c(0x2000);
            func_02049f44(data_02097e4c, 0x65, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
        }
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            func_02049f44(data_02097e4c, self->sfx[5], &self->pos, 0);
        }
    }
    case 3: {
        u8 *a;
        u16 id = self->target_id;
        a = data_ov000_021ccd68 == NULL ? NULL : (u8 *)ActorMgr_GetActor(data_ov000_021ccd68, id);
        if (a == NULL) {
            self->fsm->st = 4;
            return;
        }
        func_ov000_0218d46c(a, self->id, 0xb);
        self->target_id = 0xffff;
        self->fsm->st = 4;
        return;
    }
    case 4:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov010_0220f050, 0xcd, 0);
        func_ov000_021915a0(self->model);
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_ec_0 = 1;
        func_ov000_02198360(self->fsm, 1, 0);
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
}


extern void *data_02097e4c;
extern VecFx32 data_ov010_0220f0b4;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern BOOL func_ov000_02191120(void *p);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov000_02191618(void *a);
extern u8 *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 Rand_PlusMinus(s32 max);
extern void Ov003StateMachine_Leave(void *p);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);
extern void Actor_Move(void *self, s32 a);
extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);
extern void Actor_TurnToPos(void *self, void *t, s32 a);

static inline BOOL Ov010f_Arrived(const VecFx32 *a, const VecFx32 *b) {
    return Ov003Vec_DistSq(a, b) == 0 ? TRUE : FALSE;
}

void func_ov010_02205f40(Ov010Obj02210154 *self) {
    func_ov003_021d982c(&self->seq, 1);
    self->unk_f1 = 0;
    switch (self->fsm->st) {
    case 0: {
        u16 ang;
        void *t;
        func_ov000_02190cb0(self->model, data_ov010_0220f038, 0x1000, 1);
        func_ov000_02191418(self->model, 5, 1);
        func_ov000_02191618(self->model);
        self->unk_92 = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->targetObj->target = 0xffff;
        if (self->hp != NULL) {
            t = func_ov000_02199f60(self->hp);
            if (t == NULL || t == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(FLD(s32, t, 0x70) - self->pos.x, FLD(s32, t, 0x78) - self->pos.z);
            }
        } else {
            ang = self->rot_y;
        }
        self->unk_96 = ang;
        self->moveYaw = self->unk_96 + 0x8000 + Rand_PlusMinus(0x2000);
        Ov003StateMachine_Leave(self->unk_118);
        Ov010Coll_ClearHandler(&self->coll);
        func_ov003_021d969c(&self->seq, 0);
        switch (self->step.b) {
        case 1:
            self->fsm->st = 0x10;
            break;
        case 2:
            self->fsm->st = 0x20;
            break;
        }
        break;
    }
    case 0x10:
        self->speed = 0x1000;
        self->friction = 0x400;
        self->fsm->st = 0x11;
        func_02049f44(data_02097e4c, self->sfx[1], &self->pos, 0);
    case 0x11: {
        VecFx32 v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, self->moveYaw, &v);
        Ov003Vec_MultAdd(&self->pos, &v, &self->pos, self->speed, self->velY);
        func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
        if (self->speed < 0x40) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if (self->speed == 0) {
            self->fsm->st = 0x50;
        }
        break;
    }
    case 0x20:
        self->unk_b8 = self->pos;
        self->speed = 0x500;
        self->velY = 0x200;
        self->gravity = 0x18;
        self->friction = 0xf00;
        self->fsm->st = 0x21;
        func_02049f44(data_02097e4c, self->sfx[1], &self->pos, 0);
    case 0x21:
        self->fsm->timer++;
        if (self->fsm->timer >= 0x14) {
            self->fsm->timer = 0;
            self->fsm->st = 0x30;
        }
        Actor_Move(self, 0);
        break;
    case 0x30:
        func_ov000_02190cb0(self->model, data_ov010_0220fefc, 0x266, 1);
        func_ov000_02191418(self->model, 5, 1);
        func_ov000_02191618(self->model);
        self->gravity -= 2;
        self->fsm->st = 0x31;
        break;
    case 0x31:
        if (self->model->anim_state == 1) {
            self->fsm->st = 0x40;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x666;
        }
        Actor_Move(self, 0);
        break;
    case 0x40: {
        VecFx32 t;
        t.x = self->unk_b8.x;
        t.y = self->unk_b8.y;
        t.z = self->unk_b8.z;
        if (Ov003Vec_DistSq(&t, &self->pos) < 0x9000) {
            self->friction = 0x1000;
        }
        func_ov003_021d9dbc(&self->pos, &t, &self->pos, self->speed, self->velY);
        func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
        self->moveYaw = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
        Actor_TurnToPos(self, self->arena, 0x400);
        if (Ov010f_Arrived(&t, &self->pos)) {
            self->fsm->st = 0x50;
        }
        break;
    }
    case 0x50:
        ((VObj *)self)->vfunc_a4();
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}


struct Ov010G54b {
    u8 unk_000[0x1cc];
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov010G54b *data_ov000_021ccd54;
extern void func_0203f364(ActorSub48 *p);
extern void func_0203cb78(s32 a, s32 b, s32 c);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern BOOL Ov003Timer_IsStopped(void *a);
extern u8 *func_ov000_02190a30(void *p, s32 a);

static inline s32 Ov010g_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

// The screen argument of func_0203cb78 (its callers pass 0, 1 or -1).
// As an enum local it is not propagated, so its `mov #0` is listed before
// the jump's loads, as in the ROM (round o4B).
typedef enum { OV010_FADE_SCREEN_MAIN = 0, OV010_FADE_SCREEN_SUB = 1 } Ov010FadeScreen;

static inline void Ov010_Jump640c(Ov010Obj02210154 *self) {
    self->moveYaw = self->moveYaw + (u16)(self->rot_y + 0x7fff);
    self->speed = 0x280;
    self->velY = 0x180;
    self->gravity = 0xb;
    self->friction = 0xf00;
}

void func_ov010_0220640c(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m48;
        ActorSub44 *n;
        VObj *o;
        Ov010FadeScreen scr;
        func_ov003_021d97fc(&self->seq, 1);
        m48 = self->hit;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        Ov003StateMachine_Leave(self->unk_118);
        func_ov000_02190cb0(self->model, data_ov010_0220f038, 0x800, 1);
        func_ov000_02191418(self->model, 5, 1);
        scr = OV010_FADE_SCREEN_MAIN;
        Ov010_Jump640c(self);
        func_0203cb78(0x1e000, 1, scr);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4817, 0x15);
        o = func_02065f88(0x69, &self->pos);
        if (o != NULL) {
            o->vfunc_0c(0x5000);
        }
        func_02049f44(data_02097e4c, self->sfx[1], &self->pos, 0);
        self->fsm->st = 1;
        return;
    }
    case 1:
        self->fsm->timer++;
        if (self->fsm->timer == 0x1e) {
            func_ov003_021d8eac(&self->timer, self, 0x1000, 0);
            self->gravity >>= 1;
            self->velY -= self->velY >> 2;
        }
        if (self->fsm->timer >= 0x5a) {
            self->gravity = 0;
            self->velY = Ov010g_Mul(self->velY, 0xf80);
        }
        if (self->fsm->timer >= 0x5a && Ov003Timer_IsStopped(&self->timer)) {
            VObj *o = func_02065f88(0x69, &self->pos);
            if (o != NULL) {
                o->vfunc_0c(0x5000);
            }
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        Actor_Move(self, 0);
        return;
    case 2:
        func_ov000_02190cb0(self->model, data_ov010_0220f028, 0x266, 0);
        func_ov000_021915a0(self->model);
        FLD(u16, func_ov000_02190a30(self->model, 0), 0x112) = 0x800;
        self->gravity = 0;
        self->velY = Ov010g_Mul(self->velY, 0xf80);
        self->fsm->timer++;
        if (self->fsm->timer > 0x78) {
            self->fsm->timer = 0;
            self->fsm->st = 3;
        }
        Actor_Move(self, 0);
        return;
    case 3:
        data_ov000_021ccd54->b0 = 1;
        func_ov003_021d6a3c(self, self->unk_f3, 1, 1);
        self->fsm->st = 4;
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
extern void func_ov010_02206784(Ov010Obj02210154 *self);
extern void func_ov010_02206974(Ov010Obj02210154 *self);

void func_ov010_02206758(Ov010Obj02210154 *self) {
    switch (self->step.b) {
    case 1:
        func_ov010_02206784(self);
        break;
    case 2:
        func_ov010_02206974(self);
        break;
    }
}

extern void *data_02097e4c;
extern void func_ov010_02204030(VecFx32 *out, void *c, const VecFx32 *target, s32 n, u16 ang);
extern void VEC_Normalize(VecFx32 *a, VecFx32 *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov010_02207828(void *self);
extern void Actor_TurnToPos(void *self, void *t, s32 a);

void func_ov010_02206784(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0: {
        VecFx32 p;
        VObj *e;
        u16 d;
        func_ov010_02204030(&p, self->arena, &self->pos, 4, 0);
        Ov010_VecCopy(&self->unk_b8, &p);
        self->moveDir.x = p.x - self->pos.x;
        self->moveDir.y = p.y - self->pos.y;
        self->moveDir.z = p.z - self->pos.z;
        VEC_Normalize(&self->moveDir, &self->moveDir);
        self->moveYaw = FX_Atan2(self->moveDir.x, self->moveDir.z);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        e = func_ov010_0220eaf0(self, &self->pos, &p);
        e->vfunc_0c(0x2000);
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->fsm->st = 1;
        d = FLD(u16, e, 0x66) - self->rot_y;
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(self->model, data_ov010_0220f048, 0x800, 0);
            return;
        }
        if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(self->model, data_ov010_0220f044, 0x800, 0);
        }
        break;
    }
    case 1:
        func_ov010_02207828(self);
        Actor_TurnToPos(self, self->arena, 0x400);
        if (self->speed == 0) {
            self->fsm->st = 0x100;
        }
        break;
    case 0x100:
        func_ov000_02190cb0(self->model, data_ov010_0220f050, 0xcd, 0);
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
}

struct Ov010Mtx33f {
    s32 m[9];
};

extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void MTX_RotY33_(Ov010Mtx33f *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33f *m, VecFx32 *o);
extern u16 func_ov010_02208e90(s32 a, s32 b);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);

static inline s32 Ov010f_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010f_PolarVec(VecFx32 *v, s32 r, u16 ang) {
    Ov010Mtx33f m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010f_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

static inline void Ov010f_ClearVel(Ov010Obj02210154 *self) {
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
}

void func_ov010_02206974(Ov010Obj02210154 *self) {
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;
    if ((u8 *)data_ov000_021ccd54 + 0xf4 == NULL) {
        self->fsm->st = 0x100;
    } else {
        Ov010Arena *t = self->arena;
        s32 cross;
        u16 ang;
        a.x = self->pos.x - t->center.x;
        a.y = self->pos.y - t->center.y;
        a.z = self->pos.z - t->center.z;
        VEC_Normalize(&a, &a);
        b = data_ov000_021ccd54->cam.base.eye;
        t = self->arena;
        b.x = t->center.x - b.x;
        b.y = t->center.y - b.y;
        b.z = t->center.z - b.z;
        VEC_Normalize(&b, &b);
        cross = (s32)(((s64)b.z * a.x - (s64)b.x * a.z + 0x800) >> 12);
        {
            s32 dist = VEC_Distance(&self->pos, &self->arena->center);
            if (cross > 0) {
                ang = 0xffff - func_ov010_02208e90(dist, self->unk_b0->unk_00);
            } else {
                ang = func_ov010_02208e90(dist, self->unk_b0->unk_00);
            }
        }
        func_ov003_021d9d28(&c, &self->pos, ang, self->arena);
    }
    switch (self->fsm->st) {
    case 0: {
        VecFx32 d;
        VecFx32 v;
        Ov010Arena *t = self->arena;
        u16 r;
        s32 y;
        d.x = self->pos.x - t->center.x;
        d.y = self->pos.y - t->center.y;
        d.z = self->pos.z - t->center.z;
        r = Ov003Vec_Yaw(&d);
        t = self->arena;
        y = t->center.y;
        Ov010f_PolarVec(&v, t->radius, r);
        VEC_Add(&v, &t->center, &v);
        v.y = y;
        self->unk_b8 = v;
        self->moveDir.x = v.x - self->pos.x;
        self->moveDir.y = v.y - self->pos.y;
        self->moveDir.z = v.z - self->pos.z;
        VEC_Normalize(&self->moveDir, &self->moveDir);
        self->moveYaw = FX_Atan2(self->moveDir.x, self->moveDir.z);
        Ov010f_ClearVel(self);
        self->fsm->st = 1;
        break;
    }
    case 1:
        func_ov010_02207828(self);
        Actor_TurnToPos(self, self->arena, 0x400);
        if (self->speed == 0) {
            self->fsm->st = 0x30;
        }
        break;
    case 0x30: {
        VObj *e;
        u16 d;
        Ov010f_ClearVel(self);
        self->speed = Ov010f_FxMul(self->unk_b0->unk_00, 0x1800);
        e = func_ov010_0220eaf0(self, &self->pos, &c);
        e->vfunc_0c(0x2000);
        d = FLD(u16, e, 0x66) - self->rot_y;
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(self->model, data_ov010_0220f048, 0x800, 0);
        } else if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(self->model, data_ov010_0220f044, 0x800, 0);
        }
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->fsm->st = 0x31;
        self->fsm->timer = 0;
        break;
    }
    case 0x31: {
        ActorSub40 *m = self->fsm;
        s32 dot = (s32)(((s64)a.x * b.x + (s64)a.y * b.y + (s64)a.z * b.z + 0x800) >> 12);
        if (dot > 0xc00 || (m->timer++, m->timer > 0x12c)) {
            self->moveDir.x = c.x - self->pos.x;
            self->moveDir.y = c.y - self->pos.y;
            self->moveDir.z = c.z - self->pos.z;
            VEC_Normalize(&self->moveDir, &self->moveDir);
            self->speed = 0x300;
            func_ov000_02190cb0(self->model, data_ov010_0220f050, 0xcd, 0);
            self->fsm->st = 0x40;
        } else {
            self->pos = c;
            Actor_TurnToPos(self, self->arena, 0x400);
            func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
            break;
        }
    }
    case 0x40:
        if (self->speed < 0x38) {
            Ov010f_ClearVel(self);
            self->fsm->st = 0x100;
        }
        self->friction = 0xe80;
        Ov003Vec_MultAdd(&self->pos, &self->moveDir, &self->pos, self->speed, self->velY);
        Actor_TurnToPos(self, self->arena, 0x400);
        func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
        break;
    case 0x100:
        func_ov003_021d969c(&self->seq, 1);
        break;
    }
}

}
}  // namespace m_02206758

// ---- merged from ov010_02206f54.cpp
namespace m_02206f54 {
extern "C" {

extern void *data_02097e4c;
extern void Ov003StateMachine_Leave(void *p);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern VObj *func_02065f88(s32 a, VecFx32 *b);

static inline VecFx32 Ov010_Center(Actor *self) {
    VecFx32 p;
    p.x = self->pos.x;
    p.y = self->pos.y + self->height / 2;
    p.z = self->pos.z;
    return p;
}

void func_ov010_02206f54(Ov010Obj02210154 *self) {
    self->unk_f2 = 1;
    self->unk_f1 = 1;
}

void func_ov010_02206f64(Ov010Obj02210154 *self) {
    self->unk_f2 = 1;
    if (self->fsm->st != 0) {
        return;
    }
    func_ov003_021d8a7c(self->unk_118, 0);
    func_ov003_021d969c(&self->seq, 1);
    self->fsm->st++;
    func_02049f44(data_02097e4c, self->sfx[6], &self->pos, 0);
}

// Reads the state word through a const view (a const getter is not merged with the later
// plain read of the same field, so the increment reloads it as in the target).
static inline u16 Ov010_GetState(const ActorSub40 *state) {
    return state->st;
}

void func_ov010_02206fd0(Ov010Obj02210154 *self) {
    ActorSub40 *m = self->fsm;
    self->unk_f2 = 1;
    if (Ov010_GetState(m) != 0) {
        return;
    }
    m->st++;
    Ov003StateMachine_Leave(self->unk_118);
}

void func_ov010_02207004(Ov010Obj02210154 *self) {
    self->unk_f2 = 1;
    if (self->fsm->st == 0) {
        Ov010Coll_SetHandler(&self->coll, self->unk_114);
        self->fsm->st++;
        return;
    }
    if (Ov010Coll_IsFree(&self->coll)) {
        func_ov003_021d969c(&self->seq, 1);
    }
}

void func_ov010_02207064(Ov010Obj02210154 *self) {
    ActorSub40 *m = self->fsm;
    switch (m->st) {
    case 0: {
        s32 sc = Ov010_FxMul(self->radius, 0x1800);
        VecFx32 q = Ov010_Center(self);
        VObj *fx = func_02065f88(0x196, &q);
        fx->vfunc_0c(sc);
        FLD(s32, fx, 0x3c) = 0x1000;
        func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        self->fsm->st = 1;
        break;
    }
    case 1:
        m->timer++;
        if (self->fsm->timer > 0x32) {
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        break;
    case 2:
        func_ov003_021d969c(&self->seq, 1);
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
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33e *m, VecFx32 *o);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void Actor_TurnToPos(void *self, void *t, s32 a);
extern void Actor_Move(void *self, s32 a);

static inline s32 Ov010e_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010e_PolarVec(VecFx32 *v, s32 r, u16 ang) {
    Ov010Mtx33e m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010e_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

void func_ov010_022071a0(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->st = 0x10;
        break;
    case 0x30:
        break;
    case 0x10:
        func_ov000_02190cb0(self->model, data_ov010_0220f050, 0x266, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x11;
        break;
    case 0x11:
        if (!func_ov010_0220794c(self)) {
            break;
        }
        self->fsm->st = 0x20;
    case 0x20: {
        VecFx32 v;
        Ov010Arena *c = self->arena;
        u16 ang = FX_Atan2(c->center.x - self->pos.x, c->center.z - self->pos.z) + 0x7fff;
        u16 d = func_ov010_02208e90(self->arena->radius, 0x3000);
        s32 y;
        VObj *e;
        u16 diff;
        if (func_0204045c() % 2 == 0) {
            ang += d;
        } else {
            ang -= d;
        }
        c = self->arena;
        y = c->center.y;
        Ov010e_PolarVec(&v, c->radius, ang);
        VEC_Add(&v, &c->center, &v);
        v.y = y;
        self->unk_b8 = v;
        self->moveYaw = FX_Atan2(v.x - self->pos.x, v.z - self->pos.z);
        self->speed = 0x2800;
        Actor_TurnToPos(self, self->arena, 0x400);
        Actor_Move(self, 0);
        self->speed = 0x400;
        e = func_ov010_0220eaf0(self, &self->pos, &v);
        e->vfunc_0c(0x2000);
        diff = FLD(u16, e, 0x66) - self->rot_y;
        if (diff >= 0x1400 && diff <= 0x6c00) {
            func_ov000_02190cb0(self->model, data_ov010_0220f048, 0x800, 0);
        } else if (diff >= 0x9400 && diff <= 0xec00) {
            func_ov000_02190cb0(self->model, data_ov010_0220f044, 0x800, 0);
        }
        func_02049f44(data_02097e4c, self->sfx[8], &self->pos, 0);
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->fsm->st = 0x21;
        break;
    }
    case 0x21:
        if (VEC_Distance(&self->pos, &self->unk_b8) < 0x3000) {
            self->friction = 0xf00;
        }
        if (self->speed < 0x100) {
            func_ov000_02190cb0(self->model, data_ov010_0220f050, 0xcd, 0);
        }
        Actor_Move(self, 0);
        Actor_TurnToPos(self, self->arena, 0x400);
        if (self->speed < 4) {
            self->fsm->st = 0x30;
        }
        break;
    }
}

}
}  // namespace m_02206f54
