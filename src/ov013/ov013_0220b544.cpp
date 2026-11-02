#include "ov013/ov013.h"

struct Ov013Rot { u16 x, y, z; };
struct Ov013Offs5 { u16 v[5]; };

// A header's zero rotation and vector, plus copies made at startup, among this TU's constants.
// The functions of 0x02204a3c..0x022065ac (five files, merged in round dtC, each in its own
// namespace) are part of this TU: they read the rotation 0220b292, the five angle offsets
// 0220b29e and the zero vector 0220b2c0 through the .rodata base 0220b290 plus an offset, and
// name them instead of Ov013RotTbl/Ov013Offs5/u8[] views of data_ov013_0220b290.
extern const u16 data_ov013_0220b290;
extern const VecFx32 data_ov013_0220b2a8;
extern const VecFx32 data_ov013_0220b2b4;
const u16 data_ov013_0220b290 = 1;
static const Ov013Rot data_ov013_0220b292 = {0x4000, 0, 0};
static const Ov013Offs5 data_ov013_0220b29e = {{(u16)-0x1556, (u16)-0xaac, 0, 0xaab, 0x1555}};
const VecFx32 data_ov013_0220b2a8 = {0, -0xccd, 0};
static const VecFx16 data_ov013_0220b298 = {0, 0, 0};
static const VecFx32 data_ov013_0220b2c0 = {0, 0, 0};
const VecFx32 data_ov013_0220b2b4 = {-FX32_ONE / 2, 0, 0};
static const VecFx16 data_ov013_0220ba44 = data_ov013_0220b298;
static const VecFx32 data_ov013_0220ba4c = data_ov013_0220b2c0;

// ---- merged from ov013_02204a3c.cpp
namespace m_02204a3c {
class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();


struct Ov013RotC {
    u16 x;
    u16 y;
    u16 z;
    Ov013RotC() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Ov013Offs5 {
    u16 v[5];
};

extern "C" {

extern Ov013Pmf data_ov013_0220bc48;
extern Ov013Pmf data_ov013_0220bc50;
extern Ov013Pmf data_ov013_0220bc58;
extern const u8 data_ov003_021f4340;
extern char data_ov013_0220ba6c[];
extern u8 data_ov013_0220b308[];
extern u8 data_ov013_0220b324[];
extern void func_ov000_02194758(void *self);
extern char data_ov013_0220ba73[];
extern const Ov013Pmf data_ov013_0220bc60;
extern Ov013Pmf data_ov013_0220bc68;
extern Ov013Pmf data_ov013_0220bc70;
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_0203f364(ActorSub48 *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_ov013_02205760(Ov003Actor *self);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov003Actor *self, s32 a);
extern BOOL func_ov000_021950e8(Actor *self, Ov013Msg *msg);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern u8 *func_020704b4(u16 kind);
extern void func_ov013_02205098(Ov003Actor *self);
extern void func_ov000_02195d88(Actor *self);
extern void func_ov000_02197dec(Ov003Actor *self, s32 a, s32 b);
extern void func_ov000_0219763c(Actor *self);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 Ov013_FaceAngle(Actor *self, Actor *a) {
    if (a != NULL) {
        if (a != NULL && a != self) {
            return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        return self->rot_y;
    }
    return self->moveYaw + 0x7fff;
}

void Ov013ActEx_02204454_Start(Ov013ActEx_02204454 *self) {
    s32 x;
    s32 y;
    s32 z;
    void *m;
    ActorSub48 *m48;
    ActorSub44 *n;
    func_ov000_02194758(self);
    self->model->visible = 0;
    func_ov000_02198360(self->fsm, 0x20, 0);
    FLD(s8, self, 0xcf) = 2;
    FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc48;
    x = self->model->scale.x;
    y = self->model->scale.y;
    z = self->model->scale.z;
    m = Heap_Alloc(0xe8);
    if (m != NULL) {
        m = func_ov000_0218fe1c(m);
    }
    self->unk_e0 = m;
    func_ov000_0218ffdc(m, ((void *)self->unk_dc), 0, 1);
    m = self->unk_e0;
    FLD(s32, m, 0xa8) = x;
    FLD(s32, m, 0xac) = y;
    FLD(s32, m, 0xb0) = z;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    self->unk_44->unk_1c = x + 0x2000;
    m48 = self->hit;
    m48->unk_9a_1 = 0;
    m48->unk_9a_4 = 0;
    m48 = self->hit;
    m48->unk_9a_0 = 0;
    m48->unk_9a_3 = 0;
    func_0203f364(m48);
    self->hit->unk_30 = 0;
    func_ov003_021cf330((u8 *)self + 0xec, data_ov013_0220ba6c, data_ov003_021f4340);
}

void Ov013ActEx_02204454_Update(Ov013ActEx_02204454 *self) {
    u32 *p = ((u32 *)self->unk_5c);
    if (p != NULL) {
        *p &= ~2;
    }
    self->rot_x += self->unk_d0;
}

void func_ov013_02204b88(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    u8 k = s->current;
    if (k != 0x15) {
        if (k == 0x27) {
            func_ov013_02205760(self);
            self->fsm->flags = 0;
        } else if (s->flags & 0x200000) {
            func_ov000_02198360(s, 0x15, 0);
        } else if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        } else {
            func_ov003_021da40c(s);
        }
    }
    func_ov000_0218d7e8(self, self->fsm->current);
}

BOOL func_ov013_02204c20(Ov013ActEx_02204454 *self, Ov013Msg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        r = TRUE;
        if (FLD(u8, msg, 8) == 1) {
            Ov003Actor *a;
            self->targetObj->target = FLD(u16, msg, 6);
            self->target = 0xffff;
            a = Ov013_FindActor(FLD(u16, msg, 6));
            if (a != NULL) {
                self->target = a->target;
            }
            FLD(s8, self, 0xcf)--;
            if (FLD(s8, self, 0xcf) <= 0) {
                FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc50;
                func_ov000_02198360(self->fsm, 0x27, 0);
            } else {
                FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc58;
                self->moveYaw = Ov013_FaceAngle(self, Ov013_FindActor(self->target));
                FLD(Ov013Flags8, self, 0xce).b1 = 0;
                self->unk_d8 = data_ov013_0220b308;
                self->unk_d0 = 0xc00;
                self->targetObj->type = func_020704b4(self->kind)[0];
                func_ov000_02198360(self->fsm, 0xe, 0);
            }
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

void func_ov013_02204dbc(Ov003Actor *self) {
    func_ov013_02205098(self);
}

void func_ov013_02204dc8(Ov013ActEx_02204454 *self) {
    if (self->fsm->st == 0) {
        self->unk_d0 = 0;
    }
    func_ov000_02195d88(self);
}

static inline BOOL Ov013_IsSolid(ActorSub44 *n) {
    return n->unk_22_0 == 1 && n->unk_22_1 == 1;
}

void func_ov013_02204de8(Ov013ActEx_02204454 *self) {
    ActorSub44 *n;
    ActorSub48 *m;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220ba73, 0x1000, 0);
        func_ov000_021915a0(self->model);
        FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc60;
        self->unk_d0 = 0x700;
        self->speed = 0x59a;
        self->velY = 0;
        self->moveYaw = self->rot_y;
        self->gravity = 1;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        self->fsm->st++;
    case 1: {
        u16 t;
        self->fsm->timer++;
        t = self->fsm->timer;
        if (t > 3 && (self->hit->unk_58 & 0x20)) {
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->fsm, 0x15, 0);
            return;
        }
        if (t > 0x96) {
            FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc68;
            func_ov000_02198360(self->fsm, 0x15, 0);
            return;
        }
        if (t > 0x3c) {
            Ov003Actor *a = Actor_GetTarget(self);
            n = NULL;
            if (a != NULL) {
                n = a->unk_44;
            }
            if (n != NULL && !Ov013_IsSolid(n)) {
                n = NULL;
            }
            if (n == NULL) {
                FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc70;
                func_ov000_02198360(self->fsm, 0x15, 0);
                return;
            }
        }
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        break;
    }
    }
}

void func_ov013_02205054(Ov003Actor *self) {
    func_ov000_02198360(self->fsm, 0x15, 1);
}

void func_ov013_0220506c(Ov003Actor *self) {
    (((Ov013Cls *)self)->*FLD(Ov013Pmf, self, 0xe4))();
}

static inline void Ov013_RotZero(Ov013Rot *p) {
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

static inline Actor *Ov013_SpawnAt(u16 kind, const VecFx32 *pos, const Ov013Rot *rot) {
    Actor *b = func_ov003_021da32c(kind);
    if (b != NULL) {
        b->pos = *pos;
        FLD(Ov013Rot, b, 0x7c) = *rot;
    }
    return b;
}


struct Ov013Prm {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 pad;
    s16 v2;
    s16 v4;
    s16 v6;
    s16 v8;
    s16 va;
    s16 vc;
    u16 ve;
    s16 v10;
    s16 v12;
    s16 v14;
    u8 pad2[2];
    s32 v18;
};

// Reads the parameter pointer through a const view, so the plain reads in Ov013_Dur that
// follow load it again, as in the target.
static inline BOOL Ov013_PrmB0(const Ov003Actor *self) {
    return (*(const Ov013Prm *const *)((const u8 *)self + 0xd8))->b0;
}


extern void *Target_Get(void *p);
extern void func_ov003_021d9980(VecFx32 *out, u16 ang, const void *b);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern void *data_02097e4c;
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern const u8 data_ov013_0220b2cc[];
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

static inline u16 Ov013_Dur(Ov003Actor *self) {
    u16 v = 0;
    if (FLD(Ov013Flags8, self, 0xce).b1) {
        v = FLD(u16, self, 0xd2);
    } else if (((u8 *)self->unk_d8) != NULL) {
        v = FLD(u16, ((u8 *)self->unk_d8), 0xe);
    }
    return v;
}

#define OV013_CLAMP(x, lo, hi) ((x) > (hi) ? (hi) : ((x) < (lo) ? (lo) : (x)))

static inline s32 Ov013_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov013_VecSub(VecFx32 *o, const VecFx32 *a, const VecFx32 *b) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline s32 Ov013_Dot(const VecFx32 *a, const VecFx32 *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

void func_ov013_02205098(Ov003Actor *self) {
    VecFx32 tp;
    VecFx32 d;
    VecFx32 f;
    VecFx32 dv;
    if (self->fsm->st != 100 && ((Ov013Prm *)self->unk_d8) == NULL) {
        self->fsm->st = 100;
    }
    switch (self->fsm->st) {
    case 0: {
        Ov003Actor *a = Ov013_FindActor(self->target);
        ActorSub48 *m;
        ActorSub44 *n;
        if (a == NULL) {
            self->fsm->st = 100;
            break;
        }
        self->unk_84 = a->pos;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = ((Ov013Prm *)self->unk_d8)->v2;
        self->rot_y = self->moveYaw;
        self->model->visible = 1;
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->fsm->st = 10;
        break;
    }
    case 10: {
        Ov003Actor *t = (Ov003Actor *)Target_Get(self->targetObj);
        s32 dist;
        BOOL ahead;
        Ov013Prm *p;
        if (t == NULL) {
            self->fsm->st = 100;
            break;
        }
        tp = t->pos;
        d.x = self->unk_84.x - self->pos.x;
        d.y = self->unk_84.y - self->pos.y;
        d.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&d, &d);
        func_ov003_021d9980(&f, self->moveYaw, data_ov013_0220b2cc);
        dist = VEC_Distance(&tp, &self->pos);
        ahead = Ov013_Dot(&d, &f) < 0x800;
        if (dist > 0x6000 && ahead) {
            self->fsm->st = 20;
        } else {
            p = ((Ov013Prm *)self->unk_d8);
            if (p->b2 && dist >= p->v18) {
                self->fsm->st = 20;
            }
        }
        Actor_Move(self, 0);
        self->speed += ((Ov013Prm *)self->unk_d8)->v4;
        self->speed = OV013_CLAMP(self->speed, 0, ((Ov013Prm *)self->unk_d8)->v6);
        break;
    }
    case 20: {
        EffectObj *o = func_02065f88(0x192, &self->pos);
        o->SetScaleAll(0x4000);
        o->SetRotXYZ(0, self->rot_y, 0);
        self->fsm->st = 21;
    }
    case 21: {
        Ov013Prm *p = ((Ov013Prm *)self->unk_d8);
        if (p->b1 && self->speed >= p->v10) {
            self->speed = p->v10;
        }
        p = ((Ov013Prm *)self->unk_d8);
        self->friction = p->v12;
        if (self->speed < p->v14) {
            self->fsm->st = 30;
            break;
        }
        Actor_Move(self, 0);
        break;
    }
    case 30: {
        if (self->fsm->timer % 12 == 0) {
            func_02049f44(data_02097e4c, 100, &self->pos, 0);
        }
        if (!Ov013_PrmB0(self)) {
            s32 lim = Ov013_Dur(self) - 0x6e;
            lim = OV013_CLAMP(lim, 0, Ov013_Dur(self));
            if (lim < self->fsm->timer && self->fsm->timer % 8 == 0) {
                Model0218fe1c *m = self->model;
                if (FLD(u8, m, 0xbe) == 0x10) {
                    FLD(u8, m, 0xbe) = 0x1f;
                } else {
                    FLD(u8, m, 0xbe) = 0x10;
                    m = self->model;
                    FLD(u16, m, 0xb6) = 0x318c;
                    FLD(u16, m, 0xb8) = 0x7fff;
                    FLD(u16, m, 0xba) = 9;
                    FLD(u16, m, 0xbc) = 8;
                }
            }
        }
        if (self->fsm->timer >= Ov013_Dur(self)) {
            self->fsm->timer = 0;
            if (((Ov013Prm *)self->unk_d8)->b0) {
                self->fsm->st = 40;
            } else {
                self->fsm->st = 100;
                break;
            }
        } else {
            self->fsm->timer = ActorSub40_Timer(self->fsm) + 1;
            break;
        }
    }
    case 40:
    case 41: {
        Ov003Actor *a;
        ActorSub40 *s = self->fsm;
        if (s->st == 40) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            FLD(Ov013Flags8, self, 0xce).b0 = 1;
            self->speed = ((Ov013Prm *)self->unk_d8)->v8;
            s->st = 41;
        } else {
            self->speed += ((Ov013Prm *)self->unk_d8)->va;
            self->speed = OV013_CLAMP(self->speed, 0, ((Ov013Prm *)self->unk_d8)->vc);
        }
        Actor_Move(self, 0);
        a = Ov013_FindActor(self->targetObj->target);
        if (a == NULL) {
            self->fsm->st = 100;
            break;
        }
        {
            s32 x = a->pos.x;
            s32 y = a->pos.y;
            s32 z = a->pos.z;
            dv.x = x - self->pos.x;
            dv.y = y - self->pos.y;
            dv.z = z - self->pos.z;
        }
        self->moveYaw = Ov003Vec_Yaw(&dv);
        self->rot_y = self->moveYaw + 0x7fff;
        break;
    }
    case 100:
        func_ov000_02198360(self->fsm, 0x15, 1);
        FLD(Ov013Prm *, self, 0xd8) = NULL;
        break;
    }
    {
        Ov013Rot r = data_ov013_0220b292;
        r.y = self->rot_y + 0x4000;
        VecFx32 v = data_ov013_0220b2b4;
        func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &v, &r, 0x5800, 0x1000, 100, 0x1000);
    }
}

}
}  // namespace m_02204a3c

// ---- merged from ov013_022058d4.cpp
namespace m_022058d4 {
class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();

struct Ov013Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov013RotC {
    u16 x;
    u16 y;
    u16 z;
    Ov013RotC() {
        x = 0;
        y = 0;
        z = 0;
    }
};


extern "C" {

extern Ov013Pmf data_ov013_0220bc48;
extern Ov013Pmf data_ov013_0220bc50;
extern Ov013Pmf data_ov013_0220bc58;
extern const u8 data_ov003_021f4340;
extern char data_ov013_0220ba6c[];
extern u8 data_ov013_0220b308[];
extern u8 data_ov013_0220b324[];
extern void func_ov000_02194758(void *self);
extern char data_ov013_0220ba73[];
extern const Ov013Pmf data_ov013_0220bc60;
extern Ov013Pmf data_ov013_0220bc68;
extern Ov013Pmf data_ov013_0220bc70;
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_0203f364(ActorSub48 *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_ov013_02205760(Ov003Actor *self);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov003Actor *self, s32 a);
extern BOOL func_ov000_021950e8(Actor *self, Ov013Msg *msg);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern u8 *func_020704b4(u16 kind);
extern void func_ov013_02205098(Ov003Actor *self);
extern void func_ov000_02195d88(Actor *self);
extern void func_ov000_02197dec(Ov003Actor *self, s32 a, s32 b);
extern void func_ov000_0219763c(Actor *self);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 Ov013_FaceAngle(Actor *self, Actor *a) {
    if (a != NULL) {
        if (a != NULL && a != self) {
            return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        return self->rot_y;
    }
    return self->moveYaw + 0x7fff;
}

void func_ov013_02205760(Ov003Actor *self) {
    Ov013Offs5 offs;
    u16 ang;
    u32 i;
    u16 lvl;
    if (self->fsm->st != 0) {
        return;
    }
    offs = data_ov013_0220b29e;
    ang = Ov013_FaceAngle(self, Ov013_FindActor(self->target));
    lvl = self->targetObj->target;
    for (i = 0; i < 5; i++) {
        Actor *c;
        Ov013Rot r = {0, 0, 0};
        r.y = ang + offs.v[i];
        c = func_ov003_021da32c(0x480a);
        if (c != NULL) {
            c->pos = self->pos;
            FLD(Ov013Rot, c, 0x7c) = r;
            c->target = self->target;
            c->targetObj->target = lvl;
            FLD(void *, c, 0x60) = data_ov013_0220b324;
        }
    }
    func_ov000_02198360(self->fsm, 0x15, 1);
}

void func_ov013_022058d4(Ov003Actor *self) {
    func_ov000_02197dec(self, 0xf, 0x63);
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    self->vfunc_08();
}

void func_ov013_02205914(Ov003Actor *self) {
    self->radius = 0x1000;
    func_ov000_0219763c(self);
}

extern void *data_02097e4c;
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);

static inline s32 Ov013_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov013_SetAlpha(Model0218fe1c *m, s32 a) {
    m->alpha = Ov013_Clamp(a, 1, 31);
}

void func_ov013_02205928(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        FLD(u16, self, 0xd0) = 0;
        if (ActorSub40_Timer(s) >= 3) {
            s->timer = 0;
            self->fsm->st = 1;
        } else {
            s->timer++;
            return;
        }
    case 1:
        Ov013_SetAlpha(self->model, 31 - self->fsm->timer);
        if (self->fsm->timer % 10 == 0) {
            func_ov003_021da108(self, 0x2800, 0x38b, 0x1000, 0x1000);
            func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        }
        if (self->fsm->timer == 0) {
            FieldState *g = data_ov000_021ccd54;
            g->cam.base.shakeX = 1;
            g->cam.base.shakeY = 1;
            g->cam.base.shakeZ = 1;
            g->cam.base.shakeTime = 20;
            g->cam.base.shakeLen = 0xf;
            g->cam.base.shakeCur = 0xf;
        }
        if (self->fsm->timer < 30) {
            self->fsm->timer = ActorSub40_Timer(self->fsm) + 1;
        } else {
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        break;
    case 2:
        self->model->visible = 0;
        func_ov000_02197dec(self, 0xf, 0x63);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        break;
    }
}

}
}  // namespace m_022058d4

// ---- merged from ov013_02205ae4.cpp
namespace m_02205ae4 {
class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();

struct Ov013Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov013RotC {
    u16 x;
    u16 y;
    u16 z;
    Ov013RotC() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Ov013Offs5 {
    u16 v[5];
};

extern "C" {

extern Ov013Pmf data_ov013_0220bc48;
extern Ov013Pmf data_ov013_0220bc50;
extern Ov013Pmf data_ov013_0220bc58;
extern const u8 data_ov003_021f4340;
extern char data_ov013_0220ba6c[];
extern u8 data_ov013_0220b308[];
extern u8 data_ov013_0220b324[];
extern void func_ov000_02194758(void *self);
extern char data_ov013_0220ba73[];
extern const Ov013Pmf data_ov013_0220bc60;
extern Ov013Pmf data_ov013_0220bc68;
extern Ov013Pmf data_ov013_0220bc70;
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_0203f364(ActorSub48 *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_ov013_02205760(Ov003Actor *self);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov003Actor *self, s32 a);
extern BOOL func_ov000_021950e8(Actor *self, Ov013Msg *msg);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern u8 *func_020704b4(u16 kind);
extern void func_ov013_02205098(Ov003Actor *self);
extern void func_ov000_02195d88(Actor *self);
extern void func_ov000_02197dec(Ov003Actor *self, s32 a, s32 b);
extern void func_ov000_0219763c(Actor *self);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 Ov013_FaceAngle(Actor *self, Actor *a) {
    if (a != NULL) {
        if (a != NULL && a != self) {
            return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        return self->rot_y;
    }
    return self->moveYaw + 0x7fff;
}

extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void *data_02097e4c;
extern void *data_ov013_0220ba88[];
extern const u8 data_ov013_0220b2cc[];
extern void func_ov003_021d9980(void *out, u16 rot, const void *v);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void func_ov003_021cf33c(void *p, void *q);
extern void *ActorEx_Ctor(void *self);
extern BOOL func_ov000_02194c08(void *self);

void *Ov013ActEx_02205ae4_Ctor(Ov013ActEx_02205ae4 *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov013_0220ba88;
    Ov003Vt_021f79a8_Ctor((u8 *)self + 0xe0);
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(Ov013Flags8, self, 0xce).b1 = 0;
    self->unk_d0 = 0;
    self->unk_d2 = 0;
    self->unk_d4 = data_ov013_0220b2c0;
    return self;
}

void *Ov013ActEx_02205ae4_Dtor(Ov003Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220ba88;
    ((Ov013V *)((u8 *)self + 0xe0))->v08();
    Ov003Vt_021f79a8_Dtor((u8 *)self + 0xe0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov013ActEx_02205ae4_DtorDelete(Ov003Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220ba88;
    ((Ov013V *)((u8 *)self + 0xe0))->v08();
    Ov003Vt_021f79a8_Dtor((u8 *)self + 0xe0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

BOOL Ov013ActEx_02205ae4_Draw(Ov003Actor *self) {
    func_ov003_021cf33c((u8 *)self + 0xe0, self->fsm);
    return func_ov000_02194c08(self);
}

void func_ov013_02205bec(Ov003Actor *self, const VecFx32 *v, u16 id, u16 plid, u16 r, u16 rot) {
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(Ov013Flags8, self, 0xce).b1 = 0;
    self->pos = *v;
    self->targetObj->target = id;
    self->target = plid;
    self->moveYaw = r;
    self->rot_y = rot;
    func_ov003_021d9980((u8 *)self + 0xd4, self->moveYaw, data_ov013_0220b2cc);
    FLD(u16, self, 0xd2) = 0x280;
    func_ov000_02198360(self->fsm, 0xe, 0);
}

}
}  // namespace m_02205ae4

// ---- merged from ov013_02205c64.cpp
namespace m_02205c64 {
class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();

struct Ov013Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov013RotC {
    u16 x;
    u16 y;
    u16 z;
    Ov013RotC() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Ov013Offs5 {
    u16 v[5];
};

extern "C" {

extern Ov013Pmf data_ov013_0220bc48;
extern Ov013Pmf data_ov013_0220bc50;
extern Ov013Pmf data_ov013_0220bc58;
extern const u8 data_ov003_021f4340;
extern char data_ov013_0220ba6c[];
extern u8 data_ov013_0220b308[];
extern u8 data_ov013_0220b324[];
extern void func_ov000_02194758(void *self);
extern char data_ov013_0220ba73[];
extern const Ov013Pmf data_ov013_0220bc60;
extern Ov013Pmf data_ov013_0220bc68;
extern Ov013Pmf data_ov013_0220bc70;
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_0203f364(ActorSub48 *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_ov013_02205760(Ov003Actor *self);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov003Actor *self, s32 a);
extern BOOL func_ov000_021950e8(Actor *self, Ov013Msg *msg);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern u8 *func_020704b4(u16 kind);
extern void func_ov013_02205098(Ov003Actor *self);
extern void func_ov000_02195d88(Actor *self);
extern void func_ov000_02197dec(Ov003Actor *self, s32 a, s32 b);
extern void func_ov000_0219763c(Actor *self);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 Ov013_FaceAngle(Actor *self, Actor *a) {
    if (a != NULL) {
        if (a != NULL && a != self) {
            return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        return self->rot_y;
    }
    return self->moveYaw + 0x7fff;
}

u32 func_ov013_02205c64(Ov003Actor *self) {
    return FLD(Ov013Flags8, self, 0xce).b0;
}

struct Ov013Mtx33 {
    s32 m[3][3];
};


static inline s32 Ov013_Dot(const VecFx32 *a, const VecFx32 *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

static inline s32 Ov013_Dot2(const VecFx32 *a, const VecFx32 *b) {
    s64 ax = a->x;
    s64 ay = a->y;
    s64 az = a->z;
    s64 bx = b->x;
    s64 by = b->y;
    s64 bz = b->z;
    return (s32)((az * bz + (ax * bx + ay * by) + 0x800) >> 12);
}

static inline void Ov013_Cross(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    s32 x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    s32 y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    s32 z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
    o->x = x;
    o->y = y;
    o->z = z;
}

void func_ov013_02205c74(VecFx32 *out, const VecFx32 *a, const VecFx32 *b, const VecFx32 *v, u16 ang) {
    VecFx32 d;
    VecFx32 axis;
    Ov013Mtx33 m1;
    Ov013Mtx33 m2;
    VecFx32 r1;
    VecFx32 r2;
    VecFx32 res;
    VEC_Subtract(a, b, &d);
    VEC_Normalize(&d, &d);
    Ov013_Cross(v, &d, &axis);
    MTX_RotAxis33((MtxFx33 *)&m1, &axis, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
    MTX_RotAxis33((MtxFx33 *)&m2, &axis, FX_SinCosTable_[((u16)(0xffff - ang) >> 4) * 2], FX_SinCosTable_[((u16)(0xffff - ang) >> 4) * 2 + 1]);
    MTX_MultVec33(v, (MtxFx33 *)&m1, &r1);
    MTX_MultVec33(v, (MtxFx33 *)&m2, &r2);
    bool behind = 0 != (Ov013_Dot(&r1, v) < Ov013_Dot(&d, v));
    if (behind) {
        res = d;
    } else if (Ov013_Dot2(&r1, &d) > Ov013_Dot2(&r2, &d)) {
        res = r1;
    } else {
        res = r2;
    }
    *out = res;
}

}
}  // namespace m_02205c64

// ---- merged from ov013_02205fa4.cpp
namespace m_02205fa4 {
extern "C" {

extern const u8 data_ov003_021f4344;
extern char data_ov013_0220ba79[];
extern void func_ov000_02194758(void *self);
extern void func_0203f364(ActorSub48 *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern BOOL func_ov000_021950e8(Actor *self, Ov013Msg *msg);

void Ov013ActEx_02205ae4_Start(Ov013ActEx_02205ae4 *self) {
    ActorSub48 *m;
    func_ov000_02194758(self);
    switch (self->kind) {
    case 0x4808:
        self->unk_d0 = 0x1555;
        break;
    case 0x4809:
        self->unk_d0 = 0xeaaa;
        break;
    }
    self->model->visible = 0;
    func_ov000_02198360(self->fsm, 0x20, 0);
    m = self->hit;
    m->unk_9a_1 = 1;
    m->unk_9a_4 = 1;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->hit->unk_9a_6 = 0;
    self->hit->unk_30 = 0x20000000;
    func_ov003_021cf330((u8 *)self + 0xe0, data_ov013_0220ba79, data_ov003_021f4344);
}

BOOL func_ov013_02206074(Ov003Actor *self, Ov013Msg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        if (FLD(u8, msg, 8) == 1) {
            FLD(Ov013Flags8, self, 0xce).b1 = 1;
        }
        r = TRUE;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

void func_ov013_022060c8(void) {
}


extern void *data_02097e4c;
extern const VecFx32 data_ov013_0220b2cc;
extern void func_ov003_021d9980(VecFx32 *out, u16 rot, const VecFx32 *v);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern Ov003Actor *Target_Get(void *p);
extern void func_ov013_02205c74(VecFx32 *dir, VecFx32 *target, VecFx32 *pos, VecFx32 *n, u16 rate);
extern void func_ov000_0219bd20(u16 kind, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);

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

static inline s32 Ov013_DistXZ3(const VecFx32 *a, const VecFx32 *b) {
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt2(sq);
}

static inline void Ov013_Steer(Ov013ActEx_02205ae4 *self, VecFx32 *t, u16 rate) {
    VecFx32 n;
    VEC_Normalize(&self->unk_d4, &n);
    func_ov013_02205c74(&self->unk_d4, t, &self->pos, &n, rate);
}

void func_ov013_022060cc(Ov013ActEx_02205ae4 *self) {
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        VecFx32 v;
        Ov003Actor *o;
        self->model->visible = 1;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_ov003_021d9980(&v, self->rot_y, &data_ov013_0220b2cc);
        VEC_MultAdd(0x14000, &v, &self->pos, &self->unk_84);
        o = Actor_GetTarget(self);
        if (o == NULL || o->hit == NULL) {
            self->fsm->st = 0x15;
            break;
        }
        self->unk_84.y = o->hit->check.y + 0xccd;
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    }
    case 10: {
        s32 sp = self->speed + 0x40;
        VecFx32 t;
        s32 d;
        if (sp > 0x1600) {
            sp = 0x1600;
        } else if (sp < 0) {
            sp = 0;
        }
        self->speed = sp;
        t = self->unk_84;
        d = Ov013_DistXZ3(&self->pos, &t);
        if (d > 0x5000) {
            d = 0x5000;
        }
        t.y += d - 0x5000;
        Ov013_Steer(self, &t, self->unk_d2);
        VEC_MultAdd(self->speed, &self->unk_d4, &self->pos, &self->pos);
        {
            s32 r = self->unk_d2 + 8;
            if (r > 0x800) {
                r = 0x800;
            } else if (r < 0) {
                r = 0;
            }
            self->unk_d2 = r;
        }
        if (VEC_Distance(&self->pos, &self->unk_84) <= 0x3000) {
            const u16 *p = &data_ov013_0220b290;
            func_ov000_0219bd20(self->kind, self->id, 0xe, FALSE, 1, &p);
            self->fsm->st = 0x14;
        } else if (FLD(Ov013Flags8, self, 0xce).b1) {
            self->fsm->st = 0x14;
        }
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer % 20 == 0) {
                func_0204a028(data_02097e4c, 9, &self->pos, -5);
            }
        }
        break;
    }
    case 0x14: {
        Ov003Actor *pl;
        VecFx32 t;
        s32 d;
        FLD(Ov013Flags8, self, 0xce).b0 = 1;
        self->speed = FX_Mul(self->speed, 0xf40);
        self->speed = self->speed < 0x400 ? 0x400 : self->speed;
        pl = Target_Get(self->targetObj);
        if (pl == NULL) {
            self->fsm->st = 0x15;
            break;
        }
        {
            s32 r = self->unk_d2 + 8;
            if (r > 0x2000) {
                r = 0x2000;
            } else if (r < 0) {
                r = 0;
            }
            self->unk_d2 = r;
        }
        t = pl->pos;
        d = Ov013_DistXZ3(&self->pos, &t);
        if (d > 0x5000) {
            d = 0x5000;
        }
        t.y -= FX_Mul(d, 0x99a);
        Ov013_Steer(self, &t, self->unk_d2);
        VEC_MultAdd(self->speed, &self->unk_d4, &self->pos, &self->pos);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer % 20 == 0) {
                func_0204a028(data_02097e4c, 9, &self->pos, -5);
            }
        }
        break;
    }
    case 0x15:
        func_ov000_02198360(st, 0x15, 0);
        break;
    }
    self->rot_y += self->unk_d0;
    {
        VecFx32 off = data_ov013_0220b2a8;
        func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &off, 0, 0x3000, 0xccd, 0x64, 0x1000);
    }
}

}
}  // namespace m_02205fa4
