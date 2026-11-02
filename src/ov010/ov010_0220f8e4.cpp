#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nitro/mi.h"

typedef s32 fx32;

// This TU's .rodata (all of it) and its .data up to the copies the static initialiser makes. The
// copied vectors and their sources are weak: the stub loads each through its own pool word, not
// from the section base. All objects are the TU's size-sorted group (order found with solve2.py).
// Ov010_GrowFxCallback at the end is part of this TU: it scales data_ov010_0220fe38, which it reads
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
namespace m_022020c8 {
struct Ov010Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

static inline void Ov010Glow_Init(Ov010Glow *s, u16 id) {
    s->b0 = 1;
    s->b1 = 0;
    s->b2 = 0;
    s->b3 = 0;
    s->id = id;
    s->cur = 0;
    s->tgt = 0;
    s->scale = 0;
    s->keyA = 0;
    s->keyB = 0;
    s->off.x = 0;
    s->off.y = 0x1be;
    s->off.z = -0x125e;
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
extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void HitSphere_Unlink_0203f364(void *p);
extern int func_ov003_021cf330(void *p, void *d, s32 c);

extern u8 data_ov010_0220fe6c[];

extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);

static inline void Ov010_022020c8_Init(Obj022020c8 *self) {
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_ce_2 = 0;
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
    void *saved;
    *(void **)self = data_ov010_0220fe6c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_d8 != NULL) {
        Ov010Glow *s = self->unk_d8;
        if (s != NULL) {
            if (s->b0) {
                s->b0 = 0;
                EffectMgr_StopLoop(data_0214a420, s->keyA);
                EffectMgr_StopLoop(data_0214a420, s->keyB);
                s->keyA = 0;
                s->keyB = 0;
            }
            Heap_Free(s);
        }
        self->unk_d8 = NULL;
    }
    data_02097dd0->cur = saved;
    self->flagObj.vfunc_08();
    Ov010_022020c8_Init(self);
    Ov003Vt_021f79a8_Dtor(&self->flagObj);
    ActorEx_DtorBase(self);
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
    Actor_Draw(self);
}

void Ov010Obj022020c8_Launch(Obj022020c8 *self, u16 a, const VecFx32 *pos, const VecFx32 *v, const Ov010Rot3 *rot) {
    if (self->unk_ce_0) {
        return;
    }
    self->target = a;
    self->unk_d4 = 0;
    self->unk_ce_0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    *(Ov010Rot3 *)&self->rot_x = *rot; // one 6-byte copy, as the original
    self->unk_d0 = 0;
    self->unk_e0 = data_ov010_0220f000;
}

void Ov010Obj022020c8_Launch2(Obj022020c8 *self, u16 a, const VecFx32 *pos, const VecFx32 *v, const Ov010Rot3 *rot) {
    if (self->unk_ce_0) {
        return;
    }
    self->target = a;
    self->unk_d4 = 1;
    self->unk_ce_0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    *(Ov010Rot3 *)&self->rot_x = *rot; // one 6-byte copy, as the original
    self->unk_d0 = 0;
    self->unk_e0 = data_ov010_0220f000;
}

void Ov010Obj022020c8_SetHitTest(Obj022020c8 *self, BOOL (*fn)(u16 id, const VecFx32 *a, const VecFx32 *b)) {
    self->unk_dc = fn;
}

void Ov010ActVt_0220fe6c_Start(Obj022020c8 *self) {
    ActorSub48 *m;
    Ov010Glow *s;
    u8 c;
    ActorEx_Start(self);
    self->model->visible = 0;
    History_SetState(self->fsm, 0x20, 0);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    self->hit->unk_9a_7 = 1;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    c = data_ov003_021f4340;
    self->hit->unk_9a_6 = 0;
    self->hit->unk_30 = 0;
    self->unk_44->unk_1c = self->radius * 2;
    func_ov003_021cf330(&self->flagObj, data_ov010_0220fe5c, c);
    s = (Ov010Glow *)Heap_Alloc(sizeof(Ov010Glow));
    if (s != NULL) {
        s->b0 = 0;
    }
    self->unk_d8 = s;
    Ov010Glow_Init(s, self->id);
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
extern BOOL History_SetState(void *a, s32 b, s32 c);

void func_ov010_02202838(Obj022020c8 *self) {
    ActorSub40 *m = self->fsm;
    switch (m->current) {
    case 0x20:
        if (self->unk_ce_0) {
            History_SetState(m, 0x21, 1);
        }
        break;
    case 0x21:
        self->unk_d0++;
        if (self->unk_d0 > 0x3c) {
            self->unk_d0 = 0;
            History_SetState(m, 0x22, 1);
        }
        break;
    case 0x22:
        self->unk_d0++;
        if (self->unk_d0 > 0x3c) {
            self->unk_d0 = 0;
            History_SetState(m, 0x23, 1);
        }
        break;
    }
}

void func_ov010_022028ec(Obj022020c8 *self) {
    ActorSub40 *m = self->fsm;
    switch (m->current) {
    case 0x20:
        if (self->unk_ce_0) {
            History_SetState(m, 0x21, 1);
        }
        break;
    case 0x21:
        self->unk_d0++;
        if (self->unk_d0 > 0x28) {
            self->unk_d0 = 0;
            History_SetState(m, 0x22, 1);
        }
        break;
    case 0x22:
        self->unk_d0++;
        if (self->unk_d0 > 0x64) {
            self->unk_d0 = 0;
            History_SetState(m, 0x23, 1);
        }
        break;
    }
}

void Ov010Obj022020c8_State20(Obj022020c8 *self) {
}
}
}  // namespace m_02202838

// ---- merged from ov010_02202c9c.cpp
namespace m_02202c9c {
extern "C" {
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Add(VecFx32 *a, const VecFx32 *b, VecFx32 *c);

extern void *data_02097e4c;
extern void HitSphere_Unlink_0203f364(void *p);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern void Ov010_GrowFxCallback(EffectObj *fx);

static inline EffectObj *Ov010_SpawnRing(s32 a, const VecFx32 *b) {
    EffectObj *fx = Effect_SpawnId(a, b);
    if (fx != NULL) {
        fx->unk_04 = 0;
        fx->unk_08 = 0;
    }
    fx->onUpdate = Ov010_GrowFxCallback;
    return fx;
}

void Ov010Obj022020c8_State21(Obj022020c8 *self) {
    s32 a = 0;
    s32 b = a;
    s32 c = a;
    s32 d = a;
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *h;
        Model0218fe1c *m;
        self->model->visible = 1;
        self->speed = a;
        self->velY = a;
        self->friction = a;
        self->gravity = a;
        Ov010_SpawnRing(0x12c, &self->pos)->SetScaleAll(0x2000);
        self->fsm->st = 1;
        self->unk_44->unk_22_1 = 0;
        h = self->hit;
        h->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(h);
        m = self->model;
        m->color = 0x53ff;
        m->color2 = 0x53ff;
        m->blend = 2;
        m->blendMax = 1;
        self->model->alpha = 0x14;
        SndMgr_PlayAt(data_02097e4c, 0x2b, &self->pos, 0);
        break;
    }
    case 1: {
        ActorSub48 *h;
        Model0218fe1c *m;
        b = 0x10;
        d = 0x400;
        self->fsm->timer++;
        if (self->fsm->timer > 0x41) {
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        self->unk_44->unk_22_1 = 0;
        h = self->hit;
        h->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(h);
        m = self->model;
        m->color = 0x53ff;
        m->color2 = 0x53ff;
        m->blend = 2;
        m->blendMax = 1;
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
            Ov010Glow *s;
            self->model->alpha = 0x1f;
            s = self->unk_d8;
            if (s->b0) {
                s->b1 = 1;
                s->tgt = 0x1000;
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
    Ov003Vec_ClampLen(&self->unk_e0, &self->unk_e0, d);
    VEC_Add(&self->pos, &self->unk_e0, &self->pos);
    if (self->unk_d8 != NULL) {
        Ov010Glow_Update(self->unk_d8);
    }
}

void Ov010Obj022020c8_State22(Obj022020c8 *self) {
    if (self->fsm->st == 0) {
        Ov010Glow *s;
        self->model->alpha = 0x1f;
        s = self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->tgt = 0x1000;
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
    if (self->unk_d8 != NULL) {
        Ov010Glow_Update(self->unk_d8);
    }
}
}
}  // namespace m_02202c9c

// ---- merged from ov010_02202d9c.cpp
namespace m_02202d9c {
typedef BOOL (*Ov010HitFn)(u16 id, const VecFx32 *a, const VecFx32 *b);

extern "C" {
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Add(VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern u16 Ov003Vec_Pitch(VecFx32 *v);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);
extern void Body_Update(void *a, s32 b, s32 c, s32 d);
extern BOOL Hit_DiffInSphere(const VecFx32 *a, const VecFx32 *b, s32 r);

static inline s32 Ov010t_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Ov010Obj022020c8_State23(Obj022020c8 *self) {
    ActorSub40 *p40 = self->fsm;
    BOOL dir;
    BOOL done = FALSE;
    Actor *tgt;
    u8 chk;
    if ((p40->flags & 0x200) != 0) {
        History_SetState(p40, 9, done);
        return;
    }
    dir = done;
    tgt = NULL;
    chk = done;
    switch (p40->st) {
    case 0: {
        Model0218fe1c *m = self->model;
        Ov010Glow *s;
        m->color = 0x7fff;
        m->color2 = 0x7fff;
        m->blend = 0x10;
        m->blendMax = 0xf;
        self->model->alpha = 0x1f;
        s = self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->tgt = 0x3000;
        }
        s = self->unk_d8;
        if (s->b0) {
            if (s->b2) {
                EffectMgr_StopLoop(data_0214a420, s->keyB);
                s->keyB = 0;
            }
            s->b2 = 1;
            s->scale = 0x2000;
            s->b3 = 0;
        }
        self->fsm->st = 1;
        SndMgr_PlayAt(data_02097e4c, 0x50, &self->pos, 0);
        break;
    }
    case 1:
        VEC_MultAdd(6, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
        Ov003Vec_ShrinkLen(&self->unk_e0, &self->unk_e0, 0x180, 0x180);
        self->fsm->timer++;
        if (self->fsm->timer > 0x46) {
            self->fsm->timer = 0;
            self->fsm->st = 10;
            SndMgr_PlayAtPitch(data_02097e4c, 0x32, &self->pos, 8);
        }
        break;
    case 10:
        VEC_MultAdd(0x18, &data_ov010_0220efdc, &self->unk_e0, &self->unk_e0);
        VEC_MultAdd(6, &data_ov010_0220fe44, &self->unk_e0, &self->unk_e0);
        Ov003Vec_ClampLen(&self->unk_e0, &self->unk_e0, 0x700);
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
                self->unk_f8 = tgt->pos;
                self->unk_f8.y += tgt->unk_44->unk_0c.y;
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
        Ov003Vec_ClampLen(&self->unk_e0, &self->unk_e0, 0x700);
        fn = self->unk_dc;
        if (fn != NULL) {
            if (fn(tgt->id, &self->unk_f8, &self->pos)) {
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
        m->color = col;
        m->color2 = col;
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
        self->hit->unk_9a |= 0x10;
        Body_Update(self->hit, 0, 0, 0);
        hit = FALSE;
        if (self->hit->unk_50 & 0x20000000) {
            hit = TRUE;
        }
        r = Hit_DiffInSphere(&tgt->pos, &self->pos, self->radius + tgt->radius);
        if (hit || r) {
            done = TRUE;
        }
    }
    if (done) {
        self->unk_ce_1 = 1;
        History_SetState(self->fsm, 0x15, 1);
    }
    VEC_Add(&self->pos, &self->unk_e0, &self->pos);
    if (self->unk_d8 != NULL) {
        Ov010Glow_Update(self->unk_d8);
    }
}
}
}  // namespace m_02202d9c

// ---- merged from ov010_022033d0.cpp
namespace m_022033d0 {
extern "C" {
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218996c(s32 a, s32 b);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern void Body_SetOwner(void *p, s32 a);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
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

void Ov010Obj022020c8_StateDie(Obj022020c8 *self) {
    ActorSub40 *st = self->fsm;
    if (((const ActorSub40 *)st)->st == 0) {
        EffectObj *e;
        Ov010Glow *s;
        st->st++;
        if (self->unk_ce_1) {
            Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, Ov010_TeamBit(self->target), NULL, NULL, 0x2000, 0, 100, 0x1000);
            func_ov000_0218996c(0xf, 5);
        }
        e = Effect_SpawnId(0x131, &self->pos);
        e->SetRotXYZ(0, Ov003Vec_Yaw(&data_ov010_0220fe38), 0);
        e->SetScaleAll(0x2000);
        SndMgr_PlayAt(data_02097e4c, 0x1a, &self->pos, 0);
        s = self->unk_d8;
        if (s->b0) {
            s->b1 = 0;
            EffectMgr_Kill(data_0214a420, s->keyA);
            s->keyA = 0;
        }
        s = self->unk_d8;
        if (s->b0) {
            s->b2 = 0;
            EffectMgr_Kill(data_0214a420, s->keyB);
            s->keyB = 0;
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *m;
            Body_SetOwner(self->hit, 0xffff);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
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
    Ov010Glow_Update(self->unk_d8);
}
}
}  // namespace m_022033d0

// ---- merged from ov010_0220366c.cpp
namespace m_0220366c {
extern "C" {
extern Actor *Target_Get(ActorSub4c *p);

void Ov010Obj022020c8_StateHeld(Obj022020c8 *self) {
    if (self->fsm->st == 0) {
        Ov010Glow *s = self->unk_d8;
        if (s->b0) {
            s->b1 = 0;
            EffectMgr_Kill(data_0214a420, s->keyA);
            s->keyA = 0;
        }
        s = self->unk_d8;
        if (s->b0) {
            s->b2 = 0;
            EffectMgr_Kill(data_0214a420, s->keyB);
            s->keyB = 0;
        }
    }
    ActorEx_StateHeld(self);
}

void Ov010Obj022020c8_StateThrown(Obj022020c8 *self) {
    BOOL first = FALSE;
    if (self->fsm->st == 0) {
        first = TRUE;
    }
    ActorEx_StateThrown(self);
    if (first) {
        Ov010Glow *s = self->unk_d8;
        if (s->b0) {
            s->b1 = 1;
            s->tgt = 0x3000;
        }
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_ce_2 = 1;
        self->speed = 0x4c0;
        self->target = Target_Get(self->targetObj)->target;
    }
    Ov010Glow_Update(self->unk_d8);
}

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *o);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, const VecFx32 *pos, s32 r, s32 a, void **list);
extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);
extern void HitSphere_Link(ActorSub48 *p);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void Body_Update(void *a, s32 b, s32 c, s32 d);
extern u16 Ov003Vec_Pitch(VecFx32 *v);
extern u16 Ov003Vec_Yaw(const VecFx32 *v);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void Ov010Obj022020c8_StateFly(Obj022020c8 *self) {
    u16 *st;
    Actor *actor;
    if (!self->unk_ce_2) {
        self->targetObj->target = ActorMgr_FindPlayer()->id;
        ActorEx_StateFly(self);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        actor = Ov010_FindActor(self->target);
        if (actor != NULL) {
            VecFx32 c;
            VecFx32 b = Ov003Actor_GetSub44Offset(actor);
            c.x = actor->pos.x;
            c.y = actor->pos.y;
            c.z = actor->pos.z;
            VEC_Add(&c, &b, &c);
            self->unk_ec.x = c.x - self->pos.x;
            self->unk_ec.y = c.y - self->pos.y;
            self->unk_ec.z = c.z - self->pos.z;
            VEC_Normalize(&self->unk_ec, &self->unk_ec);
        } else {
            Ov003Vec_RotateY(&self->unk_ec, self->rot_y, &data_ov010_0220efd0);
        }
        self->fsm->st = 10;
        break;
    case 10: {
        void *list[32];
        actor = Ov010_FindActor(self->target);
        if (actor != NULL) {
            VecFx32 c;
            VecFx32 b = Ov003Actor_GetSub44Offset(actor);
            c.x = actor->pos.x;
            c.y = actor->pos.y;
            c.z = actor->pos.z;
            VEC_Add(&c, &b, &c);
            self->unk_ec.x = c.x - self->pos.x;
            self->unk_ec.y = c.y - self->pos.y;
            self->unk_ec.z = c.z - self->pos.z;
            VEC_Normalize(&self->unk_ec, &self->unk_ec);
        }
        if (Actor_FindInRadius(self, 0x20, &self->pos, self->radius, 0, list) != 0 ||
            (self->hit)->unk_58 != 0) {
            Ov003Pickup_Update(self, 0);
            History_SetState(self->fsm, 0x15, 0);
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
        if (Actor_FindInRadius(self, 0x20, &self->pos, self->radius, 0, list) != 0 ||
            (self->hit)->unk_58 != 0) {
            Ov003Pickup_Update(self, 0);
            History_SetState(self->fsm, 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        self->fsm->timer++;
        if (self->fsm->timer > 0x3c) {
            History_SetState(self->fsm, 0x15, 0);
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
        if (self->param->type == 2) {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
        }
        o = NULL;
        f = FALSE;
        {
            ActorSub4c *ow = self->targetObj;
            if (ow != NULL && ow->target != 0xffff && ow->unk_01 == 1) {
                s32 r = self->radius + 0x4cd;
                Actor *p;
                if (r < 0xccd) {
                    r = 0xccd;
                }
                (self->hit)->unk_44 = r;
                p = Target_Get(self->targetObj);
                if (p != NULL && (o = p->hit) != NULL && o->unk_9a_3) {
                    o->unk_9a_3 = 0;
                    HitSphere_Unlink_0203f364(o);
                    f = TRUE;
                }
            }
        }
        Body_Update(self->hit, 1, 0, 0);
        if (f) {
            o->unk_9a_3 = 1;
            HitSphere_Link(o);
        }
    }
    self->rot_x = Ov003Vec_Pitch(&self->unk_ec);
    self->rot_y = Ov003Vec_Yaw(&self->unk_ec);
    Ov010Glow_Update(self->unk_d8);
}
}
}  // namespace m_0220366c

// ---- merged from ov010_02203ee0.cpp
namespace m_02203ee0 {
extern "C" {

extern s32 func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *p, s32 a);
void Ov010_GrowFxCallback(EffectObj *fx);

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

void Ov010Glow_Update(Ov010Glow *self) {
    Actor *actor;
    EffectObj *o;
    u16 rx;
    u16 ry;
    VecFx32 base;
    if (!self->b0) {
        return;
    }
    {
        u16 id = self->id;
        actor = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
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
        self->keyA = Effect_SpawnId(0x324, &data_ov010_0220fe50)->id;
    }
    if (self->b2 && self->keyB == 0) {
        EffectObj *fx = Effect_SpawnId(self->b3 ? 0x25e : 0x25d, &data_ov010_0220fe50);
        fx->SetScaleXYZ(self->scale, self->scale, self->scale);
        self->keyB = fx->id;
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
    base = actor->pos;
    rx = actor->rot_x;
    ry = actor->rot_y;
    if (self->keyA != 0) {
        o = Effect_Find_020657b0(data_0214a420, self->keyA);
        if (o == NULL) {
            self->keyA = 0;
            self->b1 = 0;
        } else {
            VecFx32 v;
            Ov003Vec_RotateX(&v, rx, &self->off);
            Ov003Vec_RotateY(&v, ry, &v);
            VEC_Add(&v, &base, &v);
            o->SetPos(&v);
            o->SetScaleXYZ(self->cur, self->cur, self->cur);
        }
    }
    if (self->keyB == 0) {
        return;
    }
    o = Effect_Find_020657b0(data_0214a420, self->keyB);
    if (o == NULL) {
        self->keyB = 0;
        self->b2 = 0;
        return;
    }
    {
        VecFx32 v;
        Ov003Vec_RotateX(&v, rx, &self->off);
        Ov003Vec_RotateY(&v, ry, &v);
        VEC_Add(&v, &base, &v);
        o->SetPos(&v);
        o->SetRotXYZ((u16)(rx + 0x7fff), ry, 0);
    }
}

EffectObj *Ov010_SpawnGrowFx(s32 a, const VecFx32 *b) {
    EffectObj *fx = Effect_SpawnId(a, b);
    if (fx != NULL) {
        fx->unk_04 = 0;
        fx->unk_08 = 0;
    }
    fx->onUpdate = Ov010_GrowFxCallback;
    return fx;
}

}
}  // namespace m_02203ee0

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

void Ov010_GrowFxCallback(EffectObj *fx) {
    VecFx32 v;
    if (fx == NULL) {
        return;
    }
    if (fx->unk_04 < 0x14) {
        fx->unk_08 += 0x20;
        fx->unk_08 = Ov010_Clamp(fx->unk_08, 0, 0x600);
    } else {
        fx->unk_08 += 0x100;
        fx->unk_08 = Ov010_Clamp(fx->unk_08, 0, 0x2000);
    }
    Ov010_VecScale(&v, &data_ov010_0220fe38, fx->unk_08);
    fx->AddPos(&v);
    fx->unk_04++;
}

}
