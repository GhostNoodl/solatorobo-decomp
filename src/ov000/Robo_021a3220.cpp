#include "ov000/FieldCam.h"
#include "ov000/ActorMgr.h"
#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 b0 : 5;
    u16 b5 : 1;
    u16 rest : 10;
} Ba4_021a3220;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} B19_021a3220;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 x;
} Msg_021a3220;

extern "C" {
extern char data_ov000_021cc630[];
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc636[];
extern char *const data_ov000_021ca030[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd6c;
u8 *Actor_GetTarget(u8 *self);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void func_01ffc9fc(VecFx32 *out, const void *a, s32 b);
s32 Rand_UpTo(s32 max);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, VecFx32 *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);
u16 func_ov000_02198da8(void *body, u16 angle);
void func_ov000_0218996c(s32 a, s32 b);
void *func_ov000_021b68b8(void *a, void *pos);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

static inline Actor *FindActor_021a3220(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline u16 AngTo_021a3220(Robo021ca458 *self, Actor *t) {
    if (t == NULL || t == self) {
        return self->rot_y;
    }
    return FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
}

static inline BOOL IsBusy_021a3220(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL IsIdle_021a3220(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_021a3220(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

#define Ba4Bit_021a3220(self) (LFLD(u8 *, self, 0xba4) != NULL && LFLD(Ba4_021a3220, LFLD(u8 *, self, 0xba4), 6).b5)

void func_ov000_021a3220(Robo021ca458 *self) {
    Actor *tgt;
    BOOL hit;
    BOOL turned;

    tgt = (Actor *)Actor_GetTarget((u8 *)self);
    switch (self->fsm->st) {
    case 0: {
        self->unk_b24_17 = 0;
        func_ov000_02190cb0(self->model, data_ov000_021ca030[self->unk_b24_5], 0x555, 1);
        self->fsm->st++;
        if (self->unk_b2c_6) {
            self->fsm->timer = 5;
            func_02049f44(data_02097e4c, 0x79, &self->pos, 0);
        }
        if (self->velY == 0) {
            if (!self->unk_b2c_6) {
                func_02049f44(data_02097e4c, 7, &self->pos, 0);
            }
            if (!self->unk_93_4) {
                s32 se = 0x300;
                if (data_ov000_021ccd68->frame & 1) {
                    se = 0x304;
                }
                func_02049f44(data_02097e4c, se, &self->pos, 0);
            }
        }
        self->moveYaw = self->rot_y;
        self->speed >>= 3;
        self->velY >>= 3;
        if ((self->unk_b1c >> 12) == 5) {
            Actor *a = FindActor_021a3220(self->unk_b1c);
            ActorSub4c *s = NULL;
            if (a != NULL) {
                s = a->targetObj;
            }
            if (s != NULL && (s->type == 0xf || s->type == 0x11)) {
                self->unk_b24_22 = 1;
            }
        }
        self->unk_b2a_3 = 0;
    }
    case 1: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 5) {
            EffectObj *e;
            if (self->unk_b1c == 0xffff && tgt != NULL && (u16)(tgt->id & 0xf000) == 0x5000) {
                self->velY = (tgt->pos.y - self->pos.y) >> 4;
                self->moveYaw = AngTo_021a3220(self, tgt);
                self->gravity = 0x52;
            } else {
                if (self->velY > 0) {
                    self->velY = 0;
                }
                self->gravity = 0x148;
            }
            if (Ba4Bit_021a3220(self)) {
                self->speed = self->unk_b08 + 0x5c3;
            } else {
                self->speed = self->unk_b08 + 0x51f;
            }
            if (self->speed > 0x933) {
                self->speed = 0x933;
            }
            self->friction = 0xf9a;
            self->fsm->timer = 0;
            self->fsm->st++;
            if (self->padCur & 0xf0) {
                u16 yaw = FieldCam_GetYaw(&data_ov000_021ccd54->cam);
                self->moveYaw = yaw + self->padDir;
            }
            e = func_02065f88(0x192, &self->pos);
            self->unk_b40 = e->id;
            e->SetRotXYZ(0, self->moveYaw, 0);
            e->speed = 0x800;
            if (self->unk_b22_3) {
                e->SetScaleXYZ(0x1266, 0x1266, 0x1000);
            }
            if (Ba4Bit_021a3220(self)) {
                VecFx32 v;
                EffectObj *e2;
                v.y = self->height >> 2;
                v.z = 0x1800;
                v.x = 0;
                func_01ffc9fc(&v, &v, self->moveYaw);
                VEC_Add(&v, (VecFx32 *)((u8 *)self + 0x70), &v);
                e2 = func_02065f88(0x66, &v);
                e2->SetRotXYZ(0xc000, self->moveYaw, 0);
                e2->SetScaleXYZ(0xb33, 0x3000, 0xb33);
                e2->speed = 0x1ccd;
            }
        }
        self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        func_ov000_021b1fac(self, FALSE, 1);
        break;
    }
    case 2: {
        BOOL near;
        if (Ba4Bit_021a3220(self)) {
            s32 spd = self->speed;
            u8 f = 1;
            if (self->unk_b2c_6) {
                f = 0;
            }
            func_ov000_021b1dd8((u8 *)self, spd, 0x1000, 0x1000, 0x466, f);
            self->speed = LO_FX_MUL(spd, 0xfc3);
            if ((self->hit->unk_50 & 0x20000000) && (self->fsm->timer & 3) == 1) {
                EffectObj *e = func_02065f88(0x67, &self->pos);
                e->SetRotXYZ(0, self->moveYaw, 0);
                e->SetScaleAll(0x800);
                e->speed = 0x2000;
            }
        } else {
            s32 f = 1;
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            if (self->unk_b2c_6) {
                f = 0;
            }
            func_ov000_021b1fac(self, FALSE, f);
        }
        if (self->unk_b2c_6) {
            u16 t = self->fsm->timer;
            if (!(t & 3) && t < 0x14) {
                EffectObj *e = func_02065f88(0x322, &self->pos);
                e->AddPosXYZ(0, self->height >> 2, 0);
                e->SetRotXYZ(0, (u16)Rand_UpTo(0xffff), 0);
                e->SetScaleAll(((t & 0xfffe) << 7) + 0x800);
                e->speed = 0x4800;
            }
        }
        {
            VecFx32 o;
            o.y = self->centerY;
            o.x = 0;
            o.z = 0xc00;
            hit = func_ov000_0219aae8(self, self, 0, 0x42, 0x20, &o, NULL, 0x1400, 0, 0x69, 0x800);
        }
        if (self->hit->unk_58 & 1) {
            hit = TRUE;
        }
        if (self->unk_b2c_6) {
            hit = FALSE;
        }
        near = FALSE;
        if (!hit && (self->hit->unk_50 & 0x30) && !Ba4Bit_021a3220(self)) {
            u16 a = func_ov000_02198da8(self->hit, self->moveYaw);
            if ((u16)(a - self->moveYaw - 0x6400) < 0x3800) {
                near = TRUE;
            }
        }
        if (hit || near) {
            BOOL ok;
            Actor *a;
            u8 *p;
            func_ov000_02190cb0(self->model, data_ov000_021cc636, 0x1000, 1);
            func_02049f44(data_02097e4c, 8, &self->pos, 0);
            ok = TRUE;
            p = LFLD(u8 *, data_ov000_021ccd6c, 0x14);
            if (p == NULL || !LFLD(B19_021a3220, p, 0x19).b1) {
                ok = FALSE;
            }
            if (!ok) {
                func_ov000_0218996c(5, 10);
            }
            a = FindActor_021a3220(self->unk_b1c);
            if (a != NULL) {
                Msg_021a3220 m;
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
            self->unk_b24_7 = self->unk_b24_9;
            self->unk_b1e = 0xffff;
            self->moveYaw += 0x8000;
            self->speed >>= 1;
            if (hit) {
                self->speed >>= 1;
            }
            self->velY = 0xb8;
            self->gravity = 0x52;
            self->unk_b2c_6 = 0;
            self->fsm->st = 10;
            self->fsm->timer = 0;
        } else if (!IsIdle_021a3220() || self->mode == 3 || func_ov000_021b68b8(data_ov000_021ccd6c, &self->pos) != NULL) {
            self->speed >>= 2;
            func_ov000_02198360(self->fsm, 4, 0);
        } else {
            ActorSub40 *st = self->fsm;
            st->timer++;
            if (st->timer >= 0x14) {
                if (Ba4Bit_021a3220(self) && (self->hit->unk_50 & 0x20000000)) {
                    if (self->unk_b38 != 0) {
                        func_ov000_02198360(self->fsm, 4, 0);
                    } else if (self->fsm->timer > 0x28) {
                        func_ov000_02198360(self->fsm, 4, 0);
                    }
                } else {
                    func_ov000_02198360(self->fsm, 4, 0);
                }
            }
        }
        break;
    }
    case 10: {
        ActorSub40 *st;
        func_ov000_021b1fac(self, FALSE, 1);
        st = self->fsm;
        st->timer++;
        if (st->timer >= 0x1e) {
            func_ov000_02198360(self->fsm, 4, 0);
        } else if (self->hit->unk_50 & 0x20000000) {
            func_ov000_02190cb0(self->model, data_ov000_021cc630, 0x800, 0);
            self->friction = 0xe66;
            func_02049f44(data_02097e4c, 0x81, &self->pos, 0);
            func_02065f88(0x12f, &self->pos)->SetScaleAll(0x800);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 11: {
        ActorSub40 *st;
        func_ov000_021b1fac(self, FALSE, 1);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x14 || Ba4Bit_021a3220(self)) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    }
    if (self->unk_b2c_6 && self->fsm->current != 0x16) {
        self->unk_b2c_6 = 0;
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
        func_ov000_02190cb0(self->model, data_ov000_021cc62a, 0x800, 0);
        func_ov000_02198360(self->fsm, 4, 0);
    }
}

}
