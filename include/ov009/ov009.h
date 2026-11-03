#ifndef OV009_H
#define OV009_H

#include "types.h"
#include "Main/Lang/TblRes.h"
#include "nitro/std.h"
#include "nitro/fx.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Field.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Group.h"
#include "ov003/Actor.h"
#include "Main/Effect/Effect.h"

#define OV009_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov009V {
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


// 12-byte block: assigning one copies with ldm/stm (as Ov010Blk12 / Ov011Blk12)
struct Ov009Blk12 {
    s32 w[3];
};
#define OV009_BLKCPY(dst, src) (*(Ov009Blk12 *)(dst) = *(const Ov009Blk12 *)(src))

#define OV009_SINCOS FX_SinCosTable_
#define OV009_SIN(a) (OV009_SINCOS[((a) >> 4) * 2])
#define OV009_COS(a) (OV009_SINCOS[((a) >> 4) * 2 + 1])

// Two bytes of the unk_50 block (at +8).
typedef struct Ov009Pair {
    u8 a;
    u8 b;
} Ov009Pair;

// Sets b by copying the pair out and back, so a is reloaded and stored again as well.
static inline void Ov009Pair_SetB(Ov009Pair *p, u8 b) {
    Ov009Pair v;
    v = *p;
    v.b = b;
    *p = v;
}

// The 0x138-byte animation object (ResSet_Init); unk_00 is negative until it is ready.
struct Ov009Names {
    s16 unk_00;
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
    char anmName[0x18];
    u32 *unk_84;     // entry 2 (ActorRes::unk_84): handle, name and extension
    char unk_88[0x20];
    char unk_a8[0x18];
    u32 *unk_c0;
    char evDir[0x20];
    char evName[0x20];
    u8 unk_104[0x34];
};

class Ov009Multi : public Ov003Actor {
public:
    Model0218fe1c models[4];
    u8 unk_490;
    u8 unk_491;
    u16 unk_492;
    VecFx32 unk_494;
    VecFx32 unk_4a0; // point the actor moves toward (Ov009Multi_StateIdle)
};

struct Ov009Path {
    VecFx32 start;
    VecFx32 end;
};


static inline BOOL Ov009Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov009Game_IsIdle(FieldState *g) {
    if (Ov009Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov009_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov009Game_IsIdle(g);
    }
    return TRUE;
}

extern "C" {
void *Heap_Alloc(u32 size); // Main/Gfx/ObjPool.h
// The spawn group node an actor came from (Actor::unk_20; mgr is data_ov000_021ccd64).
GroupNode *Group_FindNode(void *mgr, u16 id);
void Heap_Free(void *ptr);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
BOOL History_SetState(void *a, s32 b, s32 c);
void Model0218fe1c_SetLoop(void *a);
s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
void Body_Update(void *a, s32 b, s32 c, s32 d);
s32 Geom_SnapToGround(VecFx32 *v, s32 y, s32 b);
BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *p);
char *func_0207011c(s32 id);
char *func_020701d4(s32 id);
}


// Render user data of a model (the 0x34-byte block the joint draw callback fills): the joint
// (func_ov000_021909a8) and its current matrix.
struct Ov009JointMtx {
    s32 joint;
    union {
        MtxFx43 mtx;
        struct {
            u8 unk_04[0x24];
            VecFx32 trans; // mtx's translation row
        };
    };
};

// Actor class of Ov009Act_02200b48_Ctor (vtable data_ov009_02216d20).
class Ov009Act_02200b48 : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u16 unk_f6;
    Ov009JointMtx joint; // the model's renderUser
};
SIZE_ASSERT(Ov009Act_02200b48, 0x12c);

// Actor class of Ov009Act_02202788_Ctor (vtable data_ov009_02216e78).
class Ov009Act_02202788 : public Ov003Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
    s32 unk_f4;
    Ov009JointMtx joint; // the model's renderUser
};
SIZE_ASSERT(Ov009Act_02202788, 0x12c);

// Actor class with vtable data_ov009_022163f4 (built inline by the ov003 factory).
class Ov009ActVt_022163f4 : public Ov003Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
};
SIZE_ASSERT(Ov009ActVt_022163f4, 0xf8);

// Actor class with vtable data_ov009_022164a0 (built inline by the ov003 factory).
class Ov009ActVt_022164a0 : public Ov003Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
};
SIZE_ASSERT(Ov009ActVt_022164a0, 0xf4);

// Actor class with vtable data_ov009_022165f8 (built inline by the ov003 factory).
class Ov009ActVt_022165f8 : public Ov003Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6[0x2];
    u32 unk_f8; // effect handle
};
SIZE_ASSERT(Ov009ActVt_022165f8, 0xfc);

// Actor class with vtable data_ov009_022166a4 (built inline by the ov003 factory).
class Ov009ActVt_022166a4 : public Ov003Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
    VecFx32 unk_f4;
    VecFx32 unk_100;
};
SIZE_ASSERT(Ov009ActVt_022166a4, 0x10c);

// Actor class with vtable data_ov009_02216750 (built inline by the ov003 factory).
class Ov009ActVt_02216750 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    VecFx32 unk_fc;
};
SIZE_ASSERT(Ov009ActVt_02216750, 0x108);

// Actor class with vtable data_ov009_02216a00 (built inline by the ov003 factory).
class Ov009ActVt_02216a00 : public Ov003Actor {
public:
    u16 unk_f0;
    u8 unk_f2[0x2];
};
SIZE_ASSERT(Ov009ActVt_02216a00, 0xf4);

// Actor class with vtable data_ov009_02216bc8 (built inline by the ov003 factory).
class Ov009ActVt_02216bc8 : public Ov003Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u16 unk_f4;
    u16 unk_f6;
    s32 unk_f8;
    s32 unk_fc;
    VecFx32 unk_100;
    u8 unk_10c[0x3c];
};
SIZE_ASSERT(Ov009ActVt_02216bc8, 0x148);

// Actor class with vtable data_ov009_02216dcc (built inline by the ov003 factory).
class Ov009ActVt_02216dcc : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6;
    u8 unk_f7;
};
SIZE_ASSERT(Ov009ActVt_02216dcc, 0xf8);

// Actor class with vtable data_ov009_02217128 (built inline by the ov003 factory).
class Ov009ActVt_02217128 : public Ov003Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
    s32 unk_f4;
    VecFx32 unk_f8;
    VecFx32 unk_104;
};
SIZE_ASSERT(Ov009ActVt_02217128, 0x110);

// Actor class with vtable data_ov009_022171d4 (built inline by the ov003 factory).
class Ov009ActVt_022171d4 : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6[0x2];
    VecFx32 unk_f8;
};
SIZE_ASSERT(Ov009ActVt_022171d4, 0x104);

// Actor class with vtable data_ov009_022172e4 (built inline by the ov003 factory).
class Ov009ActVt_022172e4 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    u16 unk_fc;
    u16 unk_fe;
};
SIZE_ASSERT(Ov009ActVt_022172e4, 0x100);

// Actor class with vtable data_ov009_02217390 (built inline by the ov003 factory).
class Ov009ActVt_02217390 : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6[0x2];
    VecFx32 unk_f8;
};
SIZE_ASSERT(Ov009ActVt_02217390, 0x104);

// Actor class with vtable data_ov009_02217640 (built inline by the ov003 factory).
class Ov009ActVt_02217640 : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u16 unk_f4;
    u8 unk_f6;
    u8 unk_f7;
    s32 unk_f8;
    VecFx32 unk_fc;
    VecFx32 unk_108;
};
SIZE_ASSERT(Ov009ActVt_02217640, 0x114);

// Actor class with vtable data_ov009_022176ec (built inline by the ov003 factory).
class Ov009ActVt_022176ec : public Ov003Actor {
public:
    VecFx32 unk_f0;
};
SIZE_ASSERT(Ov009ActVt_022176ec, 0xfc);

// Actor class with vtable data_ov009_022178f0 (built inline by the ov003 factory).
class Ov009ActVt_022178f0 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    VecFx32 unk_fc;
    u16 unk_108;
    u16 unk_10a;
    s32 unk_10c;
};
SIZE_ASSERT(Ov009ActVt_022178f0, 0x110);

// Actor class with vtable data_ov009_02217a00 (built inline by the ov003 factory).
// The 0x140 layout shared by the classes with vtables 02217a00 and 02217d5c,
// which also share their member functions (Ov009ActSpin_Init, 02211f9c, 0221268c, 022127f8).
class Ov009ActSpin : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2; // angle
    s32 unk_f4; // from func_ov000_021909a8; the model's unk_50 points here
    u8 unk_f8;
    u8 unk_f9[0x23];
    VecFx32 unk_11c;
    VecFx32 unk_128;
    VecFx32 unk_134; // pos at setup; Ov009ActSpin_StateIdle bobs around it
};
OV009_SIZE(Ov009ActSpin, 0x140);

class Ov009ActVt_02217a00 : public Ov009ActSpin {
};
SIZE_ASSERT(Ov009ActVt_02217a00, 0x140);

// Actor class with vtable data_ov009_02217aac (built inline by the ov003 factory).
class Ov009ActVt_02217aac : public Ov003Actor {
public:
    VecFx32 unk_f0;
    u8 unk_fc;
    u8 unk_fd;
    u8 unk_fe;
    u8 unk_ff;
    void *unk_100;
    void *unk_104;
};
SIZE_ASSERT(Ov009ActVt_02217aac, 0x108);

// Actor class with vtable data_ov009_02217b58 (built inline by the ov003 factory).
// The 0x110 layout shared by the classes with vtables 02217b58 and 02217f60,
// which also share Ov009ActPair110_Start and Ov009ActPair110_State20.
class Ov009ActPair110 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    VecFx32 unk_fc;
    u8 unk_108;
    u8 unk_109[0x3];
    s32 unk_10c;
};
OV009_SIZE(Ov009ActPair110, 0x110);

class Ov009ActVt_02217b58 : public Ov009ActPair110 {
};
SIZE_ASSERT(Ov009ActVt_02217b58, 0x110);

// Actor class with vtable data_ov009_02217c04 (built inline by the ov003 factory).
class Ov009ActVt_02217c04 : public Ov003Actor {
public:
    VecFx32 unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02217c04, 0xfc);

// Actor class with vtable data_ov009_02217cb0 (built inline by the ov003 factory).
class Ov009ActVt_02217cb0 : public Ov003Actor {
public:
    VecFx32 unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02217cb0, 0xfc);

// Actor class with vtable data_ov009_02217d5c (built inline by the ov003 factory).
class Ov009ActVt_02217d5c : public Ov009ActSpin {
};
SIZE_ASSERT(Ov009ActVt_02217d5c, 0x140);

// Actor class with vtable data_ov009_02217e08 (built inline by the ov003 factory).
class Ov009ActVt_02217e08 : public Ov003Actor {
public:
    s32 unk_f0;
};
SIZE_ASSERT(Ov009ActVt_02217e08, 0xf4);

// Actor class with vtable data_ov009_02217eb4 (built inline by the ov003 factory).
class Ov009ActVt_02217eb4 : public Ov003Actor {
public:
    VecFx32 unk_f0;
    VecFx32 unk_fc;
    u8 unk_108;
    u8 unk_109;
    u8 unk_10a[0x2];
};
SIZE_ASSERT(Ov009ActVt_02217eb4, 0x10c);

// Actor class with vtable data_ov009_02217f60 (built inline by the ov003 factory).
class Ov009ActVt_02217f60 : public Ov009ActPair110 {
};
SIZE_ASSERT(Ov009ActVt_02217f60, 0x110);

// Actor class with vtable data_ov009_0221802c (built inline by the ov003 factory).
class Ov009ActExVt_0221802c : public ActorEx {
public:
    u32 unk_d0;
    u8 unk_d4;
    u8 unk_d5[0x3];
    s32 unk_d8;
};
SIZE_ASSERT(Ov009ActExVt_0221802c, 0xdc);

// Actor class with vtable data_ov009_022181f4 (built inline by the ov003 factory).
class Ov009ActExVt_022181f4 : public ActorEx {
public:
    u16 unk_d0;
    u16 unk_d2;
};
SIZE_ASSERT(Ov009ActExVt_022181f4, 0xd4);

// Actor class with vtable data_ov009_0221828c (built inline by the ov003 factory).
class Ov009ActExVt_0221828c : public ActorEx {
public:
    u16 unk_d0;
    u16 unk_d2;
};
SIZE_ASSERT(Ov009ActExVt_0221828c, 0xd4);

// Actor class with vtable data_ov009_02216348 (built inline by the ov003 factory).
class Ov009ActVt_02216348 : public Ov003Actor {
public:
    u8 unk_f0;
    u8 unk_f1[0x3];
};
SIZE_ASSERT(Ov009ActVt_02216348, 0xf4);

// Actor class with vtable data_ov009_02216c74 (built inline by the ov003 factory).
class Ov009ActVt_02216c74 : public Ov003Actor {
public:
    u32 unk_f0; // effect handle
};
SIZE_ASSERT(Ov009ActVt_02216c74, 0xf4);

// Actor class with vtable data_ov009_0221707c (built inline by the ov003 factory, which clears unk_104).
class Ov009ActVt_0221707c : public Ov003Actor {
public:
    u16 unk_f0;
    u16 unk_f2;
    u8 unk_f4;
    s8 unk_f5;
    u8 unk_f6[0x2];
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    void *unk_104;
    s32 unk_108;
};

// An actor holding one animation and one model (factory 0x5414 and 0x31c class).
class Ov009ActModel : public Ov003Actor {
public:
    Ov009Names anim;
    Model0218fe1c modelObj; // built with Model0218fe1c_Init
};
OV009_SIZE(Ov009ActModel, 0x310);
OV009_SIZE(Model0218fe1c, 0xe8);
OV009_SIZE(Ov009Names, 0x138);

// Actor class with vtable 02217844 (built inline by the ov003 factory, 0x5414).
class Ov009ActVt_02217844 : public Ov009ActModel {
};

// Actor class with vtable 02217594 (built inline by the ov003 factory).
class Ov009ActVt_02217594 : public Ov009ActModel {
public:
    u16 step;
    u8 unk_312;
    u8 unk_313;
    s32 unk_314; // effect handle (Effect_Find_020657b0)
    u8 unk_318;
    u8 unk_319[0x3];
};
OV009_SIZE(Ov009ActVt_02217594, 0x31c);
SIZE_ASSERT(Ov009ActVt_0221707c, 0x10c);

#endif
