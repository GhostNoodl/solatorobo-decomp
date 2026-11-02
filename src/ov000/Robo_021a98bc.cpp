#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern u8 data_ov000_021cc69c[];
extern u8 data_ov000_021cc6a2[];
extern u8 data_ov000_021cc6a8[];
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_IsAnimDone(void *a);
BOOL History_SetState(ActorSub40 *st, s32 state, s32 x);
void Robo021ca458_Move(Robo021ca458 *self, BOOL a, s32 b);
u8 *Actor_GetTarget(Actor *self);
u8 *Actor_GetTargetSub44(Actor *self);
u16 Actor_YawToPos(Actor *self, void *target);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

void func_ov000_021a98bc(Robo021ca458 *self) {
    u8 *t;
    ActorSub40 *s;
    Actor_GetTarget(self);
    t = Actor_GetTargetSub44(self);
    s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc69c, 0x555, 0);
        self->speed >>= 1;
        self->friction = 0xd9a;
        if (self->velY <= 0) {
            self->velY = 0x2e;
        } else {
            self->velY -= self->velY >> 2;
        }
        if (t != NULL) {
            self->moveYaw = Actor_YawToPos(self, t);
        } else {
            self->moveYaw = self->rot_y;
        }
        self->fsm->st++;
    case 1:
        if (self->velY < 0) {
            self->gravity = 0x14;
        }
        if (self->model->anim_state == 1) {
            self->unk_b24_21 = 1;
            self->gravity = 0x29;
            self->fsm->st++;
        }
        break;
    case 2:
        if (self->model->anim_state == 2) {
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc6a2, 0x333, 1);
            self->fsm->st = 10;
        }
        break;
    case 10:
        if (self->model->anim_state == 1) {
            s->st = ActorSub40_State(s) + 1;
        }
        break;
    case 11:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->st = 20;
        } else {
            ActorSub40 *q = self->fsm;
            if (q->flags != 0) {
                if (q->flags & 0x10000) {
                    s32 lim;
                    BOOL hit = FALSE;
                    if (!(self->hit->unk_54 & 0x20000000)) {
                        lim = -0xf000;
                        if (self->unk_b22_0 != 0 || self->unk_b24_12 != 0 || self->unk_b24_19) {
                            lim = -0x2d000;
                        }
                        if (self->pos.y - self->unk_afc.y < lim) {
                            hit = TRUE;
                        }
                    }
                    if (hit) {
                        self->unk_b24_18 = 1;
                        self->fsm->st = 20;
                    } else {
                        Model0218fe1c_SetAnim(self->model, data_ov000_021cc6a2, 0x333, 1);
                        self->fsm->st = 10;
                    }
                } else {
                    q->st = 20;
                }
            }
        }
        break;
    case 20:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc6a8, 0x800, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0x52;
        self->fsm->st++;
        break;
    case 21:
        if (self->model->anim_state == 1) {
            self->unk_b24_21 = 0;
        }
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->unk_b24_21 = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
    Robo021ca458_Move(self, FALSE, 1);
}

}
