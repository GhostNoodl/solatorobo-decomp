#include "ov009/ov009.h"


// A header's zero rotation and vector, plus copies made at startup, next to this TU's name and
// scale. The pointer to the name and the scale are read by the functions of 0x022143d8..0x02215714
// (nine files, merged in round dtD, each in its own namespace).
extern const char *const data_ov009_022161c8;
extern const VecFx32 data_ov009_022161d4;
extern char data_ov009_0221800a[];
const char *const data_ov009_022161c8 = data_ov009_0221800a;
static const VecFx16 data_ov009_022161cc = {0, 0, 0};
const VecFx32 data_ov009_022161d4 = {0, 0, FX32_ONE};
static const VecFx32 data_ov009_022161e0 = {0, 0, 0};
static const VecFx16 data_ov009_02218004 = data_ov009_022161cc;
char data_ov009_0221800a[] = "nut00";
static const VecFx32 data_ov009_02218010 = data_ov009_022161e0;

// ---- merged from ov009_022143d8.cpp
namespace m_022143d8 {
extern "C" {

extern void func_0203f364(ActorSub48 *p);

void func_ov009_022143d8(Ov009ActExVt_0221828c *self) {
    if (self->fsm->st == 0) {
        ActorSub48 *s48;
        func_ov000_02190cb0(self->model, data_ov009_022161c8, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        FLD(u8, self, 0xce) = 0;
        if (self->kind == 0x408f) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        self->fsm->st++;
    }
    self->unk_94_1 = FLD(u8, self, 0xce);
}

}
}  // namespace m_022143d8

// ---- merged from ov009_022144a8.cpp
namespace m_022144a8 {
extern "C" {

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_02195d88(Actor *self);
extern void func_ov000_02196c40(Actor *self);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_022144a8(Ov009ActExVt_0221828c *self) {
    func_ov000_02198360(self->fsm, 0x15, 0);
}

void func_ov009_022144c0(Ov009ActExVt_0221828c *self) {
    func_ov000_02195d88(self);
    if (Ov009_FindActor(self->unk_d2) == NULL) {
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}

void func_ov009_02214508(ActorEx *self) {
    if (self->fsm->st == 0 && self->speed == 0) {
        self->hit->unk_30 = 0;
    }
    func_ov000_02196c40(self);
}

extern void func_0203f364(ActorSub48 *p);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(ActorGroup *group, u16 kind);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_ov000_02197dec(ActorEx *self, u8 a, s16 b);
extern void func_ov000_0218996c(s32 a, s32 b);
struct Ov009SpawnDesc2 {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov009Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

extern Ov003Actor *Group_SpawnActor(void *mgr, Ov009SpawnDesc2 *d, VecFx32 *pos, Ov009Rot16 *rot, u16 a);

static inline void Ov009Spawn_Init(Ov009SpawnDesc2 *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

void func_ov009_02214534(ActorEx *self) {
    VecFx32 p;
    Ov009SpawnDesc2 desc;
    Ov009Rot16 r;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        u16 i;
        u16 n;
        ActorGroup *e;
        s32 s;
        Ov009Spawn_Init(&desc, 0x4006);
        n = 3;
        e = ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000);
        if (e != NULL) {
            u32 c = ActorGroup_CountKind(e, 0x4006);
            if (c > 3) {
                c = 3;
            }
            n = 3 - c;
        }
        for (i = 0; i < n; i++) {
            Ov003Actor *o;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += 0x1000;
            r.x = self->rot_x;
            r.y = self->rot_y;
            r.z = self->rot_z;
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, &p, &r, 0xffff);
            if (o != NULL) {
                o->flags_0 = 1;
                o->target = self->target;
                o->speed = 0;
                o->velY = 0x333;
                o->friction = 0;
                o->gravity = 0x52;
                if (o->targetObj != NULL) {
                    o->targetObj->target = self->id;
                }
            }
        }
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += self->centerY;
        {
            EffectObj *e2 = func_02065f88(0x1f7, &p);
            s = self->radius + (self->radius >> 3);
            e2->SetScaleXYZ(s, s, s);
        }
        func_ov000_0218996c(0xc, 0x14);
        if (self->unk_44 != NULL) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *s48;
            func_ov000_02198c8c(self->hit, 0xffff);
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s48 = self->hit;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 5) {
            func_ov000_02197dec(self, 0xf, 0x63);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        if (self->model != NULL) {
            self->model->alpha = 0x1f - (self->fsm->timer << 2);
        }
        break;
    }
}

}
}  // namespace m_022144a8

// ---- merged from ov009_02214810.cpp
namespace m_02214810 {
extern "C" {

extern void func_ov000_02194758(Actor *self);

void Ov009ActExVt_022181f4_Start(Ov009ActExVt_022181f4 *self) {
    func_ov000_02194758(self);
    self->unk_d0 = 0x5a;
    self->unk_ce = 0xb4;
    self->unk_d2 = 0xffff;
}

}
}  // namespace m_02214810

// ---- merged from ov009_0221483c.cpp
namespace m_0221483c {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);

void Ov009ActExVt_022181f4_Update(Ov009ActExVt_022181f4 *self) {
    if (self->unk_ce != 0) {
        self->unk_ce--;
        if (self->unk_ce <= self->unk_d0) {
            Model0218fe1c *m = self->model;
            m->color = 0x14bf;
            m->color2 = 0x73ff;
            m->blend = 9;
            m->blendMax = 8;
            if (self->unk_d0 >= 0x46) {
                self->unk_d0 -= 0x14;
            } else if (self->unk_d0 >= 0x28) {
                self->unk_d0 -= 10;
            }
        }
        if (self->unk_ce <= 0x14) {
            if (self->unk_ce == 0x14) {
                EffectObj *e = func_02065f88(0x196, &self->pos);
                e->time = 0x2a000;
                e->SetScaleAll(0xe66);
                self->unk_bc = e->id;
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
        }
        if (self->unk_ce <= 0x10) {
            self->velY >>= 1;
            self->friction = 0xc7b;
        }
    } else {
        if (self->fsm->current == 9) {
            self->targetObj->target = 0xffff;
            self->unk_d2 = 0xffff;
        }
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}

}
}  // namespace m_0221483c

// ---- merged from ov009_02214974.cpp
namespace m_02214974 {
extern "C" {

extern char data_ov009_0221801c[];
extern Actor *Target_Get(ActorSub4c *p);
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov000_02196060(Actor *self);

void func_ov009_02214974(Ov009ActExVt_022181f4 *self) {
    Actor *p = Target_Get(self->targetObj);
    if (p != NULL) {
        self->unk_d2 = p->id;
        if (p->kind == 0x501d && self->fsm->st == 0) {
            ActorSub44 *s44;
            func_ov000_02190cb0(self->model, data_ov009_0221801c, 0x1000, 0);
            func_ov000_021915a0(self->model);
            self->speed = 0x2f6;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0x29;
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            if (self->hit != NULL) {
                ActorSub48 *s48 = self->hit;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                HitSphere_Link(s48);
                s48 = self->hit;
                s48->unk_9a_1 = 1;
                s48->unk_9a_4 = 1;
            }
            self->fsm->st++;
            self->fsm->timer = 0;
        } else {
            func_ov000_02196060(self);
        }
    } else {
        self->unk_d2 = 0xffff;
        func_ov000_02198360(self->fsm, 4, 0);
    }
}

}
}  // namespace m_02214974

// ---- merged from ov009_02214a9c.cpp
namespace m_02214a9c {
extern "C" {

void func_ov009_02214a9c(Ov009ActExVt_022181f4 *self) {
    self->unk_d2 = 0xffff;
    func_ov000_02198360(self->fsm, 4, 0);
}


#define OV009_F32_TO_FX32(f) ((s32)(((f) > 0) ? (f) * 4096.0f + 0.5f : (f) * 4096.0f - 0.5f))

struct Ov009ParamB {
    s16 unk_00;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 13;
};

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

extern void *data_02097e4c;
extern void HitSphere_Link(ActorSub48 *p);
extern void func_0203f364(ActorSub48 *p);
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern u16 func_ov000_02198da8(ActorSub48 *p, u16 a);
extern Actor *Target_Get(ActorSub4c *p);

void func_ov009_02214ac0(Ov009ActExVt_022181f4 *self) {
    VecFx32 v;
    ActorSub48 *o48;
    BOOL flag;
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *s48;
        ActorSub44 *s44;
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
        self->friction = 0xfae;
        s48 = self->hit;
        s48->unk_9a_0 = 1;
        s48->unk_9a_3 = 1;
        HitSphere_Link(s48);
        s48 = self->hit;
        s48->unk_9a_1 = 1;
        s48->unk_9a_4 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->unk_92 = 0;
        self->fsm->st++;
    }
    case 1: {
        ActorSub48 *s48 = self->hit;
        u32 f = s48->unk_50;
        if ((f & 0x20000000) || (f & 0x40000000) || ((s32)s48->unk_58) != 0) {
            u8 n = self->unk_92;
            if (f & 0x20000000) {
                if (n < 5) {
                    self->velY = OV009_F32_TO_FX32(0.2f - 0.0315f * n);
                    func_0204a028(data_02097e4c, 0x83, &self->pos, -2);
                    self->unk_92++;
                }
                if (self->velY < 0) {
                    self->velY = 0;
                }
                self->gravity = 0x29;
                self->speed = Ov009_FxMulL(self->speed, 0xc00);
            } else {
                self->moveYaw = func_ov000_02198da8(s48, self->moveYaw);
                self->speed = Ov009_FxMulL(self->speed, 0x59a);
                if (((s32)self->hit->unk_58) != 0 && n < 5) {
                    if (self->velY < 0xcd) {
                        self->velY = 0xcd;
                    }
                    self->unk_92++;
                }
                self->gravity = 0x29;
            }
            self->targetObj->target = 0xffff;
        }
        break;
    }
    }
    Actor_Move(self, 0);
    if (self->hit == NULL) {
        return;
    }
    if (((Ov009ParamB *)self->param)->unk_02_0 == 2) {
        ActorSub48 *s48 = self->hit;
        s48->unk_9a_0 = 1;
        s48->unk_9a_3 = 1;
        HitSphere_Link(s48);
    }
    o48 = NULL;
    flag = FALSE;
    {
        ActorSub4c *p4c = self->targetObj;
        if (p4c != NULL && p4c->target != 0xffff && p4c->unk_01 == 1) {
            Actor *p;
            s32 r = self->radius + 0x4cd;
            if (r < 0xccd) {
                r = 0xccd;
            }
            self->hit->unk_44 = r;
            p = Target_Get(self->targetObj);
            if (p != NULL && (o48 = p->hit) != NULL && o48->unk_9a_3) {
                o48->unk_9a_3 = 0;
                func_0203f364(o48);
                flag = TRUE;
            }
        }
    }
    v = self->pos;
    v.y -= self->height;
    func_ov000_021987b8(self->hit, 1, (s32)&v, (s32)&self->rot_x);
    if (flag) {
        o48->unk_9a_3 = 1;
        HitSphere_Link(o48);
    }
}

}
}  // namespace m_02214a9c

// ---- merged from ov009_02214e90.cpp
namespace m_02214e90 {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(Actor *self, Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern BOOL func_ov000_0219a8bc(void *p, Actor *a, Actor *b, s32 c, s32 d, const VecFx32 *pos, s32 e, s32 f, s32 g);
extern void func_ov000_0219763c(Actor *self);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_02214e90(Ov009ActExVt_022181f4 *self) {
    if (self->fsm->st == 0) {
        Actor *a;
        Ov003Actor *t;
        func_ov000_0218996c(10, 10);
        self->targetObj->unk_02 = 0;
        func_02065f88(5, &self->pos)->SetScaleAll(0x299a);
        func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        a = Ov009_FindActor(self->unk_d2);
        if (a == NULL) {
            a = self;
        }
        func_ov000_0219aae8(self, a, self->targetObj->unk_08, self->targetObj->unk_0a & 0xff, 0x30, 0, 0, 0x299a, 0, 0x64, 0x1000);
        t = func_ov000_0219bf90();
        if (t != NULL && Hit_DiffInSphere(&t->pos, &self->pos, t->radius + 0x299a)) {
            ActorSub4c *q = self->targetObj;
            func_ov000_0219a8bc(t->unk_44, self, self, q->unk_08, q->unk_0a & 0xff, &self->pos, 0x64, 0x1000, 0x1000);
        }
    }
    func_ov000_0219763c(self);
}

}
}  // namespace m_02214e90

// ---- merged from ov009_02214fe4.cpp
namespace m_02214fe4 {
extern "C" {

extern void func_ov000_02194758(Actor *self);
extern void func_0203f364(ActorSub48 *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern void Actor_TurnToActor(Actor *self, Ov003Actor *other, s32 a);
extern void func_ov000_0219433c(Actor *self);
extern Actor *Target_Get(ActorSub4c *p);

void func_ov009_02214fe4(ActorEx *self) {
    ActorSub48 *s48;
    func_ov000_02194758(self);
    s48 = self->hit;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
}

void func_ov009_02215014(ActorEx *self) {
    Actor_TurnToActor(self, func_ov000_0219bf90(), 0x7b);
    func_ov000_02198360(self->fsm, 1, 0);
}

void Ov009ActExVt_0221802c_Init(Ov009ActExVt_0221802c *self) {
    func_ov000_0219433c(self);
    self->rot_x = 0xd548;
    self->unk_d0 = 0;
}

void Ov009ActExVt_0221802c_Start(Ov009ActExVt_0221802c *self) {
    ActorSub48 *s48;
    Actor *p;
    func_ov000_02194758(self);
    s48 = self->hit;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    p = Target_Get(self->targetObj);
    if (p != NULL && p->unk_1c == 0) {
        self->hit->unk_30 = 0;
    }
    func_ov000_02198360(self->fsm, 0xb, 0);
}

}
}  // namespace m_02214fe4

// ---- merged from ov009_022150cc.cpp
namespace m_022150cc {
extern "C" {

extern void *data_02097e4c;
extern const VecFx32 data_ov009_022161ec;
extern Actor *Target_Get(ActorSub4c *p);
extern void func_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov009_02215714(Ov009ActExVt_0221802c *self);
extern void func_ov009_02215a6c(Ov009ActExVt_0221802c *self);
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_01ffc9fc(VecFx32 *out, const void *a, s32 b);
extern void Actor_PitchToPos(Actor *self, const VecFx32 *v, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov009_RotX(VecFx32 *out, const VecFx32 *v, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 s = OV009_SIN(ang);
    s32 c = OV009_COS(ang);
    if (v->y != 0) {
        y += FX_Mul(c, v->y);
        z += FX_Mul(s, v->y);
    }
    if (v->z != 0) {
        y += FX_Mul(-s, v->z);
        z += FX_Mul(c, v->z);
    }
    out->x = v->x;
    out->y = y;
    out->z = z;
}

void func_ov009_022150cc(Ov009ActExVt_0221802c *self) {
    Actor *p;
    ActorSub48 *m;
    p = Target_Get(self->targetObj);
    if (p != NULL) {
        m = p->hit;
        if (m != NULL && m->unk_9a_3) {
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    } else {
        func_ov000_02198360(self->fsm, 0x15, 0);
        return;
    }
    if (p->kind == 0x1000) {
        func_ov009_02215714(self);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        func_02065f88(0x6a, &self->pos)->SetScaleAll(0xccd);
        func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
        self->unk_d8 = Rand_PlusMinus(0x14) + 0x7b;
        if (self->unk_18 == 1) {
            self->unk_d8 = 0x3d;
        }
        self->unk_d4 = 0;
        self->unk_92 = 0;
        self->fsm->st++;
        break;
    case 1: {
        VecFx32 a = data_ov009_022161ec;
        func_01ffc9fc(&a, &a, self->rot_y);
        VEC_Add(&a, &self->pos, &a);
        Actor_PitchToPos(self, &a, ((s32)self->unk_d8));
        if (self->hit->unk_50 & 0x40000000) {
            self->rot_x = 0x3ffc;
        } else if (self->rot_x < 0xbff4 && self->rot_x > 0x3ffc) {
            self->rot_x = 0x3ffc;
        }
        VecFx32 v = data_ov009_022161d4;
        Ov009_RotX(&v, &v, self->rot_x);
        func_01ffc9fc(&v, &v, self->rot_y);
        VEC_Normalize(&v, &v);
        self->speed = Ov009_FxMulL(v.x, 0x333);
        self->velY = Ov009_FxMulL(v.y, 0x333);
        self->friction = Ov009_FxMulL(v.z, 0x333);
        switch (self->unk_18) {
        case 1:
            if (p->pos.y > 0x9000) {
                self->speed = Ov009_FxMulL(v.x, 0x51f);
                self->velY = Ov009_FxMulL(v.y, 0x51f);
                self->friction = Ov009_FxMulL(v.z, 0x51f);
            } else {
                self->speed = Ov009_FxMulL(v.x, 0x59a);
                self->velY = Ov009_FxMulL(v.y, 0x59a);
                self->friction = Ov009_FxMulL(v.z, 0x59a);
            }
            break;
        case 2:
            self->speed = Ov009_FxMulL(v.x, 0x47b);
            self->velY = Ov009_FxMulL(v.y, 0x47b);
            self->friction = Ov009_FxMulL(v.z, 0x47b);
            break;
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        func_ov009_02215a6c(self);
        m = self->hit;
        if (m->unk_50 & 0x20000000) {
            self->velY = 0x266;
            self->gravity = 0x29;
            self->unk_92++;
            m->unk_9a_0 = true;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
            self->fsm->st++;
        }
        if (++self->unk_d4 >= 0x96) {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
    case 2:
        if (self->velY <= 0 && (self->hit->unk_50 & 0x20000000)) {
            if (++self->unk_92 <= 2) {
                self->velY = 0x19a;
            } else {
                ActorSub44 *s;
                func_ov000_0218996c(10, 10);
                func_02065f88(5, &self->pos)->SetScaleAll(0x3000);
                func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, NULL, 0, 0x4000, 0, 0x64, 0x1000);
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
                s = self->unk_44;
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
                func_ov000_02198360(self->fsm, 0x15, 0);
            }
        }
        Actor_Move(self, 0);
        break;
    }
    func_ov000_021987b8(self->hit, 1, 0, 0);
}

}
}  // namespace m_022150cc
