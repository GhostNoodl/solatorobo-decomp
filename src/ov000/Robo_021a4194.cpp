#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021a4194;

extern "C" {
extern char *data_ov000_021ca050[];
extern char *data_ov000_021ca040[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc654[];
extern char data_ov000_021cc65a[];
extern char data_ov000_021cc660[];
extern char data_ov000_021cc61e[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL History_SetState(void *p, s32 a, s32 b);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL Hit_DiffInCylinder(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *p, void *a, s32 b, s32 c);
void Model0218fe1c_SetLoop(void *p);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
void Model0218fe1c_SetReverse(void *a);
BOOL Model0218fe1c_IsAnimDone(void *a);
void Actor_Move(Actor *self, s32 a);
void Body_Update(void *a, s32 b, s32 c, s32 d);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void Actor_SendMsgU8(void *o, u16 id, s32 c);
void Target_Set(void *a, void *b);
void Geom_AddRotatedOffset(VecFx32 *pos, const VecFx32 *ofs, s32 angle);

static inline Actor *FindActor_021a4194(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Robo021ca458_State06(Robo021ca458 *self) {
    Actor *t;
    ActorSub4c *info;
    ActorSub40 *sub;
    BOOL hit;
    VecFx32 pos;
    VecFx32 o;
    VecFx32 p;
    Pose_021a4194 pose;

    self->hit->unk_9a |= 0x20;
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    t = FindActor_021a4194(self->target);
    info = NULL;
    if (t != NULL) {
        info = t->targetObj;
    }
    if (info == NULL && self->fsm->st < 0x14) {
        History_SetState(self->fsm, 1, 0);
        return;
    }
    sub = self->fsm;
    switch (sub->st) {
    case 0:
        if (info->type != 0x12) {
            u16 ang;
            if (t == NULL || t == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
            }
            self->moveYaw = ang;
            self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            {
                ActorSub40 *s;
                pos.x = self->pos.x;
                pos.y = self->pos.y;
                pos.z = self->pos.z;
                pos.y -= 0x1000;
                s = self->fsm;
                s->timer++;
                if (s->timer < 0x23 &&
                    !Hit_DiffInCylinder(&t->pos, &pos, t->radius * 2 + 0x1000, 0x3800)) {
                    hit = FALSE;
                    Model0218fe1c_SetAnim(self->model, data_ov000_021ca050[self->unk_b24_5], 0x400, 0);
                    Model0218fe1c_SetLoop(self->model);
                    self->speed = 0x15c;
                    Actor_Move(self, 0);
                    Body_Update(self->hit, 0, 0, 0);
                    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
                        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
                        self->speed = 0x66;
                        self->friction = 0;
                        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                            self->velY = 0x200;
                        }
                        self->gravity = 0x52;
                        self->unk_b24_17 = 1;
                        hit = TRUE;
                    }
                    if (!hit) {
                        return;
                    }
                    History_SetState(self->fsm, 4, 0);
                    {
                        Actor *a = FindActor_021a4194(self->unk_b1c);
                        if (a != NULL) {
                            pose.pos = self->pos;
                            pose.pos.y += self->centerY;
                            pose.rx = a->rot_x;
                            pose.ry = a->rot_y;
                            pose.rz = a->rot_z;
                            pose.unk = 0;
                            Actor_SendMsg(a, self->id, 7, 1, 0x18, &pose);
                            Actor_SendMsgU8(a, self->id, 0xa);
                            if (a->targetObj != NULL) {
                                a->targetObj->unk_18_0 = 0;
                            }
                        }
                    }
                    self->unk_b1c = 0xffff;
                    self->unk_b1e = 0xffff;
                    self->unk_b24_5 = 0;
                    self->unk_b24_7 = self->unk_b24_9;
                    return;
                }
            }
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
        }
        self->fsm->st++;
    case 1: {
        char *anim;
        if (self->unk_b1c != 0xffff) {
            if (self->unk_b22_3) {
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc64e, 0x555, 0);
                Model0218fe1c_SetAnimFrame(self->model, 0xa000);
                Model0218fe1c_SetReverse(self->model);
                self->fsm->st++;
                return;
            }
            if (self->unk_b24_5 == 2) {
                anim = data_ov000_021cc654;
            } else {
                anim = data_ov000_021cc65a;
            }
        } else {
            if (info->type == 0x12) {
                self->fsm->st = 10;
                return;
            }
            if (!self->unk_b22_3) {
                if (info->type == 0xd) {
                    anim = data_ov000_021cc654;
                } else {
                    anim = self->unk_b24_1 ? data_ov000_021cc65a : data_ov000_021cc660;
                }
            } else {
                anim = data_ov000_021cc64e;
            }
        }
        Model0218fe1c_SetAnim(self->model, anim, 0x400, 0);
        self->fsm->st++;
        return;
    }
    case 2: {
        s16 f = self->model->anim_state;
        Actor *a;
        if (f == 1 || self->unk_b22_3) {
            sub->st = 10;
            return;
        }
        if (f <= 1) {
            return;
        }
        a = FindActor_021a4194(self->unk_b1c);
        if (a != NULL) {
            if (a->targetObj->unk_02 == 7) {
                if (a->model != NULL) {
                    Model0218fe1c_SetAnim(a->model, data_ov000_021cc660, 0x1000, 0);
                }
                self->fsm->timer = self->model->anim_state;
                self->fsm->st++;
                return;
            }
        } else if (info != NULL && info->unk_02 == 7) {
            self->fsm->timer = self->model->anim_state;
            self->fsm->st++;
            return;
        }
        self->fsm->st = 10;
        return;
    }
    case 3:
        if (sub->timer != 0) {
            sub->timer--;
        }
        if (sub->timer == 0) {
            self->fsm->st = 10;
        }
        return;
    case 10:
        if (self->unk_b1c != 0xffff) {
            Actor *a = FindActor_021a4194(self->unk_b1c);
            if (a != NULL) {
                a->target = t->id;
                Actor_SendMsgU8(a, self->id, 6);
            }
        } else {
            Actor_SendMsgU8(t, self->id, 6);
            t->target = 0xffff;
            Target_Set(info, self);
            if (info->unk_02 == 6) {
                self->unk_b29_0 = 1;
            }
        }
        self->fsm->st++;
        return;
    case 11:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            if (info->unk_02 == 6) {
                if (t->unk_18 != 3) {
                    if (!self->unk_b24_1) {
                        self->unk_93_0 = 1;
                    } else {
                        Model0218fe1c_SetAnim(self->model, data_ov000_021cc61e, 0x400, 0);
                        Model0218fe1c_SetLoop(self->model);
                    }
                    {
                        p.x = t->pos.x;
                        p.y = t->pos.y;
                        p.z = t->pos.z;
                        o.x = 0;
                        o.y = 0;
                        o.z = -0x800;
                        Geom_AddRotatedOffset(&p, &o, t->rot_y);
                        self->moveYaw = FX_Atan2(p.x - self->pos.x, p.z - self->pos.z);
                    }
                    self->speed = 0x15c;
                    self->friction = 0;
                    self->gravity = 0;
                    self->fsm->st = 0x14;
                } else {
                    History_SetState(self->fsm, 1, 0);
                }
            } else {
                Model0218fe1c_SetAnim(self->model, data_ov000_021ca040[self->unk_b24_5], 0xcd, 0);
                Model0218fe1c_SetLoop(self->model);
                self->fsm->st = 0x32;
            }
            self->target = 0xffff;
            self->unk_5c->show = 0;
            func_ov000_021bd300(self->unk_5c);
            ActorMarker_SetPos(self->unk_5c, (VecFx32 *)((u8 *)self + 0x70), 0);
        }
        self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        if (info->unk_02 == 6) {
            self->unk_b29_0 = 1;
            self->unk_b29_3 = 1;
        }
        return;
    case 0x14:
        self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        Actor_Move(self, 0);
        self->unk_b29_0 = 1;
        self->unk_b29_3 = 1;
        return;
    case 0x32:
        if (self->hit->unk_50 & 0x20000000) {
            self->velY = 0;
            return;
        }
        self->gravity = 0x52;
        Actor_Move(self, 0);
        Body_Update(self->hit, 0, 0, 0);
        break;
    }
}
}
