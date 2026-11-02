#include "ov012/ov012.h"

extern "C" {
void func_ov012_0220824c(Ov003Actor *self) {
    if (self->fsm->st == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x600, &self->pos, 0);
    }
    func_ov003_021d452c(self);
}

extern char data_ov012_0220b335[];
extern char data_ov012_0220b33b[];
extern char data_ov012_0220b341[];
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);

struct Ov012Rot8294 {
    u16 x;
    u16 y;
    u16 z;
};

static inline u16 Ov012_HpPct8294(Ov003Actor *self) {
    return self->hp[0] * 100 / self->hp[1];
}

void func_ov012_02208294(Ov003Actor *self) {
    Ov003Actor *pl = Ov012_FindActor(self->target);
    ActorSub40 *s = self->fsm;
    VecFx32 t;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov012_0220b335, 0x400, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        t = self->unk_b8;
        self->moveYaw = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
        self->fsm->st++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 0x14) {
            Ov012V *e;
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            e = func_02065f88(0x192, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0x1333);
            e->v34(0, self->moveYaw, 0);
            self->speed = 0x533;
            self->fsm->timer = 0;
            self->fsm->st++;
        } else {
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > 0x2d || VEC_Distance(&self->pos, &self->unk_b8) < 0x4800) {
            func_ov000_02190cb0(self->model, data_ov012_0220b33b, 0x19a, 0);
            self->unk_94_1 = 1;
            self->unk_ea_0 = 3;
            self->friction = 0xc00;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        t = self->unk_b8;
        Actor_MoveToPos(self, &t, 0);
        self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        break;
    case 3:
        Actor_TurnToActor(self, pl, 0x400);
        self->fsm->timer++;
        if (self->fsm->timer == 5 || self->fsm->timer == 0x23) {
            Ov012V *e = func_02065f88(0x384, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xe66);
        }
        if (self->model->anim_state == 1) {
            self->speed = 0;
            self->unk_ea_3 = 1;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        self->unk_94_1 = 1;
        Actor_Move(self, 0);
        break;
    case 4:
        if (func_ov000_02191120(self->model)) {
            self->unk_ea_3 = 0;
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            func_ov000_02190cb0(self->model, data_ov012_0220b341, 0x19a, 0);
            func_ov000_021915a0(self->model);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            if (Ov012_HpPct8294(self) < 0x28 && FLD(u16, self, 0x228) == 0) {
                FLD(u16, self, 0x228)++;
                func_ov000_02198360(self->fsm, 0x10, 1);
            } else {
                func_ov000_02190cb0(self->model, data_ov012_0220b335, 0x19a, 0);
                func_ov000_021911c8(self->model, 0x666);
                self->fsm->timer = 0;
                self->fsm->st++;
            }
        }
        self->unk_94_1 = 1;
        break;
    case 5:
        s->timer++;
        if (s->timer > 0x14) {
            Ov012V *e;
            Ov012Rot8294 r;
            func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
            e = func_02065f88(0x25d, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xb33);
            r.y = self->rot_y + 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->v30(&r);
            e = func_02065f88(0x25d, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xb33);
            r.y = self->rot_y - 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->v30(&r);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 6:
        s->timer++;
        if (s->timer > 100) {
            FLD(u16, self, 0x228) = 0;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    self->hit->unk_9a_5 = 1;
    func_ov000_021987b8(self->hit, 0, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        self->velY = 0;
    }
}
}
