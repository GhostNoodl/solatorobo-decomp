#include "ov013/ov013.h"

extern "C" {

extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern char data_ov013_0220b5ca[];

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

void func_ov013_021fcef8(Ov003Actor *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220b5ca, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->friction = 0;
        self->gravity = 0;
        self->speed = 0x214;
        self->velY = 0xcd;
        self->rot_y = func_01ffc128(0x8000, self->rot_y, 0x1000, 1, 0x8000);
        self->moveYaw = self->rot_y;
        self->hp[2] = 0xffff;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->targetObj->type = 1;
        self->unk_94_1 = 1;
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    case 0x14:
        Actor_Move(self, 0);
        if (self->pos.y > 0x3000) {
            self->pos.y = 0x3000;
        }
        if (self->model == NULL) {
            return;
        }
        if (self->model->alpha != 0) {
            u8 v;
            ActorSub40 *st = self->fsm;
            st->timer++;
            v = 0x1f - (st->timer >> 2);
            if (v > 0x1f) {
                v = 0;
            }
            self->model->alpha = v;
        } else {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
}

void func_ov013_021fd06c(Ov013ActVt_0220b5e0 *self) {
    if (self->fsm->st == 0) {
        EffectMgr_Kill(data_0214a420, self->unk_f4);
    }
    func_ov003_021d36fc(self);
}

void func_ov013_021fd0a4(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->hit->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov013_021fd0c8(Ov003Actor *self) {
    ActorSub48 *m;
    if (self->fsm->st == 0) {
        if (self->fsm->history[0] == 0xb) {
            Ov003Actor *a;
            if (data_ov000_021ccd68 == NULL) {
                a = NULL;
            } else {
                a = ActorMgr_FindKind(data_ov000_021ccd68, 0x5000, 0x5c0a);
            }
            if (a != NULL && a->unk_44->unk_22_0 == 1 && a->unk_44->unk_22_1 == 1) {
                s32 ty = a->pos.y;
                s32 dist = Ov013_DistXZ(&self->pos, &a->pos);
                u16 ang = FX_Atan2(dist, ty + 0x3800 - self->pos.y);
                self->speed = FX_Mul(OV013_SIN(ang), 0x666);
                self->velY = FX_Mul(OV013_COS(ang), 0x666);
            }
        }
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->hit;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        self->unk_b6 = 300;
    }
    func_ov003_021d3d28(self);
}

}
