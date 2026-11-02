#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B18_021aa978;

typedef struct {
    u16 val;
    u8 d;
    u16 id;
} Hit021aa978;

typedef struct {
    u16 x, y, z;
} Rot021aa978;

typedef struct {
    VecFx32 pos;
    Rot021aa978 rot;
    u8 pad[2];
    s32 unk_14;
} Msg021aa978;

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc6ae[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL func_ov000_02191508(void *a);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_0218999c(u8 a, u8 b);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
VObj *func_02065f88(s32 id, VecFx32 *pos);
u16 FX_Atan2(s32 a, s32 b);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s16 i, s32 j);
void func_ov000_0218996c(u8 a, u8 b);
void func_ov000_0218d46c(Actor *o, u16 id, s32 m);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
BOOL func_ov000_02191120(void *a);
void func_ov000_02191418(void *a, u16 b, s32 c);
void func_ov000_021b1fac(void *self, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, u16 b);
u16 Camera_GetYaw(void *cam);

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021aa978;

static inline Actor *FindActor021aa978(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return (Actor *)ActorMgr_GetActor(mgr, id);
}

static inline u16 AngleTo021aa978(Actor *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline void Charge021aa978(Robo021ca458 *self) {
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

static inline u16 CamYaw021aa978(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return Camera_GetYaw(cam);
}

static inline void Release021aa978(Robo021ca458 *self, s32 next) {
    Actor *a = FindActor021aa978(self->unk_b1c);
    if (a != NULL) {
        Msg021aa978 m;
        m.pos.x = self->pos.x;
        m.pos.y = self->pos.y;
        m.pos.z = self->pos.z;
        m.pos.y += self->centerY;
        m.rot = *(Rot021aa978 *)&a->rot_x;
        m.unk_14 = 0;
        Actor_SendMsg(a, self->id, 7, 1, sizeof(Msg021aa978), &m);
        func_ov000_0218d46c(a, self->id, 0xa);
        if (a->targetObj != NULL) {
            LFLD(B18_021aa978, a->targetObj, 0x18).b0 = 0;
        }
    }
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
    self->unk_b2c_1 = 0;
    func_ov000_02198360(((void *)self->fsm), next, 0);
}


void func_ov000_021aa978(Robo021ca458 *self) {
    Actor *a = FindActor021aa978(self->unk_b1c);
    ActorSub40 *st;
    ActorSub4c *sub;
    BOOL hit;
    s32 eff;
    sub = NULL;
    if (a != NULL) {
        sub = a->targetObj;
    }
    eff = 0;
    hit = FALSE;
    st = self->fsm;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc6ae, 0x555, 0);
        self->fsm->st++;
        break;
    case 1:
        if (self->model->anim_state != 1) {
            break;
        }
        self->moveYaw = self->rot_y;
        self->unk_b2c_7 = 1;
        eff = 1;
        st->st++;
        self->fsm->timer = 0;
    case 2: {
        ActorSub40 *s;
        hit = TRUE;
        Charge021aa978(self);
        func_ov000_02191418(self->model, 1, 0);
        s = self->fsm;
        s->timer++;
        if (s->timer < 0x20) {
            self->rot_y += 0x800;
            break;
        }
        self->fsm->timer = 0;
        if (self->unk_b2c_7 < 3 && self->unk_b2b >= 4) {
            eff = 1;
            self->unk_b2b = 0;
            self->unk_b2c_7++;
            break;
        }
        {
            Actor *t = FindActor021aa978(self->target);
            if (t != NULL) {
                self->moveYaw = AngleTo021aa978((Actor *)self, t);
            } else if (self->padCur & 0xf0) {
                self->moveYaw = CamYaw021aa978((u8 *)data_ov000_021ccd54 + 0xf4) + self->padDir;
            }
        }
        self->fsm->st++;
        break;
    }
    case 3: {
        u16 tgt;
        u16 d;
        func_ov000_02191418(self->model, 1, 0);
        tgt = self->moveYaw + 0x8000;
        d = tgt - self->rot_y;
        if (d > 0x800 && d < 0xf800) {
            self->rot_y += 0x800;
            break;
        }
        self->rot_y = tgt;
        hit = TRUE;
        eff = 2;
        self->fsm->st++;
        break;
    }
    case 4:
        if (a == NULL || sub == NULL) {
            st->st++;
            break;
        }
        if (self->model->anim_state != 2) {
            break;
        }
        func_ov000_0218d46c(a, self->id, 0xb);
        a->rot_y = self->rot_y + 0x8000;
        LFLD(s32, sub, 0x50) = 0x2000;
        LFLD(s32, sub, 0x54) = 0x19a;
        LFLD(s32, sub, 0x58) = 0;
        {
            u8 v = self->unk_b2c_7 * 5;
            sub->unk_19 = self->unk_b24_22;
            sub->unk_1b = v;
        }
        if (a != NULL) {
            Msg021aa978 m;
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
                m.rot = *(Rot021aa978 *)&a->rot_x;
                m.unk_14 = 0;
                Actor_SendMsg(a, self->id, 7, 1, sizeof(Msg021aa978), &m);
            }
        }
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        self->unk_b1c = 0xffff;
        self->unk_b1e = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->fsm->st++;
        break;
    case 5:
        if (!func_ov000_02191120(self->model)) {
            break;
        }
        self->unk_b2c_0 = 0;
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    if (eff != 0) {
        s32 sc = 0x4400;
        s32 id;
        VObj *o;
        if (a != NULL) {
            sc += a->radius * 2;
        }
        id = 0x3ea;
        if (eff == 2) {
            id = 0x3e9;
        }
        o = func_02065f88(id, (VecFx32 *)((u8 *)self + 0x70));
        o->vfunc_24(0, self->centerY, 0);
        o->vfunc_0c(sc);
        o->vfunc_30((u8 *)self + 0x7c);
        LFLD(s32, o, 0x3c) = 0x99a;
    }
    if (!hit || a == NULL) {
        return;
    }
    if (!func_ov000_0219aae8(a, self, (u8)(self->unk_b2c_7 * 5), 0x30, 0x30, NULL, 0, a->radius + 0xccd, 0, 0x64, 0x1000)) {
        return;
    }
    func_ov000_0218996c(8, 0xa);
    func_02049f44(data_02097e4c, 0x7d, &self->pos, 0);
    func_ov000_02191418(self->model, 3, 0);
}

}
