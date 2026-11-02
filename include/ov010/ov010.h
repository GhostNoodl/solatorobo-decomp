#ifndef OV010_H
#define OV010_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov010V {
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

struct Ov010Vec {
    s32 x;
    s32 y;
    s32 z;
};

// ov000's VecFx32 is this layout; a TU that has not seen nitro/fx.h gets it as Ov010Vec (as the
// merged TUs spelled it locally), so the ov000 part structs below share one vector type.
#ifndef VECFX32_DEFINED
#define VECFX32_DEFINED
typedef Ov010Vec VecFx32;
#endif
#include "ov000/ActorParts.h"

// The ov000 actor base (ov000 Actor, ctor Actor_Ctor, 0xac bytes) as ov010 uses it.
class Ov010Obj : public Ov010V {
public:
    Ov010Obj *prev;
    Ov010Obj *next;
    u16 id;
    u16 kind;
    s32 unk_10;
    u8 state;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    s16 unk_18[4];
    u16 unk_20;
    s16 unk_22;
    u8 unk_24[0x8];
    void *msgs;
    u32 msg_flags;
    s32 unk_34;
    void *unk_38;
    void *unk_3c;
    ActorSub40 *unk_40; // state block (ov000 Actor::unk_40)
    void *unk_44;
    ActorSub48 *unk_48; // movement/collision body (ov000 Actor::unk_48)
    u8 *unk_4c;
    u16 *hp; // hp gauge (ov000 Actor::hp)
    void *unk_54;
    void *unk_58;
    void *unk_5c;
    void *unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov010Vec pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[0x2];
    Ov010Vec unk_84;
    u16 target;
    u8 unk_92;
    Ov010Flags8 unk_93;
    u8 unk_94;
    u8 unk_95;
    u16 unk_96;
    u16 unk_98;
    u16 unk_9a;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};
SIZE_ASSERT(Ov010Obj, 0xac);

// The beam effect of ov010_0220f828.cpp (round svG). An Ov010BeamSet (0x40, func_ov010_02200dcc)
// keeps a list of three Ov010BeamNode (0x8c); each node holds an Ov010Beam (0x80, drawn by
// func_ov010_02200a00 and stepped by func_ov010_0220078c), which holds its hit effect
// Ov010FxObj (0x44, func_ov010_02200048 / func_ov010_022000d8). The st members are the ov000
// state blocks (func_ov000_02198328 / func_ov000_02198360).
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
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    u16 unk_12; // id of the actor the effect follows
    s32 unk_14; // effect handles
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    Ov010Vec pos;
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
    Ov010Vec pos;
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
    Ov010Vec unk_14;
    Ov010Vec unk_20;
    ActorSub40 st;
};
SIZE_ASSERT(Ov010BeamSet, 0x40);

// 12-byte block: assigning one copies with ldm/stm (a plain Vec copies word by word)
struct Ov010Blk12 {
    s32 w[3];
};
#define OV010_BLKCPY(dst, src) (*(Ov010Blk12 *)(dst) = *(const Ov010Blk12 *)(src))

static inline void Ov010_VecSet(Ov010Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov010_VecCopy(Ov010Vec *d, const Ov010Vec *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Copy that loads y and z before x (matches the original's load order)
static inline void Ov010_VecCopyYZ(Ov010Vec *d, const Ov010Vec *s) {
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
void func_ov003_021d9900(Ov010Vec *a, u16 b, const Ov010Vec *c);
void func_ov003_021d9980(Ov010Vec *a, u16 b, const Ov010Vec *c);
extern const Ov010Vec data_ov010_0220ec20;
}

// Offset of the actor's attach point (func_ov010_021fa7e0)
static inline Ov010Vec Ov010_AttachOffset(void *obj) {
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (obj != NULL && (p = FLD(void *, obj, 0x44)) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = FLD(u16, obj, 0x7e);
        func_ov003_021d9900(&v, FLD(u16, obj, 0x7c), &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    return v;
}

#endif
