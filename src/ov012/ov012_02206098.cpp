#include "ov012/ov012.h"

extern "C" {

extern void Ov012ActExVt_0220b1e8_HitNearby(Ov012ActExVt_0220b1e8 *self);

void Ov012ActExVt_0220b1e8_UpdateThrown(Ov012ActExVt_0220b1e8 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
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
                OV012_SQRTCNT = 1;
                OV012_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV012_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV012_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV012_SIN(self->rot_y));
            d.z = FX_Mul(r, OV012_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = FX_Mul(d.x, 0x4cd);
            self->velY = FX_Mul(d.y, 0x4cd);
            self->friction = FX_Mul(d.z, 0x4cd);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            if (!(self->unk_d0 & 0x100000)) {
                Obj02190758_SetRot(&self->mdl, &self->rot_x, 0);
            }
            self->unk_d0 |= 0x400000;
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
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->unk_d0 & 0x400000) {
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        } else {
            Actor_Move(self, 0);
        }
        Ov012ActExVt_0220b1e8_HitNearby(self);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x60000000) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
}

}
