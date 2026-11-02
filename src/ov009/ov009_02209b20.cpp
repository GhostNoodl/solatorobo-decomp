#include "ov009/ov009.h"

extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov003Actor *a);

void func_ov009_02209b20(Ov009ActVt_02217594 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    func_ov000_02199f48(self->hp, func_ov000_0219bf90());
    func_ov003_021d6a3c(self, 0, 1, 1);
    self->fsm->st++;
}

void func_ov009_02209b70(Ov009ActVt_02217594 *self) {
    if (self->fsm->st == 0) {
        self->unk_312 = 1;
    }
    switch (self->unk_1a) {
    case 0:
    case 1:
        self->unk_93_4 = 1;
        self->vfunc_64();
        break;
    case 2:
        self->unk_93_4 = 1;
        self->vfunc_68();
        break;
    }
}


extern char data_ov009_022172b5[];
extern void *data_02097e4c;
extern void *func_ov000_02191318(Model0218fe1c *m, s32 a);
extern void func_ov000_02191780(void *p);
extern void func_ov000_021917f8(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_0203f364(ActorSub48 *p);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);

void func_ov009_02209bdc(Ov009ActVt_02217594 *self) {
    VecFx32 p;
    VecFx32 v;
    VecFx32 p2;
    VecFx32 v2;
    switch (self->unk_1a) {
    case 0:
    case 1:
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *s48;
            ActorSub44 *s44;
            func_ov000_02190cb0(self->model, data_ov009_022172b5, 0x1000, 0);
            func_ov000_02191318(self->model, 0x40000);
            func_ov000_02191780(self->model);
            self->fsm->timer = 0xc;
            self->fsm->st++;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            self->step = 1;
            break;
        }
        case 1:
            {
                ActorSub40 *s = self->fsm;
                if (s->timer != 0) {
                    s->timer--;
                }
                if (s->timer != 0) {
                    break;
                }
            }
            if (self->step % 2 == 0) {
                func_ov000_02191780(self->model);
            } else {
                func_ov000_021917f8(self->model);
            }
            self->step++;
            self->fsm->timer = 0xc;
            if (self->step % 2 == 0) {
                p = self->pos;
                if (self->unk_1a == 0) {
                    p.x += self->radius;
                } else {
                    p.x -= self->radius;
                }
                v.x = self->radius * 2;
                v.y = self->height;
                v.z = self->radius;
                func_ov000_0219b71c(&p, &v, 0x99a, 0x1333, 0x38b, 0x32);
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            }
            if (self->step > 0xd) {
                self->fsm->st++;
                self->fsm->timer = 0;
                self->step = 0;
                func_ov000_021917f8(self->model);
            }
            break;
        case 2:
            if (func_ov000_02191120(self->model)) {
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                data_ov000_021ccd54->stageFlags = 1;
                func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                self->vfunc_08();
            }
            break;
        }
        break;
    case 2:
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *s48;
            ActorSub44 *s44;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            self->fsm->timer = 0x18;
            self->fsm->st++;
            func_ov000_021911c8(self->model, 0x800);
            break;
        }
        case 1: {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                self->fsm->timer = 0x18;
                p2 = self->pos;
                p2.y += 0x5000;
                v2.x = self->radius;
                v2.y = self->height * 2;
                v2.z = self->radius;
                func_ov000_0219b71c(&p2, &v2, 0x99a, 0x1333, 0x38b, 0x32);
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            }
            if (func_ov000_02191120(self->model)) {
                func_ov000_021911c8(self->model, 0x1000);
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                data_ov000_021ccd54->stageFlags = 1;
                func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                self->vfunc_08();
            }
            break;
        }
        }
        break;
    }
}

}
