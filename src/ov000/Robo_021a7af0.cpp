#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"
#include "ov000/FieldMgr.h"


extern "C" {
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
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL Model0218fe1c_IsAnimDone(void *a);
s32 Model0218fe1c_SetAnim(void *model, const char *name, s16 blend, u8 force);
void *Model0218fe1c_SetAnimFrame(void *model, s32 frame);
void Model0218fe1c_SetAnimSpeed(void *model, s16 speed);
s32 History_SetState(void *history, u8 value, BOOL force);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);
void Body_Update(void *body, u8 keep, VecFx32 *pos, const void *rot);
BOOL Hit_DiffInCylinder(void *a, void *b, s32 c, s32 d);
s32 **Model0218fe1c_GetAnimCtrl(void *model, u32 i);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 volume, s32 targetVolume, s32 frame);
void Robo021ca458_Move(Robo021ca458 *self, BOOL a, s32 b);
void Model0218fe1c_SetLoop(void *p);
void Actor_TurnToActor(Actor *self, void *other, s32 a);
void Field_ShakeCamera(u8 a, u8 b);
s32 SndMgr_PlayPan(void *mgr, s32 id, s32 pan);
void Shared_SetEventActor(u16 a, u16 b);
void func_020627dc(u16 a);
void func_ov000_02182590(void *p);
void Model0218fe1c_SetAnimDelay(void *model, u16 delay, BOOL force);
s32 Rand_PlusMinus(s32 max);
u32 Rand_UpTo(u32 max);
u8 func_0206d37c(void *flags, u32 i);
void Actor_SendMsgU8(void *actor, u16 id, u8 value);
void Target_Set(void *a, void *b);
u8 *Target_Get(void *p);
u16 Actor_YawToPos(Actor *self, void *target);
void *SndMgr_PlayAt(void *mgr, s32 id, void *pos, s32 pan);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s16 d, s16 e);
void func_ov000_02168490(Lo021cb894 *self, s32 a, s32 b, VecFx32 *p, VecFx32 *q);
void Shared_ChangeFlags(u16 clear, u16 set);

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
    s32 **a = Model0218fe1c_GetAnimCtrl(m, f);
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

static inline BOOL Flag19_021a7af0(FieldMgr *g) {
    LangBlockB *p = g->blockB;
    if (p != NULL && p->unk_19_0) {
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
    History_SetState(st, 3, 0);
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
        if (Model0218fe1c_IsAnimDone(self->model)) {
            if (t != NULL) {
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc672, 0x111, 0);
                Model0218fe1c_SetAnimFrame(self->model, 0x17000);
                Model0218fe1c_SetAnimSpeed(self->model, 0);
                self->fsm->timer = 0xf;
                self->fsm->st++;
            } else {
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc5e3, 0x89, 0);
                History_SetState(self->fsm, 1, 0);
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
            Body_Update(self->hit, 0, NULL, NULL);
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
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc62a, 0x800, 0);
                History_SetState(self->fsm, 4, 0);
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
            History_SetState(st, 1, 0);
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
            Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
            self->unk_b1e = t->id;
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0x52;
            self->fsm->timer = 0;
            self->fsm->st = 10;
            return;
        } else {
            History_SetState(st, 1, 0);
        }
        return;
    case 0:
        self->unk_b24_27 = 0;
        if (self->unk_b2c_4 == 3) {
            EffectObj *o;
            self->unk_b2c_4 = 0;
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc666, 0x800, 1);
            o = Effect_SpawnId(0x391, &self->pos);
            o->AddPosXYZ(0, (self->height >> 1) + (self->height >> 3), 0);
            o->SetScaleAll(0x1333);
            o->speed = 0x2ccd;
            SndMgr_PlayVolume(data_02097e4c, 0x44, -1, -1, -1);
            self->fsm->st = 0x64;
            return;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            self->speed = 0;
            self->moveYaw = AngleTo_021a7af0(self, t);
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            Robo021ca458_Move(self, FALSE, 1);
            Bump_021a7af0(self);
            {
                ActorSub40 *s = self->fsm;
                s->timer++;
                if (s->timer >= 0x1e) {
                    History_SetState(self->fsm, 4, 0);
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
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc61e, 0x400, 0);
                Model0218fe1c_SetLoop(self->model);
                self->speed = 0x229;
                self->hit->unk_9a |= 0x20;
                Robo021ca458_Move(self, FALSE, 1);
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
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc62a, 0x800, 0);
                History_SetState(self->fsm, 4, 0);
                return;
            }
        }
        {
            s16 rate = 0x159a;
            char *anim = !self->unk_b22_3 ? data_ov000_021cc672 : data_ov000_021cc64e;
            if (info != NULL && info->type == 0x14) {
                rate = 0x1c00;
            }
            Model0218fe1c_SetAnim(self->model, anim, 0x800, 1);
            Model0218fe1c_SetAnimSpeed(self->model, rate);
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
                Robo021ca458_Move(self, FALSE, 1);
                Bump_021a7af0(self);
            }
        }
        Actor_TurnToActor(self, t, 0x400);
        if (Model0218fe1c_IsAnimDone(self->model)) {
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
        o = Effect_SpawnId(0x193, &self->pos);
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
            Field_ShakeCamera(9, 0xf);
            v = t->pos;
            v.y += t->height + 0x400;
            o2 = Effect_SpawnId(0x44c, &v);
            o2->speed = 0x99a;
            o2->SetScaleAll(0x1400);
            m = self->model;
            m->color = 0x73ff;
            m->color2 = 0x73ff;
            m->blend = 5;
            m->blendMax = 4;
            SndMgr_PlayPan(data_02097e4c, 0x4a, -5);
        } else {
            Field_ShakeCamera(6, 10);
        }
        SndMgr_PlayVolume(data_02097e4c, 0x45, -1, -1, -1);
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
                Robo021ca458_Move(self, FALSE, 1);
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
                        Shared_SetEventActor(t->kind, t->id);
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
            Param0206ef10 *p = self->unk_ba4;
            if (p != NULL && p->unk_06_8 && self->unk_b36 >= 0x10) {
                self->unk_b24_5 = 0;
                self->unk_b1c = 0xffff;
                self->unk_b1e = 0xffff;
                self->unk_b24_7 = self->unk_b24_9;
                self->unk_b3a = 0;
                self->unk_93_5 = 1;
                History_SetState(self->fsm, 0x1c, 0);
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
        Model0218fe1c_SetAnimDelay(self->model, 1, 0);
        {
            s32 fr = Frame_021a7af0(self->model);
            Model0218fe1c_SetAnimFrame(self->model, fr + ((self->unk_b60 - fr) >> 3));
        }
        if (self->padTrig & 1) {
            s16 n;
            self->fsm->timer = 0;
            Model0218fe1c_SetAnimFrame(self->model, self->unk_b60 + 0x3000);
            SndMgr_PlayVolume(data_02097e4c, 0x2a, -1, -1, -1);
            if (!self->unk_b22_3) {
                EffectObj *o = Effect_SpawnId(0x44d, &self->pos);
                s32 a = Rand_PlusMinus(0x4cd);
                s32 b = Rand_UpTo(0x800);
                s32 c = Rand_PlusMinus(0x4cd);
                o->AddPosXYZ(a, b, c);
                o->SetScaleAll((data_ov000_021ccd68->frame & 0xff) + 0xf00);
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
                    Actor_SendMsgU8(t, self->id, 0x14);
                    if (x50 != NULL) {
                        x50->unk_04 = self->id;
                        x50->dmg = 0;
                        x50->kind = 0;
                        x50->kind2 = 0;
                    }
                    Model0218fe1c_SetAnimSpeed(self->model, 0x159a);
                } else if (kind == 0x13) {
                    if (self->unk_b22_3 && info->unk_01 == 1) {
                        self->unk_b24_5 = 1;
                    } else {
                        self->unk_b24_5 = 2;
                    }
                    self->unk_b24_7 = 2;
                    self->unk_b1c = self->target;
                    self->target = 0xffff;
                    Actor_SendMsgU8(t, self->id, 9);
                    Target_Set(info, self);
                    SndMgr_PlayVolume(data_02097e4c, 0x302, -1, -1, -1);
                    Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
                } else if (kind == 0x12) {
                    SndMgr_PlayVolume(data_02097e4c, 0x302, -1, -1, -1);
                    History_SetState(self->fsm, 6, 0);
                } else if (kind == 0x14) {
                    u8 *p;
                    EffectObj *o;
                    self->target = 0xffff;
                    Actor_SendMsgU8(t, self->id, 0xb);
                    p = Target_Get(info);
                    if (p == NULL) {
                        t->rot_y = self->rot_y;
                    } else {
                        t->rot_y = Actor_YawToPos(t, LFLD(void *, p, 0x44));
                        t->target = LFLD(u16, p, 0xc);
                    }
                    Target_Set(info, self);
                    SndMgr_PlayVolume(data_02097e4c, 0x302, -1, -1, -1);
                    SndMgr_PlayAt(data_02097e4c, 0x2c, &self->pos, 0);
                    Field_ShakeCamera(8, 0xc);
                    o = Effect_SpawnId(0x69, &self->pos);
                    if (o != NULL) {
                        o->AddPosXYZ(0, self->centerY, 0);
                    }
                    Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
                }
            }
        }
        Actor_TurnToActor(self, t, 0x400);
        {
            FieldMgr *g = data_ov000_021ccd6c;
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
                    SndMgr_PlayAt(data_02097e4c, 0x29, &self->pos, 0);
                    SndMgr_PlayVolume(data_02097e4c, self->unk_b3c > 0x28 ? 0x303 : 0x302, -1, -1, -1);
                    Field_ShakeCamera(4, 5);
                }
            } else if (kind == 0x13) {
                if (t != NULL && SubKind_021a7af0(t) == 9 && info->unk_18_1) {
                    FieldState *g;
                    Shared_ChangeFlags(0x3c0, 0x200);
                    Shared_SetEventActor(t->kind, t->id);
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
        if (Model0218fe1c_IsAnimDone(self->model) || self->model->anim_state == 2) {
            Model0218fe1c_SetAnimSpeed(self->model, 0x800);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        Tail13_021a7af0(self);
        return;
    case 14:
        st->timer++;
        if (st->timer >= 0xf) {
            History_SetState(self->fsm, 1, 0);
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
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc5e3, 0x200, 0);
        History_SetState(self->fsm, 1, 0);
        return;
    case 0x1e:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc636, 0x1000, 1);
        SndMgr_PlayAt(data_02097e4c, 0x73, &self->pos, 0);
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
        Robo021ca458_Move(self, f, 1);
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
            History_SetState(self->fsm, 4, 0);
            return;
        }
        s = self->fsm;
        s->timer++;
        if (s->timer >= 0x1e) {
            History_SetState(self->fsm, 4, 0);
            return;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc630, 0x800, 0);
        self->friction = 0xe66;
        SndMgr_PlayAt(data_02097e4c, 0x81, &self->pos, 0);
        Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x800);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 0x20: {
        ActorSub40 *s;
        f = FALSE;
        Robo021ca458_Move(self, f, 1);
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
            History_SetState(self->fsm, 4, 0);
            return;
        }
        s = self->fsm;
        s->timer++;
        if (s->timer > 0x1e) {
            History_SetState(self->fsm, 1, 0);
        }
        return;
    }
    }
}
}
