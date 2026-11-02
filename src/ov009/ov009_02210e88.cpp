#include "ov009/ov009.h"

extern "C" {

extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 a);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Target_SetActor(void *p, Ov003Actor *a);

void Ov009ActVt_02217c04_StateDie(Ov009ActVt_02217c04 *self) {
    if (self->fsm->st == 0) {
        self->radius += self->radius >> 1;
        Model0218fe1c_SetAnimSpeed(self->model, 0x400);
        Target_SetActor(self->hp, ActorMgr_FindPlayer());
    }
    Ov003Actor_StateDie(self);
    self->pos.y -= 0x29;
}

}
