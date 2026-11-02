#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220b738[];
extern VecFx32 data_ov013_0220aed0;
extern void func_ov000_0219763c(Actor *self);
extern Ov003Actor *func_ov000_0219bf90(void);

void Ov013ActExVt_0220b7d0_StateDie(Ov013ActExVt_0220b7d0 *self) {
    s32 i;
    if (self->fsm->st == 0) {
        for (i = 0; i < 2; i++) {
            EffectObj *p = func_020657b0(data_0214a420, self->unk_d0[i]);
            if (p != NULL) {
                p->state = 4;
            }
        }
    }
    func_ov000_0219763c(self);
}

Ov013ActEx_021fdb70 *Ov013ActEx_021fdb70_Ctor(Ov013ActEx_021fdb70 *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov013_0220b738;
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
    func_ov000_02194758(self);
    func_ov000_02198360(self->fsm, 0x20, 0);
    self->target = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->target = p->id;
    }
    Ov013_SetSpd(self, data_ov013_0220aed0);
    self->unk_ce = 0x140;
}

}
