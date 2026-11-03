#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"


typedef struct {
    u16 val;
    u8 d;
    u16 id;
} Hit021ab68c;

typedef struct {
    u16 x, y, z;
} Rot021ab68c;

typedef struct {
    VecFx32 pos;
    Rot021ab68c rot;
    u8 pad[2];
    s32 unk_14;
} Msg021ab68c;

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc6ba[];
extern char data_ov000_021cc5e3[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL Model0218fe1c_IsAnimDelayed(void *a);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
void Field_ShakeCameraY(s32 a, s32 b);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
u16 FX_Atan2(s32 a, s32 b);
BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);
void Actor_SendMsgU8(Actor *o, u16 id, s32 m);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
BOOL History_SetState(void *s, s32 a, s32 b);

static inline Actor *FindActor021ab68c(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return (Actor *)ActorMgr_GetActor(mgr, id);
}

static inline u16 AngleTo021ab68c(Actor *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline void Charge021ab68c(Robo021ca458 *self) {
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

void func_ov000_021ab68c(Robo021ca458 *self) {
    Actor *a = FindActor021ab68c(self->unk_b1c);
    ActorSub4c *sub = NULL;
    ActorSub40 *st;
    BOOL hit;
    u8 lvl2;
    if (a != NULL) {
        sub = a->targetObj;
    }
    st = self->fsm;
    switch (st->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc6ba, 0x555, 0);
        self->fsm->st++;
        return;
    case 1:
    case 10: {
        BOOL ok;
        s16 v;
        if (a == NULL || sub == NULL) {
            st->st = 0x14;
            return;
        }
        ok = FALSE;
        Charge021ab68c(self);
        v = self->model->anim_state;
        if (v == 1) {
            ok = TRUE;
        }
        if (v == 2) {
            ok = TRUE;
        }
        if (ok) {
            self->fsm->st++;
        }
        return;
    }
    case 2:
    case 11: {
        u32 lvl;
        if (a == NULL || sub == NULL) {
            st->st = 0x14;
            return;
        }
        hit = TRUE;
        self->unk_b2c_7++;
        lvl = self->unk_b2c_7;
        if (lvl < 2) {
            hit = FALSE;
        } else if (lvl < 5 && self->unk_b2b >= 4) {
            self->unk_b2b = 0;
            if (!(lvl & 1)) {
                Model0218fe1c_SetAnimFrame(self->model, 0xa000);
            }
            hit = FALSE;
        }
        Field_ShakeCameraY(0x14, 0x28);
        SndMgr_PlayAt(data_02097e4c, 0x52, &self->pos, 0);
        if (!hit) {
            VecFx32 p;
            EffectObj *o;
            p = sub->dest;
            p.y = self->pos.y;
            o = Effect_SpawnId(0x67, &p);
            o->SetScaleAll(0x1800);
            o->SetRotXYZ(0, AngleTo021ab68c(a, (Actor *)self), 0);
        }
        lvl2 = self->unk_b2c_7 * 2;
        Hit_ApplyInArea(a, self, lvl2 * 3, 0x31, 0x30, NULL, 0, a->radius + 0x2333, 0, 0x64, 0x1000);
        if (!hit) {
            Hit021ab68c msg;
            msg.val = lvl2;
            msg.d = 1;
            msg.id = 0xffff;
            Actor_SendMsg(a, self->id, 9, 1, 6, &msg);
        }
        if (!hit && a->hpObj->cur != 0) {
            goto again;
        }
        if (hit) {
            Actor_SendMsgU8(a, self->id, 0xb);
            a->rot_y = AngleTo021ab68c((Actor *)self, a);
            sub->unk_50 = 0x19a;
            sub->unk_54 = -0x1000;
            sub->unk_58 = 0;
            sub->unk_19 = self->unk_b24_22;
            sub->unk_1b = lvl2;
        }
        sub->unk_18_0 = 0;
        if (a != NULL) {
            Msg021ab68c m;
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
                m.rot = *(Rot021ab68c *)&a->rot_x;
                m.unk_14 = 0;
                Actor_SendMsg(a, self->id, 7, 1, sizeof(Msg021ab68c), &m);
            }
        }
        self->unk_b1c = 0xffff;
        self->unk_b1e = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->fsm->st = 0x14;
        return;
    again:
        self->fsm->st = 0xa;
        return;
    }
    case 0x14:
        if (Model0218fe1c_IsAnimDelayed(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc5e3, 0x89, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    case 0x15:
        st->timer++;
        if (st->timer <= 0xf) {
            return;
        }
        self->unk_b2c_2 = 0;
        History_SetState(self->fsm, 1, 0);
        return;
    }
}

}
