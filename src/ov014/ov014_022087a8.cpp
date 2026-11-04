#include "ov014/ov014.h"

extern "C" {

extern Ov003Actor *Target_Get(void *p);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void Ov014ActEx_02208618_UpdateThrown(Ov014ActEx_02208618 *self);
extern void Ov014ActEx_02208618_HitNearby(Ov014ActEx_02208618 *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void Ov014ActEx_02208618_StateThrown(Ov014ActEx_02208618 *self) {
    Ov003Actor *o = Target_Get(self->targetObj);
    if (o != NULL) {
        {
            ActorSub48 *m = o->hit;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                HitSphere_Unlink_0203f364(m);
            }
        }
        if (o->kind == 0x1000) {
            Ov014ActEx_02208618_UpdateThrown(self);
            return;
        }
        switch (self->fsm->st) {
        case 0: {
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
            }
            {
                s64 sq;
                dx = self->pos.x - self->unk_84.x;
                dz = self->pos.z - self->unk_84.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->speed = FX_Mul(OV014_SIN(a), 0x666);
            self->velY = FX_Mul(OV014_COS(a), 0x666);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            self->moveYaw = self->rot_y;
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
            Actor_Move(self, 0);
            Ov014ActEx_02208618_HitNearby(self);
            if ((self->hit->unk_50 & 0x20000000) || ++self->unk_d4 >= 200) {
                self->unk_d0 |= 0x1000;
                History_SetState(self->fsm, 0x15, 0);
            }
            if (self->hit->unk_50 & 0x20000000) {
                VecFx32 v;
                EffectObj *e;
                v = self->pos;
                v.y = 0x47800;
                e = Effect_SpawnId(0x67, &v);
                e->SetScaleAll(0x2000);
                e->SetRotXYZ(0, (u16)(self->rot_y + 0x7fff), 0);
            }
            break;
        }
    } else {
        self->unk_d0 |= 0x1000;
        History_SetState(self->fsm, 0x15, 0);
    }
}

}
