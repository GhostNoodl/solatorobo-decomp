#include "ov003/Vec.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"


static inline s32 Ov003Kind_Get(ActorSub40 *k) {
    return k != NULL ? k->current : 0;
}

extern "C" {

extern void *data_ov000_021ccd68;
extern const VecFx32 data_ov003_021f4988;
extern void *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(void *obj, u16 id);
extern BOOL func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(void);
extern u32 Rand_UpTo(u32 v);

void Ov003Vec_ApproachWithin(Ov003Vec *out, const Ov003Vec *a, const Ov003Vec *b, s32 dist, s32 yoff) {
    Ov003Vec d;
    Ov003Vec r;
    if (VEC_Distance(a, b) <= dist) {
        *out = *a;
        return;
    }
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(dist, &d, b, &r);
    if (yoff != 0) {
        r.y += yoff;
    }
    *out = r;
}

void Ov003Vec_MultAdd(Ov003Vec *out, const Ov003Vec *dir, const Ov003Vec *base, s32 scale, s32 yoff) {
    Ov003Vec r;
    VEC_MultAdd(scale, dir, base, &r);
    if (yoff != 0) {
        r.y += yoff;
    }
    *out = r;
}

s32 Ov003_CountActorsOfKind(u16 id) {
    return ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, id), id);
}

void Ov003Vec_ToRot(Ov003Rot *out, const Ov003Vec *v) {
    out->x = Ov003_Pitch(v->y);
    out->y = FX_Atan2(v->x, v->z);
    out->z = 0;
}

void Ov003Rot_LookAt(Ov003Rot *out, const Ov003Vec *a, const Ov003Vec *b) {
    Ov003Vec d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    VEC_Normalize(&d, &d);
    out->x = Ov003_Pitch(d.y);
    out->y = FX_Atan2(d.x, d.z);
    out->z = 0;
}

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return true;
}

BOOL Ov003Actor_CanAct(Ov003Actor *self) {
    if (!Ov003_GameIdle()) {
        return FALSE;
    }
    if (*self->hp == 0) {
        return FALSE;
    }
    if (Ov003Kind_Get(self->fsm) == 0x20 || Ov003Kind_Get(self->fsm) == 0) {
        return FALSE;
    }
    if (!func_ov000_0219bf90() || func_ov000_021b4738()) {
        return FALSE;
    }
    return TRUE;
}

static inline EffectObj *Ov003_SpawnScatter(const Ov003Vec *base, s32 range, s32 fx) {
    Ov003Vec v;
    Ov003Vec p;
    s32 y = Rand_PlusMinus(range);
    v.x = Rand_PlusMinus(range);
    v.y = y;
    v.z = 0;
    MTX_MultVec33(&v, (const MtxFx33 *)NNS_G3dGlbGetInvV(), &v); // the inverse view matrix's rotation rows
    VEC_Add(base, &v, &p);
    return func_02065f88(fx, &p);
}

void Ov003Actor_SpawnScatterFx(Actor *self, s32 range, s32 fx, s32 base, s32 top) {
    Ov003Vec pos;
    VecFx32 off = data_ov003_021f4988;
    pos = *(Ov003Vec *)&self->pos; // copied as an Ov003Vec (see ov003/Vec.h)
    s32 r;
    EffectObj *e;
    if (self->unk_44 != NULL) {
        off.x = self->unk_44->unk_0c.x;
        off.y = self->unk_44->unk_0c.y;
        off.z = self->unk_44->unk_0c.z;
    }
    VEC_Add(&pos, &off, &pos);
    r = Rand_UpTo(top - base);
    e = Ov003_SpawnScatter(&pos, range, fx);
    if (e != NULL) {
        e->SetScaleAll(base + r);
    }
}

static inline void Ov003_RotY(VecFx32 *out, s32 angle, const VecFx32 *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotY33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33(in, &m, out);
}

VecFx32 Ov003Actor_GetSub44Offset(Ov003Actor *actor) {
    VecFx32 v = data_ov003_021f4988;
    if (actor != NULL && actor->unk_44 != NULL) {
        v = *&actor->unk_44->unk_0c;
        Ov003_RotY(&v, actor->rot_y, &v);
    }
    return v;
}

}
