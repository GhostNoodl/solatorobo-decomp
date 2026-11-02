#ifndef OV012_H
#define OV012_H

#include "types.h"
#include "nitro/std.h"
#include "nitro/fx.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Field.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov003/Actor.h"
#include "ov003/FxList.h"
#include "ov003/Unit.h"
#include "ov003/Script.h"
#include "Main/Res/ResMgr.h"
#include "Main/Res/StageCmd.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Res/ResArc.h"
#include "Main/Hit/HitSphere.h"
#include "nitro/std.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov012V {
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

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))


static inline void Ov012_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov012_VecCopy(VecFx32 *d, const VecFx32 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov012_VecCopyYZ(VecFx32 *d, const VecFx32 *s) {
    s32 y = s->y;
    s32 z = s->z;
    d->x = s->x;
    d->y = y;
    d->z = z;
}

struct Ov012Msg {
    u8 unk_00[0x5];
    u8 type;
    u16 unk_06;
    union {
        u8 idx;
        s32 unk_08;
    };
    VecFx32 v;
};

#define OV012_SINCOS FX_SinCosTable_
#define OV012_SIN(a) (OV012_SINCOS[((a) >> 4) * 2])
#define OV012_COS(a) (OV012_SINCOS[((a) >> 4) * 2 + 1])

struct Ov012Names {
    s16 unk_00; // negative until the resources are loaded
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 ownMdl : 1;
    u8 ownAnm : 1;
    u8 unk_03_3 : 1;
    u8 ownEv : 1;
    u8 unk_03_5 : 3;
    u8 unk_04[0xc];
    char mdlDir[0x20];
    char mdlName[0x1c];
    char anmDir[0x20];
    char anmName[0x58];
    char evDir[0x20];
    char evName[0x20];
    u8 unk_104[0x34];
};
SIZE_ASSERT(Ov012Names, 0x138);

class Ov012Multi : public Ov003Actor {
public:
    Model0218fe1c models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    VecFx32 unk_494;
};

static inline BOOL Ov012Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov012Game_IsIdle(FieldState *g) {
    if (Ov012Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov012_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov012Game_IsIdle(g);
    }
    return TRUE;
}

extern "C" {
void *Heap_Alloc(u32 size); // Main/Gfx/ObjPool.h
void Heap_Free(void *ptr);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_021915a0(void *a);
s32 Rand_PlusMinus(s32 max);
u32 Rand_UpTo(u32 max);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_ov000_0219a2f4(VecFx32 *v, s32 y, s32 b);
BOOL func_ov000_02191120(Model0218fe1c *p);
char *func_0207011c(void *res);
char *func_020701d4(void *res);
u8 *func_02070558(void *res);
}
extern "C" {
void func_ov000_021953b4(ActorEx *self);
void Ov003FxList_Prune(Ov003FxList *p);
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *a, s32 b);
}


// Frees the effect list in *slot with the default heap selected.
static inline void Ov012_FreeFx(Ov003FxList **slot) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*slot != NULL) {
        Ov003FxList *p = *slot;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        *slot = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline Ov003FxList *Ov012_NewFx(void) {
    Ov003FxList *p = (Ov003FxList *)Heap_Alloc(sizeof(Ov003FxList));
    if (p != NULL) {
        p->head = NULL;
    }
    return p;
}


extern "C" {
extern void *data_ov000_021ccd64;
extern char data_ov012_0220aaf9[];
extern void *func_ov000_0218e9c4(void *p);
extern void *func_ov000_0218fe1c(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void SndMgr_LoadHeapState(SndMgr *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern BOOL func_ov000_0218cf5c(Ov003Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov000_021903b4(void *p);
extern s32 Ov003Actor_HandleMsg(Ov003Actor *self, Ov012Msg *msg);
extern BOOL func_020621c4(void);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
}

static inline void Ov012_StopSnd(void) {
    if (func_02035b90(data_ov012_0220aaf9, 7)) {
        func_02036838(data_02097cdc, data_ov012_0220aaf9, 7, 0);
    }
}


extern "C" {
extern void func_0203f364(ActorSub48 *p);
extern void *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern void func_ov000_021984f4(void *p, s32 a, s32 b);
extern void func_ov000_0219864c(ActorSub48 *p, VecFx32 *a, u16 *b);
extern void func_ov000_02196860(Actor *self);
extern void func_ov000_0219763c(Actor *self);
}

#define VCALL(p) ((Ov012V *)(p))


extern "C" {
extern void func_02049678(SndMgr *a, s32 b, s32 c, s32 d);
extern BOOL SndMgr_IsLoadDone(SndMgr *a);
}


extern "C" {
extern void func_ov000_0218f074(void *a, const void *b, s32 c, s32 d, s32 e, s32 f);
extern Actor *Target_Get(void *p);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);
}


extern "C" {
}


extern "C" {
}


extern "C" {
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
}


extern "C" {
}

static inline Ov003Actor *Ov012_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (Ov003Actor *)ActorMgr_GetActor(data_ov000_021ccd68, id);
}


extern "C" {
extern void Actor_MoveToPos(Actor *self, const VecFx32 *v, s32 a);
extern Ov003Actor *Actor_GetTarget(void *self);
}


struct Ov012SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov012Spawn_Init(Ov012SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov012SpawnDesc *d, void *pos, void *rot, u16 a);
extern void Target_Set(void *a, void *b);
extern void func_ov000_02190758(void *a, void *b, s32 c);
extern void func_ov000_02191c24(void *a, VecFx32 *b);
}


struct Ov012VecC {
    s32 x;
    s32 y;
    s32 z;
    Ov012VecC() {}
    Ov012VecC(const Ov012VecC &o) : x(o.x), y(o.y), z(o.z) {}
};


extern "C" {
extern s32 func_ov000_0219a510(Actor *self, u16 mask, const VecFx32 *pos, s32 r, s32 a, void **list);
extern void *func_ov000_021985c0(void *p);
extern void Ov003Pickup_Update(void *self, s32 a);
extern void func_ov000_0218996c(u8 a, u8 b);
}


extern "C" {
}

static inline void Ov012_ClearOwnerFlag(Ov003Actor *self) {
    Ov003Unit *o = (Ov003Unit *)Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (o != NULL) {
        o->unk_a2_0 = 0;
    }
}


extern "C" {
extern void func_01ffc9fc(VecFx32 *a, const VecFx32 *b, u16 ang);
extern void func_ov000_0219bebc(void *o, s16 a);
extern BOOL func_ov000_021b4738(void *o);
extern void Actor_TurnToPos(void *self, const void *v, s32 a);
}


extern "C" {
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
}


static inline Ov003Actor *Ov012_FindRes(s32 a, s32 b) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (Ov003Actor *)ActorMgr_FindKind(data_ov000_021ccd68, a, b);
}


class Ov012Lift : public Ov003Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    VecFx32 unk_f4;
    VecFx32 unk_100;
    u32 unk_10c;
    u8 unk_110;
    u8 unk_111;
    s16 unk_112;
    s32 unk_114;
    u8 unk_118[0xc];
    VecFx32 unk_124;
    s32 unk_130;
    u8 unk_134;
    u8 unk_135;
    u8 unk_136;
    u8 unk_137;
    u8 unk_138;
    u8 unk_139[0x3];
    s32 fxId[3]; // effect handles (func_02065f88(...)->id); the ctor sets all three to -1
    u8 unk_148[0xc];
    s32 unk_154;
    s32 unk_158;
    s32 unk_15c;
    u8 unk_160[0xc];
    u16 unk_16c;
    u8 unk_16e;
    u8 unk_16f;
    s16 unk_170;
    u8 unk_172[0x2];
    Ov012Names unk_174; // func_ov000_0218e9c4 / func_ov000_0218ea20
    Model0218fe1c mdl;  // func_ov000_0218fe1c / func_ov000_0218fee4, drawn once per arr entry
    VecFx32 arr[2];
    u8 unk_3ac[2];
    u8 unk_3ae;
    u8 unk_3af;
};
SIZE_ASSERT(Ov012Lift, 0x3b0);


extern "C" {
extern const char *const data_ov012_0220a3c4;
extern const char *const data_ov012_0220a3c8;
extern const char *const data_ov012_0220a57c;
}


extern "C" {
extern u16 FX_AsinIdx(s32 a);
extern u16 FX_Atan2(s32 a, s32 b);
}



static inline void Ov012Spawn_Set(Ov012SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {
extern Ov003Actor *func_ov000_02192b24(Ov012SpawnDesc *d);
extern void func_ov000_02182590(void *p);
}


extern "C" {
}


extern "C" {
extern BOOL func_ov000_021983b0(ActorSub40 *p, u8 a, s32 b, BOOL c);
extern void func_ov000_02191418(Model0218fe1c *p, u16 a, BOOL b);
}


extern "C" {
extern s32 Ov003_CountActorsOfKind(u16 kind);
}


#define OV012_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov012_Sqrt2(s64 sq) {
    OV012_SQRTCNT = 1;
    OV012_SQRT_PARAM = (u64)(sq << 2);
    while (OV012_SQRTCNT & 0x8000) {
    }
    return (s32)(OV012_SQRT_RESULT + 1) >> 1;
}

static inline s32 Ov012_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    return Ov012_Sqrt2((s64)dx * dx + (s64)dz * dz);
}

extern "C" {
}

// Actor class of Ov012Act_021fee1c_Ctor (vtable data_ov012_0220abf0).
class Ov012Act_021fee1c : public Ov003Actor {
public:
    VecFx32 unk_f0;
    u32 unk_fc;
    s16 unk_100;
    u8 unk_102;
    u8 unk_103;
    s16 unk_104;
    u8 unk_106[0x2];
};
SIZE_ASSERT(Ov012Act_021fee1c, 0x108);

// Actor class of Ov012Act_021ffa68_Ctor (vtable data_ov012_0220ab44).
class Ov012Act_021ffa68 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    s32 unk_fc;
    u32 unk_100;
    s16 unk_104;
    u8 unk_106;
    u8 unk_107;
    Ov003FxList *fxList;
};
SIZE_ASSERT(Ov012Act_021ffa68, 0x10c);

// Actor class of Ov012Act_02202b10_Ctor (vtable data_ov012_0220afe4).
class Ov012Act_02202b10 : public Ov003Actor {
public:
    u32 unk_f0;
    u8 unk_f4;
    u8 unk_f5;
    u16 unk_f6;
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa;
    u8 unk_fb;
    u8 unk_fc;
    u8 unk_fd;
    u8 unk_fe[0x2];
    Ov003FxList *fxList;
    const Ov003Step *step; // the step of scripts the actor is carrying out (NULL: none)
    Ov003ScriptList scripts;
    s16 unk_124;
    u8 unk_126[0x2];
};
SIZE_ASSERT(Ov012Act_02202b10, 0x128);

static inline void Ov012_ResetF0(Ov012Act_02202b10 *self) {
    self->step = NULL;
    self->unk_f0 = 1;
    self->unk_f8 = 0;
}

// Actor class of Ov012ActEx_02207018_Ctor (vtable data_ov012_0220b0b8).
class Ov012ActEx_02207018 : public ActorEx {
public:
    u32 unk_d0;
    Ov003FxList *fxList;
};
SIZE_ASSERT(Ov012ActEx_02207018, 0xd8);

// The ov000-factory class with vtable data_ov012_0220af10 (0xe4 bytes).
class Ov012ActExVt_0220af10 : public ActorEx {
public:
    VecFx32 unk_d0;
    u16 unk_dc;
    u16 unk_de;
    u16 unk_e0;
    u8 unk_e2;
    u8 unk_e3;
};
SIZE_ASSERT(Ov012ActExVt_0220af10, 0xe4);

// The ov000-factory class with vtable data_ov012_0220b150 (0xe8 bytes).
class Ov012ActExVt_0220b150 : public ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
    s32 unk_d8;
    u32 unk_dc;
    u8 unk_e0;
    u8 unk_e1[0x3];
    s32 unk_e4;
};
SIZE_ASSERT(Ov012ActExVt_0220b150, 0xe8);

// The ov000-factory class with vtable data_ov012_0220b1e8 (0x2fc bytes): an ActorEx with a second
// model and its resources, drawn at pos while unk_d0 bit 20 is clear.
class Ov012ActExVt_0220b1e8 : public ActorEx {
public:
    u32 unk_d0;
    u8 unk_d4;
    u8 unk_d5[0x3];
    ActorRes unk_d8;    // func_ov000_0218e9c4 / func_ov000_0218ea20
    Model0218fe1c mdl;  // func_ov000_0218fe1c / func_ov000_0218fee4
    u8 unk_2f8;
    u8 unk_2f9[0x3];
};
SIZE_ASSERT(Ov012ActExVt_0220b1e8, 0x2fc);

// The ov003-factory class with vtable data_ov012_0220b280 (0x22c bytes, kinds 0x5029, 0x5039,
// 0x5057, 0x5c01): its own resource names at 0xf0, filled through nameFunc.
class Ov012ActVt_0220b280 : public Ov003Actor {
public:
    Ov012Names unk_f0; // func_ov000_0218e9c4 / func_ov000_0218ea20
    u16 unk_228;
    u8 unk_22a[0x2];
};
SIZE_ASSERT(Ov012ActVt_0220b280, 0x22c);

// ov000 actor functions, typed (round acA).
extern "C" {
ActorEx *ActorEx_Ctor(ActorEx *self);
void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
VecFx32 *func_ov000_0218d2e0(Actor *self);
ActorEx *func_ov000_0219429c(ActorEx *self);
void func_ov000_0219433c(ActorEx *self);
BOOL func_ov000_021946f8(ActorEx *self);
void func_ov000_02194758(ActorEx *self);
BOOL func_ov000_02194c08(ActorEx *self);
void func_ov000_02195d88(ActorEx *self);
}

#endif
