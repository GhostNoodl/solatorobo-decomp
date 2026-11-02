#include "ov011/ov011.h"

struct Ov011Rot {
    u16 x, y, z;
};

extern "C" {

u32 Rand_UpTo(u32 max);
s32 Rand_PlusMinus(s32 max);
extern const VecFx32 data_02092a50;
extern u8 data_ov011_0220755c[];
extern char data_ov011_022075d4[];
Actor *Actor_SpawnKind(s32 kind, VecFx32 *pos, Ov011Rot *rot, u16 a, u16 b);

#pragma force_active on
void Ov011Act7da4_StateHurt(Ov011Act7da4 *self) {
    History_SetState(self->fsm, 1, 0);
}

void Ov011Act7da4_StateShoot(Ov011Act7da4 *self) {
    Ov011Rot rot;
    VecFx32 v;
    switch (self->fsm->st) {
    case 0:
        self->unk_f0 = 0;
        self->fsm->st++;
        self->fsm->timer = 30;
        break;
    case 1:
        if (self->fsm->timer != 0) {
            self->fsm->timer--;
        }
        if (self->fsm->timer == 18) {
            EffectObj *e;
            Ov011_VecSet(&self->unk_84, Rand_PlusMinus(0x4000), -Rand_UpTo(0x3000), -0xf000);
            Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = Effect_SpawnId(0x389, &v);
            if (e == NULL) {
                return;
            }
            e->SetScaleAll(0x2000);
            e->speed = 0x299a;
        } else if (self->fsm->timer == 0) {
            Robo021ca458 *pl = (Robo021ca458 *)ActorMgr_FindPlayer();
            if (pl != NULL) {
                Actor *o;
                v.x = pl->unk_af0.x;
                v.y = pl->unk_af0.y;
                v.z = pl->unk_af0.z;
                v.y += 0x3000;
                v.x -= self->unk_84.x;
                v.y -= self->unk_84.y;
                v.z -= self->unk_84.z;
                VEC_Normalize(&v, &v);
                rot.x = FX_Atan(-v.y);
                rot.y = FX_Atan2(v.x, v.z);
                rot.z = 0;
                o = Actor_SpawnKind(0x4805, &self->unk_84, &rot, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_0220755c;
                }
            }
            self->unk_f0++;
            if (self->unk_f0 < 5) {
                self->fsm->timer = 20;
            } else {
                History_SetState(self->fsm, 1, 0);
            }
        }
        break;
    }
}
void Ov011Act7da4_StateAttack3(Ov011Act7da4 *self) {
    Ov011Rot rot;
    VecFx32 v;
    switch (self->fsm->st) {
    case 0:
        self->unk_f0 = 0;
        self->fsm->st++;
        self->fsm->timer = 30;
        break;
    case 1:
        if (self->fsm->timer != 0) {
            self->fsm->timer--;
        }
        if (self->fsm->timer == 18) {
            EffectObj *e;
            Ov011_VecSet(&self->unk_84, 0x4000, Rand_PlusMinus(0x3000), -0xf000);
            if (!(self->unk_f0 & 1)) {
                self->unk_84.x = -self->unk_84.x;
            }
            Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = Effect_SpawnId(0x389, &v);
            if (e == NULL) {
                return;
            }
            e->SetScaleAll(0x2000);
            e->speed = 0x299a;
        } else if (self->fsm->timer == 0) {
            Robo021ca458 *pl = (Robo021ca458 *)ActorMgr_FindPlayer();
            if (pl != NULL) {
                Actor *o;
                v.x = pl->unk_af0.x;
                v.y = pl->unk_af0.y;
                v.z = pl->unk_af0.z;
                v.y += 0x3000;
                v.x -= self->unk_84.x;
                v.y -= self->unk_84.y;
                v.z -= self->unk_84.z;
                VEC_Normalize(&v, &v);
                rot.x = FX_Atan(-v.y);
                rot.y = FX_Atan2(v.x, v.z);
                rot.z = 0;
                if (self->unk_f0 & 1) {
                    rot.y += 0x4000;
                } else {
                    rot.y -= 0x4000;
                }
                o = Actor_SpawnKind(0x4804, &self->unk_84, &rot, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_022075d4;
                }
            }
            self->unk_f0++;
            if (self->unk_f0 < 6) {
                self->fsm->timer = 20;
            } else {
                History_SetState(self->fsm, 1, 0);
            }
        }
        break;
    }
}
#pragma force_active reset
}
