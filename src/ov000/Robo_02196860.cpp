#include "types.h"
#include "Main/Res/StageFlags.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern char data_ov000_021cc456[];
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void HitSphere_Link(void *a);
void HitSphere_Unlink_0203f364(void *a);
BOOL History_SetState(void *s, s32 a, s32 b);
Robo021ca458 *ActorMgr_FindPlayer(void);
void *Target_Get(void *p);
void Target_Set(void *a, void *b);
void Ov003Pickup_Update(void *self, s32 a);
void *Ov003_FindPlayerInRange(void *pos, s32 a, s32 b);
s32 Rand_UpTo(s32 n);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);

void ActorEx_State0a(ActorEx *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub4c *m = self->targetObj;
        if (m->target != 0xffff && (u8)(m->unk_02 + 0xff) <= 1) {
            BOOL done = FALSE;
            Robo021ca458 *p = ActorMgr_FindPlayer();
            if (p->id == self->targetObj->target) {
                StageFlags *g = data_0214a424;
                u32 n = g->unk_016 + 1;
                if (n >= 0xffff) {
                    n = 0xffff;
                }
                g->unk_016 = n;
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
                if (self->targetObj->unk_03 != 0) {
                    self->targetObj->target = 0xffff;
                    Ov003Pickup_Update(self, 0);
                }
                done = TRUE;
            }
            if (done) {
                History_SetState(self->fsm, 0x15, 0);
                break;
            }
        }
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc456, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        if (self->unk_44 != NULL) {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        if (self->hit != NULL) {
            self->speed = 0xf6 - Rand_UpTo(0x7b);
            self->velY = 0x2e1 - Rand_UpTo(0x5c);
            self->friction = 0;
            self->gravity = 0x52;
            if (self->targetObj->target == 0xffff) {
                self->moveYaw = self->rot_y;
            } else {
                u8 *t = (u8 *)Target_Get(((u8 *)self->targetObj));
                if (t != NULL) {
                    VecFx32 a;
                    VecFx32 b;
                    s32 y;
                    self->moveYaw = FX_Atan2(self->pos.x - LFLD(s32, t, 0x70), self->pos.z - LFLD(s32, t, 0x78));
                    a = *(VecFx32 *)(t + 0x70);
                    b = *(VecFx32 *)((u8 *)self + 0x70);
                    a.y += LFLD(s32, t, 0x6c);
                    y = b.y + self->centerY;
                    b.y = y;
                    if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) != -0x1000) {
                        a.x = a.x - b.x;
                        a.y = a.y - b.y;
                        a.z = a.z - b.z;
                        VEC_MultAdd(0xc00, &a, &b, &b);
                        if (b.y < y) {
                            b.y = y;
                        }
                        *(VecFx32 *)((u8 *)self + 0x70) = b;
                    }
                }
            }
            {
                ActorSub48 *q = self->hit;
                q->unk_9a_0 = 1;
                q->unk_9a_3 = 1;
                HitSphere_Link(q);
                self->hit->unk_9a |= 0x12;
                self->hit->unk_9a_4 = 0;
            }
            self->fsm->st++;
        } else {
            History_SetState(self->fsm, 1, 0);
        }
        self->targetObj->target = 0xffff;
        break;
    }
    case 1:
        if (self->hit != NULL) {
            self->hit->unk_9a_4 = 0;
        }
        History_SetState(self->fsm, 4, 0);
        break;
    }
    if (self->targetObj != NULL && self->targetObj->type == 2) {
        void *r = Ov003_FindPlayerInRange(&self->pos, self->radius, self->height);
        if (r != NULL) {
            Target_Set(((u8 *)self->targetObj), r);
            History_SetState(self->fsm, 0xd, 0);
        }
    }
}

}
