#ifndef OV011_H
#define OV011_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Field.h"
#include "Main/Res/StageCmd.h"
#include "ov000/Actor.h"
#include "ov003/Actor.h"
#include "ov000/TwlRequest.h"
#include "Main/Effect/Effect.h"
#include "ov000/ObjLayouts.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov011V {
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
    virtual s32 v24(...);
    virtual s32 v28(...);
    virtual s32 v2c(...);
    virtual s32 v30(...);
    virtual s32 v34(...);
    virtual s32 v38(...);
    virtual s32 v3c(...);
    virtual s32 v40(...);
    virtual s32 v44(...);
    virtual s32 v48(...);
    virtual s32 v4c(...);
    virtual s32 v50(...);
    virtual s32 v54(...);
    virtual s32 v58(...);
    virtual s32 v5c(...);
    virtual s32 v60(...);
    virtual s32 v64(...);
    virtual s32 v68(...);
    virtual s32 v6c(...);
    virtual s32 v70(...);
    virtual s32 v74(...);
    virtual s32 v78(...);
    virtual s32 v7c(...);
    virtual s32 v80(...);
    virtual s32 v84(...);
    virtual s32 v88(...);
    virtual s32 v8c(...);
    virtual s32 v90(...);
    virtual s32 v94(...);
    virtual s32 v98(...);
    virtual s32 v9c(...);
    virtual s32 va0(...);
    virtual s32 va4(...);
    virtual s32 va8(...);
    virtual s32 vac(...);
    virtual s32 vb0(...);
    virtual s32 vb4(...);
    virtual s32 vb8(...);
    virtual s32 vbc(...);
    virtual s32 vc0(...);
    virtual s32 vc4(...);
    virtual s32 vc8(...);
    virtual s32 vcc(...);
    virtual s32 vd0(...);
    virtual s32 vd4(...);
    virtual s32 vd8(...);
    virtual s32 vdc(...);
    virtual s32 ve0(...);
    virtual s32 ve4(...);
    virtual s32 ve8(...);
    virtual s32 vec(...);
    virtual s32 vf0(...);
    virtual s32 vf4(...);
    virtual s32 vf8(...);
    virtual s32 vfc(...);
    virtual s32 v100(...);
    virtual s32 v104(...);
    virtual s32 v108(...);
    virtual s32 v10c(...);
    virtual s32 v110(...);
    virtual s32 v114(...);
    virtual s32 v118(...);
    virtual s32 v11c(...);
    virtual s32 v120(...);
    virtual s32 v124(...);
    virtual s32 v128(...);
    virtual s32 v12c(...);
    virtual s32 v130(...);
    virtual s32 v134(...);
    virtual s32 v138(...);
    virtual s32 v13c(...);
    virtual s32 v140(...);
    virtual s32 v144(...);
    virtual s32 v148(...);
    virtual s32 v14c(...);
    virtual s32 v150(...);
    virtual s32 v154(...);
    virtual s32 v158(...);
    virtual s32 v15c(...);
    virtual s32 v160(...);
    virtual s32 v164(...);
    virtual s32 v168(...);
    virtual s32 v16c(...);
    virtual s32 v170(...);
    virtual s32 v174(...);
    virtual s32 v178(...);
    virtual s32 v17c(...);
    virtual s32 v180(...);
    virtual s32 v184(...);
    virtual s32 v188(...);
    virtual s32 v18c(...);
    virtual s32 v190(...);
    virtual s32 v194(...);
    virtual s32 v198(...);
    virtual s32 v19c(...);
    virtual s32 v1a0(...);
    virtual s32 v1a4(...);
    virtual s32 v1a8(...);
    virtual s32 v1ac(...);
    virtual s32 v1b0(...);
    virtual s32 v1b4(...);
    virtual s32 v1b8(...);
    virtual s32 v1bc(...);
    virtual s32 v1c0(...);
    virtual s32 v1c4(...);
    virtual s32 v1c8(...);
    virtual s32 v1cc(...);
    virtual s32 v1d0(...);
    virtual s32 v1d4(...);
    virtual s32 v1d8(...);
    virtual s32 v1dc(...);
    virtual s32 v1e0(...);
    virtual s32 v1e4(...);
    virtual s32 v1e8(...);
    virtual s32 v1ec(...);
    virtual s32 v1f0(...);
    virtual s32 v1f4(...);
    virtual s32 v1f8(...);
    virtual s32 v1fc(...);
};

// Compile-time size check: fails with a negative array size when sizeof(T) != n.
#define OV011_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]

// Generic bitfield views
struct Ov011Flags {
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

struct Ov011Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

static inline void Ov011_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// 12-byte block: assigning one copies with ldm/stm
struct Ov011Blk12 {
    s32 w[3];
};
#define OV011_BLKCPY(dst, src) (*(Ov011Blk12 *)(dst) = *(const Ov011Blk12 *)(src))

#define OV011_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV011_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

extern "C" {
void Heap_FreeArray(void *p);
void *Heap_AllocArray(u32 size);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void Ov003ActorSub40_ApplyFlags(void *p);
void Ov003ActorSub40_ForceState(void *p, u8 a);
}

static inline BOOL Ov011Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov011Game_IsIdle(FieldState *g) {
    if (Ov011Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov011_GameIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov011Game_IsIdle(g);
    }
    return TRUE;
}

struct Ov011Node {
    u16 id;
    u8 unk_02[0x2];
    Ov011Node *next;
};

struct Ov011LNode {
    u8 unk_00[0xc];
    Ov011LNode *next;
};

struct Ov011PNode {
    VecFx32 v;
    Ov011PNode *next;
};

struct Ov011Ent {
    u8 active : 1;
    u8 settled : 1;
    u8 radiusLerp : 1;
    u8 spinLerp : 1;
    u8 heightLerp : 1;
    u8 b5 : 3;
    u8 unk_01[0x3];
    Ov011PNode *nodes;
    s32 blend;
    s32 radius;
    s32 radiusTo;
    s32 radiusStep;
    s32 spin;
    s32 spinTo;
    s32 spinStep;
    s32 height;
    s32 heightTo;
    s32 heightStep;
    u16 angle;
    u8 unk_32[0x2];
    s32 dir;
};
OV011_SIZE(Ov011Ent, 0x38);

struct Ov011E38 : public Ov011V {
    u8 unk_04[0x34];
};

struct Ov011E30 : public Ov011V {
    u8 unk_04[0x2c];
};


static inline void Ov011_SetLerp(s32 *p, s32 from, s32 to, s32 frames) {
    p[1] = to;
    p[0] = from;
    p[2] = (to - p[0]) / frames;
}

static inline Ov011PNode *Ov011_PushNode(Ov011PNode *head, Ov011PNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

struct Ov011Tw {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s32 unk_04;
    VecFx32 v08;
    VecFx32 v14;
    VecFx32 v20;
};

struct Ov011TwObj {
    Ov011V *vt;
    Ov011Tw tw;
};

// The 0x138-byte animation object (ResSet_Init); unk_00 is negative until it is ready.
struct Ov011Anim {
    s16 unk_00;
    u8 unk_02[0x2];
    u32 unk_04[0x4d];
};
OV011_SIZE(Ov011Anim, 0x138);

struct Ov011Model2 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    Model0218fe1c *model;
    u8 m0c[0x30];
    u8 m3c[0x24];
};

#define OV011_TWV(p) ((Ov011V *)(p))
#define OV011_TW(p) ((Ov011Tw *)((u8 *)(p) + 4))



OV011_SIZE(Ov003Actor, 0xf0);

// The ov011 NPC class (constructor Ov011Npc_Ctor, vtable Ov011Npc_vtbl),
// derived straight from the object base.
class Ov011Npc : public Actor {
public:
    // 0xac..0xcb laid out as in Ov003Actor
    u8 unk_ac[0x4];
    Ov003Param *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    VecFx32 unk_b8;
    s32 unk_c4;
    s32 unk_c8;
    Ov011Flags unk_cc;
    u8 unk_ce_0 : 1;
    u8 unk_ce_1 : 1;
    u8 unk_ce_2 : 6;
    u8 unk_cf;
    u16 unk_d0;
    void *unk_d4;
    u8 unk_d8[0xc];
    u8 unk_e4[0xc];
    u8 unk_f0[0xc];
};

// Head of Ov011Scene: the owning actor and the list of actors taking part. The group movers
// keep a pointer to it.
class Ov011List {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[0x3];
    s32 unk_04;
    Actor *actor;
    Ov011Node *head;
};

// A Ov011Ent-driven group mover (update Ov011Mgr_Update, table Ov011Mgr_StateTable).
class Ov011Mgr {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E38 *arr8;
    Ov011E30 *arrC;
    u16 *ids;
    Ov011List *list;
    Ov011Ent *ent;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_28[0x7];
    u8 unk_2f;
};
OV011_SIZE(Ov011Mgr, 0x30);

struct Ov011E40 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01[0x3];
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011E38 mover;
};

// Point mover (Ov011Mov_Init .. Ov011Mov_GetPos).
struct Ov011Mov {
    u8 active;
    u8 unk_01[0x3];
    s32 accel;
    VecFx32 pos;
    VecFx32 vel;
};
OV011_SIZE(Ov011Mov, 0x20);

// Second group mover (update Ov011Mgr2_Update, table Ov011Mgr2_StateTable).
class Ov011Mgr2 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E40 *arr8;
    Ov011List *list;
    Ov011Ent *ent;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_20[0x7];
    u8 unk_27;
    u8 unk_28[0xb8];
    Ov011Mov mov;
};
OV011_SIZE(Ov011Mgr2, 0x100);

// Effect with its own model (init Ov011Fx_Init, update Ov011Fx_Update).
struct Ov011Fx {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    s16 unk_02;
    Ov011Anim *anim;
    Model0218fe1c *model;
    VecFx32 v0c;
    VecFx32 v18;
    MtxFx33 mtx;
    u16 state;
    u16 timer;
    u8 unk_4c[0x10];
    u8 s5c[0xc];
    u8 s68[0xc];
    u8 s74[0xc];
};
OV011_SIZE(Ov011Fx, 0x80);

// Ring buffer of s32 values (allocated by Ov011Scene_Init).
struct Ov011Ring {
    u8 b0 : 1;
    u8 rest : 7;
    u8 pad;
    u16 idx;
    u16 cap;
    u8 pad2[2];
    s32 *buf;
    s32 count;
};

class Ov011Scene;

// Tutorial/message step runner (handlers in Ov011Sub1b4_StateTable).
class Ov011Sub1b4 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 id;
    Ov011Scene *scene;
    Ov011Ent *ent;
    ActorSub40 seq;
};
OV011_SIZE(Ov011Sub1b4, 0x20);

// The 0x23c-byte scene state that the main ov011 actor owns at unk_100 (built by
// Ov011SceneActor_Start, initialised by Ov011Scene_Init, updated by Ov011Scene_Update,
// handlers in Ov011Scene_StateTable).
class Ov011Scene : public Ov011List {
public:
    Ov011Ring ring;
    ActorSub40 seq;
    Ov011Fx fx;
    Ov011Mgr2 mgr2;
    Ov011Sub1b4 s1b4;
    Ov011Mgr mgr;
    Ov011Ent ent;
};
OV011_SIZE(Ov011Scene, 0x23c);

// Tween object with a 0x24-byte layout (Ov011Vt_022079b0_Ctor constructs one).
struct Ov011E24 : public Ov011V {
    u8 unk_04[0x20];
};

// The 0x3c-byte object at Ov011SceneActor::unk_104.
struct Ov011Sa104 {
    ActorSub40 seq;
    Ov011E24 tw;
    u32 unk_38; // effect handle
};
OV011_SIZE(Ov011Sa104, 0x3c);

// The 6-byte object at Ov011SceneActor::unk_108.
struct Ov011Sa108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
};
OV011_SIZE(Ov011Sa108, 6);

// The 4-byte object at Ov011SceneActor::unk_10c.
struct Ov011Sa10c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    u16 timer;
};
OV011_SIZE(Ov011Sa10c, 4);

// The ov011 actor that owns the scene (constructor Ov011SceneActor_Ctor, vtable
// Ov011SceneActor_vtbl, setup Ov011SceneActor_Start).
class Ov011SceneActor : public Ov003Actor {
public:
    u8 unk_f0_0 : 1;
    u8 unk_f0_1 : 1;
    u8 unk_f0_2 : 6;
    u8 unk_f1;
    u16 unk_f2;
    VecFx32 unk_f4;
    Ov011Scene *scene;
    Ov011Sa104 *unk_104;
    Ov011Sa108 *unk_108;
    Ov011Sa10c *unk_10c;
};

// ov003-actor subclasses named after their vtables (only the fields ov011 reads).
// vtable Ov011Act7cf8_vtbl: Ov011Act7cf8_Start, Ov011Act7cf8_StateIdle.
class Ov011Act7cf8 : public Ov003Actor {
public:
    VecFx32 unk_f0;
};

// vtable Ov011Act7e50_vtbl: Ov011Act7e50_Start, Ov011Act7e50_SelectState, Ov011Act7e50_StateIdle.
class Ov011Act7e50 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    u16 unk_fc;
};

// vtable Ov011Act7c4c_vtbl: Ov011Act7c4c_Start, Ov011Act7c4c_SelectState, Ov011Act7c4c_StateIdle,
// Ov011Act7c4c_StateDie.
class Ov011Act7c4c : public Ov003Actor {
public:
    VecFx32 unk_f0;
    u16 unk_fc;
    u16 unk_fe;
    s32 unk_100;
    VecFx32 unk_104;
};

class Ov011Bar;

// vtable Ov011Act7da4_vtbl: Ov011Act7da4_Dtor .. Ov011Act7da4_StateDie (the photo/boss
// actor of ov011_02204b94.cpp .. ov011_022071b4.cpp).
class Ov011Act7da4 : public Ov003Actor {
public:
    u8 unk_f0;
    Ov011Anim unk_f4[2];
    Twl0214b570 *unk_364; // TWL texture requests (Ov011Act7da4_Init); their results are the
    Twl0214b570 *unk_368; // spawned actors' unk_60 (func_ov011_02205460)
    u16 unk_36c;
    u8 unk_36e;
    u8 unk_36f;
    VecFx32 unk_370[3];
    u8 unk_394;
    Ov011Bar *unk_398;
};

// An actor message (ov000 ActorMsg); the payload at 0x0c depends on cmd.
struct Ov011ActMsg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    s32 cmd;
    union {
        s32 arg;
        struct {
            u8 b;
            u8 unk_01;
            s16 x;
            s16 y;
        } p;
    } u;
};

static inline Actor *Ov011_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return (Actor *)ActorMgr_GetActor(gActorMgr, id);
}

// The scene node lists name Ov011Npc actors by id.
static inline Ov011Npc *Ov011_FindNpc(u16 id) {
    return static_cast<Ov011Npc *>(Ov011_FindActor(id));
}

static inline BOOL Ov011_ActorValid(u16 id) {
    Actor *a;
    Robo021ca458 *pl;
    a = Ov011_FindActor(id);
    if (a == NULL) {
        return FALSE;
    }
    pl = (Robo021ca458 *)ActorMgr_FindPlayer();
    if (pl == NULL) {
        return FALSE;
    }
    if (pl->unk_b1c == a->id) {
        return FALSE;
    }
    if (!(a->hit->unk_50 & 0x20000000)) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov011_NodeValid(Ov011Node *n) {
    BOOL r = FALSE;
    if (n != NULL) {
        r = Ov011_ActorValid(n->id);
    }
    return r;
}

// ov011 member functions, declared once with their classes (round acD).
extern "C" {
void func_ov011_022011c0(Ov011Npc *self, u16 v);
void func_ov011_02201214(Ov011Npc *self, void *p);
u32 Ov011Npc_IsTracking(Ov011Npc *self);
void *Ov011Npc_GetEntKey(Ov011Npc *self);
BOOL Ov011Mov_Start(Ov011Mov *self, const VecFx32 *pos, const VecFx32 *vel, s32 scale, s32 accel);
VecFx32 *Ov011Mov_GetPos(Ov011Mov *self);
void *Ov011E40_Dtor(Ov011E40 *self);
void func_ov011_021fff38(Ov011SceneActor *self);
void func_ov011_0220023c(Ov011SceneActor *self);
void func_ov011_02200310(Ov011SceneActor *self);
void Ov011SceneActor_DtorBase(Ov011SceneActor *self);
}

// v * the 3x3 part of m (the rotation of a 4x3 matrix), as MTX_MultVec33 would compute it.
static inline void Ov011_MulVec33(const VecFx32 *v, const MtxFx43 *m, VecFx32 *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m->a[0] + (s64)y * m->a[3] + (s64)z * m->a[6]) >> 12);
    out->y = (s32)(((s64)x * m->a[1] + (s64)y * m->a[4] + (s64)z * m->a[7]) >> 12);
    out->z = (s32)(((s64)x * m->a[2] + (s64)y * m->a[5] + (s64)z * m->a[8]) >> 12);
}

#endif
