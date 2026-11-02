#ifndef OV010_H
#define OV010_H

#include "types.h"
#include "nitro/fx.h"
#include "ov000/VObj.h"

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

// Generic bitfield views
struct Ov010Flags {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 1;
    u16 b15 : 1;
};

struct Ov010Flags32 {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 28;
};

struct Ov010Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

// ov010 objects are ov000 actors (ov000/ActorBase.h: Actor, 0xac bytes, ctor Actor_Ctor).
#include "ov000/ActorBase.h"
#include "ov000/ObjLayouts.h"
#include "ov003/Actor.h"
#include "Main/Effect/Effect.h"

// The beam effect of ov010_0220f828.cpp (round svG). An Ov010BeamSet (0x40, func_ov010_02200dcc)
// keeps a list of three Ov010BeamNode (0x8c); each node holds an Ov010Beam (0x80, drawn by
// func_ov010_02200a00 and stepped by func_ov010_0220078c), which holds its hit effect
// Ov010FxObj (0x44, func_ov010_02200048 / func_ov010_022000d8). The st members are the ov000
// state blocks (History_Init / func_ov000_02198360).
struct Ov010FxObj {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0a;
    u16 timer;
    u16 rx;
    u16 ry;
    u16 targetId; // id of the actor the effect follows
    s32 fx0; // effect handles
    s32 fx1;
    s32 fx2;
    s32 unk_20;
    VecFx32 pos;
    ActorSub40 st;
};
SIZE_ASSERT(Ov010FxObj, 0x44);

struct Ov010Beam {
    u8 on;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s16 unk_0c;
    s16 len;
    u16 rx;
    u16 ry;
    s32 alpha;
    s32 mode;
    VecFx32 pos;
    Ov010FxObj fx;
    ActorSub40 st;
};
SIZE_ASSERT(Ov010Beam, 0x80);

struct Ov010BeamNode {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    struct Ov010BeamNode *next;
    Ov010Beam beam;
};
SIZE_ASSERT(Ov010BeamNode, 0x8c);

struct Ov010BeamSet {
    Ov010Flags8 flags;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u8 unk_0e[0x2];
    Ov010BeamNode *beams;
    VecFx32 unk_14;
    VecFx32 unk_20;
    ActorSub40 st;
};
SIZE_ASSERT(Ov010BeamSet, 0x40);

// 12-byte block: assigning one copies with ldm/stm (a plain Vec copies word by word)
struct Ov010Blk12 {
    s32 w[3];
};
#define OV010_BLKCPY(dst, src) (*(Ov010Blk12 *)(dst) = *(const Ov010Blk12 *)(src))

static inline void Ov010_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov010_VecCopy(VecFx32 *d, const VecFx32 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov010_VecCopyYZ(VecFx32 *d, const VecFx32 *s) {
    s32 y = s->y;
    s32 z = s->z;
    d->x = s->x;
    d->y = y;
    d->z = z;
}

static inline s32 Ov010_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

// NitroSDK sin/cos table: s16 sin,cos pairs
extern "C" const s16 FX_SinCosTable_[];
#define OV010_SINCOS FX_SinCosTable_
#define OV010_SIN(a) (OV010_SINCOS[((a) >> 4) * 2])
#define OV010_COS(a) (OV010_SINCOS[((a) >> 4) * 2 + 1])

extern "C" {
void Heap_Free(void *p);
void *Heap_Alloc(u32 size);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void func_ov003_021d9900(VecFx32 *a, u16 b, const VecFx32 *c);
void func_ov003_021d9980(VecFx32 *a, u16 b, const VecFx32 *c);

// ov003 helpers that ov010 calls (state blocks, fx lists, pools, vector math), declared once here.
// The ov003 sources define them on their own local types, so these take void * where ov010 has no
// shared type for the argument. The actor API is in ov003/Actor.h.
void func_ov003_021cedf4(u16 a);
void func_ov003_021cf340(const char *p);
void func_ov003_021cf39c(s32 a, const char *b);
void func_ov003_021cf3fc(s32 a);
void func_ov003_021cf400(s32 a);
void func_ov003_021cf404(s32 a);
int func_ov003_021cf408(void);
void func_ov003_021cf418(void *p);
void func_ov003_021cf4ac(void *p);
void func_ov003_021cf4ec(void *p);
void *func_ov003_021cf52c(void *g, void *obj, u16 a, u16 b);
void func_ov003_021d7848(void *p);
BOOL func_ov003_021d7894(void *p, s32 a, s32 b);
void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov003_021d883c(void *a, VecFx32 *b, VecFx32 *c, s32 d);
void func_ov003_021d8a30(void *p, u8 id, void *st);
void func_ov003_021d8a7c(void *p, s32 a);
BOOL func_ov003_021d8c10(void *p);
void func_ov003_021d8eac(void *a, void *b, s32 c, s32 d);
void func_ov003_021d8f24(void *p);
void func_ov003_021d8f34(void *p);
BOOL func_ov003_021d8f4c(void *p);
void func_ov003_021d8fa8(void *p);
void func_ov003_021d8fc0(void *p);
void func_ov003_021d95e8(void *p, void *tbl, u16 n);
void func_ov003_021d969c(void *p, s32 a);
void func_ov003_021d9740(void *p, s32 a);
void func_ov003_021d97fc(void *p, s32 a);
void func_ov003_021d982c(void *p, u8 v);
BOOL func_ov003_021d9878(void *p);
BOOL func_ov003_021d98a0(void *p);
void func_ov003_021d9a00(VecFx32 *out, s32 angle, const VecFx32 *in);
void func_ov003_021d9aec(VecFx32 *out, const VecFx32 *in, s32 max);
void func_ov003_021d9b8c(VecFx32 *out, const VecFx32 *in, s32 max, s32 sub);
void func_ov003_021d9d28(VecFx32 *out, VecFx32 *pos, u16 ang, void *c);
void func_ov003_021d9dbc(VecFx32 *out, const VecFx32 *a, const VecFx32 *b, s32 dist, s32 yoff);
void func_ov003_021d9f80(void *rot, const VecFx32 *a, const VecFx32 *b);
VecFx32 func_ov003_021da214(void *actor);
void func_ov003_021da40c(ActorSub40 *p);
void func_ov003_021da48c(void *p, s32 a);
EffectObj *func_ov003_021da788(s32 id, void *self, const VecFx32 *ofs);
EffectObj *func_ov003_021da7e8(s32 id, void *src, const VecFx32 *ofs);
EffectObj *func_ov003_021da8e4(s32 fxId, const VecFx32 *pos, s32 scale);
void func_ov003_021da904(EffectObj *e, void *src, const VecFx32 *off);
void func_ov003_021f0c60(void *self, s32 a);
extern const VecFx32 data_ov010_0220ec20;

// Effect 0x192 at the actor's centre, turned by (a, b) / along a -> b (ov010_0220ea84.cpp).
EffectObj *func_ov010_0220ea84(Actor *self, u16 a, u16 b);
EffectObj *func_ov010_0220eaf0(Actor *self, const VecFx32 *a, const VecFx32 *b);

// Effect onUpdate callback: counts unk_04 down, then kills the effect.
void func_ov010_02209074(EffectObj *p);
}

// Offset of the actor's attach point (func_ov010_021fa7e0)
static inline VecFx32 Ov010_AttachOffset(Actor *obj) {
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
    return v;
}

// A u16 rotation (x, y, z), as copied into Actor::rot_x..rot_z.
struct Ov010Ang3 {
    u16 x;
    u16 y;
    u16 z;
};

// ---- Sub-objects that ov010 classes embed. ov003 defines these on its own local types, so ov010
// keeps these views; the ov003 helpers that take them are declared above with void *.

// Ov003Mover (vtable data_ov003_021f7d2c, ctor Ov003Vt_021f7d2c_Ctor): moves a point from start
// toward target (Ov003Mover_Start); vfunc_08 stops it, vfunc_10 returns the point, vfunc_14 says
// whether it arrived.
class Ov010Mover : public VObj {
public:
    u8 active : 1;
    u8 noSnap : 1;
    u8 done : 1;
    s32 speed;
    s32 dist;
    s32 maxDist;
    VecFx32 pos;
    VecFx32 target;
    VecFx32 dir;
};
SIZE_ASSERT(Ov010Mover, 0x38);

// A marker effect (0x28, func_ov010_0220e38c): effect handle, position and a state block.
struct Ov010Trail {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad_01;
    u16 life;
    s32 key; // effect handle (EffectMgr_Kill)
    VecFx32 pos;
    ActorSub40 st;
};
SIZE_ASSERT(Ov010Trail, 0x28);

// An effect that follows an actor and then sends it a message (0x6c, func_ov010_0220e740 /
// func_ov010_0220e7c8).
struct Ov010Path {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 timer;
    u16 duration;
    u16 unk_06;
    s32 fxHandle; // EffectMgr_StopLoop
    s32 fxId;     // effect id (func_ov003_021da8e4)
    s32 unk_10;
    s32 scale;    // VObj::vfunc_0c of the effect
    Actor *owner; // the effect follows its position; the message goes to its id
    VecFx32 offset;
    u8 msg[0x30]; // ActorMgr_SendMsg payload
    ActorSub40 sm;
};
SIZE_ASSERT(Ov010Path, 0x6c);

extern "C" {
BOOL func_ov010_0220e740(Ov010Path *self, Actor *owner, const void *msg, s32 size, const VecFx32 *offset, s32 fxId);
void func_ov010_0220e7c8(Ov010Path *self);
void func_ov010_0220e38c(Ov010Trail *self);
}

// A list of spawned 0x4817 actors (Obj0220a6b0) with a handler object (0x3c, ctor
// func_ov010_0220d79c). pool is an Ov003Pool of list nodes.
struct Ov010CollNode {
    u16 id;
    u16 unk_02;
    Ov010CollNode *next;
};

struct Ov010Coll {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010CollNode *list;
    VObj *handler;
    u8 pool[0x10];
};
SIZE_ASSERT(Ov010Coll, 0x3c);

extern "C" {
Ov010Coll *func_ov010_0220d79c(Ov010Coll *self);
Ov010Coll *Ov010Coll_Dtor(Ov010Coll *self);
BOOL Ov010Coll_Init(Ov010Coll *self);
void Ov010Coll_Release(Ov010Coll *self);
void func_ov010_0220d858(Ov010Coll *self);
s32 Ov010Coll_GetCount(Ov010Coll *self);
void Ov010Coll_SetHandler(Ov010Coll *self, VObj *h);
void Ov010Coll_ClearHandler(Ov010Coll *self);
BOOL Ov010Coll_IsFree(Ov010Coll *self);
}

// An area circle (func_ov010_022090b4 type 1): the centre and the radius.
typedef struct Ov010Circle {
    VecFx32 centre;
    fx32 radius;
} Ov010Circle;

// ---- The 0x4817 actor (vtable data_ov010_02210378, ctor Ov010ActVt_02210378_Ctor).
// Spawned by func_ov010_0220da74 and set up by func_ov010_0220a948. Its methods are in
// ov010_0220f9b4.cpp (0220a6a0..0220d3d8). It is built by ActorEx_Ctor, but reads 0xcf as an
// unsigned byte, where ActorEx::unk_cf is signed (a counter in ov013), so it derives from Actor and
// declares 0xac.. itself.
class Obj0220a6b0 : public Actor {
public:
    u8 unk_ac[0x20];
    Ov010Flags unk_cc;
    Ov010Flags8 unk_ce; // b0/b1: run fsmA/fsmB through their state tables (Update)
    u8 unk_cf;
    u16 unk_d0;
    u16 unk_d2;
    u16 unk_d4;
    u16 unk_d6;
    s32 unk_d8;
    s32 unk_dc;      // area kind: 0 rectangle (unk_e0), 1 circle (unk_e4) (func_ov010_022090b4)
    s32 *unk_e0;     // {x0, z0, x1, z1, y}
    Ov010Circle *unk_e4;
    Ov010Trail *trail;
    Ov010Path *path;
    VecFx32 unk_f0;
    VecFx32 unk_fc;
    VecFx32 unk_108;
    VecFx32 unk_114;
    Ov010Mover mover;
    ActorSub40 fsmA;
    ActorSub40 fsmB;
    u16 unk_180;
    u16 unk_182;
    VecFx32 unk_184;
    Ov010Ang3 unk_190;
    Ov010Ang3 unk_196;
};
SIZE_ASSERT(Obj0220a6b0, 0x19c);

extern "C" {
// Coll filters: func_ov010_0220d918 keeps the ids of the listed actors fn accepts.
BOOL func_ov010_0220d77c(Obj0220a6b0 *p);
void func_ov010_0220d918(Ov010Coll *self, BOOL (*fn)(Obj0220a6b0 *obj));
}

// ---- More ov003 sub-objects (views; see above).

// Ov003Sequence (func_ov003_021d8f24 / 021d8f34, Ov003Sequence_HasEntries, func_ov003_021d95e8): plays
// a list of steps; func_ov003_021d9644 returns the current step's two bytes.
struct Ov010Seq {
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 pairA;
    u8 pairB;
    u16 unk_04;
    u16 index;
    u16 length;
    void *entries;
};
SIZE_ASSERT(Ov010Seq, 0x10);

// The two bytes of a sequence step (func_ov003_021d9644).
struct Ov010B2 {
    u8 a;
    u8 b;
};

extern "C" Ov010B2 func_ov003_021d9644(void *p);

// Ov003TickerSet (vtable data_ov003_021f7d10, Ov003TickerSet_Init).
class Ov010TickerSet : public VObj {
public:
    u8 unk_04[0x28];
};
SIZE_ASSERT(Ov010TickerSet, 0x2c);

// Ov003Timer (vtable data_ov003_021f7cd8, func_ov003_021d8c10 / 021d8eac, Ov003Timer_IsStopped).
class Ov010Timer : public VObj {
public:
    u8 active : 1;
    u8 running : 1;
    u8 loop : 1;
    s16 duration;
    void *target;
    u8 unk_0c[0x14];
};
SIZE_ASSERT(Ov010Timer, 0x20);

// A camera preset (vtable data_ov010_0220ffc4, 0x20): position, angles and distance.
class Ov010CamPreset : public VObj {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    s32 x;
    s32 y;
    s32 z;
    u16 a;
    u16 b;
    u16 c;
    s32 w;
};
SIZE_ASSERT(Ov010CamPreset, 0x20);

// The arena a 02210154 actor moves in (0x14 records data_ov010_0220f160 / 0220f174): the actor
// circles its centre at the radius (polar vectors of that length around it).
struct Ov010Arena {
    VecFx32 center;
    s32 unk_0c;
    s32 radius;
};

// ---- The 02210154 actors (ctor Ov010ActVt_02210154_Ctor, ov010_02204204.cpp; methods in
// ov010_0220f958.cpp and ov010_02207520.cpp). Two subclasses: vtables data_ov010_0220ffe4 and
// data_ov010_0221009c.
class Ov010Obj02210154 : public Ov003Actor {
public:
    u8 unk_f0; // set once the sound bank load was requested (func_ov010_02204344)
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u16 unk_f4; // hp does not drop below this (func_ov010_0220441c)
    u8 unk_f6[0x2];
    Ov010Arena *arena;
    const s32 *unk_fc;      // area rectangle {x0, z0, x1, z1, y}, for the Ov010Trig handlers
    const Ov010Circle *unk_100; // area circle
    VObj *unk_104; // handlers that run on coll (Ov010Coll_SetHandler)
    VObj *unk_108;
    VObj *unk_10c;
    VObj *unk_110;
    VObj *unk_114;
    VObj *unk_118; // Ov003StateMachine (ctor Ov003Vt_021f7cf4_Ctor)
    Ov010CamPreset *unk_11c;
    Ov010CamPreset *unk_120;
    s16 *unk_124; // knockback: angle, speed, decay (0x0220441c / 02204b74)
    s32 sndBank;  // loaded through func_02049678; SndMgr_IsLoadDone waits for it
    s32 sfx[9];   // sound ids played with func_02049f44 (filled by vfunc_ac)
    VecFx32 moveDir;
    s32 unk_15c;
    Ov010Seq seq;
    Ov010B2 step; // the current step of seq (func_ov003_021d9644)
    u8 unk_172[0x2];
    Ov010Coll coll;
    Ov010TickerSet ticker;
    Ov010Timer timer;
};
SIZE_ASSERT(Ov010Obj02210154, 0x1fc);

class Ov010Obj0220ffe4 : public Ov010Obj02210154 {
public:
    u8 unk_1fc;
    u8 unk_1fd[0x3];
    s32 unk_200;
};

class Ov010Obj0221009c : public Ov010Obj02210154 {
};

extern "C" {
void Ov010ActVt_02210154_Start(Ov010Obj02210154 *self);
BOOL func_ov010_0220441c(Ov010Obj02210154 *self, ActorMsg *msg);
void func_ov010_02207828(Ov010Obj02210154 *self);
BOOL func_ov010_0220794c(Actor *self);
}

// ---- The Obj021fa860 actor (vtable data_ov010_0220fccc, ctor Ov010ActVt_0220fccc_Ctor; all its
// methods are in ov010_0220f5dc.cpp, which defines the types it points to).

struct Ov010MovePath;
struct Ov010Shake;
struct Ov010Wobble;

// A list of timed tasks (vtable data_ov010_0220fe1c, 0x20; Ov010TaskList_Init,
// ov010_02201914.cpp .. ov010_02201c34.cpp). pool is an Ov003Pool of nodes.
struct Ov010TaskNode {
    VObj *obj;
    u32 time;
    Ov010TaskNode *next;
};

struct Ov010TaskList {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u32 time;
    Ov010TaskNode *head;
    u8 pool[0x10];
};
SIZE_ASSERT(Ov010TaskList, 0x20);

// A timed shot task (0x24, Ov010Vt_0220fe08_New / Ov010Vt_0220fdf4_New; queued on an
// Ov010TaskList with func_ov010_02201ad4): at its time it spawns a 0x4829 shot (Obj022020c8)
// from actor id, offset by v18 and moving along v0c (func_ov010_02201cc8 / 02201f44).
struct Ov010Task {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06; // the shot's target id
    u16 id;
    u8 unk_0a[2];
    VecFx32 v0c;
    VecFx32 v18;
};
SIZE_ASSERT(Ov010Task, 0x24);

// An effect that follows an actor and fades (func_ov010_021ffa6c): getPos returns the point on the
// actor (func_ov010_021fa7e0), key is the effect handle (EffectMgr_Kill).
struct Ov010Fade {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 id;
    u16 timer;
    u16 unk_06;
    s32 state;
    s32 fxId; // effect id (func_02065f88)
    s32 key;
    void (*getPos)(VecFx32 *out, Actor *obj);
};
SIZE_ASSERT(Ov010Fade, 0x18);

// Ov003FlagObj (vtable data_ov003_021f79a8, func_ov003_021cf330).
class Ov010FlagObj : public VObj {
public:
    u8 active : 1;
    u8 unk_05[0xb];
};
SIZE_ASSERT(Ov010FlagObj, 0x10);

// Ov003StateMachine (vtable data_ov003_021f7cf4, Ov003StateMachine_Init / _SendMessage / _Leave).
class Ov010StateMachine : public VObj {
public:
    u8 active;
    void *cur;
    void *list;
};
SIZE_ASSERT(Ov010StateMachine, 0x10);

// Ov003Group (func_ov003_021cf418, Ov003Group_Init, func_ov003_021cf52c adds objects to it).
struct Ov010Group {
    u8 active : 1;
    u16 unk_02;
    void *list4;
    void *list8;
};
SIZE_ASSERT(Ov010Group, 0xc);

// ---- The 0x4829 shot (vtable data_ov010_0220fe6c, ctor Ov010ActVt_0220fe6c_Ctor; methods in
// ov010_0220f8e4.cpp, spawned by the Ov010Task tasks of ov010_0220f870.cpp).

// The two looping effects that follow an actor (0x20, allocated by the shot's Start, stepped by
// func_ov010_02203bf8, freed by the dtor): keyA (effect 0x324) is scaled from cur toward tgt,
// keyB (0x25d, or 0x25e with b3) is created at scale and turned with the actor; both sit at off,
// rotated by the actor's angles.
struct Ov010Glow {
    u8 b0 : 1;
    u8 b1 : 1; // keyA on
    u8 b2 : 1; // keyB on
    u8 b3 : 1;
    u8 rest : 4;
    u8 pad_01;
    u16 id; // the actor followed
    s16 cur;
    s16 tgt;
    s16 scale;
    u16 pad_0a;
    s32 keyA; // effect handles
    s32 keyB;
    VecFx32 off;
};
SIZE_ASSERT(Ov010Glow, 0x20);

extern "C" void func_ov010_02203bf8(Ov010Glow *self);

// ActorEx::unk_ce_0: launched (func_ov010_022024c4 / 02202560), unk_ce_1: hit or done.
struct Obj022020c8 : public ActorEx {
    u16 unk_d0;
    s32 unk_d4;
    Ov010Glow *unk_d8;
    BOOL (*unk_dc)(u16 id, const VecFx32 *a, const VecFx32 *b); // checked against the target in flight (func_ov010_02202600)
    VecFx32 unk_e0;
    VecFx32 unk_ec;
    VecFx32 unk_f8;
    Ov010FlagObj flagObj;
};

class Obj021fa860 : public Ov003Actor {
public:
    Ov010Flags8 unk_f0;
    u8 unk_f1;
    s16 unk_f2;
    s32 unk_f4;
    u16 *unk_f8;
    Ov010MovePath *unk_fc;
    Ov010BeamSet *beams; // func_ov010_02200d94 / 02200dcc
    Ov010Shake *unk_104;
    Ov010Wobble *unk_108;
    Ov010Timer *unk_10c;
    VObj *unk_110; // states of sm (func_ov003_021d8a30 ids 1..3)
    VObj *unk_114;
    VObj *unk_118;
    s32 seqHandle; // music (func_02049afc, SndMgr_StopSeqArc)
    VecFx32 unk_120;
    VecFx32 unk_12c;
    Ov010Fade fade;
    Ov010TickerSet ticker;
    Ov010TaskList tasks;
    Ov010FlagObj flagObj;
    Ov010Seq seq;
    Ov010B2 step; // the current step of seq (func_ov003_021d9644)
    u8 unk_1be[0x2];
    Ov010StateMachine sm;
    Ov010Group group;
};

// ov000 / ov003 actor functions, typed (round acD; the same set as ov014.h).
extern "C" {
ActorEx *ActorEx_Ctor(ActorEx *self);
ActorEx *func_ov000_0219429c(ActorEx *self);
void func_ov000_02194758(ActorEx *self);
BOOL func_ov000_02194c08(ActorEx *self);
BOOL func_ov000_021950e8(ActorEx *self, ActorMsg *msg);
void func_ov000_021953b4(ActorEx *self);
void func_ov000_02195d88(ActorEx *self);
void func_ov000_02196060(ActorEx *self);
void func_ov000_02196c40(ActorEx *self);
void func_ov000_02197dec(ActorEx *self, u8 a, s16 b);
BOOL func_ov000_0218cea4(Actor *self);
BOOL func_ov000_0218cf5c(Actor *self);
void func_ov000_0218d7e8(Actor *self, u8 a);
void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
void Actor_TurnToPos(Actor *self, const VecFx32 *target, s32 step);
void Actor_Move(Actor *self, s32 turn);
BOOL func_ov003_021d1c00(Ov003Actor *self, ActorMsg *msg);
}

#endif
