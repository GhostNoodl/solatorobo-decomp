#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 rest : 7;
} Ba4_021a7af0;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B19_021a7af0;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd6c;
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern char data_ov000_021cc672[];
extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc666[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc636[];
extern char data_ov000_021cc630[];
Actor *ActorMgr_GetActor(void *mgr, u16 id);
BOOL func_ov000_02191120(void *a);
s32 func_ov000_02190cb0(void *model, const char *name, s16 blend, u8 force);
void *func_ov000_02191318(void *model, s32 frame);
void func_ov000_021911c8(void *model, s16 speed);
s32 func_ov000_02198360(void *history, u8 value, BOOL force);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);
void func_ov000_021987b8(void *body, u8 keep, VecFx32 *pos, const void *rot);
BOOL Hit_DiffInCylinder(void *a, void *b, s32 c, s32 d);
s32 **func_ov000_02190a30(void *model, u32 i);
void *func_02049a48(void *mgr, s32 id, s32 volume, s32 targetVolume, s32 frame);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021915a0(void *p);
void Actor_TurnToActor(void *self, void *other, s32 a);
void func_ov000_0218996c(u8 a, u8 b);
s32 func_02049bdc(void *mgr, s32 id, s32 pan);
void func_020627a0(u16 a, u16 b);
void func_020627dc(u16 a);
void func_ov000_02182590(void *p);
void func_ov000_02191418(void *model, u16 delay, BOOL force);
s32 Rand_PlusMinus(s32 max);
u32 Rand_UpTo(u32 max);
u8 func_0206d37c(void *flags, u32 i);
void func_ov000_0218d46c(void *actor, u16 id, u8 value);
void Target_Set(void *a, void *b);
u8 *Target_Get(void *p);
u16 Actor_YawToPos(void *self, void *target);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 pan);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s16 d, s16 e);
void func_ov000_02168490(void *self, s32 a, s32 b, VecFx32 *p, VecFx32 *q);
void func_02062764(u16 clear, u16 set);

static inline Actor *FindActor_021a7af0(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 AngleTo_021a7af0(Robo021ca458 *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline s32 Frame_021a7af0(Model0218fe1c *m) {
    s32 f = 0;
    s32 **a = func_ov000_02190a30(m, f);
    if (*a != NULL) {
        f = **a;
    }
    return f;
}

static inline s32 FxMul_021a7af0(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL IsBusy_021a7af0(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL IsIdle_021a7af0(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_021a7af0(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 SubKind_021a7af0(Actor *a) {
    return a->fsm != NULL ? a->fsm->current : 0;
}

static inline void Gauge_021a7af0(s32 a, s32 b, VecFx32 *p, VecFx32 *q) {
    ListBuffer021cb940 *o = data_ov000_021ccd30->unk_11c;
    if (o == NULL) {
        return;
    }
    if (o->unk_74 == NULL) {
        return;
    }
    func_ov000_02168490(o->unk_74, a, b, p, q);
}

static inline BOOL Flag19_021a7af0(u8 *g) {
    u8 *p = LFLD(u8 *, g, 0x14);
    if (p != NULL && LFLD(B19_021a7af0, p, 0x19).b0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Info18b4_021a7af0(ActorSub4c *info) {
    return info->unk_18_4 ? TRUE : FALSE;
}

static inline BOOL HasD4_021a7af0(FieldState *g) {
    return ((s32)g->event) != 0;
}

static inline void Bump_021a7af0(Robo021ca458 *self) {
    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        self->unk_b24_17 = 1;
    }
}

static inline void Tail13_021a7af0(Robo021ca458 *self) {
    ActorSub40 *st = self->fsm;
    if (!(st->flags & 8)) {
        return;
    }
    if (!(self->hit->unk_50 & 0x20000000)) {
        return;
    }
    func_ov000_02198360(st, 3, 0);
}

void func_ov000_021a7af0(Robo021ca458 *self) {
    Actor *t;
    ActorSub4c *info;
    ActorHp *x50;
    ActorSub40 *st;
    VecFx32 v;
    BOOL f;
    u16 id;

    id = self->unk_b1e;
    if (id == 0xffff) {
        id = self->unk_b1c;
        if (id == 0xffff) {
            id = self->target;
        }
    }
    t = FindActor_021a7af0(id);
    info = NULL;
    x50 = NULL;
    if (t != NULL) {
        ActorSub44 *c = t->unk_44;
        if (self->unk_b1c != 0xffff ||
            (c != NULL && c->unk_22_0 == 1 && c->unk_22_1 == 1)) {
            info = t->targetObj;
            x50 = (ActorHp *)t->hp;
            if (self->unk_b2f == 0) {
                self->unk_b2f++;
            }
        }
    }
    st = self->fsm;
    switch (st->st) {
    case 0x64:
        if (func_ov000_02191120(self->model)) {
            if (t != NULL) {
                func_ov000_02190cb0(self->model, data_ov000_021cc672, 0x111, 0);
                func_ov000_02191318(self->model, 0x17000);
                func_ov000_021911c8(self->model, 0);
                self->fsm->timer = 0xf;
                self->fsm->st++;
            } else {
                func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x89, 0);
                func_ov000_02198360(self->fsm, 1, 0);
                return;
            }
        }
        if (t == NULL) {
            return;
        }
        self->moveYaw = AngleTo_021a7af0(self, t);
        self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        return;
    case 0x65:
        if (t != NULL) {
            v = t->pos;
            v.x -= self->pos.x;
            v.y -= self->pos.y;
            v.z -= self->pos.z;
            v.x = FxMul_021a7af0(v.x, 0x1ec);
            v.y = FxMul_021a7af0(v.y, 0x1ec);
            v.z = FxMul_021a7af0(v.z, 0x1ec);
            v.y *= 3;
            VEC_Add((VecFx32 *)((u8 *)self + 0x70), &v, (VecFx32 *)((u8 *)self + 0x70));
            v = self->pos;
            v.y -= 0x1000;
            self->moveYaw = AngleTo_021a7af0(self, t);
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            f = FALSE;
            func_ov000_021987b8(self->hit, 0, NULL, NULL);
            if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
                self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
                self->speed = 0x66;
                self->friction = 0;
                if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                    self->velY = 0x200;
                }
                self->gravity = 0x52;
                self->unk_b24_17 = 1;
                f = TRUE;
            }
            if (f) {
                func_ov000_02190cb0(self->model, data_ov000_021cc62a, 0x800, 0);
                func_ov000_02198360(self->fsm, 4, 0);
                return;
            }
            {
                ActorSub40 *s = self->fsm;
                if (s->timer != 0) {
                    s->timer--;
                }
            }
            if (self->fsm->timer == 0 || Hit_DiffInCylinder(&t->pos, &v, t->radius * 2 + 0x99a, 0x3800)) {
                self->fsm->st++;
                return;
            }
            if (self->hit->unk_50 & 0x40000000) {
                self->fsm->st = 0x1e;
            }
            return;
        } else {
            func_ov000_02198360(st, 1, 0);
        }
        return;
    case 0x66:
        if (t != NULL) {
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer != 0) {
                return;
            }
            self->unk_b60 = Frame_021a7af0(self->model);
            func_ov000_021911c8(self->model, 0x1000);
            self->unk_b1e = t->id;
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0x52;
            self->fsm->timer = 0;
            self->fsm->st = 10;
            return;
        } else {
            func_ov000_02198360(st, 1, 0);
        }
        return;
    case 0:
        self->unk_b24_27 = 0;
        if (self->unk_b2c_4 == 3) {
            EffectObj *o;
            self->unk_b2c_4 = 0;
            func_ov000_02190cb0(self->model, data_ov000_021cc666, 0x800, 1);
            o = func_02065f88(0x391, &self->pos);
            o->AddPosXYZ(0, (self->height >> 1) + (self->height >> 3), 0);
            o->SetScaleAll(0x1333);
            o->speed = 0x2ccd;
            func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
            self->fsm->st = 0x64;
            return;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            self->speed = 0;
            self->moveYaw = AngleTo_021a7af0(self, t);
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            func_ov000_021b1fac(self, FALSE, 1);
            Bump_021a7af0(self);
            {
                ActorSub40 *s = self->fsm;
                s->timer++;
                if (s->timer >= 0x1e) {
                    func_ov000_02198360(self->fsm, 4, 0);
                }
            }
        } else {
            self->unk_b24_22 = 0;
            st->timer = 0;
            self->fsm->st++;
        }
        return;
    case 1: {
        s32 r;
        s32 h;
        if (info == NULL) {
            st->st = 0x14;
            return;
        }
        self->moveYaw = AngleTo_021a7af0(self, t);
        self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        v = self->pos;
        v.y -= 0x1000;
        r = self->radius + 0x1000;
        h = 0x3800;
        if (self->unk_b22_3) {
            r += 0x400;
            h += 0x429;
        }
        {
            ActorSub40 *s = self->fsm;
            s->timer++;
            if (s->timer < 0x14 && !Hit_DiffInCylinder(&t->pos, &v, r + t->radius, h)) {
                u32 fl;
                f = FALSE;
                func_ov000_02190cb0(self->model, data_ov000_021cc61e, 0x400, 0);
                func_ov000_021915a0(self->model);
                self->speed = 0x229;
                self->hit->unk_9a |= 0x20;
                func_ov000_021b1fac(self, FALSE, 1);
                fl = self->hit->unk_50;
                if (fl & 0x40000000) {
                    self->fsm->st = 0x1e;
                    return;
                }
                if (!(fl & 0x20000000)) {
                    self->fsm->st = 0x1e;
                    return;
                }
                if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
                    self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
                    self->speed = 0x66;
                    self->friction = 0;
                    if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                        self->velY = 0x200;
                    }
                    self->gravity = 0x52;
                    self->unk_b24_17 = 1;
                    f = TRUE;
                }
                if (!f) {
                    return;
                }
                func_ov000_02190cb0(self->model, data_ov000_021cc62a, 0x800, 0);
                func_ov000_02198360(self->fsm, 4, 0);
                return;
            }
        }
        {
            s16 rate = 0x159a;
            char *anim = !self->unk_b22_3 ? data_ov000_021cc672 : data_ov000_021cc64e;
            if (info != NULL && info->type == 0x14) {
                rate = 0x1c00;
            }
            func_ov000_02190cb0(self->model, anim, 0x800, 1);
            func_ov000_021911c8(self->model, rate);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0x52;
            self->fsm->st = 10;
        }
        return;
    }
    case 10: {
        s32 r;
        s32 h;
        u16 bonus;
        EffectObj *o;
        if (info == NULL) {
            st->st = 0x1e;
            return;
        }
        v = self->pos;
        v.y -= 0x1000;
        r = self->radius + 0x2800;
        h = 0x3800;
        if (self->unk_b22_3) {
            r += 0x400;
            h += 0x429;
        }
        if (!Hit_DiffInCylinder(&t->pos, &v, r + t->radius, h)) {
            self->fsm->st = 0x1e;
            return;
        }
        {
            ActorSub48 *b = self->hit;
            if (!(b->unk_50 & 0x20000000)) {
                if (!(b->unk_54 & 0x20000000)) {
                    self->fsm->st = 0x1e;
                    return;
                }
                func_ov000_021b1fac(self, FALSE, 1);
                Bump_021a7af0(self);
            }
        }
        Actor_TurnToActor(self, t, 0x400);
        if (func_ov000_02191120(self->model)) {
            self->fsm->st = 0x1e;
            return;
        }
        if (self->model->anim_state != 3) {
            return;
        }
        bonus = 0;
        self->unk_b3a = 0;
        self->unk_b3c = info->unk_04;
        if (x50 != NULL) {
            u16 lim;
            u16 n;
            u16 d;
            self->unk_b2a |= 4;
            n = x50->unk_0e + 5;
            lim = self->unk_b3c - (self->unk_b3c >> 2);
            self->unk_b3a = x50->unk_0e;
            if (n > lim) {
                n = lim;
            }
            x50->unk_0e = n;
            d = (u16)(AngleTo_021a7af0(self, t) - t->rot_y) + 0x38e2;
            if (d <= 0x71c4) {
                if (d < 0x2aaa || d > 0x471a) {
                    bonus = (self->unk_b3c + 3) >> 2;
                } else {
                    bonus = (self->unk_b3c + 1) >> 1;
                }
            } else {
                s32 k = SubKind_021a7af0(t);
                if (k == 0x12 || k == 0x13 || t->unk_94_0) {
                    bonus = (self->unk_b3c + 3) >> 2;
                }
            }
        }
        o = func_02065f88(0x193, &self->pos);
        o->SetRotXYZ(0, self->rot_y, 0);
        o->speed = 0xccd;
        self->unk_b48 = o->id;
        self->unk_b5e = 0;
        self->unk_b4c = 0;
        self->unk_b50 = 0;
        self->unk_b54 = 0;
        self->unk_b58 = 0;
        self->unk_b5a = 0;
        self->unk_b5c = 0;
        if (bonus != 0) {
            EffectObj *o2;
            Model0218fe1c *m;
            self->unk_b3a += bonus;
            if (self->unk_b3a >= self->unk_b3c) {
                self->unk_b3a = self->unk_b3c - 1;
            }
            func_ov000_0218996c(9, 0xf);
            v = t->pos;
            v.y += t->height + 0x400;
            o2 = func_02065f88(0x44c, &v);
            o2->speed = 0x99a;
            o2->SetScaleAll(0x1400);
            m = self->model;
            m->color = 0x73ff;
            m->color2 = 0x73ff;
            m->blend = 5;
            m->blendMax = 4;
            func_02049bdc(data_02097e4c, 0x4a, -5);
        } else {
            func_ov000_0218996c(6, 10);
        }
        func_02049a48(data_02097e4c, 0x45, -1, -1, -1);
        self->unk_b60 = Frame_021a7af0(self->model);
        self->unk_b1e = t->id;
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 11: {
        s32 r;
        s32 h;
        if (info == NULL) {
            st->st = 0x1e;
            return;
        }
        {
            ActorSub48 *b = self->hit;
            if (!(b->unk_50 & 0x20000000)) {
                if (!(b->unk_54 & 0x20000000)) {
                    st->st = 0x1e;
                    return;
                }
                func_ov000_021b1fac(self, FALSE, 1);
                Bump_021a7af0(self);
            }
        }
        {
            u8 k = t->unk_94_1;
            if (k != 0) {
                BOOL stop = TRUE;
                if ((u8)(k + 0xfe) <= 1) {
                    if ((u16)(t->rot_y - self->rot_y + 0x4000) < 0x8000) {
                        stop = FALSE;
                    } else if (k == 3) {
                        FieldState *g;
                        func_020627a0(t->kind, t->id);
                        func_020627dc(5);
                        g = data_ov000_021ccd54;
                        g->stageFlags = stop;
                        func_ov000_02182590((u8 *)g + 0xac);
                    }
                }
                if (stop) {
                    self->fsm->st = 0x1e;
                    return;
                }
            }
        }
        v = self->pos;
        v.y -= 0x1000;
        r = self->radius + 0x2800;
        h = 0x3800;
        if (self->unk_b22_3) {
            r += 0x400;
            h += 0x429;
        }
        if (!Hit_DiffInCylinder(&t->pos, &v, r + t->radius, h)) {
            self->fsm->st = 0x1e;
            return;
        }
        {
            u8 *p = self->unk_ba4;
            if (p != NULL && LFLD(Ba4_021a7af0, p, 6).b8 && self->unk_b36 >= 0x10) {
                self->unk_b24_5 = 0;
                self->unk_b1c = 0xffff;
                self->unk_b1e = 0xffff;
                self->unk_b24_7 = self->unk_b24_9;
                self->unk_b3a = 0;
                self->unk_93_5 = 1;
                func_ov000_02198360(self->fsm, 0x1c, 0);
                return;
            }
        }
        if (IsIdle_021a7af0()) {
            self->fsm->timer++;
        }
        if ((self->padTrig & 2) || (self->fsm->timer >= 0x1e && (self->padCur & 0xf0))) {
            self->fsm->st = 0x14;
            return;
        }
        if (self->fsm->timer >= 0x4b) {
            if (self->unk_b3a > 1) {
                self->unk_b3a--;
                self->fsm->timer = 0x46;
            } else {
                self->unk_b3a = 0;
                self->fsm->st = 0x1e;
                return;
            }
        }
        func_ov000_02191418(self->model, 1, 0);
        {
            s32 fr = Frame_021a7af0(self->model);
            func_ov000_02191318(self->model, fr + ((self->unk_b60 - fr) >> 3));
        }
        if (self->padTrig & 1) {
            s16 n;
            self->fsm->timer = 0;
            func_ov000_02191318(self->model, self->unk_b60 + 0x3000);
            func_02049a48(data_02097e4c, 0x2a, -1, -1, -1);
            if (!self->unk_b22_3) {
                EffectObj *o = func_02065f88(0x44d, &self->pos);
                s32 a = Rand_PlusMinus(0x4cd);
                s32 b = Rand_UpTo(0x800);
                s32 c = Rand_PlusMinus(0x4cd);
                o->AddPosXYZ(a, b, c);
                o->SetScaleAll((LFLD(u16, data_ov000_021ccd68, 0xa) & 0xff) + 0xf00);
            }
            n = func_0206d37c(data_0214a424, 2);
            if (self->unk_b22_3) {
                n += 5;
            }
            n += 10;
            self->unk_b3a += (u16)n;
            if (self->unk_b3a >= self->unk_b3c) {
                u8 kind;
                self->unk_b3a = self->unk_b3c;
                self->unk_b1e = 0xffff;
                if (x50 != NULL) {
                    x50->unk_0e = 0;
                }
                self->hit->unk_9a_4 = 0;
                self->fsm->st++;
                kind = info->type;
                if (kind == 0x11) {
                    func_ov000_0218d46c(t, self->id, 0x14);
                    if (x50 != NULL) {
                        x50->unk_04 = self->id;
                        x50->dmg = 0;
                        x50->kind = 0;
                        x50->kind2 = 0;
                    }
                    func_ov000_021911c8(self->model, 0x159a);
                } else if (kind == 0x13) {
                    if (self->unk_b22_3 && info->unk_01 == 1) {
                        self->unk_b24_5 = 1;
                    } else {
                        self->unk_b24_5 = 2;
                    }
                    self->unk_b24_7 = 2;
                    self->unk_b1c = self->target;
                    self->target = 0xffff;
                    func_ov000_0218d46c(t, self->id, 9);
                    Target_Set(info, self);
                    func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    func_ov000_021911c8(self->model, 0x1000);
                } else if (kind == 0x12) {
                    func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    func_ov000_02198360(self->fsm, 6, 0);
                } else if (kind == 0x14) {
                    u8 *p;
                    EffectObj *o;
                    self->target = 0xffff;
                    func_ov000_0218d46c(t, self->id, 0xb);
                    p = Target_Get(info);
                    if (p == NULL) {
                        t->rot_y = self->rot_y;
                    } else {
                        t->rot_y = Actor_YawToPos(t, LFLD(void *, p, 0x44));
                        t->target = LFLD(u16, p, 0xc);
                    }
                    Target_Set(info, self);
                    func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    func_02049f44(data_02097e4c, 0x2c, &self->pos, 0);
                    func_ov000_0218996c(8, 0xc);
                    o = func_02065f88(0x69, &self->pos);
                    if (o != NULL) {
                        o->AddPosXYZ(0, self->centerY, 0);
                    }
                    func_ov000_021911c8(self->model, 0x1000);
                }
            }
        }
        Actor_TurnToActor(self, t, 0x400);
        {
            u8 *g = data_ov000_021ccd6c;
            VecFx32 w;
            VecFx32 u;
            v = t->pos;
            v.y += t->height - self->centerY;
            v.x -= self->pos.x;
            v.y -= self->pos.y;
            v.z -= self->pos.z;
            v.x = FxMul_021a7af0(v.x, 0x733);
            v.y = FxMul_021a7af0(v.y, 0x733);
            v.y += self->centerY;
            v.z = FxMul_021a7af0(v.z, 0x733);
            if (!Flag19_021a7af0(g) && !Info18b4_021a7af0(info) && !self->unk_b24_27) {
                if (!IsIdle_021a7af0() || HasD4_021a7af0(data_ov000_021ccd54)) {
                    self->unk_b24_27 = 1;
                }
                VEC_Add(&v, (VecFx32 *)((u8 *)self + 0x70), &w);
                func_ov000_021899d8(&w, 0, t->radius + 0x8ccd, 1, 0x2000, 0x1000);
            }
            u.x = 0;
            u.y = -0x2000;
            u.z = 0;
            Gauge_021a7af0(self->unk_b3a, self->unk_b3c, &v, &u);
        }
        return;
    }
    case 12:
        st->timer++;
        if (st->timer >= 4) {
            s32 kind = 0;
            if (info != NULL) {
                kind = info->type;
            }
            if (kind == 0xf) {
                if (t != NULL && SubKind_021a7af0(t) == 0x14) {
                    func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
                    func_02049a48(data_02097e4c, self->unk_b3c > 0x28 ? 0x303 : 0x302, -1, -1, -1);
                    func_ov000_0218996c(4, 5);
                }
            } else if (kind == 0x13) {
                if (t != NULL && SubKind_021a7af0(t) == 9 && info->unk_18_1) {
                    FieldState *g;
                    func_02062764(0x3c0, 0x200);
                    func_020627a0(t->kind, t->id);
                    g = data_ov000_021ccd54;
                    g->stageFlags = 1;
                    func_ov000_02182590((u8 *)g + 0xac);
                }
            }
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        self->hit->unk_9a_4 = 0;
        return;
    case 13:
        if (func_ov000_02191120(self->model) || self->model->anim_state == 2) {
            func_ov000_021911c8(self->model, 0x800);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        Tail13_021a7af0(self);
        return;
    case 14:
        st->timer++;
        if (st->timer >= 0xf) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        Tail13_021a7af0(self);
        return;
    case 0x14:
        self->unk_b1c = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b1e = 0xffff;
        self->unk_b24_7 = self->unk_b24_9;
        self->target = 0xffff;
        self->unk_b3a = 0;
        self->unk_b48 = 0;
        func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x200, 0);
        func_ov000_02198360(self->fsm, 1, 0);
        return;
    case 0x1e:
        func_ov000_02190cb0(self->model, data_ov000_021cc636, 0x1000, 1);
        func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
        self->unk_b1c = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->unk_b3a = 0;
        self->unk_b48 = 0;
        self->unk_b1e = 0xffff;
        self->moveYaw = self->rot_y + 0x8000;
        self->speed = 0x200;
        self->friction = 0xef6;
        self->target = 0xffff;
        self->velY = 0x10a;
        self->gravity = 0x52;
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    case 0x1f: {
        ActorSub40 *s;
        f = FALSE;
        func_ov000_021b1fac(self, f, 1);
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
            f = TRUE;
        }
        if (f) {
            func_ov000_02198360(self->fsm, 4, 0);
            return;
        }
        s = self->fsm;
        s->timer++;
        if (s->timer >= 0x1e) {
            func_ov000_02198360(self->fsm, 4, 0);
            return;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov000_021cc630, 0x800, 0);
        self->friction = 0xe66;
        func_02049f44(data_02097e4c, 0x81, &self->pos, 0);
        func_02065f88(0x12f, &self->pos)->SetScaleAll(0x800);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 0x20: {
        ActorSub40 *s;
        f = FALSE;
        func_ov000_021b1fac(self, f, 1);
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
            f = TRUE;
        }
        if (f) {
            func_ov000_02198360(self->fsm, 4, 0);
            return;
        }
        s = self->fsm;
        s->timer++;
        if (s->timer > 0x1e) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        return;
    }
    }
}
}
