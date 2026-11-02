#include "ov003/Vec.h"
#include "Main/Math/Rot16.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"

struct Ov003SpawnInfo {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
};

extern "C" {

extern Actor *func_ov003_021f1420(Ov003SpawnInfo *info);
extern Actor *func_ov000_02192b24(Ov003SpawnInfo *info);
extern Actor *func_ov003_021cfab4(Ov003SpawnInfo *info);
extern Actor *func_ov000_021b4828(Ov003SpawnInfo *info);
extern void func_ov000_02198360(ActorSub40 *self, u8 idx, s32 flag);

void func_ov003_021da2c8(Actor *self, s32 speed, s32 velY, s32 friction, s32 gravity) {
    if (self == NULL) {
        return;
    }
    if (friction > 0 && friction < 0x1000) {
        speed = FX_Mul(speed, friction);
    }
    if (gravity != 0) {
        velY -= gravity;
        if (velY < -0x800) {
            velY = -0x800;
        }
    }
    self->speed = speed;
    self->velY = velY;
    self->friction = friction;
    self->gravity = gravity;
}

Actor *func_ov003_021da32c(u16 id) {
    Ov003SpawnInfo info;
    Actor *obj = NULL;
    s32 i;
    s32 kind = id & 0xf000;
    info.id = id;
    info.kind = kind;
    for (i = 0; i < 4; i++) {
        info.unk_04[i] = 0;
    }
    info.unk_0c = -1;
    switch ((u16)kind) {
    case 0x1000:
        obj = func_ov003_021f1420(&info);
        break;
    case 0x2000:
    case 0x3000:
        obj = func_ov003_021f1420(&info);
        break;
    case 0x4000:
        obj = func_ov000_02192b24(&info);
        break;
    case 0x5000:
        obj = func_ov003_021cfab4(&info);
        break;
    case 0x6000:
        obj = func_ov000_021b4828(&info);
        break;
    }
    if (obj != NULL) {
        obj->vfunc_04();
    }
    return obj;
}

void func_ov003_021da40c(ActorSub40 *self) {
    u8 idx;
    u8 i;
    if (self->flags == 0) {
        return;
    }
    idx = self->current;
    for (i = 0; i < 64; i++) {
        if (((u64)1 << i) & self->flags) {
            idx = i;
            break;
        }
    }
    func_ov000_02198360(self, idx, 0);
    self->flags = 0;
}

void func_ov003_021da48c(ActorSub40 *self, u8 idx) {
    self->flags = 0;
    func_ov000_02198360(self, idx, 1);
}

EffectObj *func_ov003_021da4a8(const Ov003Vec *base, s32 range, s32 fxId) {
    Ov003Vec v;
    Ov003Vec p;
    s32 y = Rand_PlusMinus(range);
    v.x = Rand_PlusMinus(range);
    v.y = y;
    v.z = 0;
    MTX_MultVec33(&v, (const MtxFx33 *)NNS_G3dGlbGetInvV(), &v); // the inverse view matrix's rotation rows
    VEC_Add(base, &v, &p);
    return func_02065f88(fxId, &p);
}


class Ov003Follower {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void SetPos(Ov003Vec *pos);
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Rot16 *rot);
    u32 target;
    Ov003Vec offset;
    u8 unk_14[0x50];
    Rot16 rot;
};

struct Ov003FollowTgt {
    u8 unk_00[0x70];
    Ov003Vec pos;
    Rot16 rot;
};

extern void *data_ov000_021ccd68;
extern Ov003FollowTgt *ActorMgr_GetActor(void *mgr, u16 id);

static inline Ov003FollowTgt *Ov003_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov003_RotY(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotY33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33(in, &m, out);
}

static inline void Ov003_RotYM(Ov003Vec *out, s32 angle, const Ov003Vec *in, Ov003Mtx33 *m) {
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotY33_(m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33(in, m, out);
}

static inline void Ov003Follower_Update(Ov003Follower *self) {
    Ov003FollowTgt *t;
    Ov003Vec p;
    Ov003Vec off;
    Ov003Mtx33 m;
    if (self == NULL) {
        return;
    }
    t = Ov003_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    p = t->pos;
    off = self->offset;
    Ov003_RotYM(&off, (u16)t->rot.y, &off, &m);
    VEC_Add(&p, &off, &p);
    self->SetPos(&p);
}

void func_ov003_021da520(Ov003Follower *self) {
    Ov003FollowTgt *t;
    if (self == NULL) {
        return;
    }
    t = Ov003_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Ov003Vec p = t->pos;
    Ov003Vec off = self->offset;
    Ov003_RotY(&off, (u16)t->rot.y, &off);
    VEC_Add(&p, &off, &p);
    self->SetPos(&p);
}

void func_ov003_021da620(Ov003Follower *self) {
    Ov003FollowTgt *t;
    if (self == NULL) {
        return;
    }
    Ov003Follower_Update(self);
    t = Ov003_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Rot16 r;
    r.x = self->rot.x;
    r.y = self->rot.y;
    r.z = self->rot.z;
    r.y = t->rot.y;
    self->SetRot(&r);
}

}
