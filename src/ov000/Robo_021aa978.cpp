#include "ov000/FieldCam.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"


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
BOOL Model0218fe1c_IsAnimDelayed(void *a);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
void Field_ShakeCameraY(u8 a, u8 b);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
u16 FX_Atan2(s32 a, s32 b);
BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s16 i, s32 j);
void Field_ShakeCamera(u8 a, u8 b);
void Actor_SendMsgU8(Actor *o, u16 id, s32 m);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
BOOL History_SetState(void *s, s32 a, s32 b);
BOOL Model0218fe1c_IsAnimDone(void *a);
void Model0218fe1c_SetAnimDelay(void *a, u16 b, s32 c);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, u16 b);

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
        Actor_SendMsgU8(a, self->id, 0xa);
        if (a->targetObj != NULL) {
            a->targetObj->unk_18_0 = 0;
        }
    }
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
    self->unk_b2c_1 = 0;
    History_SetState(((void *)self->fsm), next, 0);
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
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc6ae, 0x555, 0);
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
        Model0218fe1c_SetAnimDelay(self->model, 1, 0);
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
                self->moveYaw = FieldCam_GetYaw(&data_ov000_021ccd54->cam) + self->padDir;
            }
        }
        self->fsm->st++;
        break;
    }
    case 3: {
        u16 tgt;
        u16 d;
        Model0218fe1c_SetAnimDelay(self->model, 1, 0);
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
        Actor_SendMsgU8(a, self->id, 0xb);
        a->rot_y = self->rot_y + 0x8000;
        sub->unk_50 = 0x2000;
        sub->unk_54 = 0x19a;
        sub->unk_58 = 0;
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
        SndMgr_PlayAt(data_02097e4c, 0x32, &self->pos, 0);
        self->unk_b1c = 0xffff;
        self->unk_b1e = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->fsm->st++;
        break;
    case 5:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            break;
        }
        self->unk_b2c_0 = 0;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    if (eff != 0) {
        s32 sc = 0x4400;
        s32 id;
        EffectObj *o;
        if (a != NULL) {
            sc += a->radius * 2;
        }
        id = 0x3ea;
        if (eff == 2) {
            id = 0x3e9;
        }
        o = Effect_SpawnId(id, (VecFx32 *)(&self->pos));
        o->AddPosXYZ(0, self->centerY, 0);
        o->SetScaleAll(sc);
        o->SetRot(&self->rot);
        o->speed = 0x99a;
    }
    if (!hit || a == NULL) {
        return;
    }
    if (!Hit_ApplyInArea(a, self, (u8)(self->unk_b2c_7 * 5), 0x30, 0x30, NULL, 0, a->radius + 0xccd, 0, 0x64, 0x1000)) {
        return;
    }
    Field_ShakeCamera(8, 0xa);
    SndMgr_PlayAt(data_02097e4c, 0x7d, &self->pos, 0);
    Model0218fe1c_SetAnimDelay(self->model, 3, 0);
}

}
