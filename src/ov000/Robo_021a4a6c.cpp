#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
} S18_021a4a6c;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} H22_021a4a6c;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 x;
} Msg_021a4a6c;

extern "C" {
extern char data_ov000_021cc666[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc66c[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc672[];
extern char data_ov000_021cc5e3[];
extern void *data_02097e4c;
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_021b1fac(Robo021ca458 *self, BOOL a, s32 b);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *a);
void func_ov000_021911c8(void *a, s32 b);
void *func_ov000_02191318(void *a, s32 frame);
void func_ov000_02191418(void *a, s32 b, s32 c);
void func_ov000_021915a0(void *a);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL Hit_DiffInCylinder(void *hit, VecFx32 *pos, s32 r, s32 h);
BOOL Hit_DiffInSphere(void *a, VecFx32 *b, s32 r);
void Actor_TurnToActor(Actor *self, void *other, s32 step);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void Target_Set(void *body, void *p);
void func_02062764(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_ov000_02182590(void *p);
void func_ov000_021899d8(VecFx32 *a, s32 b, s32 c, s32 d, s16 e, s16 f);

static inline BOOL IsBusy_021a4a6c(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL IsIdle_021a4a6c(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_021a4a6c(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline Actor *FindActor_021a4a6c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u8 *FindActor2_021a4a6c(u16 id) {
    u8 *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = (u8 *)ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return a;
}

static inline u16 AngleTo_021a4a6c(Robo021ca458 *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline s32 FxMul_021a4a6c(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Falling_021a4a6c(Robo021ca458 *self) {
    BOOL drop = FALSE;
    if (!(self->hit->unk_54 & 0x20000000)) {
        s32 lim = -0xf000;
        if (self->unk_b22_0 != 0 || self->unk_b24_12 != 0 || self->unk_b24_19) {
            lim = -0x2d000;
        }
        if (self->pos.y - self->unk_afc.y < lim) {
            drop = TRUE;
        }
    }
    return drop;
}

void func_ov000_021a4a6c(Robo021ca458 *self) {
    Actor *t;
    ActorSub4c *sub;
    VecFx32 p1;
    VecFx32 p2;
    VecFx32 o;
    VecFx32 d;
    Msg_021a4a6c m;

    t = NULL;
    sub = NULL;
    if (IsIdle_021a4a6c()) {
        t = FindActor_021a4a6c(self->target);
        if (t != NULL && t->unk_44 != NULL && t->unk_44->unk_22_0 == 1 &&
            t->unk_44->unk_22_1 == 1) {
            sub = (ActorSub4c *)((u8 *)t->targetObj);
            if (self->unk_b2f == 0) {
                self->unk_b2f++;
            }
        }
    }
    switch (self->fsm->st) {
    case 0:
        self->unk_b24_17 = 0;
        if (self->unk_b2c_4 == 3) {
            EffectObj *e;
            self->unk_b24_7 = 2;
            self->unk_b36 = 0;
            func_ov000_02190cb0(self->model, data_ov000_021cc666, 0x800, 1);
            e = func_02065f88(0x391, &self->pos);
            e->AddPosXYZ(0, (self->height >> 1) + (self->height >> 3), 0);
            e->SetScaleAll(0x1333);
            e->speed = 0x2ccd;
            func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
            self->speed = 0;
            self->friction = 0;
        } else if (self->unk_b22_3) {
            self->unk_b24_7 = 2;
            self->unk_b36 = 0;
            func_ov000_02190cb0(self->model, data_ov000_021cc64e, 0x800, 1);
            func_ov000_021911c8(self->model, 0x2800);
        } else {
            self->unk_b24_7 = self->unk_b24_9;
            if (sub != NULL && sub->type == 0xf) {
                if ((u16)(t->id & 0xf000) != 0x4000 || (self->hit->unk_50 & 0x20000000)) {
                    self->unk_b24_7 = 2;
                    self->speed = 0;
                    self->friction = 0;
                }
            }
        }
        switch (self->unk_b24_7) {
        case 0:
            self->unk_b24_9 = 1;
            func_ov000_02190cb0(self->model, data_ov000_021cc64e, 0x800, 1);
            break;
        case 1:
            self->unk_b24_9 = 0;
            func_ov000_02190cb0(self->model, data_ov000_021cc66c, 0x800, 1);
            break;
        }
        if (self->unk_b24_12 == 0 && !(self->hit->unk_50 & 0x20000000)) {
            BOOL f;
            if (self->velY < 0 || self->gravity == 0) {
                self->gravity = 0x29;
            }
            f = FALSE;
            if (!(self->msg_flags & 0x80)) {
                s32 dy = self->pos.y - self->hit->check.y;
                if (dy <= 0 && !(self->hit->unk_54 & 0x20000000)) {
                    if (self->velY > 0) {
                        self->velY = 0;
                    }
                    f = TRUE;
                } else if (dy > 0x28cd) {
                    f = TRUE;
                }
            }
            if (!f) {
                if (self->velY <= 0) {
                    self->velY = 0x2e;
                } else {
                    self->velY -= self->velY >> 2;
                }
            }
        }
        self->unk_b2c_0 = 0;
        self->unk_b2c_1 = 0;
        self->unk_b2c_2 = 0;
        self->unk_b2c_3_f = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->unk_b24_7 == 2) {
            if (!self->unk_b22_3 && self->unk_b2c_4 < 3) {
                if (sub != NULL && t != NULL) {
                    self->moveYaw = AngleTo_021a4a6c(self, t);
                    if ((self->hit->unk_50 & 0x20000000) && self->unk_b24_22 == 0) {
                        ActorSub40 *st;
                        p1 = self->pos;
                        p1.y -= 0x1000;
                        st = self->fsm;
                        st->timer++;
                        if (st->timer < 0x14 && !Hit_DiffInCylinder(&t->pos, &p1, (t->radius << 1) + 0x1000, 0x4800)) {
                            func_ov000_02190cb0(self->model, data_ov000_021cc61e, 0x400, 0);
                            func_ov000_021915a0(self->model);
                            self->speed = 0x229;
                            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
                            goto end;
                        }
                    }
                }
                func_ov000_02190cb0(self->model, data_ov000_021cc672, 0x800, 1);
                self->speed = 0;
                self->friction = 0;
            }
            if (sub != NULL && self->unk_93_4) {
                ActorSub48 *q;
                if (!self->unk_b22_3 && self->unk_b2c_4 < 3) {
                    func_ov000_02191318(self->model, 0x16000);
                }
                q = t->hit;
                if ((u16)(t->id & 0xf000) == 0x5000 && sub->type == 0xf) {
                    u32 fl = self->hit->unk_50 & 0x20000000;
                    if (fl == 0 || (t->unk_92 == 0 && q != NULL && !(q->unk_50 & 0x20000000))) {
                        if (self->unk_b24_22 != 1 && t->unk_92 == 0 && fl == 0 && q != NULL && !(q->unk_50 & 0x20000000)) {
                            self->unk_b24_22 = 2;
                        } else {
                            self->unk_b24_22 = 1;
                        }
                        func_ov000_021911c8(self->model, 0x3800);
                        self->gravity = 0x29;
                        if (self->velY > 0) {
                            self->velY -= self->velY >> 1;
                        } else {
                            self->velY = 0;
                        }
                        goto next;
                    }
                }
                self->unk_b24_22 = 0;
                func_ov000_021911c8(self->model, 0x1800);
                goto next;
            }
            self->unk_b24_22 = 0;
        } else {
            self->unk_b24_22 = 0;
        }
    next:
        self->fsm->timer = 0;
        self->fsm->st++;
    case 2:
        if (self->unk_b24_7 == 2) {
            Actor_TurnToActor(self, t, 0x400);
        }
        if (self->unk_b24_5 != 0) {
            break;
        }
        if (self->model->anim_state < 1) {
            break;
        }
        self->fsm->st++;
    case 3:
        if (self->unk_b24_12 == 0 && self->velY < 0) {
            self->gravity = 0x29;
        }
        if (sub != NULL) {
            ActorSub44 *h = NULL;
            BOOL ok = FALSE;
            u8 k = sub->type;
            if (self->unk_b22_3 || self->unk_b2c_4 == 3) {
                if (k == 0xf || k == 0xe || k == 5) {
                    ok = TRUE;
                }
            } else if ((k == 0xf && self->unk_b24_7 == 2) || (k == 0xe && self->unk_b24_7 != 2) || (k == 5 && self->unk_b24_7 != 2)) {
                ok = TRUE;
            }
            if (ok) {
                h = t->unk_44;
            }
            if (h != NULL) {
                s32 r;
                BOOL hit;
                p2 = self->pos;
                p2.y += self->centerY;
                r = 0x3000;
                if (self->unk_b22_3) {
                    r += 0x1800;
                }
                if (self->unk_b2c_4 == 3) {
                    r = 0x7000;
                }
                r += self->radius;
                if (h->unk_22_0 == 1 && h->unk_22_1 == 1) {
                    hit = Hit_DiffInSphere(h, &p2, r + h->unk_1c);
                } else {
                    hit = FALSE;
                }
                if (hit) {
                    u16 id;
                    func_02049f44(data_02097e4c, 0xc, &self->pos, 0);
                    if (self->unk_b24_22 == 0) {
                        func_ov000_02191418(self->model, 4, 0);
                    }
                    if (self->unk_b24_7 == 2) {
                        if (self->unk_b22_3) {
                            self->unk_b24_5 = 1;
                        } else if (self->unk_b2c_4 == 3) {
                            if (k == 0xf) {
                                self->unk_b24_5 = 2;
                            } else {
                                self->unk_b24_5 = 1;
                            }
                        } else {
                            self->unk_b24_5 = 2;
                        }
                    } else {
                        self->unk_b24_5 = 1;
                    }
                    if (self->unk_b24_5 == 2 && self->unk_b24_22 == 0) {
                        func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    }
                    id = self->target;
                    self->unk_b1c = id;
                    self->target = 0xffff;
                    func_ov000_0218d46c(t, self->id, 9);
                    Target_Set(sub, self);
                    if (sub->unk_18_1) {
                        func_02062764(0x3c0, 0x200);
                        func_020627a0(t->kind, t->id);
                        FieldState *g = data_ov000_021ccd54;
                        g->stageFlags = 1;
                        func_ov000_02182590((u8 *)g + 0xac);
                    }
                    self->fsm->st = 10;
                    break;
                }
            }
        } else if (self->unk_b24_22 == 0 && self->unk_b22_3 && data_0214a424->bits18.mode == 1 && self->unk_b36 >= 6) {
            func_ov000_02198360(self->fsm, 0xf, 0);
            break;
        }
        if (self->model->anim_state == 2 || func_ov000_02191120(self->model)) {
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
            self->fsm->st = 10;
        }
        break;
    case 10: {
        BOOL done;
        t = FindActor_021a4a6c(self->unk_b1c);
        if (t != NULL) {
            sub = (ActorSub4c *)((u8 *)t->targetObj);
        } else {
            sub = NULL;
        }
        if (!func_ov000_02191120(self->model) && self->fsm->flags == 0) {
            break;
        }
        if (t == NULL) {
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
        }
        done = FALSE;
        if (sub != NULL) {
            if (sub->unk_01 == 4) {
                self->unk_b24_7 = 2;
                func_ov000_02198360(self->fsm, 0xd, 0);
                done = TRUE;
            } else {
                if (!self->unk_b22_3 && self->unk_b24_5 == 1) {
                    self->unk_b24_7 = 0;
                }
                if (self->unk_b24_22 == 0) {
                    self->gravity = 0x52;
                } else {
                    func_ov000_02198360(self->fsm, 0xb, 0);
                    done = TRUE;
                }
            }
        } else if (self->unk_b2c_4 < 3) {
            u64 keys = self->fsm->flags;
            if (keys & 0x80) {
                BOOL drop = Falling_021a4a6c(self);
                if (drop) {
                    self->unk_b24_18 = 1;
                } else {
                    func_ov000_02198360(self->fsm, 7, 1);
                    done = TRUE;
                }
                self->unk_b2f = 0;
            } else if (keys & 8) {
                if (self->hit->unk_50 & 0x20000000) {
                    func_ov000_02198360(self->fsm, 3, 0);
                    done = TRUE;
                }
            }
        }
        if (!done) {
            if (self->unk_b2c_4 == 3 && sub == NULL) {
                func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x89, 0);
                self->fsm->timer = 0;
                self->fsm->st++;
            } else {
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        self->unk_b2c_4 = 0;
        break;
    }
    case 11: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 0xf) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    }
end:
    if (!func_ov000_02191508(self->model)) {
        BOOL turned;
        if (self->unk_b24_7 == 2 && !self->unk_b22_3) {
            func_ov000_021b1fac(self, FALSE, 1);
        } else {
            s32 spd = self->unk_b08 >> 1;
            if (!(self->hit->unk_50 & 0x20000000)) {
                spd >>= 2;
            }
            if (spd > 0x252) {
                spd = 0x252;
            }
            func_ov000_021b1dd8((u8 *)self, spd, 0x200, 0xe00, 0x466, 1);
        }
        turned = FALSE;
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
            turned = TRUE;
        }
        if (turned) {
            Actor *a;
            func_ov000_02198360(self->fsm, 4, 0);
            a = (Actor *)FindActor2_021a4a6c(self->unk_b1c);
            if (a != NULL) {
                m.pos.x = self->pos.x;
                m.pos.y = self->pos.y;
                m.pos.z = self->pos.z;
                m.pos.y += self->centerY;
                m.rot[0] = a->rot_x;
                m.rot[1] = a->rot_y;
                m.rot[2] = a->rot_z;
                m.x = 0;
                Actor_SendMsg(a, self->id, 7, TRUE, 0x18, &m);
                func_ov000_0218d46c(a, self->id, 10);
                if (a->targetObj != NULL) {
                    a->targetObj->unk_18_0 = 0;
                }
            }
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
        }
    }
    if (t == NULL || sub == NULL) {
        return;
    }
    if (sub->unk_18_4 ? TRUE : FALSE) {
        return;
    }
    if (self->unk_b22_0 != 0) {
        return;
    }
    {
        s32 c = 0;
        s16 e = 0x1000;
        if (self->unk_b24_22 == 2 && self->unk_b1c != 0xffff) {
            d = t->pos;
            d.x -= self->pos.x;
            d.y -= self->pos.y;
            d.z -= self->pos.z;
            d.x = FxMul_021a4a6c(d.x, 0x733);
            d.y = FxMul_021a4a6c(d.y, 0x733);
            d.z = FxMul_021a4a6c(d.z, 0x733);
            d.y = self->height;
            VEC_Add(&d, (VecFx32 *)((u8 *)self + 0x70), &o);
            c = 0x6f33;
            e = 0x2000;
        }
        if (c == 0) {
            return;
        }
        func_ov000_021899d8(&o, 0, c, 1, e, 0x1000);
    }
}

}
