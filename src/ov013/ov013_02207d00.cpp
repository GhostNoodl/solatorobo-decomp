#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be7c[];
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov003Actor *a);
extern void func_ov000_02182590(void *p);
extern void func_ov003_021ce9c4(u16 a);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern s32 func_ov013_02209b44(Ov013Act_02207968 *self);

void Ov013Act_02207968_Update(Ov013Act_02207968 *self) {
    Ov003Actor *pl;
    s32 dist;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_94_1 = 1;
    self->target = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->target = pl->id;
    }
    if (self->unk_110 != 0) {
        self->fsm->flags |= 4;
    }
    if (self->unk_111 == 0) {
        u16 pct = self->hp[0] * 100 / self->hp[1];
        if (pct <= 0x14 && pl != NULL && !func_ov000_021b4738(pl)) {
            FieldState *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(5);
            g = data_ov000_021ccd54;
            g->stageFlags = 1;
            func_ov000_02182590(&g->stageFlags);
            func_ov003_021ce9c4(FLD(u16, self->unk_b0, 4));
            {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = 0;
                n->unk_22_1 = 0;
            }
            self->hp[2] = 0xffff;
            self->unk_111 = 1;
        }
    }
    if (self->fsm->current != 1 || self->unk_f0 != 0) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    dist = 0;
    {
        Ov003Actor *t = Actor_GetTarget(self);
        if (t != NULL) {
            s32 dz = self->pos.z - t->pos.z;
            s32 dx = self->pos.x - t->pos.x;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            dist = Dist2D(sq);
        }
    }
    if (dist < 0x6800 && !func_ov000_021983b0(self->fsm, 2, 2, 1)) {
        self->fsm->flags |= 4;
        self->unk_b6 = 0x23;
        return;
    }
    self->fsm->flags |= 1ull << func_ov013_02209b44(self);
    self->unk_b6 = 0x46;
}

void func_ov013_02207d00(Ov003Actor *self) {
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->rot_y = 0;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->fsm->st = 1;
        self->fsm->timer = 0;
        break;
    case 1: {
        s32 d = 0x9000 - self->pos.y;
        if (d > 0x3000) {
            VecFx32 v = {0, d, 0};
            VEC_MultAdd(0x52, &v, &self->pos, &self->pos);
            return;
        }
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->fsm->st = 7;
        self->fsm->timer = 0;
        break;
    }
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}

extern void *ActorMgr_GetGroup(void *mgr, s32 a);
extern u16 ActorGroup_CountKind(void *p, s32 a);

void func_ov013_02207eac(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 7;
        self->fsm->timer = 0;
        self->hit->unk_30 = 0x40000000;
    }
    switch (self->unk_f0) {
    case 1:
        if (ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000), 0x4813) != 0) {
            return;
        }
        self->fsm->flags |= 0x10000;
        self->unk_f0 = 0;
        return;
    case 2:
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        self->velY = 0x19a;
        self->unk_f0 = 3;
        if (self->pos.y < 0x3000) {
            Ov013_VecSet(&self->unk_b8, self->pos.x, 0x3000, self->pos.z);
            self->velY = 0xcd;
            return;
        }
        Ov013_VecCopy(&self->unk_b8, &self->pos);
        return;
    case 3: {
        s32 y = self->unk_b8.y;
        if (self->pos.y < y) {
            Actor_Move(self, 0);
            if (self->pos.y > y) {
                self->pos.y = y;
            }
            self->rot_x = func_01ffc128(0, self->rot_x, 0xcd, 1, 0x8000);
        }
        {
            ActorSub40 *st = self->fsm;
            st->timer++;
            if (st->timer <= 0x14) {
                return;
            }
        }
        self->velY = 0x334;
        self->unk_f0 = 4;
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0xe4, 0);
        return;
    }
    case 4:
        Actor_Move(self, 0);
        self->rot_x = func_01ffc128(0, self->rot_x, 0xcd, 1, 0x8000);
        if (self->pos.y >= 0x9000) {
            self->pos.y = 0x9000;
            self->unk_f0 = 0;
            self->fsm->st = 0;
        }
        return;
    }
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern VecFx32 Ov003Vec_DirXZ(const VecFx32 *a, const VecFx32 *b);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *target, s32 a);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern VecFx32 data_ov013_0220b3b0;

static inline Ov003Actor *Ov013_GetActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov013_VecCopyR(VecFx32 *d, const VecFx32 &s) {
    d->x = s.x;
    d->y = s.y;
    d->z = s.z;
}

static inline VecFx32 Ov013_ApproachPoint(Ov003Actor *self) {
    VecFx32 res;
    Ov003Actor *t;
    res.x = 0;
    res.y = 0;
    res.z = 0;
    t = Ov013_GetActor(self->target);
    if (t == NULL) {
        return res;
    }
    {
        VecFx32 tp;
        VecFx32 dir;
        Ov013_VecCopy(&tp, &t->pos);
        Ov013_VecCopyR(&dir, Ov003Vec_DirXZ(&tp, &self->pos));
        VEC_MultAdd(0x7800, &dir, &tp, &res);
    }
    return res;
}

static inline s32 Ov013_DistXZ3(const VecFx32 *a, const VecFx32 *b) {
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Dist2D(sq);
}

static inline s32 Ov013_DistXZc(s32 x, s32 z, const VecFx32 *b) {
    s32 dz = z - b->z;
    s32 dx = x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Dist2D(sq);
}

void func_ov013_022080bc(Ov013Act_02207968 *self) {
    Ov003Actor *t = Ov013_GetActor(self->target);
    VecFx32 tpos;
    VecFx32 v;
    s32 d;
    if (t == NULL) {
        return;
    }
    tpos = t->pos;
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        v = Ov013_ApproachPoint(self);
        self->unk_b8 = v;
        self->speed = self->unk_b0->unk_00;
        self->unk_110 = 1;
        self->fsm->st = 7;
        self->fsm->timer = 0;
        self->hit->unk_30 = 0;
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
    }
    v = self->unk_b8;
    Actor_TurnToActor(self, t, self->unk_b0->unk_02);
    Actor_MoveToPos(self, &v, 0);
    func_ov000_021987b8(self->hit, 1, 0, 0);
    if (Ov013_DistXZ3(&tpos, &self->pos) < 0x7800) {
        VecFx32 dir = Ov003Vec_DirXZ(&tpos, &self->pos);
        VEC_MultAdd(0x7800, &dir, &tpos, &v);
        self->unk_b8 = v;
    }
    d = Ov013_DistXZc(-0x2d9a, -0x452, &self->pos);
    if (d > 0xf000) {
        VecFx32 dir = Ov003Vec_DirXZ(&self->pos, &data_ov013_0220b3b0);
        VEC_MultAdd(d - 0xf000, &dir, &data_ov013_0220b3b0, &v);
        self->unk_b8 = v;
    }
    if (Ov013_DistXZ3(&v, &self->pos) != 0) {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer <= 0x78) {
            return;
        }
    }
    func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x19a, 0);
    func_ov000_021915a0(self->model);
    self->unk_110 = 0;
    func_ov000_02198360(self->fsm, 1, 0);
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
}

extern char data_ov013_0220be82[];
extern BOOL Hit_DiffInCylinder(const VecFx32 *a, const VecFx32 *b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_ov000_02191318(void *a, s32 b);
extern void Actor_TurnToPos(Ov003Actor *self, VecFx32 *p, s32 a);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);

static inline VecFx32 Ov013_ApproachPointK(Ov003Actor *self, s32 k) {
    VecFx32 res;
    Ov003Actor *t;
    res.x = 0;
    res.y = 0;
    res.z = 0;
    t = Ov013_GetActor(self->target);
    if (t == NULL) {
        return res;
    }
    {
        VecFx32 tp;
        VecFx32 dir;
        Ov013_VecCopy(&tp, &t->pos);
        Ov013_VecCopyR(&dir, Ov003Vec_DirXZ(&tp, &self->pos));
        VEC_MultAdd(k, &dir, &tp, &res);
    }
    return res;
}

void func_ov013_02208500(Ov013Act_02207968 *self) {
    Ov003Actor *t = Ov013_GetActor(self->target);
    VecFx32 v;
    if (t == NULL) {
        return;
    }
    v = self->unk_b8;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 tp;
        self->unk_f1 = 0xf;
        func_ov000_02190cb0(self->model, data_ov013_0220be82, 0x2ab, 0);
        tp = t->pos;
        {
            VecFx32 dir = Ov003Vec_DirXZ(&tp, &self->pos);
            VEC_MultAdd(0xc000, &dir, &tp, &v);
        }
        v.y = 0x5800;
        self->unk_b8 = v;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = FX_Div(Ov013_DistXZ3(&self->pos, &v), 0x3c000);
        self->velY = -0xcd;
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        self->fsm->st = 2;
        self->fsm->timer = 0;
        break;
    }
    case 2: {
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        Actor_MoveToPos(self, &v, 0);
        if (self->pos.y < 0x5800) {
            self->pos.y = 0x5800;
        }
        if (self->model->anim_state != 1) {
            return;
        }
        v = Ov013_ApproachPointK(self, -0x4000);
        if (!Hit_DiffInCylinder(&v, &data_ov013_0220b3b0, 0x7000, 0x2800) || Hit_DiffInCylinder(&v, &data_ov013_0220b3b0, 0x5800, 0x2800)) {
            VecFx32 dir = Ov003Vec_DirXZ(&data_ov013_0220b3b0, &v);
            VEC_MultAdd(0x7000, &dir, &data_ov013_0220b3b0, &v);
        }
        {
        VecFx32 tp;
        tp = t->pos;
        {
        VecFx32 a = Ov003Vec_DirXZ(&self->pos, &tp);
        VecFx32 b = Ov003Vec_DirXZ(&data_ov013_0220b3b0, &tp);
        if ((s32)(((s64)a.x * b.x + (s64)a.y * b.y + (s64)a.z * b.z + 0x800) >> 12) < 0x19a) {
            VEC_MultAdd(0x7000, &a, &data_ov013_0220b3b0, &v);
        }
        }
        }
        v.y = 0x5800;
        self->unk_b8 = v;
        self->speed = 0x266;
        self->velY = -0x52;
        self->friction = 0x1052;
        self->gravity = 0x29;
        self->fsm->st = 3;
        self->fsm->timer = 0;
        break;
    }
    case 3: {
        VecFx32 p;
        VecFx32 d;
        Actor_MoveToPos(self, &v, 0);
        if (self->pos.y < 0x5800) {
            self->pos.y = 0x5800;
            self->velY = 0;
        }
        Ov013_VecCopyR(&d, Ov003Vec_DirXZ(&data_ov013_0220b3b0, &v));
        VEC_MultAdd(0xf000, &d, &data_ov013_0220b3b0, &p);
        Actor_TurnToPos(self, &p, 0x400);
        if (self->model->anim_state == 3) {
            func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        }
        if (self->model->anim_state != 2) {
            return;
        }
        self->unk_94_1 = 0;
        self->velY = -0x15;
        v.y = 0x1b33;
        self->unk_b8 = v;
        self->fsm->st = 4;
        self->fsm->timer = 0;
        self->unk_92 = 0;
        break;
    }
    case 4: {
        VecFx32 p;
        VecFx32 d;
        self->unk_94_1 = 0;
        self->rot_x = func_01ffc128(0x271c, self->rot_x, 0xcd, 1, 0x8000);
        Ov013_VecCopyR(&d, Ov003Vec_DirXZ(&data_ov013_0220b3b0, &self->pos));
        VEC_MultAdd(0x5000, &d, &self->pos, &p);
        Actor_TurnToPos(self, &p, 0x400);
        if (self->pos.y <= 0x1b33) {
            self->pos.y = 0x1b33;
        } else {
            self->pos.y += self->velY;
            self->velY -= self->gravity;
            if (self->velY < -0x800) {
                self->velY = -0x800;
            }
            if (self->pos.y < 0x1b33) {
                self->pos.y = 0x1b33;
                func_ov000_0218996c(5, 0x1e);
                func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            }
        }
        {
            ActorSub40 *st = self->fsm;
            st->timer++;
            if (st->timer <= 0xfa) {
                return;
            }
        }
        func_ov000_02190cb0(self->model, data_ov013_0220be82, 0x155, 0);
        func_ov000_02191318(self->model, 0x96000);
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        self->unk_f0 = 2;
        func_ov000_02198360(self->fsm, 1, 0);
        self->fsm->st = 7;
        break;
    }
    }
}

struct Ov013Blk12 {
    s32 w[3];
};

extern char data_ov013_0220be8e[];
extern VecFx32 data_ov013_0220b398;
extern VecFx32 data_ov013_0220b38c;
extern VecFx32 data_ov013_0220b380;
extern void func_ov000_0219a210(VecFx32 *p, VecFx32 *o, u16 rot);
extern Ov003Actor *func_ov000_0219be1c(s32 kind, VecFx32 *pos, u16 *rot, u16 id, u16 owner);
extern void func_ov000_0219bebc(Actor *a, s32 b);
extern u8 *func_0206fef8(u16 kind);
extern Ov013V *func_02065f88(s32 id, VecFx32 *pos);

void func_ov013_02208bfc(Ov013Act_02207968 *self) {
    Ov003Actor *t = Ov013_GetActor(self->target);
    ActorSub40 *st;
    if (t == NULL) {
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0: {
        VecFx32 *pt;
        self->unk_f1 = 0xe;
        func_ov000_02190cb0(self->model, data_ov013_0220be8e, 0x2ab, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = self->unk_b0->unk_00;
        pt = &self->unk_f8;
        pt->x = t->pos.x;
        pt->y = t->pos.y;
        pt->z = t->pos.z;
        if (pt->y > 0x2000) {
            pt->y = 0x2000;
        }
        if (!Hit_DiffInCylinder(pt, &data_ov013_0220b3b0, 0x6000, 0x2800)) {
            VecFx32 dir = Ov003Vec_DirXZ(&data_ov013_0220b3b0, pt);
            VEC_MultAdd(0x5800, &dir, &data_ov013_0220b3b0, pt);
        }
        if (Ov013_DistXZ3(&self->pos, pt) < 0x5000) {
            VecFx32 d;
            VecFx32 q;
            Ov013_VecCopyR(&d, Ov003Vec_DirXZ(pt, &self->pos));
            VEC_MultAdd(0x5000, &d, pt, &q);
            Ov013_VecCopy(&self->unk_b8, &q);
            self->hit->unk_30 = 0;
        } else {
            self->unk_b8 = self->pos;
        }
        self->fsm->st = 2;
        self->fsm->timer = 0;
        break;
    }
    case 2: {
        VecFx32 v;
        Actor_TurnToPos(self, &self->unk_f8, 0x400);
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (self->model->anim_state != 1) {
            return;
        }
        self->fsm->st = 3;
        self->fsm->timer = 0;
        break;
    }
    case 3: {
        VecFx32 p;
        Ov013ActEx_0220a4e0 *a;
        u16 id;
        if (self->model->anim_state != 2) {
            return;
        }
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
        func_ov000_0219a210(&p, &data_ov013_0220b398, self->rot_y);
        a = (Ov013ActEx_0220a4e0 *)func_ov000_0219be1c(0x4811, &p, &self->rot_x, self->id, self->target);
        if (a != NULL) {
            a->unk_d0 = 0x99a;
            a->unk_d4.x = self->unk_f8.x;
            a->unk_d4.y = self->unk_f8.y;
            a->unk_d4.z = self->unk_f8.z;
            FLD(u16, func_0206fef8(a->kind), 0x10) = 0x99a;
            func_ov000_0219bebc(a, 0x1000);
            id = a->id;
        } else {
            id = 0xffff;
        }
        self->target_id = id;
        self->fsm->st = 4;
        self->fsm->timer = 0;
        break;
    }
    case 4:
        if (st->timer == 0) {
            VecFx32 p;
            Ov013V *e;
            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
            func_ov000_0219a210(&p, &data_ov013_0220b38c, self->rot_y);
            e = func_02065f88(0x12c, &p);
            e->v10(&data_ov013_0220b380);
            e->v34(0, self->rot_y, 0);
            self->fsm->timer++;
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 7;
        self->fsm->timer = 0;
        break;
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}

void func_ov013_022090ac(Ov013Act_02207968 *self) {
    Ov003Actor *t = Ov013_GetActor(self->target);
    ActorSub40 *st;
    if (t == NULL) {
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0: {
        VecFx32 *pt;
        self->unk_f1 = 0xe;
        func_ov000_02190cb0(self->model, data_ov013_0220be8e, 0x2ab, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = self->unk_b0->unk_00;
        pt = &self->unk_f8;
        if (self->unk_f2 == 0) {
            Ov013_VecCopyYZ(pt, &t->pos);
            if (pt->y > 0x2000) {
                pt->y = 0x2000;
            }
            if (Ov013_DistXZ3(pt, &self->pos) < 0x5000) {
                VecFx32 d = Ov003Vec_DirXZ(pt, &self->pos);
                VecFx32 q;
                VEC_MultAdd(0x5000, &d, pt, &q);
                Ov013_VecCopy(&self->unk_b8, &q);
                self->hit->unk_30 = 0;
            }
            Ov013_VecCopyR(&self->unk_104, Ov003Vec_DirXZ(&self->pos, pt));
        } else {
            VecFx32 w;
            s32 k;
            if (self->unk_f2 == 1) {
                Ov013_VecSet(&w, FX_Mul(self->unk_104.z, 0x1000), 0, (s32)((0x800 - (s64)self->unk_104.x * 0x1000) >> 12));
                k = 0x3000;
            } else {
                Ov013_VecSet(&w, (s32)((0x800 - (s64)self->unk_104.z * 0x1000) >> 12), 0, FX_Mul(self->unk_104.x, 0x1000));
                k = 0x6000;
            }
            VEC_MultAdd(k, &w, pt, pt);
            if (!Hit_DiffInCylinder(pt, &data_ov013_0220b3b0, 0x6000, 0x2800)) {
                VecFx32 dir = Ov003Vec_DirXZ(&data_ov013_0220b3b0, pt);
                VEC_MultAdd(0x5800, &dir, &data_ov013_0220b3b0, pt);
            }
        }
        self->fsm->st = 2;
        self->fsm->timer = 0;
        break;
    }
    case 2: {
        VecFx32 v;
        Actor_TurnToPos(self, &self->unk_f8, 0x400);
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (self->model->anim_state != 1) {
            return;
        }
        self->fsm->st = 3;
        self->fsm->timer = 0;
        break;
    }
    case 3: {
        VecFx32 p;
        Ov013ActEx_0220a4e0 *a;
        u16 id;
        if (self->model->anim_state != 2) {
            return;
        }
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        p = self->pos;
        func_ov000_0219a210(&p, &data_ov013_0220b398, self->rot_y);
        a = (Ov013ActEx_0220a4e0 *)func_ov000_0219be1c(0x4811, &p, &self->rot_x, self->id, self->target);
        if (a != NULL) {
            a->unk_d0 = 0x99a;
            a->unk_d4.x = self->unk_f8.x;
            a->unk_d4.y = self->unk_f8.y;
            a->unk_d4.z = self->unk_f8.z;
            FLD(u16, func_0206fef8(a->kind), 0x10) = 0x99a;
            func_ov000_0219bebc(a, 0x1000);
            id = a->id;
        } else {
            id = 0xffff;
        }
        self->target_id = id;
        self->unk_f2++;
        self->fsm->st = 4;
        self->fsm->timer = 0;
        break;
    }
    case 4:
        if (st->timer == 0) {
            VecFx32 p;
            Ov013V *e;
            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
            func_ov000_0219a210(&p, &data_ov013_0220b38c, self->rot_y);
            e = func_02065f88(0x12c, &p);
            e->v10(&data_ov013_0220b380);
            e->v34(0, self->rot_y, 0);
            self->fsm->timer++;
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 7;
        self->fsm->timer = 0;
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        break;
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        if (self->unk_f2 < 3) {
            self->fsm->st = 0;
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_f2 = 0;
        break;
    }
}

}
