#include "ov010/ov010.h"
#include "Main/Lang/TblRes.h"
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
char data_ov010_0220ff24[] =
#include "romdata/ov010/0220ff24.inc"
;
const u16 data_ov010_0220f0a0[4] = {0x1800, 0x1800, 0x1800, 0x1733};
char data_ov010_0220ff60[] =
#include "romdata/ov010/0220ff60.inc"
;
const char *const data_ov010_0220f058 = data_ov010_0220ff00;
const Ov010Rot data_ov010_0220f05c = {0, 0, 0};
const Ov010Rot data_ov010_0220f07a = {0x0, 0x7fff, 0x0};
const Ov010Rot data_ov010_0220ff3c = data_ov010_0220f05c;
const Ov010Rot data_ov010_0220f092 = {0x0, 0xff, 0x0};
char data_ov010_0220ff54[] =
#include "romdata/ov010/0220ff54.inc"
;
const Ov010Rot data_ov010_0220f086 = {0x10ce, 0x6c1c, 0x0};
char data_ov010_0220ff36[] =
#include "romdata/ov010/0220ff36.inc"
;
const Ov010Rot data_ov010_0220f08c = {0xd73, 0x801c, 0x0};
__declspec(weak) const VecFx32 data_ov010_0220f0a8 = {0, 0, 0};
const u8 data_ov010_0220f098[8] = {0, 1, 2, 2, 2, 2, 2, 0};
char data_ov010_0220ff06[] =
#include "romdata/ov010/0220ff06.inc"
;
const char *const data_ov010_0220f040 = data_ov010_0220ff12;
char data_ov010_0220ff1e[] =
#include "romdata/ov010/0220ff1e.inc"
;
const Ov010Rot data_ov010_0220f074 = {0x0, 0x0, 0x0};
__declspec(weak) const VecFx32 data_ov010_0220ff48 = data_ov010_0220f0a8;
char data_ov010_0220ff12[] =
#include "romdata/ov010/0220ff12.inc"
;
const char *const data_ov010_0220f02c = data_ov010_0220ff06;
const char *const data_ov010_0220f034 = data_ov010_0220ff42;
const char *const data_ov010_0220fefc = data_ov010_0220f058;
const char *const data_ov010_0220f050 = data_ov010_0220ff1e;
const char *const data_ov010_0220f038 = data_ov010_0220ff36;
const fx32 data_ov010_0220ff70[5] = {-0x3302, -0x82b0, 0x33d7, -0x1d37, K(-0xdb33)};
const char *const data_ov010_0220f028 = data_ov010_0220ff30;
char data_ov010_0220ff42[] =
#include "romdata/ov010/0220ff42.inc"
;
const char *const data_ov010_0220f03c = data_ov010_0220ff18;
const char *const data_ov010_0220f04c = data_ov010_0220ff54;
char data_ov010_0220ff0c[] =
#include "romdata/ov010/0220ff0c.inc"
;
const s32 data_ov010_0220f024 = 0xff00;
char data_ov010_0220ff18[] =
#include "romdata/ov010/0220ff18.inc"
;
const char *const data_ov010_0220f030 = data_ov010_0220ff0c;
char data_ov010_0220ff2a[] =
#include "romdata/ov010/0220ff2a.inc"
;
char data_ov010_0220ff30[] =
#include "romdata/ov010/0220ff30.inc"
;
char data_ov010_0220ff00[] =
#include "romdata/ov010/0220ff00.inc"
;
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

extern void *gActorMgr;
extern void *gSndMgr;
extern void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);

static inline u8 Ov010_HitKind(s32 i) {
    if (i >= 0 && (u32)i < 7) {
        return data_ov010_0220f098[i];
    }
    return 2;
}

static inline BOOL Ov010_IsInvul(ActorHp *hp) {
    return hp->unk_0a != 0;
}

static inline BOOL Ov010_HasFlag(ActorSub40 *s, u64 m) {
    BOOL r = FALSE;
    if (s->flags & m) {
        r = TRUE;
    }
    return r;
}

BOOL Ov010Obj02210154_HandleMsg(Ov010Obj02210154 *self, ActorMsg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        switch (msg->unk_08) {
        case 1:
            Ov003TickerSet_Start(&self->ticker, 3, 0, 0, 0);
            break;
        case 0: {
            ActorHp *hp = self->hpObj;
            if (!Ov010_IsInvul(hp)) {
                s32 n;
                u8 st;
                FieldState *g;
                hp->unk_04 = msg->id;
                n = Ov003Actor_ApplyHit(self, (ActorMsgHit *)&msg->unk_0a);
                hp = self->hpObj;
                st = hp->kind2;
                if (hp->cur <= self->unk_f4) {
                    n = 0x15;
                    hp->cur = self->unk_f4;
                }
                if (n != 0) {
                    self->step.a = n;
                    self->step.b = Ov010_HitKind(msg->unk_09);
                    self->fsm->flags |= 1ull << n;
                    Ov003Sequence_SetHold(&self->seq, 1);
                }
                if (st != 1) {
                    Model0218fe1c_SetAnimDelay(self->model, 5, 0);
                }
                g = gSceneCmd;
                g->cam.base.shakeX = 1;
                g->cam.base.shakeY = 1;
                g->cam.base.shakeZ = 1;
                g->cam.base.shakeTime = 0x14;
                g->cam.base.shakeLen = 0x1e;
                g->cam.base.shakeCur = 0x1e;
                Ov003Actor_FadeColor(self, 0x14bf, 0x739f, 10);
                SndMgr_PlayAt(gSndMgr, 0x1b, &self->pos, 0);
            }
            break;
        }
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        r = TRUE;
    } else if (msg->type == 9) {
        Actor *o;
        r = Ov003Actor_HandleMsg(self, msg);
        {
            u16 id = msg->unk_0c;
            o = gActorMgr == NULL ? NULL : ActorMgr_GetActor(gActorMgr, id);
        }
        if (o != NULL && o->kind == 0x4817) {
            ActorHp *hp = self->hpObj;
            if (hp->cur <= self->unk_f4) {
                hp->cur = self->unk_f4 + 1;
                self->fsm->flags = 0;
            }
        }
        self->unk_124[0] = o->rot_y;
        self->unk_124[1] = 0xa00;
        self->unk_124[2] = 0x600;
        SndMgr_PlayAt(gSndMgr, self->sfx[0], &self->pos, 0);
        if (!Ov010_HasFlag(self->fsm, 0x200000)) {
            self->fsm->flags = 0;
        }
    } else {
        r = Ov003Actor_HandleMsg(self, msg);
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

extern u8 Ov010Vt_0220ffc4_vtbl[];
extern Ov010Arena data_ov010_0220f160;
extern Ov010Arena data_ov010_0220f174;
extern const Ov010Circle data_ov010_0220f150;
extern void *Heap_Alloc(u32 size);
extern void *Ov010Vt_02210280_Ctor(void *p);
extern void *Ov010Vt_022102c0_Ctor(void *p);
extern void *Ov010Vt_022102a0_Ctor(void *p);
extern void *Ov010Vt_02210260_Ctor(void *p);
extern void *Ov010Vt_02210240_Ctor(void *p);
extern void *Ov003Vt_021f7cf4_Ctor(void *p);
extern BOOL Ov003TickerSet_Init(void *p);
extern BOOL Ov003StateMachine_Init(void *p);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern BOOL Stage_UseScaledStats(void);

static inline Ov010CamPreset *Ov010Cam_New(void) {
    Ov010CamPreset *o = (Ov010CamPreset *)Heap_Alloc(0x20);
    if (o != NULL) {
        *(void **)o = Ov010Vt_0220ffc4_vtbl;
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
    Ov003Actor_Start(self);
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
    Ov003Flag_Init(&self->seq);
    Ov010Coll_Init(&self->coll);
    Ov003TickerSet_Init(&self->ticker);
    Ov003Timer_Init(&self->timer);
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
    Ov003StateMachine_AddState(self->unk_118, 0, self->unk_120);
    Ov003StateMachine_AddState(self->unk_118, 1, self->unk_11c);
    self->model->visible = 0;
    self->target = ActorMgr_FindPlayer()->id;
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov010_0220f0a0);
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

extern BOOL History_SetState(void *a, s32 b, s32 c);

void Ov010Obj02210154_SelectState(Ov010Obj02210154 *self) {
    Ov003ActorSub40_ApplyFlags(self->fsm);
    Actor_DropStateMsgs(self, self->fsm->current);
}

void Ov010Actor_UpdateMode1(void) {
}

void Ov010Obj02210154_Update(Ov010Obj02210154 *self) {
    BOOL go = FALSE;
    self->unk_93_4 = 0;
    if (Ov003Actor_CanAct(self) || self->unk_f2 != 0) {
        go = TRUE;
    }
    self->unk_f2 = 0;
    if (!go) {
        return;
    }
    self->unk_c4 = 0;
    self->unk_93_4 = 1;
    Ov003Seq_Update(&self->seq);
    if (Ov003Sequence_IsReady(&self->seq)) {
        Ov010B2 r = Ov003Sequence_GetPair(&self->seq);
        self->step = r;
        History_SetState(self->fsm, r.a, 1);
    }
}

extern const Ov010StEnt Ov010Obj02210154_StateTable[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void VEC_MultAdd(s32 a, const VecFx32 *b, const VecFx32 *c, VecFx32 *out);


void Ov010Obj02210154_RunState(Ov010Cls *self) {
    u32 i;
    Robo021ca458 *pl;
    s16 *p;
    u8 key;
    key = self->fsm->current;
    for (i = 0; i < 6; i++) {
        if (key == Ov010Obj02210154_StateTable[i].key && *(s32 *)&Ov010Obj02210154_StateTable[i].fn != 0) {
            (self->*Ov010Obj02210154_StateTable[i].fn)();
            break;
        }
    }
    Ov003Actor_RunState(self);
    if (func_ov003_021cf408()) {
        self->mode = func_ov003_021cf408();
    }
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        Ov010_VecCopy(&pl->unk_b90, &self->pos);
        pl->unk_b9c = 0x800;
    }
    p = self->unk_124;
    if (p != NULL) {
        VecFx32 v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        Ov003Vec_RotateY(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &self->pos, &self->pos);
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    Ov010Coll_Prune(&self->coll);
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

extern BOOL Model0218fe1c_SetAnim(void *p, const void *a, s32 b, s32 c);
extern void Model0218fe1c_SetLoop(void *p);

void Ov010Obj02210154_StateIdle(Ov010Obj02210154 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0x266, 0);
    Model0218fe1c_SetLoop(self->model);
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    self->fsm->st++;
}

struct Ov010Mtx33 {
    s32 m[3][3];
};

extern void *gSndMgr;
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void Ov010Trig_Setup(VObj *t, s32 a, const s32 *rect, const Ov010Circle *circ, u16 d, u16 e);
extern void Ov010_PickRingPoint(VecFx32 *out, void *c, const VecFx32 *target, s32 n, u16 ang);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern u32 Rand_Get(void);
extern s32 Rand_PlusMinus(s32 n);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33 *m, VecFx32 *o);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void VEC_Normalize(VecFx32 *a, VecFx32 *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern void Model0218fe1c_SetAnimSpeed(void *p, s32 a);
extern BOOL Model0218fe1c_IsAnimDone(void *p);
extern void func_ov010_0220984c(void *t, u16 a);

static inline VecFx32 Ov010d_Pt(Ov010Obj02210154 *self) {
    VecFx32 p;
    Ov010_PickRingPoint(&p, self->arena, &self->pos, 4, 0);
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

void Ov010Obj02210154_StateAttack(Ov010Obj02210154 *self) {
    BOOL flag = FALSE;
    switch (self->fsm->st) {
    case 0:
        Ov010Coll_Filter(&self->coll, Ov010Obj0220a6b0_IsFinished);
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
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f040, 0x800, 1);
        pl = ActorMgr_FindPlayer();
        Ov010Trig_Setup(self->unk_104, self->unk_15c, self->unk_fc, self->unk_100, self->id, pl->id);
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
        EffectObj *e;
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
        e = Ov010_SpawnAimFxAt(self, &self->pos, &v);
        e->SetScaleAll(0x2000);
        self->fsm->st = 0x15;
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            SndMgr_PlayAt(gSndMgr, self->sfx[3], &self->pos, 0);
        }
        SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
        }
        break;
    }
    case 0x15:
        flag = TRUE;
        if (Ov010Coll_IsFree(&self->coll)) {
            self->fsm->st = 0x1e;
        }
        Ov010Obj02210154_MoveToDest(self);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        break;
    case 0x1e:
        Ov010Obj02210154_MoveToDest(self);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        Model0218fe1c_GetAnimCtrl(self->model, 0)->paused = 0;
        Model0218fe1c_SetAnimSpeed(self->model, 0x2000);
        self->fsm->st = 0x1f;
        break;
    case 0x1f:
        if (self->model->anim_state == 1) {
            func_ov010_0220984c(self->unk_108, self->id);
            Ov010Coll_SetHandler(&self->coll, self->unk_108);
            self->fsm->st = 0x28;
            SndMgr_PlayAt(gSndMgr, self->sfx[4], &self->pos, 0);
        }
        Ov010Obj02210154_MoveToDest(self);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        break;
    case 0x28:
        if (Ov010Coll_IsFree(&self->coll) && Model0218fe1c_IsAnimDone(self->model)) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0x266, 1);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st = 0x32;
        }
        Ov010Obj02210154_MoveToDest(self);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        break;
    case 0x32:
        Ov003Sequence_Signal(&self->seq, 1);
        break;
    }
    if (flag && self->model->anim_state == 2) {
        Model0218fe1c_GetAnimCtrl(self->model, 0)->paused = 1;
    }
}

}
}  // namespace m_02204cdc

// ---- merged from ov010_0220522c.cpp
namespace m_0220522c {
extern "C" {

extern void *gSndMgr;
extern BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
extern void Model0218fe1c_SetLoop(void *a);
extern BOOL Model0218fe1c_IsAnimDone(void *p);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
extern void Ov010Wave_Setup(VObj *self, u16 a, s32 b, const s32 *rect, const Ov010Circle *circ, u16 e, u16 f);
extern void Ov003StateMachine_Leave(void *p);

void Ov010Obj02210154_StateAttack2(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->st = 0x10;
        break;
    case 0x10:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f040, 0x266, 0);
        self->fsm->st = 0x11;
        SndMgr_PlayAt(gSndMgr, self->sfx[2], &self->pos, 0);
    case 0x11:
        self->fsm->timer++;
        if (self->fsm->timer > 0x32) {
            self->fsm->timer = 0;
            self->fsm->st = 0x20;
        }
        break;
    case 0x20: {
        Robo021ca458 *pl = ActorMgr_FindPlayer();
        Ov010Wave_Setup(self->unk_10c, self->step.b, self->unk_15c, self->unk_fc,
                            self->unk_100, self->id, pl->id);
        Ov010Coll_SetHandler(&self->coll, self->unk_10c);
        self->fsm->st = 0x21;
        break;
    }
    case 0x21:
        if (Ov010Coll_IsFree(&self->coll) && Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->st = 0x30;
        }
        if (Model0218fe1c_IsAnimDone(self->model)) {
            Ov003StateMachine_ChangeState(self->unk_118, 1);
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
        Ov003Sequence_Signal(&self->seq, 1);
        break;
    }
    if (Model0218fe1c_IsAnimDone(self->model)) {
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0x800, 0);
        Model0218fe1c_SetLoop(self->model);
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

extern void *gSndMgr;
extern const Ov010Blk12 data_ov010_0220f0b4;
extern const Ov010Blk12 data_ov010_0220f0c0;
extern const Ov010Blk12 data_ov010_0220f0cc;
extern BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
extern void Model0218fe1c_SetLoop(void *a);
extern void Model0218fe1c_ClearLoop(void *a);
extern BOOL Model0218fe1c_IsAnimDone(void *p);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(VecFx32 *v, Ov010Mtx33 *m, VecFx32 *out);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Normalize(const VecFx32 *in, VecFx32 *out);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);

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

void Ov010Obj02210154_StateAttack3(Ov010Obj02210154 *self) {
    ActorSub40 *st = self->fsm;
    self->unk_f2 = 1;
    switch (st->st) {
    case 0: {
        u8 k;
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f02c, 0x266, 0);
        Model0218fe1c_SetLoop(self->model);
        Ov003StateMachine_ChangeState(self->unk_118, 0);
        k = self->step.b;
        switch (k) {
        case 1:
            self->fsm->st = 10;
            break;
        case 2:
            self->fsm->st = 0x14;
            break;
        }
        SndMgr_PlayAt(gSndMgr, 0x36, &self->pos, 0);
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
            Effect_SpawnId(0x5e2, &c)->SetScaleAll(0x3000);
        }
        self->fsm->st = 0xb;
        break;
    }
    case 0xb:
        Ov010Obj02210154_MoveToDest(self);
        if (self->fsm->timer % 30 == 0) {
            Effect_SpawnId(0x66, &self->pos)->SetScaleAll(0x2800);
        }
        self->fsm->timer++;
        st = self->fsm;
        if (st->timer > 0x3c) {
            st->timer = 0;
            self->fsm->st = 0x1e;
        }
        Actor_TurnToActor(self, ActorMgr_FindPlayer(), 0x800);
        break;
    case 0x14:
        st->timer++;
        st = self->fsm;
        if (st->timer > 0xf) {
            st->timer = 0;
            self->fsm->st = 0x1e;
        }
        Actor_TurnToActor(self, ActorMgr_FindPlayer(), 0x800);
        break;
    case 0x1e: {
        VecFx32 a;
        VecFx32 b;
        VecFx32 c2;
        EffectObj *o2;
        *(Ov010Blk12 *)&a = data_ov010_0220f0c0;
        *(Ov010Blk12 *)&b = data_ov010_0220f0cc;
        Ov003Vec_RotateY(&c2, self->rot_y, &b);
        self->moveYaw = self->rot_y;
        o2 = Effect3D_Create(data_ov010_0220f054, data_ov010_0220f04c, 0, &self->pos);
        o2->unk_28 = 0;
        o2->SetRotXYZ(0, self->moveYaw, 0);
        o2->SetScale(&a);
        o2->AddPos(&c2);
        self->fsm->st = 0x1f;
        SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
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
        EffectObj *e;
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f030, 0x266, 0);
        Model0218fe1c_SetLoop(self->model);
        Ov010_ClearSpeed(self);
        g = gSceneCmd;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0xf;
        g->cam.base.shakeLen = 0x28;
        g->cam.base.shakeCur = 0x28;
        self->fsm->st = 0x29;
        VecFx32 o = {0, 0, 0};
        o.y = self->height / 2;
        e = Ov003_SpawnFollowFx(0x4b0, self, &o);
        e->SetRotXYZ(0, self->rot_y, 0);
        e->SetScaleAll(0x1800);
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            SndMgr_PlayAt(gSndMgr, self->sfx[7], &self->pos, 0);
        }
        SndMgr_PlayAt(gSndMgr, 0x32, &self->pos, 0);
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
        Ov003Vec_RotateY(&f, self->moveYaw, (VecFx32 *)&data_ov010_0220f0b4);
        if ((s32)(((s64)f.x * dx + (s64)f.y * dy + (s64)f.z * dz + 0x800) >> 12) < 0) {
            if (VEC_Distance(&self->arena->center, &self->pos) >=
                self->arena->radius + 0x3000) {
                self->fsm->timer = 0;
                self->fsm->st = 0x32;
            }
        }
        Hit_ApplyInArea(self, self, 0x8c, 0x30, 2, 0, 0, 0x800, 0x3000, 0x64, 0x1000);
        self->speed += 0x266;
        sv = self->speed;
        self->speed = sv > 0x1000 ? 0x1000 : (sv < 0 ? 0 : sv);
        Actor_Move(self, 0x1000);
        self->hp[5] = 1;
        break;
    }
    case 0x32:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f034, 0x266, 0);
        Model0218fe1c_ClearLoop(self->model);
        self->friction = 0x400;
        self->fsm->st = 0x33;
        break;
    case 0x33:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            Ov010_ClearSpeed(self);
            self->fsm->st = 0x3c;
        }
        Actor_Move(self, 0x1000);
        break;
    case 0x3c:
        self->rot_y += 0x7fff;
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st = 0x46;
        break;
    case 0x46:
        Ov003Sequence_Signal(&self->seq, 1);
        break;
    }
}

}
}  // namespace m_02205444

// ---- merged from ov010_02205c30.cpp
namespace m_02205c30 {

extern "C" {

extern void *gSndMgr;
extern void *gActorMgr;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
extern void Model0218fe1c_SetLoop(void *a);
extern BOOL Model0218fe1c_IsAnimDone(void *p);
extern void Actor_SendMsgU8(void *a, u16 b, s32 c);
extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void Vec_RotateY(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern void func_ov010_0220de4c(void *p, u8 a);
extern void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);

void Ov010Obj02210154_StateShoot(Ov010Obj02210154 *self) {
    Actor *tgt;
    s32 r = self->unk_b0->unk_02 * 2;
    {
        u16 id = self->target;
        tgt = gActorMgr == NULL ? NULL : ActorMgr_GetActor(gActorMgr, id);
    }
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f03c, 0x800, 0);
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
        TblActorParam *res;
        TblActorSpawn *ent;
        if (self->model->anim_state != 3) {
            return;
        }
        res = Tbl_GetActorParam(self->kind);
        ent = res != NULL ? &res->spawn : NULL;
        if (ent == NULL || ent->id == 0xffff) {
            self->fsm->st = 4;
        } else {
            VecFx32 v;
            Model0218fe1c *m = self->model;
            Actor *o;
            v.x = ((s16)m->unk_c6) << 4;
            v.y = ((s16)m->unk_c8) << 4;
            v.z = ((s16)m->unk_ca) << 4;
            Vec_RotateY(&v, &v, self->rot_y);
            VEC_Add(&v, &self->pos, &v);
            o = Ov003Actor_SpawnChild(self, 0x4818, &v, &self->rot_x, tgt);
            if (o != NULL) {
                o->unk_18 = ent->arg;
                func_ov010_0220de4c(o, self->step.b);
            }
            self->fsm->st = 3;
            Effect_SpawnId(0x12c, &v)->SetScaleAll(0x2000);
            SndMgr_PlayAt(gSndMgr, 0x65, &self->pos, 0);
            SndMgr_PlayAt(gSndMgr, 0x82, &self->pos, 0);
        }
        if (self->unk_f1 != 0) {
            self->unk_f1 = 0;
            SndMgr_PlayAt(gSndMgr, self->sfx[5], &self->pos, 0);
        }
    }
    case 3: {
        u8 *a;
        u16 id = self->target_id;
        a = gActorMgr == NULL ? NULL : (u8 *)ActorMgr_GetActor(gActorMgr, id);
        if (a == NULL) {
            self->fsm->st = 4;
            return;
        }
        Actor_SendMsgU8(a, self->id, 0xb);
        self->target_id = 0xffff;
        self->fsm->st = 4;
        return;
    }
    case 4:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0xcd, 0);
        Model0218fe1c_SetLoop(self->model);
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_ec_0 = 1;
        History_SetState(self->fsm, 1, 0);
        Ov003Sequence_Signal(&self->seq, 1);
        break;
    }
}


extern void *gSndMgr;
extern VecFx32 data_ov010_0220f0b4;
extern BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
extern BOOL Model0218fe1c_IsAnimDone(void *p);
extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
extern void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
extern void Model0218fe1c_ClearLoop(void *a);
extern Actor *Target_GetActor(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 Rand_PlusMinus(s32 max);
extern void Ov003StateMachine_Leave(void *p);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);
extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);

static inline BOOL Ov010f_Arrived(const VecFx32 *a, const VecFx32 *b) {
    return Ov003Vec_DistSq(a, b) == 0 ? TRUE : FALSE;
}

void Ov010Obj02210154_StateKnockBack(Ov010Obj02210154 *self) {
    Ov003Sequence_SetHold(&self->seq, 1);
    self->unk_f1 = 0;
    switch (self->fsm->st) {
    case 0: {
        u16 ang;
        Actor *t;
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f038, 0x1000, 1);
        Model0218fe1c_SetAnimDelay(self->model, 5, 1);
        Model0218fe1c_ClearLoop(self->model);
        self->unk_92 = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->targetObj->target = 0xffff;
        if (self->hp != NULL) {
            t = Target_GetActor(self->hp);
            if (t == NULL || t == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
            }
        } else {
            ang = self->rot_y;
        }
        self->unk_96 = ang;
        self->moveYaw = self->unk_96 + 0x8000 + Rand_PlusMinus(0x2000);
        Ov003StateMachine_Leave(self->unk_118);
        Ov010Coll_ClearHandler(&self->coll);
        Ov003Sequence_Signal(&self->seq, 0);
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
        SndMgr_PlayAt(gSndMgr, self->sfx[1], &self->pos, 0);
    case 0x11: {
        VecFx32 v = data_ov010_0220f0b4;
        Ov003Vec_RotateY(&v, self->moveYaw, &v);
        Ov003Vec_MultAdd(&self->pos, &v, &self->pos, self->speed, self->velY);
        Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
        if (self->speed < 0x40) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
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
        SndMgr_PlayAt(gSndMgr, self->sfx[1], &self->pos, 0);
    case 0x21:
        self->fsm->timer++;
        if (self->fsm->timer >= 0x14) {
            self->fsm->timer = 0;
            self->fsm->st = 0x30;
        }
        Actor_Move(self, 0);
        break;
    case 0x30:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220fefc, 0x266, 1);
        Model0218fe1c_SetAnimDelay(self->model, 5, 1);
        Model0218fe1c_ClearLoop(self->model);
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
        Ov003Vec_ApproachWithin(&self->pos, &t, &self->pos, self->speed, self->velY);
        Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
        self->moveYaw = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        if (Ov010f_Arrived(&t, &self->pos)) {
            self->fsm->st = 0x50;
        }
        break;
    }
    case 0x50:
        ((VObj *)self)->vfunc_a4();
        History_SetState(self->fsm, 1, 0);
        break;
    }
}


struct Ov010G54b {
    u8 unk_000[0x1cc];
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov010G54b *gSceneCmd;
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern BOOL Ov003Timer_IsStopped(void *a);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);

static inline s32 Ov010g_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

// The screen argument of GfxSys_StartFadeIn (its callers pass 0, 1 or -1).
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

void Ov010Obj02210154_StateDie(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m48;
        ActorSub44 *n;
        EffectObj *o;
        Ov010FadeScreen scr;
        Ov003Sequence_SetPaused(&self->seq, 1);
        m48 = self->hit;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        Ov003StateMachine_Leave(self->unk_118);
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f038, 0x800, 1);
        Model0218fe1c_SetAnimDelay(self->model, 5, 1);
        scr = OV010_FADE_SCREEN_MAIN;
        Ov010_Jump640c(self);
        GfxSys_StartFadeIn(0x1e000, 1, scr);
        ActorMgr_BroadcastKind(gActorMgr, 0x4817, 0x15);
        o = Effect_SpawnId(0x69, &self->pos);
        if (o != NULL) {
            o->SetScaleAll(0x5000);
        }
        SndMgr_PlayAt(gSndMgr, self->sfx[1], &self->pos, 0);
        self->fsm->st = 1;
        return;
    }
    case 1:
        self->fsm->timer++;
        if (self->fsm->timer == 0x1e) {
            Ov003Timer_Start(&self->timer, self, 0x1000, 0);
            self->gravity >>= 1;
            self->velY -= self->velY >> 2;
        }
        if (self->fsm->timer >= 0x5a) {
            self->gravity = 0;
            self->velY = Ov010g_Mul(self->velY, 0xf80);
        }
        if (self->fsm->timer >= 0x5a && Ov003Timer_IsStopped(&self->timer)) {
            EffectObj *o = Effect_SpawnId(0x69, &self->pos);
            if (o != NULL) {
                o->SetScaleAll(0x5000);
            }
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        Actor_Move(self, 0);
        return;
    case 2:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f028, 0x266, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_GetAnimCtrl(self->model, 0)->speed = 0x800;
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
        gSceneCmd->b0 = 1;
        Ov003Actor_Defeat(self, self->unk_f3, 1, 1);
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

void Ov010Obj02210154_StateMove(Ov010Obj02210154 *self) {
    switch (self->step.b) {
    case 1:
        func_ov010_02206784(self);
        break;
    case 2:
        func_ov010_02206974(self);
        break;
    }
}

extern void *gSndMgr;
extern void Ov010_PickRingPoint(VecFx32 *out, void *c, const VecFx32 *target, s32 n, u16 ang);
extern void VEC_Normalize(VecFx32 *a, VecFx32 *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);

void func_ov010_02206784(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0: {
        VecFx32 p;
        EffectObj *e;
        u16 d;
        Ov010_PickRingPoint(&p, self->arena, &self->pos, 4, 0);
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
        e = Ov010_SpawnAimFxAt(self, &self->pos, &p);
        e->SetScaleAll(0x2000);
        SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
        self->fsm->st = 1;
        d = e->rot.y - self->rot_y;
        if (d >= 0x1400 && d <= 0x6c00) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f048, 0x800, 0);
            return;
        }
        if (d >= 0x9400 && d <= 0xec00) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f044, 0x800, 0);
        }
        break;
    }
    case 1:
        Ov010Obj02210154_MoveToDest(self);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        if (self->speed == 0) {
            self->fsm->st = 0x100;
        }
        break;
    case 0x100:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0xcd, 0);
        Ov003Sequence_Signal(&self->seq, 1);
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
extern u16 Ov010_PhaseAngle(s32 a, s32 b);
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
    if (&gSceneCmd->cam == NULL) {
        self->fsm->st = 0x100;
    } else {
        Ov010Arena *t = self->arena;
        s32 cross;
        u16 ang;
        a.x = self->pos.x - t->center.x;
        a.y = self->pos.y - t->center.y;
        a.z = self->pos.z - t->center.z;
        VEC_Normalize(&a, &a);
        b = gSceneCmd->cam.base.eye;
        t = self->arena;
        b.x = t->center.x - b.x;
        b.y = t->center.y - b.y;
        b.z = t->center.z - b.z;
        VEC_Normalize(&b, &b);
        cross = (s32)(((s64)b.z * a.x - (s64)b.x * a.z + 0x800) >> 12);
        {
            s32 dist = VEC_Distance(&self->pos, &self->arena->center);
            if (cross > 0) {
                ang = 0xffff - Ov010_PhaseAngle(dist, self->unk_b0->unk_00);
            } else {
                ang = Ov010_PhaseAngle(dist, self->unk_b0->unk_00);
            }
        }
        Ov003Vec_RotateYAround(&c, &self->pos, ang, self->arena);
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
        Ov010Obj02210154_MoveToDest(self);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        if (self->speed == 0) {
            self->fsm->st = 0x30;
        }
        break;
    case 0x30: {
        EffectObj *e;
        u16 d;
        Ov010f_ClearVel(self);
        self->speed = Ov010f_FxMul(self->unk_b0->unk_00, 0x1800);
        e = Ov010_SpawnAimFxAt(self, &self->pos, &c);
        e->SetScaleAll(0x2000);
        d = e->rot.y - self->rot_y;
        if (d >= 0x1400 && d <= 0x6c00) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f048, 0x800, 0);
        } else if (d >= 0x9400 && d <= 0xec00) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f044, 0x800, 0);
        }
        SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
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
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0xcd, 0);
            self->fsm->st = 0x40;
        } else {
            self->pos = c;
            Actor_TurnToPos(self, &self->arena->center, 0x400);
            Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
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
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
        break;
    case 0x100:
        Ov003Sequence_Signal(&self->seq, 1);
        break;
    }
}

}
}  // namespace m_02206758

// ---- merged from ov010_02206f54.cpp
namespace m_02206f54 {
extern "C" {

extern void *gSndMgr;
extern void Ov003StateMachine_Leave(void *p);
extern void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);

static inline VecFx32 Ov010_Center(Actor *self) {
    VecFx32 p;
    p.x = self->pos.x;
    p.y = self->pos.y + self->height / 2;
    p.z = self->pos.z;
    return p;
}

void Ov010Obj02210154_SetFlagsF1F2(Ov010Obj02210154 *self) {
    self->unk_f2 = 1;
    self->unk_f1 = 1;
}

void Ov010Obj02210154_State28(Ov010Obj02210154 *self) {
    self->unk_f2 = 1;
    if (self->fsm->st != 0) {
        return;
    }
    Ov003StateMachine_ChangeState(self->unk_118, 0);
    Ov003Sequence_Signal(&self->seq, 1);
    self->fsm->st++;
    SndMgr_PlayAt(gSndMgr, self->sfx[6], &self->pos, 0);
}

// Reads the state word through a const view (a const getter is not merged with the later
// plain read of the same field, so the increment reloads it as in the target).
static inline u16 Ov010_GetState(const ActorSub40 *state) {
    return state->st;
}

void Ov010Obj02210154_State29(Ov010Obj02210154 *self) {
    ActorSub40 *m = self->fsm;
    self->unk_f2 = 1;
    if (Ov010_GetState(m) != 0) {
        return;
    }
    m->st++;
    Ov003StateMachine_Leave(self->unk_118);
}

void Ov010Obj02210154_State2a(Ov010Obj02210154 *self) {
    self->unk_f2 = 1;
    if (self->fsm->st == 0) {
        Ov010Coll_SetHandler(&self->coll, self->unk_114);
        self->fsm->st++;
        return;
    }
    if (Ov010Coll_IsFree(&self->coll)) {
        Ov003Sequence_Signal(&self->seq, 1);
    }
}

void Ov010Obj02210154_State2b(Ov010Obj02210154 *self) {
    ActorSub40 *m = self->fsm;
    switch (m->st) {
    case 0: {
        s32 sc = Ov010_FxMul(self->radius, 0x1800);
        VecFx32 q = Ov010_Center(self);
        EffectObj *fx = Effect_SpawnId(0x196, &q);
        fx->SetScaleAll(sc);
        fx->speed = 0x1000;
        SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
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
        Ov003Sequence_Signal(&self->seq, 1);
        break;
    }
}


struct Ov010Mtx33e {
    s32 m[9];
};

extern BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
extern void Model0218fe1c_SetLoop(void *a);
extern u16 FX_Atan2(s32 y, s32 x);
extern u16 Ov010_PhaseAngle(s32 a, s32 b);
extern s32 Rand_GetGlobal(void);
extern void MTX_RotY33_(Ov010Mtx33e *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33e *m, VecFx32 *o);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *o);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);

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

void Ov010Obj02210154_State2c(Ov010Obj02210154 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->st = 0x10;
        break;
    case 0x30:
        break;
    case 0x10:
        Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0x266, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x11;
        break;
    case 0x11:
        if (!Ov010_FindActorInCone(self)) {
            break;
        }
        self->fsm->st = 0x20;
    case 0x20: {
        VecFx32 v;
        Ov010Arena *c = self->arena;
        u16 ang = FX_Atan2(c->center.x - self->pos.x, c->center.z - self->pos.z) + 0x7fff;
        u16 d = Ov010_PhaseAngle(self->arena->radius, 0x3000);
        s32 y;
        EffectObj *e;
        u16 diff;
        if (Rand_GetGlobal() % 2 == 0) {
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
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        Actor_Move(self, 0);
        self->speed = 0x400;
        e = Ov010_SpawnAimFxAt(self, &self->pos, &v);
        e->SetScaleAll(0x2000);
        diff = e->rot.y - self->rot_y;
        if (diff >= 0x1400 && diff <= 0x6c00) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f048, 0x800, 0);
        } else if (diff >= 0x9400 && diff <= 0xec00) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f044, 0x800, 0);
        }
        SndMgr_PlayAt(gSndMgr, self->sfx[8], &self->pos, 0);
        SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
        self->fsm->st = 0x21;
        break;
    }
    case 0x21:
        if (VEC_Distance(&self->pos, &self->unk_b8) < 0x3000) {
            self->friction = 0xf00;
        }
        if (self->speed < 0x100) {
            Model0218fe1c_SetAnim(self->model, data_ov010_0220f050, 0xcd, 0);
        }
        Actor_Move(self, 0);
        Actor_TurnToPos(self, &self->arena->center, 0x400);
        if (self->speed < 4) {
            self->fsm->st = 0x30;
        }
        break;
    }
}

}
}  // namespace m_02206f54
