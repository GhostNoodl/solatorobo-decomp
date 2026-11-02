#include "ov011/ov011.h"

struct Ov011Rot {
    u16 x, y, z;
};

extern "C" {

s32 Rand_UpTo(s32 max);
s32 Rand_PlusMinus(s32 max);
extern const VecFx32 data_02092a50;
extern u8 data_ov011_0220755c[];
extern u8 data_ov011_022075d4[];
Ov011Eff *func_02065f88(s32 id, VecFx32 *pos);
Ov011Obj *func_ov000_0219be1c(s32 kind, VecFx32 *pos, Ov011Rot *rot, u16 a, u16 b);

#pragma force_active on
void func_ov011_02205e9c(Ov011Act7da4 *self) {
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov011_02205eb4(Ov011Act7da4 *self) {
    Ov011Rot rot;
    VecFx32 v;
    switch (self->unk_40->state) {
    case 0:
        self->unk_f0 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 30;
        break;
    case 1:
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        if (self->unk_40->timer == 18) {
            Ov011Eff *e;
            Ov011_VecSet(&self->unk_84, Rand_PlusMinus(0x4000), -Rand_UpTo(0x3000), -0xf000);
            Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = func_02065f88(0x389, &v);
            if (e == NULL) {
                return;
            }
            e->v0c(0x2000);
            e->unk_3c = 0x299a;
        } else if (self->unk_40->timer == 0) {
            Ov011Player *pl = (Ov011Player *)func_ov000_0219bf90();
            if (pl != NULL) {
                Ov011Obj *o;
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
                o = func_ov000_0219be1c(0x4805, &self->unk_84, &rot, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_0220755c;
                }
            }
            self->unk_f0++;
            if (self->unk_f0 < 5) {
                self->unk_40->timer = 20;
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}
void func_ov011_02206120(Ov011Act7da4 *self) {
    Ov011Rot rot;
    VecFx32 v;
    switch (self->unk_40->state) {
    case 0:
        self->unk_f0 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 30;
        break;
    case 1:
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        if (self->unk_40->timer == 18) {
            Ov011Eff *e;
            Ov011_VecSet(&self->unk_84, 0x4000, Rand_PlusMinus(0x3000), -0xf000);
            if (!(self->unk_f0 & 1)) {
                self->unk_84.x = -self->unk_84.x;
            }
            Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = func_02065f88(0x389, &v);
            if (e == NULL) {
                return;
            }
            e->v0c(0x2000);
            e->unk_3c = 0x299a;
        } else if (self->unk_40->timer == 0) {
            Ov011Player *pl = (Ov011Player *)func_ov000_0219bf90();
            if (pl != NULL) {
                Ov011Obj *o;
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
                o = func_ov000_0219be1c(0x4804, &self->unk_84, &rot, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_022075d4;
                }
            }
            self->unk_f0++;
            if (self->unk_f0 < 6) {
                self->unk_40->timer = 20;
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}
#pragma force_active reset
}
