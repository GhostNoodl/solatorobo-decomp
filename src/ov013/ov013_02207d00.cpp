#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be7c[];
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void VEC_MultAdd(s32 s, const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov013Actor *a);
extern void func_ov000_02182590(void *p);
extern void func_ov003_021ce9c4(u16 a);
extern Ov013Actor *Actor_GetTarget(Ov013Obj *self);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern s32 func_ov013_02209b44(Ov013Act_02207968 *self);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline void CP_SetSqrtImm64_NS_(u64 param) {
    OV013_SQRT_PARAM = param;
}

static inline void CP_SetSqrt64(u64 param) {
    OV013_SQRTCNT = 1;
    CP_SetSqrtImm64_NS_(param);
}

static inline void CP_WaitSqrt(void) {
    while (OV013_SQRTCNT & 0x8000) {
    }
}

static inline u32 CP_GetSqrtResult32(void) {
    return OV013_SQRT_RESULT;
}

static inline s32 Ov013_Sqrt2(s64 sq) {
    CP_SetSqrt64((u64)(sq << 2));
    CP_WaitSqrt();
    return (s32)(CP_GetSqrtResult32() + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const Ov013Vec *a, const Ov013Vec *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    return Ov013_Sqrt2((s64)dx * dx + (s64)dz * dz);
}

void Ov013Act_02207968_Update(Ov013Act_02207968 *self) {
    Ov013Actor *pl;
    s32 dist;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_94_1 = 1;
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    if (self->unk_110 != 0) {
        self->unk_40->flags |= 4;
    }
    if (self->unk_111 == 0) {
        u16 pct = self->unk_50[0] * 100 / self->unk_50[1];
        if (pct <= 0x14 && pl != NULL && !func_ov000_021b4738(pl)) {
            Ov013Game54 *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(5);
            g = data_ov000_021ccd54;
            g->unk_ac = 1;
            func_ov000_02182590(&g->unk_ac);
            func_ov003_021ce9c4(FLD(u16, self->unk_b0, 4));
            {
                Ov013Sub44 *n = self->unk_44;
                n->unk_22_0 = 0;
                n->unk_22_1 = 0;
            }
            self->unk_50[2] = 0xffff;
            self->unk_111 = 1;
        }
    }
    if (self->unk_40->unk_13 != 1 || self->unk_f0 != 0) {
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
        Ov013Actor *t = Actor_GetTarget(self);
        if (t != NULL) {
            s32 dz = self->pos.z - t->pos.z;
            s32 dx = self->pos.x - t->pos.x;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            dist = Ov013_Sqrt2(sq);
        }
    }
    if (dist < 0x6800 && !func_ov000_021983b0(self->unk_40, 2, 2, 1)) {
        self->unk_40->flags |= 4;
        self->unk_b6 = 0x23;
        return;
    }
    self->unk_40->flags |= 1ull << func_ov013_02209b44(self);
    self->unk_b6 = 0x46;
}

void func_ov013_02207d00(Ov013Actor *self) {
    Ov013Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->rot[1] = 0;
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        break;
    case 1: {
        s32 d = 0x9000 - self->pos.y;
        if (d > 0x3000) {
            Ov013Vec v = {0, d, 0};
            VEC_MultAdd(0x52, &v, &self->pos, &self->pos);
            return;
        }
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        break;
    }
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

extern void *data_ov000_021ccd68;
extern void *ActorMgr_GetGroup(void *mgr, s32 a);
extern u16 ActorGroup_CountKind(void *p, s32 a);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void Actor_Move(Ov013Obj *self, s32 a);

void func_ov013_02207eac(Ov013Act_02207968 *self) {
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        self->unk_48->unk_30 = 0x40000000;
    }
    switch (self->unk_f0) {
    case 1:
        if (ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000), 0x4813) != 0) {
            return;
        }
        self->unk_40->flags |= 0x10000;
        self->unk_f0 = 0;
        return;
    case 2:
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0x19a;
        self->unk_f0 = 3;
        if (self->pos.y < 0x3000) {
            Ov013_VecSet(&self->unk_b8, self->pos.x, 0x3000, self->pos.z);
            self->unk_a0 = 0xcd;
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
            self->rot[0] = func_01ffc128(0, self->rot[0], 0xcd, 1, 0x8000);
        }
        {
            Ov013Sub40 *st = self->unk_40;
            st->timer++;
            if (st->timer <= 0x14) {
                return;
            }
        }
        self->unk_a0 = 0x334;
        self->unk_f0 = 4;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0xe4, 0);
        return;
    }
    case 4:
        Actor_Move(self, 0);
        self->rot[0] = func_01ffc128(0, self->rot[0], 0xcd, 1, 0x8000);
        if (self->pos.y >= 0x9000) {
            self->pos.y = 0x9000;
            self->unk_f0 = 0;
            self->unk_40->state = 0;
        }
        return;
    }
}

extern Ov013Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov013Vec func_ov003_021dadc0(const Ov013Vec *a, const Ov013Vec *b);
extern void Actor_TurnToActor(Ov013Actor *self, Ov013Actor *target, s32 a);
extern void Actor_MoveToPos(Ov013Actor *self, Ov013Vec *v, s32 a);
extern Ov013Vec data_ov013_0220b3b0;

static inline Ov013Actor *Ov013_GetActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov013_VecCopyR(Ov013Vec *d, const Ov013Vec &s) {
    d->x = s.x;
    d->y = s.y;
    d->z = s.z;
}

static inline Ov013Vec Ov013_ApproachPoint(Ov013Actor *self) {
    Ov013Vec res;
    Ov013Actor *t;
    res.x = 0;
    res.y = 0;
    res.z = 0;
    t = Ov013_GetActor(self->unk_90);
    if (t == NULL) {
        return res;
    }
    {
        Ov013Vec tp;
        Ov013Vec dir;
        Ov013_VecCopy(&tp, &t->pos);
        Ov013_VecCopyR(&dir, func_ov003_021dadc0(&tp, &self->pos));
        VEC_MultAdd(0x7800, &dir, &tp, &res);
    }
    return res;
}

static inline s32 Ov013_DistXZ3(const Ov013Vec *a, const Ov013Vec *b) {
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt2(sq);
}

static inline s32 Ov013_DistXZc(s32 x, s32 z, const Ov013Vec *b) {
    s32 dz = z - b->z;
    s32 dx = x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt2(sq);
}

void func_ov013_022080bc(Ov013Act_02207968 *self) {
    Ov013Actor *t = Ov013_GetActor(self->unk_90);
    Ov013Vec tpos;
    Ov013Vec v;
    s32 d;
    if (t == NULL) {
        return;
    }
    tpos = t->pos;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        v = Ov013_ApproachPoint(self);
        self->unk_b8 = v;
        self->unk_9c = self->unk_b0->unk_00;
        self->unk_110 = 1;
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        self->unk_48->unk_30 = 0;
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
    }
    v = self->unk_b8;
    Actor_TurnToActor(self, t, self->unk_b0->unk_02);
    Actor_MoveToPos(self, &v, 0);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    if (Ov013_DistXZ3(&tpos, &self->pos) < 0x7800) {
        Ov013Vec dir = func_ov003_021dadc0(&tpos, &self->pos);
        VEC_MultAdd(0x7800, &dir, &tpos, &v);
        self->unk_b8 = v;
    }
    d = Ov013_DistXZc(-0x2d9a, -0x452, &self->pos);
    if (d > 0xf000) {
        Ov013Vec dir = func_ov003_021dadc0(&self->pos, &data_ov013_0220b3b0);
        VEC_MultAdd(d - 0xf000, &dir, &data_ov013_0220b3b0, &v);
        self->unk_b8 = v;
    }
    if (Ov013_DistXZ3(&v, &self->pos) != 0) {
        Ov013Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x78) {
            return;
        }
    }
    func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x19a, 0);
    func_ov000_021915a0(self->unk_38);
    self->unk_110 = 0;
    func_ov000_02198360(self->unk_40, 1, 0);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
}

extern char data_ov013_0220be82[];
extern s32 FX_Div(s32 a, s32 b);
extern BOOL func_01ffc584(const Ov013Vec *a, const Ov013Vec *b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_ov000_02191318(void *a, s32 b);
extern void Actor_TurnToPos(Ov013Actor *self, Ov013Vec *p, s32 a);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);

static inline Ov013Vec Ov013_ApproachPointK(Ov013Actor *self, s32 k) {
    Ov013Vec res;
    Ov013Actor *t;
    res.x = 0;
    res.y = 0;
    res.z = 0;
    t = Ov013_GetActor(self->unk_90);
    if (t == NULL) {
        return res;
    }
    {
        Ov013Vec tp;
        Ov013Vec dir;
        Ov013_VecCopy(&tp, &t->pos);
        Ov013_VecCopyR(&dir, func_ov003_021dadc0(&tp, &self->pos));
        VEC_MultAdd(k, &dir, &tp, &res);
    }
    return res;
}

void func_ov013_02208500(Ov013Act_02207968 *self) {
    Ov013Actor *t = Ov013_GetActor(self->unk_90);
    Ov013Vec v;
    if (t == NULL) {
        return;
    }
    v = self->unk_b8;
    switch (self->unk_40->state) {
    case 0: {
        Ov013Vec tp;
        self->unk_f1 = 0xf;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be82, 0x2ab, 0);
        tp = t->pos;
        {
            Ov013Vec dir = func_ov003_021dadc0(&tp, &self->pos);
            VEC_MultAdd(0xc000, &dir, &tp, &v);
        }
        v.y = 0x5800;
        self->unk_b8 = v;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = FX_Div(Ov013_DistXZ3(&self->pos, &v), 0x3c000);
        self->unk_a0 = -0xcd;
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        self->unk_40->state = 2;
        self->unk_40->timer = 0;
        break;
    }
    case 2: {
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        Actor_MoveToPos(self, &v, 0);
        if (self->pos.y < 0x5800) {
            self->pos.y = 0x5800;
        }
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        v = Ov013_ApproachPointK(self, -0x4000);
        if (!func_01ffc584(&v, &data_ov013_0220b3b0, 0x7000, 0x2800) || func_01ffc584(&v, &data_ov013_0220b3b0, 0x5800, 0x2800)) {
            Ov013Vec dir = func_ov003_021dadc0(&data_ov013_0220b3b0, &v);
            VEC_MultAdd(0x7000, &dir, &data_ov013_0220b3b0, &v);
        }
        {
        Ov013Vec tp;
        tp = t->pos;
        {
        Ov013Vec a = func_ov003_021dadc0(&self->pos, &tp);
        Ov013Vec b = func_ov003_021dadc0(&data_ov013_0220b3b0, &tp);
        if ((s32)(((s64)a.x * b.x + (s64)a.y * b.y + (s64)a.z * b.z + 0x800) >> 12) < 0x19a) {
            VEC_MultAdd(0x7000, &a, &data_ov013_0220b3b0, &v);
        }
        }
        }
        v.y = 0x5800;
        self->unk_b8 = v;
        self->unk_9c = 0x266;
        self->unk_a0 = -0x52;
        self->unk_a4 = 0x1052;
        self->unk_a8 = 0x29;
        self->unk_40->state = 3;
        self->unk_40->timer = 0;
        break;
    }
    case 3: {
        Ov013Vec p;
        Ov013Vec d;
        Actor_MoveToPos(self, &v, 0);
        if (self->pos.y < 0x5800) {
            self->pos.y = 0x5800;
            self->unk_a0 = 0;
        }
        Ov013_VecCopyR(&d, func_ov003_021dadc0(&data_ov013_0220b3b0, &v));
        VEC_MultAdd(0xf000, &d, &data_ov013_0220b3b0, &p);
        Actor_TurnToPos(self, &p, 0x400);
        if (self->unk_38->unk_c4 == 3) {
            func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        }
        if (self->unk_38->unk_c4 != 2) {
            return;
        }
        self->unk_94_1 = 0;
        self->unk_a0 = -0x15;
        v.y = 0x1b33;
        self->unk_b8 = v;
        self->unk_40->state = 4;
        self->unk_40->timer = 0;
        self->unk_92 = 0;
        break;
    }
    case 4: {
        Ov013Vec p;
        Ov013Vec d;
        self->unk_94_1 = 0;
        self->rot[0] = func_01ffc128(0x271c, self->rot[0], 0xcd, 1, 0x8000);
        Ov013_VecCopyR(&d, func_ov003_021dadc0(&data_ov013_0220b3b0, &self->pos));
        VEC_MultAdd(0x5000, &d, &self->pos, &p);
        Actor_TurnToPos(self, &p, 0x400);
        if (self->pos.y <= 0x1b33) {
            self->pos.y = 0x1b33;
        } else {
            self->pos.y += self->unk_a0;
            self->unk_a0 -= self->unk_a8;
            if (self->unk_a0 < -0x800) {
                self->unk_a0 = -0x800;
            }
            if (self->pos.y < 0x1b33) {
                self->pos.y = 0x1b33;
                func_ov000_0218996c(5, 0x1e);
                func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            }
        }
        {
            Ov013Sub40 *st = self->unk_40;
            st->timer++;
            if (st->timer <= 0xfa) {
                return;
            }
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be82, 0x155, 0);
        func_ov000_02191318(self->unk_38, 0x96000);
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        self->unk_f0 = 2;
        func_ov000_02198360(self->unk_40, 1, 0);
        self->unk_40->state = 7;
        break;
    }
    }
}

struct Ov013Blk12 {
    s32 w[3];
};

extern char data_ov013_0220be8e[];
extern Ov013Vec data_ov013_0220b398;
extern Ov013Vec data_ov013_0220b38c;
extern Ov013Vec data_ov013_0220b380;
extern void func_ov000_0219a210(Ov013Vec *p, Ov013Vec *o, u16 rot);
extern Ov013Actor *func_ov000_0219be1c(s32 kind, Ov013Vec *pos, u16 *rot, u16 id, u16 owner);
extern void func_ov000_0219bebc(Ov013Obj *a, s32 b);
extern u8 *func_0206fef8(u16 kind);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);

void func_ov013_02208bfc(Ov013Act_02207968 *self) {
    Ov013Actor *t = Ov013_GetActor(self->unk_90);
    Ov013Sub40 *st;
    if (t == NULL) {
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov013Vec *pt;
        self->unk_f1 = 0xe;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be8e, 0x2ab, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00;
        pt = &self->unk_f8;
        pt->x = t->pos.x;
        pt->y = t->pos.y;
        pt->z = t->pos.z;
        if (pt->y > 0x2000) {
            pt->y = 0x2000;
        }
        if (!func_01ffc584(pt, &data_ov013_0220b3b0, 0x6000, 0x2800)) {
            Ov013Vec dir = func_ov003_021dadc0(&data_ov013_0220b3b0, pt);
            VEC_MultAdd(0x5800, &dir, &data_ov013_0220b3b0, pt);
        }
        if (Ov013_DistXZ3(&self->pos, pt) < 0x5000) {
            Ov013Vec d;
            Ov013Vec q;
            Ov013_VecCopyR(&d, func_ov003_021dadc0(pt, &self->pos));
            VEC_MultAdd(0x5000, &d, pt, &q);
            Ov013_VecCopy(&self->unk_b8, &q);
            self->unk_48->unk_30 = 0;
        } else {
            self->unk_b8 = self->pos;
        }
        self->unk_40->state = 2;
        self->unk_40->timer = 0;
        break;
    }
    case 2: {
        Ov013Vec v;
        Actor_TurnToPos(self, &self->unk_f8, 0x400);
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        self->unk_40->state = 3;
        self->unk_40->timer = 0;
        break;
    }
    case 3: {
        Ov013Vec p;
        Ov013ActEx_0220a4e0 *a;
        u16 id;
        if (self->unk_38->unk_c4 != 2) {
            return;
        }
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
        func_ov000_0219a210(&p, &data_ov013_0220b398, self->rot[1]);
        a = (Ov013ActEx_0220a4e0 *)func_ov000_0219be1c(0x4811, &p, self->rot, self->id, self->unk_90);
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
        self->unk_40->state = 4;
        self->unk_40->timer = 0;
        break;
    }
    case 4:
        if (st->timer == 0) {
            Ov013Vec p;
            Ov013V *e;
            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
            func_ov000_0219a210(&p, &data_ov013_0220b38c, self->rot[1]);
            e = func_02065f88(0x12c, &p);
            e->v10(&data_ov013_0220b380);
            e->v34(0, self->rot[1], 0);
            self->unk_40->timer++;
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        break;
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

void func_ov013_022090ac(Ov013Act_02207968 *self) {
    Ov013Actor *t = Ov013_GetActor(self->unk_90);
    Ov013Sub40 *st;
    if (t == NULL) {
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov013Vec *pt;
        self->unk_f1 = 0xe;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be8e, 0x2ab, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00;
        pt = &self->unk_f8;
        if (self->unk_f2 == 0) {
            Ov013_VecCopyYZ(pt, &t->pos);
            if (pt->y > 0x2000) {
                pt->y = 0x2000;
            }
            if (Ov013_DistXZ3(pt, &self->pos) < 0x5000) {
                Ov013Vec d = func_ov003_021dadc0(pt, &self->pos);
                Ov013Vec q;
                VEC_MultAdd(0x5000, &d, pt, &q);
                Ov013_VecCopy(&self->unk_b8, &q);
                self->unk_48->unk_30 = 0;
            }
            Ov013_VecCopyR(&self->unk_104, func_ov003_021dadc0(&self->pos, pt));
        } else {
            Ov013Vec w;
            s32 k;
            if (self->unk_f2 == 1) {
                Ov013_VecSet(&w, Ov013_FxMul(self->unk_104.z, 0x1000), 0, (s32)((0x800 - (s64)self->unk_104.x * 0x1000) >> 12));
                k = 0x3000;
            } else {
                Ov013_VecSet(&w, (s32)((0x800 - (s64)self->unk_104.z * 0x1000) >> 12), 0, Ov013_FxMul(self->unk_104.x, 0x1000));
                k = 0x6000;
            }
            VEC_MultAdd(k, &w, pt, pt);
            if (!func_01ffc584(pt, &data_ov013_0220b3b0, 0x6000, 0x2800)) {
                Ov013Vec dir = func_ov003_021dadc0(&data_ov013_0220b3b0, pt);
                VEC_MultAdd(0x5800, &dir, &data_ov013_0220b3b0, pt);
            }
        }
        self->unk_40->state = 2;
        self->unk_40->timer = 0;
        break;
    }
    case 2: {
        Ov013Vec v;
        Actor_TurnToPos(self, &self->unk_f8, 0x400);
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        self->unk_40->state = 3;
        self->unk_40->timer = 0;
        break;
    }
    case 3: {
        Ov013Vec p;
        Ov013ActEx_0220a4e0 *a;
        u16 id;
        if (self->unk_38->unk_c4 != 2) {
            return;
        }
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        p = self->pos;
        func_ov000_0219a210(&p, &data_ov013_0220b398, self->rot[1]);
        a = (Ov013ActEx_0220a4e0 *)func_ov000_0219be1c(0x4811, &p, self->rot, self->id, self->unk_90);
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
        self->unk_40->state = 4;
        self->unk_40->timer = 0;
        break;
    }
    case 4:
        if (st->timer == 0) {
            Ov013Vec p;
            Ov013V *e;
            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
            func_ov000_0219a210(&p, &data_ov013_0220b38c, self->rot[1]);
            e = func_02065f88(0x12c, &p);
            e->v10(&data_ov013_0220b380);
            e->v34(0, self->rot[1], 0);
            self->unk_40->timer++;
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        break;
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        if (self->unk_f2 < 3) {
            self->unk_40->state = 0;
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_f2 = 0;
        break;
    }
}

}
