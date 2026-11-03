#include "ov013/ov013.h"

extern "C" {

extern void *Ov013ActEx_021fdb70_vtbl[];
extern VecFx32 data_ov013_0220aed0;
extern void ActorEx_StateDie(Actor *self);
extern Ov003Actor *ActorMgr_FindPlayer(void);

void Ov013ActExVt_0220b7d0_StateDie(Ov013ActExVt_0220b7d0 *self) {
    s32 i;
    if (self->fsm->st == 0) {
        for (i = 0; i < 2; i++) {
            EffectObj *p = Effect_Find_020657b0(gEffectMgr, self->unk_d0[i]);
            if (p != NULL) {
                p->state = 4;
            }
        }
    }
    ActorEx_StateDie(self);
}

Ov013ActEx_021fdb70 *Ov013ActEx_021fdb70_Ctor(Ov013ActEx_021fdb70 *self) {
    ActorEx_Ctor(self);
    *(void **)self = Ov013ActEx_021fdb70_vtbl;
    self->unk_ce = 0;
    self->unk_d0 = -1;
    self->unk_d4 = 0;
    return self;
}

static inline void Ov013_SetSpd(Actor *self, VecFx32 v) {
    Ov013_VecCopy(&self->hit->offset, &v);
    Ov013_VecCopy(&self->unk_44->unk_0c, &v);
}

void Ov013ActEx_021fdb70_Start(Ov013ActEx_021fdb70 *self) {
    Ov003Actor *p;
    ActorEx_Start(self);
    History_SetState(self->fsm, 0x20, 0);
    self->target = 0xffff;
    p = ActorMgr_FindPlayer();
    if (p != NULL) {
        self->target = p->id;
    }
    Ov013_SetSpd(self, data_ov013_0220aed0);
    self->unk_ce = 0x140;
}

}
