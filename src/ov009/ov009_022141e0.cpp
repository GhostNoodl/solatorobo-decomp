#include "ov009/ov009.h"

extern "C" {

extern Actor *Target_Get(void *p);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, const VecFx32 *pos, s32 r, s32 b, void **out);
extern Ov003Actor *Obj021984c8_GetActor(void *p);
extern void Ov003Pickup_Update(Actor *self, s32 a);
extern void ActorEx_StateThrown(Actor *self);

void Ov009ActVt_02218324_StateThrown(ActorEx *self) {
    void *list[32];
    s32 n;
    s32 r;
    u16 grp;
    s32 i;
    if (Target_Get(self->targetObj) == NULL) {
        return;
    }
    if (self->fsm->st == 1) {
        Actor_Move(self, 0);
        if (self->hit != NULL) {
            Body_Update(self->hit, 0, 0, 0);
            if (self->hit->unk_50 & 0x20000000) {
                History_SetState(self->fsm, 0x15, 0);
            }
        }
        r = self->radius + 0x4cd;
        if (r < 0xccd) {
            r = 0xccd;
        }
        self->hit->unk_44 = r;
        grp = Target_Get(self->targetObj)->id & 0xf000;
        n = Actor_FindInRadius(self, ~(1 << (grp >> 12)), &self->pos, r, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov003Actor *a;
                if (list[i] != NULL && (a = Obj021984c8_GetActor(list[i])) != NULL) {
                    ActorSub4c *p = a->targetObj;
                    if (p == NULL || grp != (u16)(p->target & 0xf000)) {
                        Ov003Pickup_Update(self, 0);
                        History_SetState(self->fsm, 0x15, 0);
                        return;
                    }
                }
            }
        }
    } else {
        ActorEx_StateThrown(self);
    }
}

}
