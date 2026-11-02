#ifndef OV014_H
#define OV014_H

#include "types.h"
#include "nitro/std.h"
#include "nitro/fx.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Field.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov003/Actor.h"
#include "ov003/FxList.h"
#include "ov003/Script.h"
#include "ov003/Unit.h"
#include "Main/Effect/Effect.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Res/ResArc.h"
#include "nitro/std.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov014V {
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

// Generic bitfield views
// A resource name and its frame count (data_ov014_022173e0, defined in ov014_02216ff0.cpp).
struct Ov014Res { const char *name; u16 n; };

struct Ov014Flags {
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

struct Ov014Vec16 {
    s16 x;
    s16 y;
    s16 z;
};

// Three u16 angles.

static inline void Ov014_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov014_VecCopy(VecFx32 *d, const VecFx32 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov014_VecCopyYZ(VecFx32 *d, const VecFx32 *s) {
    s32 y = s->y;
    s32 z = s->z;
    d->x = s->x;
    d->y = y;
    d->z = z;
}

struct Ov014Msg {
    u8 unk_00[0x5];
    u8 type;
    u16 id; // sender
    union {
        u8 idx;
        s16 unk_08;
    };
    u8 unk_0a[0x2];
    union {
        VecFx32 v;
        u16 unk_0c; // type 9: an actor id
    };
};

#define OV014_SINCOS FX_SinCosTable_
#define OV014_SIN(a) (OV014_SINCOS[((a) >> 4) * 2])
#define OV014_COS(a) (OV014_SINCOS[((a) >> 4) * 2 + 1])


struct Ov014Names {
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
SIZE_ASSERT(Ov014Names, 0x138);

class Ov014Multi : public Ov003Actor {
public:
    Model0218fe1c models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    VecFx32 unk_494;
};

static inline BOOL Ov014Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov014Game_IsIdle(FieldState *g) {
    if (Ov014Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov014_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov014Game_IsIdle(g);
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
void func_ov003_021dacfc(void *p);
void func_ov000_0219763c(Actor *self);
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *a, s32 b);
}


// Frees the effect list in *slot with the default heap selected.
static inline void Ov014_FreeFx(Ov003FxList **slot) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*slot != NULL) {
        Ov003FxList *p = *slot;
        if (p != NULL) {
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        *slot = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline Ov003FxList *Ov014_NewFx(void) {
    Ov003FxList *p = (Ov003FxList *)Heap_Alloc(sizeof(Ov003FxList));
    if (p != NULL) {
        p->head = NULL;
    }
    return p;
}

// Actor class of Ov014Act_021fa6a0_Ctor (vtable data_ov014_02217114).
class Ov014Act_021fa6a0 : public Ov003Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
    VecFx32 unk_f8;
    VecFx32 unk_104;
    VecFx32 unk_110;
    s16 unk_11c;
    u8 unk_11e;
    u8 unk_11f;
    u32 unk_120;
    Ov014Names unk_124;
    Model0218fe1c mdl;
    const Ov003Step *step; // current step of scripts
    Ov003ScriptList scripts;
    s16 unk_364;
    u8 unk_366[0x2];
};
SIZE_ASSERT(Ov014Act_021fa6a0, 0x368);

// Actor class of Ov014Act_021fd4d4_Ctor (vtable data_ov014_02217588).
class Ov014Act_021fd4d4 : public Ov003Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    s32 unk_f4;
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa[0x2];
    Ov003FxList *unk_fc; // effect list (func_ov003_021da940 frees it)
    u8 unk_100[0x2c];
    VecFx32 unk_12c;
    u8 unk_138;
    u8 unk_139;
    s16 unk_13a;
    const Ov003Step *step; // current step of scripts
    Ov003ScriptList scripts; // tracks 0..3, picked by hp (func_ov014_021fd37c)
    const Ov003Step *step2; // current step of scripts2
    Ov003ScriptList scripts2; // tracks 10..12, picked by hp (func_ov014_021fd43c)
};
SIZE_ASSERT(Ov014Act_021fd4d4, 0x17c);

// Actor class of Ov014Act_0220011c_Ctor (vtable data_ov014_022174dc).
class Ov014Act_0220011c : public Ov003Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    u32 unk_f4;
    u8 unk_f8;
    u8 unk_f9;
    u16 unk_fa;
    u16 unk_fc;
    u8 unk_fe;
    u8 unk_ff;
    Ov003FxList *unk_100; // effect list (func_ov003_021da940 frees it)
    const Ov003Step *step; // current step of scripts
    Ov003ScriptList scripts;
};
SIZE_ASSERT(Ov014Act_0220011c, 0x124);

// Actor class of Ov014Act_02201b94_Ctor (vtable data_ov014_02217430).
class Ov014Act_02201b94 : public Ov003Actor {
public:
    s16 unk_f0;
    u8 unk_f2[0x2];
    u32 unk_f4;
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa[0x2];
    Ov003FxList *unk_fc; // effect list (func_ov003_021da940 frees it)
    u8 unk_100[0x2c];
    s16 unk_12c;
    u8 unk_12e;
    u8 unk_12f;
    const Ov003Step *step; // current step of scripts
    Ov003ScriptList scripts;
    u16 unk_150;
    u8 unk_152;
    u8 unk_153;
    u8 unk_154[0x1ac];
    VecFx32 unk_300;
    u8 unk_30c[0x24];
    s32 unk_330;
    s32 unk_334;
    s32 unk_338;
    u8 unk_33c[0xe];
    Ov014Flags unk_34a;
    u8 unk_34c[0x24];
};
SIZE_ASSERT(Ov014Act_02201b94, 0x370);

// Render user data of a model: the draw callback (func_ov014_0220f8a4) stores the current
// matrix of the joint into mtx.
struct Ov014JointMtx {
    s32 joint; // func_ov000_021909a8 result
    union {
        MtxFx43 mtx;
        struct {
            u8 unk_04[0x24];
            VecFx32 trans; // mtx's translation row
        };
    };
};

// A copy of Ov003Actor::unk_b4..unk_b8 (0x10 bytes, MIi_CpuCopyFast).
struct Ov014B4Save {
    u16 unk_b4;
    u16 unk_b6;
    VecFx32 unk_b8;
};

// Actor class of Ov014Act_0221267c_Ctor (vtable data_ov014_02217dc0).
class Ov014Act_0221267c : public Ov003Actor {
public:
    Ov014Names unk_f0;
    Model0218fe1c mdl;
    u16 unk_310;
    u16 unk_312;
    Ov014JointMtx unk_314; // the model's renderUser
    s32 unk_348;
    u16 unk_34c;
    u8 unk_34e[0x2];
    s32 unk_350;
    u8 unk_354;
    u8 unk_355[0x3];
};
SIZE_ASSERT(Ov014Act_0221267c, 0x358);

// Actor class of Ov014Act_02209280_Ctor (vtable data_ov014_02217968).
class Ov014Act_02209280 : public Ov003Actor {
public:
    const Ov003Step *step; // current step of scripts
    u32 unk_f4;
    u16 unk_f8;
    u8 unk_fa[0x2];
    u8 unk_fc;
    u8 unk_fd[0x3];
    s32 unk_100;
    s32 unk_104;
    u8 unk_108[0x24];
    VecFx32 unk_12c;
    s32 unk_138;
    u8 unk_13c[0x24];
    s32 unk_160;
    s32 unk_164;
    s32 unk_168;
    s32 unk_16c;
    u8 unk_170[0x24];
    s32 unk_194;
    s32 unk_198;
    s32 unk_19c;
    u16 unk_1a0;
    u16 unk_1a2;
    u8 unk_1a4;
    u8 unk_1a5;
    u8 unk_1a6[0x2];
    s32 unk_1a8;
    s32 unk_1ac;
    s32 unk_1b0;
    VecFx32 unk_1b4;
    Ov003ScriptList scripts; // tracks 0..2, picked by hp (func_ov014_022091ec)
    u32 unk_1dc;
    u32 unk_1e0;
    s32 unk_1e4;
    s32 unk_1e8;
    s32 unk_1ec;
    s32 unk_1f0;
    u16 unk_1f4;
    u16 unk_1f6;
};
SIZE_ASSERT(Ov014Act_02209280, 0x1f8);

// Actor class of Ov014Act_0220f9d0_Ctor (vtable data_ov014_02217e6c).
class Ov014Act_0220f9d0 : public Ov003Actor {
public:
    Ov014JointMtx unk_f0; // the model's renderUser
    Ov003ScriptList scripts; // tracks 0..3, picked by hp (func_ov014_0220f8fc)
    const Ov003Step *step; // current step of scripts
    s32 unk_144;
    u16 unk_148;
    u16 unk_14a;
    u16 unk_14c;
    u16 unk_14e;
    u16 unk_150;
    u8 unk_152[0x2];
    void *unk_154;
    u32 unk_158;
    Ov014B4Save unk_15c; // Ov003Actor::unk_b4..unk_b8 saved while a 0x200 message is handled
    u8 unk_16c;
    u8 unk_16d[0x13];
    u8 unk_180;
    u8 unk_181[0x3];
};
SIZE_ASSERT(Ov014Act_0220f9d0, 0x184);

// Actor class of Ov014ActEx_02208618_Ctor (vtable data_ov014_02217708).
class Ov014ActEx_02208618 : public ActorEx {
public:
    u32 unk_d0;
    u8 unk_d4;
    u8 unk_d5[0x3];
    Ov003FxList *unk_d8; // effect list
};
SIZE_ASSERT(Ov014ActEx_02208618, 0xdc);

// Actor class of Ov014ActEx_0220d70c_Ctor (vtable data_ov014_02217bdc).
class Ov014ActEx_0220d70c : public ActorEx {
public:
    u32 unk_d0;
    u32 unk_d4;
    Ov014Vec16 unk_d8; // state durations, copied from the spawn data at 0x18
    u8 unk_de[0x2];
};
SIZE_ASSERT(Ov014ActEx_0220d70c, 0xe0);

// Actor class of Ov014ActEx_0220dcf4_Ctor (vtable data_ov014_02217b44).
class Ov014ActEx_0220dcf4 : public ActorEx {
public:
    u32 unk_d0;
    u8 unk_d4;
    u8 unk_d5;
    s16 unk_d6;
    u16 unk_d8; // rot_y and rot_z while it flies (0x19)
    u16 unk_da;
};
SIZE_ASSERT(Ov014ActEx_0220dcf4, 0xdc);

// Actor class of Ov014ActEx_021fbd64_Ctor (vtable data_ov014_022172c4).
class Ov014ActEx_021fbd64 : public ActorEx {
public:
    Ov003FxList *unk_d0; // effect list (func_ov003_021da940 frees it)
};
SIZE_ASSERT(Ov014ActEx_021fbd64, 0xd4);

// Actor class of Ov014ActEx_021fc24c_Ctor (vtable data_ov014_0221722c).
class Ov014ActEx_021fc24c : public ActorEx {
public:
    VecFx32 unk_d0;
    s32 unk_dc;
    s32 unk_e0;
    s32 unk_e4;
    VecFx32 unk_e8;
    s32 unk_f4;
    u32 unk_f8;
    u8 unk_fc;
    u8 unk_fd;
    u8 unk_fe;
    u8 unk_ff;
    Ov003FxList *unk_100; // effect list (func_ov003_021da940 frees it)
};
SIZE_ASSERT(Ov014ActEx_021fc24c, 0x104);

// Actor class of Ov014ActEx_02206c68_Ctor (vtable data_ov014_02217670).
class Ov014ActEx_02206c68 : public ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
    u16 unk_d8;
    u8 unk_da[0x2];
    Ov003FxList *unk_dc; // effect list (func_ov003_021da940 frees it)
};
SIZE_ASSERT(Ov014ActEx_02206c68, 0xe0);

// Actor class of Ov014ActEx_0220774c_Ctor (vtable data_ov014_022177a0).
class Ov014ActEx_0220774c : public ActorEx {
public:
    u32 unk_d0;
    s32 unk_d4;
    Ov003FxList *unk_d8; // effect list (func_ov003_021da940 frees it)
};
SIZE_ASSERT(Ov014ActEx_0220774c, 0xdc);

// Actor class of Ov014ActEx_0220eca0_Ctor (vtable data_ov014_02217aac).
class Ov014ActEx_0220eca0 : public ActorEx {
public:
    s32 unk_d0;
    s32 unk_d4;
    VecFx32 unk_d8;
    s32 unk_e4;
    s32 unk_e8;
    s32 unk_ec;
    s16 unk_f0;
    s16 unk_f2;
    s16 unk_f4;
    u8 unk_f6[0x2];
};
SIZE_ASSERT(Ov014ActEx_0220eca0, 0xf8);

// Actor class of Ov014ActEx_022142fc_Ctor (vtable data_ov014_02217fb0).
class Ov014ActEx_022142fc : public ActorEx {
public:
    VecFx32 unk_d0;
    s32 unk_dc;
    s32 unk_e0;
};
SIZE_ASSERT(Ov014ActEx_022142fc, 0xe4);

// Actor class of Ov014ActEx_022152e8_Ctor (vtable data_ov014_02217f18).
class Ov014ActEx_022152e8 : public ActorEx {
public:
    VecFx32 unk_d0;
    VecFx32 unk_dc;
    s32 unk_e8;
    s32 unk_ec;
    u16 unk_f0;
    u8 unk_f2[0x2];
    s32 unk_f4;
};
SIZE_ASSERT(Ov014ActEx_022152e8, 0xf8);

// The ov000-factory classes with vtables data_ov014_022178d0 (0xe8 bytes, exactly this class) and
// data_ov014_02217838 (Ov014ActExVt_02217838): both scale in from 0 to the model's scale.
class Ov014ActExGrow : public ActorEx {
public:
    u32 flags;      // 0x1000: remove, 0x200000: hit
    VecFx32 scale; // the model's scale, saved at start
    s32 cur_scale;
    u8 timer;
    u8 unk_e5[0x3];
};
SIZE_ASSERT(Ov014ActExGrow, 0xe8);

class Ov014ActExVt_02217838 : public Ov014ActExGrow {
public:
    u32 fx; // handle of the effect spawned at full size
};
SIZE_ASSERT(Ov014ActExVt_02217838, 0xec);

// ov000 actor functions, typed (round acA).
extern "C" {
ActorEx *ActorEx_Ctor(ActorEx *self);
void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
void Actor_TurnToPos(Actor *self, const VecFx32 *target, s32 step);
VecFx32 *func_ov000_0218d2e0(Actor *self);
ActorEx *func_ov000_0219429c(ActorEx *self);
void func_ov000_02194758(ActorEx *self);
BOOL func_ov000_02194c08(ActorEx *self);
void func_ov000_02195d88(ActorEx *self);
}

#endif
