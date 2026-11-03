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
typedef ActorRot Ov010Rot;

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010Col {
    u32 a;
    u32 b;
};

extern "C" {

extern void *gActorMgr;
extern u8 Ov010Vt_0220fdf4_vtbl[];
extern Actor *ActorMgr_GetActor(void *a, u16 b);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33 *m, VecFx32 *o);
extern void VEC_Add(VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void Ov003Vec_ToRot(Ov010Col *out, const void *p);
extern void Ov010Obj022020c8_Launch(Obj022020c8 *e, u16 a, VecFx32 *b, VecFx32 *c, Ov010Col *d);
extern void Ov010Obj022020c8_Launch2(Obj022020c8 *e, u16 a, VecFx32 *b, VecFx32 *c, Ov010Rot *d);
extern void Ov010Obj022020c8_SetHitTest(Obj022020c8 *e, BOOL (*fn)(u16 id, const VecFx32 *a, const VecFx32 *b));
extern BOOL Ov010_IsPlayerNear(u16 id, const VecFx32 *a, const VecFx32 *b);

static inline Actor *Ov010_FindObjById(u16 id) {
    if (gActorMgr != NULL) {
        return ActorMgr_GetActor(gActorMgr, id);
    }
    return NULL;
}

static inline Obj022020c8 *Ov010_SpawnShot(Ov010Task *t) {
    Obj022020c8 *e = (Obj022020c8 *)Ov003_SpawnById(0x4829);
    e->flags_0 = 1;
    if (e->targetObj != NULL) {
        e->targetObj->target = t->id;
    }
    return e;
}

Obj022020c8 *Ov010Vt_0220fe08_Spawn(Ov010Task *t) {
    Obj022020c8 *e = NULL;
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
            r = obj->rot;
            MTX_RotX33_(&mx, OV010_SIN(r.x), OV010_COS(r.x));
            MTX_RotY33_(&my, OV010_SIN(r.y), OV010_COS(r.y));
            MTX_RotZ33_(&mz, OV010_SIN(r.z), OV010_COS(r.z));
            MTX_MultVec33(&t->v18, &mz, &d);
            MTX_MultVec33(&d, &mx, &d);
            MTX_MultVec33(&d, &my, &d);
            p = obj->pos;
            VEC_Add(&p, &d, &p);
            MTX_MultVec33(&t->v0c, &mz, &o);
            MTX_MultVec33(&o, &mx, &o);
            MTX_MultVec33(&o, &my, &o);
            Ov003Vec_ToRot(&c, &data_ov010_0220efb0);
            Ov010Obj022020c8_Launch(e, t->unk_06, &p, &o, &c);
            Ov010Obj022020c8_SetHitTest(e, Ov010_IsPlayerNear);
        }
    }
    return e;
}

void Ov010Task_Setup(Ov010Task *t, u16 a, u16 id, const VecFx32 *v0, const VecFx32 *v1) {
    t->b0 = 1;
    t->unk_06 = a;
    t->id = id;
    t->v0c = *v0;
    t->v18 = *v1;
}

void Ov010Vt_0220fdf4_Dtor(void) {
}

void *Ov010Vt_0220fdf4_DtorDelete(void *o) {
    Heap_Free(o);
    return o;
}

Ov010Task *Ov010Vt_0220fdf4_New(void) {
    Ov010Task *p = (Ov010Task *)Heap_Alloc(sizeof(Ov010Task));
    if (p != NULL) {
        p->vtbl = Ov010Vt_0220fdf4_vtbl;
        p->b0 = 0;
    }
    return p;
}

Obj022020c8 *Ov010Vt_0220fdf4_Spawn(Ov010Task *t) {
    Obj022020c8 *e = NULL;
    if (t->b0) {
        Actor *obj = Ov010_FindObjById(t->id);
        if (obj != NULL) {
            VecFx32 p;
            VecFx32 d;
            VecFx32 o;
            Ov010Rot r;
            e = Ov010_SpawnShot(t);
            p = obj->pos;
            OV010_BLKCPY(&d, &t->v18);
            Ov003Vec_RotateY(&d, obj->rot_y, &d);
            VEC_Add(&p, &d, &p);
            r = obj->rot;
            r.x = 0;
            r.z = 0;
            Ov003Vec_RotateY(&o, obj->rot_y, &t->v0c);
            Ov010Obj022020c8_Launch2(e, t->unk_06, &p, &o, &r);
            Ov010Obj022020c8_SetHitTest(e, Ov010_IsPlayerNear);
        }
    }
    return e;
}

void Ov010Task_Setup_02202074(Ov010Task *t, u16 a, u16 id, const VecFx32 *v0, const VecFx32 *v1) {
    t->b0 = 1;
    t->unk_06 = a;
    t->id = id;
    t->v0c = *v0;
    t->v18 = *v1;
}

}
}  // namespace m_02201cc8
