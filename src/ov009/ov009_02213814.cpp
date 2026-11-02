#include "ov009/ov009.h"

extern "C" {

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

extern Ov003Actor *func_ov000_0219bf90(void);

void Ov009ActVt_02217cb0_Update(Ov009ActVt_02217cb0 *self) {
    u8 k;
    Ov003Actor *t;
    VecFx32 v;
    s32 dist;
    if (!Ov009_GameIdle()) {
        return;
    }
    k = self->fsm->current;
    t = func_ov000_0219bf90();
    if (t == NULL) {
        return;
    }
    v = t->pos;
    dist = Ov009_DistXZ(&self->pos, &v);
    if (dist > 0x6000) {
        self->unk_b8 = v;
        self->fsm->flags |= 4;
    }
    if (k == 1 || k == 2) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        self->unk_93_4 = 1;
        if (self->unk_b6 != 0) {
            return;
        }
        if (dist >= 0x7000) {
            func_ov000_02198360(self->fsm, 0x10, 0);
        } else if (Rand_UpTo(6) != 0) {
            func_ov000_02198360(self->fsm, 0xf, 0);
        } else {
            func_ov000_02198360(self->fsm, 0x10, 0);
        }
        self->unk_b6 = Rand_UpTo(0x14) + 0x64;
    }
}

extern char data_ov009_022179ba[];
extern char data_ov009_022179df[];
extern char data_ov009_022179e5[];
extern char data_ov009_022179eb[];
extern char data_ov009_022179b4[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
static inline Ov003Actor *Ov009_FindActor4(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void Ov009ActVt_02217cb0_StateAttack(Ov009ActVt_02217cb0 *self) {
    Ov003Actor *t = Ov009_FindActor4(self->target);
    ActorSub40 *st;
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022179ba, 0x2ab, 0);
        self->fsm->st = 10;
        self->fsm->timer = 0x78;
        break;
    case 10: {
        s32 d;
        s32 max;
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov009_022179df, 0x1000, 0);
        self->unk_f0.x = t->pos.x;
        self->unk_f0.y = t->pos.y;
        self->unk_f0.z = t->pos.z;
        self->moveYaw = self->rot_y;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        d = FX_Div(Ov009_DistXZ(&self->pos, &self->unk_f0), 0x18000);
        max = 0x452;
        if (self->unk_1a == 0) {
            max += 0x148;
        }
        if (d > max) {
            d = max;
        }
        if (d < 0xcd) {
            d = 0xcd;
        }
        self->speed = d;
        self->velY = 0x266;
        self->gravity = 0x52;
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    }
    case 0x14:
        if ((self->hit->unk_50 & 0x20000000) && self->velY < 0) {
            self->speed = 0;
        }
        Actor_Move(self, 0);
        if (self->hit != NULL) {
            func_ov000_021987b8(self->hit, 1, 0, 0);
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov009_022179e5, 0x1000, 0);
        func_ov000_021915a0(self->model);
        if (self->unk_1a == 0) {
            self->fsm->timer = Rand_UpTo(0xf) + 300;
        } else {
            self->fsm->timer = Rand_UpTo(0xf) + 200;
        }
        self->fsm->st = 0x1e;
        break;
    case 0x1e:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02190cb0(self->model, data_ov009_022179eb, 0x1000, 0);
            self->fsm->st = 0x1f;
            self->fsm->timer = 0;
        }
        self->unk_94_1 = 0;
        break;
    case 0x1f:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x20;
        self->fsm->timer = Rand_UpTo(10) + 0x32;
        break;
    case 0x20:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

}
