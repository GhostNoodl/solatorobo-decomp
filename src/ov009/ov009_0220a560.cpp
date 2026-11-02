#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

void Ov009ActVt_02217390_State20(Ov009ActVt_02217390 *self) {
    switch (self->fsm->st) {
    case 0:
        self->pos.y = self->unk_f8.y - 0xc00;
        self->model->alpha = 0;
        self->model->visible = 1;
        self->fsm->st++;
        break;
    case 1: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer >= 0x1f) {
            if (self->unk_1a == 0) {
                func_ov000_02198360(self->fsm, 1, 0);
            } else {
                func_ov000_02198360(self->fsm, 0x10, 0);
            }
            self->fsm->timer = 0x1f;
        }
        self->model->alpha = self->fsm->timer;
        self->pos.y = self->pos.y + ((self->unk_f8.y - self->pos.y) >> 2);
        break;
    }
    }
    self->hit->unk_9a_4 = 0;
    self->hit->unk_9a_5 = 0;
}

extern char data_ov009_022172cd[];
extern void func_ov000_02191618(Model0218fe1c *model);
extern void func_ov000_021911c8(Model0218fe1c *model, s16 a);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void Ov009ActVt_02217390_StateHeld(Ov009ActVt_02217390 *self) {
    if (self->fsm->st == 0) {
        self->unk_f0 = 0;
    }
    Ov003Actor_StateHeld(self);
    if (self->fsm->st == 2) {
        self->fsm->timer = 0;
    }
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    self->unk_f0++;
    if (self->unk_f0 > 0xf0) {
        func_ov000_02198360(self->fsm, 0x15, 0);
        return;
    }
    func_ov000_02190cb0(self->model, data_ov009_022172cd, 0x29, 0);
    func_ov000_02191618(self->model);
    func_ov000_021911c8(self->model, 0x200);
}

extern char data_ov009_022172af[];
extern char data_ov009_022172bb[];
extern void func_ov000_02191418(Model0218fe1c *m, u16 a, BOOL b);
extern BOOL func_ov000_02191508(Model0218fe1c *m);
void Ov009ActVt_02217390_StateAttack(Ov009ActVt_02217390 *self) {
    ActorSub40 *st = self->fsm;
    Model0218fe1c *m = self->model;
    u32 f = m->unk_e4;
    ActorSub44 *s44;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(m, data_ov009_022172af, 0x400, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        if (f & 0x80) {
            self->rot_y = self->unk_f4;
            self->moveYaw = self->rot_y;
        } else {
            self->rot_y = func_01ffc128(self->unk_f4, self->rot_y, 0x400, 1, 0x8000);
        }
        if (f & 0x8000000) {
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
            self->unk_f4 += 0x8000;
            func_02065f88(0x2bc, &self->pos);
            func_02065f88(0x2bd, &self->pos);
            func_02049a48(data_02097e4c, 0x3d, -1, -1, -1);
        }
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_f2++;
            if (self->unk_f2 <= 1) {
                self->fsm->st = 0;
            } else {
                self->unk_f2 = 0;
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        self->hit->unk_9a_5 = 0;
        break;
    }
    if (!(self->hit->unk_50 & 0x20000000)) {
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
}

extern char data_ov009_022172d3[];
extern s16 *func_ov000_02191318(Model0218fe1c *m, s32 a);
void Ov009ActVt_02217390_StateAttack2(Ov009ActVt_02217390 *self) {
    s32 prev;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172af, 0x400, 0);
        self->model->visible = 1;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        self->fsm->timer = 0;
        self->unk_f0 = 0;
        break;
    case 1:
        if (self->model->unk_e4 & 0x80) {
            self->speed = 0;
            self->friction = 0;
            self->velY = 0x666;
            self->gravity = 0x3d;
        }
        if (self->fsm->timer == 1) {
            func_ov000_02190cb0(self->model, data_ov009_022172af, 0x1000, 0);
            func_ov000_02191318(self->model, 0x19000);
        }
        {
            ActorSub40 *st = self->fsm;
            prev = self->velY;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                Actor_Move(self, 0);
                if (prev > 0 && self->velY < 0) {
                    self->fsm->timer = 0x78;
                    func_ov000_02190cb0(self->model, data_ov009_022172d3, 0x155, 0);
                    func_ov000_021915a0(self->model);
                }
            }
        }
        if (self->model->unk_e4 & 0x8000000) {
            func_ov000_02191418(self->model, 3, 0);
        }
        if (self->velY < 0) {
            if (self->hit->unk_50 & 0x20000000) {
                self->velY = 0;
                self->gravity = 0;
                func_ov000_02190cb0(self->model, data_ov009_022172bb, 0x200, 0);
                func_ov000_021915a0(self->model);
                func_ov000_02198360(self->fsm, 1, 0);
                func_02065f88(0x2bc, &self->pos);
                func_02065f88(0x2bd, &self->pos);
                func_02049a48(data_02097e4c, 0x3d, -1, -1, -1);
                self->model->visible = 0;
            }
            if (self->unk_f0++ > 0xf0) {
                func_ov000_02198360(self->fsm, 0x15, 0);
            }
        }
        break;
    }
    if (!(self->hit->unk_50 & 0x20000000)) {
        ActorSub44 *s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
}

}
