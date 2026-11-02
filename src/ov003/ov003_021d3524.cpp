#include "types.h"
#include "ov003/Actor.h"

extern "C" {

extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern char data_ov003_021f7a6c[];
extern char data_ov003_021f7a72[];
extern BOOL func_ov000_02190cb0(Model0218fe1c *model, const char *name, s16 a, u8 b);
extern void func_ov000_021915a0(Model0218fe1c *model);
extern void func_ov000_021911c8(Model0218fe1c *model, s16 v);
extern s32 Rand_PlusMinus(s32 max);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);
extern void Actor_MoveToPos(Actor *self, const VecFx32 *v, s32 a);
extern void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);

void func_ov003_021d3524(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        const char *name = data_ov003_021f7a60;
        if (self->unk_ee_0) {
            name = data_ov003_021f7a66;
        }
        func_ov000_02190cb0(self->model, name, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, (s16)(Rand_PlusMinus(0x19a) + 0x1000));
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    if (self->hit != NULL && self->hit->unk_9a_4) {
        self->hit->unk_9a_5 = 1;
        if (!(self->hit->unk_50 & 0x20000000)) {
            func_ov000_02198360(self->fsm, 4, 0);
        }
    }
}

void func_ov003_021d3600(Ov003Actor *self) {
    Ov003Param *p;
    VecFx32 v;
    if (self->fsm->st == 0) {
        const char *name = data_ov003_021f7a6c;
        if (self->unk_ee_0) {
            name = data_ov003_021f7a72;
        }
        func_ov000_02190cb0(self->model, name, 0x2ab, 0);
        func_ov000_021915a0(self->model);
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
    func_ov000_021987b8(self->hit, 1, 0, 0);
    if (!(self->hit->unk_50 & 0x20000000)) {
        func_ov000_02198360(self->fsm, 4, 0);
    }
}

}
