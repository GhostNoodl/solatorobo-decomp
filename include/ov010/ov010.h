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
#include "ov003/Actor.h"

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
void func_ov003_021cedf4(s32 a);
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
void func_ov003_021da40c(void *p);
void func_ov003_021da48c(void *p, s32 a);
VObj *func_ov003_021da788(s32 id, void *self, const VecFx32 *ofs);
VObj *func_ov003_021da7e8(s32 id, void *src, const VecFx32 *ofs);
VObj *func_ov003_021da8e4(s32 a, VecFx32 *pos, s32 b);
void func_ov003_021da904(VObj *e, void *src, const VecFx32 *off);
void func_ov003_021f0c60(void *self, s32 a);
extern const VecFx32 data_ov010_0220ec20;

// Effect 0x192 at the actor's centre, turned by (a, b) / along a -> b (ov010_0220ea84.cpp).
VObj *func_ov010_0220ea84(Actor *self, u16 a, u16 b);
VObj *func_ov010_0220eaf0(Actor *self, const VecFx32 *a, const VecFx32 *b);
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

#endif
