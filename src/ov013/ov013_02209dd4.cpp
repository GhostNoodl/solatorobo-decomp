#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220be7c[];
extern char data_ov013_0220be82[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}
extern char data_ov013_0220bea0[];
extern char data_ov013_0220bea6[];
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);


extern void *ActorMgr_GetGroup(void *mgr, s32 a);
extern u16 ActorGroup_CountKind(void *p, s32 a);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);


s32 func_ov013_02209b44(Ov013Act_02207968 *self) {
    s32 rnd;
    s32 st;
    u16 pct;
    u32 n;
    rnd = Rand_UpTo(0x63);
    pct = self->hp[0] * 100 / self->hp[1];
    n = ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000), 0x4813);
    st = 0xe;
    if ((self->unk_f2 == 2 && rnd % 2 == 0) || self->unk_f2 == 3) {
        st = 0xf;
    }
    if (st == 0xe) {
        if (pct <= 0x32) {
            if (!func_ov000_021983b0(self->fsm, 0x10, 3, 1)) {
                st = 0x10;
                if (n != 0) {
                    st = 1;
                    self->unk_f0 = 1;
                }
            }
        } else if (pct <= 0x46) {
            if (n == 0) {
                st = 0x10;
            }
        }
    }
    if (st == 0xe && n >= 3) {
        st = 0xf;
    }
    if (!func_ov000_021983b0(self->fsm, 0xf, 7, 1)) {
        if (self->unk_f1 != 0xf) {
            st = 0xf;
        }
    }
    switch (st) {
    case 1:
    case 0xf:
    case 0x10:
        self->unk_f2 = 0;
        break;
    case 0xe:
        self->unk_f2++;
        break;
    }
    return st;
}

void Ov013ActVt_0220bc80_Start(Ov013ActVt_0220bc80 *self) {
    s32 r;
    VecFx32 *v;
    func_ov003_021d112c(self);
    self->unk_f0 = self->rot_y + Rand_PlusMinus(0x3400);
    v = &self->unk_f4;
    Ov013_VecCopy(v, &self->pos);
    r = Rand_UpTo(0x800) + 0x3800;
    v->x += FX_Mul(r, OV013_SIN(self->rot_y));
    v->z += FX_Mul(r, OV013_COS(self->rot_y));
    self->unk_100.y = v->y;
    self->unk_b8.y = v->y;
    self->unk_100.x = v->x;
    self->unk_b8.x = v->x;
    self->unk_1c = 0x96;
    self->unk_100.z = v->z;
    self->unk_b8.z = v->z;
    self->unk_ea_6 = 1;
    {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    self->hit->unk_30 = 0;
    self->hit->unk_48 = 0x1000;
    self->unk_c8 = 0xf000;
    self->unk_cc = 0x5000;
}

void func_ov013_02209dd4(Ov013ActVt_0220bc80 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    case 1: {
        ActorSub40 *q = self->fsm;
        q->timer++;
        if (q->timer > 0x1e) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    }
    d.x = self->unk_100.x - self->pos.x;
    d.y = self->unk_100.y - self->pos.y;
    d.z = self->unk_100.z - self->pos.z;
    VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
    func_ov000_021987b8(self->hit, 0, 0, 0);
}

void func_ov013_02209ed8(Ov013ActVt_0220bc80 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    case 1: {
        ActorSub40 *q = self->fsm;
        if (q->timer != 0) {
            q->timer--;
        }
        if (q->timer == 0) {
            self->fsm->timer = 0x3c;
            self->unk_100 = self->unk_b8;
            self->unk_100.x += Rand_PlusMinus(0x8cd);
            self->unk_100.z += Rand_PlusMinus(0x8cd);
            self->unk_100.y = self->unk_100.y + Rand_PlusMinus(0x8cd) + 0x1800;
        }
        break;
    }
    }
    d.x = self->unk_100.x - self->pos.x;
    d.y = self->unk_100.y - self->pos.y;
    d.z = self->unk_100.z - self->pos.z;
    d.x = FX_Mul(d.x, 0x33);
    d.y = FX_Mul(d.y, 0x33);
    d.z = FX_Mul(d.z, 0x33);
    d.y *= 3;
    VEC_Add(&self->pos, &d, &self->pos);
    func_ov000_021987b8(self->hit, 1, 0, 0);
}

void func_ov013_0220a080(Ov003Actor *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        const char *name = data_ov013_0220bea0;
        if (self->unk_ee_0) {
            name = data_ov013_0220bea6;
        }
        func_ov000_02190cb0(self->model, name, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
    }
    self->speed = self->unk_b0->unk_00;
    v = self->unk_b8;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    self->pos.y += FX_Mul(v.y + 0x1800 - self->pos.y, 0xcd);
    func_ov000_021987b8(self->hit, 1, 0, 0);
}

void func_ov013_0220a17c(Ov003Actor *self) {
    ActorSub40 *q;
    if (!Ov013_GameIdle()) {
        func_ov000_02198360(self->fsm, 1, 0);
        return;
    }
    q = self->fsm;
    switch (q->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220be82, 0x200, 1);
        self->fsm->st++;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        break;
    case 1:
        Actor_TurnToActor(self, Ov013_FindActor(self->target), self->unk_b0->unk_02);
        if (self->model->anim_state == 1) {
            self->fsm->st++;
        }
        break;
    case 2: {
        s32 y = self->hit->check.y;
        q->timer++;
        if (q->timer > 0x2d || self->pos.y < y + 0x1400) {
            func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x200, 0);
            func_ov000_021915a0(self->model);
            self->fsm->timer = 0;
            self->fsm->st++;
            if (self->pos.y < y + 0x1400) {
                self->velY >>= 1;
            }
        }
        break;
    }
    case 3: {
        s32 lim;
        self->speed -= self->speed >> 3;
        self->velY -= self->velY >> 2;
        lim = self->unk_1c;
        q->timer++;
        if (q->timer > lim) {
            func_ov000_02198360(self->fsm, 1, 0);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
        }
        break;
    }
    }
    Actor_Move(self, 0);
    func_ov000_021987b8(self->hit, 0, 0, 0);
}

}
