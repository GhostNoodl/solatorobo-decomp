#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

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
extern const VecFx32 data_ov010_0220efd0;
extern const VecFx32 data_ov010_0220efdc;
extern const VecFx32 data_ov010_0220efe8;
extern const VecFx32 data_ov010_0220eff4;
extern const VecFx32 data_ov010_0220f000;
extern const Ov010Handler data_ov010_0220f00c[2];
extern const Ov010Rot data_ov010_0220fe30;
extern const VecFx32 data_ov010_0220fe38;
extern const VecFx32 data_ov010_0220fe44;
extern const VecFx32 data_ov010_0220fe50;

static inline fx32 K(fx32 v) { return v; }

const VecFx32 data_ov010_0220f000 = {0, 0, 0};
const Ov010Handler data_ov010_0220f00c[2] = {{0, func_ov010_02202838, 0}, {1, func_ov010_022028ec, 0}};
const Ov010Rot data_ov010_0220efc8 = {0, 0, 0};
const Ov010Rot data_ov010_0220fe30 = data_ov010_0220efc8;
const VecFx32 data_ov010_0220efdc = {-0x1000, 0, 0};
const VecFx32 data_ov010_0220efd0 = {0, 0, 0x1000};
__declspec(weak) const VecFx32 data_ov010_0220fe50 = data_ov010_0220f000;
__declspec(weak) const VecFx32 data_ov010_0220efe8 = {0, 0x1000, 0};
const VecFx32 data_ov010_0220fe38 = {K(0x1000), K(0), K(0)};
__declspec(weak) const VecFx32 data_ov010_0220fe44 = data_ov010_0220efe8;
const VecFx32 data_ov010_0220eff4 = {0, 0x1be, -0x125e};

}

// ---- merged from ov010_022020c8.cpp
// The effect pair at 0xd8 (0x20, freed by the dtor).
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

// Built by ActorEx_Ctor, but not an ActorEx here: these methods use 0xce as a byte of flag bits
// and 0xcf as a byte (ActorEx::unk_ce is one u16).
struct Obj022020c8 : public Actor {
    u8 unk_ac[0x4];
    void *unk_b0;
    u8 unk_b4[0x1a];
    Ov010Flags8 unk_ce;
    u8 unk_cf;
    u16 unk_d0;
    s32 unk_d4;
    Ov010Snd *unk_d8;
    void *unk_dc;
    VecFx32 unk_e0;
    VecFx32 unk_ec;
    VecFx32 unk_f8;
    Ov010FlagObj flagObj;
};

namespace m_022020c8 {
struct Ov010Heap022 {
    u32 cur;
    u32 unk_04;
    u32 def;
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

// The state-handler class: complete, so that the dispatcher reads its fields by name.
class Ov010Cls : public Obj022020c8 {
};
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010FnEnt {
    s32 key;
    Ov010Fn fn;
};

struct Ov010FnTbl2 {
    s32 w[6];
};

extern "C" {


extern u8 data_ov010_0220fe5c[];
extern const u8 data_ov003_021f4340;
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_0203f364(void *p);
extern int func_ov003_021cf330(void *p, void *d, s32 c);

extern u8 data_ov010_0220fe6c[];
extern Ov010Heap022 *data_02097dd0;
extern void *data_0214a420;

extern void *ActorEx_Ctor(void *self);
extern void *func_ov000_0219429c(void *self);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void EffectMgr_StopLoop(void *a, s32 b);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void MI_Copy36B(void *m, void *b);
extern BOOL func_ov000_0218cea4(void *self);

static inline void Ov010_022020c8_Init(Obj022020c8 *self) {
    self->unk_ce.b0 = 0;
    self->unk_ce.b1 = 0;
    self->unk_ce.b2 = 0;
    self->unk_d0 = 0;
    self->unk_d4 = -1;
    self->unk_d8 = NULL;
    self->unk_dc = NULL;
    self->unk_f8 = self->unk_ec = self->unk_e0 = data_ov010_0220f000;
}

void *Ov010ActVt_0220fe6c_Ctor(Obj022020c8 *self) {
    ActorEx_Ctor(self);
    *(void * *)self = data_ov010_0220fe6c;
    Ov003Vt_021f79a8_Ctor(&self->flagObj);
    Ov010_022020c8_Init(self);
    return self;
}

static inline void Ov010_022020c8_Dtor(Obj022020c8 *self) {
    u32 saved;
    *(void **)self = data_ov010_0220fe6c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_d8 != NULL) {
        Ov010Snd *s = self->unk_d8;
        if (s != NULL) {
            if (s->b0) {
                s->b0 = 0;
                EffectMgr_StopLoop(data_0214a420, s->unk_0c);
                EffectMgr_StopLoop(data_0214a420, s->unk_10);
                s->unk_0c = 0;
                s->unk_10 = 0;
            }
            Heap_Free(s);
        }
        self->unk_d8 = NULL;
    }
    data_02097dd0->cur = saved;
    self->flagObj.vfunc_08();
    Ov010_022020c8_Init(self);
    Ov003Vt_021f79a8_Dtor(&self->flagObj);
    func_ov000_0219429c(self);
}

void *Ov010ActVt_0220fe6c_Dtor(Obj022020c8 *self) {
    Ov010_022020c8_Dtor(self);
    return self;
}

void *Ov010ActVt_0220fe6c_DtorDelete(Obj022020c8 *self) {
    Ov010_022020c8_Dtor(self);
    Heap_Free(self);
    return self;
}

void Ov010ActVt_0220fe6c_Draw(Obj022020c8 *self) {
    u8 m1[0x24];
    u8 m2[0x24];
    self->unk_93_0 = 1;
    MTX_RotZ33_(m1, OV010_SIN(self->rot_z), OV010_COS(self->rot_z));
    MTX_RotX33_(m2, OV010_SIN(self->rot_x), OV010_COS(self->rot_x));
    MTX_Concat33(m1, m2, m1);
    MTX_RotY33_(m2, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
    MTX_Concat33(m1, m2, m1);
    MI_Copy36B(m1, &self->model->rot);
    self->model->trans = self->pos;
    func_ov000_0218cea4(self);
}

void func_ov010_022024c4(Obj022020c8 *self, u16 a, const VecFx32 *pos, const VecFx32 *v, const Ov010Rot3 *rot) {
    if (self->unk_ce.b0) {
        return;
    }
    self->target = a;
    self->unk_d4 = 0;
    self->unk_ce.b0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    *(Ov010Rot3 *)&self->rot_x = *rot; // one 6-byte copy, as the original
    self->unk_d0 = 0;
    self->unk_e0 = data_ov010_0220f000;
}

void func_ov010_02202560(Obj022020c8 *self, u16 a, const VecFx32 *pos, const VecFx32 *v, const Ov010Rot3 *rot) {
    if (self->unk_ce.b0) {
        return;
    }
    self->target = a;
    self->unk_d4 = 1;
    self->unk_ce.b0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    *(Ov010Rot3 *)&self->rot_x = *rot; // one 6-byte copy, as the original
    self->unk_d0 = 0;
    self->unk_e0 = data_ov010_0220f000;
}

void func_ov010_02202600(Obj022020c8 *self, void *fn) {
    self->unk_dc = fn;
}

void Ov010ActVt_0220fe6c_Start(Obj022020c8 *self) {
    ActorSub48 *m;
    Ov010Snd *s;
    u8 c;
    func_ov000_02194758(self);
    self->model->visible = 0;
    func_ov000_02198360(self->fsm, 0x20, 0);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    self->hit->unk_9a_7 = 1;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    c = data_ov003_021f4340;
    self->hit->unk_9a_6 = 0;
    self->hit->unk_30 = 0;
    self->unk_44->unk_1c = self->radius * 2;
    func_ov003_021cf330(&self->flagObj, data_ov010_0220fe5c, c);
    s = (Ov010Snd *)Heap_Alloc(sizeof(Ov010Snd));
    if (s != NULL) {
        s->b0 = 0;
    }
    self->unk_d8 = s;
    Ov010Snd_Init(s, self->id);
}

static inline BOOL Ov010_GBusy(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL Ov010_GIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (Ov010_GBusy(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void Ov010ActVt_0220fe6c_Update(Ov010Cls *self) {
    Ov010FnEnt tbl[2];
    s32 key;
    u32 i;
    if (!Ov010_GIdle()) {
        return;
    }
    *(Ov010FnTbl2 *)tbl = *(const Ov010FnTbl2 *)data_ov010_0220f00c;
    key = self->unk_d4;
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

void func_ov010_02202838(Obj022020c8 *self) {
    void *m = self->fsm;
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

void func_ov010_022028ec(Obj022020c8 *self) {
    void *m = self->fsm;
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
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Add(VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void func_ov010_02203bf8(Ov010FxSet *p);

extern void *data_02097e4c;
extern void func_0203f364(void *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_ov010_02203f08(void *fx);

class Ov010Fx2 : public VObj {
public:
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
    switch (self->fsm->st) {
    case 0: {
        void *m;
        self->model->visible = 1;
        self->speed = a;
        LFLD(VecFx32, self, 0xa0).x = a;
        LFLD(VecFx32, self, 0xa0).y = a;
        LFLD(VecFx32, self, 0xa0).z = a;
        Ov010_SpawnRing(0x12c, &self->pos)->vfunc_0c(0x2000);
        self->fsm->st = 1;
        self->unk_44->unk_22_1 = 0;
        m = self->hit;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = self->model;
        FLD(u16, m, 0xb6) = 0x53ff;
        FLD(u16, m, 0xb8) = 0x53ff;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        self->model->alpha = 0x14;
        func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
        break;
    }
    case 1: {
        void *m;
        b = 0x10;
        d = 0x400;
        self->fsm->timer++;
        if (self->fsm->timer > 0x41) {
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        self->unk_44->unk_22_1 = 0;
        m = self->hit;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = self->model;
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
        self->fsm->timer++;
        if (self->fsm->timer > 0x3c) {
            Ov010FxSet *s;
            self->model->alpha = 0x1f;
            s = (Ov010FxSet *)self->unk_d8;
            if (s->b0) {
                s->b1 = 1;
                s->unk_06 = 0x1000;
            }
            self->fsm->timer = 0;
            self->fsm->st = 3;
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
    VEC_Add(&self->pos, &self->unk_e0, &self->pos);
    if ((Ov010FxSet *)self->unk_d8 != NULL) {
        func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
    }
}

void func_ov010_02202c9c(Obj022020c8 *self) {
    if (self->fsm->st == 0) {
        Ov010FxSet *s;
        self->model->alpha = 0x1f;
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x1000;
        }
        self->fsm->st++;
    }
    {
        self->unk_e0.x = Ov010_FxMul(self->unk_e0.x, 0xf80);
        self->unk_e0.y = Ov010_FxMul(self->unk_e0.y, 0xf80);
        self->unk_e0.z = Ov010_FxMul(self->unk_e0.z, 0xf80);
    }
    VEC_MultAdd(4, &data_ov010_0220fe38, &self->unk_e0, &self->unk_e0);
    VEC_Add(&self->pos, &self->unk_e0, &self->pos);
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

typedef BOOL (*Ov010HitFn)(u16 id, VecFx32 *a, VecFx32 *b);

extern "C" {
extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void EffectMgr_StopLoop(void *a, void *b);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Add(VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern u16 Ov003Vec_Pitch(VecFx32 *v);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL Hit_DiffInSphere(const VecFx32 *a, const VecFx32 *b, s32 r);
extern void func_ov010_02203bf8(Ov010Trail *p);

static inline s32 Ov010t_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov010_02202d9c(Obj022020c8 *self) {
    ActorSub40 *p40 = self->fsm;
    BOOL dir;
    BOOL done = FALSE;
    void *tgt;
    u8 chk;
    if ((p40->flags & 0x200) != 0) {
        func_ov000_02198360(p40, 9, done);
        return;
    }
    dir = done;
    tgt = NULL;
    chk = done;
    switch (p40->st) {
    case 0: {
        Model0218fe1c *m = self->model;
        Ov010Trail *s;
        FLD(u16, m, 0xb6) = 0x7fff;
        FLD(u16, m, 0xb8) = 0x7fff;
        m->blend = 0x10;
        m->blendMax = 0xf;
        self->model->alpha = 0x1f;
        s = (Ov010Trail *)self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        s = (Ov010Trail *)self->unk_d8;
        if (s->b0) {
            if (s->b2) {
                EffectMgr_StopLoop(data_0214a420, s->unk_10);
                s->unk_10 = NULL;
            }
            s->b2 = 1;
            s->unk_08 = 0x2000;
            s->b3 = 0;
        }
        self->fsm->st = 1;
        func_02049f44(data_02097e4c, 0x50, &self->pos, 0);
        break;
    }
    case 1:
        VEC_MultAdd(6, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
        func_ov003_021d9b8c(&self->unk_e0, &self->unk_e0, 0x180, 0x180);
        self->fsm->timer++;
        if (self->fsm->timer > 0x46) {
            self->fsm->timer = 0;
            self->fsm->st = 10;
            func_0204a028(data_02097e4c, 0x32, &self->pos, 8);
        }
        break;
    case 10:
        VEC_MultAdd(0x18, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
        VEC_MultAdd(6, &data_ov010_0220fe44, &self->unk_e0, &self->unk_e0);
        func_ov003_021d9aec(&self->unk_e0, &self->unk_e0, 0x700);
        self->fsm->timer++;
        if (self->fsm->timer > 0x1d) {
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        }
        break;
    case 0x15:
    case 0x14: {
        VecFx32 d;
        Ov010HitFn fn;
        dir = TRUE;
        chk = TRUE;
        {
            u16 id = self->target;
            tgt = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        {
            ActorSub40 *st = self->fsm;
            if (st->st == 0x14) {
                self->speed = 0;
                self->unk_f8 = FLD(VecFx32, tgt, 0x70);
                self->unk_f8.y += FLD(s32, FLD(void *, tgt, 0x44), 0x10);
                st->st = 0x15;
            }
        }
        d.x = self->unk_f8.x - self->pos.x;
        d.y = self->unk_f8.y - self->pos.y;
        d.z = self->unk_f8.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(self->speed, &d, &self->unk_e0, &self->unk_e0);
        VEC_MultAdd(4, &data_ov010_0220fe44, &self->unk_e0, &self->unk_e0);
        self->speed += 4;
        {
            s32 v = self->speed;
            if (v > 0x400) {
                v = 0x400;
            } else if (v < 0) {
                v = 0;
            }
            self->speed = v;
        }
        func_ov003_021d9aec(&self->unk_e0, &self->unk_e0, 0x700);
        fn = FLD(Ov010HitFn, self, 0xdc);
        if (fn != NULL) {
            if (fn(FLD(u16, tgt, 0xc), &self->unk_f8, &self->pos)) {
                self->fsm->st = 0x1e;
            }
        }
        if (VEC_Distance(&self->pos, &self->unk_f8) < 0x1000) {
            self->fsm->st = 0x28;
        }
        break;
    }
    case 0x1e: {
        VecFx32 d;
        dir = TRUE;
        chk = TRUE;
        {
            u16 id = self->target;
            if (data_ov000_021ccd68 != NULL) {
                tgt = ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
        }
        self->unk_e0.x = Ov010t_FxMul64(self->unk_e0.x, 0xe80);
        self->unk_e0.y = Ov010t_FxMul64(self->unk_e0.y, 0xe80);
        self->unk_e0.z = Ov010t_FxMul64(self->unk_e0.z, 0xe80);
        d.x = self->unk_f8.x - self->pos.x;
        d.y = self->unk_f8.y - self->pos.y;
        d.z = self->unk_f8.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x40, &d, &self->unk_e0, &self->unk_e0);
        if (VEC_Distance(&self->pos, &self->unk_f8) < 0x1000) {
            self->fsm->st = 0x28;
        }
        break;
    }
    case 100:
        // Final state: nothing to do, but the empty case sets the switch's compare tree.
        break;
    case 0x28: {
        s32 t;
        u16 col;
        Model0218fe1c *m;
        {
            u16 id = self->target;
            if (data_ov000_021ccd68 != NULL) {
                tgt = ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
        }
        t = 0x19 - self->fsm->timer;
        if (t > 0x19) {
            t = 0x19;
        } else if (t < 1) {
            t = 1;
        }
        col = (t << 5) | 0x1f | (t << 10);
        m = self->model;
        FLD(u16, m, 0xb6) = col;
        FLD(u16, m, 0xb8) = col;
        m->blend = 2;
        m->blendMax = 1;
        dir = TRUE;
        chk = TRUE;
        self->fsm->timer++;
        if (self->fsm->timer > 0x1e) {
            self->fsm->timer = 0;
            self->fsm->st = 100;
            done = TRUE;
        }
        break;
    }
    }
    if (dir) {
        VecFx32 n;
        VEC_Normalize(&self->unk_e0, &n);
        self->rot_x = Ov003Vec_Pitch(&n);
        self->rot_y = Ov003Vec_Yaw(&n);
    }
    if (chk && tgt != NULL) {
        BOOL hit;
        BOOL r;
        FLD(u16, self->hit, 0x9a) |= 0x10;
        func_ov000_021987b8(self->hit, 0, 0, 0);
        hit = FALSE;
        if (self->hit->unk_50 & 0x20000000) {
            hit = TRUE;
        }
        r = Hit_DiffInSphere(&FLD(VecFx32, tgt, 0x70), &self->pos, self->radius + FLD(s32, tgt, 0x64));
        if (hit || r) {
            done = TRUE;
        }
    }
    if (done) {
        FLD(u8, self, 0xce) |= 2;
        func_ov000_02198360(self->fsm, 0x15, 1);
    }
    VEC_Add(&self->pos, &self->unk_e0, &self->pos);
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

extern "C" {
extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern void EffectMgr_Kill(void *a, s32 b);
extern void func_ov010_02203bf8(Ov010FxSet *p);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218996c(s32 a, s32 b);
extern VObj *func_02065f88(s32 id, VecFx32 *pos);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(ActorSub48 *p);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov010_TeamBit(u16 id) {
    Actor *a = Ov010_FindActor(id);
    if (a == NULL) {
        return 0;
    }
    return (u16)(1 << (a->kind >> 12));
}

void func_ov010_022033d0(Obj022020c8 *self) {
    ActorSub40 *st = self->fsm;
    if (((const ActorSub40 *)st)->st == 0) {
        VObj *e;
        Ov010FxSet *s;
        st->st++;
        if (self->unk_ce.b1) {
            func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, Ov010_TeamBit(self->target), NULL, NULL, 0x2000, 0, 100, 0x1000);
            func_ov000_0218996c(0xf, 5);
        }
        e = func_02065f88(0x131, &self->pos);
        e->vfunc_34(0, Ov003Vec_Yaw(&data_ov010_0220fe38), 0);
        e->vfunc_0c(0x2000);
        func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 0;
            EffectMgr_Kill(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b2 = 0;
            EffectMgr_Kill(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *m;
            func_ov000_02198c8c(self->hit, 0xffff);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
    } else {
        st->timer++;
        if (st->timer > 5) {
            func_ov000_02197dec(self, 0xf, 0x63);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((VObj *)self)->vfunc_08();
        } else if (self->model != NULL) {
            self->model->alpha = 31 - self->fsm->timer * 4;
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
extern void EffectMgr_Kill(void *a, s32 b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02196060(void *self);
extern void *Target_Get(void *p);
extern void func_ov010_02203bf8(Ov010FxSet *p);

void func_ov010_0220366c(Obj022020c8 *self) {
    if (self->fsm->st == 0) {
        Ov010FxSet *s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 0;
            EffectMgr_Kill(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b2 = 0;
            EffectMgr_Kill(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
    }
    func_ov000_02195d88(self);
}

void func_ov010_022036fc(Obj022020c8 *self) {
    BOOL first = FALSE;
    if (self->fsm->st == 0) {
        first = TRUE;
    }
    func_ov000_02196060(self);
    if (first) {
        Ov010FxSet *s = (Ov010FxSet *)self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        Ov010_VecSet(&LFLD(VecFx32, self, 0xa0), 0, 0, 0);
        self->unk_ce.b2 = 1;
        self->speed = 0x4c0;
        self->target = FLD(u16, Target_Get(self->targetObj), 0x90);
    }
    func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
}

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void func_ov000_02196c40(void *self);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *o);
extern s32 func_ov000_0219a510(void *self, u16 mask, VecFx32 *pos, s32 r, s32 a, void **list);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);
extern void HitSphere_Link(ActorSub48 *p);
extern void func_0203f364(ActorSub48 *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern u16 Ov003Vec_Pitch(VecFx32 *v);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov010_02203788(Obj022020c8 *self) {
    u16 *st;
    Actor *actor;
    if (!self->unk_ce.b2) {
        self->targetObj->target = FLD(u16, func_ov000_0219bf90(), 0xc);
        func_ov000_02196c40(self);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        actor = Ov010_FindActor(self->target);
        if (actor != NULL) {
            VecFx32 c;
            VecFx32 b = func_ov003_021da214(actor);
            c.x = actor->pos.x;
            c.y = actor->pos.y;
            c.z = actor->pos.z;
            VEC_Add(&c, &b, &c);
            self->unk_ec.x = c.x - self->pos.x;
            self->unk_ec.y = c.y - self->pos.y;
            self->unk_ec.z = c.z - self->pos.z;
            VEC_Normalize(&self->unk_ec, &self->unk_ec);
        } else {
            func_ov003_021d9980(&self->unk_ec, self->rot_y, &data_ov010_0220efd0);
        }
        self->fsm->st = 10;
        break;
    case 10: {
        void *list[32];
        actor = Ov010_FindActor(self->target);
        if (actor != NULL) {
            VecFx32 c;
            VecFx32 b = func_ov003_021da214(actor);
            c.x = actor->pos.x;
            c.y = actor->pos.y;
            c.z = actor->pos.z;
            VEC_Add(&c, &b, &c);
            self->unk_ec.x = c.x - self->pos.x;
            self->unk_ec.y = c.y - self->pos.y;
            self->unk_ec.z = c.z - self->pos.z;
            VEC_Normalize(&self->unk_ec, &self->unk_ec);
        }
        if (func_ov000_0219a510(self, 0x20, &self->pos, self->radius, 0, list) != 0 ||
            (self->hit)->unk_58 != 0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->fsm, 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        self->fsm->timer++;
        if (self->fsm->timer > 0x3c) {
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        }
        break;
    }
    case 0x14: {
        void *list[32];
        if (func_ov000_0219a510(self, 0x20, &self->pos, self->radius, 0, list) != 0 ||
            (self->hit)->unk_58 != 0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->fsm, 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        self->fsm->timer++;
        if (self->fsm->timer > 0x3c) {
            func_ov000_02198360(self->fsm, 0x15, 0);
            return;
        }
        break;
    }
    }
    {
        s32 v = self->speed + 0x14;
        self->speed = v;
        if (v > 0xa00) {
            v = 0xa00;
        } else if (v < 0) {
            v = 0;
        }
        self->speed = v;
    }
    Ov003Vec_MultAdd(&self->pos, &self->unk_ec, &self->pos, self->speed, 0);
    if (self->hit != NULL) {
        ActorSub48 *o;
        BOOL f;
        if (((Ov010B0 *)self->unk_b0)->mode == 2) {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
        }
        o = NULL;
        f = FALSE;
        {
            Ov010Owner *ow = (Ov010Owner *)self->targetObj;
            if (ow != NULL && ow->id != 0xffff && ow->kind == 1) {
                s32 r = self->radius + 0x4cd;
                void *p;
                if (r < 0xccd) {
                    r = 0xccd;
                }
                (self->hit)->unk_44 = r;
                p = Target_Get(self->targetObj);
                if (p != NULL && (o = FLD(ActorSub48 *, p, 0x48)) != NULL && o->unk_9a_3) {
                    o->unk_9a_3 = 0;
                    func_0203f364(o);
                    f = TRUE;
                }
            }
        }
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (f) {
            o->unk_9a_3 = 1;
            HitSphere_Link(o);
        }
    }
    self->rot_x = Ov003Vec_Pitch(&self->unk_ec);
    self->rot_y = Ov003Vec_Yaw(&self->unk_ec);
    func_ov010_02203bf8((Ov010FxSet *)self->unk_d8);
}
}
}  // namespace m_0220366c

// ---- merged from ov010_02203ee0.cpp
namespace m_02203ee0 {
class Ov010Fx : public VObj {
public:
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
extern VObj *func_020657b0(void *a, s32 b);
extern void EffectMgr_StopLoop(void *a, s32 b);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);

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
    VecFx32 off;
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
    VObj *o;
    u16 ry;
    u16 rx;
    VecFx32 base;
    if (!self->b0) {
        return;
    }
    {
        u16 id = self->id;
        actor = data_ov000_021ccd68 == NULL ? NULL : (u8 *)ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    if (actor == NULL) {
        self->id = 0xffff;
        EffectMgr_StopLoop(data_0214a420, self->keyA);
        EffectMgr_StopLoop(data_0214a420, self->keyB);
        self->keyA = 0;
        self->keyB = 0;
        return;
    }
    if (self->b1 && self->keyA == 0) {
        self->keyA = FLD(s32, func_02065f88(0x324, &data_ov010_0220fe50), 0x24);
    }
    if (self->b2 && self->keyB == 0) {
        Ov010Fx *fx = func_02065f88(self->b3 ? 0x25e : 0x25d, &data_ov010_0220fe50);
        fx->vfunc_14(self->scale, self->scale, self->scale);
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
    base = FLD(VecFx32, actor, 0x70);
    ry = FLD(u16, actor, 0x7c);
    rx = FLD(u16, actor, 0x7e);
    if (self->keyA != 0) {
        o = func_020657b0(data_0214a420, self->keyA);
        if (o == NULL) {
            self->keyA = 0;
            self->b1 = 0;
        } else {
            VecFx32 v;
            func_ov003_021d9900(&v, ry, &self->off);
            func_ov003_021d9980(&v, rx, &v);
            VEC_Add(&v, &base, &v);
            o->vfunc_18(&v);
            o->vfunc_14(self->cur, self->cur, self->cur);
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
        VecFx32 v;
        func_ov003_021d9900(&v, ry, &self->off);
        func_ov003_021d9980(&v, rx, &v);
        VEC_Add(&v, &base, &v);
        o->vfunc_18(&v);
        o->vfunc_34((u16)(ry + 0x7fff), rx, 0);
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

class Ov010Fx : public VObj {
public:
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

static inline void Ov010_VecScale(VecFx32 *out, const VecFx32 *in, s32 sc) {
    out->x = Ov010_FxMul(in->x, sc);
    out->y = Ov010_FxMul(in->y, sc);
    out->z = Ov010_FxMul(in->z, sc);
}

void func_ov010_02203f08(Ov010Fx *fx) {
    VecFx32 v;
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
    fx->vfunc_20(&v);
    fx->timer++;
}

}
