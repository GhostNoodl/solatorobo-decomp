#include "ov000/FieldCam.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 x, y, z;
} Rot021aaf80;

typedef struct {
    VecFx32 pos;
    Rot021aaf80 rot;
    u8 pad[2];
    s32 unk_14;
} Msg021aaf80;

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc6b4[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL func_ov000_02191508(void *a);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_0218999c(u8 a, u8 b);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u16 FX_Atan2(s32 a, s32 b);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s16 i, s32 j);
void func_ov000_0218d46c(Actor *o, u16 id, s32 m);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
BOOL func_ov000_02191120(void *a);
void func_ov000_02191418(void *a, u16 b, s32 c);
void func_ov000_021b1fac(void *self, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, u16 b);

static inline Actor *FindActor021aaf80(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return (Actor *)ActorMgr_GetActor(mgr, id);
}

static inline u16 AngleTo021aaf80(Actor *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline void Charge021aaf80(Robo021ca458 *self) {
    if (self->padTrig & 1) {
        self->unk_b2b++;
    }
    if (self->padTrig & 0xf0) {
        self->unk_b2b += 2;
    }
    if (self->unk_b2b > 4) {
        self->unk_b2b = 4;
    }
}

static inline void Release021aaf80(Robo021ca458 *self, s32 next) {
    Actor *a = FindActor021aaf80(self->unk_b1c);
    if (a != NULL) {
        Msg021aaf80 m;
        m.pos.x = self->pos.x;
        m.pos.y = self->pos.y;
        m.pos.z = self->pos.z;
        m.pos.y += self->centerY;
        m.rot = *(Rot021aaf80 *)&a->rot_x;
        m.unk_14 = 0;
        Actor_SendMsg(a, self->id, 7, 1, sizeof(Msg021aaf80), &m);
        func_ov000_0218d46c(a, self->id, 0xa);
        if (a->targetObj != NULL) {
            a->targetObj->unk_18_0 = 0;
        }
    }
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
    self->unk_b2c_1 = 0;
    func_ov000_02198360(self->fsm, next, 0);
}

void func_ov000_021aaf80(Robo021ca458 *self) {
    Actor *a = FindActor021aaf80(self->unk_b1c);
    ActorSub4c *sub = NULL;
    if (a != NULL) {
        sub = a->targetObj;
    }
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc6b4, 0x555, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1: {
        EffectObj *o;
        if (self->model->anim_state != 1) {
            break;
        }
        o = func_02065f88(0x192, (VecFx32 *)(&self->pos));
        self->unk_b40 = o->id;
        o->SetRotXYZ(0x4000, 0, 0);
        self->fsm->st++;
    }
    case 2:
        if (a == NULL || sub == NULL) {
            self->fsm->st++;
            break;
        }
        if (self->hit->unk_50 & 0x20000000) {
            VecFx32 p;
            EffectObj *o;
            s32 sc;
            u8 v;
            p = a->pos;
            p.y = self->pos.y;
            func_ov000_0218999c(0xe, 0x19);
            func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x53, &self->pos, 0);
            sc = a->radius;
            if (sc < 0xccd) {
                sc = 0xccd;
            }
            o = func_02065f88(0x66, &p);
            o->SetScaleXYZ(sc + 0xccd, 0x1400, sc + 0xccd);
            o->speed = 0xe66;
            func_ov000_0218d46c(a, self->id, 0xb);
            sub->unk_18_0 = 0;
            sub->unk_50 = 0x19a;
            sub->unk_54 = -0x1000;
            sub->unk_58 = 0;
            v = sub->unk_1a * 5;
            sub->unk_19 = self->unk_b24_22;
            sub->unk_1b = v;
            if (a != NULL) {
                Msg021aaf80 m;
                VecFx32 t;
                VecFx32 *q = ((VecFx32 *)a->hit);
                if (q != NULL) {
                    t.x = q->x;
                    t.y = q->y;
                    t.z = q->z;
                } else {
                    t.x = a->pos.x;
                    t.y = a->pos.y;
                    t.z = a->pos.z;
                }
                if (func_01ffbd6c((VecFx32 *)((u8 *)self + 0x70), &t, -1, 0, 0, -1) != -0x1000) {
                    t.x -= self->pos.x;
                    t.y -= self->pos.y;
                    t.z -= self->pos.z;
                    VEC_MultAdd(0xc00, &t, (VecFx32 *)((u8 *)self + 0x70), &t);
                    m.pos = t;
                    m.rot = *(Rot021aaf80 *)&a->rot_x;
                    m.unk_14 = 0;
                    Actor_SendMsg(a, self->id, 7, 1, sizeof(Msg021aaf80), &m);
                }
            }
            func_ov000_0219aae8(a, self, v * 2, 0x30, 0x30, NULL, 0, sc + 0x34cd, 0x1800, -1, 0x1000);
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_5 = 0;
            self->unk_b24_7 = self->unk_b24_9;
            func_ov000_02191418(self->model, 3, 0);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st++;
        } else {
            s32 lim;
            BOOL fall = FALSE;
            if (!(self->hit->unk_54 & 0x20000000)) {
                lim = -0xf000;
                if (self->unk_b22_0 || self->unk_b24_12 || self->unk_b24_19) {
                    lim = -0x2d000;
                }
                if (self->pos.y - self->unk_afc.y < lim) {
                    fall = TRUE;
                }
            }
            if (fall) {
                self->unk_b24 |= 0x40000;
                Release021aaf80(self, 4);
            }
            func_ov000_02191418(self->model, 1, 0);
        }
        break;
    case 3:
        if (!func_ov000_02191120(self->model)) {
            break;
        }
        Release021aaf80(self, 1);
        break;
    }
    if (!func_ov000_02191508(self->model)) {
        u16 ang = self->rot_y;
        if (self->mode == 1 && (self->padCur & 0xf0)) {
            ang = FieldCam_GetYaw(&data_ov000_021ccd54->cam) + self->padDir;
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x19a, 1, 0x8000);
    }
    func_ov000_021b1fac(self, 0, 0);
}

}
