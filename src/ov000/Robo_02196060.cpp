#include "types.h"
#include "ov000/ObjLayouts.h"
#include "ov000/FieldMgr.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern char data_ov000_021cc456[];
extern void *data_02097e4c;
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void func_ov000_02199dc0(ActorSub4c *self, Actor *out);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
void HitSphere_Link(void *a);
BOOL History_SetState(void *s, s32 a, s32 b);
void Actor_Move(Actor *self, s32 a);
void Body_Update(void *a, s32 b, s32 c, s32 d);

static inline void SetVel02196060(ActorEx *self, s32 x, s32 y, s32 z) {
    self->speed = x;
    self->velY = y;
    self->friction = z;
}

void ActorEx_StateThrown(ActorEx *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc456, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        if (self->targetObj->unk_01 == 1) {
            func_ov000_02199dc0(self->targetObj, self);
            SndMgr_PlayAt(data_02097e4c, 0xb, (u8 *)self + 0x70, 0);
            self->fsm->st++;
        } else {
            SetVel02196060(self, 0x229, 0x27, 0);
            self->gravity = 0x52;
            self->fsm->st++;
        }
        self->moveYaw = self->rot_y;
        {
            ActorSub44 *q = self->unk_44;
            self->unk_44->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        if (self->hit != NULL) {
            ActorSub48 *p = self->hit;
            p->unk_9a_0 = 1;
            p->unk_9a_3 = 1;
            HitSphere_Link(p);
            self->hit->unk_9a |= 0x12;
        }
        break;
    case 1:
        s->timer++;
        if (s->timer > 2) {
            History_SetState(self->fsm, 4, 0);
        }
        if (self->velY > 0 && (self->hit->unk_50 & 0x80000000)) {
            self->velY = -0xcd;
        }
        {
            FieldExit *o = FieldMgr_FindExitAt(data_ov000_021ccd6c, &self->pos);
            if (o != NULL) {
                u16 ang = (u64)o->dir;
                self->speed = FX_Mul(self->speed, 0x59a);
                if (self->speed < 0x8f) {
                    self->speed = 0x8f;
                }
                self->moveYaw = ang;
                self->gravity = 0x52;
            }
        }
        Actor_Move(self, 0);
        if (self->hit != NULL) {
            Body_Update(self->hit, 0, 0, 0);
        }
        break;
    }
}
}
