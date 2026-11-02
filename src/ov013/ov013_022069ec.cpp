#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be7c[];
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);


void func_ov013_022069ec(Ov013ActVt_0220bdd8 *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0: {
        ActorSub44 *n;
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->friction = 0;
        self->unk_f0 = self->pos;
        self->pos.y -= 0x3c000;
        self->gravity = 0;
        self->rot_y = 0;
        self->velY = 0x148;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->fsm->st = 2;
        self->fsm->timer = 0;
    }
    case 2:
        w = self->fsm;
        w->timer++;
        if (w->timer <= 10) {
            return;
        }
        func_ov000_0218996c(0xf, 0x50);
        self->fsm->st = 3;
        self->fsm->timer = 0;
        break;
    case 3:
        w->timer++;
        if (w->timer <= 80) {
            return;
        }
        func_02049a48(data_02097e4c, 0x6a, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x53, -1, -1, -1);
        func_ov000_0218996c(0x14, 0xf);
        self->fsm->st = 4;
        self->fsm->timer = 0;
        break;
    case 4:
        if (VEC_Distance(&self->unk_f0, &self->pos) > 0x333) {
            VecFx32 d;
            s32 sc = self->velY;
            d.x = self->unk_f0.x - self->pos.x;
            d.y = self->unk_f0.y - self->pos.y;
            d.z = self->unk_f0.z - self->pos.z;
            VEC_MultAdd(sc, &d, &self->pos, &self->pos);
            return;
        } else {
            ActorSub44 *n;
            self->pos = self->unk_f0;
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
            self->fsm->st = 10;
            self->fsm->timer = 0;
        }
        break;
    case 10:
        w->timer++;
        if (w->timer <= 30) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}
}
