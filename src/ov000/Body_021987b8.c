#include "types.h"
#include "ov000/Vec.h"

typedef struct {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 unk_18;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[0xa];
    u32 unk_30;
    u32 unk_34;
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    VecFx32 offset;
    VecFx32 check;
    VecFx32 unk_74;
    VecFx32 normal;
    VecFx32 target;
    u16 unk_98;
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
    u16 unk_9a_7 : 1;
    u16 unk_9a_8 : 1;
    u16 unk_9a_9 : 1;
    u16 unk_9a_10 : 6;
} Body;

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
} ActorC;


typedef struct {
    VecFx32 a;
    VecFx32 b;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 d0;
    s32 d1;
    u32 flags;
    s32 d[3];
} HitInfo021987b8;

typedef struct ActorMgr ActorMgr;

extern ActorMgr *data_ov000_021ccd68;
extern u32 data_02fe0f04;
extern VecFx32 *data_02fe0f00;
extern HitInfo021987b8 data_02fe0f14;
extern s32 data_02fe0efc;
extern HitInfo021987b8 data_02fe0f50[];

typedef struct {
    u8 unk_00[2];
    u16 angle;
} Rot021987b8;

ActorC *func_ov000_0218e640(ActorMgr *mgr, u16 id);
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u32 angle);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
void func_0203f364(Body *self);
void func_0203f324(Body *self);
s32 func_0203f3d0(Body *self);
void func_ov000_02198ad8(Body *self, VecFx32 *pos, const VecFx32 *vel);

static inline void VEC_Copy(VecFx32 *d, const VecFx32 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline ActorC *FindActor(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov000_021987b8(Body *self, u8 keep, VecFx32 *pos, const Rot021987b8 *rot) {
    ActorC *actor = NULL;
    u32 angle;
    VecFx32 v;
    VecFx32 off;
    VecFx32 acc;
    VecFx32 push;
    u8 active;
    s32 hit;
    s32 i;

    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    if (pos != NULL && rot != NULL) {
        VEC_Copy(&v, pos);
        angle = rot->angle;
    } else {
        actor = FindActor(self->unk_98);
        if (actor == NULL) {
            func_0203f364(self);
            return;
        }
        VEC_Copy(&v, &actor->pos);
        angle = actor->rot_y;
    }
    func_01ffc9fc(&off, &self->offset, angle);
    VEC_Add(&v, &off, &v);
    VEC_Copy(&self->prev, &self->pos);
    VEC_Copy(&self->pos, &v);
    active = self->unk_24;
    if (!keep && active) {
        func_0203f364(self);
    }
    if (self->unk_44 != 0) {
        s32 t = self->unk_38;
        self->unk_38 = self->unk_44;
        self->unk_44 = t;
    }
    self->unk_25 = 1;
    hit = func_0203f3d0(self);
    if (hit != 0) {
        if ((hit & 1) && data_02fe0f00 != NULL) {
            self->unk_58 |= data_02fe0f04;
            VEC_Copy(&self->target, data_02fe0f00);
        }
        if ((hit & 2) && data_02fe0efc > 0) {
            acc.x = 0;
            acc.y = 0;
            acc.z = 0;
            for (i = 0; i < data_02fe0efc; i++) {
                if (self->unk_9a_9) {
                    self->unk_50 |= data_02fe0f50[i].flags;
                } else {
                    self->unk_50 |= data_02fe0f50[i].flags & 0xff0f0f0f;
                }
                VEC_Add(&acc, &data_02fe0f50[i].b, &acc);
            }
            VEC_Copy(&self->unk_74, &data_02fe0f14.a);
            VEC_Normalize(&acc, &self->normal);
        }
        VEC_Copy(&push, &self->unk_18);
        VEC_Add(&v, &push, &v);
        self->unk_54 = self->unk_50;
    }
    func_ov000_02198ad8(self, &v, &off);
    if (actor != NULL) {
        VEC_Copy(&actor->pos, &v);
    } else {
        VEC_Copy(pos, &v);
    }
    self->unk_25 = 0;
    if (!keep && active) {
        func_0203f324(self);
    }
    if (self->unk_44 != 0) {
        self->unk_38 = self->unk_44;
        self->unk_44 = 0;
    }
    self->unk_9a_8 = 1;
}
