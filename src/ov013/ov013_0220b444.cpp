#include "ov013/ov013.h"


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

// The camera-target object whose functions follow the "SHR2" name in data_ov013_0220b930:
// it keeps the player's camera point at actor id plus off, clamped to min/max when b1 is set.
struct Ov013Cam {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 id;
    VecFx32 min;
    VecFx32 max;
    VecFx32 off;
};

extern "C" {

void func_ov013_02204450(void);
Ov013Cam *Ov013Cam_Delete(Ov013Cam *self);
BOOL func_ov013_02204448(void);
void func_ov013_02204444(void);
void Ov013Cam_Follow(Ov013Cam *self);
void Ov013Cam_SetOffsetY(Ov013Cam *self, u32 *p);

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
const Ov013SpotBlock data_ov013_0220b930 = {"SHR2", {(Ov013Fn)func_ov013_02204450, (Ov013Fn)Ov013Cam_Delete, (Ov013Fn)func_ov013_02204448, (Ov013Fn)func_ov013_02204444, (Ov013Fn)Ov013Cam_Follow, (Ov013Fn)Ov013Cam_SetOffsetY}, {{data_ov013_0220afa0, 0xde4e}, {data_ov013_0220afac, 0x1b00}, {data_ov013_0220afb8, 0xaa65}, {data_ov013_0220afc4, 0x6b00}}};
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
    VecFx32 v;
};

extern "C" {

extern void *Ov013Act_021fea8c_vtbl[];
extern void *Ov003Vt_021f7cf4_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void Ov003Flag_Deactivate(void *p);
extern void Ov003Flag_Stop(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void *Ov003Vt_021f7cf4_Dtor(void *p);
extern void Ov003Flag_Stop_021d8fa8(void *p);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void func_ov003_021cf3fc(s32 a);
void Ov013Act_021fea8c_ClearFields(Ov013Act_021fea8c *self);
void Ov013Act_021fea8c_DtorBase(Ov013Act_021fea8c *self);

Ov013Act_021fea8c *Ov013Act_021fea8c_Ctor(Ov013Act_021fea8c *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov013Act_021fea8c_vtbl;
    Ov003Vt_021f7cf4_Ctor((u8 *)self + 0x12c);
    Ov003Vt_021f79a8_Ctor((u8 *)self + 0x13c);
    Ov003Flag_Deactivate((u8 *)self + 0x14c);
    Ov013Act_021fea8c_ClearFields(self);
    return self;
}

Ov013Act_021fea8c *Ov013Act_021fea8c_Dtor(Ov013Act_021fea8c *self) {
    *(void **)self = Ov013Act_021fea8c_vtbl;
    Ov013Act_021fea8c_DtorBase(self);
    Ov003Flag_Stop((u8 *)self + 0x14c);
    Ov003Vt_021f79a8_Dtor((u8 *)self + 0x13c);
    Ov003Vt_021f7cf4_Dtor((u8 *)self + 0x12c);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov013Act_021fea8c *Ov013Act_021fea8c_DtorDelete(Ov013Act_021fea8c *self) {
    *(void **)self = Ov013Act_021fea8c_vtbl;
    Ov013Act_021fea8c_DtorBase(self);
    Ov003Flag_Stop((u8 *)self + 0x14c);
    Ov003Vt_021f79a8_Dtor((u8 *)self + 0x13c);
    Ov003Vt_021f7cf4_Dtor((u8 *)self + 0x12c);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

static inline void Ov013_AddVec(VecFx32 *a, VecFx32 b, VecFx32 *out) {
    VEC_Add(a, &b, out);
}

static inline VecFx32 Ov013_GetOff(Ov013Opt120 *o) {
    VecFx32 off = data_ov013_0220af28;
    if (o->b0) {
        off.x = o->v.x;
        off.y = o->v.y;
        off.z = o->v.z;
    }
    return off;
}

BOOL Ov013Act_021fea8c_Draw(Ov013Act_021fea8c *self) {
    VecFx32 saved = self->pos;
    BOOL r;
    Ov013_AddVec(&self->pos, Ov013_GetOff(((Ov013Opt120 *)self->unk_120)), &self->pos);
    r = Ov003Actor_Draw(self);
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
        Heap_Free(o);
    }
}

void Ov013Act_021fea8c_DtorBase(Ov013Act_021fea8c *self) {
    void *saved;
    ((Ov013V *)((u8 *)self + 0x12c))->v08();
    ((Ov013V *)((u8 *)self + 0x13c))->v08();
    Ov003Flag_Stop_021d8fa8((u8 *)self + 0x14c);
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (((Ov013Opt120 *)self->unk_120) != NULL) {
        Ov013_DelOpt(((Ov013Opt120 *)self->unk_120));
        self->unk_120 = NULL;
    }
    gSysState->cur = saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (((Ov013Opt120 *)self->unk_124) != NULL) {
        Ov013_DelOpt(((Ov013Opt120 *)self->unk_124));
        self->unk_124 = NULL;
    }
    gSysState->cur = saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (((Ov013V *)self->unk_128) != NULL) {
        Ov013V *v = ((Ov013V *)self->unk_128);
        if (v != NULL) {
            v->v04();
        }
        self->unk_128 = NULL;
    }
    gSysState->cur = saved;
    EffectMgr_Kill(gEffectMgr, self->unk_100);
    EffectMgr_Kill(gEffectMgr, self->unk_104);
    Ov013Act_021fea8c_ClearFields(self);
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    func_ov003_021cf3fc(0);
}

Ov013Cam *Ov013Cam_Delete(Ov013Cam *self) {
    Heap_Free(self);
    return self;
}

void Ov013Act_021fea8c_ClearFields(Ov013Act_021fea8c *self) {
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

struct Ov013Opt120B {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 pad;
    u16 unk_02;
    VecFx32 v;
    VecFx32 w;
};

struct Ov013Opt124 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 unk_02;
    s32 unk_04;
    VecFx32 v;
    s32 unk_14;
    void *fn;
};

extern const u8 data_ov003_021f4340;
extern u8 data_ov013_0220b150[];
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void HitSphere_Link(ActorSub48 *p);
extern BOOL Ov003Flag_Init(void *p);
extern void Ov003Sequence_SetEntries(void *p, void *tbl, s32 n);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL Ov003StateMachine_Init(void *p);
extern void Ov003StateMachine_AddState(void *p, s32 a, void *b);
extern void Ov013_CopyVec(void *dst, const void *src, void *owner);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern void ActorMarker_Release(void *p);
extern BOOL Stage_UseScaledStats(void);

static inline void Ov013B_PartFlag(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
    }
}

static inline void Ov013Cam_Set(Ov013Cam *ar, u16 id) {
    ar->b0 = 1;
    ar->b1 = 1;
    ar->id = id;
    ar->min.x = -0x1464a;
    ar->min.y = 0x2000;
    ar->min.z = -0xad64;
    ar->max.x = 0xa89c;
    ar->max.y = 0xc642;
    ar->max.z = 0xc4cd;
}

void Ov013Act_021fea8c_Start(Ov013Act_021fea8c *self) {
    ActorSub48 *m48;
    Ov013Cam *ar;
    Ov013Opt120B *o2;
    Ov013Opt124 *o3;
    const char *anim;
    Model0218fe1c *m;
    s32 x;
    s32 y;
    s32 z;
    Ov003Actor_Start(self);
    self->unk_f0.b3 = 1;
    func_ov003_021cf330((u8 *)self + 0x13c, data_ov013_0220b930.name, data_ov003_021f4340);
    m48 = self->hit;
    m48->unk_9a_1 = 0;
    m48->unk_9a_4 = 0;
    m48 = self->hit;
    m48->unk_9a_0 = 1;
    m48->unk_9a_3 = 1;
    HitSphere_Link(m48);
    {
        ActorSub44 *n = self->unk_44;
        n->unk_1c = FX_Mul(n->unk_1c, 0x1800);
    }
    Ov003Flag_Init((u8 *)self + 0x14c);
    Ov003Sequence_SetEntries((u8 *)self + 0x14c, data_ov013_0220b150, 0xf);
    self->target = ActorMgr_FindPlayer()->id;
    ar = (Ov013Cam *)Heap_Alloc(sizeof(Ov013Cam));
    if (ar != NULL) {
        ar->vtbl = (void *)data_ov013_0220b930.fn;
        ar->b0 = 0;
    }
    self->unk_128 = ar;
    Ov013Cam_Set(ar, self->id);
    ar->off.x = x = data_ov013_0220af28.x;
    ar->off.y = y = data_ov013_0220af28.y;
    ar->off.z = z = data_ov013_0220af28.z;
    Ov003StateMachine_Init((u8 *)self + 0x12c);
    Ov003StateMachine_AddState((u8 *)self + 0x12c, 0, self->unk_128);
    o2 = (Ov013Opt120B *)Heap_Alloc(0x1c);
    if (o2 != NULL) {
        o2->b0 = 0;
    }
    self->unk_120 = o2;
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
    o3 = (Ov013Opt124 *)Heap_Alloc(0x1c);
    if (o3 != NULL) {
        o3->b0 = 0;
    }
    self->unk_124 = o3;
    o3->b0 = 0;
    o3->b1 = 0;
    o3->unk_02 = 0x1000;
    o3->unk_04 = 0;
    o3->v.x = x;
    o3->v.y = y;
    o3->v.z = z;
    o3->unk_14 = 0;
    o3->fn = (void *)Ov013_CopyVec;
    o3->b0 = 1;
    anim = data_ov013_0220aee0;
    Model0218fe1c_SetAnim(self->model, anim, 0x1000, 1);
    m = self->model;
    if (m->unk_14 != NULL) {
        ResSet *o = m->res;
        AnimCtrl_SetAnim(m->unk_14, m->renderObj, o, o->anims->list[2], anim, 0x1000, 0);
    }
    Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
    m = self->model;
    if (m != NULL) {
        Ov013B_PartFlag(m, 0);
        Ov013B_PartFlag(m, 1);
        Ov013B_PartFlag(m, 3);
        Ov013B_PartFlag(m, 4);
    }
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk_5c != NULL) {
            void *p = self->unk_5c;
            if (p != NULL) {
                ActorMarker_Release(p);
                Heap_Free(p);
            }
            self->unk_5c = NULL;
        }
        gSysState->cur = saved;
    }
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov013_0220af1e);
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

typedef void (Ov003Actor::*Ov013ActFn)();

struct Ov013StEnt {
    u8 key;
    Ov013ActFn fn;
};

struct Ov013Obj1c;
typedef void (*Ov013OffFn)(VecFx32 *out, VecFx32 *v, Ov003Actor *a);

struct Ov013Obj1c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    u32 unk_04;
    VecFx32 v;
    Ov003Actor *unk_14;
    Ov013OffFn unk_18;
};

struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    VecFx32 v;
    VecFx32 w;
};

extern "C" {

extern void Ov003Seq_Update(void *p);
extern BOOL Ov003Sequence_IsReady(void *p);
extern Ov013Pair Ov003Sequence_GetPair(void *p);
extern void Ov003ActorSub40_ApplyFlags(void *p);
extern void Actor_DropStateMsgs(Ov003Actor *self, s32 a);
extern void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov013Msg *msg);

void Ov013Act_021fea8c_UpdateMode1(void) {
}

void Ov013Act_021fea8c_Update(Ov013Act_021fea8c *self) {
    Ov013Pair p;
    if (!Ov003Actor_CanAct(self)) {
        return;
    }
    self->unk_93_4 = 1;
    self->unk_c4 = 0;
    self->unk_f0.b0 = 0;
    Ov003Seq_Update((u8 *)self + 0x14c);
    if (!Ov003Sequence_IsReady((u8 *)self + 0x14c)) {
        return;
    }
    p = Ov003Sequence_GetPair((u8 *)self + 0x14c);
    self->unk_15c = p.a;
    self->unk_15d = p.b;
    History_SetState(self->fsm, p.a, 1);
}

void Ov013Act_021fea8c_SelectState(Ov013Act_021fea8c *self) {
    Ov003ActorSub40_ApplyFlags(self->fsm);
    Actor_DropStateMsgs(self, self->fsm->current);
}

static inline void Ov013_Ack(Ov013Act_021fea8c *self, Ov013Msg *msg) {
    self->msg_flags |= 1 << msg->type;
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
        if (!Ov013_IsBusy(self->fsm->current)) {
            r = TRUE;
        }
    }
    return r;
}

BOOL Ov013Act_021fea8c_HandleMsg(Ov013Act_021fea8c *self, Ov013Msg *msg) {
    if (self->unk_f0.b0 && msg->type == 9) {
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    if (msg->type == 9) {
        if (!Ov013_IsInvul(self->hp) && self->fsm->current != 0x20) {
            self->hp[2] = msg->id;
            Ov003Actor_ApplyHit(self, &msg->hit);
            Ov003Actor_FadeColor(self, 0x14bf, 0x739f, 10);
            self->hp[5] = 5;
            Model0218fe1c_SetAnimDelay(self->model, 5, 0);
            if (self->hp[0] == 0) {
                self->fsm->flags |= 0x200000;
            } else if (Ov013_CanFlinch(self, msg)) {
                History_SetState(self->fsm, 0x12, 1);
            }
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return Ov003Actor_HandleMsg(self, msg);
}

extern const Ov013StEnt Ov013Act_021fea8c_StateTable[];
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern int func_ov003_021cf408(void);
extern void Ov003Vec_RotateY(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void HitSphere_Unlink_0203f364(void *p);
extern void HitSphere_Link(void *p);

struct Ov013Blk12 {
    s32 w[3];
};

static inline void Ov013_MoveToward(VecFx32 *v, const VecFx32 *w, s32 k, VecFx32 &d) {
    d.x = w->x - v->x;
    d.y = w->y - v->y;
    d.z = w->z - v->z;
    VEC_MultAdd(k, &d, v, v);
}


void Ov013Act_021fea8c_RunState(Ov013Act_021fea8c *self) {
    VecFx32 w;
    VecFx32 d;
    VecFx32 off;
    VecFx32 pos;
    u32 i;
    u8 key = self->fsm->current;
    for (i = 0; i < 9; i++) {
        if (key == Ov013Act_021fea8c_StateTable[i].key && *(s32 *)((u8 *)&Ov013Act_021fea8c_StateTable[i] + 4) != 0) {
            (self->*Ov013Act_021fea8c_StateTable[i].fn)();
            break;
        }
    }
    Ov003Actor_RunState(self);
    if (self->unk_f0.b4) {
        const char *anim;
        Model0218fe1c *m;
        if (self->unk_f0.b3) {
            anim = data_ov013_0220aeec;
        } else {
            anim = data_ov013_0220aef0;
        }
        m = self->model;
        if (m->unk_1c != NULL) {
            ResSet *o = m->res;
            AnimCtrl_SetAnim(m->unk_1c, m->renderObj, o, o->anims->list[4], anim, 0x1000, 0);
        }
    }
    self->unk_f0.b4 = 1;
    if (func_ov003_021cf408()) {
        self->mode = func_ov003_021cf408();
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
                Model0218fe1c *a = q->unk_14->model;
                a->color = 0x7fff;
                a->color2 = 0x3eaf;
                a->blend = 6;
                a->blendMax = 5;
            }
            if (q->unk_04 % 50 == 0) {
                Ov013_VecCopy(&pos, &q->unk_14->pos);
                q->unk_18(&off, &q->v, q->unk_14);
                VEC_Add(&pos, &off, &pos);
                Effect_SpawnId(0x66, &pos)->SetScaleAll(q->unk_02);
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
        if (Effect_Find_020657b0(gEffectMgr, self->unk_104) == NULL && !self->unk_f0.b2) {
            VecFx32 v;
            EffectObj *e;
            Ov003Vec_RotateY(&v, self->rot_y, &data_ov013_0220af34);
            VEC_Add(&v, &self->pos, &v);
            *(Ov013Blk12 *)&w = *(Ov013Blk12 *)&v;
            w.y = 0x1000;
            e = Effect_SpawnId(0x2bd, &w);
            e->SetScaleAll(0x4000);
            self->unk_104 = e->id;
        }
    } else {
        EffectMgr_StopLoop(gEffectMgr, self->unk_104);
        self->unk_104 = 0;
        Ov003Actor_SetColor(self, 0x4698);
    }
    self->unk_f0.b2 = 0;
    if (self->fsm->current != 0x15) {
        if (self->pos.y < -0xc000) {
            self->model->visible = 0;
        } else {
            s32 a;
            self->model->visible = 1;
            a = 0x1f;
            if (self->pos.y < -0x8000) {
                a = 0x1f >> (5 - ((self->pos.y + 0xd000) >> 12));
            }
            if (a > 0x1f) {
                a = 0x1f;
            } else if (a < 1) {
                a = 1;
            }
            self->model->alpha = a;
        }
    }
    if (self->unk_f0.b0) {
        ActorSub48 *m = self->hit;
        if (m != NULL) {
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
        }
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
    } else {
        ActorSub48 *m = self->hit;
        if (m != NULL) {
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
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

extern void Ov003Seq_Update(void *p);
extern BOOL Ov003Sequence_IsReady(void *p);
extern Ov013Pair Ov003Sequence_GetPair(void *p);
extern void Ov003ActorSub40_ApplyFlags(void *p);
extern void Actor_DropStateMsgs(Ov003Actor *self, s32 a);
extern void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov013Msg *msg);

extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern void Ov013_PickRandomSpot(VecFx32 *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude);
extern BOOL func_ov013_022038a8(Ov013Act_021fea8c *self, VecFx32 *pos, u16 rot);
extern void Ov003Sequence_Signal(void *p, s32 a);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void func_ov013_02202dc8(Ov013Act_021fea8c *self, s32 a, s32 b, BOOL c, s32 d);

static inline void Ov013_PartFlag(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
    }
}

static inline u32 Ov013_Nearest(const VecFx32 *p, const Ov013Spot *tbl, u32 n) {
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

void Ov013Act_021fea8c_StateIdle(Ov013Act_021fea8c *self) {
    const char *anim;
    Model0218fe1c *m;
    if (self->fsm->st != 0) {
        return;
    }
    anim = data_ov013_0220aee0;
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    Model0218fe1c_SetAnim(self->model, anim, 0x266, 0);
    m = self->model;
    if (m->unk_14 != NULL) {
        ResSet *o = m->res;
        AnimCtrl_SetAnim(m->unk_14, m->renderObj, o, o->anims->list[2], anim, 0x1000, 0);
    }
    Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
    m = self->model;
    if (m != NULL) {
        Ov013_PartFlag(m, 0);
        Ov013_PartFlag(m, 1);
        Ov013_PartFlag(m, 3);
        Ov013_PartFlag(m, 4);
    }
    self->rot_x = 0;
    self->rot_z = 0;
    self->fsm->st++;
}

void Ov013Act_021fea8c_StateMove(Ov013Act_021fea8c *self) {
    if (self->fsm->st == 0) {
        VecFx32 p;
        u32 best;
        Ov003Actor *pl = ActorMgr_FindPlayer();
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
            Ov013_PickRandomSpot(&self->unk_114, &self->unk_fc, data_ov013_0220b900, 3, (u8 *)self + 0x108);
            break;
        case 4:
            Ov013_PickRandomSpot(&self->unk_114, &self->unk_fc, data_ov013_0220b930.far, 4, (u8 *)self + 0x108);
            break;
        }
    }
    if (func_ov013_022038a8(self, &self->unk_114, self->unk_fc)) {
        self->unk_108 = self->unk_114;
        self->unk_fa = self->unk_fc;
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
        History_SetState(self->fsm, 1, 0);
    }
}

extern void *gSndMgr;
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern s32 Interp_SinLerp(s32 t, s32 a, s32 b);
extern BOOL Ov003Vec_Equal(VecFx32 *a, VecFx32 *b);
extern void Ov003Vec_ApproachWithin(VecFx32 *out, const VecFx32 *a, const VecFx32 *b, s32 dist, s32 yoff);

void Ov013Act_021fea8c_State29(Ov013Act_021fea8c *self) {
    BOOL move = FALSE;
    s32 c = 0;
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        move = TRUE;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af04, 0x266, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *o = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, o, o->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlag(m, 0);
            Ov013_PartFlag(m, 1);
            Ov013_PartFlag(m, 3);
            Ov013_PartFlag(m, 4);
        }
        {
            VecFx32 v;
            Ov013_VecCopy(&v, &self->pos);
            v.y -= 0xf000;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x100;
            Ov013_VecCopy(&self->unk_b8, &v);
        }
        self->fsm->st = 1;
        {
            ActorSub48 *s = self->hit;
            s->unk_9a_0 = 0;
            s->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s);
        }
        SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        break;
    }
    case 1: {
        s32 t;
        s32 sp;
        VecFx32 v;
        self->fsm->timer++;
        t = FX_Div(self->fsm->timer << 12, 0x1e000);
        if (t > 0x1000) {
            c = 0x1000;
        } else if (t >= 0) {
            c = t;
        }
        self->rot_x = Interp_SinLerp(c, 0, 0x4000);
        t = self->speed + 0x30;
        sp = 0;
        if (t > 0x1000) {
            sp = 0x1000;
        } else if (t >= 0) {
            sp = t;
        }
        self->speed = sp;
        v = self->unk_b8;
        if (Ov003Vec_Equal(&v, &self->pos)) {
            self->fsm->st = 2;
        } else {
            move = TRUE;
        }
        break;
    }
    case 2:
        EffectMgr_Kill(gEffectMgr, self->unk_100);
        self->unk_100 = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
        break;
    }
    if (move) {
        VecFx32 v;
        Ov013_VecCopy(&v, &self->unk_b8);
        Ov003Vec_ApproachWithin(&self->pos, &v, &self->pos, self->speed, self->velY);
        Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
    }
}

}
}  // namespace m_021ff924

// ---- merged from ov013_021fffd0.cpp
namespace m_021fffd0 {
extern "C" {

extern void Ov013_PickRandomSpot(VecFx32 *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude);
extern BOOL func_ov013_02203ea4(Ov013Act_021fea8c *self, VecFx32 *pos);
extern void Ov003Sequence_Signal(void *p, s32 a);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void HitSphere_Link(ActorSub48 *p);

static inline u32 Ov013_Nearest(const VecFx32 *p, const Ov013Spot *tbl, u32 n) {
    u32 best = 0;
    u32 i;
    for (i = 0; i < n; i++) {
        if (VEC_Distance(p, &tbl[best].pos) > VEC_Distance(p, &tbl[i].pos)) {
            best = i;
        }
    }
    return best;
}

void Ov013Act_021fea8c_State2a(Ov013Act_021fea8c *self) {
    if (self->fsm->st == 0) {
        VecFx32 p;
        u32 best;
        ActorSub48 *m;
        Ov003Actor *pl = ActorMgr_FindPlayer();
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
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
            Ov013_PickRandomSpot(&self->unk_114, &self->unk_fc, data_ov013_0220b900, 3, (u8 *)self + 0x108);
            break;
        case 4:
            Ov013_PickRandomSpot(&self->unk_114, &self->unk_fc, data_ov013_0220b930.far, 4, (u8 *)self + 0x108);
            break;
        }
    }
    if (func_ov013_02203ea4(self, &self->unk_114)) {
        self->unk_108 = self->unk_114;
        self->unk_fa = self->unk_fc;
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
    }
}

extern void func_ov013_02202dc8(Ov013Act_021fea8c *self, u16 a, s32 b, BOOL c, u16 d);

void Ov013Act_021fea8c_StateAttack(Ov013Act_021fea8c *self) {
    BOOL m;
    if (self->unk_15d != 1) {
        m = FALSE;
        // Kept (round auA honesty audit): never-true pointer-bit test. Without it the call's argument
        // moves are scheduled differently (9 if/ternary/init/u8 forms tried). The file has .rodata,
        // .data and .ctor and the function is mid-file, so it can't be cut out to a dsd gap.
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
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void *gSndMgr;
extern void *Tbl_FindEntry_0206fef8(u16 id);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Ov003Vec_RotateY(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void Ov013ActEx_02205ae4_Launch(Ov013ActEx_02205ae4 *self, const VecFx32 *v, u16 id, u16 plid, u16 r, u16 rot);
extern u32 Ov013ActEx_02205ae4_IsDone(Ov013ActEx_02205ae4 *self);
extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);
extern void Ov003_ClearWords4(u32 *p);
extern void Ov003StateMachine_SendMessage(void *sm, void *arg);
extern void Ov003Sequence_Signal(void *p, s32 a);

struct Ov013Opt120b {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    VecFx32 v;
    VecFx32 w;
};

static inline void Ov013b_PathTarget(Ov013Act_021fea8c *self, const VecFx32 &v) {
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

static inline VecFx32 Ov013b_FrontPos(Ov013Act_021fea8c *self, const VecFx32 *off) {
    VecFx32 v;
    Ov003Vec_RotateY(&v, self->rot_y, off);
    VEC_Add(&v, &self->pos, &v);
    return v;
}

static inline VecFx32 Ov013b_Lift(s32 h) {
    VecFx32 v = {0, 0, 0};
    v.y = -FX_Mul(h, 0x900);
    return v;
}

static inline void Ov013b_Set84(Ov013Act_021fea8c *self, const VecFx32 &v) {
    self->unk_84.x = v.x;
    self->unk_84.y = v.y;
    self->unk_84.z = v.z;
}

static inline void Ov013b_Place(Ov013Act_021fea8c *self, Ov013ActEx_02205ae4 *o, Ov003Actor *pl, s32 x, u16 dr) {
    u16 rot = self->rot_y;
    VecFx32 v;
    u16 r;
    v.x = x;
    v.y = 0x4cd;
    v.z = 0;
    r = rot + dr;
    Ov003Vec_RotateY(&v, self->rot_y, &v);
    VEC_Add(&v, &self->pos, &v);
    Ov013ActEx_02205ae4_Launch(o, &v, self->id, pl->id, r, self->rot_y);
}

// The two linked ov013 objects (unk_f4/unk_f6) are Ov013ActEx_02205ae4.
static inline Ov013ActEx_02205ae4 *Ov013b_Find(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return (Ov013ActEx_02205ae4 *)ActorMgr_GetActor(gActorMgr, id);
}

static inline void Ov013b_PartSet(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->paused = 1;
    }
}

static inline void Ov013b_PartClr(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->paused = 0;
    }
}

static inline void Ov013b_PartB2(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
    }
}

static inline void Ov013b_PartsSet(Model0218fe1c *m) {
    if (m != NULL) {
        Ov013b_PartSet(m, 0);
        Ov013b_PartSet(m, 1);
        Ov013b_PartSet(m, 3);
        Ov013b_PartSet(m, 4);
    }
}

static inline void Ov013b_PartsClr(Model0218fe1c *m) {
    if (m != NULL) {
        Ov013b_PartClr(m, 0);
        Ov013b_PartClr(m, 1);
        Ov013b_PartClr(m, 3);
        Ov013b_PartClr(m, 4);
    }
}

static inline void Ov013b_Fade(void) {
    FieldState *g = gSceneCmd;
    g->cam.base.shakeX = 1;
    g->cam.base.shakeY = 1;
    g->cam.base.shakeZ = 1;
    g->cam.base.shakeTime = 10;
    g->cam.base.shakeLen = 0xf;
    g->cam.base.shakeCur = 0xf;
}

static inline void Ov013b_Link(Ov013Act_021fea8c *self, u16 *out, s32 kind) {
    Actor *o = Ov003_SpawnById(kind);
    o->flags_0 = 1;
    o->target = ActorMgr_FindPlayer()->id;
    o->targetObj->target = self->id;
    o->rot_y = self->rot_y;
    *out = o->id;
}

void Ov013Act_021fea8c_StateAttack2(Ov013Act_021fea8c *self) {
    Ov013ActEx_02205ae4 *a = NULL;
    Ov013ActEx_02205ae4 *b = NULL;
    s32 zone = 0;
    BOOL move = FALSE;
    BOOL path = TRUE;
    self->unk_f0.b2 = 1;
    self->unk_f0.b4 = 0;
    switch (self->fsm->st) {
    case 0: {
        void *info;
        s32 k;
        EffectObj *o;
        Model0218fe1c *m;
        move = TRUE;
        self->unk_f0.b3 = 1;
        Ov013b_Link(self, &self->unk_f4, 0x4808);
        Ov013b_Link(self, &self->unk_f6, 0x4809);
        self->gravity = 0x60;
        self->velY = 0x800;
        self->speed = 0;
        self->friction = 0;
        info = Tbl_FindEntry_0206fef8(self->kind);
        k = FX_Mul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        Ov013b_Set84(self, Ov013b_Lift(k));
        o = Effect3D_Create(data_ov013_0220aee4, data_ov013_0220aee8, 0, &self->pos);
        o->unk_28 = 0;
        o->SetScale(&data_ov013_0220af7c);
        self->rot_x = 0;
        Ov013b_Fade();
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af08, 0x1000, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        self->fsm->st = 0xa;
        SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        SndMgr_PlayAtPitch(gSndMgr, 0x3c, &self->pos, -5);
        break;
    }
    case 0xa:
        move = TRUE;
        if (self->velY < 0) {
            self->fsm->st = 0x1e;
        }
        break;
    case 0x1e: {
        a = Ov013b_Find(self->unk_f4);
        b = Ov013b_Find(self->unk_f6);
        if (a == NULL || b == NULL) {
            self->fsm->st = 0x50;
        } else if (a != NULL && b != NULL && a->state == 2 && b->state == 2) {
            self->fsm->st = 0x28;
        }
        break;
    }
    case 0x28:
        Ov013b_PartsClr(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x29;
        SndMgr_PlayAt(gSndMgr, 0x54, &self->pos, 0);
        break;
    case 0x29:
        if (self->model->anim_state == 2) {
            Ov003Actor *pl;
            a = Ov013b_Find(self->unk_f4);
            b = Ov013b_Find(self->unk_f6);
            pl = ActorMgr_FindPlayer();
            if (a == NULL || b == NULL || pl == NULL) {
                self->fsm->st = 0x50;
            } else {
                VecFx32 v;
                u16 r;
                r = self->rot_y + 0xbfff;
                v.x = -0x14d1;
                v.y = 0x4cd;
                v.z = 0;
                Ov003Vec_RotateY(&v, self->rot_y, &v);
                VEC_Add(&v, &self->pos, &v);
                Ov013ActEx_02205ae4_Launch(a, &v, self->id, pl->id, r, self->rot_y);
                r = self->rot_y + 0x4000;
                v.y = 0x4cd;
                v.x = 0x14d1;
                v.z = 0;
                Ov003Vec_RotateY(&v, self->rot_y, &v);
                VEC_Add(&v, &self->pos, &v);
                Ov013ActEx_02205ae4_Launch(b, &v, self->id, pl->id, r, self->rot_y);
            }
            SndMgr_PlayAtPitch(gSndMgr, 0x32, &self->pos, 10);
        }
        if (self->model->anim_state == 3) {
            Ov013b_PartsSet(self->model);
            self->fsm->st = 0x32;
        }
        break;
    case 0x32: {
        a = Ov013b_Find(self->unk_f4);
        b = Ov013b_Find(self->unk_f6);
        if (a != NULL && Ov013ActEx_02205ae4_IsDone(a)) {
            VecFx32 p;
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            if (Ov003Vec_DistSq(&self->pos, &p) < 0x9000) {
                a->vfunc_08();
                self->unk_f4 = 0xffff;
            }
        }
        if (b != NULL && Ov013ActEx_02205ae4_IsDone(b)) {
            VecFx32 p;
            p.x = b->pos.x;
            p.y = b->pos.y;
            p.z = b->pos.z;
            if (Ov003Vec_DistSq(&self->pos, &p) < 0x9000) {
                b->vfunc_08();
                self->unk_f6 = 0xffff;
            }
        }
        if (a == NULL && b == NULL) {
            SndMgr_PlayAtPitch(gSndMgr, 0x66, &self->pos, -5);
            self->fsm->st = 0x3c;
        }
        break;
    }
    case 0x3c:
        move = TRUE;
        Ov013b_PartsClr(self->model);
        self->speed = 0;
        self->velY = 0x4cd;
        self->friction = 0x1000;
        self->gravity = 0x19a;
        self->fsm->st = 0x3d;
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
            self->fsm->st = 0x46;
        } else if (self->model->anim_state == 4) {
            Ov013b_PartsSet(self->model);
        }
        break;
    }
    case 0x46: {
        path = FALSE;
        Ov013b_PartsClr(self->model);
        Ov013b_Fade();
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x47;
        {
            VecFx32 t = Ov013b_FrontPos(self, &data_ov013_0220af34);
            EffectObj *o = Effect3D_Create(data_ov013_0220aee4, data_ov013_0220aee8, 0, &t);
            o->unk_28 = 0;
            o->SetScale(&data_ov013_0220af88);
        }
        SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        SndMgr_PlayAtPitch(gSndMgr, 0x3d, &self->pos, -5);
        break;
    }
    case 0x47:
        path = FALSE;
        self->fsm->timer++;
        if (self->fsm->timer > 0x14 && Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->timer = 0;
            self->fsm->st = 0x50;
            break;
        }
        if (self->fsm->timer > 10) {
            Ov013b_PathTarget(self, data_ov013_0220af28);
            Ov013b_PathSpeed(self, 0x180);
        } else {
            Ov013b_PathTarget(self, self->unk_84);
            Ov013b_PathSpeed(self, 0x140);
        }
        break;
    case 0x50: {
        Model0218fe1c *m;
        const char *name;
        path = FALSE;
        self->unk_f0.b4 = 1;
        self->unk_f4 = 0xffff;
        self->unk_f6 = 0xffff;
        name = data_ov013_0220aee0;
        Model0218fe1c_SetAnim(self->model, name, 0x800, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], name, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
        if (m != NULL) {
            Ov013b_PartB2(m, 0);
            Ov013b_PartB2(m, 1);
            Ov013b_PartB2(m, 3);
            Ov013b_PartB2(m, 4);
        }
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
    if (move) {
        Actor_Move(self, 0);
    }
    if (path) {
        u32 cmd[4];
        Ov003_ClearWords4(cmd);
        cmd[0] = 0x2800;
        Ov003StateMachine_SendMessage((u8 *)self + 0x12c, cmd);
    }
}



extern void *gSndMgr;
extern u8 data_ov013_0220b090[];
extern u8 data_ov013_0220b0cc[];
extern void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
extern void Ov003Vec_RotateY(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_ov013_02203494(Ov013Act_021fea8c *self, BOOL a, BOOL b, s32 c, void *d);

static inline EffectObj *Ov013_SpawnFx(s32 id, const VecFx32 &pos) {
    return Effect_SpawnId(id, &pos);
}

static inline VecFx32 Ov013_FrontPos(Ov013Act_021fea8c *self, const VecFx32 *off) {
    VecFx32 v;
    Ov003Vec_RotateY(&v, self->rot_y, off);
    VEC_Add(&v, &self->pos, &v);
    return v;
}

void Ov013Act_021fea8c_State28(Ov013Act_021fea8c *self) {
    if (self->fsm->st != 0) {
        return;
    }
    Model0218fe1c_SetAnimDelay(self->model, 0x28, 1);
    Ov013_SpawnFx(0x196, Ov013_FrontPos(self, &data_ov013_0220af34))->SetScaleAll(0x2000);
    SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
    SndMgr_PlayAt(gSndMgr, 0x36, &self->pos, 0);
    self->fsm->st++;
}

void Ov013Act_021fea8c_StateShoot(Ov013Act_021fea8c *self) {
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

void Ov013Act_021fea8c_State20(Ov013Act_021fea8c *self) {
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_18) {
    case 0:
        Ov003Actor_State20(self);
        break;
    case 1: {
        ActorSub40 *s = self->fsm;
        if (s->st == 0) {
            self->pos.x = -0x212b;
            self->pos.y = 0x2000;
            self->pos.z = -0xb3a2;
            self->rot_y = 0;
            s->st++;
        } else {
            s->timer++;
            if (self->fsm->timer > 0x1e) {
                History_SetState(self->fsm, 1, 0);
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
    VecFx32 v;
    VecFx32 w;
};

extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b150[];
extern u8 data_ov013_0220b218[];
extern void Ov003Sequence_Signal(void *p, s32 a);
extern void Ov003Sequence_SetPaused(void *p, s32 a);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern Ov003Actor *Target_GetActor(void *p);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern s32 SndMgr_PlayPan(void *a, s32 b, s32 c);
extern BOOL AnimCtrl_IsDone(void *a);
extern BOOL Model0218fe1c_IsAnimDelayed(void *m);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void *Tbl_FindEntry_0206fef8(u16 id);
extern BOOL Ov003Sequence_HasEntries(void *p, void *tbl);
extern void Ov003Sequence_SetEntries(void *p, void *tbl, s32 n);

static inline VecFx32 Ov013_MakeVec(s32 x, s32 y, s32 z) {
    VecFx32 v;
    Ov013_VecSet(&v, x, y, z);
    return v;
}

static inline VecFx32 Ov013_Lift(s32 h) {
    VecFx32 v = {0, 0, 0};
    v.y = -FX_Mul(h, 0x600);
    return v;
}

static inline void Ov013_PathTarget(Ov013Act_021fea8c *self, const VecFx32 &v) {
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

void Ov013Act_021fea8c_StateHurt(Ov013Act_021fea8c *self) {
    self->hit->unk_9a_4 = 1;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        u16 ang;
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
        Ov003Sequence_SetPaused((u8 *)self + 0x14c, 1);
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af00, 0x800, 1);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        Model0218fe1c_SetAnimDelay(self->model, 5, 1);
        if (((void *)self->hp) != NULL) {
            Ov003Actor *a = Target_GetActor(((void *)self->hp));
            if (a != NULL && a != self) {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            } else {
                ang = self->rot_y;
            }
        } else {
            ang = self->rot_y;
        }
        self->unk_96 = ang;
        self->moveYaw = self->unk_96 + 0x8000 + Rand_PlusMinus(0x2000);
        self->rot_y = Angle_Approach(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        self->speed = 0x27b;
        self->velY = 0x39a;
        self->friction = 0xcb8;
        self->gravity = 0x52;
        ActorMgr_BroadcastKind(gActorMgr, 0x4808, 0x15);
        ActorMgr_BroadcastKind(gActorMgr, 0x4809, 0x15);
        SndMgr_PlayPan(gSndMgr, 0x41, 4);
        if (self->pos.y - 0x2000 > 0x2000) {
            self->fsm->st = 0x14;
        } else {
            self->fsm->st = 0xa;
        }
        break;
    }
    case 0xa:
        if (self->hit->unk_50 & 0x20000000) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            if (AnimCtrl_IsDone(Model0218fe1c_GetAnimCtrl(self->model, 0))) {
                self->fsm->st = 0x64;
            }
            break;
        }
        if (!Model0218fe1c_IsAnimDelayed(self->model)) {
            Actor_Move(self, 0);
        }
        break;
    case 0x14:
        if (self->hit->unk_50 & 0x20000000) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st = 0x1e;
            break;
        }
        if (!Model0218fe1c_IsAnimDelayed(self->model)) {
            Actor_Move(self, 0);
        }
        break;
    case 0x1e: {
        VecFx32 t = Ov013_FrontPos(self, &data_ov013_0220af34);
        EffectObj *o;
        void *info;
        s32 k;
        o = Effect3D_Create(data_ov013_0220aee4, data_ov013_0220aee8, 0, &t);
        o->unk_28 = 0;
        o->SetScale(&data_ov013_0220af88);
        SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        SndMgr_PlayAtPitch(gSndMgr, 0x3d, &self->pos, -5);
        info = Tbl_FindEntry_0206fef8(self->kind);
        k = FX_Mul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        {
            VecFx32 w2 = Ov013_Lift(k);
            self->unk_84.x = w2.x;
            self->unk_84.y = w2.y;
            self->unk_84.z = w2.z;
        }
        self->fsm->st = 0x1f;
    }
    case 0x1f:
        self->fsm->timer++;
        if (self->fsm->timer > 0xf && Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->timer = 0;
            self->fsm->st = 0x64;
            break;
        }
        if (self->fsm->timer > 6) {
            Ov013_PathTarget(self, data_ov013_0220af28);
            Ov013_PathSpeed(self, 0x280);
        } else {
            Ov013_PathTarget(self, self->unk_84);
            Ov013_PathSpeed(self, 0x240);
        }
        break;
    case 0x64: {
        s32 r = (self->hp[0] << 12) / self->hp[1];
        if (r <= 0x666) {
            if (Ov003Sequence_HasEntries((u8 *)self + 0x14c, data_ov013_0220b218) || Ov003Sequence_HasEntries((u8 *)self + 0x14c, data_ov013_0220b150)) {
                Ov003Sequence_SetEntries((u8 *)self + 0x14c, data_ov013_0220b108, 0xc);
            } else if (Ov003Sequence_HasEntries((u8 *)self + 0x14c, data_ov013_0220b03a)) {
                Ov003Sequence_SetEntries((u8 *)self + 0x14c, data_ov013_0220b064, 7);
            }
        } else if (r <= 0xccd) {
            if (Ov003Sequence_HasEntries((u8 *)self + 0x14c, data_ov013_0220b150)) {
                Ov003Sequence_SetEntries((u8 *)self + 0x14c, data_ov013_0220b218, 0x14);
            }
        }
        Ov003Sequence_SetPaused((u8 *)self + 0x14c, 0);
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}

extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern VecFx32 Ov003Actor_GetSub44Offset(Ov003Actor *self);
extern void *Ov003_SpawnScatterFx(VecFx32 *pos, s32 a, s32 b);
extern void Field_ShakeCamera(s32 a, s32 b);

#define OV013_CLAMP(x, lo, hi) ((x) > (hi) ? (hi) : ((x) < (lo) ? (lo) : (x)))

void Ov013Act_021fea8c_StateDie(Ov013Act_021fea8c *self) {
    self->hit->unk_9a_4 = 1;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        ActorSub48 *m48;
        ActorSub44 *n;
        u16 ang;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af00, 0x800, 1);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        Model0218fe1c_SetAnimDelay(self->model, 5, 1);
        ActorMgr_BroadcastKind(gActorMgr, 0x483e, 0x15);
        ActorMgr_BroadcastKind(gActorMgr, 0x4808, 0x15);
        ActorMgr_BroadcastKind(gActorMgr, 0x4809, 0x15);
        ActorMgr_BroadcastKind(gActorMgr, 0x4807, 0x15);
        EffectMgr_Kill(gEffectMgr, self->unk_100);
        self->hp[0] = 0;
        m48 = self->hit;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        self->speed = 0x27b;
        self->velY = 0x39a;
        self->friction = 0xcb8;
        self->gravity = 0x52;
        if (((void *)self->hp) != NULL) {
            Ov003Actor *a = Target_GetActor(((void *)self->hp));
            if (a != NULL && a != self) {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            } else {
                ang = self->rot_y;
            }
        } else {
            ang = self->rot_y;
        }
        self->unk_96 = ang;
        self->moveYaw = self->unk_96 + 0x8000 + Rand_PlusMinus(0x2000);
        self->speed = 0x27b;
        self->velY = 0;
        self->friction = 0xcb8;
        self->gravity = 0x52;
        self->fsm->st = 0xa;
        break;
    }
    case 0xa:
        if (self->hit->unk_50 & 0x20000000) {
            VecFx32 p = Ov003Actor_GetSub44Offset(self);
            EffectObj *o = Effect_SpawnId(0x390, &self->pos);
            if (o != NULL) {
                self->unk_100 = o->id;
                o->AddPos(&p);
                o->SetScaleAll(0x1800);
            }
            o = Effect_SpawnId(0x69, &self->pos);
            if (o != NULL) {
                o->AddPos(&p);
                o->SetScaleAll(0x5000);
            }
            SndMgr_PlayAt(gSndMgr, 0x56, &self->pos, 0);
            Field_ShakeCamera(0xc, 0x28);
            self->fsm->st = 0x14;
        }
    case 0x14: {
        ActorSub40 *q = self->fsm;
        u16 t;
        q->timer++;
        t = q->timer;
        if (t >= 0x78) {
            if (t % 30 == 0) {
                VecFx32 a = Ov003Actor_GetSub44Offset(self);
                VecFx32 b;
                VEC_Add(&self->pos, &a, &b);
                Ov003_SpawnScatterFx(&b, self->radius, 0x38b);
                Field_ShakeCamera(8, 8);
                SndMgr_PlayAt(gSndMgr, 0x35, &self->pos, 0);
            }
            if (t >= 0x12b) {
                Field_ShakeCamera(0x14, 0x78);
                self->fsm->timer = 0;
                self->fsm->st = 0x1e;
            }
        } else {
            if (t % 25 == 0) {
                SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
            }
            if (t == 0x6e) {
                EffectMgr_StopLoop(gEffectMgr, self->unk_100);
                self->unk_100 = 0;
            }
        }
        break;
    }
    case 0x1e: {
        VecFx32 p = Ov003Actor_GetSub44Offset(self);
        EffectObj *o = Effect_SpawnId(0x38b, &self->pos);
        if (o != NULL) {
            o->AddPos(&p);
            o->SetScaleAll(0x3000);
        }
        o = Effect_SpawnId(0x69, &self->pos);
        if (o != NULL) {
            o->AddPos(&p);
            o->SetScaleAll(0x5000);
            o->speed = 0xccd;
        }
        SndMgr_PlayAtPitch(gSndMgr, 0x56, &self->pos, -8);
        SndMgr_PlayAtPitch(gSndMgr, 0x41, &self->pos, 4);
        self->fsm->st = 0x64;
        break;
    }
    case 0x64:
        self->unk_f0.b2 = 1;
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer > 0x78) {
                Ov003Actor_Defeat(self, 1, 1, 1);
                break;
            }
        }
        {
            s32 a = 0x1f - (self->fsm->timer >> 1);
            Ov003Actor_SetAlpha(self, OV013_CLAMP(a, 1, 0x1f));
        }
        break;
    }
    Body_Update(self->hit, 1, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
    } else {
        Actor_Move(self, 0);
    }
}

struct Ov013Obj1c;
typedef void (*Ov013OffFn)(VecFx32 *out, VecFx32 *v, Ov003Actor *a);

struct Ov013Obj1c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    u32 unk_04;
    VecFx32 v;
    Ov003Actor *unk_14;
    Ov013OffFn unk_18;
};

extern void Ov013_CopyVec(VecFx32 *out, VecFx32 *v, Ov003Actor *a);
extern void Ov013_RotateByActorYaw(VecFx32 *out, VecFx32 *v, Ov003Actor *a);
extern s32 Ov003_CountActorsOfKind(u16 kind);
extern void Ov003Sequence_Update(void *p);
extern s32 Ov013_FindActorsNear(Ov003Actor **out, s32 max, u16 kind, VecFx32 *pos, s32 dist);
extern Ov003Actor *ActorMgr_FindPlayer(void);

static inline void Ov013_PartFlagB2(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
    }
}

static inline VecFx32 Ov013_Lift2(s32 h) {
    VecFx32 v = {0, 0, 0};
    v.y = -FX_Mul(h, 0x480);
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

static inline void Ov013Obj_Start(Ov013Obj1c *q, Ov003Actor *owner, s16 sp, const VecFx32 *v, Ov013OffFn fn) {
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

static inline s32 Ov013_Mode(Ov003Actor *a) {
    return a->fsm != NULL ? a->fsm->current : 0;
}

static inline BOOL Ov013_IsMarked(Ov003Actor *a) {
    if (a == NULL) {
        return FALSE;
    }
    if (a->kind != 0x483e) {
        return FALSE;
    }
    if (Ov013_Mode(a) != 0xb) {
        return FALSE;
    }
    if (ActorMgr_FindPlayer() == NULL) {
        return FALSE;
    }
    u16 id = ActorMgr_FindPlayer()->id;
    if (id != a->targetObj->target) {
        return FALSE;
    }
    return TRUE;
}

void Ov013Act_021fea8c_State30(Ov013Act_021fea8c *self) {
    Ov003Actor *list[8];
    self->unk_f0.b2 = 1;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        EffectObj *o;
        void *info;
        s32 k;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af10, 0x266, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        Ov013Obj_Start(((Ov013Obj1c *)self->unk_124), self, 0x1000, &data_ov013_0220af28, Ov013_CopyVec);
        Ov013Obj_SetSpeed(((Ov013Obj1c *)self->unk_124), 0x3000);
        Ov013Obj_SetVec(((Ov013Obj1c *)self->unk_124), 0, 0, -0x3000);
        Ov013Obj_SetFn(((Ov013Obj1c *)self->unk_124), Ov013_RotateByActorYaw);
        self->rot_x = 0;
        self->rot_z = 0;
        SndMgr_PlayAtPitch(gSndMgr, 0x44, &self->pos, 3);
        o = Effect_SpawnId(0x69, &self->pos);
        o->SetScaleAll(0x2000);
        EffectMgr_Kill(gEffectMgr, self->unk_100);
        self->unk_100 = o->id;
        info = Tbl_FindEntry_0206fef8(self->kind);
        k = FX_Mul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        {
            VecFx32 w2 = Ov013_Lift2(k);
            ActorSub48 *m48;
            self->unk_84.x = w2.x;
            self->unk_84.y = w2.y;
            self->unk_84.z = w2.z;
            m48 = self->hit;
            m48->unk_9a_0 = 0;
            m48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m48);
        }
        self->fsm->st = 1;
    }
    case 1: {
        s32 n;
        s32 i;
        BOOL found;
        EffectObj *p;
        if (!Ov003_CountActorsOfKind(0x483e)) {
            Ov003Sequence_Update((u8 *)self + 0x14c);
            self->fsm->st = 2;
            break;
        }
        n = Ov013_FindActorsNear(list, 8, 0x483e, &self->pos, FX_Mul(self->radius, self->model->scale.x) / 2 + 0x5000);
        found = FALSE;
        for (i = 0; i < n; i++) {
            if (Ov013_IsMarked(list[i])) {
                found = TRUE;
                break;
            }
        }
        if (found) {
            Ov003Sequence_SetPaused((u8 *)self + 0x14c, 1);
            Ov003Sequence_Update((u8 *)self + 0x14c);
            History_SetState(self->fsm, 0x31, 1);
        }
        p = Effect_Find_020657b0(gEffectMgr, self->unk_100);
        if (p == NULL) {
            self->unk_100 = 0;
        } else {
            p->SetRotXYZ(p->rot.x, (u16)(p->rot.y + 0x400), p->rot.z);
        }
        break;
    }
    }
    self->unk_f0.b1 = 1;
    Ov013_PathSpeed(self, 0x100);
    Ov013_PathTarget(self, self->unk_84);
}


static inline VecFx32 Ov013_Lift3(s32 h) {
    VecFx32 v = {0, 0, 0};
    v.y = -FX_Mul(h, 0x900);
    return v;
}

struct Ov013HitArg {
    u8 a;
};

static inline void Ov013_Hit(Ov003Actor *t, Ov003Actor *self) {
    Ov013HitArg arg;
    arg.a = 1;
    t->target = ActorMgr_FindPlayer()->id;
    Actor_SendMsg(t, self->id, 0xe, 0, 1, &arg);
}

void Ov013Act_021fea8c_State31(Ov013Act_021fea8c *self) {
    self->unk_f0.b2 = 1;
    self->unk_f0.b0 = true;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        void *info;
        s32 k;
        info = Tbl_FindEntry_0206fef8(self->kind);
        k = FX_Mul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        Ov013b_Set84(self, Ov013_Lift3(k));
        Ov013_PathSpeed(self, 0x19a);
        Ov003Sequence_SetPaused((u8 *)self + 0x14c, 1);
        Model0218fe1c_SetAnim(self->model, data_ov013_0220aefc, 0x800, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *q = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, q, q->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        self->fsm->st = 0xa;
        SndMgr_PlayAt(gSndMgr, 0x65, &self->pos, 0);
        break;
    }
    case 0xa:
        Ov013_PathTarget(self, self->unk_84);
        if (self->model->anim_state == 2) {
            self->fsm->st = 0x14;
        }
        break;
    case 0x14:
        Ov013_PathTarget(self, data_ov013_0220af28);
        if (AnimCtrl_IsDone(Model0218fe1c_GetAnimCtrl(self->model, 0))) {
            self->fsm->st = 0x28;
        }
        break;
    case 0x28: {
        s32 r = (self->hp[0] << 12) / self->hp[1];
        if (r <= 0x666) {
            self->unk_f8 = 0xaf;
        } else {
            self->unk_f8 = 0x118;
        }
        History_SetState(self->fsm, 0x32, 0);
        break;
    }
    }
    if (self->model->anim_state == 3) {
        VecFx32 t = Ov013_FrontPos(self, &data_ov013_0220af34);
        EffectObj *o = Effect3D_Create(data_ov013_0220aee4, data_ov013_0220aee8, 0, &t);
        o->unk_28 = 0;
        o->SetScale(&data_ov013_0220af88);
    }
    if (self->model->anim_state != 1) {
        return;
    }
    {
    Ov003Actor *list[8];
    VecFx32 p;
    s32 n;
    s32 i;
    BOOL hit;
    n = Ov013_FindActorsNear(list, 8, 0x483e, &self->pos, FX_Mul(self->radius, self->model->scale.x) / 2 + 0x4000);
    hit = FALSE;
    for (i = 0; i < n; i++) {
        if (Ov013_Mode(list[i]) != 0x15) {
            Ov013HitArg arg;
            EffectObj *e;
            arg.a = 1;
            list[i]->target = ActorMgr_FindPlayer()->id;
            Actor_SendMsg((Actor *)list[i], self->id, 0xe, 0, 1, &arg);
            p = list[i]->pos;
            e = Effect_SpawnId(0x6d, &p);
            e->SetRotXYZ(0x4000, (u16)(list[i]->rot_y + 0x7fff), 0);
            e->SetScaleAll(0x4000);
            hit = TRUE;
        }
    }
    if (hit) {
        Model0218fe1c_SetAnimDelay(self->model, 3, 1);
        SndMgr_PlayAtPitch(gSndMgr, 0x2c, &self->pos, -3);
    }
    }
}

extern void HitSphere_Link(ActorSub48 *p);
extern const VecFx32 data_ov013_0220afd0;
extern const VecFx32 data_ov013_0220afdc;

static inline void Ov013c_Anim(Ov013Act_021fea8c *self, const char *nm, s32 sp, s32 loop) {
    Model0218fe1c *m;
    Model0218fe1c_SetAnim(self->model, nm, sp, loop);
    m = self->model;
    if (m->unk_14 != NULL) {
        ResSet *p = m->res;
        AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], nm, 0x1000, 0);
    }
}

static inline void Ov013c_Parts(Ov013Act_021fea8c *self) {
    Model0218fe1c *m;
    Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
    m = self->model;
    if (m != NULL) {
        Ov013_PartFlagB2(m, 0);
        Ov013_PartFlagB2(m, 1);
        Ov013_PartFlagB2(m, 3);
        Ov013_PartFlagB2(m, 4);
    }
}

void Ov013Act_021fea8c_State32(Ov013Act_021fea8c *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m48;
        Ov013c_Anim(self, data_ov013_0220aee0, 0x266, 1);
        Ov013c_Parts(self);
        self->fsm->timer = 0;
        self->fsm->st = 0xa;
        m48 = self->hit;
        m48->unk_9a_0 = true;
        m48->unk_9a_3 = 1;
        HitSphere_Link(m48);
    }
    case 0xa: {
        ActorSub40 *q = self->fsm;
        if (q->timer >= self->unk_f8 - 0x3c) {
            q->st = 0x14;
        } else {
            self->unk_f0.b2 = 1;
            Model0218fe1c_GetAnimCtrl(self->model, 0)->speed = 0x800;
            Model0218fe1c_GetAnimCtrl(self->model, 2)->speed = 0x800;
            self->fsm->timer++;
            break;
        }
    }
    case 0x14: {
        VecFx32 a = data_ov013_0220afd0;
        VecFx32 b = data_ov013_0220afdc;
        VecFx32 v;
        EffectObj *o;
        Ov003Vec_RotateY(&v, self->rot_y, &b);
        VEC_Add(&v, &self->pos, &v);
        o = Effect_SpawnId(0x25d, &v);
        o->SetScale(&a);
        o->SetRotXYZ(0, self->rot_y, 0);
        self->fsm->st = 0x15;
    }
    case 0x15: {
        ActorSub40 *q = self->fsm;
        if (q->timer >= self->unk_f8) {
            q->timer = 0;
            self->fsm->st = 0x64;
        } else {
            Model0218fe1c_GetAnimCtrl(self->model, 0)->speed = 0x1000;
            Model0218fe1c_GetAnimCtrl(self->model, 2)->speed = 0x1000;
            self->fsm->timer++;
            break;
        }
    }
    case 0x64:
        Ov013c_Anim(self, data_ov013_0220aee0, 0x266, 1);
        Ov013c_Parts(self);
        Ov003Sequence_SetPaused((u8 *)self + 0x14c, 0);
        break;
    }
}
}
}  // namespace m_02200fe8

// ---- merged from ov013_02202c88.cpp
namespace m_02202c88 {
extern "C" {

extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b218[];
extern BOOL Ov003Sequence_HasEntries(void *p, void *tbl);
extern void Ov003Sequence_SetEntries(void *p, void *tbl, s32 n);
extern void Ov003Sequence_Signal(void *p, s32 a);
extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);

void Ov013Act_021fea8c_State2b(Ov013Act_021fea8c *self) {
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
    if (!Ov003Sequence_HasEntries((u8 *)self + 0x14c, tbl)) {
        Ov003Sequence_SetEntries((u8 *)self + 0x14c, tbl, n);
    }
}

void Ov013Act_021fea8c_State2c(Ov013Act_021fea8c *self) {
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
    if (!Ov003Sequence_HasEntries((u8 *)self + 0x14c, tbl)) {
        Ov003Sequence_SetEntries((u8 *)self + 0x14c, tbl, n);
    }
}

void Ov013Act_021fea8c_State2e(Ov013Act_021fea8c *self) {
    BOOL f = FALSE;
    Ov003Actor *a;
    if (gActorMgr == NULL) {
        a = NULL;
    } else {
        a = ActorMgr_FindKind(gActorMgr, 0x4000, 0x483e);
    }
    if (a != NULL) {
        u8 k;
        if (a->fsm != NULL) {
            k = a->fsm->current;
        } else {
            k = 0;
        }
        if (k == 9) {
            f = TRUE;
        }
    }
    if (!f) {
        Ov003Sequence_Signal((u8 *)self + 0x14c, 0);
    } else {
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
    }
}


extern void *gSndMgr;
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);
extern void Ov003Vec_RotateY(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void Ov013ActEx_02204454_StartMove(Ov013ActEx_02204454 *self, u16 a, u16 b, u16 c, u16 d);
extern void Ov013ActEx_02204454_SetSpeedScale(Ov013ActEx_02204454 *self, s32 a);
extern void Ov013ActEx_02204454_SetD2(Ov013ActEx_02204454 *self, u16 a);
extern u32 Ov013ActEx_02204454_IsDone(Ov013ActEx_02204454 *self);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);

static inline void Ov013_PartFlagB2(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
    }
}

static inline void Ov013_PartFlagB3(Model0218fe1c *m, s32 i, s32 v) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->paused = v;
    }
}

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void func_ov013_02202dc8(Ov013Act_021fea8c *self, u16 a, s32 b, BOOL c, u16 d) {
    self->unk_f0.b4 = 0;
    switch (self->fsm->st) {
    case 0: {
        Actor *o;
        const char *anim;
        Model0218fe1c *m;
        self->target = ActorMgr_FindPlayer()->id;
        o = Ov003_SpawnById(0x483e);
        o->flags_0 = 1;
        self->unk_f2 = o->id;
        anim = data_ov013_0220aee0;
        Model0218fe1c_SetAnim(self->model, anim, 0x266, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], anim, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->fsm->st = 0x1e;
        break;
    }
    case 0x1e: {
        Model0218fe1c *m;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220aef4, 0x1000, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        self->fsm->st = 0x1f;
        break;
    }
    case 0x1f: {
        Ov003Actor *t;
        Ov013ActEx_02204454 *o;
        VecFx32 v;
        Model0218fe1c *m;
        t = Ov013_FindActor(self->target);
        if (t != NULL) {
            Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        }
        if (self->model->anim_state != 1) {
            break;
        }
        o = (Ov013ActEx_02204454 *)Ov013_FindActor(self->unk_f2);
        self->unk_f0.b3 = 0;
        Ov003Vec_RotateY(&v, self->rot_y, data_ov013_0220af40);
        VEC_Add(&v, &self->pos, &v);
        o->pos.x = v.x;
        o->pos.y = v.y;
        o->pos.z = v.z;
        Ov013ActEx_02204454_StartMove(o, self->id, self->target, self->rot_y, a);
        Ov013ActEx_02204454_SetSpeedScale(o, b);
        if (c) {
            Ov013ActEx_02204454_SetD2(o, d);
        }
        Effect_SpawnId(0x57a, &self->pos)->SetScaleAll(0x2800);
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlagB3(m, 0, 1);
            Ov013_PartFlagB3(m, 1, 1);
            Ov013_PartFlagB3(m, 3, 1);
            Ov013_PartFlagB3(m, 4, 1);
        }
        SndMgr_PlayAtPitch(gSndMgr, 0x2b, &self->pos, -5);
        self->fsm->st = 0x28;
        break;
    }
    case 0x28: {
        Ov013ActEx_02204454 *o = (Ov013ActEx_02204454 *)Ov013_FindActor(self->unk_f2);
        Ov003Actor *t = Ov013_FindActor(self->target);
        VecFx32 v;
        if (o == NULL || t == NULL) {
            self->unk_f0.b5 = 1;
            self->fsm->st = 0x3c;
            break;
        }
        if (o->targetObj != NULL && t->id == o->targetObj->target) {
            self->unk_f0.b5 = 0;
            self->fsm->st = 0x3c;
            break;
        }
        if (!Ov013ActEx_02204454_IsDone(o)) {
            break;
        }
        self->unk_f0.b5 = 1;
        v.x = o->pos.x;
        v.y = o->pos.y;
        v.z = o->pos.z;
        if (VEC_Distance(&self->pos, &v) >= 0x3000) {
            break;
        }
        SndMgr_PlayAtPitch(gSndMgr, 0x66, &self->pos, -5);
        self->unk_f0.b3 = 1;
        o->vfunc_08();
        self->fsm->st = 0x3c;
        break;
    }
    case 0x3c: {
        Model0218fe1c *m;
        Ov003Sequence_Signal((u8 *)self + 0x14c, self->unk_f0.b5);
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlagB3(m, 0, 0);
            Ov013_PartFlagB3(m, 1, 0);
            Ov013_PartFlagB3(m, 3, 0);
            Ov013_PartFlagB3(m, 4, 0);
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            break;
        }
        self->unk_f2 = 0xffff;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}

extern s32 AnimCtrl_IsDone(void *p);
extern void Ov013ActEx_022065ac_SetF6(Ov003Actor *o, u16 a);
extern void Ov013ActEx_022065ac_SetF4(Ov003Actor *o, s32 a);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);

struct Ov013Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov013_02203494(Ov013Act_021fea8c *self, BOOL a, BOOL b, u16 c, s32 d) {
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af14, 0x1000, 1);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        self->fsm->st = 10;
        break;
    }
    case 10:
        Actor_TurnToActor(self, Ov013_FindActor(self->target), 0x80);
        if ((u16)(s16)(self->model->anim_state - 1) <= 1) {
            self->fsm->st = 20;
        }
    case 20: {
        u16 rot = self->rot_y;
        BOOL fire = FALSE;
        if (b && self->model->anim_state == 1) {
            rot = self->rot_y + 0x1555;
            fire = TRUE;
        }
        if (a && self->model->anim_state == 2) {
            rot = self->rot_y + 0xeaaa;
            fire = TRUE;
        }
        if (fire) {
            VecFx32 v;
            VecFx32 w;
            Ov003Actor *o;
            Model0218fe1c *m = self->model;
            v.x = m->unk_c6 << 4;
            v.y = m->unk_c8 << 4;
            v.z = m->unk_ca << 4;
            if (self != NULL) {
                Ov003Vec_RotateY(&v, self->rot_y, &v);
            }
            {
                Ov013Rot3 r = {0, 0, 0};
                r.y = rot;
                VEC_Add(&self->pos, &v, &w);
                o = static_cast<Ov003Actor *>(Ov003_SpawnById(0x4807));
                o->pos.x = w.x;
                o->pos.y = w.y;
                o->pos.z = w.z;
                *(Ov013Rot3 *)&o->rot_x = r;
            }
            o->target = self->target;
            o->targetObj->target = self->id;
            o->unk_60 = (void *)d; // the caller passes the word as an s32
            Ov013ActEx_022065ac_SetF6(o, c);
            Ov013ActEx_022065ac_SetF4(o, 1);
            o->flags_0 = 1;
            SndMgr_PlayAt(gSndMgr, 0x54, &self->pos, 0);
        }
        if (AnimCtrl_IsDone(Model0218fe1c_GetAnimCtrl(self->model, 0))) {
            self->fsm->st = 100;
        }
        break;
    }
    case 100: {
        Model0218fe1c *m;
        const char *anim;
        Ov003Sequence_Signal((u8 *)self + 0x14c, 1);
        anim = data_ov013_0220aee0;
        Model0218fe1c_SetAnim(self->model, anim, 0x266, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], anim, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
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

extern const VecFx32 data_ov013_0220afe8;
extern void *gSndMgr;
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern void Ov003Vec_RotateY(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL Ov003Vec_Equal(VecFx32 *a, VecFx32 *b);
extern void Ov003Vec_ApproachWithin(VecFx32 *out, const VecFx32 *a, const VecFx32 *b, s32 dist, s32 yoff);
extern void Ov003StateMachine_ChangeState(void *p, s32 a);
extern void Ov003StateMachine_Leave(void *p);
extern u16 Ov003Vec_Yaw(VecFx32 *v);

static inline void Ov013_PartFlagB2(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
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

static inline VecFx32 Ov013_Around(const VecFx32 *base, u16 r) {
    VecFx32 v;
    VecFx32 t = data_ov013_0220afe8;
    Ov003Vec_RotateY(&v, r, &t);
    VEC_Add(&v, base, &v);
    return v;
}

static inline void Ov013_VecSubYZ(VecFx32 *o, const VecFx32 *a, const VecFx32 *b) {
    s32 y = a->y;
    s32 z = a->z;
    o->x = a->x - b->x;
    o->y = y - b->y;
    o->z = z - b->z;
}

BOOL func_ov013_022038a8(Ov013Act_021fea8c *self, const VecFx32 *pos, u16 rot) {
    BOOL ret = FALSE;
    BOOL move = TRUE;
    BOOL turn = TRUE;
    s32 rate = 0x400;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        move = FALSE;
        turn = FALSE;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af04, 0x266, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->rot_x = 0;
        self->rot_z = 0;
        self->fsm->st = 10;
        SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        break;
    }
    case 10:
    case 11: {
        rate = 0x80;
        if (self->fsm->st == 10) {
            VecFx32 c = Ov013_Around(&self->unk_108, self->unk_fa);
            Ov013_VecCopy(&self->unk_b8, &c);
            self->fsm->st = 11;
        }
        self->speed += 0x40;
        self->speed = Ov013_Clamp(self->speed, 0, 0x2000);
        {
            VecFx32 w;
            Ov013_VecCopy(&w, &self->unk_b8);
            if (Ov003Vec_Equal(&w, &self->pos)) {
                Ov003StateMachine_Leave((u8 *)self + 0x12c);
                self->fsm->st = 20;
            }
        }
        break;
    }
    case 20:
    case 21: {
        rate = 0x300;
        if (self->fsm->st == 20) {
            VecFx32 c = Ov013_Around(pos, rot);
            Ov013_VecCopy(&self->unk_b8, &c);
            self->unk_f0.b3 = 1;
            self->fsm->st = 21;
        }
        {
            VecFx32 w;
            Ov013_VecCopy(&w, &self->unk_b8);
            if (VEC_Distance(&w, &self->pos) < 0x6000) {
                self->speed = Ov013_FxMul64(self->speed, 0xe00);
            } else {
                self->speed += 0x100;
                self->speed = Ov013_Clamp(self->speed, 0, 0x4000);
            }
            if (Ov003Vec_Equal(&w, &self->pos) || self->speed < 0x10) {
                self->fsm->st = 30;
            }
        }
        break;
    }
    case 30:
    case 31: {
        VecFx32 w;
        rate = 0x180;
        if (self->fsm->st == 30) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            Ov003StateMachine_ChangeState((u8 *)self + 0x12c, 0);
            Ov013_VecCopy(&self->unk_b8, pos);
            self->fsm->st = 31;
        }
        Ov013_VecCopy(&w, &self->unk_b8);
        if (VEC_Distance(&w, &self->pos) < 0x7000) {
            self->speed = Ov013_FxMul64(self->speed, 0xf00);
            turn = FALSE;
        } else {
            self->speed += 0xa0;
            self->speed = Ov013_Clamp(self->speed, 0, 0xa00);
        }
        if (Ov003Vec_Equal(&w, &self->pos) || self->speed < 8) {
            self->fsm->st = 40;
            turn = FALSE;
            SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        }
        break;
    }
    case 40:
        move = FALSE;
        turn = FALSE;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        ret = TRUE;
        break;
    }
    if (move) {
        VecFx32 w;
        Ov013_VecCopy(&w, &self->unk_b8);
        Ov003Vec_ApproachWithin(&self->pos, &w, &self->pos, self->speed, 0);
    }
    if (turn) {
        VecFx32 d;
        Ov013_VecSubYZ(&d, &self->unk_b8, &self->pos);
        self->rot_y = Angle_Approach(Ov003Vec_Yaw(&d), self->rot_y, rate, 1, 0x8000);
    }
    return ret;
}

}
}  // namespace m_022038a8

// ---- merged from ov013_02203ea4.cpp
namespace m_02203ea4 {
extern "C" {

extern void *gSndMgr;
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL Ov003Vec_Equal(VecFx32 *a, VecFx32 *b);
extern void Ov003Vec_ApproachWithin(VecFx32 *out, const VecFx32 *a, const VecFx32 *b, s32 dist, s32 yoff);
extern void Ov003StateMachine_ChangeState(void *p, s32 a);

static inline void Ov013_PartFlagB2(Model0218fe1c *m, s32 i) {
    if (Model0218fe1c_GetAnimCtrl(m, i) != NULL) {
        Model0218fe1c_GetAnimCtrl(m, i)->loop = 1;
    }
}

static inline s32 Ov013_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

BOOL func_ov013_02203ea4(Ov013Act_021fea8c *self, const VecFx32 *dst) {
    BOOL ret = FALSE;
    BOOL move = FALSE;
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *m;
        EffectObj *o;
        VecFx32 v;
        Ov013_VecCopy(&v, dst);
        Ov013_VecCopy(&self->unk_b8, &v);
        self->pos.x = v.x;
        self->pos.z = v.z;
        self->pos.y = v.y - 0xf000;
        move = TRUE;
        self->rot_x = 0xbfff;
        o = Effect_SpawnId(0x2bd, (VecFx32 *)dst);
        o->SetScaleAll(0x3000);
        o->loopCount = -1;
        self->unk_100 = o->id;
        self->speed = 0x900;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        Ov003StateMachine_ChangeState((u8 *)self + 0x12c, 0);
        Model0218fe1c_SetAnim(self->model, data_ov013_0220af04, 0x266, 0);
        m = self->model;
        if (m->unk_14 != NULL) {
            ResSet *p = m->res;
            AnimCtrl_SetAnim(m->unk_14, m->renderObj, p, p->anims->list[2], data_ov013_0220aee0, 0x1000, 0);
        }
        Model0218fe1c_GetAnimCtrl(self->model, 2)->loop = 1;
        m = self->model;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->fsm->st = 10;
        SndMgr_PlayAtPitch(gSndMgr, 0x3e, &self->pos, 5);
        break;
    }
    case 10:
        self->fsm->timer++;
        if (self->fsm->timer > 0x4b) {
            self->fsm->timer = 0;
            self->fsm->st = 20;
        }
        break;
    case 20: {
        Ov003Actor *a = ActorMgr_FindPlayer();
        u16 r;
        if (a == NULL || a == self) {
            r = self->rot_y;
        } else {
            r = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        self->rot_y = r;
        self->fsm->st = 21;
        break;
    }
    case 21: {
        VecFx32 w;
        Ov013_VecCopy(&w, &self->unk_b8);
        move = TRUE;
        if (Ov003Vec_Equal(&w, &self->pos) || self->speed < 0x40) {
            self->fsm->st = 100;
        } else if (VEC_Distance(&w, &self->pos) < 0x5000) {
            self->speed = Ov013_FxMul64(self->speed, 0xf00);
        }
        break;
    }
    case 100:
        EffectMgr_Kill(gEffectMgr, self->unk_100);
        self->unk_100 = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        ret = TRUE;
        break;
    }
    if (move) {
        VecFx32 w;
        Ov013_VecCopy(&w, &self->unk_b8);
        Ov003Vec_ApproachWithin(&self->pos, &w, &self->pos, self->speed, self->velY);
        Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
    }
    return ret;
}
}
}  // namespace m_02203ea4

// ---- merged from ov013_022043f8.cpp
namespace m_022043f8 {


extern "C" {

extern void *Ov013ActEx_02204454_vtbl[];
extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
extern void Ov003Vec_RotateY(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void *ResSet_ReleaseAll(void *p);
extern void *Model0218fe1c_FreeAnims(void *p);
extern void *ResSet_Init(void *p);
extern BOOL ResSet_UpdateLoad(void *p);

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline void Ov013_RotY(VecFx32 *out, const VecFx32 *v, Ov003Actor *a) {
    if (a != NULL) {
        Ov003Vec_RotateY(out, a->rot_y, v);
    }
}


void Ov013Cam_Follow(Ov013Cam *self) {
    Ov003Actor *t;
    Robo021ca458 *pl;
    VecFx32 p;
    VecFx32 o;
    if (!self->b0) {
        return;
    }
    t = Ov013_FindActor(self->id);
    pl = ActorMgr_FindPlayer();
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
    pl->unk_b90 = p;
    pl->unk_b9c = 0x700;
}

void Ov013Cam_SetOffsetY(Ov013Cam *self, u32 *p) {
    if (p != NULL) {
        self->off.y = *p;
    }
}

void Ov013_RotateByActorYaw(VecFx32 *out, const VecFx32 *v, Ov003Actor *a) {
    if (a != NULL) {
        Ov003Vec_RotateY(out, a->rot_y, v);
    }
}

void Ov013_CopyVec(VecFx32 *dst, const VecFx32 *src, Ov003Actor *owner) {
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
