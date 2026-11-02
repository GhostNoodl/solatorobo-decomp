#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern char data_ov009_022172af[];
extern char data_ov009_022172bb[];
extern void func_ov000_02191418(Model0218fe1c *m, u16 a, BOOL b);
extern BOOL func_ov000_02191508(Model0218fe1c *m);
void func_ov009_0220b258(Ov009ActVt_022172e4 *self) {
    ActorSub40 *st = self->fsm;
    ActorSub44 *s44;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172af, 0x400, 1);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->model->unk_e4 & 0x80) {
            self->rot_y = self->unk_fc;
            self->moveYaw = self->rot_y;
        } else {
            self->rot_y = func_01ffc128(self->unk_fc, self->rot_y, 0x400, 1, 0x8000);
        }
        if (self->model->unk_e4 & 0x8000000) {
            func_ov000_02191418(self->model, 3, 0);
        }
        if (!func_ov000_02191508(self->model)) {
            Actor_Move(self, 0);
        }
        if (self->velY < 0 && (self->hit->unk_50 & 0x20000000)) {
            self->velY = 0;
            self->gravity = 0;
            func_ov000_02190cb0(self->model, data_ov009_022172bb, 0x200, 0);
            func_ov000_021915a0(self->model);
            self->fsm->st++;
            self->fsm->timer = Rand_UpTo(0x14) + 0x28;
            self->friction = 0xc00;
            self->unk_fc += 0x8000;
            func_02065f88(0x2bc, &self->pos);
            func_02065f88(0x2bd, &self->pos);
            func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
        }
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_fe++;
            if (self->unk_fe <= 1) {
                self->fsm->st = 0;
            } else {
                self->unk_fe = 0;
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
    if (!(self->hit->unk_50 & 0x20000000)) {
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
}

}
