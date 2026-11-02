#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_02208fe4(Ov014ActEx_02208618 *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02208a9c(Ov014ActEx_02208618 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        p = func_ov000_0218d2e0(self);
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
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = FX_Mul(d.x, 0x666);
            self->velY = FX_Mul(d.y, 0x666);
            self->friction = FX_Mul(d.z, 0x666);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            self->unk_d0 |= 0x200000;
        } else {
            self->speed = 0x666;
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
        func_ov014_02208fe4(self);
        if ((self->hit->unk_50 & 0x20000000) || ++self->unk_d4 >= 200) {
            self->unk_d0 |= 0x1000;
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
}

}
