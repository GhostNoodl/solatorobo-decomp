#include "ov013/ov013.h"

struct Ov013Spot {
    VecFx32 pos;
    u16 rot;
};

extern "C" {

extern char data_ov013_0220b88d[];
extern void ActorEx_StateDie(Actor *self);
extern void ActorEx_StateHeld(Actor *self);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern BOOL Ov003Vec_Equal(void *a, const Ov013Spot *b);

void Ov013ActEx_021fdb70_StateHeld(Ov013ActEx_021fdb70 *self) {
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov013_0220b88d, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
    }
    ActorEx_StateHeld(self);
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

void Ov013ActEx_021fdb70_StateThrown(Ov013ActEx_021fdb70 *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *t = NULL;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220b88d, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        {
            u16 id = self->target;
            if (gActorMgr != NULL) {
                t = ActorMgr_GetActor(gActorMgr, id);
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
    ActorEx_StateThrown(self);
}

}
