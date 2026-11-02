#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} State021a98bc;

extern "C" {

extern u8 data_ov000_021cc69c[];
extern u8 data_ov000_021cc6a2[];
extern u8 data_ov000_021cc6a8[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02198360(State021a98bc *st, s32 state, s32 x);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
u8 *Actor_GetTarget(void *self);
u8 *func_ov000_0218d2e0(void *self);
u16 Actor_YawToPos(void *self, void *target);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

void func_ov000_021a98bc(Robo021ca458 *self) {
    u8 *t;
    State021a98bc *s;
    Actor_GetTarget(self);
    t = func_ov000_0218d2e0(self);
    s = (State021a98bc *)self->fsm;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc69c, 0x555, 0);
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
        ((State021a98bc *)self->fsm)->state++;
    case 1:
        if (self->velY < 0) {
            self->gravity = 0x14;
        }
        if (self->model->anim_state == 1) {
            self->unk_b24_21 = 1;
            self->gravity = 0x29;
            ((State021a98bc *)self->fsm)->state++;
        }
        break;
    case 2:
        if (self->model->anim_state == 2) {
            func_ov000_02190cb0(self->model, data_ov000_021cc6a2, 0x333, 1);
            ((State021a98bc *)self->fsm)->state = 10;
        }
        break;
    case 10:
        if (self->model->anim_state == 1) {
            s->state = ((const State021a98bc *)s)->state + 1;
        }
        break;
    case 11:
        if (func_ov000_02191120(self->model)) {
            ((State021a98bc *)self->fsm)->state = 20;
        } else {
            State021a98bc *q = (State021a98bc *)self->fsm;
            if (LFLD(u64, q, 4) != 0) {
                if (LFLD(u64, q, 4) & 0x10000) {
                    s32 lim;
                    BOOL hit = FALSE;
                    if (!(self->hit->unk_54 & 0x20000000)) {
                        lim = -0xf000;
                        if (self->unk_b22_0 != 0 || self->unk_b24_12 != 0 || self->unk_b24_19) {
                            lim = -0x2d000;
                        }
                        if (self->pos.y - self->unk_b00 < lim) {
                            hit = TRUE;
                        }
                    }
                    if (hit) {
                        self->unk_b24_18 = 1;
                        ((State021a98bc *)self->fsm)->state = 20;
                    } else {
                        func_ov000_02190cb0(self->model, data_ov000_021cc6a2, 0x333, 1);
                        ((State021a98bc *)self->fsm)->state = 10;
                    }
                } else {
                    q->state = 20;
                }
            }
        }
        break;
    case 20:
        func_ov000_02190cb0(self->model, data_ov000_021cc6a8, 0x800, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0x52;
        ((State021a98bc *)self->fsm)->state++;
        break;
    case 21:
        if (self->model->anim_state == 1) {
            self->unk_b24_21 = 0;
        }
        if (func_ov000_02191120(self->model)) {
            self->unk_b24_21 = 0;
            func_ov000_02198360((State021a98bc *)self->fsm, 1, 0);
        }
        break;
    }
    self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
    func_ov000_021b1fac(self, FALSE, 1);
}

}
