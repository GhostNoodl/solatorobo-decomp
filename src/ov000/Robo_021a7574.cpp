#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/FieldCam.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

extern "C" {

extern u8 data_ov000_021cc696[];
extern u8 data_ov000_021cc672[];
extern s16 data_ov000_021ca0a4[]; // animation event script (Model0218fe1c::evScript)
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc618[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02198360(ActorSub40 *st, s32 state, s32 x);
void func_ov000_021b1fac(Robo021ca458 *self, BOOL a, s32 b);
void func_ov000_021b03c8(Robo021ca458 *self);
Actor *Actor_GetTarget(Actor *self);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_0218d46c(void *a, u16 id, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline Actor *FindActor021a783c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 AngleTo(Robo021ca458 *self, Actor *other) {
    u16 angle;
    if (other == NULL || other == self) {
        angle = self->rot_y;
    } else {
        angle = FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
    }
    return angle;
}

static inline s32 FxMul64(s64 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

extern u8 data_ov000_021cc64e[];
extern u8 data_ov000_021cc68a[];
extern u8 data_ov000_021cc690[];
extern s16 data_ov000_021ca090[]; // animation event script (Model0218fe1c::evScript)
extern void *data_02097e4c;
void *func_ov000_02191318(void *a, s32 frame);
void func_ov000_02191780(void *a);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_01ffbd6c(void *a, void *b, s32 c, s32 d, s32 e, s32 f);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);

typedef struct {
    VecFx32 pos;
    ActorRot rot;
    u8 pad[2];
    s32 unk_14;
} Msg021a70b0;

void func_ov000_021a70b0(Robo021ca458 *self) {
    switch (((ActorSub40 *)self->fsm)->st) {
    case 0:
        if (self->unk_b22_3) {
            func_ov000_02190cb0(self->model, data_ov000_021cc64e, 0x555, 0);
            func_ov000_02191318(self->model, 0xa000);
            func_ov000_02191780(self->model);
        } else if (self->unk_b24_5 == 1) {
            func_ov000_02190cb0(self->model, data_ov000_021cc68a, 0x555, 0);
        } else {
            func_ov000_02190cb0(self->model, data_ov000_021cc690, 0x333, 0);
            {
                Model0218fe1c *m = self->model;
                m->evScript = data_ov000_021ca090;
                m->evCursor = data_ov000_021ca090;
            }
        }
        if (self->velY > 0) {
            self->velY = 0;
        }
        self->friction = 0x99a;
        self->gravity = 10;
        ((ActorSub40 *)self->fsm)->st++;
        break;
    case 1: {
        u16 ang;
        Actor *t = Actor_GetTarget(self);
        if (t != NULL) {
            ang = AngleTo(self, t);
        } else {
            ang = self->rot_y;
            if (self->mode == 1 && (self->padCur & 0xf0)) {
                ang = FieldCam_GetYaw(&data_ov000_021ccd54->cam) + self->padDir;
            }
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x59a, 1, 0x8000);
        if (self->unk_b24_5 != 0 &&
            (self->model->anim_state == 1 || self->unk_b22_3)) {
            Actor *a;
            func_02049a48(data_02097e4c, 0x301, -1, -1, -1);
            a = FindActor021a783c(self->unk_b1c);
            if (a != NULL) {
                func_ov000_0218d46c(a, self->id, 0xb);
                if (a != NULL) {
                    Msg021a70b0 m;
                    VecFx32 v;
                    if (((VecFx32 *)a->hit) != NULL) {
                        v = *((VecFx32 *)a->hit);
                    } else {
                        v = a->pos;
                    }
                    if (func_01ffbd6c(&self->pos, &v, -1, 0, 0, -1) != -0x1000) {
                        v.x -= self->pos.x;
                        v.y -= self->pos.y;
                        v.z -= self->pos.z;
                        VEC_MultAdd(0xc00, &v, &self->pos, &v);
                        m.pos = v;
                        m.rot = a->rot;
                        m.unk_14 = 0;
                        Actor_SendMsg(a, self->id, 7, TRUE, sizeof(Msg021a70b0), &m);
                    }
                }
            }
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
            ((ActorSub40 *)self->fsm)->st++;
        }
    }
    case 2:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x200, 0);
            ((ActorSub40 *)self->fsm)->st++;
            ((ActorSub40 *)self->fsm)->timer = 0;
            self->friction = 0x800;
        }
        break;
    case 3: {
        ActorSub40 *st = ((ActorSub40 *)self->fsm);
        st->timer++;
        if (st->timer > 15) {
            self->gravity = 0x52;
            func_ov000_02198360(((ActorSub40 *)self->fsm), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 0);
    if (!self->unk_b24_1) {
        return;
    }
    if (!(self->hit->unk_54 & 0x400)) {
        return;
    }
    self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x,
                                     self->unk_af0.z - self->pos.z);
    self->speed = 0x66;
    self->friction = 0;
    if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
        self->velY = 0x200;
    }
    self->gravity = 0x52;
    self->unk_b24_17 = 1;
}

void func_ov000_021a7574(Robo021ca458 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc672, 0x800, 0);
        if (self->unk_b24_5 != 2) {
            Model0218fe1c *m = self->model;
            m->evScript = data_ov000_021ca0a4;
            m->evCursor = data_ov000_021ca0a4;
        }
        if (self->velY > 0) {
            self->velY = 0;
        }
        self->friction = 0xccd;
        self->gravity = 10;
        self->unk_b24_7 = 2;
        ((ActorSub40 *)self->fsm)->st++;
        break;
    case 1:
        if (self->model->anim_state == 1 || func_ov000_02191120(self->model)) {
            if (self->unk_b24_5 != 0) {
                EffectObj *e;
                u8 *a = (u8 *)FindActor021a783c(self->unk_b1c);
                if (a != NULL) {
                    func_ov000_0218d46c(a, self->id, 0xd);
                }
                self->unk_b24_5 = 0;
                self->unk_b1c = 0xffff;
                self->unk_b1e = 0xffff;
                self->unk_b24_7 = self->unk_b24_9;
                e = func_02065f88(0xc9, &self->pos);
                self->unk_b48 = e->id;
                self->unk_b5e = 0;
                self->unk_b4c = 0;
                self->unk_b50 = FxMul64(self->height, 0xa66);
                self->unk_b54 = 0;
                self->unk_b58 = 0xe000;
                self->unk_b5a = 0;
                self->unk_b5c = 0;
                e->SetScaleXYZ(0x2800, 0x2000, 0x2800);
            }
            func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x155, 0);
            self->gravity = 0x52;
            ((ActorSub40 *)self->fsm)->st++;
        }
        break;
    case 2: {
        ActorSub40 *st = self->fsm;
        s32 lim = 0x10;
        if (self->unk_93_4) {
            lim = 8;
        }
        st->timer++;
        if (st->timer > lim) {
            func_ov000_02198360(((ActorSub40 *)self->fsm), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 1);
    if (!self->unk_b24_1) {
        return;
    }
    if (!(self->hit->unk_54 & 0x400)) {
        return;
    }
    self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x,
                                     self->unk_af0.z - self->pos.z);
    self->speed = 0x66;
    self->friction = 0;
    if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
        self->velY = 0x200;
    }
    self->gravity = 0x52;
    self->unk_b24_17 = 1;
}

void func_ov000_021a783c(Robo021ca458 *self) {
    if (self->unk_b24_12 == 3) {
        func_ov000_021b03c8(self);
        return;
    }
    switch (((ActorSub40 *)self->fsm)->st) {
    case 0:
        if (self->velY > 0) {
            self->velY = 0;
        }
        self->friction = 0xe66;
        self->gravity = 10;
        func_ov000_02190cb0(self->model, data_ov000_021cc696, 0x800, 0);
        ((ActorSub40 *)self->fsm)->st++;
        break;
    case 1: {
        u16 ang;
        Actor *t = Actor_GetTarget(self);
        if (t != NULL) {
            ang = AngleTo(self, t);
        } else {
            ang = self->rot_y;
            if (self->mode == 1 && (self->padCur & 0xf0)) {
                ang = FieldCam_GetYaw(&data_ov000_021ccd54->cam) + self->padDir;
            }
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x8cd, 1, 0x8000);
        if (self->unk_b24_5 != 0 && self->model->anim_state == 1) {
            u8 *a = (u8 *)FindActor021a783c(self->unk_b1c);
            if (a != NULL) {
                func_ov000_0218d46c(a, self->id, 0xe);
            }
            ((ActorSub40 *)self->fsm)->st++;
        }
        break;
    }
    case 2:
        if (func_ov000_02191120(self->model)) {
            self->gravity = 0x52;
            func_ov000_02190cb0(self->model, data_ov000_021cc618, 0x19a, 0);
            ((ActorSub40 *)self->fsm)->st++;
            ((ActorSub40 *)self->fsm)->timer = 0;
        }
        break;
    case 3: {
        ActorSub40 *st = ((ActorSub40 *)self->fsm);
        st->timer++;
        if (st->timer > 20) {
            func_ov000_02198360(((ActorSub40 *)self->fsm), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 1);
    if (!self->unk_b24_1) {
        return;
    }
    if (!(self->hit->unk_54 & 0x400)) {
        return;
    }
    self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x,
                                     self->unk_af0.z - self->pos.z);
    self->speed = 0x66;
    self->friction = 0;
    if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
        self->velY = 0x200;
    }
    self->gravity = 0x52;
    self->unk_b24_17 = 1;
}

}
