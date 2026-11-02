#include "ov010/ov010.h"
#include "ov000/ActorBase.h"

typedef s32 fx32;

// This TU's .rodata (all of it) and its .data up to the copies the static initialiser makes. The
// copied vectors and their sources are weak: the stub loads each through its own pool word, not
// from the section base. ov010_02201cc8.cpp (0x02201cc8..0x022020c8, which reads
// data_ov010_0220efb0) joined this TU in round dtD, in its own namespace.
struct Ov010Rot { u16 x, y, z; };

extern "C" {

extern const s32 data_ov010_0220ef98;
extern const VecFx32 data_ov010_0220efa4;
extern const VecFx32 data_ov010_0220efb0;
extern const VecFx32 data_ov010_0220efbc;
extern const VecFx32 data_ov010_0220fdc8;
extern const VecFx32 data_ov010_0220fde0;

static inline fx32 K(fx32 v) { return v; }

const s32 data_ov010_0220ef98 = 0x9000;
static const Ov010Rot data_ov010_0220ef9c = {0, 0, 0};
const VecFx32 data_ov010_0220efb0 = {-0x1000, 0, 0};
__declspec(weak) const VecFx32 data_ov010_0220efa4 = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov010_0220efbc = {0, 0x1000, 0};
static const Ov010Rot data_ov010_0220fdc0 = data_ov010_0220ef9c;
__declspec(weak) const VecFx32 data_ov010_0220fdc8 = data_ov010_0220efa4;
static const VecFx32 data_ov010_0220fdd4 = {K(0x1000), K(0), K(0)};
__declspec(weak) const VecFx32 data_ov010_0220fde0 = data_ov010_0220efbc;

}

// ---- merged from ov010_02201cc8.cpp
namespace m_02201cc8 {
struct Ov010Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010Col {
    u32 a;
    u32 b;
};

struct Ov010Task {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    u16 id;
    u8 unk_0a[2];
    VecFx32 v0c;
    VecFx32 v18;
};
SIZE_ASSERT(Ov010Task, 0x24);

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 data_ov010_0220fdf4[];
extern Actor *ActorMgr_GetActor(void *a, u16 b);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33 *m, VecFx32 *o);
extern void VEC_Add(VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void Ov003Vec_ToRot(Ov010Col *out, const void *p);
extern void func_ov010_022024c4(u8 *e, u16 a, VecFx32 *b, VecFx32 *c, Ov010Col *d);
extern void func_ov010_02202560(u8 *e, u16 a, VecFx32 *b, VecFx32 *c, Ov010Rot *d);
extern void func_ov010_02202600(u8 *e, void *fn);
extern BOOL func_ov010_022018c4(u16 id, const VecFx32 *a, const VecFx32 *b);

static inline Actor *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return NULL;
}

static inline u8 *Ov010_SpawnShot(Ov010Task *t) {
    Actor *e = func_ov003_021da32c(0x4829);
    e->flags_0 = 1;
    if (e->targetObj != NULL) {
        e->targetObj->target = t->id;
    }
    return (u8 *)e;
}

u8 *func_ov010_02201cc8(Ov010Task *t) {
    u8 *e = NULL;
    if (t->b0) {
        Actor *obj = Ov010_FindObjById(t->id);
        if (obj != NULL) {
            Ov010Mtx33 mx;
            Ov010Mtx33 my;
            Ov010Mtx33 mz;
            VecFx32 p;
            VecFx32 d;
            VecFx32 o;
            Ov010Col c;
            Ov010Rot r;
            e = Ov010_SpawnShot(t);
            r = FLD(Ov010Rot, obj, 0x7c);
            MTX_RotX33_(&mx, OV010_SIN(r.x), OV010_COS(r.x));
            MTX_RotY33_(&my, OV010_SIN(r.y), OV010_COS(r.y));
            MTX_RotZ33_(&mz, OV010_SIN(r.z), OV010_COS(r.z));
            MTX_MultVec33(&t->v18, &mz, &d);
            MTX_MultVec33(&d, &mx, &d);
            MTX_MultVec33(&d, &my, &d);
            p = FLD(VecFx32, obj, 0x70);
            VEC_Add(&p, &d, &p);
            MTX_MultVec33(&t->v0c, &mz, &o);
            MTX_MultVec33(&o, &mx, &o);
            MTX_MultVec33(&o, &my, &o);
            Ov003Vec_ToRot(&c, &data_ov010_0220efb0);
            func_ov010_022024c4(e, t->unk_06, &p, &o, &c);
            func_ov010_02202600(e, (void *)func_ov010_022018c4);
        }
    }
    return e;
}

void func_ov010_02201eac(Ov010Task *t, u16 a, u16 id, const VecFx32 *v0, const VecFx32 *v1) {
    t->b0 = 1;
    t->unk_06 = a;
    t->id = id;
    t->v0c = *v0;
    t->v18 = *v1;
}

void func_ov010_02201f00(void) {
}

void *func_ov010_02201f04(void *o) {
    Heap_Free(o);
    return o;
}

void *Ov010Vt_0220fdf4_New(void) {
    u8 *p = (u8 *)Heap_Alloc(0x24);
    if (p != NULL) {
        FLD(void *, p, 0) = data_ov010_0220fdf4;
        FLD(Ov010Flags8, p, 4).b0 = 0;
    }
    return p;
}

u8 *func_ov010_02201f44(Ov010Task *t) {
    u8 *e = NULL;
    if (t->b0) {
        Actor *obj = Ov010_FindObjById(t->id);
        if (obj != NULL) {
            VecFx32 p;
            VecFx32 d;
            VecFx32 o;
            Ov010Rot r;
            e = Ov010_SpawnShot(t);
            p = FLD(VecFx32, obj, 0x70);
            OV010_BLKCPY(&d, &t->v18);
            func_ov003_021d9980(&d, obj->rot_y, &d);
            VEC_Add(&p, &d, &p);
            r = FLD(Ov010Rot, obj, 0x7c);
            r.x = 0;
            r.z = 0;
            func_ov003_021d9980(&o, obj->rot_y, &t->v0c);
            func_ov010_02202560(e, t->unk_06, &p, &o, &r);
            func_ov010_02202600(e, (void *)func_ov010_022018c4);
        }
    }
    return e;
}

void func_ov010_02202074(Ov010Task *t, u16 a, u16 id, const VecFx32 *v0, const VecFx32 *v1) {
    t->b0 = 1;
    t->unk_06 = a;
    t->id = id;
    t->v0c = *v0;
    t->v18 = *v1;
}

}
}  // namespace m_02201cc8
