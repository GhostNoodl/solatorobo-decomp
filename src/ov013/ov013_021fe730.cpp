#include "ov013/ov013.h"

struct Ov013Spot {
    VecFx32 pos;
    u16 rot;
};

extern "C" {

extern char data_ov013_0220b88d[];
extern void func_ov000_0219763c(Actor *self);
extern void func_ov000_02195d88(Actor *self);
extern void func_ov000_02196060(Ov003Actor *self);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003Actor *ActorMgr_GetGroup(void *mgr, u16 id);
extern BOOL Ov003Vec_Equal(void *a, const Ov013Spot *b);

void func_ov013_021fe730(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->model);
    }
    func_ov000_02195d88(self);
}

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

void func_ov013_021fe778(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *t = NULL;
        func_ov000_02190cb0(self->model, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        {
            u16 id = self->target;
            if (data_ov000_021ccd68 != NULL) {
                t = ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
        }
        if (t != NULL) {
            s32 ty = t->pos.y;
            s32 d = Ov013_DistXZ(&self->pos, &t->pos);
            s32 dy = self->pos.y >= ty ? self->pos.y - ty : ty - self->pos.y;
            ActorSub4c *m = self->targetObj;
            m->unk_50 = d;
            m->unk_54 = dy;
            m->unk_58 = 0;
        }
        self->hit->unk_30 = 0;
    }
    func_ov000_02196060(self);
}

}
