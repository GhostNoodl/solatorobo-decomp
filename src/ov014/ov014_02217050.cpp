#include "ov014/ov014.h"
#include "nitro/mi.h"


// A header's zero rotation and vector, plus copies made at startup, with this TU's offset
// between them. Other functions read all three constants.
// The functions of 0x022054f8..0x02206050 (four files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the zero vector through the .rodata base plus an
// offset, and name it (data_ov014_022169d4) instead of an FLD view of data_ov014_022169c0.
// The readers of 0x02206050..0x022083a4 (four files) joined in round dtD.
extern const VecFx16 data_ov014_022169c0;
extern const VecFx32 data_ov014_022169c8;
extern const VecFx32 data_ov014_022169d4;
const VecFx16 data_ov014_022169c0 = {0, 0, 0};
const VecFx32 data_ov014_022169c8 = {0, 0x333, 0};
static const VecFx16 data_ov014_0221762c = data_ov014_022169c0;
const VecFx32 data_ov014_022169d4 = {0, 0, 0};
static const VecFx32 data_ov014_02217634 = data_ov014_022169d4;

// ---- merged from ov014_022054f8.cpp
namespace m_022054f8 {
extern "C" {

extern void func_0203f364(ActorSub48 *p);
extern BOOL Target_Get(void *p);

void func_ov014_022054f8(void) {
}

void Ov014ActExGrow_Start(Ov014ActExGrow *self) {
    Model0218fe1c *m;
    func_ov000_02194758(self);
    self->flags = 0;
    self->cur_scale = 0;
    self->timer = 0;
    {
        ActorSub48 *s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    self->hit->unk_30 = 0;
    {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    m = self->model;
    Ov014_VecCopyYZ(&self->scale, &m->scale);
    m->scale = data_ov014_022169d4;
    func_ov000_02198360(self->fsm, 1, 0);
}

void func_ov014_022055ac(Ov014ActExGrow *self) {
    Model0218fe1c *m;
    s32 s;
    if (!Target_Get(self->targetObj)) {
        self->flags |= 0x1000;
        func_ov000_02198360(self->fsm, 0x15, 0);
        return;
    }
    if (self->fsm->st != 0) {
        return;
    }
    if (self->cur_scale < self->scale.x) {
        self->cur_scale += 0xcd;
    } else {
        self->cur_scale = self->scale.x;
        func_ov000_02198360(self->fsm, 0xb, 0);
    }
    m = self->model;
    s = self->cur_scale;
    m->scale.x = s;
    m->scale.y = s;
    m->scale.z = s;
}

}
}  // namespace m_022054f8

// ---- merged from ov014_02205634.cpp
namespace m_02205634 {
extern "C" {

extern void func_ov014_02205d70(Ov014ActExGrow *self);

extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void func_0203f364(ActorSub48 *p);
extern void func_ov014_02205924(Ov014ActExGrow *self);
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)

// Like the SDK's CP_SetSqrt64: the parameter is written through a plain (non-volatile)
// u64 pointer, so the scheduler may still move other stores around it.
static inline void Ov014_SetSqrt64(u64 param) {
    OV014_SQRTCNT = 1;
    *(u64 *)0x40002b8 = param;
}

static inline s32 Ov014g_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_02205634(Ov014ActExGrow *self) {
    Ov003Actor *t = Target_Get(self->targetObj);
    if (t != NULL) {
        {
            ActorSub48 *m = t->hit;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
        }
        if (t->kind == 0x1000) {
            func_ov014_02205924(self);
            return;
        }
        switch (self->fsm->st) {
        case 0: {
            Ov003Actor *g;
            s32 r;
            u16 a;
            EffectObj *e;
            {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
            }
            g = Actor_GetTarget(self);
            {
                s64 sq;
                s32 dx;
                s32 dz;
                VecFx32 p;
                Ov014_VecCopyYZ(&p, &g->pos);
                dx = self->pos.x - p.x; dz = self->pos.z - p.z; sq = (s64)dx * dx; sq += (s64)dz * dz;
                self->unk_84.x = p.x;
                self->unk_84.y = p.y + 0x1000;
                self->unk_84.z = p.z;
                Ov014_SetSqrt64((u64)(sq * 4));
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->speed = Ov014g_FxMul64(OV014_SIN(a), 0x666);
            self->velY = Ov014g_FxMul64(OV014_COS(a), 0x666);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            e = func_02065f88(0x68, &self->pos);
            e->SetScaleAll(0xb33);
            e->SetRotXYZ(0xbfff, self->rot_y, 0);
            func_02065f88(0x6b, &self->pos);
            func_0204a028(data_02097e4c, 0x35, &self->pos, 5);
            {
                ActorSub48 *m = self->hit;
                m->unk_50 = 0;
                m->unk_54 = 0;
                m->unk_58 = 0;
            }
            self->timer = 0;
            self->fsm->st++;
            break;
        }
        case 1:
            if (self->pos.y - self->unk_84.y > 0x1000) {
                Actor_TurnToPos(self, &self->unk_84, 0x266);
                self->moveYaw = self->rot_y;
            }
            Actor_Move(self, 0);
            func_ov014_02205d70(self);
            if ((self->hit->unk_50 & 0x20000000) || ++self->timer >= 100) {
                self->flags |= 0x1000;
                func_ov000_02198360(self->fsm, 0x15, 0);
            }
            break;
        }
    } else {
        self->flags |= 0x1000;
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}

}
}  // namespace m_02205634

// ---- merged from ov014_02205924.cpp
namespace m_02205924 {
extern "C" {

extern void func_ov014_02205d70(Ov014ActExGrow *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02205924(Ov014ActExGrow *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            self->unk_84.x = d.x;
            self->unk_84.y = d.y;
            self->unk_84.z = d.z;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = FX_Mul(d.x, 0x59a);
            self->velY = FX_Mul(d.y, 0x59a);
            self->friction = FX_Mul(d.z, 0x59a);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            self->flags |= 0x200000;
        } else {
            self->speed = 0x4cd;
            self->moveYaw = self->rot_y;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->flags & 0x200000) {
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        } else {
            Actor_Move(self, 0);
        }
        func_ov014_02205d70(self);
        if ((self->hit->unk_50 & 0x20000000) || ++self->timer >= 100) {
            self->flags |= 0x1000;
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
}

}
}  // namespace m_02205924

// ---- merged from ov014_02205c1c.cpp
namespace m_02205c1c {
extern "C" {

extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(ActorSub48 *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov003Actor *Target_Get(void *p);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);

void func_ov014_02205c1c(Ov014ActExGrow *self) {
    self->flags |= 0x1000;
    func_ov000_02198360(self->fsm, 0x15, 0);
}

void func_ov014_02205c40(Ov014ActExGrow *self) {
    switch (self->fsm->st) {
    case 0:
        if (self->unk_44 != NULL) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *m;
            func_ov000_02198c8c(self->hit, 0xffff);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->model->visible = 0;
        if (self->flags & 0x1000) {
            func_02065f88(0x38f, &self->pos);
        } else {
            func_02065f88(4, &self->pos);
        }
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        self->fsm->st++;
        break;
    case 1:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        break;
    }
}

void func_ov014_02205d70(Ov014ActExGrow *self) {
    Ov003Actor *list[0x20];
    s32 r;
    s32 n;
    u16 k;
    s32 i;
    r = self->radius + 0x4cd;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->hit->unk_44 = r;
    k = Target_Get(self->targetObj)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov003Actor *q;
        if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
            ActorSub4c *s = q->targetObj;
            if (s == NULL || k != (u16)(s->target & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                self->flags |= 0x1000;
                func_ov000_02198360(self->fsm, 0x15, 0);
                return;
            }
        }
    }
}

void Ov014ActExVt_02217838_Start(Ov014ActExVt_02217838 *self) {
    Model0218fe1c *m;
    func_ov000_02194758(self);
    self->flags = 0;
    self->cur_scale = 0;
    self->timer = 0;
    {
        ActorSub48 *s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    self->hit->unk_30 = 0;
    {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    m = self->model;
    Ov014_VecCopyYZ(&self->scale, &m->scale);
    m->scale = data_ov014_022169d4;
    func_ov000_02198360(self->fsm, 1, 0);
}

static inline void Ov014_SetScale(Ov014ActExVt_02217838 *self) {
    Model0218fe1c *m = self->model;
    s32 s = self->cur_scale;
    m->scale.x = s;
    m->scale.y = s;
    m->scale.z = s;
}

void func_ov014_02205f2c(Ov014ActExVt_02217838 *self) {
    if (!Target_Get(self->targetObj)) {
        self->flags |= 0x1000;
        func_ov000_02198360(self->fsm, 0x15, 0);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        if (self->cur_scale < self->scale.x + 0x1000) {
            self->cur_scale += 0xcd;
        } else {
            self->fx = func_02065f88(0x648, &self->pos)->id;
            self->fsm->st++;
        }
        Ov014_SetScale(self);
        break;
    case 1:
        if (self->cur_scale <= self->scale.x) {
            self->cur_scale = self->scale.x;
            self->fsm->st++;
        } else {
            self->cur_scale -= 0xcd;
        }
        Ov014_SetScale(self);
        break;
    case 2:
        if (!func_020657b0(data_0214a420, self->fx)) {
            func_ov000_02198360(self->fsm, 0xb, 0);
        }
        break;
    }
}

}
}  // namespace m_02205c1c

// ---- merged from ov014_02206050.cpp
namespace m_02206050 {
extern "C" {

extern VecFx32 data_ov014_022169ec;
extern void func_0203f364(ActorSub48 *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void func_01ffc9fc(VecFx32 *a, VecFx32 *b, u16 ang);
extern void func_ov014_02206b5c(Ov014ActExVt_02217838 *self);
extern void func_ov014_02206734(Ov014ActExVt_02217838 *self);

#define OV014F_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014F_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014F_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02206050(Ov014ActExVt_02217838 *self) {
    Ov003Actor *t = Target_Get(self->targetObj);
    Ov003Actor *pl;
    if (t != NULL) {
    {
        ActorSub48 *m = t->hit;
        if (m != NULL && m->unk_9a_3) {
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    }
    if (t->kind == 0x1000) {
        func_ov014_02206734(self);
        return;
    }
    pl = Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        e = func_02065f88(0x68, &self->pos);
        e->SetScaleAll(0xb33);
        e->SetRotXYZ(0xbfff, self->rot_y, 0);
        func_02065f88(0x579, &self->pos)->SetScaleAll(0x2000);
        func_0204a028(data_02097e4c, 0x32, &self->pos, 0xa);
        self->fsm->st++;
        break;
    }
    case 1: {
        EffectObj *e;
        s32 r;
        VecFx32 v = data_ov014_022169ec;
        v.y = (0x47000 - self->pos.y) / 6;
        func_01ffc9fc(&v, &v, self->rot_y);
        VEC_Add(&self->pos, &v, &v);
        self->unk_84.x = v.x;
        self->unk_84.y = v.y;
        self->unk_84.z = v.z;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        {
            s64 sq;
            s32 dx;
            s32 dz;
            dx = self->pos.x - self->unk_84.x;
            dz = self->pos.z - self->unk_84.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV014F_SQRTCNT = 1;
            OV014F_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014F_SQRTCNT & 0x8000) {
        }
        self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, (s32)(OV014F_SQRT_RESULT + 1) >> 1);
        func_02065f88(0x192, &self->pos)->SetRot(&self->rot);
        e = func_02065f88(0x68, &self->pos);
        e->SetScaleAll(0xb33);
        e->SetRotXYZ((u16)(self->rot_x + 0xbfff), self->rot_y, 0);
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->fsm->st++;
        break;
    }
    case 2: {
        VecFx32 d;
        ActorSub40 *s;
        d.x = self->unk_84.x - self->pos.x;
        d.y = self->unk_84.y - self->pos.y;
        d.z = self->unk_84.z - self->pos.z;
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        func_ov014_02206b5c(self);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        s = self->fsm;
        s->timer++;
        if (s->timer <= 0x1e) {
            return;
        }
        self->speed = 0xf6;
        self->velY = -0x52;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 3: {
        ActorSub40 *s;
        Actor_TurnToActor(self, pl, 0x19a);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        s = self->fsm;
        s->timer++;
        if (s->timer > 0x1e) {
            self->fsm->timer = 0;
            self->fsm->st = 1;
        }
        if (self->pos.y > 0x4b000) {
            return;
        }
        {
            EffectObj *e = func_02065f88(0x69, &self->pos);
            e->SetScaleAll(0x800);
            self->fx = e->id;
        }
        self->fsm->timer = 0;
        self->fsm->st = 10;
        break;
    }
    case 10: {
        Ov003Actor *o;
        EffectObj *e;
        s32 r;
        u16 ang;
        Actor_TurnToActor(self, pl, 0x400);
        if (func_020657b0(data_0214a420, self->fx)) {
            return;
        }
        o = Actor_GetTarget(self);
        {
            s64 sq;
            s32 dx;
            s32 dz;
            VecFx32 p;
            Ov014_VecCopyYZ(&p, &o->pos);
            dx = self->pos.x - p.x;
            dz = self->pos.z - p.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            self->unk_84.y = 0x48000;
            self->unk_84.z = p.z;
            self->unk_84.x = p.x;
            OV014F_SQRTCNT = 1;
            OV014F_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014F_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV014F_SQRT_RESULT + 1) >> 1;
        ang = FX_Atan2(r, self->unk_84.y - self->pos.y);
        self->speed = (s32)(((s64)OV014_SIN(ang) * (s64)0x4cd + 0x800) >> 12);
        self->velY = (s32)(((s64)OV014_COS(ang) * (s64)0x4cd + 0x800) >> 12);
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
        func_02065f88(0x192, &self->pos)->SetRot(&self->rot);
        e = func_02065f88(0x68, &self->pos);
        e->SetScaleAll(0xb33);
        e->SetRotXYZ((u16)(self->rot_x + 0xbfff), self->rot_y, 0);
        self->timer = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 11:
        if (self->pos.y - self->unk_84.y > 0x1000) {
            Actor_TurnToPos(self, &self->unk_84, 0x266);
            self->moveYaw = self->rot_y;
        }
        Actor_Move(self, 0);
        func_ov014_02206b5c(self);
        if (!(self->hit->unk_50 & 0x20000000)) {
            if (++self->timer < 100) {
                return;
            }
        }
        self->flags |= 0x1000;
        func_ov000_02198360(self->fsm, 0x15, 0);
        break;
    }
    } else {
        self->flags |= 0x1000;
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}

}
}  // namespace m_02206050

// ---- merged from ov014_02206734.cpp
namespace m_02206734 {
extern "C" {

extern void func_ov014_02206b5c(Ov014ActExVt_02217838 *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02206734(Ov014ActExVt_02217838 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            self->unk_84.x = d.x;
            self->unk_84.y = d.y;
            self->unk_84.z = d.z;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = FX_Mul(d.x, 0x59a);
            self->velY = FX_Mul(d.y, 0x59a);
            self->friction = FX_Mul(d.z, 0x59a);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            self->flags |= 0x200000;
        } else {
            self->speed = 0x4cd;
            self->moveYaw = self->rot_y;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->flags & 0x200000) {
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        } else {
            Actor_Move(self, 0);
        }
        func_ov014_02206b5c(self);
        if ((self->hit->unk_50 & 0x20000000) || ++self->timer >= 100) {
            self->flags |= 0x1000;
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
}

}
}  // namespace m_02206734

// ---- merged from ov014_02206a2c.cpp
namespace m_02206a2c {
extern "C" {

extern u8 data_ov014_02217670[];
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(ActorSub48 *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov003Actor *Target_Get(void *p);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);
extern char data_ov014_02217640[];
extern char data_ov014_0221764f[];

void func_ov014_02206a2c(Ov014ActExVt_02217838 *self) {
    self->flags |= 0x1000;
    func_ov000_02198360(self->fsm, 0x15, 0);
}

void func_ov014_02206a50(Ov014ActExVt_02217838 *self) {
    if (self->flags & 0x1000) {
        func_ov000_0219763c(self);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        if (self->unk_44 != NULL) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *m;
            func_ov000_02198c8c(self->hit, 0xffff);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->model->visible = 0;
        func_02065f88(4, &self->pos);
        self->fsm->st++;
        break;
    case 1:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        break;
    }
}

void func_ov014_02206b5c(Ov014ActExVt_02217838 *self) {
    Ov003Actor *list[0x20];
    s32 r;
    s32 n;
    u16 k;
    s32 i;
    r = self->radius + 0x4cd;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->hit->unk_44 = r;
    k = Target_Get(self->targetObj)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov003Actor *q;
        if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
            ActorSub4c *s = q->targetObj;
            if (s == NULL || k != (u16)(s->target & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                self->flags |= 0x1000;
                func_ov000_02198360(self->fsm, 0x15, 0);
                return;
            }
        }
    }
}

#pragma force_active on
Ov014ActEx_02206c68 *Ov014ActEx_02206c68_Ctor(Ov014ActEx_02206c68 *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov014_02217670;
    self->unk_d0 = 0;
    self->unk_dc = NULL;
    self->unk_d8 = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeDC(Ov014ActEx_02206c68 *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_dc != NULL) {
        Ov003FxList *p = self->unk_dc;
        if (p != NULL) {
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        self->unk_dc = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014ActEx_02206c68 *Ov014ActEx_02206c68_Dtor(Ov014ActEx_02206c68 *self) {
    *(void **)self = data_ov014_02217670;
    Ov014_FreeDC(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_02206c68 *Ov014ActEx_02206c68_DtorDelete(Ov014ActEx_02206c68 *self) {
    *(void **)self = data_ov014_02217670;
    Ov014_FreeDC(self);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_02206c68_Start(Ov014ActEx_02206c68 *self) {
    func_ov000_02194758(self);
    self->unk_dc = Ov014_NewFx();
    self->unk_d4 = 0;
    func_ov000_02198360(self->fsm, 0x20, 0);
}

void Ov014ActEx_02206c68_Update(Ov014ActEx_02206c68 *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(self->unk_dc);
}

void func_ov014_02206dd4(Ov014ActEx_02206c68 *self) {
    switch (self->fsm->st) {
    case 0: {
        EffectObj *a;
        EffectObj *e;
        self->pos.y += 0x19a;
        a = func_02065f88(0x646, &self->pos);
        a->SetScaleAll(0x1800);
        func_ov003_021da9ac(self->unk_dc, 0xfd, a);
        e = Effect3D_Create(data_ov014_02217640, data_ov014_0221764f, 0, &self->pos);
        e->SetScale(&data_ov014_022169d4);
        e->AddPos(&data_ov014_022169c8);
        e->unk_28 = 0;
        e->loopCount = -1;
        func_ov003_021da9ac(self->unk_dc, 0xff, e);
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->unk_d4 < 0x2000) {
            EffectObj *o;
            self->unk_d4 += 0xcd;
            if (self->unk_d4 >= 0x2000) {
                self->unk_d4 = 0x2000;
            }
            o = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_dc, 0xff));
            if (o != NULL) {
                o->SetScaleAll(self->unk_d4);
            }
        } else if (!Ov003FxList_Has(self->unk_dc, 0xfd)) {
            func_ov000_02198360(self->fsm, 0xb, 0);
        }
        break;
    }
}

struct Ov014HitArg {
    u8 a;
    u8 pad;
    u16 b;
    u16 c;
};

struct Ov014HitBox {
    VecFx32 min;
    VecFx32 max;
    u16 rot[3];
    u16 unk_1e;
    u32 unk_20;
    VecFx32 v;
    s32 unk_30;
};

struct Ov014PlFlags {
    u32 b0 : 1;
    u32 b1 : 1;
};

#define OV014_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern void Actor_MoveToPos(Actor *self, VecFx32 *v, s32 a);
extern u8 *func_ov000_0219bf90(void);
extern BOOL func_01ffc318(VecFx32 *a, VecFx32 *pos, VecFx32 *min, VecFx32 *max, u16 *rot);
extern void func_ov000_0219b808(u16 id, VecFx32 *pos, Ov014HitBox *box, s32 a, s32 b);
extern VecFx32 data_ov014_02216a34;
extern VecFx32 data_ov014_02216a28;
extern Ov003Actor *Actor_GetTarget(Actor *self);

static inline void Ov014i_HitFrom(Actor *self, Ov014HitBox *box, VecFx32 *d, VecFx32 *from, VecFx32 *at) {
    d->x = self->pos.x - from->x;
    d->y = self->pos.y - from->y;
    d->z = self->pos.z - from->z;
    d->y = 0;
    VEC_Normalize(d, d);
    box->v.x = d->x = OV014_FXMUL_K(d->x, 0x7b);
    box->v.y = d->y = OV014_FXMUL_K(d->y, 0x7b);
    box->v.z = d->z = OV014_FXMUL_K(d->z, 0x7b);
    box->unk_30 = -1;
    func_ov000_0219b808(self->id, at, box, 0, 0);
}

static inline BOOL Ov014i_AnyHit(Ov014ActEx_02206c68 *self, Ov003Actor **list) {
    s32 n = func_ov000_0219a510(self, 2, &self->pos, FX_Mul(self->unk_d4, 0xb33), 0x800, list);
    s32 i;
    if (n != 0) {
        for (i = 0; i < n; i++) {
            if (list[i] != NULL && func_ov000_021985c0(list[i]) != NULL) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void func_ov014_02206f40(Ov014ActEx_02206c68 *self) {
    Ov003Actor *list[0x20];
    VecFx32 p;
    VecFx32 sc;
    Ov014HitBox box;
    VecFx32 d;
    VecFx32 v2;
    Ov003Actor *t;
    ActorSub40 *s;
    u8 *pl;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    s = self->fsm;
    switch (s->st) {
    case 0:
        self->unk_d8 = 0;
        s->st++;
        return;
    case 1:
        break;
    default:
        return;
    }
    p.x = t->pos.x;
    p.y = t->pos.y;
    p.z = t->pos.z;
    if (t->hp[0] != 0) {
        if (Ov014i_AnyHit(self, list) && t != NULL) {
            Ov014HitArg arg;
            arg.b = 0x666;
            arg.a = 1;
            arg.c = 1;
            Actor_SendMsg(t, self->id, 0xb, 1, 6, &arg);
            p.y += 0x1800;
            if (!Ov003FxList_Has(self->unk_dc, 0xfe)) {
                EffectObj *e = func_02065f88(0xcb, &p);
                e->SetRotXYZ(0, 0, 0x7fff);
                e->SetScaleAll(0x800);
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                func_0204a028(data_02097e4c, 0x11, &self->pos, -10);
                func_ov003_021da9ac(self->unk_dc, 0xfe, e);
            } else {
                func_ov003_021daae4(self->unk_dc, 0xfe, &p, 0, 0, 0, 0);
            }
        } else {
            Ov003FxList_Kill(self->unk_dc, 0xfe);
        }
    } else {
        func_ov000_02198360(s, 0x15, 0);
    }
    p.y = self->pos.y;
    self->speed = 0x52;
    Actor_MoveToPos(self, &p, 0);
    sc.x = self->unk_d4;
    sc.y = self->unk_d4;
    sc.z = self->unk_d4;
    func_ov003_021daae4(self->unk_dc, 0xff, &self->pos, &self->rot, &sc, &data_ov014_022169c8, 0);
    if (t->hp[0] != 0) {
        p = t->pos;
        box.unk_1e = 2;
        box.unk_20 = 0x20000000;
        box.rot[0] = self->rot_x;
        box.rot[1] = self->rot_y;
        box.rot[2] = self->rot_z;
        pl = func_ov000_0219bf90();
        if (pl != NULL && (((Robo021ca458 *)pl)->unk_b24_1 ? TRUE : FALSE) == TRUE) {
            box.min.x = -0xa000;
            box.min.y = -0x800;
            box.min.z = -0xa000;
            box.max.x = 0xa000;
            box.max.y = 0x800;
            box.max.z = 0xa000;
            Ov014i_HitFrom(self, &box, &d, &p, &self->pos);
        } else if (pl != NULL && (((Robo021ca458 *)pl)->unk_b24_1 ? TRUE : FALSE) == FALSE) {
            box.min.x = -0x1000;
            box.min.y = -0x800;
            box.min.z = -0x1000;
            box.max.x = 0x1000;
            box.max.y = 0x800;
            box.max.z = 0x1000;
            v2 = ((Robo021ca458 *)pl)->unk_75c;
            if (func_01ffc318(&v2, &self->pos, &data_ov014_02216a34, &data_ov014_02216a28, &self->rot_x)) {
                Ov014i_HitFrom(self, &box, &d, &v2, &v2);
            }
            if (func_01ffc318(&p, &self->pos, &data_ov014_02216a34, &data_ov014_02216a28, &self->rot_x)) {
                Ov014i_HitFrom(self, &box, &d, &p, &p);
            }
        }
    }
    self->unk_d8++;
    if (self->unk_d8 >= 300) {
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}

}
}  // namespace m_02206a2c

// ---- merged from ov014_0220774c.cpp
namespace m_0220774c {
extern "C" {

extern u8 data_ov014_022177a0[];
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);

void func_ov014_022075f4(Ov014ActEx_02206c68 *self) {
    // The const read keeps the state reload in case 1 (no CSE with the switch value).
    switch (ActorSub40_State(self->fsm)) {
    case 0:
        Ov003FxList_Kill(self->unk_dc, 0xfe);
        self->fsm->st++;
        break;
    case 1:
        if (self->unk_d4 > 0) {
            EffectObj *o;
            self->unk_d4 += -0x266;
            if (self->unk_d4 <= 0) {
                self->unk_d4 = 0;
            }
            o = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_dc, 0xff));
            if (o != NULL) {
                o->SetScaleXYZ(self->unk_d4, self->unk_d4, self->unk_d4);
            }
        } else {
            self->fsm->st++;
        }
        break;
    case 2: {
        u8 c;
        Ov003FxList_Kill(self->unk_dc, 0xff);
        c = 10;
        func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, &c);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        self->fsm->st++;
        break;
    }
    }
}

#pragma force_active on
Ov014ActEx_0220774c *Ov014ActEx_0220774c_Ctor(Ov014ActEx_0220774c *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov014_022177a0;
    self->unk_d0 = 0;
    self->unk_d8 = NULL;
    return self;
}
#pragma force_active reset

Ov014ActEx_0220774c *Ov014ActEx_0220774c_Dtor(Ov014ActEx_0220774c *self) {
    *(void **)self = data_ov014_022177a0;
    Ov014_FreeFx(&self->unk_d8);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_0220774c *Ov014ActEx_0220774c_DtorDelete(Ov014ActEx_0220774c *self) {
    *(void **)self = data_ov014_022177a0;
    Ov014_FreeFx(&self->unk_d8);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_0220774c_Start(Ov014ActEx_0220774c *self) {
    func_ov000_02194758(self);
    self->unk_d8 = Ov014_NewFx();
    self->unk_d4 = 0;
    func_ov000_02198360(self->fsm, 0xb, 0);
}

void Ov014ActEx_0220774c_Update(Ov014ActEx_0220774c *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(self->unk_d8);
}

#define OV014_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

struct Ov014HitBox {
    VecFx32 min;
    VecFx32 max;
    u16 rot[3];
    u16 unk_1e;
    u32 unk_20;
    VecFx32 v;
    s32 unk_30;
};

struct Ov014Swing {
    VecFx32 v;
    s32 unk_0c;
};

struct Ov014PlFlags {
    u32 b0 : 1;
    u32 b1 : 1;
};

extern Ov014Swing data_ov014_02216a40[];
extern char data_ov014_0221764f[];
extern char data_ov014_0221765b[];
extern char data_ov014_02217640[];
extern VecFx32 data_ov014_02216a1c;
extern VecFx32 data_ov014_022169e0;
extern VecFx32 data_ov014_02216a10;
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void *func_02049f44(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov014_0220840c(Ov014ActEx_0220774c *self);
extern u8 *func_ov000_0219bf90(void);
extern BOOL func_01ffc318(VecFx32 *a, VecFx32 *pos, VecFx32 *min, VecFx32 *max, u16 *rot);
extern void func_ov000_0219b808(u16 id, VecFx32 *pos, Ov014HitBox *box, s32 a, s32 b);

static inline void Ov014_HitFrom(Actor *self, Ov014HitBox *box, VecFx32 *d, VecFx32 *from, VecFx32 *at) {
    d->x = self->pos.x - from->x;
    d->y = self->pos.y - from->y;
    d->z = self->pos.z - from->z;
    d->y = 0;
    VEC_Normalize(d, d);
    box->v.x = d->x = OV014_FXMUL_K(d->x, 0x2b8);
    box->v.y = d->y = OV014_FXMUL_K(d->y, 0x2b8);
    box->v.z = d->z = OV014_FXMUL_K(d->z, 0x2b8);
    box->unk_30 = -1;
    func_ov000_0219b808(self->id, at, box, 0, 0);
}

void func_ov014_022078b4(Ov014ActEx_0220774c *self) {
    VecFx32 pos;
    Ov014HitBox box;
    VecFx32 d;
    VecFx32 v2;
    Ov014Swing *tbl;
    Ov003Actor *t;
    EffectObj *e;
    u8 *pl;
    u8 i;
    tbl = data_ov014_02216a40;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        FieldState *g;
        self->pos.y += 0x266;
        e = Effect3D_Create(data_ov014_02217640, data_ov014_0221764f, 0, &self->pos);
        e->SetScale(&data_ov014_022169d4);
        e->unk_28 = 0;
        e->AddPosXYZ(0, 0x19a, 0);
        e->loopCount = -1;
        func_ov003_021da9ac(self->unk_d8, 0xff, e);
        g = data_ov000_021ccd54;
        g->cam.base.shakeX = 1;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 1;
        g->cam.base.shakeTime = 7;
        g->cam.base.shakeLen = 10;
        g->cam.base.shakeCur = 10;
        g->cam.base.shakeRandom = 1;
        self->fsm->st++;
    }
    case 1: {
        s16 n = self->unk_18;
        if (self->unk_d4 < 0x9000) {
            self->unk_d4 += 0xf6;
            if (self->unk_d4 >= 0x9000) {
                self->unk_d4 = 0x9000;
            }
            e = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_d8, 0xff));
            if (e != NULL) {
                e->SetScaleAll(self->unk_d4);
            }
        } else if (n == 3) {
            self->fsm->st++;
        }
        if (!Ov003FxList_Has(self->unk_d8, 0xfd)) {
            e = func_02065f88(0x646, &self->pos);
            e->SetScaleAll(0x2000);
            func_ov003_021da9ac(self->unk_d8, 0xfd, e);
            n = n + 1;
            self->unk_18 = n;
            if (n == 3) {
                MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
                func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
            }
        }
        if (!Ov003FxList_Has(self->unk_d8, 0xf8)) {
            e = func_02065f88(0x68, &self->pos);
            e->SetScaleAll(0x8000);
            e->alpha = FX_Div(0x8000, 0x1f000);
            func_ov003_021da9ac(self->unk_d8, 0xf8, e);
        }
        break;
    }
    case 2:
        if (!Ov003FxList_Has(self->unk_d8, 0xfd)) {
            FieldState *g = data_ov000_021ccd54;
            g->cam.base.shakeRandom = 0;
            g->cam.base.shakeTime = 0;
            g->cam.base.shakeLen = 0;
            g->cam.base.shakeCur = 0;
            e = func_02065f88(0x391, &self->pos);
            e->AddPos(&data_ov014_02216a1c);
            e->SetScale(&data_ov014_022169d4);
            e->alpha = FX_Div(0x1d000, 0x1f000);
            func_ov003_021da9ac(self->unk_d8, 0xf9, e);
            self->fsm->st++;
        }
        break;
    case 3:
        if (self->unk_d4 > 0) {
            self->unk_d4 += -0xb33;
            if (self->unk_d4 <= 0) {
                self->unk_d4 = 0;
            }
            e = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_d8, 0xff));
            if (e != NULL) {
                e->SetScaleAll(self->unk_d4);
            }
            e = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_d8, 0xf9));
            if (e != NULL) {
                e->SetScaleAll(e->scale.x + 0x4cd);
            }
        } else {
            Ov003FxList_Kill(self->unk_d8, 0xfe);
            Ov003FxList_Kill(self->unk_d8, 0xff);
            self->fsm->st++;
        }
        break;
    case 4: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 5) {
            Ov003FxList_Kill(self->unk_d8, 0xf9);
            i = 0;
            e = Effect3D_Create(data_ov014_02217640, data_ov014_0221765b, (const char *)i, &self->pos); // i is 0 here: no animation name
            e->SetScale(&data_ov014_022169d4);
            e->unk_28 = i;
            func_ov003_021da9ac(self->unk_d8, 0xfc, e);
            for (; i < 2; i++) {
                e = func_02065f88(0x68, &self->pos);
                e->AddPos(&tbl[i].v);
                e->SetScale(&data_ov014_022169d4);
                func_ov003_021da9ac(self->unk_d8, 0xfb - i, e);
            }
            func_02065f88(0x322, &self->pos)->SetScaleAll(0x8000);
            func_ov000_0218996c(0x14, 0x32);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 5:
        e = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_d8, 0xfc));
        if (e != NULL) {
            s32 v = e->scale.x;
            if (v < 0xa000) {
                v += 0x1800;
                if (v >= 0xa000) {
                    func_ov000_0218996c(0xf, 0x32);
                    func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
                    func_02049f44(data_02097e4c, 0x7a, &self->pos, 0);
                    func_02049f44(data_02097e4c, 0x5a, &self->pos, 0);
                    v = 0xa000;
                }
                e->SetScaleAll(v);
            }
            func_ov000_0219aca8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 0, 0, 0x6800, 0, 0x328, 0x1000);
        } else if (!(self->unk_d0 & 0x200000)) {
            self->unk_d0 |= 0x200000;
        }
        for (i = 0; i < 2; i++) {
            e = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_d8, 0xfb - i));
            if (e != NULL) {
                e->SetScaleAll(e->scale.x + tbl[i].unk_0c);
            } else if (!(self->unk_d0 & 0x400000)) {
                self->unk_d0 |= 0x400000;
            }
        }
        break;
    }
    if ((self->unk_d0 & 0x400000) && (self->unk_d0 & 0x200000)) {
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
    e = func_020657b0(data_0214a420, Ov003FxList_Get(self->unk_d8, 0xf8));
    if (e != NULL) {
        s32 v = e->scale.x + -0x59a;
        if (v <= 0) {
            e->state = 4;
        } else {
            e->SetScaleAll(v);
        }
    }
    if (self->fsm->st > 3) {
        return;
    }
    if (*t->hp == 0) {
        return;
    }
    func_ov014_0220840c(self);
    pos = t->pos;
    box.unk_1e = 2;
    box.unk_20 = 0x20000000;
    box.rot[0] = self->rot_x;
    box.rot[1] = self->rot_y;
    box.rot[2] = self->rot_z;
    pl = func_ov000_0219bf90();
    if (pl != NULL && (((Robo021ca458 *)pl)->unk_b24_1 ? TRUE : FALSE) == TRUE) {
        box.min.x = -0xf000;
        box.min.y = -0x800;
        box.min.z = -0xf000;
        box.max.x = 0xf000;
        box.max.y = 0x800;
        box.max.z = 0xf000;
        Ov014_HitFrom(self, &box, &d, &pos, &self->pos);
    } else if (pl != NULL && (((Robo021ca458 *)pl)->unk_b24_1 ? TRUE : FALSE) == FALSE) {
        box.min.x = -0x1000;
        box.min.y = -0x800;
        box.min.z = -0x1000;
        box.max.x = 0x1000;
        box.max.y = 0x800;
        box.max.z = 0x1000;
        v2 = ((Robo021ca458 *)pl)->unk_75c;
        if (func_01ffc318(&v2, &self->pos, &data_ov014_022169e0, &data_ov014_02216a10, &self->rot_x)) {
            Ov014_HitFrom(self, &box, &d, &v2, &v2);
        }
        if (func_01ffc318(&pos, &self->pos, &data_ov014_022169e0, &data_ov014_02216a10, &self->rot_x)) {
            Ov014_HitFrom(self, &box, &d, &pos, &pos);
        }
    }
}

}
}  // namespace m_0220774c
