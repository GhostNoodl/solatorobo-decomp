#include "ov000/LoCommon.h"
#include "ov000/FieldCam.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/FieldMgr.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021a5d00;

extern "C" {

extern void *gSndMgr;
extern char data_ov000_021cc67e[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc660[];
extern char data_ov000_021cc684[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
u16 FX_Atan2(s32 y, s32 x);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL Hit_DiffInCylinder(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void Actor_Move(Actor *self, s32 turn);
void Body_Update(void *a, s32 b, s32 c, s32 d);
BOOL Model0218fe1c_IsAnimDone(void *a);
void Shared_ChangeFlags(s32 a, s32 b);
void Shared_SetEventActor(u16 a, u16 b);
void func_ov000_02182590(void *p);
BOOL StageRes_HasQueued(void);
void Actor_SendMsgU8(void *o, u16 id, s32 c);
void Target_Set(ActorSub4c *info, Actor *actor);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
BOOL History_SetState(St_021a5d00 *st, s32 state, s32 x);

static inline Actor *FindActor021a5d00(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline u16 AngleTo021a5d00(Robo021ca458 *self, Actor *a) {
    if (a == NULL || a == self) {
        return self->rot_y;
    }
    return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
}

static inline BOOL Ev19_021a5d00(void) {
    LangBlockB *e = gFieldMgr->blockB;
    if (e != NULL && e->unk_19_0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Fx021a5d00(Robo021ca458 *self, ActorSub4c *info) {
    if (!Ev19_021a5d00() && !(info != NULL && (info->unk_18_4 ? TRUE : FALSE))) {
        VecFx32 v;
        v = self->pos;
        v.y += self->height;
        func_ov000_021899d8(&v, NULL, 0x8000, 1, 0x1000, 0x1000);
    }
    self->unk_44->unk_22_1 = 0;
}

static inline void Reset021a5d00(Robo021ca458 *self) {
    self->unk_b24_5 = 0;
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_7 = self->unk_b24_9;
    History_SetState((St_021a5d00 *)self->fsm, 1, 0);
}

void Robo021ca458_State08(Robo021ca458 *self) {
    Actor *a;
    ActorSub4c *info;
    self->hit->unk_9a |= 0x20;
    a = FindActor021a5d00(self->target);
    info = NULL;
    if (a != NULL) {
        info = a->targetObj;
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    switch (((St_021a5d00 *)self->fsm)->state) {
    case 0: {
        char *lbl = data_ov000_021cc67e;
        if (a != NULL) {
            VecFx32 pos;
            pos = self->pos;
            pos.y -= 0x1000;
            self->moveYaw = AngleTo021a5d00(self, a);
            self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            {
                St_021a5d00 *st = (St_021a5d00 *)self->fsm;
                st->timer++;
                if (st->timer < 0xf) {
                    if (!Hit_DiffInCylinder(&a->pos, &pos, (a->radius << 1) + 0x19a, 0x3800)) {
                        Model0218fe1c_SetAnim(self->model, data_ov000_021cc61e, 0x400, 0);
                        Model0218fe1c_SetLoop(self->model);
                        self->speed = 0x15c;
                        Actor_Move(self, 0);
                        Body_Update(self->hit, 0, 0, 0);
                        return;
                    }
                }
            }
            if (pos.y > self->pos.y) {
                lbl = data_ov000_021cc660;
            }
        }
        Model0218fe1c_SetAnim(self->model, lbl, 0x400, 0);
        ((St_021a5d00 *)self->fsm)->state++;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        return;
    }
    case 1:
        Fx021a5d00(self, info);
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (a != NULL && info != NULL) {
            BOOL done;
            u8 *o44;
            o44 = ((u8 *)a->unk_44);
            done = FALSE;
            if (info->unk_18_1 && info->unk_03 != 10 && info->unk_03 != 11) {
                FieldState *g;
                Shared_ChangeFlags(0x3c0, 0x80);
                Shared_SetEventActor(a->kind, a->id);
                g = gSceneCmd;
                g->stageFlags = 1;
                func_ov000_02182590((u8 *)g + 0xac);
                if (StageRes_HasQueued()) {
                    done = TRUE;
                }
            }
            if (!done && o44 != NULL) {
                u8 k0 = info->type;
                u8 k1 = info->unk_01;
                if ((k0 == 5 || k0 == 7) && (k1 == 4 || k1 == 6)) {
                    self->unk_b24_5 = 3;
                    self->unk_b24_7 = 3;
                    self->unk_b1c = self->target;
                    self->target = 0xffff;
                    Actor_SendMsgU8(a, self->id, 0xd);
                    Target_Set(info, self);
                    info->unk_01 = 9;
                    if (info->unk_03 != 10 && info->unk_03 != 11) {
                        SndMgr_PlayVolume(gSndMgr, 0x4a, -1, -1, -1);
                    }
                    Model0218fe1c_SetAnim(self->model, data_ov000_021cc684, 0x1000, 0);
                    ((St_021a5d00 *)self->fsm)->state++;
                    ((St_021a5d00 *)self->fsm)->timer = 0;
                    return;
                }
            }
        }
        Reset021a5d00(self);
        return;
    case 2:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            St_021a5d00 *st = (St_021a5d00 *)self->fsm;
            st->timer++;
            if (st->timer > 0x14) {
                Reset021a5d00(self);
            }
        }
        Fx021a5d00(self, info);
        return;
    }
}

}
