#include "types.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern char data_ov000_021cc456[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd6c;
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02199dc0(void *a, void *b);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void HitSphere_Link(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void *func_ov000_021b68b8(void *a, void *pos);
void Actor_Move(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);

static inline void SetVel02196060(ActorEx *self, s32 x, s32 y, s32 z) {
    self->speed = x;
    self->velY = y;
    self->friction = z;
}

void func_ov000_02196060(ActorEx *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc456, 0x1000, 0);
        func_ov000_021915a0(self->model);
        if (self->targetObj->unk_01 == 1) {
            func_ov000_02199dc0(((u8 *)self->targetObj), self);
            func_02049f44(data_02097e4c, 0xb, (u8 *)self + 0x70, 0);
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
            func_ov000_02198360(self->fsm, 4, 0);
        }
        if (self->velY > 0 && (self->hit->unk_50 & 0x80000000)) {
            self->velY = -0xcd;
        }
        {
            u8 *o = (u8 *)func_ov000_021b68b8(data_ov000_021ccd6c, (u8 *)self + 0x70);
            if (o != NULL) {
                u16 ang = (u64)LFLD(u16, o, 0x1a);
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
            func_ov000_021987b8(self->hit, 0, 0, 0);
        }
        break;
    }
}
}
