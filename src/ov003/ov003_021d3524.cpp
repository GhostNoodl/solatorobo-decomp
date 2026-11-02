#include "types.h"
#include "ov003/ActorApi.h"
#include "ov003/Actor.h"

extern "C" {

extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern char data_ov003_021f7a6c[];
extern char data_ov003_021f7a72[];
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s16 a, u8 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 v);
extern s32 Rand_PlusMinus(s32 max);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);
extern void Body_Update(ActorSub48 *ctl, s32 a, s32 b, s32 c);

void Ov003Actor_StateIdle(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        const char *name = data_ov003_021f7a60;
        if (self->unk_ee_0) {
            name = data_ov003_021f7a66;
        }
        Model0218fe1c_SetAnim(self->model, name, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, (s16)(Rand_PlusMinus(0x19a) + 0x1000));
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    if (self->hit != NULL && self->hit->unk_9a_4) {
        self->hit->unk_9a_5 = 1;
        if (!(self->hit->unk_50 & 0x20000000)) {
            History_SetState(self->fsm, 4, 0);
        }
    }
}

void Ov003Actor_StateMove(Ov003Actor *self) {
    Ov003Param *p;
    VecFx32 v;
    if (self->fsm->st == 0) {
        const char *name = data_ov003_021f7a6c;
        if (self->unk_ee_0) {
            name = data_ov003_021f7a72;
        }
        Model0218fe1c_SetAnim(self->model, name, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
    }
    self->hit->unk_9a_5 = 1;
    p = self->unk_b0;
    self->speed = p->unk_00;
    v.x = self->unk_b8.x;
    v.y = self->unk_b8.y;
    v.z = self->unk_b8.z;
    Actor_MoveToPos(self, &v, p->unk_02);
    Body_Update(self->hit, 1, 0, 0);
    if (!(self->hit->unk_50 & 0x20000000)) {
        History_SetState(self->fsm, 4, 0);
    }
}

}
