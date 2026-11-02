#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220be7c[];
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);

void func_ov013_02206ca8(Ov003Actor *self) {
    Ov003Actor *t;
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    t = Actor_GetTarget(self);
    if (t != NULL) {
        Actor_TurnToActor(self, t, 0xcd);
    }
}

extern char data_ov013_0220be82[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_021911c8(Model0218fe1c *p, s16 a);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov013_02206d28(Ov013ActVt_0220bdd8 *self) {
    Ov003Actor *t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
        self->unk_ee_2 = 0;
        func_ov000_02190cb0(self->model, data_ov013_0220be82, 0x2ab, 0);
        func_ov000_021911c8(self->model, 0x99a);
        self->fsm->st = 1;
        self->fsm->timer = 0;
        self->unk_ea_0 = 3;
        break;
    case 1:
        Actor_TurnToActor(self, t, 0x400);
        if (self->model->anim_state != 1) {
            return;
        }
        self->fsm->st = 5;
        self->fsm->timer = 0;
        func_ov000_021911c8(self->model, 0x1000);
        break;
    case 5:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x111, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        self->unk_fd = 0;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        break;
    case 10: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer <= 0x14) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    }
}

struct Ov013Blk12 {
    s32 w[3];
};

extern void *data_02097e4c;
extern char data_ov013_0220be88[];
extern const Ov013Blk12 data_ov013_0220b3e0;
extern ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 a);
extern u16 ActorGroup_CountKind(void *p, s32 a);
extern void func_ov000_0219a210(VecFx32 *p, const VecFx32 *o, s32 rot);
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);

void func_ov013_02206edc(Ov013ActVt_0220bdd8 *self) {
    s32 flip;
    Actor *a;
    void *mgr;
    Ov003Actor *t;
    t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
        self->unk_ee_2 = 1;
        func_ov000_02190cb0(self->model, data_ov013_0220be88, 0x2ab, 0);
        self->fsm->st = 5;
        self->fsm->timer = 0;
        break;
    case 5:
        if (self->model->anim_state == 1) {
            mgr = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
            if (mgr != NULL) {
                flip = Rand_UpTo(1);
                if (ActorGroup_CountKind(mgr, 0x540c) < 2) {
                    VecFx32 p;
                    VecFx32 o;
                    Ov013Blk12 base = data_ov013_0220b3e0;
                    do {
                        a = func_ov003_021d69a0(self, 0x540c, 0x20);
                        if (a != NULL) {
                            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
                            *(Ov013Blk12 *)&o = base;
                            o.x = Rand_UpTo(0x1800) + 0x1000;
                            o.y = Rand_PlusMinus(0x666) + -0x333;
                            if (!flip) {
                                flip = 1;
                            } else {
                                o.x = -o.x;
                                flip = 0;
                            }
                            func_ov000_0219a210(&p, &o, self->rot_y);
                            if (p.z < -0x5000) {
                                p.z = -0x5000;
                            }
                            if (p.y > 0x6000) {
                                p.y = 0x6000;
                            }
                            Ov013_VecCopy(&a->pos, &p);
                        }
                    } while (ActorGroup_CountKind(mgr, 0x540c) < 2);
                }
            }
        }
        if (self->model->anim_state == 2) {
            func_0204a028(data_02097e4c, 0x54, &self->pos, 5);
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        self->unk_fd = 0;
        break;
    case 10: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer <= 0x2d) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    }
}

extern char data_ov013_0220be8e[];
extern const Ov013Blk12 data_ov013_0220b3d4;
extern const Ov013Blk12 data_ov013_0220b3c8;
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov003Actor *func_ov000_0219be1c(s32 kind, VecFx32 *pos, u16 *rot, u16 id, u16 owner);
extern void func_ov000_0219bebc(Actor *a, s32 b);
extern u8 *func_0206fef8(u16 kind);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov013_Sqrt2(s64 sq) {
    OV013_SQRTCNT = 1;
    OV013_SQRT_PARAM = (u64)(sq << 2);
    while (OV013_SQRTCNT & 0x8000) {
    }
    return (s32)(OV013_SQRT_RESULT + 1) >> 1;
}

void func_ov013_02207180(Ov013ActVt_0220bdd8 *self) {
    s16 r;
    s32 tx;
    s32 ty;
    s32 tz;
    Ov003Actor *t;
    t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220be8e, 0x2ab, 0);
        self->fsm->st = 1;
        break;
    case 1:
        Actor_TurnToActor(self, t, 0x400);
        if (self->model->anim_state != 1) {
            return;
        }
        self->fsm->st = 5;
        func_02049f44(data_02097e4c, 0x43, &self->pos, 0);
        break;
    case 5: {
        VecFx32 p;
        Ov013ActEx_0220a4e0 *a;
        u16 id;
        if (self->model->anim_state != 2) {
            return;
        }
        self->target_id = 0xffff;
        *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
        {
            VecFx32 o = {0, 0, self->hit->radius + 0x5800};
            func_ov000_0219a210(&p, &o, self->rot_y);
        }
        tz = t->pos.z;
        tx = t->pos.x;
        ty = t->pos.y;
        if (ty > 0x2000) {
            ty = 0x2000;
        }
        {
            s32 dz = self->pos.z - tz;
            s32 dx = self->pos.x - tx;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            if (Ov013_Sqrt2(sq) > 0x11000) {
                ty = 0x800;
            }
        }
        r = ((s16)self->unk_fe);
        a = (Ov013ActEx_0220a4e0 *)func_ov000_0219be1c(0x4811, &p, &self->rot_x, self->id, self->target);
        if (a != NULL) {
            a->unk_d0 = 0xd9a;
            a->unk_d4.x = tx;
            a->unk_d4.y = ty;
            a->unk_d4.z = tz - 0x400;
            FLD(u16, func_0206fef8(a->kind), 0x10) = 0xd9a;
            func_ov000_0219bebc(a, r);
            id = a->id;
        } else {
            id = 0xffff;
        }
        self->target_id = id;
        self->fsm->st = 7;
        self->fsm->timer = 0;
        break;
    }
    case 7: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer <= 10) {
            return;
        }
        {
            VecFx32 p;
            VecFx32 o;
            VecFx32 s;
            EffectObj *e;
            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
            *(Ov013Blk12 *)&o = data_ov013_0220b3d4;
            *(Ov013Blk12 *)&s = data_ov013_0220b3c8;
            func_ov000_0219a210(&p, &o, self->rot_y);
            e = func_02065f88(0x12c, &p);
            e->SetScale(&s);
            e->SetRotXYZ(0, self->rot_y, 0);
        }
        self->fsm->st = 6;
        break;
    }
    case 6:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        self->fsm->st = 10;
        self->fsm->timer = 0;
        self->unk_fd = 0;
        break;
    case 10: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer <= 0x2d) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    }
}

}
