#include "ov009/ov009.h"

extern "C" {

extern VecFx32 *Actor_GetTargetSub44(Actor *self);
extern void Actor_TurnToPos(Actor *self, VecFx32 *v, s32 a);
extern void HitSphere_Link(ActorSub48 *p);
extern void Ov009ActExVt_0221802c_HitNearby(Ov009ActExVt_0221802c *self);

#define OV009_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV009_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV009_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov009_02215714(Ov009ActExVt_0221802c *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
        }
        self->hit->unk_30 = 0x40000000;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        p = Actor_GetTargetSub44(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            self->unk_84.x = d.x;
            self->unk_84.y = d.y;
            self->unk_84.z = d.z;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV009_SQRTCNT = 1;
                OV009_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV009_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV009_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV009_SIN(self->rot_y));
            d.z = FX_Mul(r, OV009_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = FX_Mul(d.x, 0x666);
            self->velY = FX_Mul(d.y, 0x666);
            self->friction = FX_Mul(d.z, 0x666);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            self->unk_d0 |= 0x200000;
            self->hit->unk_30 = 0x20000000;
        } else {
            self->speed = 0x4cd;
            self->moveYaw = self->rot_y;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_d4 = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->unk_d0 & 0x200000) {
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        } else {
            Actor_Move(self, 0);
        }
        Ov009ActExVt_0221802c_HitNearby(self);
        Body_Update(self->hit, 1, 0, 0);
        if ((self->hit->unk_50 & 0x60000000) || ++self->unk_d4 >= 150) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
}

}
