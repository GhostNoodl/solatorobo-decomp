#include "ov000/FieldCam.h"
#include "ov000/ActorMgr.h"
#include "ov000/MessageQueue.h"
#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Group.h"
#include "Main/Effect/Effect.h"

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021a9be8;


extern "C" {
extern void *data_ov000_021ccd64;
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern char data_ov000_021cc68a[];
extern char data_ov000_021ca12c[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL History_SetState(void *p, s32 a, s32 b);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL Model0218fe1c_SetAnim(void *p, void *a, s32 b, s32 c);
BOOL Model0218fe1c_IsAnimDone(void *a);
s32 **Model0218fe1c_GetAnimCtrl(void *a, int b);
void *Model0218fe1c_SeekMainAnim(void *a, s32 frame);
void Actor_Move(Actor *self, s32 a);
void Actor_MoveByPad(Actor *self, u16 base, s32 turn, void *p);
u16 Actor_YawToPos(Actor *self, void *target);
void Body_Update(void *a, s32 b, s32 c, s32 d);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void Actor_SendMsgU8(void *o, u16 id, s32 c);
u8 *Group_SpawnActor(void *mgr, GroupActorDesc *d, void *pos, void *rot, u16 a);
void *SndMgr_PlayAtPitch(void *a, s32 b, void *c, s32 d);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
s32 Hit_CastSegment(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
void func_ov000_02168e18(void *self, s32 a, s32 b, VecFx32 *p);

static inline Actor *FindActor_021a9be8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL Both_021a9be8(ActorSub44 *c) {
    return (c->unk_22_0 == 1 && c->unk_22_1 == 1) ? TRUE : FALSE;
}

static inline BOOL Has_021a9be8(ActorSub44 *c) {
    return c->unk_22_2 != 0 ? TRUE : FALSE;
}

static inline u16 AngleTo_021a9be8(Robo021ca458 *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline s32 Frame_021a9be8(Model0218fe1c *m) {
    s32 f = 0;
    s32 **a = Model0218fe1c_GetAnimCtrl(m, f);
    if (*a != NULL) {
        f = **a;
    }
    return f;
}

static inline void SetFx_021a9be8(Robo021ca458 *self, EffectObj *o, s32 rz) {
    self->unk_b48 = o->id;
    o->speed = 0x2000;
    self->unk_b4c = self->unk_a74.x - self->pos.x;
    self->unk_b50 = self->unk_a74.y - self->pos.y;
    self->unk_b54 = self->unk_a74.z - self->pos.z;
    self->unk_b58 = 0;
    self->unk_b5a = -self->rot_y;
    self->unk_b5c = 0;
    LFLD(s16, self, 0xb5e) = rz;
}

static inline void Bump_021a9be8(Robo021ca458 *self) {
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

void Robo021ca458_State0f(Robo021ca458 *self) {
    GroupActorDesc desc;
    VecFx32 z;
    Pose_021a9be8 m;
    VecFx32 t;
    Actor *tg;
    Actor *a;
    EffectObj *o;
    s32 lim;
    BOOL fall;
    ActorSub40 *s;
    u16 tm;

    tg = FindActor_021a9be8(self->target);
    if (tg != NULL) {
        ActorSub44 *c = tg->unk_44;
        if (!(c != NULL && Both_021a9be8(c) && (u16)(tg->id & 0xf000) == 0x5000 && Has_021a9be8(c))) {
            tg = NULL;
        } else if (self->unk_b2f == 0) {
            self->unk_b2f++;
        }
    }
    fall = FALSE;
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
        self->unk_b36 = 0;
        self->unk_b24 |= 0x40000;
    }
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc68a, 0x555, 1);
        self->speed = 0;
        self->velY = 0;
        if (self->unk_b36 != 0) {
            self->unk_b36 = 1;
        }
        self->friction = 0;
        self->gravity = 0x29;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->unk_b36 == 0) {
            History_SetState(self->fsm, 1, 0);
            break;
        }
        if (Frame_021a9be8(self->model) > 0x14000) {
            Model0218fe1c_SeekMainAnim(self->model, 0x14000);
            self->unk_ae4_0 = 1;
        }
        if (self->fsm->timer == 0x14) {
            o = Effect_SpawnId(0x640, &self->unk_a74);
            if (o != NULL) {
                SetFx_021a9be8(self, o, 0);
            }
        }
        s = self->fsm;
        s->timer++;
        if (s->timer >= 0x20) {
            s32 i;
            self->fsm->timer = 0x20;
            SndMgr_PlayAtPitch(data_02097e4c, 0x44, &self->pos, 2);
            SndMgr_PlayAt(data_02097e4c, 0x78, &self->pos, 0);
            desc.kind = 0x480c;
            desc.group = 0x4000;
            for (i = 0; i < 4; i++) {
                desc.args[i] = 0;
            }
            desc.unk_0c = -1;
            a = (Actor *)Group_SpawnActor(data_ov000_021ccd64, &desc, (u8 *)self + 0xa74, (u8 *)self + 0x7c, 0xffff);
            if (a != NULL) {
                ActorSub4c *p;
                a->flags_0 = 1;
                a->unk_60 = data_ov000_021ca12c;
                p = a->targetObj;
                if (p != NULL) {
                    p->target = self->id;
                    p->unk_18 |= 8;
                }
                Actor_SendMsgU8(a, self->id, 9);
                self->unk_b24_5 = 1;
                self->unk_b24_7 = 0;
                self->unk_b1c = a->id;
                o = Effect_SpawnId(0x195, &self->pos);
                if (o != NULL) {
                    SetFx_021a9be8(self, o, -0x7b);
                }
                self->fsm->st++;
            }
        }
        break;
    case 2:
        if (Frame_021a9be8(self->model) > 0x14000) {
            Model0218fe1c_SeekMainAnim(self->model, 0x14000);
        }
        if (self->unk_b36 == 0) {
            a = FindActor_021a9be8(self->unk_b1c);
            if (a == NULL || (a->fsm != NULL ? a->fsm->current : 0) == 9) {
                self->fsm->timer = 0;
                self->fsm->st = 10;
            }
        }
        break;
    case 10:
        a = FindActor_021a9be8(self->unk_b1c);
        if (a != NULL) {
            u16 ang;
            Actor_SendMsgU8(a, self->id, 0xb);
            if (a != NULL) {
                VecFx32 *q = LFLD(VecFx32 *, a, 0x48);
                if (q != NULL) {
                    t.x = q->x;
                    t.y = q->y;
                    t.z = q->z;
                } else {
                    t.x = a->pos.x;
                    t.y = a->pos.y;
                    t.z = a->pos.z;
                }
                if (Hit_CastSegment((VecFx32 *)((u8 *)self + 0x70), &t, -1, 0, 0, -1) != -0x1000) {
                    t.x -= self->pos.x;
                    t.y -= self->pos.y;
                    t.z -= self->pos.z;
                    VEC_MultAdd(0xc00, &t, (VecFx32 *)((u8 *)self + 0x70), &t);
                    m.pos = t;
                    m.rx = a->rot_x;
                    m.ry = a->rot_y;
                    m.rz = a->rot_z;
                    m.unk = 0;
                    Actor_SendMsg(a, self->id, 7, 1, sizeof(Pose_021a9be8), &m);
                }
            }
            ang = self->rot_y;
            if (tg != NULL) {
                if (tg->unk_44 != NULL) {
                    ang = Actor_YawToPos(self, tg->unk_44);
                } else {
                    ang = AngleTo_021a9be8(self,tg);
                }
            }
            {
                VecFx32 p;
                p.x = a->pos.x;
                p.y = a->pos.y;
                p.z = a->pos.z;
                p.x += FX_SinCosTable_[(ang >> 4) * 2];
                p.z += FX_SinCosTable_[(ang >> 4) * 2 + 1];
                a->unk_84 = p;
            }
            a->rot_x = 0;
            a->rot_y = ang;
            a->rot_z = 0;
            a->target = self->target;
            self->rot_y = Angle_Approach(ang, self->rot_y, 0x400, 1, 0x8000);
            SndMgr_PlayAt(data_02097e4c, 0x5c, &self->pos, 0);
        }
        self->unk_b1c = 0xffff;
        self->unk_b1e = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->target = 0xffff;
        self->fsm->st++;
        break;
    case 11:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->moveYaw = self->rot_y;
            if (self->unk_b36 != 0) {
                self->fsm->st = 0;
            } else {
                History_SetState(self->fsm, 1, 0);
            }
        }
        break;
    }
    if (self->fsm->st >= 10) {
        return;
    }
    if (!self->unk_b24_17) {
        u16 yaw = FieldCam_GetYaw(&data_ov000_021ccd54->cam);
        u16 ang;
        if (self->padCur & 0xf0) {
            self->speed = self->unk_b08 >> 2;
            Actor_MoveByPad(self, yaw, 0, (u8 *)self + 0xb70);
            ang = self->moveYaw;
        } else {
            self->friction = 0x29;
            Actor_Move(self, 0);
            ang = self->rot_y;
        }
        if (tg != NULL) {
            if (tg->unk_44 != NULL) {
                ang = Actor_YawToPos(self, tg->unk_44);
            } else {
                ang = AngleTo_021a9be8(self,tg);
            }
        }
        self->rot_y = Angle_Approach(ang, self->rot_y, 0x400, 1, 0x8000);
    } else {
        Actor_Move(self, 0);
    }
    Body_Update(self->hit, 1, 0, 0);
    if (self->velY < 0 && (self->hit->unk_50 & 0x20000000)) {
        self->velY = 0;
        self->hit->unk_9a |= 0x20;
        if (self->unk_b24_17) {
            self->unk_b24_17 = 0;
            self->moveYaw = self->rot_y;
            self->speed = 0;
        }
    }
    Bump_021a9be8(self);
    tm = self->fsm->timer;
    if (tm == 0) {
        return;
    }
    {
        ActorSub4c *p;
        u8 *x;
        z.x = 0;
        z.y = 0;
        z.z = 0;
        p = (ActorSub4c *)data_ov000_021ccd30->unk_11c;
        if (p == NULL) return;
        x = LFLD(u8 *, p, 0x70);
        if (x == NULL) return;
        func_ov000_02168e18(x, tm, 0x20, &z);
    }
}
}
