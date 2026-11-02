#include "types.h"
#include "Main/Res/StageFlags.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"
#include "ov000/FieldMgr.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

class VObj02196c40 {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c(s32 a);
};

extern "C" {
extern char data_ov000_021cc463[];
extern void *data_02097e4c;
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
BOOL Model0218fe1c_IsAnimDone(void *a);
void HitSphere_Link(void *a);
void HitSphere_Unlink_0203f364(void *a);
BOOL History_SetState(void *s, s32 a, s32 b);
Robo021ca458 *ActorMgr_FindPlayer(void);
Actor *Target_Get(ActorSub4c *p);
void Target_Set(void *a, void *b);
void Ov003Pickup_Update(void *self, s32 a);
void *Ov003_FindPlayerInRange(void *pos, s32 a, s32 b);
void *SndMgr_PlayAt(void *mgr, s32 id, void *pos, s32 a);
void func_ov000_02197ad0(Actor *self, BOOL b);
void Actor_Move(Actor *self, s32 a);
void Body_Update(void *a, BOOL b, s32 c, s32 d);

static inline s32 FxMul02196c40(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline BOOL IsB2_02196c40(ActorSub4c *m) {
    return m->unk_18_2 ? TRUE : FALSE;
}

void ActorEx_StateFly(ActorEx *self) {
    BOOL flag = TRUE;
    self->hit->unk_9a_6 = 0;
    switch (self->fsm->st) {
    case 0:
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
        self->unk_92 = 0;
        self->unk_cc_6 = 0;
        self->fsm->st++;
        break;
    case 1: {
        u32 in = self->hit->unk_50;
        FieldExit *hit;
        if (self->velY > 0 && (in & 0x80000000)) {
            self->velY = -0xcd;
        }
        if (self->msg_flags & 0x80) {
            self->speed = 0;
        }
        if (in & 0x400) {
            EffectObj *o;
            if (self->unk_cc_6) {
                break;
            }
            self->unk_cc_6 = 1;
            self->speed = 0;
            self->unk_92 = 3;
            SndMgr_PlayAt(data_02097e4c, 0x3d, &self->pos, 0);
            o = Effect_SpawnId(0x2bd, &self->pos);
            if (self->radius > 0x1000) {
                o->SetScaleAll(self->radius);
            }
            break;
        }
        hit = FieldMgr_FindExitAt(data_ov000_021ccd6c, &self->pos);
        if (hit != NULL) {
            u16 ang = hit->dir;
            self->speed = FxMul02196c40(self->speed, 0x59a);
            if (self->speed < 0x8f) {
                self->speed = 0x8f;
            }
            self->moveYaw = ang;
            self->gravity = 0x52;
            flag = FALSE;
        }
        if (hit != NULL || (in & 0x20000000) || ((in & 0x40000000) && !IsB2_02196c40(self->targetObj)) ||
            ((s32)self->hit->unk_58) != 0) {
            s32 kind = 0;
            BOOL got = FALSE;
            self->fsm->timer = 0;
            if (hit != NULL || self->targetObj->target != 0xffff) {
                if (self->targetObj->unk_01 == 1) {
                    kind = self->targetObj->unk_02;
                    got = TRUE;
                }
            }
            switch (kind) {
            case 1:
            case 2: {
                Robo021ca458 *p;
                if (self->unk_44 != NULL) {
                    ActorSub44 *q = self->unk_44;
                    q->unk_22_0 = 0;
                    q->unk_22_1 = 0;
                }
                if (self->hit != NULL) {
                    ActorSub48 *q = self->hit;
                    q->unk_9a_0 = 0;
                    q->unk_9a_3 = 0;
                    HitSphere_Unlink_0203f364(q);
                    q = self->hit;
                    q->unk_9a_1 = 0;
                    q->unk_9a_4 = 0;
                }
                p = ActorMgr_FindPlayer();
                if (p->id == self->targetObj->target) {
                    StageFlags *g = data_0214a424;
                    u32 n = g->unk_016 + 1;
                    if (n >= 0xffff) {
                        n = 0xffff;
                    }
                    g->unk_016 = n;
                }
                if (self->targetObj->unk_03 != 0) {
                    Ov003Pickup_Update(self, 0);
                }
                History_SetState(self->fsm, 0x15, 0);
                break;
            }
            default:
                func_ov000_02197ad0(self, got);
                if (((in & 0x20000000) && self->velY == 0) || self->unk_92 > 3) {
                    self->fsm->st++;
                    self->velY = 0;
                    self->gravity = 0;
                    self->friction = 0x800;
                }
                break;
            }
        }
        if (self->velY < 0) {
            ActorSub40 *st;
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc463, 0x1000, 0);
            Model0218fe1c_SetLoop(self->model);
            st = self->fsm;
            st->timer++;
            if (st->timer > 0x46) {
                self->fsm->timer = 0x46;
                if (!(self->hit->unk_54 & 0x20000000)) {
                    History_SetState(self->fsm, 0x15, 0);
                }
            }
        }
        break;
    }
    case 2: {
        ActorSub40 *st;
        self->hit->unk_9a_5 = 1;
        st = self->fsm;
        st->timer++;
        if (st->timer < 6) {
            break;
        }
        self->fsm->timer = 6;
        if (!Model0218fe1c_IsAnimDone(self->model) && ((s64)self->fsm->flags) == 0) {
            break;
        }
        self->targetObj->target = 0xffff;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
    Actor_Move(self, 0);
    if (self->hit != NULL) {
        ActorSub48 *other;
        BOOL saved;
        ActorSub4c *m;
        if (self->param->type == 2) {
            ActorSub48 *q = self->hit;
            q->unk_9a_0 = 1;
            q->unk_9a_3 = 1;
            HitSphere_Link(q);
        }
        m = self->targetObj;
        other = NULL;
        saved = FALSE;
        if (m != NULL && m->target != 0xffff && m->unk_01 == 1) {
            s32 h = self->radius + 0x4cd;
            Actor *t;
            if (h < 0xccd) {
                h = 0xccd;
            }
            self->hit->unk_44 = h;
            t = Target_Get(self->targetObj);
            if (t != NULL && (other = (ActorSub48 *)((u8 *)t->hit)) != NULL && other->unk_9a_3) {
                other->unk_9a_3 = 0;
                HitSphere_Unlink_0203f364(other);
                saved = TRUE;
            }
        }
        Body_Update(self->hit, flag, 0, 0);
        if (saved) {
            other->unk_9a_3 = 1;
            HitSphere_Link(other);
        }
    }
    if (self->targetObj != NULL && self->targetObj->type == 2) {
        void *r = Ov003_FindPlayerInRange(&self->pos, self->radius, self->height);
        if (r != NULL) {
            Target_Set(self->targetObj, r);
            History_SetState(self->fsm, 0xd, 0);
        }
    }
}

}
